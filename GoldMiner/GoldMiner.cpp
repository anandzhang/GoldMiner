#include "GoldMiner.h"

typedef struct edge {
	int left;
	int top;
	int right;
	int bottom;
}EDGE;

typedef struct thing {
	IMAGE img;
	IMAGE img_mask;
	int x;
	int y;
	int weight = NULL;		//暂未使用
	int flag = 1;
	EDGE e;
}TH;

int centerx = 425, centery = 160;				//轴心坐标
int hookx = 425, hooky = 200;					//钩子坐标
int r = 40, angle = 0;							//钩子转动半径、角度
int angle_v = 1, dig_v = 5;						//钩子转动速度、挖矿速度
int flag_dig = 0;								//是否向下挖
int number = 0, count = 0, daynum = 1;;			//抓到玩具个数、简单倒计时所用常量、关卡数
extern int retime;								//倒计时

TCHAR num[5], nowtime[5];						//转存得分为TCHAR

IMAGE start[32], load[9], home, background;		//动图、进入界面、游戏界面背景
IMAGE day1_start[43], day1_story[77];			//第一关进入界面
IMAGE day1_pass[32], day2_pass[9], day1_over[29];//第一关通过界面、失败界面
IMAGE day2_start[45], day2_story[78];			//第二关进入界面
IMAGE pig, pig_mask;							//佩奇结束图

TH prop1[6], prop2[5];							//关卡玩具

void loadimg();

void startup() {
	initgraph(WIDTH, HEIGHT);				// 窗口初始化大小

	logIn();								// 登录界面
	//gameUI();

	prop1[0].e.left = prop1[0].x = 100;		//放前面 为什么触碰不收回
	prop1[0].e.top = prop1[0].y = 580;
	prop1[1].e.left = prop1[1].x = 80;
	prop1[1].e.top = prop1[1].y = 400;
	prop1[2].e.left = prop1[2].x = 350;
	prop1[2].e.top = prop1[2].y = 320;
	prop1[3].e.left = prop1[3].x = 450;
	prop1[3].e.top = prop1[3].y = 450;
	prop1[4].e.left = prop1[4].x = 600;
	prop1[4].e.top = prop1[4].y = 300;
	prop1[5].e.left = prop1[5].x = 700;
	prop1[5].e.top = prop1[5].y = 600;
	for (int i = 0; i < 6; i++) {
		prop1[i].e.right = prop1[i].e.left + prop1[i].img.getwidth();
		prop1[i].e.bottom = prop1[i].e.top + prop1[i].img.getheight();
	}

}

void loadlogo() {
	setbkcolor(0xE8E8E8);					// 设置背景颜色
	cleardevice();

	loadimage(&start[0], "src\\start\\1.jpg");
	loadimage(&start[1], "src\\start\\2.jpg");
	loadimage(&start[2], "src\\start\\3.jpg");
	loadimage(&start[3], "src\\start\\4.jpg");
	loadimage(&start[4], "src\\start\\5.jpg");
	loadimage(&start[5], "src\\start\\6.jpg");
	loadimage(&start[6], "src\\start\\7.jpg");
	loadimage(&start[7], "src\\start\\8.jpg");
	loadimage(&start[8], "src\\start\\9.jpg");
	loadimage(&start[9], "src\\start\\10.jpg");
	loadimage(&start[10], "src\\start\\11.jpg");
	loadimage(&start[11], "src\\start\\12.jpg");
	loadimage(&start[12], "src\\start\\13.jpg");
	loadimage(&start[13], "src\\start\\14.jpg");
	loadimage(&start[14], "src\\start\\15.jpg");
	loadimage(&start[15], "src\\start\\16.jpg");
	loadimage(&start[16], "src\\start\\17.jpg");
	loadimage(&start[17], "src\\start\\18.jpg");
	loadimage(&start[18], "src\\start\\19.jpg");
	loadimage(&start[19], "src\\start\\20.jpg");
	loadimage(&start[20], "src\\start\\21.jpg");
	loadimage(&start[21], "src\\start\\22.jpg");
	loadimage(&start[22], "src\\start\\23.jpg");
	loadimage(&start[23], "src\\start\\24.jpg");
	loadimage(&start[24], "src\\start\\25.jpg");
	loadimage(&start[25], "src\\start\\26.jpg");
	loadimage(&start[26], "src\\start\\27.jpg");
	loadimage(&start[27], "src\\start\\28.jpg");
	loadimage(&start[28], "src\\start\\29.jpg");
	loadimage(&start[29], "src\\start\\30.jpg");
	loadimage(&start[30], "src\\start\\31.jpg");
	loadimage(&start[31], "src\\start\\32.jpg");

	for (int i = 0; i < 32; i++) {
		putimage(150, 200, &start[i]);
		Sleep(80);
	}
}

