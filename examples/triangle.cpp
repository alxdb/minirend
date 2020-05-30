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
  std::unique_ptr<VBO> vbo;
  std::unique_ptr<VAO> vao;

  void setup() override {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glfwSwapInterval(1);
    std::vector<std::array<float, 4>> triangle_points = {
        {-0.5, -0.5, 0.0, 1.0},
        {+0.5, -0.5, 0.0, 1.0},
        {+0.0, +0.5, 0.0, 1.0},
    };
    std::ifstream vert_shader_file("examples/resources/triangle.vert");
    std::ifstream frag_shader_file("examples/resources/triangle.frag");
    program = std::unique_ptr<Program>(new Program(vert_shader_file, frag_shader_file));
    vbo = std::unique_ptr<VBO>(new VBO(GL_ARRAY_BUFFER, &triangle_points[0], 12, GL_STATIC_DRAW));
    vao = std::unique_ptr<VAO>(new VAO({VertexAttrib(*vbo, 0)}));
  }

  void main_loop() override {
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program->get_id());
    glBindVertexArray(vao->get_id());
    glDrawArrays(GL_TRIANGLES, 0, 3);
  }
};

int main() {
  TriangleApp app;
  app.run();
}
