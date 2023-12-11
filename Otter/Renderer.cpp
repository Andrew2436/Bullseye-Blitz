#include "pch.h"
#include "Renderer.h"
#include "GLFWCode/OpenGLRenderer.h"

ot::Renderer::Renderer()
{
#ifdef OTTER_MSCPP
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif OTTER_APPLE
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif OTTER_LINUX
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#endif
}

void ot::Renderer::Init()
{
	mImplementation->Init();
}

void ot::Renderer::Draw(int x, int y, Picture& pic)
{
	mImplementation->Draw(x, y, pic);
}

void ot::Renderer::Clear()
{
	mImplementation->Clear();
}