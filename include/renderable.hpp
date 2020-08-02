#include <GL/glew.h>
#include <gloo.hpp>

#include <vector>

using namespace gloo;

namespace minirend {

class Renderable {
public:
  Renderable(){};
  virtual void render() = 0;
  virtual ~Renderable(){};
};

} // namespace minirend
