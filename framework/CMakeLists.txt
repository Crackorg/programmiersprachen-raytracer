file(GLOB FRAMEWORK_SOURCE *.cpp)
file(GLOB FRAMEWORK_INLINE *.inl)
file(GLOB FRAMEWORK_HEADER *.hpp)

source_group("Inline Files" FILES ${FRAMEWORK_INLINE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

add_library(${FRAMEWORK_NAME} STATIC glew.c
  ${FRAMEWORK_SOURCE}
  ${FRAMEWORK_INLINE}
  ${FRAMEWORK_HEADER} "Box.cpp" "shape.cpp")
target_link_libraries(${FRAMEWORK_NAME}
  ${OPENGL_LIBRARIES}
  ${GLFW_LIBRARIES}
  )
