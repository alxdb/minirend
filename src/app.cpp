#include "minirend.hpp"

#include <stdexcept>

namespace minirend {

void App::run() {
  display.make_current();
  if (glewInit() != GLEW_OK) throw std::runtime_error("GLEW init failed");
  setup();
  while (!display.should_close) {
    glViewport(0, 0, display.framebuffer_size.first, display.framebuffer_size.second);
    main_loop();
    display.swap_buffers();
    glfwPollEvents();
  }
}

} // namespace minirend
