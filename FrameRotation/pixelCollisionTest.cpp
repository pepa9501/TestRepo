#include "stdafx.h"
#include "pixelCollisionTest.h"


pixelCollisionTest::pixelCollisionTest()
{
}


pixelCollisionTest::~pixelCollisionTest()
{
}

HRESULT pixelCollisionTest::init(void)
{
	IMAGEMANAGER->addImage("情幾", "mountain.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_ball = IMAGEMANAGER->addImage("因", "ball.bmp", 60, 60, true, RGB(255, 0, 255));

	_x = WINSIZEX / 2 - 100;
	_y = WINSIZEY / 2 + 110;

	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());

	//貼紫逐精 OO拭 実特
	//-> 陥製 OO生稽 硝限精 源精 : 
	_probeY = _y + _ball->getHeight() / 2;

	return S_OK;
}

void pixelCollisionTest::release(void)
{

}

void pixelCollisionTest::update(void)
{
	//薦析 掻推廃闇 尻至 焼艦畏柔艦科たたたたたたたた

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 3.0f;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 3.0f;
	}

	//貼紫逐精 叔獣娃生稽 左舛背層陥
	_probeY = (int)_y + _ball->getHeight() / 2;


	//骨是澗 
	for (int i = _probeY - 50; i < _probeY + 50; ++i)
	{
		//波漆 舛左葵聖 亜閃人辞 鎮君傾遁訓什拭 眼焼黍陥
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("情幾")->getMemDC(), _x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_y = i - _ball->getHeight() / 2;
			break;
		}
	}

	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());

}

void pixelCollisionTest::render(void)
{
	IMAGEMANAGER->findImage("情幾")->render(getMemDC(), 0, 0);

	_ball->render(getMemDC(), _rc.left, _rc.top);


}