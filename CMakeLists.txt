# MIT License#
# Copyright (c) 2026 Nihilai Collective Corp#
# (license text unchanged)
# FCMakeLists.txt
cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(void-numerics
    DESCRIPTION "For processing some string and numeric values."
    LANGUAGES CXX
)

include(cmake/library_setup.cmake)

include(cmake/installation_setup.cmake)

if(VN_UNIT_TESTS)
    add_subdirectory(unit-tests)
endif()