cmake_minimum_required(VERSION 3.10)
project(lab06)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)

add_library(print STATIC sources/print.cpp)
target_include_directories(print PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(BUILD_TESTS)
    find_package(GTest REQUIRED)
    
    add_executable(check tests/test1.cpp)
    target_link_libraries(check PRIVATE print GTest::gtest_main)
    target_include_directories(check PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
    
    enable_testing()
    add_test(NAME check COMMAND check)
endif()

include(CPack)

set(CPACK_PACKAGE_NAME "solver")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION "Solver application")
set(CPACK_PACKAGE_VENDOR "schau721")

set(CPACK_GENERATOR "TGZ;ZIP")

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "schau721")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")

set(CPACK_RPM_PACKAGE_LICENSE "MIT")
set(CPACK_RPM_PACKAGE_GROUP "Development/Tools")

install(TARGETS print
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)

install(TARGETS solver
    RUNTIME DESTINATION bin
)
