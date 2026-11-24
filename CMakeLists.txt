cmake_minimum_required(VERSION 3.28)
project("everyday_coding" VERSION 1.2.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MESSAGE_CONTEXT_SHOW true)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()
include(CheckCXXSourceCompiles)
include(FetchContent)

set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.2
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    SYSTEM
)
FetchContent_MakeAvailable(catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

check_cxx_source_compiles("
    #include <ranges>
    #include <vector>
    int main() {
        std::vector<int> v{1, 2, 3};
        auto r = v | std::views::adjacent_transform<2>([](int a, int b) { return b - a; });
        return *r.begin();
    }
" HAVE_STD_ADJACENT_TRANSFORM)

if(NOT HAVE_STD_ADJACENT_TRANSFORM)
    message(STATUS "std::views::adjacent_transform not available — fetching range-v3 fallback")
    FetchContent_Declare(
        range-v3
        GIT_REPOSITORY https://github.com/ericniebler/range-v3.git
        GIT_TAG 0.12.0
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
        SYSTEM
    )
    FetchContent_MakeAvailable(range-v3)
endif()

find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
else()
    message(WARNING "clang-tidy not found! Disabling clang-tidy integration.")
endif()

add_subdirectory(./LeetCode)
add_subdirectory(./ProjectEuler)
