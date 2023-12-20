#include "MyGame.h"
#include <iostream>

MyGame::MyGame()
{
    SetKeyPressedCallback([this](const ot::KeyPressed& e) {OnKeyPress(e); });

}
void MyGame::OnUpdate()
{
    Draw(mBackground);
    Draw(mFire);
    Draw(mArcher);
    Draw(mMonkey);
    Draw(mBanana); //can only be gained after stage 4, apple only after stage 2 but much harder to get

    if (ot::UnitsOverlap(mArrow, mBanana)) //if arrow hits banana
    {
        mBananaActive = false;
        mArrowActive = false;
        mArrow.SetCoords(500, 100); //resets arrow
        lives = 1; //gain extra life
    }

    if (ot::UnitsOverlap(mArrow, mApple)) //if arrow hits apple, special event caused by low % chance to hit small fast apple
    {
        mArrow = { "../Assets/Pictures/arrow2.png", 475, 100 }; //arrow becomes on fire, thought about increasing size but don't want game to be easier
        arrowVelocity = 15; //arrow moves faster
        mAppleActive = false;  //apple disappears
        mApple.SetCoords(-100, -100);
        mArrowActive = false; //arrow reset
        mFire.SetCoords(450, 25); //character is on fire
        mBackground = { "../Assets/Pictures/Background2.png", 0, 0 }; //change background
        mMonkey.SetCoords(365, 32); //make monkey move away from fire
        mHeart.SetCoords(390, 70); //adjust heart with monkey
    }

    if (ot::UnitsOverlap(mArrow, mTarget)) //if arrow hits target
    {
        if (level < 2) //before stage 3 (stage starts at level 0)
        {
            mArrowActive = false;
            targetY = targetY + 75; //target moves higher
            velocity = velocity + 2; //target becomes faster
            mTarget.SetCoords(targetX, targetY); //respawns target
            mArrow.SetCoords(500, 100); //respawns arrow
            level++; //increments the level
        }

        else if (level >= 2 && level < 5)
        {
            mTargetActive = false;
            mArrowActive = false;
            changeSize(); //make target size smaller
            targetY = targetY + 75;
            velocity = velocity + 2;
            mTargetActive = true;
            Draw(mTarget); //redraws target
            mArrow.SetCoords(500, 100);
            mTarget.SetCoords(475, targetY + 75);
            level++;
        }

        else if (level == 5) //if hit, victory
        {
            Draw(mVictory);
            mTargetActive = false;
            mArrowActive = false;
            mGameActive = true;
            mAppleActive = false;
        }
    }

    if (mTargetActive) //if target is active
    {
        mTarget.UpdateXCoord(direction * velocity); //make target move with current velocity
        if (mTarget.GetXCoord() < 5 || mTarget.GetXCoord() > 930) //if reaches a bound
            direction *= -1; //turn target around
        Draw(mTarget);
    }

    if (mArrowActive)
    {
        mArrow.UpdateYCoord(arrowVelocity); // Make arrow go up
        Draw(mArrow);
    }

    if (mArrow.GetYCoord() > mTarget.GetYCoord() + 75) //if arrow flies past target, ie clear miss
    {
        if (lives > 0) //check if you have extra life
        {
            mArrow.SetCoords(500, 100); //resets arrow 
            mArrowActive = false;
            lives--;
        }
        else //no extra life = end game
        {
            Draw(mGameL);
            mTargetActive = false;
            mArrowActive = false;
            mGameActive = true;
            mAppleActive = false;
            mBananaActive = false;
        }
    }

    if (!mBananaActive)// && mBanana.GetYCoord()>35)
    {
        Draw(mHeart); //if banana == hit, monkey == happy
        if (mBanana.GetYCoord() > 35)
            mBanana.UpdateYCoord(-5); // falls until monkey can get it
    }

    if (mGameActive)
    {
        mGameL.UpdateYCoord(Ydirection); //bobble speed
        if (mGameL.GetYCoord() < 550 || mGameL.GetYCoord() > 650)
            Ydirection = Ydirection * -1; //changes direction
        Draw(mTarget); //shows how much you missed by
        Draw(mArrow);
        Draw(mApple);
    }

    if (mAppleActive) //makes sure Apple moves around and doesn't leave boundaries
    {
        mApple.UpdateXCoord(applespeed);
        if (mApple.GetXCoord() < 1 || mApple.GetXCoord() > 980) 
            applespeed *= -1;
        Draw(mApple);
    }

    if (mBananaActive) //makes sure Banana moves around and doesn't leave boundaries
    {
        mBanana.UpdateXCoord(bananaSpeed);
        if (mBanana.GetXCoord() < 1 || mBanana.GetXCoord() > 980)
            bananaSpeed *= -1;
        Draw(mBanana);
    }
}
void MyGame::OnKeyPress(const ot::KeyPressed& e)
{
    if (e.GetKeyCode() == OTTER_KEY_SPACE && !mArrowActive)
    {
        mArrowActive = true; //Activate the arrow (start moving it)
    }
}

void MyGame::changeSize() //change the arrow fired
{
    mTarget = { "../Assets/Pictures/target2.png", targetX, targetY };
}
