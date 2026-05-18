# MIT License
#
# Copyright (c) 2026 Nihilai Collective Corp
#
# (license text unchanged)

include(FetchContent)

set(VN_CLANG_COMPILE_OPTIONS
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
    $<IF:$<AND:$<CXX_COMPILER_ID:Clang>,$<VERSION_EQUAL:$<CXX_COMPILER_VERSION>,23>>,-Wno-lifetime-safety-intra-tu-suggestions,>
    $<$<CONFIG:Debug>:-O0>
    $<$<CONFIG:Debug>:-g>
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
    -Wpedantic
    -Wextra
    -Werror
    -Wall
    $<$<NOT:$<CONFIG:Debug>>:-fwhole-program>
)

set(VN_MSVC_COMPILE_OPTIONS
    $<$<BOOL:${VN_ASAN_EFFECTIVE}>:/fsanitize=address>
    /W4
    /WX
)

set(VN_COMPILE_OPTIONS
    $<$<CXX_COMPILER_ID:AppleClang>:${VN_CLANG_COMPILE_OPTIONS}>
    $<$<CXX_COMPILER_ID:Clang>:${VN_CLANG_COMPILE_OPTIONS}>
    $<$<CXX_COMPILER_ID:MSVC>:${VN_MSVC_COMPILE_OPTIONS}>
    $<$<CXX_COMPILER_ID:GNU>:${VN_GNU_COMPILE_OPTIONS}>
)

set(VN_CLANG_LINK_OPTIONS
    $<$<BOOL:${VN_ASAN_EFFECTIVE}>:-fsanitize=address>
    $<$<BOOL:${VN_UBSAN_EFFECTIVE}>:-fsanitize=undefined>
)

set(VN_GNU_LINK_OPTIONS
    $<$<BOOL:${VN_ASAN_EFFECTIVE}>:-fsanitize=address>
    $<$<BOOL:${VN_UBSAN_EFFECTIVE}>:-fsanitize=undefined>
)

set(VN_MSVC_LINK_OPTIONS
    $<$<BOOL:${VN_ASAN_EFFECTIVE}>:/INFERASANLIBS>
)

set(VN_LINK_OPTIONS
    $<$<CXX_COMPILER_ID:AppleClang>:${VN_CLANG_LINK_OPTIONS}>
    $<$<CXX_COMPILER_ID:Clang>:${VN_CLANG_LINK_OPTIONS}>
    $<$<CXX_COMPILER_ID:MSVC>:${VN_MSVC_LINK_OPTIONS}>
    $<$<CXX_COMPILER_ID:GNU>:${VN_GNU_LINK_OPTIONS}>
)

FetchContent_Declare(
    rt-ut
    GIT_REPOSITORY https://github.com/realtimechris/rt-ut.git
    GIT_TAG main
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(rt-ut)

add_executable(vn_unit_tests "void-numerics.cpp")
target_link_libraries(vn_unit_tests PUBLIC void-numerics::void-numerics rt-ut::rt-ut)
target_compile_definitions(vn_unit_tests PUBLIC ${VN_COMPILE_DEFINITIONS})
target_compile_options(vn_unit_tests PUBLIC ${VN_COMPILE_OPTIONS})
target_link_options(vn_unit_tests PUBLIC ${VN_LINK_OPTIONS})

install(
    FILES $<TARGET_FILE:vn_unit_tests>
    DESTINATION bin
    OPTIONAL
)