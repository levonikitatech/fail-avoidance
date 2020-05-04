cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 17)
project(fail_avoidance)
SET (NEED_TEST NO CACHE BOOL "Do you need tests?")
if (NEED_TEST)
    find_package(CxxTest)
    if(CXXTEST_FOUND)
        include_directories(${CXXTEST_INCLUDE_DIR})
        execute_process(COMMAND cxxtestgen "--error-printer" "-o" "tests/main.cpp" "tests/main.hpp"
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            RESULT_VARIABLE git_result
            OUTPUT_VARIABLE git_ver)
        message(STATUS "cxxtestgen[${git_result}]: ${git_ver}")
    endif (CXXTEST_FOUND)
endif (NEED_TEST)

set(EXECUTABLE_OUTPUT_PATH "bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)
INCLUDE_DIRECTORIES(src)

if (APPLE)
       set(CMAKE_MACOSX_RPATH ON)
endif (APPLE)

if (NEED_TEST)
    add_executable(main tests/main.cpp)

    target_link_libraries(main)

    if(CXXTEST_FOUND)
        add_executable(run_test tests/main.cpp)
        target_link_libraries(run_test ${CXXTEST_LIBRARIES})
    endif (CXXTEST_FOUND)
endif (NEED_TEST)


