cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(gl_play)


set(LIB_SOURCE_FILES
    src/glad.cpp
    )



add_library(musa_gl_libs
    SHARED
    ${LIB_SOURCE_FILES}
    ${LIB_HEADER_FILES}
    )

target_include_directories(musa_gl_libs PRIVATE include)

set_target_properties(musa_gl_libs
    PROPERTIES
    CXX_STANDARD 11
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE 1

    )

target_link_libraries(musa_gl_libs ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} GLU GLEW glfw dl)


find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)


set(SOURCE_FILES
    src/main.cpp
    src/display.cpp
    src/shader.cpp
    src/shape.cpp
    src/triangle.cpp


    src/rendererGL/cube.cpp
    src/rendererGL/mesh.cpp
    src/rendererGL/shader.cpp
    src/rendererGL/time.cpp
    src/rendererGL/camera.cpp
    src/rendererGL/transform.cpp
    )

add_executable(gl_play  ${SOURCE_FILES})



include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS}
    include
    )


target_link_libraries(gl_play  musa_gl_libs )
