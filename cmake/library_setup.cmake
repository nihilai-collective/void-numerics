# MIT License#
# Copyright (c) 2026 Nihilai Collective Corp#
# (license text unchanged)
# cmake/library_setup.cmake

option(VN_ASAN  "Enable AddressSanitizer"            OFF)
option(VN_UBSAN "Enable UndefinedBehaviorSanitizer"  OFF)

set(VN_ASAN_EFFECTIVE  ${VN_ASAN})
set(VN_UBSAN_EFFECTIVE ${VN_UBSAN})

if(APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "GCC")
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
