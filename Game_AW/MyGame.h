#pragma once

#include "Otter.h"
#include <iostream>

class MyGame : public ot::OtterApp<MyGame> 
{
public:
	MyGame();
	virtual void OnUpdate() override;
    void changeSize();

private:
	void OnKeyPress(const ot::KeyPressed& e);

    int direction{ 1 };
    int Ydirection{ 1 }; //bobble speed
    int targetX = 450;
    int targetY = 300;
    int velocity{ 5 };
    int level = 0;
    int applespeed = 15;
    int arrowVelocity = 10;
    int bananaSpeed = 5;
    int lives = 0;

    ot::Unit mArcher{ "../Assets/Pictures/archer.png", 475, 32 };
    ot::Unit mFire{ "../Assets/Pictures/fire.png", -150, -150 };
    ot::Unit mArrow{ "../Assets/Pictures/arrow.png", 500, 100 };
    ot::Unit mTarget{ "../Assets/Pictures/target.png", targetX, targetY };
    ot::Unit mGameL{ "../Assets/Pictures/gameend.png", 460, 600 }; //gameover unit
    ot::Unit mBackground{ "../Assets/Pictures/Background.png", 0, 0 };
    ot::Unit mApple{ "../Assets/Pictures/apple.png", 5, 500 };
    ot::Unit mVictory{ "../Assets/Pictures/victory.png", 380, 400 };
    ot::Unit mMonkey{ "../Assets/Pictures/monkey.png", 425, 32 };
    ot::Unit mBanana{ "../Assets/Pictures/banana.png", 1, 600 };
    ot::Unit mHeart{ "../Assets/Pictures/love.png", 450, 70 };

    bool mArrowActive{ false };
    bool mTargetActive{ true };
    bool mGameActive{ false };
    bool mAppleActive{ true };
    bool mBananaActive{ true };
};