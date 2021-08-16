## Use the variable PROJECT_NAME for changing the target name
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
set( PROJECT_NAME ${ProjectId} )

cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project(${PROJECT_NAME})

# include_directories(include)

find_package(OpenGL REQUIRED)
add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLEW)
include_directories(/usr/local/opt/glew/include)
include_directories(/opt/homebrew/opt/glew/include)
include_directories(/usr/local/opt/glfw/include)
include_directories(/opt/homebrew/opt/glfw/include)
link_directories(/usr/local/lib)
link_directories(/opt/homebrew/lib)

## add imgui as a library
add_library(imgui STATIC
  src/imgui/imgui.cpp
  src/imgui/imgui_demo.cpp
  src/imgui/imgui_draw.cpp
  src/imgui/imgui_widgets.cpp
  src/imgui/imgui_impl_glfw.cpp
  src/imgui/imgui_impl_opengl3.cpp
)

add_library(renderer STATIC
  src/renderer/imgui_renderer.cpp
)
target_include_directories(renderer PUBLIC include)

## Define libraries
# target_include_directories(${PROJECT_NAME}_lib include)
# add_library(${PROJECT_NAME}_lib
# 
#)

## Define the executable
set(SRCS 
  src/main.cpp
  src/world/world.cpp
  src/world/map.cpp
  src/objects/object.cpp
  src/objects/landmark.cpp
  src/objects/ideal_robot.cpp
  src/objects/robot.cpp
  src/sensors/sensor.cpp
  src/sensors/ideal_camera.cpp
  src/agents/agent.cpp
)
add_executable(${PROJECT_NAME} ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC
  include
)
target_link_libraries(${PROJECT_NAME} 
  renderer
  imgui
  glew
  glfw 
  ${OPENGL_gl_LIBRARY} 
)