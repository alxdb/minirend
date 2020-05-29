#pragma once

#include <memory>
#include <string>

#include <GLFW/glfw3.h>

namespace minirend {

class Display {
public:
  const std::string title;
  const std::pair<int, int>& window_size = m_window_size;
  const std::pair<int, int>& framebuffer_size = m_framebuffer_size;
  const bool& should_close = m_should_close;

  Display(const std::string& title, std::pair<int, int> window_size);
  Display(const Display&) = delete;
  Display& operator=(const Display&) = delete;
  Display(Display&&);
  ~Display();

  void swap_buffers() { glfwSwapBuffers(glfw_window_ptr); }
  void make_current() { glfwMakeContextCurrent(glfw_window_ptr); }

private:
  static void glfw_window_close_callback(GLFWwindow*);
  static void glfw_window_size_callback(GLFWwindow*, int, int);
  static void glfw_framebuffer_size_callback(GLFWwindow*, int, int);
  static int display_instances;
  static GLFWwindow* current_window;

  std::pair<int, int> m_window_size;
  std::pair<int, int> m_framebuffer_size;
  bool m_should_close = false;
  GLFWwindow* glfw_window_ptr;
};

} // namespace minirend
