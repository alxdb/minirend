#pragma once

#include "display.hpp"

namespace minirend {

class App {
public:
  App(Display&& display) : display(std::move(display)){};
  void run();

protected:
  virtual void setup() = 0;
  virtual void main_loop() = 0;
  Display display;
};

} // namespace minirend