void loadimg() {
	loadimage(&load[0], "src\\start\\load0.jpg");
	loadimage(&load[1], "src\\start\\load1.jpg");
	loadimage(&load[2], "src\\start\\load2.jpg");
	loadimage(&load[3], "src\\start\\load3.jpg");
	loadimage(&load[4], "src\\start\\load4.jpg");
	loadimage(&load[5], "src\\start\\load5.jpg");
	loadimage(&load[6], "src\\start\\load6.jpg");
	loadimage(&load[7], "src\\start\\load7.jpg");
	loadimage(&load[8], "src\\start\\load8.jpg");
	settextcolor(BLACK);
	outtextxy(700, 550, "Loading...");
	putimage(300, 500, &load[0]);
	/***************Day1**********/
	loadimage(&day1_start[0], "src\\day1\\1.jpg");
	loadimage(&day1_start[1], "src\\day1\\2.jpg");
	loadimage(&day1_start[2], "src\\day1\\3.jpg");
	loadimage(&day1_start[3], "src\\day1\\4.jpg");
	loadimage(&day1_start[4], "src\\day1\\5.jpg");
	loadimage(&day1_start[5], "src\\day1\\6.jpg");
	loadimage(&day1_start[6], "src\\day1\\7.jpg");
	loadimage(&day1_start[7], "src\\day1\\8.jpg");
	loadimage(&day1_start[8], "src\\day1\\9.jpg");
	loadimage(&day1_start[9], "src\\day1\\10.jpg");
	loadimage(&day1_start[10], "src\\day1\\11.jpg");
	loadimage(&day1_start[11], "src\\day1\\12.jpg");
	loadimage(&day1_start[12], "src\\day1\\13.jpg");
	loadimage(&day1_start[13], "src\\day1\\14.jpg");
	loadimage(&day1_start[14], "src\\day1\\15.jpg");
	loadimage(&day1_start[15], "src\\day1\\16.jpg");
	loadimage(&day1_start[16], "src\\day1\\17.jpg");
	loadimage(&day1_start[17], "src\\day1\\18.jpg");
	loadimage(&day1_start[18], "src\\day1\\19.jpg");
	loadimage(&day1_start[19], "src\\day1\\20.jpg");
	loadimage(&day1_start[20], "src\\day1\\21.jpg");
	loadimage(&day1_start[21], "src\\day1\\22.jpg");
	loadimage(&day1_start[22], "src\\day1\\23.jpg");
	loadimage(&day1_start[23], "src\\day1\\24.jpg");
	loadimage(&day1_start[24], "src\\day1\\25.jpg");
	loadimage(&day1_start[25], "src\\day1\\26.jpg");
	loadimage(&day1_start[26], "src\\day1\\27.jpg");
	loadimage(&day1_start[27], "src\\day1\\28.jpg");
	loadimage(&day1_start[28], "src\\day1\\29.jpg");
	loadimage(&day1_start[29], "src\\day1\\30.jpg");
	loadimage(&day1_start[30], "src\\day1\\31.jpg");
	loadimage(&day1_start[31], "src\\day1\\32.jpg");
	loadimage(&day1_start[32], "src\\day1\\33.jpg");
	loadimage(&day1_start[33], "src\\day1\\34.jpg");
	loadimage(&day1_start[34], "src\\day1\\35.jpg");
	loadimage(&day1_start[35], "src\\day1\\36.jpg");
	loadimage(&day1_start[36], "src\\day1\\37.jpg");
	loadimage(&day1_start[37], "src\\day1\\38.jpg");
	loadimage(&day1_start[38], "src\\day1\\39.jpg");
	loadimage(&day1_start[39], "src\\day1\\40.jpg");
	loadimage(&day1_start[40], "src\\day1\\41.jpg");
	loadimage(&day1_start[41], "src\\day1\\42.jpg");
	loadimage(&day1_start[42], "src\\day1\\43.jpg");

	putimage(300, 500, &load[1]);

	loadimage(&day1_story[0], "src\\day1\\s1.jpg");
	loadimage(&day1_story[1], "src\\day1\\s2.jpg");
	loadimage(&day1_story[2], "src\\day1\\s3.jpg");
	loadimage(&day1_story[3], "src\\day1\\s4.jpg");
	loadimage(&day1_story[4], "src\\day1\\s5.jpg");
	loadimage(&day1_story[5], "src\\day1\\s6.jpg");
	loadimage(&day1_story[6], "src\\day1\\s7.jpg");
	loadimage(&day1_story[7], "src\\day1\\s8.jpg");
	loadimage(&day1_story[8], "src\\day1\\s9.jpg");
	loadimage(&day1_story[9], "src\\day1\\s10.jpg");
	loadimage(&day1_story[10], "src\\day1\\s11.jpg");
	loadimage(&day1_story[11], "src\\day1\\s12.jpg");
	loadimage(&day1_story[12], "src\\day1\\s13.jpg");
	loadimage(&day1_story[13], "src\\day1\\s14.jpg");
	loadimage(&day1_story[14], "src\\day1\\s15.jpg");
	loadimage(&day1_story[15], "src\\day1\\s16.jpg");
	loadimage(&day1_story[16], "src\\day1\\s17.jpg");
	loadimage(&day1_story[17], "src\\day1\\s18.jpg");
	loadimage(&day1_story[18], "src\\day1\\s19.jpg");
	loadimage(&day1_story[19], "src\\day1\\s20.jpg");
	loadimage(&day1_story[20], "src\\day1\\s21.jpg");
	loadimage(&day1_story[21], "src\\day1\\s22.jpg");
	loadimage(&day1_story[22], "src\\day1\\s23.jpg");
	loadimage(&day1_story[23], "src\\day1\\s24.jpg");
	loadimage(&day1_story[24], "src\\day1\\s25.jpg");
	loadimage(&day1_story[25], "src\\day1\\s26.jpg");
	loadimage(&day1_story[26], "src\\day1\\s27.jpg");
	loadimage(&day1_story[27], "src\\day1\\s28.jpg");
	loadimage(&day1_story[28], "src\\day1\\s29.jpg");
	loadimage(&day1_story[29], "src\\day1\\s30.jpg");
	loadimage(&day1_story[30], "src\\day1\\s31.jpg");
	loadimage(&day1_story[31], "src\\day1\\s32.jpg");
	loadimage(&day1_story[32], "src\\day1\\s33.jpg");
	loadimage(&day1_story[33], "src\\day1\\s34.jpg");
	loadimage(&day1_story[34], "src\\day1\\s35.jpg");
	loadimage(&day1_story[35], "src\\day1\\s36.jpg");
	loadimage(&day1_story[36], "src\\day1\\s37.jpg");
	loadimage(&day1_story[37], "src\\day1\\s38.jpg");
	loadimage(&day1_story[38], "src\\day1\\s39.jpg");
	loadimage(&day1_story[39], "src\\day1\\s40.jpg");
	loadimage(&day1_story[40], "src\\day1\\s41.jpg");
	loadimage(&day1_story[41], "src\\day1\\s42.jpg");
	loadimage(&day1_story[42], "src\\day1\\s43.jpg");
	loadimage(&day1_story[43], "src\\day1\\s44.jpg");
	loadimage(&day1_story[44], "src\\day1\\s45.jpg");
	loadimage(&day1_story[45], "src\\day1\\s46.jpg");
	loadimage(&day1_story[46], "src\\day1\\s47.jpg");
	loadimage(&day1_story[47], "src\\day1\\s48.jpg");
	loadimage(&day1_story[48], "src\\day1\\s49.jpg");
	loadimage(&day1_story[49], "src\\day1\\s50.jpg");
	loadimage(&day1_story[50], "src\\day1\\s51.jpg");
	loadimage(&day1_story[51], "src\\day1\\s52.jpg");
	loadimage(&day1_story[52], "src\\day1\\s53.jpg");
	loadimage(&day1_story[53], "src\\day1\\s54.jpg");
	loadimage(&day1_story[54], "src\\day1\\s55.jpg");
	loadimage(&day1_story[55], "src\\day1\\s56.jpg");
	loadimage(&day1_story[56], "src\\day1\\s57.jpg");
	loadimage(&day1_story[57], "src\\day1\\s58.jpg");
	loadimage(&day1_story[58], "src\\day1\\s59.jpg");
	loadimage(&day1_story[59], "src\\day1\\s60.jpg");
	loadimage(&day1_story[60], "src\\day1\\s61.jpg");
	loadimage(&day1_story[61], "src\\day1\\s62.jpg");
	loadimage(&day1_story[62], "src\\day1\\s63.jpg");
	loadimage(&day1_story[63], "src\\day1\\s64.jpg");
	loadimage(&day1_story[64], "src\\day1\\s65.jpg");
	loadimage(&day1_story[65], "src\\day1\\s66.jpg");
	loadimage(&day1_story[66], "src\\day1\\s67.jpg");
	loadimage(&day1_story[67], "src\\day1\\s68.jpg");
	loadimage(&day1_story[68], "src\\day1\\s69.jpg");
	loadimage(&day1_story[69], "src\\day1\\s70.jpg");
	loadimage(&day1_story[70], "src\\day1\\s71.jpg");
	loadimage(&day1_story[71], "src\\day1\\s72.jpg");
	loadimage(&day1_story[72], "src\\day1\\s73.jpg");
	loadimage(&day1_story[73], "src\\day1\\s74.jpg");
	loadimage(&day1_story[74], "src\\day1\\s75.jpg");
	loadimage(&day1_story[75], "src\\day1\\s76.jpg");
	loadimage(&day1_story[76], "src\\day1\\s77.jpg");

	putimage(300, 500, &load[2]);
	/*****day2*******/
	loadimage(&day2_start[0], "src\\day2\\1.jpg");
	loadimage(&day2_start[1], "src\\day2\\2.jpg");
	loadimage(&day2_start[2], "src\\day2\\3.jpg");
	loadimage(&day2_start[3], "src\\day2\\4.jpg");
	loadimage(&day2_start[4], "src\\day2\\5.jpg");
	loadimage(&day2_start[5], "src\\day2\\6.jpg");
	loadimage(&day2_start[6], "src\\day2\\7.jpg");
	loadimage(&day2_start[7], "src\\day2\\8.jpg");
	loadimage(&day2_start[8], "src\\day2\\9.jpg");
	loadimage(&day2_start[9], "src\\day2\\10.jpg");
	loadimage(&day2_start[10], "src\\day2\\11.jpg");
	loadimage(&day2_start[11], "src\\day2\\12.jpg");
	loadimage(&day2_start[12], "src\\day2\\13.jpg");
	loadimage(&day2_start[13], "src\\day2\\14.jpg");
	loadimage(&day2_start[14], "src\\day2\\15.jpg");
	loadimage(&day2_start[15], "src\\day2\\16.jpg");
	loadimage(&day2_start[16], "src\\day2\\17.jpg");
	loadimage(&day2_start[17], "src\\day2\\18.jpg");
	loadimage(&day2_start[18], "src\\day2\\19.jpg");
	loadimage(&day2_start[19], "src\\day2\\20.jpg");
	loadimage(&day2_start[20], "src\\day2\\21.jpg");
	loadimage(&day2_start[21], "src\\day2\\22.jpg");
	loadimage(&day2_start[22], "src\\day2\\23.jpg");
	loadimage(&day2_start[23], "src\\day2\\24.jpg");
	loadimage(&day2_start[24], "src\\day2\\25.jpg");
	loadimage(&day2_start[25], "src\\day2\\26.jpg");
	loadimage(&day2_start[26], "src\\day2\\27.jpg");
	loadimage(&day2_start[27], "src\\day2\\28.jpg");
	loadimage(&day2_start[28], "src\\day2\\29.jpg");
	loadimage(&day2_start[29], "src\\day2\\30.jpg");
	loadimage(&day2_start[30], "src\\day2\\31.jpg");
	loadimage(&day2_start[31], "src\\day2\\32.jpg");
	loadimage(&day2_start[32], "src\\day2\\33.jpg");
	loadimage(&day2_start[33], "src\\day2\\34.jpg");
	loadimage(&day2_start[34], "src\\day2\\35.jpg");
	loadimage(&day2_start[35], "src\\day2\\36.jpg");
	loadimage(&day2_start[36], "src\\day2\\37.jpg");
	loadimage(&day2_start[37], "src\\day2\\38.jpg");
	loadimage(&day2_start[38], "src\\day2\\39.jpg");
	loadimage(&day2_start[39], "src\\day2\\40.jpg");
	loadimage(&day2_start[40], "src\\day2\\41.jpg");
	loadimage(&day2_start[41], "src\\day2\\42.jpg");
	loadimage(&day2_start[42], "src\\day2\\43.jpg");
	loadimage(&day2_start[43], "src\\day2\\44.jpg");
	loadimage(&day2_start[44], "src\\day2\\45.jpg");

	putimage(300, 500, &load[3]);

	loadimage(&day2_story[0], "src\\day2\\s1.jpg");
	loadimage(&day2_story[1], "src\\day2\\s2.jpg");
	loadimage(&day2_story[2], "src\\day2\\s3.jpg");
	loadimage(&day2_story[3], "src\\day2\\s4.jpg");
	loadimage(&day2_story[4], "src\\day2\\s5.jpg");
	loadimage(&day2_story[5], "src\\day2\\s6.jpg");
	loadimage(&day2_story[6], "src\\day2\\s7.jpg");
	loadimage(&day2_story[7], "src\\day2\\s8.jpg");
	loadimage(&day2_story[8], "src\\day2\\s9.jpg");
	loadimage(&day2_story[9], "src\\day2\\s10.jpg");
	loadimage(&day2_story[10], "src\\day2\\s11.jpg");
	loadimage(&day2_story[11], "src\\day2\\s12.jpg");
	loadimage(&day2_story[12], "src\\day2\\s13.jpg");
	loadimage(&day2_story[13], "src\\day2\\s14.jpg");
	loadimage(&day2_story[14], "src\\day2\\s15.jpg");
	loadimage(&day2_story[15], "src\\day2\\s16.jpg");
	loadimage(&day2_story[16], "src\\day2\\s17.jpg");
	loadimage(&day2_story[17], "src\\day2\\s18.jpg");
	loadimage(&day2_story[18], "src\\day2\\s19.jpg");
	loadimage(&day2_story[19], "src\\day2\\s20.jpg");
	loadimage(&day2_story[20], "src\\day2\\s21.jpg");
	loadimage(&day2_story[21], "src\\day2\\s22.jpg");
	loadimage(&day2_story[22], "src\\day2\\s23.jpg");
	loadimage(&day2_story[23], "src\\day2\\s24.jpg");
	loadimage(&day2_story[24], "src\\day2\\s25.jpg");
	loadimage(&day2_story[25], "src\\day2\\s26.jpg");
	loadimage(&day2_story[26], "src\\day2\\s27.jpg");
	loadimage(&day2_story[27], "src\\day2\\s28.jpg");
	loadimage(&day2_story[28], "src\\day2\\s29.jpg");
	loadimage(&day2_story[29], "src\\day2\\s30.jpg");
	loadimage(&day2_story[30], "src\\day2\\s31.jpg");
	loadimage(&day2_story[31], "src\\day2\\s32.jpg");
	loadimage(&day2_story[32], "src\\day2\\s33.jpg");
	loadimage(&day2_story[33], "src\\day2\\s34.jpg");
	loadimage(&day2_story[34], "src\\day2\\s35.jpg");
	loadimage(&day2_story[35], "src\\day2\\s36.jpg");
	loadimage(&day2_story[36], "src\\day2\\s37.jpg");
	loadimage(&day2_story[37], "src\\day2\\s38.jpg");
	loadimage(&day2_story[38], "src\\day2\\s39.jpg");
	loadimage(&day2_story[39], "src\\day2\\s40.jpg");
	loadimage(&day2_story[40], "src\\day2\\s41.jpg");
	loadimage(&day2_story[41], "src\\day2\\s42.jpg");
	loadimage(&day2_story[42], "src\\day2\\s43.jpg");
	loadimage(&day2_story[43], "src\\day2\\s44.jpg");
	loadimage(&day2_story[44], "src\\day2\\s45.jpg");
	loadimage(&day2_story[45], "src\\day2\\s46.jpg");
	loadimage(&day2_story[46], "src\\day2\\s47.jpg");
	loadimage(&day2_story[47], "src\\day2\\s48.jpg");
	loadimage(&day2_story[48], "src\\day2\\s49.jpg");
	loadimage(&day2_story[49], "src\\day2\\s50.jpg");
	loadimage(&day2_story[50], "src\\day2\\s51.jpg");
	loadimage(&day2_story[51], "src\\day2\\s52.jpg");
	loadimage(&day2_story[52], "src\\day2\\s53.jpg");
	loadimage(&day2_story[53], "src\\day2\\s54.jpg");
	loadimage(&day2_story[54], "src\\day2\\s55.jpg");
	loadimage(&day2_story[55], "src\\day2\\s56.jpg");
	loadimage(&day2_story[56], "src\\day2\\s57.jpg");
	loadimage(&day2_story[57], "src\\day2\\s58.jpg");
	loadimage(&day2_story[58], "src\\day2\\s59.jpg");
	loadimage(&day2_story[59], "src\\day2\\s60.jpg");
	loadimage(&day2_story[60], "src\\day2\\s61.jpg");
	loadimage(&day2_story[61], "src\\day2\\s62.jpg");
	loadimage(&day2_story[62], "src\\day2\\s63.jpg");
	loadimage(&day2_story[63], "src\\day2\\s64.jpg");
	loadimage(&day2_story[64], "src\\day2\\s65.jpg");
	loadimage(&day2_story[65], "src\\day2\\s66.jpg");
	loadimage(&day2_story[66], "src\\day2\\s67.jpg");
	loadimage(&day2_story[67], "src\\day2\\s68.jpg");
	loadimage(&day2_story[68], "src\\day2\\s69.jpg");
	loadimage(&day2_story[69], "src\\day2\\s70.jpg");
	loadimage(&day2_story[70], "src\\day2\\s71.jpg");
	loadimage(&day2_story[71], "src\\day2\\s72.jpg");
	loadimage(&day2_story[72], "src\\day2\\s73.jpg");
	loadimage(&day2_story[73], "src\\day2\\s74.jpg");
	loadimage(&day2_story[74], "src\\day2\\s75.jpg");
	loadimage(&day2_story[75], "src\\day2\\s76.jpg");
	loadimage(&day2_story[76], "src\\day2\\s77.jpg");
	loadimage(&day2_story[77], "src\\day2\\s78.jpg");

	putimage(300, 500, &load[4]);
	/**********prop******/
	loadimage(&background, "src\\background.jpg");
	loadimage(&pig, "src\\pig.jpg", 70, 70);
	loadimage(&pig_mask, "src\\pig_mask.jpg", 70, 70);

	loadimage(&prop1[0].img, "src\\ball.jpg", 60, 60);
	loadimage(&prop1[1].img, "src\\aircraft.jpg", 70, 60);
	loadimage(&prop1[2].img, "src\\star.jpg", 70, 70);
	loadimage(&prop1[3].img, "src\\frog.jpg", 90, 90);
	loadimage(&prop1[4].img, "src\\dragon.jpg", 100, 80);
	loadimage(&prop1[5].img, "src\\box.jpg", 80, 70);
	loadimage(&prop1[0].img_mask, "src\\ball_mask.jpg", 60, 60);
	loadimage(&prop1[1].img_mask, "src\\aircraft_mask.jpg", 70, 60);
	loadimage(&prop1[2].img_mask, "src\\star_mask.jpg", 70, 70);
	loadimage(&prop1[3].img_mask, "src\\frog_mask.jpg", 90, 90);
	loadimage(&prop1[4].img_mask, "src\\dragon_mask.jpg", 100, 80);
	loadimage(&prop1[5].img_mask, "src\\box_mask.jpg", 80, 70);

	putimage(300, 500, &load[5]);

	loadimage(&prop2[0].img, "src\\glass.jpg", 100, 50);
	loadimage(&prop2[1].img, "src\\car.jpg", 90, 60);
	loadimage(&prop2[2].img, "src\\bee.jpg", 90, 80);
	loadimage(&prop2[3].img, "src\\bottle.jpg", 90, 50);
	loadimage(&prop2[4].img, "src\\treasure.jpg", 90, 80);
	loadimage(&prop2[0].img_mask, "src\\glass_mask.jpg", 100, 50);
	loadimage(&prop2[1].img_mask, "src\\car_mask.jpg", 90, 60);
	loadimage(&prop2[2].img_mask, "src\\bee_mask.jpg", 90, 80);
	loadimage(&prop2[3].img_mask, "src\\bottle_mask.jpg", 90, 50);
	loadimage(&prop2[4].img_mask, "src\\treasure_mask.jpg", 90, 80);

	putimage(300, 500, &load[6]);
	/********gameover******/
	loadimage(&day1_over[0], "src\\start\\cry1.jpg");
	loadimage(&day1_over[1], "src\\start\\cry2.jpg");
	loadimage(&day1_over[2], "src\\start\\cry3.jpg");
	loadimage(&day1_over[3], "src\\start\\cry4.jpg");
	loadimage(&day1_over[4], "src\\start\\cry5.jpg");
	loadimage(&day1_over[5], "src\\start\\cry6.jpg");
	loadimage(&day1_over[6], "src\\start\\cry7.jpg");
	loadimage(&day1_over[7], "src\\start\\cry8.jpg");
	loadimage(&day1_over[8], "src\\start\\cry9.jpg");
	loadimage(&day1_over[9], "src\\start\\cry10.jpg");
	loadimage(&day1_over[10], "src\\start\\cry11.jpg");
	loadimage(&day1_over[11], "src\\start\\cry12.jpg");
	loadimage(&day1_over[12], "src\\start\\cry13.jpg");
	loadimage(&day1_over[13], "src\\start\\cry14.jpg");
	loadimage(&day1_over[14], "src\\start\\cry15.jpg");
	loadimage(&day1_over[15], "src\\start\\cry16.jpg");
	loadimage(&day1_over[16], "src\\start\\cry17.jpg");
	loadimage(&day1_over[17], "src\\start\\cry18.jpg");
	loadimage(&day1_over[18], "src\\start\\cry19.jpg");
	loadimage(&day1_over[19], "src\\start\\cry20.jpg");
	loadimage(&day1_over[20], "src\\start\\cry21.jpg");
	loadimage(&day1_over[21], "src\\start\\cry22.jpg");
	loadimage(&day1_over[22], "src\\start\\cry23.jpg");
	loadimage(&day1_over[23], "src\\start\\cry24.jpg");
	loadimage(&day1_over[24], "src\\start\\cry25.jpg");
	loadimage(&day1_over[25], "src\\start\\cry26.jpg");
	loadimage(&day1_over[26], "src\\start\\cry27.jpg");
	loadimage(&day1_over[27], "src\\start\\cry28.jpg");
	loadimage(&day1_over[28], "src\\start\\cry29.jpg");

	putimage(300, 500, &load[7]);
	/********victory******/
	loadimage(&day1_pass[0], "src\\day1\\pass1.jpg");
	loadimage(&day1_pass[1], "src\\day1\\pass2.jpg");
	loadimage(&day1_pass[2], "src\\day1\\pass3.jpg");
	loadimage(&day1_pass[3], "src\\day1\\pass4.jpg");
	loadimage(&day1_pass[4], "src\\day1\\pass5.jpg");
	loadimage(&day1_pass[5], "src\\day1\\pass6.jpg");
	loadimage(&day1_pass[6], "src\\day1\\pass7.jpg");
	loadimage(&day1_pass[7], "src\\day1\\pass8.jpg");
	loadimage(&day1_pass[8], "src\\day1\\pass9.jpg");
	loadimage(&day1_pass[9], "src\\day1\\pass10.jpg");
	loadimage(&day1_pass[10], "src\\day1\\pass11.jpg");
	loadimage(&day1_pass[11], "src\\day1\\pass12.jpg");
	loadimage(&day1_pass[12], "src\\day1\\pass13.jpg");
	loadimage(&day1_pass[13], "src\\day1\\pass14.jpg");
	loadimage(&day1_pass[14], "src\\day1\\pass15.jpg");
	loadimage(&day1_pass[15], "src\\day1\\pass16.jpg");
	loadimage(&day1_pass[16], "src\\day1\\pass17.jpg");
	loadimage(&day1_pass[17], "src\\day1\\pass18.jpg");
	loadimage(&day1_pass[18], "src\\day1\\pass19.jpg");
	loadimage(&day1_pass[19], "src\\day1\\pass20.jpg");
	loadimage(&day1_pass[20], "src\\day1\\pass21.jpg");
	loadimage(&day1_pass[21], "src\\day1\\pass22.jpg");
	loadimage(&day1_pass[22], "src\\day1\\pass23.jpg");
	loadimage(&day1_pass[23], "src\\day1\\pass24.jpg");
	loadimage(&day1_pass[24], "src\\day1\\pass25.jpg");
	loadimage(&day1_pass[25], "src\\day1\\pass26.jpg");
	loadimage(&day1_pass[26], "src\\day1\\pass27.jpg");
	loadimage(&day1_pass[27], "src\\day1\\pass28.jpg");
	loadimage(&day1_pass[28], "src\\day1\\pass29.jpg");
	loadimage(&day1_pass[29], "src\\day1\\pass30.jpg");
	loadimage(&day1_pass[30], "src\\day1\\pass31.jpg");
	loadimage(&day1_pass[31], "src\\day1\\pass32.jpg");

	putimage(300, 500, &load[8]);

	loadimage(&day2_pass[0], "src\\day2\\pass1.jpg");
	loadimage(&day2_pass[1], "src\\day2\\pass2.jpg");
	loadimage(&day2_pass[2], "src\\day2\\pass3.jpg");
	loadimage(&day2_pass[3], "src\\day2\\pass4.jpg");
	loadimage(&day2_pass[4], "src\\day2\\pass5.jpg");
	loadimage(&day2_pass[5], "src\\day2\\pass6.jpg");
	loadimage(&day2_pass[6], "src\\day2\\pass7.jpg");
	loadimage(&day2_pass[7], "src\\day2\\pass8.jpg");
	loadimage(&day2_pass[8], "src\\day2\\pass9.jpg");
}

