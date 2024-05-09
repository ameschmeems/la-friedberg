add_subdirectory(${PROJECT_SOURCE_DIR}/extern/googletest extern/googletest)

macro(package_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})

    target_link_libraries(${TESTNAME} gtest gmock gtest_main core)

    gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
    )
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

add_subdirectory(fields)
package_add_test(Matrix MatrixTest.cpp)
package_add_test(Polynomial PolynomialTest.cpp)