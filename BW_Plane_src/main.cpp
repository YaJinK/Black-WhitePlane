#include "variable_definition.h"

//程序入口
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	all_hIns = hInstance;
	game_init();

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = APPNAME.c_str();
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, "Call to RegisterClassEx failed!", "Win32 Guided Tour", NULL);
		return 1;
	}

	HWND hWnd = CreateWindow(
		APPNAME.c_str(),
		APPNAME.c_str(),
		WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 600,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL, "Call to CreateWindow failed!", "Win32 Guided Tour", NULL);
		return 1;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (!appOver)
	{
		if (GetMessage(&msg, hWnd, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		game_run(hWnd);
	}
	clear();
	PostQuitMessage(0);
	return msg.wParam;
}

//回调函数，响应信息
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	HDC bufferdc;

	switch (msg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		bufferdc = CreateCompatibleDC(hdc);
		SelectObject(bufferdc, p_back->getBBit());
		BitBlt(hdc, 0, 0, 150, 600, bufferdc, 0, 0, SRCCOPY);
		SelectObject(bufferdc, p_back->getWBit());
		BitBlt(hdc, 650, 0, 800, 600, bufferdc, 0, 0, SRCCOPY);
		MoveToEx(hdc, 650, 0, NULL);
		LineTo(hdc, 650, 600);
		DeleteDC(bufferdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_KEYUP:
		if (0x53 == wParam)
		{
			CPlane* p = (CPlane*)vector_plane.at(0);
			if (p->getPower() == 1)
			{
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 2,
					p->getLocation().y - p->getHeight() + 13, 1));
			}
			if (p->getPower() == 2)
			{
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 2,
					p->getLocation().y - p->getHeight() + 10, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 24,
					p->getLocation().y - p->getHeight() + 23, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 + 20,
					p->getLocation().y - p->getHeight() + 23, 1));
			}
			if (p->getPower() == 3)
			{
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 2,
					p->getLocation().y - p->getHeight() + 10, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 24,
					p->getLocation().y - p->getHeight() + 23, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 + 20,
					p->getLocation().y - p->getHeight() + 23, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 46,
					p->getLocation().y - p->getHeight() + 36, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 + 42,
					p->getLocation().y - p->getHeight() + 36, 1));
			}
			if (p->getPower() == 4)
			{
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 2,
					p->getLocation().y - p->getHeight() + 10, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 24,
					p->getLocation().y - p->getHeight() + 23, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 + 20,
					p->getLocation().y - p->getHeight() + 23, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 46,
					p->getLocation().y - p->getHeight() + 36, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 + 42,
					p->getLocation().y - p->getHeight() + 36, 1));

				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role2.bmp",
					p->getLocation().x + p->getWidth() / 2 - 85,
					p->getLocation().y - p->getHeight() + 50, 2));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role2.bmp",
					p->getLocation().x + p->getWidth() / 2 - 98,
					p->getLocation().y - p->getHeight() + 70, 2));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role3.bmp",
					p->getLocation().x + p->getWidth() / 2 + 52,
					p->getLocation().y - p->getHeight() + 50, 3));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role3.bmp",
					p->getLocation().x + p->getWidth() / 2 + 70,
					p->getLocation().y - p->getHeight() + 70, 3));

				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 2,
					p->getLocation().y + p->getHeight(), 4));
			}
			if (p->getPower() == 5)
			{
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 2,
					p->getLocation().y - p->getHeight() + 10, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 2,
					p->getLocation().y - p->getHeight() - 50, 1));

				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 24,
					p->getLocation().y - p->getHeight() + 23, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 30,
					p->getLocation().y - p->getHeight() - 32, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 + 20,
					p->getLocation().y - p->getHeight() + 23, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 + 26,
					p->getLocation().y - p->getHeight() - 32, 1));

				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 46,
					p->getLocation().y - p->getHeight() + 36, 1));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 + 42,
					p->getLocation().y - p->getHeight() + 36, 1));

				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role2.bmp",
					p->getLocation().x + p->getWidth() / 2 - 85,
					p->getLocation().y - p->getHeight() + 50, 2));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role2.bmp",
					p->getLocation().x + p->getWidth() / 2 - 98,
					p->getLocation().y - p->getHeight() + 70, 2));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role2.bmp",
					p->getLocation().x + p->getWidth() / 2 - 111,
					p->getLocation().y - p->getHeight() + 90, 2));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role3.bmp",
					p->getLocation().x + p->getWidth() / 2 + 52,
					p->getLocation().y - p->getHeight() + 50, 3));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role3.bmp",
					p->getLocation().x + p->getWidth() / 2 + 70,
					p->getLocation().y - p->getHeight() + 70, 3));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role3.bmp",
					p->getLocation().x + p->getWidth() / 2 + 88,
					p->getLocation().y - p->getHeight() + 90, 3));

				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role2.bmp",
					p->getLocation().x + p->getWidth() / 2 + 5,
					p->getLocation().y + p->getHeight(), 5));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role3.bmp",
					p->getLocation().x + p->getWidth() / 2 - 40,
					p->getLocation().y + p->getHeight(), 6));
				vector_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_role.bmp",
					p->getLocation().x + p->getWidth() / 2 - 2,
					p->getLocation().y + p->getHeight(), 4));
			}
		}
		break;
	case WM_DESTROY:
		appOver = true;
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//对游戏的初始内容赋值
void game_init()
{
	score = 0;
	timer = 0; 
	deadtime = 0;
	appOver = false;
	isLive = true;
	if (!gameStart)
	{
		gameStart = true;
	}
	vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_role.bmp", 340, 450, 3, 1));
	p_back = new CBack(all_hIns, ".\\images\\background.bmp", ".\\images\\b.bmp", ".\\images\\w.bmp", ".\\images\\caption.bmp", (800 - screen_width) / 2, 0, 9000);
}

