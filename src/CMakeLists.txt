find_package(glfw3 3.3 REQUIRED)

find_package(glm 0.9 REQUIRED)
find_package(GLEW REQUIRED)

add_library(${PROJECT_NAME} app.cpp display.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw GLEW::GLEW gloo glm)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
