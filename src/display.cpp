#include <minirend.hpp>

#include <iostream>
#include <stdexcept>

#include <GLFW/glfw3.h>

namespace minirend {

int Display::display_instances = 0;

Display::Display(const std::string& title, std::pair<int, int> window_size) : title(title), m_window_size(window_size) {
  if (display_instances++ == 0) {
    glfwSetErrorCallback([](int error, const char* description) {
      std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
    });

    if (!glfwInit()) throw std::runtime_error("GLFW init failed");

    glfwSetWindowCloseCallback(glfw_window_ptr, [](GLFWwindow* window) {
      static_cast<Display*>(glfwGetWindowUserPointer(window))->m_should_close = true;
    });
    glfwSetWindowSizeCallback(glfw_window_ptr, [](GLFWwindow* window, int width, int height) {
      static_cast<Display*>(glfwGetWindowUserPointer(window))->m_window_size = {width, height};
    });
    glfwSetFramebufferSizeCallback(glfw_window_ptr, [](GLFWwindow* window, int width, int height) {
      static_cast<Display*>(glfwGetWindowUserPointer(window))->m_framebuffer_size = {width, height};
    });
  }

  glfw_window_ptr = glfwCreateWindow(window_size.first, window_size.second, title.c_str(), nullptr, nullptr);
  if (!glfw_window_ptr) throw std::runtime_error("GLFW window creation failed");

  glfwSetWindowUserPointer(glfw_window_ptr, this);

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
