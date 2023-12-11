#include"pch.h"
#include"Picture.h"
#include"GLFWCode/OpenGLPicture.h"

namespace ot {
	ot::Picture::Picture(const std::string& file)
	{
#ifdef OTTER_MSCPP
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(file) };
#elif OTTER_APPLE
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(file) };
#elif OTTER_LINUX
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(file) };
#endif
	}

	void Picture::Bind()
	{
		return mImplementation->Bind();
	}

	int Picture::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	int Picture::GetWidth() const
	{
		return mImplementation->GetWidth();
	}
}