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
		while (mShouldContinue)
		{
			OnUpdate();
		}
	}

	template<typename T>
	void OtterApp<T>::OnUpdate()
	{
	}
}