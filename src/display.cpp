#include <minirend.hpp>

#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

void glfw_error_callback(int error, const char* description) {
  std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
}

namespace minirend {

int Display::display_instances = 0;
GLFWwindow* Display::current_window = nullptr;

void Display::glfw_window_close_callback(GLFWwindow* window) {
  static_cast<Display*>(glfwGetWindowUserPointer(window))->m_should_close = true;
}

void Display::glfw_window_size_callback(GLFWwindow* window, int width, int height) {
  static_cast<Display*>(glfwGetWindowUserPointer(window))->m_window_size = {width, height};
}

void Display::glfw_framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  static_cast<Display*>(glfwGetWindowUserPointer(window))->m_framebuffer_size = {width, height};
}

Display::Display(const std::string& title, std::pair<int, int> window_size) : title(title), m_window_size(window_size) {
  if (display_instances++ == 0) {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) throw std::runtime_error("GLFW init failed");
  }

  glfw_window_ptr = glfwCreateWindow(window_size.first, window_size.second, title.c_str(), nullptr, nullptr);
  if (!glfw_window_ptr) throw std::runtime_error("GLFW window creation failed");

  glfwSetWindowUserPointer(glfw_window_ptr, this);
  glfwSetWindowCloseCallback(glfw_window_ptr, glfw_window_close_callback);
  glfwSetWindowSizeCallback(glfw_window_ptr, glfw_window_size_callback);
  glfwSetFramebufferSizeCallback(glfw_window_ptr, glfw_framebuffer_size_callback);

  glfwGetWindowSize(glfw_window_ptr, &m_window_size.first, &m_window_size.second);
  glfwGetFramebufferSize(glfw_window_ptr, &m_framebuffer_size.first, &m_framebuffer_size.second);
}

Display::Display(Display&& other)
    : title(other.title), m_window_size(other.m_window_size), m_should_close(other.m_should_close),
      glfw_window_ptr(other.glfw_window_ptr) {
  other.glfw_window_ptr = nullptr;
  glfwSetWindowUserPointer(glfw_window_ptr, this);
}

Display::~Display() {
  if (glfw_window_ptr != nullptr) {
    glfwDestroyWindow(glfw_window_ptr);
    if (--display_instances == 0) glfwTerminate();
  }
}

} // namespace minirend
