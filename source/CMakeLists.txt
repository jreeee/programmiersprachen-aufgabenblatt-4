# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  rectangle.cpp
  circle.cpp
  mat2.cpp
  vec2.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  glew.c
  tests.cpp
  vec2.cpp
  mat2.cpp
  circle.cpp
  rectangle.cpp
  window.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

add_executable(clock
  clock.cpp
  window.cpp
  glew.c
  circle.cpp
  mat2.cpp
  vec2.cpp
  )
target_link_libraries(clock
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(clock glfw nanovg ${COPY_BINARY})

# assignment 4
add_executable(aufgabe4_2_und_4_3
  aufgabe_2_und_3.cpp
)

add_executable(aufgabe4_5_bis_7
  aufgabe_5_bis_7.cpp
  circle.cpp
  vec2.cpp
  mat2.cpp
  window.cpp
  glew.c
)
target_link_libraries(aufgabe4_5_bis_7
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(aufgabe4_5_bis_7 glfw nanovg ${COPY_BINARY})

add_executable(aufgabe_8
  aufgabe_8.cpp
)

add_executable(aufgabe_10
  aufgabe_10.cpp
)

add_executable(aufgabe_11
  aufgabe_11.cpp
)