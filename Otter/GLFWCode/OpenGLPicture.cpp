#include "pch.h"

#include"glad/glad.h"
#include"GLFW/glfw3.h"

#include "OpenGLPicture.h"

#include"../glad/include/glad/glad.h"
#include"../glfw/include/GLFW/glfw3.h"
#include "../Utilities.h"
#include "stb_image.h"

namespace ot {
	OpenGLPicture::OpenGLPicture(const std::string& file) 
	{
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);


		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(file.c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			OT_ERROR("Failed to load a picture from the file!!!");
		}
		stbi_image_free(data);
	}

	OpenGLPicture::OpenGLPicture(std::string&& file)
	{
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);


		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(std::move(file.c_str()), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			OT_ERROR("Failed to load a picture from the file!!!");
		}
		stbi_image_free(data);
	}

	void OpenGLPicture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, texture);
	}
	
	int OpenGLPicture::GetHeight()
	{
		return height;
	}

	int OpenGLPicture::GetWidth()
	{
		return width;
	}

	OpenGLPicture::~OpenGLPicture()
	{
		//glDeleteProgram(texture);
	}
}