#include"Otter.h"

#include<iostream>

class MyGame : public ot::OtterApp<MyGame>
{
public:
	MyGame()
	{
		SetKeyPressedCallback([this](const ot::KeyPressed& e) {OnKeyPress(e); });
	}
	virtual void OnUpdate() override
	{
		//std::cout << "Otter running" << std::endl;

		//Draw(x, y, mPic);
		Draw(mUnit);
	}

	void OnKeyPress(const ot::KeyPressed& e)
	{
		if (e.GetKeyCode() == OTTER_KEY_RIGHT)
			//x += 50;
			mUnit.UpdateXCoord(50);
		else if (e.GetKeyCode() == OTTER_KEY_LEFT)
			//x -= 50;
			mUnit.UpdateXCoord(-50);
	}
private:
	ot::Picture mPic{ "../Assets/Pictures/test.png" };
	ot::Unit mUnit{ "../Assets/Pictures/test.png", 100, 500 };

	int x{ 100 };
	int y{ 100 };
};

OTTER_APPLICATION_START(MyGame);