//主要游戏运行函数，包括键盘响应，界面的重绘
void game_run(HWND &hWnd)
{
	Sleep(10);
	HDC hdc = GetDC(hWnd);

	if (isCaption)
	{
		if (GetAsyncKeyState(VK_RETURN) & 0X8000)
		{
			gameStart = true;
			isCaption = false;
		}
		//draw caption
		startView(hdc);
		return;
	}
	if (gameStart)
	{
		if (GetAsyncKeyState(VK_F1) & 0X8000)
		{
			save();
		}
		if (GetAsyncKeyState(VK_F2) & 0X8000)
		{
			load();
			RECT rect{ 150, 520, 650, 600 };
			HBRUSH brush = (HBRUSH)GetStockObject(WHITE_BRUSH);
			FillRect(hdc, &rect, brush);
		}
		if (GetAsyncKeyState(VK_F3) & 0X8000)
		{
			if (!noHurt)
			{
				noHurt = true;
			}
			else
			{
				noHurt = true;
			}
		}
		timer++;
		if (GetAsyncKeyState(VK_BACK) & 0X8000)
		{
			gameStart = false;
			gamePause = true;
			title = "Pause";
		}
		planeAction();
		if (isLive)
		{
			//planeBoomAction
			isHurt();
		}
		if (timer - deadtime < 150)
		{
			RECT rect;
			rect.left = vector_plane.at(0)->getLocation().x;
			rect.top = vector_plane.at(0)->getLocation().y;
			rect.right = rect.left + vector_plane.at(0)->getWidth();
			rect.bottom = rect.top + vector_plane.at(0)->getHeight();
			SelectObject(hdc, (HBRUSH)GetStockObject(NULL_BRUSH));
			Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);
			Ellipse(hdc, rect.left - 10, rect.top, rect.right + 10, rect.bottom);
			isLive = false;
		}
		if (timer - deadtime == 150)
		{
			isLive = true;
		}
		//控制背景卷动
		if (timer == 4000)
		{
			p_back->setSpeed(p_back->getSpeed() + 10);
		}
		p_back->setBegin(p_back->getBegin() - p_back->getSpeed());
		if (p_back->getBegin() < 0)
		{
			p_back->setBegin(1600);
		}
		//控制敌机登场 enemy come
		enemyCome();
		// bullet action
		bulletAction();
		// enemy leave
		upgradeMove();
		enemyLeave();
		getUpgrade();
		draw(hdc);
	}
	else
	{
		if (gamePause)
		{
			game_pause(hdc);
		}
		else
		{
			game_over(hdc);
		}
	}
	InvalidateRect(hWnd, NULL, false);
	
	DeleteDC(hdc);
}
//暂停界面绘制
void game_pause(HDC &hdc)
{
	RECT rect{ 150, 0, 650, 600 };
	FillRect(hdc, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
	HFONT font = CreateFont(70, 0, 0, 0, 400, 0, 0, 0, CP_UTF8, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MyFont");
	rect.top = 70;
	SelectObject(hdc, font);
	DrawText(hdc, title.c_str(), title.length(), &rect, DT_CENTER);

	rect.top = 170;
	font = CreateFont(70, 0, 0, 0, 400, 0, 0, 0, CP_UTF8, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MyFont");
	SelectObject(hdc, font);
	DrawText(hdc, "SCORE", 5, &rect, DT_CENTER);
	DeleteObject(font);
	rect.top = 250;
	font = CreateFont(50, 0, 0, 0, 400, 0, 0, 0, CP_UTF8, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MyFont");
	SelectObject(hdc, font);
	char s[20];
	_itoa_s(score, s, 10);
	DrawText(hdc, s, strlen(s), &rect, DT_CENTER);
	DeleteObject(font);
	rect.top = 350;
	font = CreateFont(20, 0, 0, 0, 400, 0, 0, 0, CP_UTF8, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MyFont");
	SelectObject(hdc, font);
	DrawText(hdc, "Press ENTER to continue", strlen("Press ENTER to continue"), &rect, DT_CENTER);
	DeleteObject(font);
	rect.top = 390;
	font = CreateFont(20, 0, 0, 0, 400, 0, 0, 0, CP_UTF8, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MyFont");
	SelectObject(hdc, font);
	DrawText(hdc, "Press ESC to exit", strlen("Press ESC to exit"), &rect, DT_CENTER);
	DeleteObject(font);
	if (GetAsyncKeyState(VK_RETURN) & 0X8000)
	{
		gameStart = true;
		gamePause = false;
	}
	if (GetAsyncKeyState(VK_ESCAPE) & 0X8000)
	{
		appOver = true;
	}
	DeleteObject(font);
}
//游戏结束界面绘制
void game_over(HDC &hdc)
{
	RECT rect{ 150, 0, 650, 600 };
	HBRUSH brush = (HBRUSH)GetStockObject(BLACK_BRUSH);
	FillRect(hdc, &rect, brush);
	SetBkColor(hdc, RGB(0, 0, 0));
	SetTextColor(hdc, RGB(255, 255, 255));
	rect.top = 70;
	HFONT font = CreateFont(80, 0, 0, 0, 400, 0, 0, 0, CP_UTF8, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MyFont");
	SelectObject(hdc, font);
	DrawText(hdc, title.c_str(), title.length(), &rect, DT_CENTER);
	DeleteObject(font);
	rect.top = 170;
	font = CreateFont(70, 0, 0, 0, 400, 0, 0, 0, CP_UTF8, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MyFont");
	SelectObject(hdc, font);
	DrawText(hdc, "SCORE", 5, &rect, DT_CENTER);
	DeleteObject(font);
	rect.top = 250;
	font = CreateFont(50, 0, 0, 0, 400, 0, 0, 0, CP_UTF8, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MyFont");
	SelectObject(hdc, font);
	char s[20];
	_itoa_s(score, s, 10);
	DrawText(hdc, s, strlen(s), &rect, DT_CENTER);
	DeleteObject(font);
	rect.top = 350;
	font = CreateFont(20, 0, 0, 0, 400, 0, 0, 0, CP_UTF8, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MyFont");
	SelectObject(hdc, font);
	DrawText(hdc, "Press ENTER to restart", strlen("Press ENTER to restart"), &rect, DT_CENTER);
	DeleteObject(font);
	rect.top = 390;
	font = CreateFont(20, 0, 0, 0, 400, 0, 0, 0, CP_UTF8, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MyFont");
	SelectObject(hdc, font);
	DrawText(hdc, "Press ESC to exit", strlen("Press ESC to exit"), &rect, DT_CENTER);
	DeleteObject(font);
	rect.top = 450;
	font = CreateFont(30, 0, 0, 0, 400, 0, 0, 0, CP_UTF8, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MyFont");
	SelectObject(hdc, font);
	DrawText(hdc, "Thanks for playing!", strlen("Thanks for playing!"), &rect, DT_CENTER);
	DeleteObject(font);
	if (GetAsyncKeyState(VK_RETURN) & 0X8000)
	{
		gameStart = true;
		gamePause = false;
		brush = (HBRUSH)GetStockObject(WHITE_BRUSH);
		rect.top = 0;
		FillRect(hdc, &rect, brush);
		clear();
		game_init();
	}
	if (GetAsyncKeyState(VK_ESCAPE) & 0X8000)
	{
		appOver = true;
	}
	DeleteObject(brush);
	DeleteObject(font);
}
//游戏开始界面绘制
void startView(HDC &hdc)
{
	HDC bufferdc = CreateCompatibleDC(hdc);
	SelectObject(bufferdc, p_back->getCaptionBit());
	HFONT font = CreateFont(35, 0, 0, 0, 400, 0, 0, 0, CP_UTF8, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MyFont");
	SelectObject(bufferdc, font);
	TextOut(bufferdc, 110, 420, "Press", strlen("Press"));
	COLORREF color = SetTextColor(bufferdc, RGB(255, 0, 0));
	TextOut(bufferdc, 205, 420, "ENTER", strlen("ENTER"));
	SetTextColor(bufferdc, color);
	TextOut(bufferdc, 330, 420, "to start!", strlen("to start!"));
	BitBlt(hdc, 150, 0, 650, 600, bufferdc, 0, 0, SRCCOPY);
	DeleteObject(font);
	DeleteDC(bufferdc);
}
//己方飞机移动
void planeAction()
{
	if (GetAsyncKeyState(VK_LEFT) & 0X8000)
	{
		if (vector_plane.at(0)->getLocation().x > 151)
		{
			vector_plane.at(0)->move(vector_plane.at(0)->getLocation().x - vector_plane.at(0)->getSpeed(), vector_plane.at(0)->getLocation().y);
		}
	}
	if (GetKeyState(VK_RIGHT) & 0X8000)
	{
		if (vector_plane.at(0)->getLocation().x < 549)
		{
			vector_plane.at(0)->move(vector_plane.at(0)->getLocation().x + vector_plane.at(0)->getSpeed(), vector_plane.at(0)->getLocation().y);
		}
	}
	if (GetKeyState(VK_UP) & 0X8000)
	{
		if (vector_plane.at(0)->getLocation().y > 0)
		{
			vector_plane.at(0)->move(vector_plane.at(0)->getLocation().x, vector_plane.at(0)->getLocation().y - vector_plane.at(0)->getSpeed());
		}
	}
	if (GetKeyState(VK_DOWN) & 0X8000)
	{
		if (vector_plane.at(0)->getLocation().y < 452)
		{
			vector_plane.at(0)->move(vector_plane.at(0)->getLocation().x, vector_plane.at(0)->getLocation().y + vector_plane.at(0)->getSpeed());
		}
	}
	
}
//己方飞机伤害判定
void isHurt()
{
	for (voi = vector_plane.begin() + 1; voi != vector_plane.end(); voi++)
	{
		int i = vector_plane.at(0)->getLocation().x + vector_plane.at(0)->getWidth() / 2;
		int j = vector_plane.at(0)->getLocation().y;
		bool flag = (i > (*voi)->getLocation().x && i < (*voi)->getLocation().x + (*voi)->getWidth()) && (j >(*voi)->getLocation().y && j < (*voi)->getLocation().y + (*voi)->getHeight());
		j = vector_plane.at(0)->getLocation().y + vector_plane.at(0)->getHeight();
		bool flag2 = (i >(*voi)->getLocation().x && i < (*voi)->getLocation().x + (*voi)->getWidth()) && (j >(*voi)->getLocation().y && j < (*voi)->getLocation().y + (*voi)->getHeight());
		i = vector_plane.at(0)->getLocation().x;
		j = vector_plane.at(0)->getLocation().y + vector_plane.at(0)->getHeight() / 2;
		bool flag3 = (i >(*voi)->getLocation().x && i < (*voi)->getLocation().x + (*voi)->getWidth()) && (j >(*voi)->getLocation().y && j < (*voi)->getLocation().y + (*voi)->getHeight());
		i = vector_plane.at(0)->getLocation().x + vector_plane.at(0)->getWidth();
		bool flag4 = (i >(*voi)->getLocation().x && i < (*voi)->getLocation().x + (*voi)->getWidth()) && (j >(*voi)->getLocation().y && j < (*voi)->getLocation().y + (*voi)->getHeight());
		if (flag || flag2 || flag3 || flag4)
		{
			CPlane* p = (CPlane*)vector_plane.at(0);
			if (!noHurt)
				p->setLife(p->getLife() - 1);
			if (p->getLife() < 0)
			{
				gameStart = false;
				title = "YOU LOSE!";
				p_num = 0;
				s_num = 0;
			}
			isLive = false;
			deadtime = timer;
			vector_plane.at(0)->move(350, 420);
			break;
		}
	}
	//敌方子弹是否击中
	for (voi = vector_enemy_bullet.begin(); voi != vector_enemy_bullet.end();)
	{
		int i = vector_plane.at(0)->getLocation().x + vector_plane.at(0)->getWidth() / 2;
		int j = vector_plane.at(0)->getLocation().y;
		bool flag = (i > (*voi)->getLocation().x && i < (*voi)->getLocation().x + (*voi)->getWidth()) && (j >(*voi)->getLocation().y && j < (*voi)->getLocation().y + (*voi)->getHeight());
		j = vector_plane.at(0)->getLocation().y + vector_plane.at(0)->getHeight();
		bool flag2 = (i > (*voi)->getLocation().x && i < (*voi)->getLocation().x + (*voi)->getWidth()) && (j >(*voi)->getLocation().y && j < (*voi)->getLocation().y + (*voi)->getHeight());
		i = vector_plane.at(0)->getLocation().x;
		j = vector_plane.at(0)->getLocation().y + vector_plane.at(0)->getHeight() / 2;
		bool flag3 = (i > (*voi)->getLocation().x && i < (*voi)->getLocation().x + (*voi)->getWidth()) && (j >(*voi)->getLocation().y && j < (*voi)->getLocation().y + (*voi)->getHeight());
		i = vector_plane.at(0)->getLocation().x + vector_plane.at(0)->getWidth();
		bool flag4 = (i > (*voi)->getLocation().x && i < (*voi)->getLocation().x + (*voi)->getWidth()) && (j >(*voi)->getLocation().y && j < (*voi)->getLocation().y + (*voi)->getHeight());
		i = vector_plane.at(0)->getLocation().x + vector_plane.at(0)->getWidth() / 4;
		bool flag5 = (i >(*voi)->getLocation().x && i < (*voi)->getLocation().x + (*voi)->getWidth()) && (j >(*voi)->getLocation().y && j < (*voi)->getLocation().y + (*voi)->getHeight());
		i = vector_plane.at(0)->getLocation().x + vector_plane.at(0)->getWidth() * 3 / 4;
		bool flag6 = (i >(*voi)->getLocation().x && i < (*voi)->getLocation().x + (*voi)->getWidth()) && (j >(*voi)->getLocation().y && j < (*voi)->getLocation().y + (*voi)->getHeight());
		if (flag || flag2 || flag3 || flag4 || flag5 || flag6)
		{
			CPlane* p = (CPlane*)vector_plane.at(0);
			if (!noHurt)
				p->setLife(p->getLife() - 1);
			if (p->getLife() < 0)
			{
				gameStart = false;
				title = "YOU LOSE!";
				p_num = 0;
				s_num = 0;
			}
			isLive = false;
			deadtime = timer;
			vector_plane.at(0)->move(340, 420);
			delete (*voi);
			voi = vector_enemy_bullet.erase(voi);
		}
		else
		{
			voi++;
		}
	}
}

void getUpgrade()
{
	for (voi = vector_upgrade.begin(); voi != vector_upgrade.end();)
	{
		int i = vector_plane.at(0)->getLocation().x + vector_plane.at(0)->getWidth() / 2;
		int j = vector_plane.at(0)->getLocation().y;
		bool flag = (i > (*voi)->getLocation().x && i < (*voi)->getLocation().x + (*voi)->getWidth()) && (j >(*voi)->getLocation().y && j < (*voi)->getLocation().y + (*voi)->getHeight());
		j = vector_plane.at(0)->getLocation().y + vector_plane.at(0)->getHeight();
		bool flag2 = (i >(*voi)->getLocation().x && i < (*voi)->getLocation().x + (*voi)->getWidth()) && (j >(*voi)->getLocation().y && j < (*voi)->getLocation().y + (*voi)->getHeight());
		i = vector_plane.at(0)->getLocation().x;
		j = vector_plane.at(0)->getLocation().y + vector_plane.at(0)->getHeight() / 2;
		bool flag3 = (i >(*voi)->getLocation().x && i < (*voi)->getLocation().x + (*voi)->getWidth()) && (j >(*voi)->getLocation().y && j < (*voi)->getLocation().y + (*voi)->getHeight());
		i = vector_plane.at(0)->getLocation().x + vector_plane.at(0)->getWidth();
		bool flag4 = (i >(*voi)->getLocation().x && i < (*voi)->getLocation().x + (*voi)->getWidth()) && (j >(*voi)->getLocation().y && j < (*voi)->getLocation().y + (*voi)->getHeight());
		if (flag || flag2 || flag3 || flag4)
		{
			CPlane* p = (CPlane*)vector_plane.at(0);
			CUpgrade* upgrade = (CUpgrade*)(*voi);
			if (upgrade->getStyle() == 'p')
			{
				p->setPower(p->getPower() + 1);
			}
			if (upgrade->getStyle() == 's')
			{
				p->setSpeed(p->getSpeed() + 1);
			}
			delete (*voi);
			voi = vector_upgrade.erase(voi);
		}
		else
		{
			voi++;
		}
	}
}

void upgradeMove()
{
	for (voi = vector_upgrade.begin(); voi != vector_upgrade.end();)
	{
		(*voi)->move((*voi)->getLocation().x, (*voi)->getLocation().y + 3);
		if ((*voi)->getLocation().y > 470)
		{
			delete (*voi);
			voi = vector_upgrade.erase(voi);
		}
		else
		{
			voi++;
		}
	}
}
//判断己方子弹是否出界及是否击中
void bulletAction()
{
	//判断己方子弹是否出界
	for (voi = vector_bullet.begin(); voi != vector_bullet.end();)
	{
		CBullet* b = (CBullet*)*voi;
		bool flag = false;
		if (b->getStyle() != 1)
		{
			flag = (*voi)->getLocation().x > 600;
		}
		if ((*voi)->getLocation().y < 0 || (*voi)->getLocation().x < 150 || flag || (*voi)->getLocation().y > 465)
		{
			delete (*voi);
			voi = vector_bullet.erase(voi);
		}
		else
		{
			if (b->getStyle() == 1)
			{
				(*voi)->move((*voi)->getLocation().x, (*voi)->getLocation().y - 9);
			}
			if (b->getStyle() == 2)
			{
				(*voi)->move((*voi)->getLocation().x - 6, (*voi)->getLocation().y - 6);
			}
			if (b->getStyle() == 3)
			{
				(*voi)->move((*voi)->getLocation().x + 6, (*voi)->getLocation().y - 6);
			}
			if (b->getStyle() == 4)
			{
				(*voi)->move((*voi)->getLocation().x, (*voi)->getLocation().y + 6);
			}
			if (b->getStyle() == 5)
			{
				(*voi)->move((*voi)->getLocation().x + 6, (*voi)->getLocation().y + 6);
			}
			if (b->getStyle() == 6)
			{
				(*voi)->move((*voi)->getLocation().x - 6, (*voi)->getLocation().y + 6);
			}
			voi++;
		}
	}
	//判断敌方子弹是否出界
	for (voi = vector_enemy_bullet.begin(); voi != vector_enemy_bullet.end();)
	{
		CBullet* b = (CBullet*)*voi;
		bool flag = (*voi)->getLocation().y > 455;
		if (b->getStyle() != 4)
		{
			flag = (*voi)->getLocation().y > 490;
		}
		if ((*voi)->getLocation().y < 0 || (*voi)->getLocation().x < 150 || (*voi)->getLocation().x > 620 || flag)
		{
			delete (*voi);
			voi = vector_enemy_bullet.erase(voi);
		}
		else
		{
			if (b->getStyle() == 1)
			{
				(*voi)->move((*voi)->getLocation().x + 2, (*voi)->getLocation().y + 4);
			}
			if (b->getStyle() == 2)
			{
				(*voi)->move((*voi)->getLocation().x - 2, (*voi)->getLocation().y + 4);
			}
			if (b->getStyle() == 3)
			{
				(*voi)->move((*voi)->getLocation().x, (*voi)->getLocation().y + 4);
			}
			if (b->getStyle() == 4)
			{
				(*voi)->move((*voi)->getLocation().x, (*voi)->getLocation().y + 5);
			}
			voi++;
		}
	}
	//判断己方子弹是否击中敌方
	for (voi = vector_bullet.begin(); voi != vector_bullet.end();)
	{
		bool flag = FALSE;
		for (vector<CObject*>::iterator i = vector_plane.begin() + 1; i != vector_plane.end();)
		{
			bool flag1 = ((*voi)->getLocation().x > (*i)->getLocation().x && (*voi)->getLocation().x < (*i)->getLocation().x + (*i)->getWidth())
				&& ((*voi)->getLocation().y < (*i)->getLocation().y + (*i)->getHeight() * 1 / 4 && (*voi)->getLocation().y >(*i)->getLocation().y);
			bool flag2 = ((*voi)->getLocation().x > (*i)->getLocation().x + (*i)->getWidth() * 1 / 8 && (*voi)->getLocation().x < (*i)->getLocation().x + (*i)->getWidth() * 7 / 8)
				&& ((*voi)->getLocation().y < (*i)->getLocation().y + (*i)->getHeight() * 1 / 2 && (*voi)->getLocation().y >(*i)->getLocation().y + (*i)->getHeight() * 1 / 4);
			bool flag3 = ((*voi)->getLocation().x > (*i)->getLocation().x + (*i)->getWidth() * 1 / 4 && (*voi)->getLocation().x < (*i)->getLocation().x + (*i)->getWidth() * 3 / 4)
				&& ((*voi)->getLocation().y < (*i)->getLocation().y + (*i)->getHeight() * 3 / 4 && (*voi)->getLocation().y >(*i)->getLocation().y + (*i)->getHeight() * 1 / 2);
			bool flag4 = ((*voi)->getLocation().x >(*i)->getLocation().x + (*i)->getWidth() * 5 / 11 && (*voi)->getLocation().x < (*i)->getLocation().x + (*i)->getWidth() * 6 / 11)
				&& ((*voi)->getLocation().y < (*i)->getLocation().y + (*i)->getHeight() && (*voi)->getLocation().y >(*i)->getLocation().y + (*i)->getHeight() * 3 / 4);
			if (flag1 || flag2 || flag3 || flag4)
			{
				flag = TRUE;
				score += 40;
				CPlane* p = (CPlane*)(*i);
				p->setLife(p->getLife() - 1);
				
				delete (*voi);
				voi = vector_bullet.erase(voi);
				if (timer > 4100 && p->getLife() == 0)
				{
					gameStart = false;
					title = "YOU WIN!";
					noHurt = false;
				}
				if (p->getLife() == 0)
				{
					srand((unsigned int)time(NULL));
					CPlane* role = (CPlane*)vector_plane.at(0);
					int flag = rand() % 3;
					if (flag == 0 && p_num < 4)
					{
						p_num++;
						vector_upgrade.push_back(new CUpgrade(all_hIns, ".\\images\\powerup.bmp", (*i)->getLocation().x, (*i)->getLocation().y, 'p'));
					}
					if (flag == 1 && s_num < 4)
					{
						s_num++;
						vector_upgrade.push_back(new CUpgrade(all_hIns, ".\\images\\speedup.bmp", (*i)->getLocation().x, (*i)->getLocation().y, 's'));
					}
					delete (*i);
					vector_plane.erase(i);
					score += 100;
				}
				break;
			}
			else
			{
				i++;
			}
		}
		if (!flag)
		{
			voi++;
		}
	}
}
//敌机出现
void enemyCome()
{
	if (timer == 200)
	{
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 200, 0, 2));
	}

	if (timer == 500)
	{
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 470, 0, 2));
	}
	if (timer >= 850 && timer <= 1000)
	{
		if (timer == 850)
		{
			CPlane* p = new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 150, 70, 3);
			vector_plane.push_back(p);
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy.bmp", p->getLocation().x + p->getWidth() / 2, p->getLocation().y + p->getHeight(), 1));
		}
		if (timer == 900)
		{
			CPlane* p = new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 150, 70, 3);
			vector_plane.push_back(p);
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy.bmp", p->getLocation().x + p->getWidth() / 2, p->getLocation().y + p->getHeight(), 1));
		}
		if (timer == 950)
		{
			CPlane* p = new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 150, 70, 3);
			vector_plane.push_back(p);
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy.bmp", p->getLocation().x + p->getWidth() / 2, p->getLocation().y + p->getHeight(), 1));
		}
	}
	if (timer >= 1450 && timer <= 1620)
	{
		if (timer == 1450)
		{
			vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 550, 90, 5));
		}
		if (timer == 1500)
		{
			vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 550, 90, 5));
		}
		if (timer == 1550)
		{
			vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 550, 90, 5));
		}
		if (timer == 1600)
		{
			vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 550, 90, 5));
		}
	}
	if (timer >= 1800 && timer <= 1950)
	{
		if (timer == 1800)
		{
			CPlane* p = new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 550, 50, 5);
			vector_plane.push_back(p);
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy.bmp", p->getLocation().x + p->getWidth() / 2, p->getLocation().y + p->getHeight(), 2));
		}
		if (timer == 1850)
		{
			CPlane* p = new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 550, 50, 5);
			vector_plane.push_back(p);
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy.bmp", p->getLocation().x + p->getWidth() / 2, p->getLocation().y + p->getHeight(), 2));
		}
		if (timer == 1900)
		{
			CPlane* p = new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 550, 50, 5);
			vector_plane.push_back(p);
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy.bmp", p->getLocation().x + p->getWidth() / 2, p->getLocation().y + p->getHeight(), 2));
		}
	}
	if (timer == 2350)
	{
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy2.bmp", 240, -50, 40));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy2.bmp", 420, -50, 40));
	}
	if (timer == 2410 || timer == 2420 || timer == 2430)
	{
		for (voi = vector_plane.begin() + 1; voi != vector_plane.end(); voi++)
		{
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy.bmp", (*voi)->getLocation().x + (*voi)->getWidth() / 2, (*voi)->getLocation().y + (*voi)->getHeight(), 3));
		}
	}
	if (timer == 3000)
	{
		int l = 6;
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 155, 0, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 255, 0, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 355, 0, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 455, 0, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 555, 0, l));

		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 155, -65, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 255, -65, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 355, -65, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 455, -65, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 555, -65, l));

		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 155, -130, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 255, -130, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 355, -130, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 455, -130, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 555, -130, l));

		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 155, -195, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 255, -195, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 355, -195, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 455, -195, l));
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\plane_enemy.bmp", 555, -195, l));
	}

	if (timer == 3100 || timer == 3300 || timer == 3500  || timer == 3700 )
	{
		for (voi = vector_plane.begin() + 1; voi != vector_plane.end(); voi++)
		{
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy.bmp", (*voi)->getLocation().x + (*voi)->getWidth() / 2, (*voi)->getLocation().y + (*voi)->getHeight(), 3));
		}
	}

	if (timer == 4100)
	{
		vector_plane.push_back(new CPlane(all_hIns, ".\\images\\boss.bmp", 200, -242, 1500));
	}
	
}
//敌机离开
void enemyLeave()
{
	for (voi = vector_plane.begin() + 1; voi != vector_plane.end();)
	{
		bool isE = false;
		if ((timer >= 200 && timer <= 448) || (timer >= 500 && timer <= 748))
		{
			(*voi)->move((*voi)->getLocation().x, (*voi)->getLocation().y + 2);
			if ((*voi)->getLocation().y > 450)
			{
				isE = true;
				delete (*voi);
				voi = vector_plane.erase(voi);
			}
		}
		if (timer >= 850 && timer <= 1000)
		{
			(*voi)->move((*voi)->getLocation().x + 2, (*voi)->getLocation().y + 1);
		}
		if (timer >= 1200 && timer <= 1350)
		{
			(*voi)->move((*voi)->getLocation().x + 4, (*voi)->getLocation().y - 3);
			if ((*voi)->getLocation().x > 550 || (*voi)->getLocation().y < 0)
			{
				isE = true;
				delete (*voi);
				voi = vector_plane.erase(voi);
			}
		}
		if (timer >= 1450 && timer <= 1620)
		{
			(*voi)->move((*voi)->getLocation().x - 2, (*voi)->getLocation().y);
		}
		if (timer > 1650 && timer < 1750)
		{
			(*voi)->move((*voi)->getLocation().x, (*voi)->getLocation().y + 6);
			if ((*voi)->getLocation().y > 450)
			{
				isE = true;
				delete (*voi);
				voi = vector_plane.erase(voi);
			}
		}
		if (timer >= 1800 && timer <= 1950)
		{
			(*voi)->move((*voi)->getLocation().x - 2, (*voi)->getLocation().y + 1);
		}
		if (timer >= 2050 && timer <= 2250)
		{
			if (voi == vector_plane.begin() + 2 || voi == vector_plane.end())
			{
				break;
			}
			(*voi)->move((*voi)->getLocation().x - 3, (*voi)->getLocation().y - 4);
			if ((*voi)->getLocation().x < 150 || (*voi)->getLocation().y < 0)
			{
				isE = true;
				delete (*voi);
				voi = vector_plane.erase(voi);
			}
		}
		if ((timer >= 2350 && timer <= 2400) || (timer >= 3000 && timer <= 3100) || (timer > 4100 && timer < 4230))
		{
			(*voi)->move((*voi)->getLocation().x, (*voi)->getLocation().y + 2);
		}
		if (timer >= 2600 && timer <= 2900)
		{
			(*voi)->move((*voi)->getLocation().x, (*voi)->getLocation().y + 5);
			if ((*voi)->getLocation().y > 355)
			{
				isE = true;
				delete (*voi);
				voi = vector_plane.erase(voi);
			}
		}
		if (timer >= 3800 && timer <= 4000)
		{
			(*voi)->move((*voi)->getLocation().x, (*voi)->getLocation().y + 5);
			if ((*voi)->getLocation().y > 450)
			{
				isE = true;
				delete (*voi);
				voi = vector_plane.erase(voi);
			}
		}
		if ((timer > 4300 && timer < 4350) || (timer > 4450 && timer < 4550) || (timer > 5000 && timer < 5100) || (timer > 5500 && timer < 5550))
		{
			(*voi)->move((*voi)->getLocation().x - 1, (*voi)->getLocation().y);
			if (timer == 4330 || timer == 4460  || timer == 4540  || timer == 5060)
			{
				vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy.bmp", (*voi)->getLocation().x + (*voi)->getWidth() * 3 / 4 - 30, (*voi)->getLocation().y + (*voi)->getHeight() * 3 / 4, 3));
				vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy.bmp", (*voi)->getLocation().x + (*voi)->getWidth() / 4, (*voi)->getLocation().y + (*voi)->getHeight() * 3 / 4, 3));
			}
		}
		if ((timer > 4350 && timer < 4450) || (timer > 4550 && timer < 4650) || (timer > 5140 && timer < 5240))
		{
			(*voi)->move((*voi)->getLocation().x + 1, (*voi)->getLocation().y);
			if (timer == 4380    || timer == 4610  || timer == 5170  || timer == 5230)
			{
				vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy.bmp", (*voi)->getLocation().x + (*voi)->getWidth() * 3 / 4 - 30, (*voi)->getLocation().y + (*voi)->getHeight() * 3 / 4, 3));
				vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy.bmp", (*voi)->getLocation().x + (*voi)->getWidth() / 4, (*voi)->getLocation().y + (*voi)->getHeight() * 3 / 4, 3));
			}
		}
		if (timer > 4650 && timer < 4700)
		{
			(*voi)->move((*voi)->getLocation().x, (*voi)->getLocation().y + 1);
		}
		if ((timer > 4700 && timer < 4731) || (timer > 5100 && timer < 5138) || (timer > 5550 && timer < 5575))
		{
			(*voi)->move((*voi)->getLocation().x, (*voi)->getLocation().y + 7);
		}
		if ((timer > 4740 && timer < 5000) || (timer > 5240 && timer < 5500) || (timer > 5580 && timer < 5750))
		{
			(*voi)->move((*voi)->getLocation().x, (*voi)->getLocation().y - 1);
		}
		if (timer == 5770 || timer == 5790 || timer == 5810 || timer == 5830)
		{
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy2.bmp", (*voi)->getLocation().x + (*voi)->getWidth() / 6, (*voi)->getLocation().y + (*voi)->getHeight() + 10, 4));
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy2.bmp", (*voi)->getLocation().x + (*voi)->getWidth() * 2 / 6, (*voi)->getLocation().y + (*voi)->getHeight() + 20, 4));
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy2.bmp", (*voi)->getLocation().x + (*voi)->getWidth() * 3 / 6, (*voi)->getLocation().y + (*voi)->getHeight() + 30, 4));
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy2.bmp", (*voi)->getLocation().x + (*voi)->getWidth() * 4 / 6, (*voi)->getLocation().y + (*voi)->getHeight() + 20, 4));
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy2.bmp", (*voi)->getLocation().x + (*voi)->getWidth() * 5 / 6, (*voi)->getLocation().y + (*voi)->getHeight() + 10, 4));
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy.bmp", (*voi)->getLocation().x + (*voi)->getWidth() / 4, (*voi)->getLocation().y + (*voi)->getHeight() * 3 / 4, 3));
			vector_enemy_bullet.push_back(new CBullet(all_hIns, ".\\images\\bullet_enemy.bmp", (*voi)->getLocation().x + (*voi)->getWidth() * 3 / 4 - 20, (*voi)->getLocation().y + (*voi)->getHeight() * 3 / 4, 3));
		}
		if (timer == 5850) {
			timer = 4300;
		}

		if (!isE)
		{
			voi++;
		}
	}
}

