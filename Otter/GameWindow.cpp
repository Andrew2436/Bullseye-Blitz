#include"pch.h"

#include "GameWindow.h"
#include "GLFWCode/GLFWImplementation.h"

namespace ot
{
	GameWindow::GameWindow()
	{
#ifdef OTTER_MSCPP
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif OTTER_APPLE
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif OTTER_LINUX
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#endif

	}


	void GameWindow::Create(const std::string& name, int width, int height)
	{
		mImplementation->Create(name, width, height);
	}

	int GameWindow::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	int GameWindow::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	void GameWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

	void GameWindow::PollEvents()
	{
		mImplementation->PollEvents();
	}

}