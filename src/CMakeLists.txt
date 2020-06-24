find_package(glfw3 3.3 REQUIRED)

find_package(glm 0.9 REQUIRED)

add_library(${PROJECT_NAME} app.cpp display.cpp renderable.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw gloo glm)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
