set(TEST_NAME "hello-world-test")

add_executable("${TEST_NAME}"
        hello-world.test.cpp
)
target_link_libraries("${TEST_NAME}"
        GTest::gtest_main
        "${project_namespace}::hello"
        "${project_namespace}::world"
)

add_test(
        NAME "${TEST_NAME}"
        COMMAND "${TEST_NAME}" "--gtest_output=xml:${CMAKE_CURRENT_BINARY_DIR}/reports/junit-${TEST_NAME}.xml"
)
