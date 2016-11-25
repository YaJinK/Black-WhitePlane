#pragma once

#pragma comment(lib, "Msimg32.lib")
#include "CPlane.h"
#include "CBullet.h"
#include "CBack.h"
#include "CUpgrade.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
using std::vector;
using std::fstream;
using std::ios;

const string APPNAME = "B&W Plane";
string title = "YOU WIN!"; //暂停， 游戏结束时界面标题
const int screen_width = 500; //对象活动范围
const int screen_height = 520;
int score = 0; //分数
int timer = 0; //计时器
int deadtime = 0; //记录死亡时间
int p_num = 0;
int s_num = 0;
HINSTANCE all_hIns = NULL;
vector<CObject*> vector_plane; //存储飞机对象
vector<CObject*> vector_bullet; //存储己方子弹对象
vector<CObject*> vector_enemy_bullet; //存储敌方子弹对象
vector<CObject*> vector_upgrade; //存储增益道具对象 
vector<CObject*>::iterator voi; //迭代器
CBack* p_back = NULL; //背景图片对象指针
bool appOver = false; //判断程序是否结束
bool isLive = true; //判断己方飞机是否存活
bool gameStart = false; //判断游戏是否开始
bool isCaption = true; //判断游戏是否处于开始标题
bool gamePause = false; //判断游戏是否暂停

bool noHurt = false;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void game_init();
void game_run(HWND &hWnd);
void clear();
void game_pause(HDC &hdc);
void game_over(HDC &hdc);
void draw(HDC &hdc);
void startView(HDC &hdc);
void planeAction();
void isHurt();
void bulletAction();
void enemyCome();
void enemyLeave();
void getUpgrade();
void upgradeMove();
void save();
void load();