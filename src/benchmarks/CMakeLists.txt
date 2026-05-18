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
target_link_libraries(vn_benchmarks PRIVATE 
  void-numerics::void-numerics
  benchmarksuite::benchmarksuite
  fmt::fmt
  jeaiii_itoa
)

install(
    FILES
        $<TARGET_FILE:vn_benchmarks>
    DESTINATION bin
    OPTIONAL
)