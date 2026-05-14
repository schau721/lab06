cmake_minimum_required(VERSION 3.10)
project(lab05)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)

# Ваша библиотека
add_library(print STATIC sources/print.cpp)

# Добавляем директорию с заголовочными файлами
target_include_directories(print PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(BUILD_TESTS)
    # Google Test
    add_subdirectory(third-party/gtest)
    
    # Тесты
    add_executable(check tests/test1.cpp)
    
    # Линкуем библиотеки
    target_link_libraries(check PRIVATE print gtest_main)
    
    # Добавляем директорию с заголовками для тестов
    target_include_directories(check PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
    
    enable_testing()
    add_test(NAME check COMMAND check)
endif()
