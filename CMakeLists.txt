cmake_minimum_required(VERSION 3.20)

project(CodeLand)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 20)

set(SOURCE
        Main.cpp
        Window.cpp
        Graphics.cpp
        GOL.cpp
        GOLRenderer.cpp
)

add_executable(cgol ${SOURCE})
target_link_libraries(cgol ${CONAN_LIBS})
