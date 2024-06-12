add_test_executable(hello-world-test
        hello-world.test.cpp
)
target_link_libraries(hello-world-test
        "${project_namespace}::hello"
        "${project_namespace}::world"
)
