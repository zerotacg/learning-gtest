function(add_test_executable name)
    add_executable(${ARGV})
    set_target_properties("${name}" EXCLUDE_FROM_ALL ON)
    target_link_libraries("${name}"
            GTest::gtest_main
    )
    add_test(NAME "${name}" COMMAND "${name}")
endfunction()