void hook() {
	Sleep(18);		//不加的话 钩子太快
	FlushBatchDraw();
	setlinecolor(0xC0C0C0);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 8);

	if (angle >= 80 || angle <= -80) angle_v = -angle_v;
	if (!flag_dig) angle += angle_v;				//挖矿时angle不变
	hookx = centerx + r * sin(angle*PI / 180);  //使用圆上的坐标 x= x0 + r*sin# ; y = y + r*cos# 逆时针旋转
	hooky = centery + r * cos(angle*PI / 180);

	/*****************使用 (x-x0)2+(y-y0)2=r2 求点的坐标*******************
	if (hookx >= (centerx + r) || hookx <= (centerx - r)) v = -v;
	hookx += v;
	hooky = sqrt(pow(r, 2) - pow((hookx - centerx), 2)) + centery;
	*****************该方法使钩子修改参数时出现小bug*************************/

	//*******//使用hook的坐标就会多r 所以使用center的坐标
	if (daynum == 1) {
		for (int i = 0; i < 6; i++) {
			if (prop1[i].flag == 2) {
				prop1[i].x = centerx + r * sin(angle*PI / 180) - prop1[i].img.getwidth() / 2;
				prop1[i].y = centery + r * cos(angle*PI / 180) - 20;
			}
		}
	}
	else {
		for (int j = 0; j < 5; j++) {
			if (prop2[j].flag == 2) {
				prop2[j].x = centerx + r * sin(angle*PI / 180) - prop2[j].img.getwidth() / 2;
				prop2[j].y = centery + r * cos(angle*PI / 180) - 20;
			}
		}
	}
	gameUI();
	line(centerx, centery, hookx, hooky);
}

