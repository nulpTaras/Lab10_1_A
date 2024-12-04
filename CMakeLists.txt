

cmake_minimum_required(VERSION 3.29)
project(Lab10_1_A)

set(CMAKE_CXX_STANDARD 20)

# Підключаємо Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Додаємо бібліотеку з функціями, які будемо тестувати
add_library(MyLibrary src/main.cpp
)

# Додаємо тести
add_executable(MyTests tests/testfile.cpp)

# Лінкуємо тести з бібліотекою та Google Test
target_link_libraries(MyTests PRIVATE MyLibrary gtest gtest_main)

enable_testing()
add_test(NAME MyTests COMMAND MyTests)

add_executable(Lab10_1_A src/main.cpp)



