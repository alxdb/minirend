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
  GLFWwindow* const& glfw_window_ptr = m_glfw_window_ptr;

  Display(const std::string& title, std::pair<int, int> window_size);
  Display(const Display&) = delete;
  Display& operator=(const Display&) = delete;
  Display(Display&&);
  ~Display();

private:
  static int display_instances;

  std::pair<int, int> m_window_size;
  std::pair<int, int> m_framebuffer_size;
  bool m_should_close = false;
  GLFWwindow* m_glfw_window_ptr;
};

} // namespace minirend