//游戏结束收尾工作
void clear()
{
	for (voi = vector_bullet.begin(); voi != vector_bullet.end();)
	{
		delete (*voi);
		voi = vector_bullet.erase(voi);
	}
	for (voi = vector_plane.begin(); voi != vector_plane.end();)
	{
		delete (*voi);
		voi = vector_plane.erase(voi);
	}
	for (voi = vector_enemy_bullet.begin(); voi != vector_enemy_bullet.end();)
	{
		delete (*voi);
		voi = vector_enemy_bullet.erase(voi);
	}
	for (voi = vector_upgrade.begin(); voi != vector_upgrade.end();)
	{
		delete (*voi);
		voi = vector_upgrade.erase(voi);
	}
	delete p_back;
}

//游戏绘制函数，利用双缓冲，防止刷新频率过高，出现闪烁
void draw(HDC &hdc)
{
	HDC bufferdc = CreateCompatibleDC(hdc); //后台缓冲DC
	SelectObject(bufferdc, p_back->getHbitmap());
	BitBlt(hdc, p_back->getLocation().x, p_back->getLocation().y, screen_width, screen_height, bufferdc, 0, p_back->getBegin(), SRCCOPY);
	//将飞机对象绘制到后台DC，后将后台DC内容整个复制到当前DC
	for (voi = vector_plane.begin(); voi != vector_plane.end(); voi++)
	{
		SelectObject(bufferdc, (*voi)->getHbitmap());
		TransparentBlt(hdc, (*voi)->getLocation().x, (*voi)->getLocation().y, (*voi)->getWidth(), (*voi)->getHeight(),
			bufferdc, 0, 0, (*voi)->getWidth(), (*voi)->getHeight(), RGB(200, 200, 200));
	}
	//子弹，同上
	for (voi = vector_bullet.begin(); voi != vector_bullet.end(); voi++)
	{
		SelectObject(bufferdc, (*voi)->getHbitmap());
		TransparentBlt(hdc, (*voi)->getLocation().x, (*voi)->getLocation().y, (*voi)->getWidth(), (*voi)->getHeight(),
			bufferdc, 0, 0, (*voi)->getWidth(), (*voi)->getHeight(), RGB(200, 200, 200));
	}
	for (voi = vector_enemy_bullet.begin(); voi != vector_enemy_bullet.end(); voi++)
	{
		SelectObject(bufferdc, (*voi)->getHbitmap());
		TransparentBlt(hdc, (*voi)->getLocation().x, (*voi)->getLocation().y, (*voi)->getWidth(), (*voi)->getHeight(),
			bufferdc, 0, 0, (*voi)->getWidth(), (*voi)->getHeight(), RGB(200, 200, 200));
	}
	//增益道具
	for (voi = vector_upgrade.begin(); voi != vector_upgrade.end(); voi++)
	{
		SelectObject(bufferdc, (*voi)->getHbitmap());
		TransparentBlt(hdc, (*voi)->getLocation().x, (*voi)->getLocation().y, (*voi)->getWidth(), (*voi)->getHeight(),
			bufferdc, 0, 0, (*voi)->getWidth(), (*voi)->getHeight(), RGB(200, 200, 200));
	}

	MoveToEx(hdc, 150, 520, NULL);
	LineTo(hdc, 650, 520);
	
	HBITMAP life = (HBITMAP)LoadImage(all_hIns, ".\\images\\life.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(bufferdc, life);
	BitBlt(hdc, 190, 525, 50, 50, bufferdc, 0, 0, SRCCOPY);
	HFONT font = CreateFont(30, 0, 0, 0, 400, 0, 0, 0, CP_UTF8, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MyFont");
	SelectObject(hdc, font);
	TextOut(hdc, 233, 528, "=", 1);
	CPlane* p = (CPlane*)vector_plane.at(0);
	int lifeNum = p->getLife();
	char s[20];
	_itoa_s(lifeNum, s, 10);
	TextOut(hdc, 255, 528, s, 1);
	DeleteObject(font);
	font = CreateFont(20, 0, 0, 0, 400, 0, 0, 0, CP_UTF8, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MyFont");
	SelectObject(hdc, font);
	TextOut(hdc, 450, 523, "SCORE:", sizeof("SCORE:") - 1);
	_itoa_s(score, s, 10);
	TextOut(hdc, 520, 540, s, strlen(s));
	
	DeleteObject(font);
	DeleteObject(life);
	DeleteDC(bufferdc);
	DeleteDC(hdc);
	DeleteDC(bufferdc);
}

void save()
{
	fstream fs(".\\save\\savedata.dat", ios::binary | ios::out);
	if (fs.fail())
		return;
/*
int score = 0; //分数
int timer = 0; //计时器
int deadtime = 0; //记录死亡时间
int p_num = 0;
int s_num = 0;
bool appOver = false; //判断程序是否结束
bool isLive = true; //判断己方飞机是否存活
bool gameStart = false; //判断游戏是否开始
bool isCaption = true; //判断游戏是否处于开始标题
bool gamePause = false; //判断游戏是否暂停
*/
	fs.write((char*)&score, sizeof(int));
	fs.write((char*)&timer, sizeof(int));
	fs.write((char*)&deadtime, sizeof(int));
	fs.write((char*)&p_num, sizeof(int));
	fs.write((char*)&s_num, sizeof(int));

	fs.write((char*)&appOver, sizeof(bool));
	fs.write((char*)&isLive, sizeof(bool));
	fs.write((char*)&gameStart, sizeof(bool));
	fs.write((char*)&isCaption, sizeof(bool));
	fs.write((char*)&gamePause, sizeof(bool));
	fs.write((char*)p_back, sizeof(*p_back));
	int len = vector_plane.size();
	fs.write((char*)&len, sizeof(int));
	for (voi = vector_plane.begin(); voi != vector_plane.end(); voi++)
	{
		fs.write((char*)*voi, sizeof(CPlane));
	}
	len = vector_bullet.size();
	fs.write((char*)&len, sizeof(int));
	for (voi = vector_bullet.begin(); voi != vector_bullet.end(); voi++)
	{
		fs.write((char*)*voi, sizeof(CBullet));
	}
	len = vector_enemy_bullet.size();
	fs.write((char*)&len, sizeof(int));
	for (voi = vector_enemy_bullet.begin(); voi != vector_enemy_bullet.end(); voi++)
	{
		fs.write((char*)*voi, sizeof(CBullet));
	}
	len = vector_upgrade.size();
	fs.write((char*)&len, sizeof(int));
	for (voi = vector_upgrade.begin(); voi != vector_upgrade.end(); voi++)
	{
		fs.write((char*)*voi, sizeof(CUpgrade));
	}
	

	fs.close();
}

void load()
{
	fstream fs;
	fs.open(".\\save\\savedata.dat", ios::binary | ios::in);
	if (fs.fail())
		return;

	fs.read((char*)&score, sizeof(int));
	fs.read((char*)&timer, sizeof(int));
	fs.read((char*)&deadtime, sizeof(int));
	fs.read((char*)&p_num, sizeof(int));
	fs.read((char*)&s_num, sizeof(int));

	fs.read((char*)&appOver, sizeof(bool));
	fs.read((char*)&isLive, sizeof(bool));
	fs.read((char*)&gameStart, sizeof(bool));
	fs.read((char*)&isCaption, sizeof(bool));
	fs.read((char*)&gamePause, sizeof(bool));
	fs.read((char*)p_back, sizeof(CBack));
	int len;
	fs.read((char*)&len, sizeof(int));
	vector_plane.resize(len);
	for (voi = vector_plane.begin(); voi != vector_plane.end(); voi++)
	{
		CPlane* p = new CPlane();
		fs.read((char*)p, sizeof(CPlane));
		*voi = p;
	}

	fs.read((char*)&len, sizeof(int));
	vector_bullet.resize(len);
	for (voi = vector_bullet.begin(); voi != vector_bullet.end(); voi++)
	{
		CBullet* p = new CBullet();
		fs.read((char*)p, sizeof(CBullet));
		*voi = p;
	}

	fs.read((char*)&len, sizeof(int));
	vector_enemy_bullet.resize(len);
	for (voi = vector_enemy_bullet.begin(); voi != vector_enemy_bullet.end(); voi++)
	{
		CBullet* p = new CBullet();
		fs.read((char*)p, sizeof(CBullet));
		*voi = p;
	}

	fs.read((char*)&len, sizeof(int));
	vector_upgrade.resize(len);
	for (voi = vector_upgrade.begin(); voi != vector_upgrade.end(); voi++)
	{
		CUpgrade* p = new CUpgrade();
		fs.read((char*)p, sizeof(CUpgrade));
		*voi = p;
	}
	
	fs.close();
}