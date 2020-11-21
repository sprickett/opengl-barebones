cmake_minimum_required(VERSION 3.10)

project(opengl-barebones)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STADARD REQUIRED)

find_package(GLFW3 REQUIRED) # graphics and input
find_package(OpenAL REQUIRED) # sound
find_package(FreeType REQUIRED) # text
find_package(GLM REQUIRED) # maths 

add_subdirectory(glad)

include_directories(
  glad/include	
  ${OPENAL_INCLUDE_DIR}
  ${FREETYPE_INCLUDE_DIRS}
)

add_executable( ${PROJECT_NAME}
  src/main.cpp
)
target_link_libraries( ${PROJECT_NAME}
  ${GLFW_LIBRARIES}
  ${OPENAL_LIBRARY}
  ${FREETYPE_LIBRARIES}
  glad
  glfw
  glm::glm
)