void updateWithoutInput() {
	BeginBatchDraw();
	hook();		//钩子
}

void victory(int flag) {
	if (flag == 1) {
		for (int i = 0; i < 32; i++) {
			putimage(0, 0, &day1_pass[i]);
			Sleep(80);
		}
		mouse(615, 615, 820, 660);
		day2();
	}
	else {
		for (int j = 0; j < 32; j++) {
			putimage(0, 0, &day2_pass[j]);
			Sleep(80);
		}
		system("pause");
		closegraph();
	}
}

void updateWithInput() {
	int flag = 1, root = r, m = -1, n = -1;
	char kb;
	if (_kbhit()) {
		kb = _getch();
		if (kb == 'S' || kb == 's') {
			flag_dig = 1;
			while (flag) {
				r += dig_v;
				hook();
				if (daynum == 1) {
					for (int i = 0; i < 6; i++) {
						if (prop1[i].flag != 0 && hookx >= prop1[i].e.left&&hookx <= prop1[i].e.right&&hooky >= prop1[i].e.top&&hooky <= prop1[i].e.bottom) {
							prop1[i].flag = 2;
							dig_v = -dig_v;
							m = i;
						}
					}
				}
				if (daynum == 2) {
					for (int j = 0; j < 5; j++) {
						if (prop2[j].flag != 0 && hookx >= prop2[j].e.left&&hookx <= prop2[j].e.right&&hooky >= prop2[j].e.top&&hooky <= prop2[j].e.bottom) {
							prop2[j].flag = 2;
							dig_v = -dig_v;
							n = j;
						}
					}
				}
				if (hookx >= 850 || hookx <= 0 || hooky >= 700) dig_v = -dig_v;		//碰到边界收回钩子
				if (r == root) {
					dig_v = -dig_v;
					flag = 0;					//收到原来的r时停止
					flag_dig = 0;				//停止下挖dig
					if (m != -1 || n != -1) {				//m必须有初值 否则遇到没有抓到东西时会出错
									//抓到小球过关
						if (m == 0 || n == 0) {
							EndBatchDraw();
							victory(daynum);
						}
						if (daynum == 1) prop1[m].flag = 0;
						if (daynum == 2) prop2[n].flag = 0;
						m = -1;
						n = -1;
						number++;
					}
				}
			}
			EndBatchDraw();
		}
	}
}

