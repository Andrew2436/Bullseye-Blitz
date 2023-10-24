#pragma once

#include"Utilities.h"

namespace ot
{
	template<typename T>
	class OTTER_API OtterApp
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

		bool mShouldContinue{ true };
	};
};

#include"OtterApp.cpp"