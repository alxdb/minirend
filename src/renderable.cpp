#include "renderable.hpp"

namespace minirend {

Renderable::Renderable(const Program& program, std::vector<std::pair<VBO, VertexAttrib>>&& vbos)
    : m_program(program), m_vao(vbos) {
  for (std::pair<VBO, VertexAttrib>& vbo : vbos) {
    m_vbos.push_back(std::move(vbo.first));
  }
}

void Renderable::render(GLenum mode, int first, size_t count) {
  glUseProgram(m_program.id);
  glBindVertexArray(m_vao.id);
  glDrawArrays(mode, first, count);
}

} // namespace minirend
