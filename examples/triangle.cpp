#include <algorithm>
#include <iostream>
#include <memory>

#include <gloo.hpp>
#include <minirend.hpp>

using namespace minirend;
using namespace gloo;

class TriangleApp : public App {
public:
  TriangleApp() : App(Display("Triangle Example", {1024, 768})){};

private:
  std::unique_ptr<Program> program;
  std::unique_ptr<Renderable> triangle;

  void setup() override {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glfwSwapInterval(1);

    program.reset(new Program("examples/resources/flat"));

    std::array<std::array<float, 4>, 3> triangle_points = {{
        {-0.5, -0.5, 0.0, 1.0},
        {+0.5, -0.5, 0.0, 1.0},
        {+0.0, +0.5, 0.0, 1.0},
    }};
    std::array<std::array<float, 4>, 3> flat_triangle;
    std::transform(triangle_points.begin(), triangle_points.end(), flat_triangle.begin(), [](std::array<float, 4>& v) {
      return std::array<float, 4>{v[0] - 0.5f, v[1] + 0.5f, 0.0, 1.0};
    });

    std::vector<std::pair<VBO, VertexAttrib>> vbos;
    vbos.push_back({VBO(GL_ARRAY_BUFFER, flat_triangle, GL_STATIC_DRAW), {0}});
    triangle.reset(new Renderable(*program, std::move(vbos)));
  }

  void main_loop() override {
    glClear(GL_COLOR_BUFFER_BIT);
    triangle->render(GL_TRIANGLES, 0, 3);
  }
};

int main() {
  TriangleApp app;
  app.run();
}
