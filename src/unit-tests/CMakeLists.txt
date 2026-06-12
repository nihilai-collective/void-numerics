# MIT License#
# Copyright (c) 2026 Nihilai Collective Corp#
# (license text unchanged)
# src/unit-tests/CMakeLists.txt

include(FetchContent)

set(VN_CLANG_COMPILE_OPTIONS
    $<IF:$<AND:$<CXX_COMPILER_ID:Clang>,$<VERSION_EQUAL:$<CXX_COMPILER_VERSION>,23>>,-Wno-lifetime-safety-intra-tu-suggestions,>
    -Weverything
    -Werror
    -Wno-undef
    -Wno-unsafe-buffer-usage
    -Wno-poison-system-directories
    -Wno-c++20-compat
    -Wno-padded
    -Wno-zero-as-null-pointer-constant
    -Wno-c++98-compat-pedantic
    -Wno-c++98-compat
    -Wno-float-equal
    -Wno-class-varargs
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

set(VN_GCC_COMPILE_OPTIONS
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
    -Wpedantic
    -Wextra
    -Werror
    -Wall
)

set(VN_MSVC_COMPILE_OPTIONS
    $<$<AND:$<CONFIG:Debug>,$<NOT:$<BOOL:${VN_ASAN_EFFECTIVE}>>>:/Od /Zi /RTC1>
    $<$<AND:$<CONFIG:Debug>,$<BOOL:${VN_ASAN_EFFECTIVE}>>:/Od /Zi>
    $<$<CONFIG:Release>:/O2 /Ob2 /GL /GS- /Gy>
    $<$<BOOL:${VN_ASAN_EFFECTIVE}>:/fsanitize=address>
    /arch:AVX2    
    /W4
    /WX
)

set(VN_COMPILE_OPTIONS
    $<$<CXX_COMPILER_ID:AppleClang>:${VN_CLANG_COMPILE_OPTIONS}>
    $<$<CXX_COMPILER_ID:Clang>:${VN_CLANG_COMPILE_OPTIONS}>
    $<$<CXX_COMPILER_ID:MSVC>:${VN_MSVC_COMPILE_OPTIONS}>
    $<$<CXX_COMPILER_ID:GCC>:${VN_GCC_COMPILE_OPTIONS}>
)

set(VN_CLANG_LINK_OPTIONS
    $<$<BOOL:${VN_UBSAN_EFFECTIVE}>:-fsanitize=undefined>    
    $<$<BOOL:${VN_ASAN_EFFECTIVE}>:-fsanitize=address>
    $<$<NOT:$<PLATFORM_ID:Darwin>>:-s>
    $<$<PLATFORM_ID:Darwin>:-Wl,-x>
)

set(VN_GCC_LINK_OPTIONS
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
    $<$<CXX_COMPILER_ID:GCC>:${VN_GCC_LINK_OPTIONS}>
)

FetchContent_Declare(
    rt-ut
    GIT_REPOSITORY https://github.com/realtimechris/rt-ut.git
    GIT_TAG main
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(rt-ut)

add_executable(vn_unit_tests "void-numerics.cpp")
target_link_libraries(vn_unit_tests PRIVATE void-numerics::void-numerics rt-ut::rt-ut)
target_compile_options(vn_unit_tests PRIVATE ${VN_COMPILE_OPTIONS})
target_link_options(vn_unit_tests PRIVATE ${VN_LINK_OPTIONS})

if(VN_HOMEBREW_GCC_LIBDIR)
    target_link_options(vn_unit_tests 
        PRIVATE
            -L${VN_HOMEBREW_GCC_LIBDIR}
            -Wl,-rpath,${VN_HOMEBREW_GCC_LIBDIR}
    )
endif()

target_compile_definitions(vn_unit_tests 
    PRIVATE
        $<$<CONFIG:Release>:NDEBUG>
        $<$<CONFIG:Debug>:DEBUG _DEBUG>
        $<IF:$<CONFIG:Debug>,VN_DEBUG=1,VN_DEBUG=0>
        VN_ARCH_ARM64=$<IF:$<OR:$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},aarch64>,$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},ARM64>,$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},arm64>>,1,0>
        VN_ARCH_X64=$<IF:$<OR:$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},x86_64>,$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},AMD64>>,1,0>
        VN_EXTENSION=$<IF:$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GCC>,$<CXX_COMPILER_ID:AppleClang>>,__extension__,>
)

install(
    FILES $<TARGET_FILE:vn_unit_tests>
    DESTINATION bin
    OPTIONAL
)