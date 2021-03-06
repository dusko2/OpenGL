#include <glad/glad.h>
#include "../../../external/Image/stb_image.h"

#include "../GLUtils.h"
#include "../../Utils/IntTypes.h"
#include "Texture2D.h"

Texture2D::Texture2D(const char* path, bool transparent, uint32 index) : GLObject(__func__), index(index) {
    stbi_set_flip_vertically_on_load(true);

    GLCall(glGenTextures(1, &rendererID));
    GLCall(glBindTexture(GL_TEXTURE_2D, rendererID));

    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

    int32 width;
    int32 height;
    int32 channels;

    uint8* data = stbi_load(path, &width, &height, &channels, 0);

    if (data) {
        GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB + transparent, width, height, 0, GL_RGB + transparent, GL_UNSIGNED_BYTE, data));
        GLCall(glGenerateMipmap(GL_TEXTURE_2D));
    }

    stbi_image_free(data);
}

Texture2D::~Texture2D() {
    GLCall(glDeleteTextures(1, &rendererID));
}

void Texture2D::Bind() const {
    GLCall(glActiveTexture(GL_TEXTURE0 + index));
    GLCall(glBindTexture(GL_TEXTURE_2D, rendererID));
}

void Texture2D::Unbind() const {
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}
