set(COMPONENT_NAME "hello")

list(APPEND package_components "${COMPONENT_NAME}")

file(GLOB HEADER "${PROJECT_NAME}/${COMPONENT_NAME}/*.hpp")

add_library(${COMPONENT_NAME}
        liblearning-gtest/hello/hello.cpp
)
add_library("${project_namespace}::${COMPONENT_NAME}" ALIAS ${COMPONENT_NAME})
set_target_properties(${COMPONENT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-${COMPONENT_NAME}")

target_include_directories(${COMPONENT_NAME}
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(targets_export_name "${PROJECT_NAME}-${COMPONENT_NAME}-targets")


install(TARGETS "${COMPONENT_NAME}"
        EXPORT "${targets_export_name}"
)

install(FILES
        liblearning-gtest/hello/hello.hpp
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${COMPONENT_NAME}
)

install(EXPORT "${targets_export_name}"
        NAMESPACE "${project_namespace}::"
        DESTINATION "${config_install_dir}"
)

set(TEST_NAME "${COMPONENT_NAME}-test")
add_test_executable("${TEST_NAME}"
        liblearning-gtest/hello/hello.test.cpp
)
target_link_libraries("${TEST_NAME}"
        "${project_namespace}::${COMPONENT_NAME}"
)
