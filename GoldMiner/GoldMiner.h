#pragma once
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <graphics.h>

#define WIDTH 850
#define HEIGHT 700
#define PI 3.1415926

void startup();					//启动及数据初始化
void updateWithoutInput();		//与用户输入无关的更新
void updateWithInput();			//与用户输入有关的更新
void gameover();				//结束

void logIn();					//登录界面
void gameUI();					//游戏界面

void mouse(int left, int top, int right, int bottom);	//捕获鼠标
void day1();					//第一关界面加载
void day2();					//第二关界面加载
void hook();					//钩子摆动和下拉
void victory(int flag);			//游戏胜利界面