cmake_minimum_required(VERSION 3.1)

set (CXXTEST_INCLUDE_DIR ${CMAKE_HOME_DIRECTORY}/lib/cxxtest)
set (CXXTEST_PYTHON_TESTGEN_EXECUTABLE ${CMAKE_HOME_DIRECTORY}/lib/cxxtest/bin/cxxtestgen)
set (CMAKE_CXX_STANDARD 20)

set (SOURCE_LIB src/Answer.hpp
                src/Attempt.hpp
                src/Attempt.cpp
                src/Person.hpp
                src/Question.hpp
                src/Questions.hpp
                src/Storage.hpp
                src/Tester.hpp
                src/Tester.cpp)

project(fail_avoidance)
SET (NEED_TEST NO CACHE BOOL "Do you need tests?")
if (NEED_TEST)
    find_package(CxxTest)
    if(CXXTEST_FOUND)
        include_directories(${CXXTEST_INCLUDE_DIR})
        execute_process(COMMAND "${CXXTEST_PYTHON_TESTGEN_EXECUTABLE}" "--error-printer" "-o" "tests/main.cpp" "tests/main.hpp"
            RESULT_VARIABLE git_result
            OUTPUT_VARIABLE git_ver)
        message(STATUS "cxxtestgen[${git_result}]: ${git_ver}")
    endif (CXXTEST_FOUND)
endif (NEED_TEST)

set(EXECUTABLE_OUTPUT_PATH "bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)
INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(tests)

if (APPLE)
       set(CMAKE_MACOSX_RPATH ON)
endif (APPLE)

if (NEED_TEST)
    if(CXXTEST_FOUND)
        add_executable(run_test tests/main.cpp)
        target_link_libraries(run_test ${CXXTEST_LIBRARIES})
        message("Test built succesfully")
    endif (CXXTEST_FOUND)
endif (NEED_TEST)

add_library( example SHARED ${SOURCE_LIB} )	