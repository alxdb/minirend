set(example_sources triangle.cpp)

foreach(source IN LISTS example_sources)
  get_filename_component(executable ${source} NAME_WE)
  add_executable(${executable} ${source})
  target_link_libraries(${executable} PRIVATE ${CMAKE_PROJECT_NAME})
endforeach()
