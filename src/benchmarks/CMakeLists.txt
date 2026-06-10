# MIT License#
# Copyright (c) 2026 Nihilai Collective Corp#
# (license text unchanged)
# src/benchmarks/CMakeLists.txt

include(FetchContent)
FetchContent_Declare(
  benchmarksuite
  GIT_REPOSITORY https://github.com/realtimechris/benchmarksuite.git
  GIT_TAG main
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(benchmarksuite)
set(FMT_DOC OFF CACHE BOOL "" FORCE)
set(FMT_TEST OFF CACHE BOOL "" FORCE)
set(FMT_INSTALL OFF CACHE BOOL "" FORCE)
set(FMT_FUZZ OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 12.1.0
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(fmt)
if(VN_ASAN AND NOT (APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU"))
    target_compile_options(fmt PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/fsanitize=address>
        $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-fsanitize=address>
    )
    target_link_options(fmt PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-fsanitize=address>
    )
endif()
target_compile_definitions(fmt PRIVATE $<$<BOOL:${VN_ASAN}>:_ITERATOR_DEBUG_LEVEL=0>)
FetchContent_Declare(
  jeaiii_itoa
  GIT_REPOSITORY https://github.com/jeaiii/itoa.git
  GIT_TAG main
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(jeaiii_itoa)
add_library(jeaiii_itoa INTERFACE)
target_include_directories(jeaiii_itoa INTERFACE ${jeaiii_itoa_SOURCE_DIR}/itoa)

add_executable(vn_benchmarks "void-numerics.cpp")
target_link_libraries(vn_benchmarks
  void-numerics::void-numerics
  void-numerics-common-options
  benchmarksuite::benchmarksuite
  fmt::fmt
  jeaiii_itoa
)
target_compile_definitions(vn_benchmarks PRIVATE $<$<BOOL:${VN_ASAN}>:_ITERATOR_DEBUG_LEVEL=0>)
install(
    FILES
        $<TARGET_FILE:vn_benchmarks>
    DESTINATION bin
    OPTIONAL
)