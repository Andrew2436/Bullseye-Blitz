#include"Otter.h"

#include<iostream>

class MyGame : public ot::OtterApp<MyGame>
{
public:
	virtual void OnUpdate() override
	{
		std::cout << "Otter running" << std::endl;


	}
};

OTTER_APPLICATION_START(MyGame);