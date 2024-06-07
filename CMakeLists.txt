cmake_minimum_required(VERSION 3.28)
project(learning-gtest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

add_library(learning-gtest
        learning-gtest/hello.hpp
        learning-gtest/hello.cpp
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(project_namespace "${PROJECT_NAME}")
set(config_install_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(version_config "${generated_dir}/${PROJECT_NAME}-config-version.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}-config.cmake")
set(package_components "learning-gtest")

write_basic_package_version_file(
        "${version_config}" COMPATIBILITY SameMajorVersion
)

configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake.in"
        "${project_config}"
        INSTALL_DESTINATION "${config_install_dir}"
)

install(FILES "${project_config}" "${version_config}"
        DESTINATION "${config_install_dir}"
)

include(CPack)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        hello-test
        learning-gtest/hello.test.cpp
)
target_link_libraries(
        hello-test
        GTest::gtest_main
        learning-gtest
)

include(GoogleTest)
gtest_discover_tests(hello-test
        EXTRA_ARGS --gtest_output=xml:reports/junit-hello-test.xml
)

