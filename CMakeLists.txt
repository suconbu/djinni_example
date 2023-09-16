cmake_minimum_required(VERSION 3.0)

project(example)

find_package(JNI)

set(DJINNI_BUILD_TESTING OFF CACHE INTERNAL "")
set(DJINNI_WITH_JNI ON CACHE INTERNAL "")
set(DJINNI_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/djinni)

include(FetchContent)
FetchContent_Declare(djinni-support-lib
  GIT_REPOSITORY https://github.com/cross-language-cpp/djinni-support-lib.git
  GIT_TAG v1.2.1
)
FetchContent_MakeAvailable(djinni-support-lib)

# add_subdirectory(djinni-support-lib)

set(EXAMPLE_SERVER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/server)
set(EXAMPLE_GENERATED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/generated)

add_library(${CMAKE_PROJECT_NAME}
    SHARED
    ${EXAMPLE_SERVER_DIR}/example.cpp
    ${EXAMPLE_GENERATED_DIR}/jni/djinni_jni_main.cpp
    ${EXAMPLE_GENERATED_DIR}/jni/NativeHelloWorld.cpp
    ${EXAMPLE_GENERATED_DIR}/jni/NativeHelloCallback.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE
    djinni-support-lib::djinni-support-lib
)

target_include_directories(${CMAKE_PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${EXAMPLE_GENERATED_DIR}/jni
    ${EXAMPLE_GENERATED_DIR}/cpp
)
