#include "main.h"
#include "GAME.h"
#include <DxLib.h>
//using namespace DxLib;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR IpCmdLine, int nCmdShow)
{


	while (true)
	{
		bool endFlag = false;

		ChangeWindowMode(TRUE);

		SetGraphMode(1280, 720, 32);

		//��������
		//SetWaitVSyncFlag(FALSE);

		SetCreateSoundDataType(DX_SOUNDDATATYPE_MEMNOPRESS);

		SetAlwaysRunFlag(TRUE);

		if (DxLib_Init() == -1)
		{
			return -1;
		}

		SetDrawScreen(DX_SCREEN_BACK);


		ScreenFlip();

		int MoveFlag = 1;

		while (!(CheckHitKey(KEY_INPUT_SPACE)))
		{
			ClearDrawScreen();
			DrawFormatString(500, 650, GetColor(200, 0, 0), "Press Space Button\n");
			ScreenFlip();
		}

		//GAME* g = new GAME();
		{
			GAME gameObject;
			gameObject.run();
		}

		while(!0)// (!(CheckHitKey(KEY_INPUT_RETURN)))
		{
			//ClearDrawScreen();
			DrawFormatString(500, 650, GetColor(200, 0, 0), "�G���^�[�L�[�������ƏI�����܂�\n");
			DrawFormatString(500, 690, GetColor(200, 0, 0), "�X�y�[�X�L�[�������Ƒ��s���܂�\n");
			ScreenFlip();

			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				endFlag = true;
				break;
			}

			if (CheckHitKey(KEY_INPUT_SPACE))
			{
				endFlag = false;
				break;
			}
		}

		if(endFlag) break;

	}
		DxLib_End();

	return _CrtDumpMemoryLeaks();
}

