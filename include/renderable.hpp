#include <gloo.hpp>

#include <vector>

using namespace gloo;

namespace minirend {

class Renderable {
public:
  const std::vector<VBO>& vbos = m_vbos;

  Renderable(const Program& program, std::vector<std::pair<VBO, VertexAttrib>>&& vbos);

  void render(GLenum mode, int first, size_t count);

private:
  const Program& m_program;
  VAO m_vao;
  std::vector<VBO> m_vbos;
};

} // namespace minirend
