set(example_sources triangle.cpp)
file(CREATE_LINK ${CMAKE_CURRENT_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources SYMBOLIC)

foreach(source IN LISTS example_sources)
  get_filename_component(executable ${source} NAME_WE)
  add_executable(${executable} ${source})
  target_link_libraries(${executable} PRIVATE ${CMAKE_PROJECT_NAME})
endforeach()
