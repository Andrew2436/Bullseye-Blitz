#pragma once

#include "Utilities.h"

namespace ot
{
	class OTTER_API KeyPressed
	{
	public:
		KeyPressed(int kCode);

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class OTTER_API KeyReleased
	{
	public: 
		KeyReleased(int kCode);

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class OTTER_API WindowClosed
	{

	};
}