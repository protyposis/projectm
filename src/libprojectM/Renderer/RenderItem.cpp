#include "RenderItem.hpp"
#include <android/log.h>

namespace libprojectM {
namespace Renderer {

void RenderItem::Init()
{
    __android_log_print(ANDROID_LOG_DEBUG, "PRJMNATIVE", "RenderItem::Init 1");
    glGenVertexArrays(1, &m_vaoID);
    glGenBuffers(1, &m_vboID);

    glBindVertexArray(m_vaoID);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboID);

    InitVertexAttrib();

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    __android_log_print(ANDROID_LOG_DEBUG, "PRJMNATIVE", "RenderItem::Init 2");
}

RenderItem::~RenderItem()
{
    glDeleteBuffers(1, &m_vboID);
    glDeleteVertexArrays(1, &m_vaoID);
}

} // namespace Renderer
} // namespace libprojectM
