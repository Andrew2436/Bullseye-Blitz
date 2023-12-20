#pragma once

#include"pch.h"
#include"PictureImplementation.h"

namespace ot
{
	class OpenGLPicture : public PictureImplementation
	{
	public:
		OpenGLPicture(const std::string& file);
		OpenGLPicture(std::string&& file);
		~OpenGLPicture();

		virtual void Bind() override;
		virtual int GetWidth() override;
		virtual int GetHeight() override;
	private:
		unsigned int texture;
		int width{ 0 };
		int height{ 0 };
	};
}