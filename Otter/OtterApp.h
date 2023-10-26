#pragma once

#include"Utilities.h"
#include"GameWindow.h"

namespace ot
{
	template<typename T>
	class OtterApp
	{
	public:
		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate() = 0;

		friend typename T;

	private:
		OtterApp();

		inline static OtterApp* sInstance{ nullptr };

		GameWindow mWindow;

		bool mShouldContinue{ true };
	};
};

#include"OtterApp.cpp"