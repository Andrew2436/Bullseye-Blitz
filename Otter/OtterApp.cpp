#include"pch.h"
#include "OtterApp.h"

namespace ot
{
	template<typename T>
	OtterApp<T>::OtterApp()
	{
	}

	template<typename T>
	void OtterApp<T>::Init()
	{
		if (sInstance == nullptr)
			sInstance = new T;
	}

	template<typename T>
	void OtterApp<T>::RunInterface()
	{
		sInstance->Run();
	}

	template<typename T>
	void OtterApp<T>::Run()
	{
		mWindow.Create("Game AW", 1000, 800);

		while (mShouldContinue)
		{
			OnUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}

	template<typename T>
	void OtterApp<T>::OnUpdate()
	{
	}
}