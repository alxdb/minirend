#include "minirend.hpp"

#include <stdexcept>

namespace minirend {

void App::run() {
  glfwMakeContextCurrent(display.glfw_window_ptr);
  if (glewInit() != GLEW_OK) throw std::runtime_error("GLEW init failed");
  setup();
  while (!display.should_close) {
    glViewport(0, 0, display.framebuffer_size.first, display.framebuffer_size.second);
    main_loop();
    glfwSwapBuffers(display.glfw_window_ptr);
    glfwPollEvents();
  }
}

} // namespace minirend
