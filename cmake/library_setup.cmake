# MIT License
#
# Copyright (c) 2026 Nihilai Collective Corp
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

option(VN_ASAN  "Enable AddressSanitizer"            OFF)
option(VN_UBSAN "Enable UndefinedBehaviorSanitizer"  OFF)

set(VN_ASAN_EFFECTIVE  ${VN_ASAN})
set(VN_UBSAN_EFFECTIVE ${VN_UBSAN})

if(APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(VN_ASAN)
        message(WARNING
            "VN_ASAN is not supported with GCC on macOS -- ignoring for this "
            "configure. Re-run with a Clang/AppleClang toolchain to enable.")
        set(VN_ASAN_EFFECTIVE OFF)
    endif()
    if(VN_UBSAN)
        message(WARNING
            "VN_UBSAN is not supported with GCC on macOS -- ignoring for this "
            "configure. Re-run with a Clang/AppleClang toolchain to enable.")
        set(VN_UBSAN_EFFECTIVE OFF)
    endif()
endif()

if(VN_UBSAN_EFFECTIVE AND CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message(WARNING
        "VN_UBSAN has no effect with MSVC (no equivalent runtime). "
        "Use Clang-cl or a Clang/GCC build to get UBSan coverage.")
    set(VN_UBSAN_EFFECTIVE OFF)
endif()

if(APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(VN_ASAN_EFFECTIVE OFF)
    set(VN_UBSAN_EFFECTIVE OFF)
    message(STATUS "Disabling sanitizers: not supported with GCC on macOS.")
endif()

set(VN_HOMEBREW_GCC_LIBDIR "")
if(APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    find_program(VN_BREW_EXE brew)
    if(VN_BREW_EXE)
        execute_process(
            COMMAND ${VN_BREW_EXE} --prefix gcc
            OUTPUT_VARIABLE VN_BREW_GCC_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
            RESULT_VARIABLE VN_BREW_RC
        )
        if(VN_BREW_RC EQUAL 0 AND VN_BREW_GCC_PREFIX)
            file(GLOB VN_GCC_LIB_CANDIDATES
                "${VN_BREW_GCC_PREFIX}/lib/gcc/*")
            if(VN_GCC_LIB_CANDIDATES)
                list(SORT VN_GCC_LIB_CANDIDATES)
                list(REVERSE VN_GCC_LIB_CANDIDATES)
                list(GET VN_GCC_LIB_CANDIDATES 0 VN_HOMEBREW_GCC_LIBDIR)
            endif()
        endif()
    endif()
    if(NOT VN_HOMEBREW_GCC_LIBDIR)
        message(STATUS
            "Could not auto-detect Homebrew GCC runtime path; link-time "
            "rpath for libstdc++ will not be added. Set "
            "VN_HOMEBREW_GCC_LIBDIR manually if needed.")
    endif()
endif()

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_options(${PROJECT_NAME}
    INTERFACE
        $<$<CXX_COMPILER_ID:MSVC>:
            /arch:AVX2
            $<$<CONFIG:Release>:/O2 /Ob2 /GL /fp:fast /GS- /Gy>
            $<$<AND:$<CONFIG:Debug>,$<NOT:$<BOOL:${VN_ASAN_EFFECTIVE}>>>:/Od /Zi /RTC1>
            $<$<AND:$<CONFIG:Debug>,$<BOOL:${VN_ASAN_EFFECTIVE}>>:/Od /Zi>
            $<$<BOOL:${VN_ASAN_EFFECTIVE}>:/fsanitize=address>
        >
        $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
            $<$<AND:$<CONFIG:Release>,$<NOT:$<BOOL:${VN_ASAN_EFFECTIVE}>>>:
                -O3
                -march=native
                -flto
                -finline-functions
                -fomit-frame-pointer
                -fno-rtti
            >
            $<$<AND:$<CONFIG:Release>,$<BOOL:${VN_ASAN_EFFECTIVE}>>:
                -O1
                -fno-rtti
            >
            $<$<CONFIG:Debug>:
                -O0
                -g
                -fno-omit-frame-pointer
            >
            $<$<BOOL:${VN_ASAN_EFFECTIVE}>:
                -fsanitize=address
                -fno-omit-frame-pointer
                -fno-optimize-sibling-calls
                -fsanitize-address-use-after-scope
                -U_FORTIFY_SOURCE
                -D_FORTIFY_SOURCE=0
            >
            $<$<BOOL:${VN_UBSAN_EFFECTIVE}>:
                -fsanitize=undefined
                -fno-sanitize-recover=all
            >
        >
)

target_link_options(${PROJECT_NAME}
    INTERFACE
        $<$<CXX_COMPILER_ID:MSVC>:
            $<$<CONFIG:Release>:/LTCG /OPT:REF /OPT:ICF>
            $<$<BOOL:${VN_ASAN_EFFECTIVE}>:/INFERASANLIBS>
        >
        $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
            $<$<AND:$<CONFIG:Release>,$<NOT:$<BOOL:${VN_ASAN_EFFECTIVE}>>>:
                -flto
                $<$<PLATFORM_ID:Darwin>:-Wl,-x>
                $<$<NOT:$<PLATFORM_ID:Darwin>>:-s>
            >
            $<$<BOOL:${VN_ASAN_EFFECTIVE}>:
                -fsanitize=address
                $<$<AND:$<PLATFORM_ID:Linux>,$<CXX_COMPILER_ID:GNU>>:-static-libasan>
            >
            $<$<BOOL:${VN_UBSAN_EFFECTIVE}>:
                -fsanitize=undefined
            >
        >
)

if(VN_HOMEBREW_GCC_LIBDIR)
    target_link_options(${PROJECT_NAME}
        INTERFACE
            -L${VN_HOMEBREW_GCC_LIBDIR}
            -Wl,-rpath,${VN_HOMEBREW_GCC_LIBDIR}
    )
endif()

target_compile_definitions(${PROJECT_NAME}
    INTERFACE
        $<$<CONFIG:Release>:NDEBUG>
        $<$<CONFIG:Debug>:DEBUG _DEBUG>
        $<IF:$<CONFIG:Debug>,VN_DEBUG=1,VN_DEBUG=0>
        VN_ARCH_ARM64=$<IF:$<OR:$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},aarch64>,$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},ARM64>,$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},arm64>>,1,0>
        VN_ARCH_X64=$<IF:$<OR:$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},x86_64>,$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},AMD64>>,1,0>
        VN_EXTENSION=$<IF:$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:AppleClang>>,__extension__,>
)