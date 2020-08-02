#include <algorithm>
#include <iostream>
#include <memory>

#include <glm/glm.hpp>
#include <minirend.hpp>

using namespace minirend;
using namespace gloo;

class Triangle : public Renderable {
  Program m_program;
  VAO m_vao;
  Buffer m_points;

public:
  Triangle(std::array<glm::vec4, 3> points)
      : m_program("examples/resources/flat"), m_points(GL_ARRAY_BUFFER, points, GL_STATIC_DRAW) {
    m_vao.add_vertex_buffer(m_points, {{0}});
  };

  void render() override {
    glUseProgram(m_program.id);
    glBindVertexArray(m_vao.id);
    glDrawArrays(GL_TRIANGLES, 0, 3);
  }
};

class TriangleApp : public App {
public:
  TriangleApp() : App(Display("Triangle Example", {1024, 768})){};

private:
  std::unique_ptr<Renderable> triangle;

  void setup() override {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glfwSwapInterval(1);

    std::array<glm::vec4, 3> points = {{
        {-0.5, -0.5, 0.0, 1.0},
        {+0.5, -0.5, 0.0, 1.0},
        {+0.0, +0.5, 0.0, 1.0},
    }};

    triangle.reset(new Triangle(points));
  }

  void main_loop() override {
    glClear(GL_COLOR_BUFFER_BIT);
    triangle->render();
  }
};

int main() {
  TriangleApp app;
  app.run();
}
