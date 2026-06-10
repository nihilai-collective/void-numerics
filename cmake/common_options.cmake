# MIT License#
# Copyright (c) 2026 Nihilai Collective Corp#
# (license text unchanged)
# cmake/common_options.cmake

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

add_library(${PROJECT_NAME}-common-options INTERFACE)

target_include_directories(${PROJECT_NAME}-common-options
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

set(VN_CLANG_COMPILE_OPTIONS
    $<$<AND:$<CONFIG:Release>,$<NOT:$<BOOL:${VN_ASAN_EFFECTIVE}>>>:
        -O3
        -march=native
        -flto
        -finline-functions
        -fomit-frame-pointer
        -fno-rtti
        -fno-vectorize
        -fno-slp-vectorize
        -fno-stack-protector
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
)

set(VN_GNU_COMPILE_OPTIONS
    $<$<BOOL:${VN_ASAN_EFFECTIVE}>:
        -fsanitize=address
        -fsanitize-address-use-after-scope
        -U_FORTIFY_SOURCE
        -D_FORTIFY_SOURCE=0
    >
    $<$<BOOL:${VN_UBSAN_EFFECTIVE}>:
        -fsanitize=undefined
        -fno-sanitize-recover=all
    >
    $<$<CONFIG:Debug>:-O0>
    $<$<CONFIG:Debug>:-g>
    $<$<NOT:$<CONFIG:Debug>>:-fwhole-program>
)

set(VN_MSVC_COMPILE_OPTIONS
    $<$<AND:$<CONFIG:Debug>,$<NOT:$<BOOL:${VN_ASAN_EFFECTIVE}>>>:/Od /Zi /RTC1>
    $<$<AND:$<CONFIG:Debug>,$<BOOL:${VN_ASAN_EFFECTIVE}>>:/Od /Zi>
    $<$<CONFIG:Release>:/O2 /Ob2 /GL /GS- /Gy>
    $<$<BOOL:${VN_ASAN_EFFECTIVE}>:/fsanitize=address>
    /arch:AVX2
)

set(VN_COMPILE_OPTIONS
    $<$<CXX_COMPILER_ID:AppleClang>:${VN_CLANG_COMPILE_OPTIONS}>
    $<$<CXX_COMPILER_ID:Clang>:${VN_CLANG_COMPILE_OPTIONS}>
    $<$<CXX_COMPILER_ID:MSVC>:${VN_MSVC_COMPILE_OPTIONS}>
    $<$<CXX_COMPILER_ID:GNU>:${VN_GNU_COMPILE_OPTIONS}>
)

target_compile_options(${PROJECT_NAME}-common-options
    INTERFACE ${VN_COMPILE_OPTIONS}
)

set(VN_CLANG_LINK_OPTIONS
    $<$<BOOL:${VN_UBSAN_EFFECTIVE}>:-fsanitize=undefined>    
    $<$<BOOL:${VN_ASAN_EFFECTIVE}>:-fsanitize=address>
    $<$<NOT:$<PLATFORM_ID:Darwin>>:-s>
    $<$<PLATFORM_ID:Darwin>:-Wl,-x>
)

set(VN_GNU_LINK_OPTIONS
    $<$<BOOL:${VN_UBSAN_EFFECTIVE}>:-fsanitize=undefined>
    $<$<BOOL:${VN_ASAN_EFFECTIVE}>:-fsanitize=address>
    $<$<PLATFORM_ID:Linux>:-static-libasan>
    $<$<NOT:$<PLATFORM_ID:Darwin>>:-s>
    $<$<PLATFORM_ID:Darwin>:-Wl,-x>
    $<$<CONFIG:Release>:-flto>
)

set(VN_MSVC_LINK_OPTIONS
    $<$<BOOL:${VN_ASAN_EFFECTIVE}>:/INFERASANLIBS>
    $<$<CONFIG:Release>:/LTCG /OPT:REF /OPT:ICF>
)

set(VN_LINK_OPTIONS
    $<$<CXX_COMPILER_ID:AppleClang>:${VN_CLANG_LINK_OPTIONS}>
    $<$<CXX_COMPILER_ID:Clang>:${VN_CLANG_LINK_OPTIONS}>
    $<$<CXX_COMPILER_ID:MSVC>:${VN_MSVC_LINK_OPTIONS}>
    $<$<CXX_COMPILER_ID:GNU>:${VN_GNU_LINK_OPTIONS}>
)

target_link_options(${PROJECT_NAME}-common-options
    INTERFACE ${VN_LINK_OPTIONS}
)

if(VN_HOMEBREW_GCC_LIBDIR)
    target_link_options(${PROJECT_NAME}-common-options
        INTERFACE
            -L${VN_HOMEBREW_GCC_LIBDIR}
            -Wl,-rpath,${VN_HOMEBREW_GCC_LIBDIR}
    )
endif()

target_compile_definitions(${PROJECT_NAME}-common-options
    INTERFACE
        $<$<CONFIG:Release>:NDEBUG>
        $<$<CONFIG:Debug>:DEBUG _DEBUG>
        $<IF:$<CONFIG:Debug>,VN_DEBUG=1,VN_DEBUG=0>
        VN_ARCH_ARM64=$<IF:$<OR:$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},aarch64>,$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},ARM64>,$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},arm64>>,1,0>
        VN_ARCH_X64=$<IF:$<OR:$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},x86_64>,$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},AMD64>>,1,0>
        VN_EXTENSION=$<IF:$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:AppleClang>>,__extension__,>
)
