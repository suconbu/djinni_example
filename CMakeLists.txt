cmake_minimum_required(VERSION 3.0)

project(example)

find_package(JNI)

set(DJINNI_BUILD_TESTING OFF CACHE INTERNAL "")
set(DJINNI_WITH_JNI ON CACHE INTERNAL "")
set(DJINNI_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/djinni)

include(FetchContent)
FetchContent_Declare(djinni_support_lib
  GIT_REPOSITORY https://github.com/cross-language-cpp/djinni-support-lib.git
  GIT_TAG v1.2.1
)
FetchContent_Declare(nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
)
FetchContent_MakeAvailable(djinni_support_lib)
FetchContent_MakeAvailable(nlohmann_json)

# add_subdirectory(djinni-support-lib)

set(EXAMPLE_SERVER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/server)
set(EXAMPLE_GENERATED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/generated)

file(GLOB JNI_SOURCES ${EXAMPLE_GENERATED_DIR}/jni/*.cpp)

add_library(${CMAKE_PROJECT_NAME}
    SHARED
    ${EXAMPLE_SERVER_DIR}/example.cpp
    ${JNI_SOURCES}
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE
    djinni_support_lib
    nlohmann_json
)

target_include_directories(${CMAKE_PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${EXAMPLE_GENERATED_DIR}/jni
    ${EXAMPLE_GENERATED_DIR}/cpp
)
