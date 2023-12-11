#pragma once

namespace ot
{
	class PictureImplementation
	{
	public:
		virtual void Bind() = 0;
		virtual int GetHeight() = 0;
		virtual int GetWidth() = 0;

		virtual ~PictureImplementation() {};
	};
}