void gameover() {
	for (int i = 0; i < 29; i++) {
		putimage(0, 0, &day1_over[i]);
		Sleep(80);
	}

	system("pause");
	closegraph();
}

void day1() {

	for (int i = 0; i < 43; i++) {
		putimage(0, 0, &day1_start[i]);
		Sleep(80);
	}

	mouse(640, 600, 825, 650);

	for (int i = 0; i < 77; i++) {
		putimage(0, 0, &day1_story[i]);
		Sleep(50);
	}

	mouse(628, 615, 820, 665);
	gameUI();
}

void day2() {
	for (int i = 0; i < 45; i++) {
		putimage(0, 0, &day2_start[i]);
		Sleep(80);
	}

	mouse(640, 600, 825, 650);

	for (int i = 0; i < 78; i++) {
		putimage(0, 0, &day2_story[i]);
		Sleep(50);
	}
	mouse(628, 615, 820, 665);

	daynum = 2;
	number = -1;
	retime = 30;
	gameUI();

	prop2[0].e.left = prop2[0].x = 520;
	prop2[0].e.top = prop2[0].y = 600;
	prop2[1].e.left = prop2[1].x = 120;
	prop2[1].e.top = prop2[1].y = 280;
	prop2[2].e.left = prop2[2].x = 420;
	prop2[2].e.top = prop2[2].y = 320;
	prop2[3].e.left = prop2[3].x = 650;
	prop2[3].e.top = prop2[3].y = 450;
	prop2[4].e.left = prop2[4].x = 150;
	prop2[4].e.top = prop2[4].y = 500;

	for (int i = 0; i < 5; i++) {
		prop2[i].e.right = prop2[i].e.left + prop2[i].img.getwidth();
		prop2[i].e.bottom = prop2[i].e.top + prop2[i].img.getheight();
	}
}

