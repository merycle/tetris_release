#pragma once
#include <random>
#include <thread>
#include <mutex>

#include <DxLib.h>
#include <iostream>
#include <fstream>

class GAME
{

public:

	enum BLOCK_TYPE
	{		
		BLOCK_TYPE_I,
		BLOCK_TYPE_O,
		BLOCK_TYPE_S,
		BLOCK_TYPE_Z,
		BLOCK_TYPE_J,
		BLOCK_TYPE_L,
		BLOCK_TYPE_T,
		BLOCK_TYPE_NUM

	};

	enum BLOCK_ANGLE
	{
		BLOCK_ANGLE_0,
		BLOCK_ANGLE_90,
		BLOCK_ANGLE_180,
		BLOCK_ANGLE_270,
		BLOCK_ANGLE_NUM
	};

	enum SOUND_TYPE
	{
		KOKA,
		KAKO,
		KA,
		DON,
		PIRORON,
		SOUND_NUM
	};


private:

	char buffer[128];
	char buffer1[256];
	std::string line;
	
	int fontHandle = CreateFontToHandle(NULL, 40, 3);

	int gameStatus = 0; //0:正常　1:ゲームオーバー


	int startTime = 0;
	int previousTime = 0;
	int gameTime = 0;
	int passTime = 0;
	int pressLeftTime = 0;
	int pressRightTime = 0;

	double deltaTime = 0.0;
	

	int pressX = 0;
	int pressZ = 0;
	int pressLeft = 0;
	int pressRight = 0;
	int pressDown = 0;
	int pressUp = 0;
	

	std::random_device rd;
	int random_block[1000];
	int random_block_number = 0;

	
	bool isFull = true;
	bool isTetris = false;

	
	int soundON[GAME::SOUND_NUM] = { 0 };

	int score = 0;
	
	std::ofstream scoreFile;
	std::ifstream stream;
		

private:
	class BLOCK_STAGE* _block_stage;
	class BLOCK* _block[BLOCK_TYPE_NUM];


public:
	
	GAME();
	~GAME();
	void run();

	class BLOCK_STAGE* block_stage() { return _block_stage; }
	class BLOCK* block(int i) { return _block[i]; }

	
	double getDeltaTime() //const
	{
		return deltaTime;
	}

	int get_startTime() { return startTime; }

	int get_gameTime() { return gameTime; }
	void set_gameTime(int t) { gameTime = t; }

	int get_passTime() { return passTime; }
	void set_passTime(int t) { passTime = t; }

	int get_pressLeftTime() { return pressLeftTime; }
	void set_pressLeftTime(int t) { pressLeftTime = t; }
	
	int get_pressRightTime() { return pressRightTime; }
	void set_pressRightTime(int t) { pressRightTime = t; }

	
	int get_pressX() { return pressX; }
	void set_pressX(int n) { pressX = n; }

	int get_pressZ() { return pressZ; }
	void set_pressZ(int n) { pressZ = n; }

	int get_pressLeft() { return pressLeft; }
	void set_pressLeft(int n) { pressLeft = n; }

	int get_pressRight() { return pressRight; }
	void set_pressRight(int n) { pressRight = n; }

	int get_pressDown() { return pressDown; }
	void set_pressDown(int n) { pressDown = n; }

	int get_pressUp() { return pressUp; }
	void set_pressUp(int n) { pressUp = n; }


	int get_random_block(int i) { return random_block[i]; }


	int get_random_block_number() { return random_block_number; }
	void set_random_block_number(int n) { random_block_number = n; }


	int get_soundON(int i) { return soundON[i]; }
	void set_soundON(int i,int j) { soundON[i] = j; }
		

	void kari();
		
};