void mouse(int left, int top, int right, int bottom) {
	MOUSEMSG m;
	setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 5);
	while (1) {
		m = GetMouseMsg();
		if (m.x >= left && m.x <= right && m.y >= top && m.y <= bottom) {
			setlinecolor(WHITE);
			line(left, bottom, right, bottom);
			if (m.uMsg == WM_LBUTTONDOWN) return;
		}
		else {
			setlinecolor(RGB(135, 206, 250));
			line(left, bottom, right, bottom);
		}
	}
}

void logIn() {
	loadlogo();
	loadimg();
	loadimage(&home, "src\\home.jpg");
	putimage(0, 0, &home);

	mouse(660, 580, 800, 650);
	day1();
}

void gameUI() {
	putimage(0, 0, &background);					//游戏界面背景
	putimage(400, 90, &pig_mask, NOTSRCERASE);		//佩奇
	putimage(400, 90, &pig, SRCINVERT);

	if (daynum == 1) {
		for (int i = 0; i < 6; i++) {
			if (prop1[i].flag != 0) {
				putimage(prop1[i].x, prop1[i].y, &prop1[i].img_mask, NOTSRCERASE);
				putimage(prop1[i].x, prop1[i].y, &prop1[i].img, SRCINVERT);
			}
		}
	}
	else {
		for (int i = 0; i < 5; i++) {
			if (prop2[i].flag != 0) {
				putimage(prop2[i].x, prop2[i].y, &prop2[i].img_mask, NOTSRCERASE);
				putimage(prop2[i].x, prop2[i].y, &prop2[i].img, SRCINVERT);
			}
		}
	}

	wsprintf(num, "%d", number);
	wsprintf(nowtime, "%d", retime);
	setbkcolor(RGB(35, 181, 240));
	settextstyle(30, 0, "宋体");
	outtextxy(100, 90, num);
	outtextxy(700, 90, nowtime);

	count++;							//简单实现倒计时
	if (count % 50 == 0) retime--;
	if (retime <= 0) EndBatchDraw();
}