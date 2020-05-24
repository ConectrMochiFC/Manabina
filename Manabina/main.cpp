#include "DxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <string.h>

#define WinX 1120
#define WinY 630

#pragma warning(disable: 4996)

int randbgm_Title = 0;

char scene = 0;
int Image_Title[10];
int Image_Kazu[5];
int Image_Dan1[5];
int Image_RDSE[10];
int Image_GRD[5];
int Image_ADV[50];
int Image_TOHO[40];
int BGM_Name[10];
int BGM_RD[5];
int BGM_ADV[15];
int BGM_TOHO[20];
int SE_Name[10];
int Trans[10] = {};
int Teki[10] = {};
int BG_Tra[6] = {};

int count[5];
int EndFlag = 0;

int key_flag = 0;

int mode = 0;
int Kazu_mode = 0;

int select_class = 0;
int allclear = 0;


//------------------------セーブデータ---------------------------//

FILE *Kazu_save;
char String[256];
int number = -100;

std::vector<int> save_con;


int StarFlag[5];

FILE *Star_kousin;
int kunsyo_youso = 0;
char kunsyo_char;

//------------------------リードダンジョンデータ---------------------//
/*
FILE *RD1_data;
char buf1[256];

std::string str;
std::vector<int> data_kazu;
*/

int lastB_henge = 0,Tra_6B=0;
int boss_dispflag = 0;

//------------------------フォントデータ-------------------------//

int defo, modefont,kazufont[5];
int White, Red,Blue,Black,Green;
int story;

//--------------------------------------------------------------//


void Init() {
	SetWindowSize(WinX, WinY);
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);
}

void GraphLoad() {
	Image_Title[0] = LoadGraph("Graph/Title_back.png");
	Image_Title[1] = LoadGraph("Graph/TitleName.png");
	Image_Title[2] = LoadGraph("Graph/さんすう.png");
	Image_Title[3] = LoadGraph("Graph/こくご.png");
	Image_Title[4] = LoadGraph("Graph/やすみ.png");
	Image_Title[5] = LoadGraph("Graph/kari1.jpg");
	Image_Title[6] = LoadGraph("Graph/OK_Star.png");
	Image_Title[7] = LoadGraph("Graph/NO_Star.png");
	Image_Title[8] = LoadGraph("Graph/StarText.png");

	Image_Kazu[0] = LoadGraph("Graph/kazu_bg.png");
	Image_Kazu[1] = LoadGraph("Graph/Ready.png");
	Image_Kazu[2] = LoadGraph("Graph/Go.png");
	Image_Kazu[3] = LoadGraph("Graph/Finish.png");
	Image_Kazu[4] = LoadGraph("Graph/TimeB.png");
	Image_Dan1[0] = LoadGraph("Graph/danjon_1.png");
	Image_Dan1[1] = LoadGraph("Graph/monster/pra_1.png");
	Image_Dan1[2] = LoadGraph("Graph/Clear.png");
	Image_Dan1[3] = LoadGraph("Graph/GameO.png");
	Image_Dan1[4] = LoadGraph("Graph/Change.png");

	Image_RDSE[0] = LoadGraph("Graph/RD/RP.png");
	Image_RDSE[1] = LoadGraph("Graph/RD/RP_SE.jpeg");
	Image_RDSE[2] = LoadGraph("Graph/RD/ADV2.png");
	Image_RDSE[3] = LoadGraph("Graph/RD/ADV_SE.jpg");
	Image_RDSE[4] = LoadGraph("Graph/RD/GRD.png");
	Image_RDSE[5] = LoadGraph("Graph/RD/GRD_SE.jpg");
	Image_RDSE[6] = LoadGraph("Graph/RD/TOHO.png");
	Image_RDSE[7] = LoadGraph("Graph/RD/TOHO_SE.jpg");

	Image_GRD[0] = LoadGraph("Graph/RD/taiikukan.jpg");
	Image_GRD[1] = LoadGraph("Graph/monster/grd.png");

	Image_ADV[0] = LoadGraph("Graph/ADV/1_Do.jpg");
	Image_ADV[1] = LoadGraph("Graph/monster/1_1.png");
	Image_ADV[2] = LoadGraph("Graph/monster/1_2.png");
	Image_ADV[3] = LoadGraph("Graph/ADV/1_Boss.jpg");
	Image_ADV[4] = LoadGraph("Graph/monster/1_Boss.png");
	Image_ADV[5] = LoadGraph("Graph/ADV/ALL.png");
	Image_ADV[6] = LoadGraph("Graph/ADV/2_Do.jpg");
	Image_ADV[7] = LoadGraph("Graph/ADV/2_Boss.jpg");
	Image_ADV[8] = LoadGraph("Graph/monster/2_1.png");
	Image_ADV[9] = LoadGraph("Graph/monster/2_2.png");
	Image_ADV[10] = LoadGraph("Graph/monster/2_Boss.png");
	Image_ADV[11] = LoadGraph("Graph/ADV/3_Do.jpg");
	Image_ADV[12] = LoadGraph("Graph/ADV/3_Boss.jpg");
	Image_ADV[13] = LoadGraph("Graph/monster/3_1.png");
	Image_ADV[14] = LoadGraph("Graph/monster/3_2.png");
	Image_ADV[15] = LoadGraph("Graph/monster/3_3.png");
	Image_ADV[16] = LoadGraph("Graph/monster/3_Boss.png");
	Image_ADV[17] = LoadGraph("Graph/ADV/4_Do1.jpeg");
	Image_ADV[18] = LoadGraph("Graph/ADV/4_Do2.jpg");
	Image_ADV[19] = LoadGraph("Graph/ADV/4_Do3.png");
	Image_ADV[20] = LoadGraph("Graph/ADV/4_Boss.jpg");
	Image_ADV[21] = LoadGraph("Graph/monster/4_1.png");
	Image_ADV[22] = LoadGraph("Graph/monster/4_2.png");
	Image_ADV[23] = LoadGraph("Graph/monster/4_3.png");
	Image_ADV[24] = LoadGraph("Graph/monster/4_Boss.png");
	Image_ADV[25] = LoadGraph("Graph/ADV/5_Do1.jpg");
	Image_ADV[26] = LoadGraph("Graph/ADV/5_Do2.jpg");
	Image_ADV[27] = LoadGraph("Graph/ADV/5_Do3.jpg");
	Image_ADV[28] = LoadGraph("Graph/ADV/5_Boss.jpg");
	Image_ADV[29] = LoadGraph("Graph/monster/5_1.png");
	Image_ADV[30] = LoadGraph("Graph/monster/5_2.png");
	Image_ADV[31] = LoadGraph("Graph/monster/5_3.png");
	Image_ADV[32] = LoadGraph("Graph/monster/5_4.png");
	Image_ADV[33] = LoadGraph("Graph/monster/5_Boss.png");
	Image_ADV[34] = LoadGraph("Graph/ADV/6_Do2.jpeg");
	Image_ADV[35] = LoadGraph("Graph/ADV/6_Boss.jpg");
	Image_ADV[36] = LoadGraph("Graph/monster/6_1.png");
	Image_ADV[37] = LoadGraph("Graph/monster/6_Boss1.png");
	Image_ADV[38] = LoadGraph("Graph/monster/6_Boss2.png");
	Image_ADV[39] = LoadGraph("Graph/ADV/White.png");
	Image_ADV[40] = LoadGraph("Graph/ADV/Ex_Do1.jpg");
	Image_ADV[41] = LoadGraph("Graph/ADV/Ex_Do2.jpg");
	Image_ADV[42] = LoadGraph("Graph/ADV/Ex_Boss1.jpg");
	Image_ADV[43] = LoadGraph("Graph/monster/Ex_1.png");
	Image_ADV[44] = LoadGraph("Graph/monster/Ex_2.png");
	Image_ADV[45] = LoadGraph("Graph/monster/Ex_3.png");
	Image_ADV[46] = LoadGraph("Graph/monster/Ex_4.png");
	Image_ADV[47] = LoadGraph("Graph/monster/Ex_5.png");
	Image_ADV[48] = LoadGraph("Graph/monster/Ex_6.png");
	Image_ADV[49] = LoadGraph("Graph/monster/Ex_Boss1.png");

	Image_TOHO[0] = LoadGraph("Graph/TOHO/１/1-Do.png");
	Image_TOHO[1] = LoadGraph("Graph/TOHO/１/1-Boss.png");
	Image_TOHO[2] = LoadGraph("Graph/TOHO/Enemy/1-1.png");
	Image_TOHO[3] = LoadGraph("Graph/TOHO/Enemy/1-2.png");
	Image_TOHO[4] = LoadGraph("Graph/TOHO/１/1-BossG.png");
	Image_TOHO[5] = LoadGraph("Graph/TOHO/１/1-BossG2.png");
	Image_TOHO[6] = LoadGraph("Graph/TOHO/2/2-Do.png");
	Image_TOHO[7] = LoadGraph("Graph/TOHO/2/2-Boss.png");
	Image_TOHO[8] = LoadGraph("Graph/TOHO/Enemy/2-1.png");
	Image_TOHO[9] = LoadGraph("Graph/TOHO/Enemy/2-2.png");
	Image_TOHO[10] = LoadGraph("Graph/TOHO/2/2-BossG.png");
	Image_TOHO[11] = LoadGraph("Graph/TOHO/2/2-BossG2.png");
	Image_TOHO[12] = LoadGraph("Graph/TOHO/3/3-Do.png");
	Image_TOHO[13] = LoadGraph("Graph/TOHO/3/3-Boss.png");
	Image_TOHO[14] = LoadGraph("Graph/TOHO/Enemy/3-1.png");
	Image_TOHO[15] = LoadGraph("Graph/TOHO/Enemy/3-2.png");
	Image_TOHO[16] = LoadGraph("Graph/TOHO/Enemy/3-3.png");
	Image_TOHO[17] = LoadGraph("Graph/TOHO/3/3-BossG.png");
	Image_TOHO[18] = LoadGraph("Graph/TOHO/3/3-BossG2.png");

	Image_TOHO[19] = LoadGraph("Graph/TOHO/4/4-Do.png");
	Image_TOHO[20] = LoadGraph("Graph/TOHO/4/4-Boss.png");
	Image_TOHO[21] = LoadGraph("Graph/TOHO/Enemy/4-2.png");
	Image_TOHO[22] = LoadGraph("Graph/TOHO/Enemy/4-3.png");
	Image_TOHO[23] = LoadGraph("Graph/TOHO/Enemy/4-4.png");
	Image_TOHO[24] = LoadGraph("Graph/TOHO/4/4-BossG.png");
	Image_TOHO[25] = LoadGraph("Graph/TOHO/4/4-BossG2.png");

	Image_TOHO[26] = LoadGraph("Graph/TOHO/5/5-Do.png");
	Image_TOHO[27] = LoadGraph("Graph/TOHO/5/5-Boss.png");
	Image_TOHO[28] = LoadGraph("Graph/TOHO/Enemy/5-1.png");
	Image_TOHO[29] = LoadGraph("Graph/TOHO/Enemy/5-2.png");
	Image_TOHO[30] = LoadGraph("Graph/TOHO/Enemy/5-3.png");
	Image_TOHO[31] = LoadGraph("Graph/TOHO/5/5-BossG.png");
	Image_TOHO[32] = LoadGraph("Graph/TOHO/5/5-BossG2.png");

	Image_TOHO[33] = LoadGraph("Graph/TOHO/6/6-Do.png");
	Image_TOHO[34] = LoadGraph("Graph/TOHO/6/6-Boss.png");
	Image_TOHO[35] = LoadGraph("Graph/TOHO/Enemy/6-1.png");
	Image_TOHO[36] = LoadGraph("Graph/TOHO/6/6-BossG.png");
	Image_TOHO[37] = LoadGraph("Graph/TOHO/6/6-BossG2.png");

	defo = CreateFontToHandle(NULL, -1, -1, -1);
	modefont = CreateFontToHandle(NULL, 40, -1, -1);

	story = CreateFontToHandle(NULL, 18, -1, DX_FONTTYPE_EDGE);

	kazufont[0] = CreateFontToHandle(NULL, 60, -1, -1);
	kazufont[1] = CreateFontToHandle(NULL, 40, -1, -1);
	kazufont[2] = CreateFontToHandle(NULL, 30, -1, -1);
	kazufont[3] = CreateFontToHandle(NULL, 20, -1, -1);

	BGM_Name[0] = LoadSoundMem("Sound/hinamaturi.ogg");
	BGM_Name[1] = LoadSoundMem("Sound/kaen.ogg");
	BGM_Name[2] = LoadSoundMem("Sound/tetlys.ogg");
	BGM_Name[3] = LoadSoundMem("Sound/med.ogg");
	BGM_Name[4] = LoadSoundMem("Sound/gymnopedie.ogg");

	BGM_RD[0] = LoadSoundMem("Sound/RD_Pra.ogg");
	BGM_RD[1] = LoadSoundMem("Sound/GRD_5I.ogg");
	BGM_RD[2] = LoadSoundMem("Sound/GRD_6U.ogg");

	BGM_ADV[0] = LoadSoundMem("Sound/ADV/ADV1-Do.ogg");
	BGM_ADV[1] = LoadSoundMem("Sound/ADV/ADV1-Boss.ogg");
	BGM_ADV[2] = LoadSoundMem("Sound/ADV/ADV2-Do.ogg");
	BGM_ADV[3] = LoadSoundMem("Sound/ADV/ADV2-Boss.ogg");
	BGM_ADV[4] = LoadSoundMem("Sound/ADV/ADV3-Do.ogg");
	BGM_ADV[5] = LoadSoundMem("Sound/ADV/ADV3-Boss.ogg");
	BGM_ADV[6] = LoadSoundMem("Sound/ADV/ADV4-Do.ogg");
	BGM_ADV[7] = LoadSoundMem("Sound/ADV/ADV4-Boss.ogg");
	BGM_ADV[8] = LoadSoundMem("Sound/ADV/ADV5-Do.ogg");
	BGM_ADV[9] = LoadSoundMem("Sound/ADV/ADV5-Boss.ogg");
	BGM_ADV[10] = LoadSoundMem("Sound/ADV/ADV6-Do.ogg");
	BGM_ADV[11] = LoadSoundMem("Sound/ADV/ADV6-Boss.ogg");
	BGM_ADV[12] = LoadSoundMem("Sound/ADV/Ex-Do.ogg");
	BGM_ADV[13] = LoadSoundMem("Sound/ADV/Ex-Boss.ogg");
	BGM_ADV[14] = LoadSoundMem("Sound/ADV/Ex-Clear.ogg");

	BGM_TOHO[0] = LoadSoundMem("Sound/TOHO/TOHO1-Do2.ogg");
	BGM_TOHO[1] = LoadSoundMem("Sound/TOHO/TOHO1-Boss2.ogg");
	BGM_TOHO[2] = LoadSoundMem("Sound/TOHO/TOHO2-Do2.ogg");
	BGM_TOHO[3] = LoadSoundMem("Sound/TOHO/TOHO2-Boss2.ogg");
	BGM_TOHO[4] = LoadSoundMem("Sound/TOHO/TOHO3-Do2.ogg");
	BGM_TOHO[5] = LoadSoundMem("Sound/TOHO/TOHO3-Boss2.ogg");
	BGM_TOHO[6] = LoadSoundMem("Sound/TOHO/TOHO4-Boss2.ogg");
	BGM_TOHO[7] = LoadSoundMem("Sound/TOHO/TOHO5-Do2.ogg");
	BGM_TOHO[8] = LoadSoundMem("Sound/TOHO/TOHO5-Boss2.ogg");
	BGM_TOHO[9] = LoadSoundMem("Sound/TOHO/TOHO6-Do2.ogg");
	BGM_TOHO[10] = LoadSoundMem("Sound/TOHO/TOHO6-Boss2.ogg");


	SE_Name[0] = LoadSoundMem("Sound/finish.ogg");
	SE_Name[1] = LoadSoundMem("Sound/bornas.ogg");

	SE_Name[2] = LoadSoundMem("Sound/sword1.ogg");
	SE_Name[3] = LoadSoundMem("Sound/enter.ogg");
	SE_Name[4] = LoadSoundMem("Sound/hit.ogg");
	SE_Name[5] = LoadSoundMem("Sound/haziki.ogg");
	SE_Name[6] = LoadSoundMem("Sound/hakai.ogg");
	SE_Name[7] = LoadSoundMem("Sound/set.ogg");
	SE_Name[8] = LoadSoundMem("Sound/hidan.ogg");
	

	White = GetColor(255, 255, 255);
	Red = GetColor(255, 0, 0);
	Blue = GetColor(0, 0, 255);
	Black = GetColor(0, 0, 0);
	Green = GetColor(0, 255, 0);

	/*Kazu_save = fopen("Save/kazuitti.txt","a+");
	if (Kazu_save == NULL) {
		EndFlag = 1;
	}*/

}

void ProgEnd() {
	InitSoundMem();
	InitGraph();
	InitKeyInput();
	//fclose();
}


void Title() {
	static int OneTimeTitle = 1,OneTimeP=0;
	static double Name_size;
	static int Name_kai;
	static int title_select = 1;
	static int point_now = 1;

	static FILE *Star_disp;
	static char buf1;
	static int bb=0;

	if (OneTimeP == 0) {
		Star_disp = fopen("Save/Star.txt","r");
		if (Star_disp == NULL) {
			EndFlag = 1;
		}
		while ((buf1 = fgetc(Star_disp)) != EOF) {
			StarFlag[bb] = (buf1-'0');
			bb++;
		}
		fclose(Star_disp);
		OneTimeP = 1;
	}

	if (OneTimeTitle == 1) {
		Trans[0] = 0;
		Trans[1] = 0;
		OneTimeTitle = 0;
		Name_size = 1.0;
		Name_kai = 150;
		
	}
	if (randbgm_Title == 0) {
		if (CheckSoundMem(BGM_Name[0]) == 0) PlaySoundMem(BGM_Name[0], DX_PLAYTYPE_LOOP);
	}
	else if (randbgm_Title == 1) {
		if (CheckSoundMem(BGM_Name[4]) == 0) PlaySoundMem(BGM_Name[4], DX_PLAYTYPE_LOOP);
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[0]);
	DrawRotaGraph(300, 250, 0.8, 0.0, Image_Title[0], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	if (Trans[0] < 255) {
		Trans[0] += 5;
	}
	else {
		if (Name_size > 0.5)Name_size -= 0.02;
		if (Name_kai > 0) Name_kai -= 6;
		else if (Trans[1] < 255) {
			Trans[1] += 5;
		}
		else {
			if (count[0] % 20 == 0) title_select *= -1;
		}
		DrawRotaGraph(320, 100, Name_size, Name_kai, Image_Title[1], TRUE);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[1]);
		if (title_select == 1)
			DrawRotaGraph(170, 200, 1.3, 0.0, Image_Title[2], TRUE);
		else
			DrawRotaGraph(170, 200, 1.0, 0.0, Image_Title[2], TRUE);
		//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[1]);
		if (title_select == 2)
			DrawRotaGraph(470, 200, 1.3, 0.0, Image_Title[3], TRUE);
		else
			DrawRotaGraph(470, 200, 1.0, 0.0, Image_Title[3], TRUE);
		//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[1]);
		if (title_select == 99 || title_select==101)
			DrawRotaGraph(180, 380, 1.2, 0.0, Image_Title[8], TRUE);
		else
			DrawRotaGraph(180, 380, 1.0, 0.0, Image_Title[8], TRUE);
		if (title_select == 98 || title_select==102)
			DrawRotaGraph(500, 380, 1.3, 0.0, Image_Title[4], TRUE);
		else
			DrawRotaGraph(500, 380, 1.0, 0.0, Image_Title[4], TRUE);
		for (int i = 0; i < 5; i++) {
			if (StarFlag[i] == 1) DrawRotaGraph(180 + (i * 70), 300, 0.6, 0.0, Image_Title[6], TRUE);
			else if (StarFlag[i] == 0) DrawRotaGraph(180 + (i * 70), 300, 0.6, 0.0, Image_Title[7], TRUE);
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	}

	
//ーーーーーーーーーーーーーーーーーーーーデバッグ用変数表示、あとで消すことーーーーーーーーーーーーーーーーーー//
	//DrawFormatString(30, 100, GetColor(255,255,255), "title_select:%d \n point:%d", title_select,point_now);

//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー//

	//方向キー入力により操作
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && key_flag == 0 && (point_now==1 || point_now==101)) {
		if (point_now == 101) {
			if (title_select < 100) {
				if(title_select<-50 && title_select>-100) title_select++;
				else title_select--;
			}
			else title_select++;
			point_now = 102;
		}
		if (point_now == 1) {
			title_select += 1;point_now = 2;
		}
		key_flag = 1;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT) == 1 && key_flag == 0 && (point_now==2 || point_now==102)) {
		if (point_now == 102) {
			if (title_select < 100) {
				if (title_select < -50 && title_select>-100) title_select--;
				else title_select++;
			}
			else title_select--;
			point_now = 101;
		}
		if (point_now == 2) {
			title_select -= 1;point_now = 1;
		}
		key_flag = 1;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1 && key_flag == 0 && (point_now==1 || point_now==2)) {
		title_select += 100; key_flag = 1; point_now += 100;
	}
	else if (CheckHitKey(KEY_INPUT_UP) == 1 && key_flag == 0 && point_now>=98) {
		key_flag = 1; point_now -= 100;
		if (title_select >= 0) title_select -= 100;
		else if (title_select < 0) title_select += 100;
	}
	//長押し判定防止用
	else if (CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0 && CheckHitKey(KEY_INPUT_UP) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0 && CheckHitKey(KEY_INPUT_RETURN)==0)
		key_flag = 0;


	//選択している部分が数値をはみ出していないかチェック、はみ出しているようなら修正
	if (title_select ==0) title_select = 2;
	else if (title_select ==-3) title_select = 1;
	//if (title_select > 150) title_select -=100;
	//if (title_select < -3) title_select += 100;


//ーーーーーーーーーーーーーーーーエンターキーによる決定ーーーーーーーーーーーーーーーーーーーーー//

	if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0 && Trans[1]>=255) {
		if (point_now == 1) {
			mode = 1; scene = 1;
		}
		else if (point_now == 2) {
			mode = 2; scene = 1;
		}
		else if (point_now == 101) {
			scene = 20;
		}
		else EndFlag = 1;
		

		//------------------------タイトル初期化---------------------//
		OneTimeTitle = 1;
		title_select = 1;
		point_now = 1;
		count[0] = 0;
		key_flag = 1; bb = 0;
		//-----------------------------------------------------------//
	}

}

//ーーーーーーーーーーーーーーーーーーーーーー　スター入手条件　－－－－－－－－－－－－－－－－－－－－－－－


void Star() {
	DrawRotaGraph(300, 250, 0.8, 0.0, Image_Title[0], TRUE);

	for (int i = 0; i < 5; i++) {
		if (StarFlag[i] == 1) DrawRotaGraph(50, 50+(i*80), 0.6, 0.0, Image_Title[6], TRUE);
		else if (StarFlag[i] == 0) DrawRotaGraph(50, 50+(i*80), 0.6, 0.0, Image_Title[7], TRUE);
	}

	if (StarFlag[0] == 1) DrawStringToHandle(80, 25, "・・カズイッチショートかノーマルで\n　　タイムボーナスを5回以上行う", Red, kazufont[2]);
	else DrawStringToHandle(80, 25, "・・カズイッチショートかノーマルで\n　　タイムボーナスを5回以上行う", White, kazufont[2]);

	if (StarFlag[1] == 1) DrawStringToHandle(80, 105, "・・カズイッチロングかノーマルで\n　　目標の数が100を超える", Red, kazufont[2]);
	else DrawStringToHandle(80, 105, "・・カズイッチロングかノーマルで\n　　目標の数が100を超える", White, kazufont[2]);

	if (StarFlag[2] == 1) DrawStringToHandle(80, 185, "・・リードダンジョンの\n　　東方イベントをクリア", Red, kazufont[2]);
	else DrawStringToHandle(80, 185, "・・リードダンジョンの\n　　東方イベントをクリア", White, kazufont[2]);

	if(StarFlag[3]==1) DrawStringToHandle(80, 265, "・・リードダンジョンの\n　　アドベンチャーをクリア", Red, kazufont[2]);
	else DrawStringToHandle(80, 265, "・・リードダンジョンの\n　　アドベンチャーをクリア", White, kazufont[2]);

	if (StarFlag[4] == 1) DrawStringToHandle(80, 345, "・・リードダンジョンの\n　　エクストラステージをクリア", Red, kazufont[2]);
	else DrawStringToHandle(80, 345, "・・リードダンジョンの\n　　エクストラステージをクリア", White, kazufont[2]);


	if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
		scene = 0;

		count[0] = 0;
		key_flag = 1;
	}
	if (CheckHitKey(KEY_INPUT_RETURN) == 0)
		key_flag = 0;

}

//ーーーーーーーーーーーーーーーーーーーー　ゲーム選択　－－－－－－－－－－－－－－－－－－－－－－－//


void SelectMode() {

	static int mode_corsol = 1;
	static int con_sele = 0,Exflag;

	static FILE *Kaiho;

	DrawRotaGraph(330, 240, 0.8, 0.0, Image_Title[5], TRUE);

	if (mode == 1) {
		if (mode_corsol > 3 && mode_corsol<100) mode_corsol = 3;
		if (mode_corsol <= 0) mode_corsol = 1;
		if (mode_corsol == 1) {
			DrawStringToHandle(30, 70, "カズイッチ ショート", Red, modefont);
			DrawStringToHandle(30, 200, "カズイッチ ノーマル", White, modefont);
			DrawStringToHandle(30, 330, "カズイッチ ロング", White, modefont);
			DrawStringToHandle(500, 400, "もどる", White, modefont);
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag==0) {
				mode_corsol = 1; Kazu_mode = 1;
				scene = 2;
			}
		}
		if (mode_corsol == 2) {
			DrawStringToHandle(30, 70, "カズイッチ ショート", White, modefont);
			DrawStringToHandle(30, 200, "カズイッチ ノーマル", Red, modefont);
			DrawStringToHandle(30, 330, "カズイッチ ロング", White, modefont);
			DrawStringToHandle(500, 400, "もどる", White, modefont);
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
				mode_corsol = 1; Kazu_mode = 2;
				scene = 2;
			}
		}
		if (mode_corsol == 3) {
			DrawStringToHandle(30, 70, "カズイッチ ショート", White, modefont);
			DrawStringToHandle(30, 200, "カズイッチ ノーマル", White, modefont);
			DrawStringToHandle(30, 330, "カズイッチ ロング", Red, modefont);
			DrawStringToHandle(500, 400, "もどる", White, modefont);
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
				mode_corsol = 1; Kazu_mode = 3;
				scene = 2;
			}
		}
		else if(mode_corsol>=100) {
			DrawStringToHandle(30, 70, "カズイッチ ショート", White, modefont);
			DrawStringToHandle(30, 200, "カズイッチ ノーマル", White, modefont);
			DrawStringToHandle(30, 330, "カズイッチ ロング", White, modefont);
			DrawStringToHandle(500, 400, "もどる", Red, modefont);

			if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
				mode_corsol = 1; key_flag = 1;
				scene = 0;
			}
		}
	}

	else if (mode == 2) {
		if (mode_corsol > 2 && mode_corsol < 100) mode_corsol = 2;
		if (con_sele==0) {
			int num=0;
			con_sele = 1;
			Kaiho = fopen("Save/RD_Ex.txt","r");
			if (Kaiho == NULL) {
				EndFlag = 1;
			}
			while (fgets(String, sizeof(String), Kaiho) != NULL) {
				num = atoi(String);
				//save_con.push_back(number);
			}
			fclose(Kaiho);
			Exflag = num;
		}
		if (mode_corsol <= 0) mode_corsol = 1;
		switch (mode_corsol) {
		case 1:
			DrawStringToHandle(30, 70, "リードダンジョン", Red, modefont);
			if(Exflag==0) DrawStringToHandle(30, 200, "＊未開放＊", White, modefont);
			else if(Exflag==1) DrawStringToHandle(30, 200, "リードダンジョン\n[エクストラ]", White, modefont);
			DrawStringToHandle(500, 400, "もどる", White, modefont);
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
				mode_corsol = 1; key_flag = 1; con_sele = 0;
				scene = 4;
			}
			break;
		case 2:
			DrawStringToHandle(30, 70, "リードダンジョン", White, modefont);
			if (Exflag == 0) DrawStringToHandle(30, 200, "＊未開放＊", Red, modefont);
			else if (Exflag == 1) {
				DrawStringToHandle(30, 200, "リードダンジョン\n[エクストラ]", Red, modefont);
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
					mode_corsol = 1; key_flag = 1;
					mode = 3; con_sele = 0;
				}
			}
			DrawStringToHandle(500, 400, "もどる", White, modefont);
			break;
		case 101:
		case 102:
			DrawStringToHandle(30, 70, "リードダンジョン", White, modefont);
			if (Exflag == 0) DrawStringToHandle(30, 200, "＊未開放＊", White, modefont);
			else if (Exflag == 1) DrawStringToHandle(30, 200, "リードダンジョン\n[エクストラ]", White, modefont);
			DrawStringToHandle(500, 400, "もどる", Red, modefont);
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
				mode_corsol = 1; key_flag = 1;
				scene = 0; con_sele = 0;
			}
			break;
		default:
			break;
		}
	}
	if (mode == 3) {
		if (mode_corsol > 2) mode_corsol = 2;
		if (mode_corsol <= 0) mode_corsol = 1;
		DrawStringToHandle(30, 50, "長くなりますが、平気ですか？\n(全60問)", White, modefont);
		if (mode_corsol == 1) {
			DrawStringToHandle(200, 250, "かまうものか", Red, modefont);
			DrawStringToHandle(200, 350, "かなうものか", White, modefont);
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
				mode_corsol = 1; key_flag = 1;
				scene = 7; con_sele = 0; mode = 2;
			}
		}
		else if (mode_corsol == 2) {
			DrawStringToHandle(200, 250, "かまうものか", White, modefont);
			DrawStringToHandle(200, 350, "かなうものか", Red, modefont);
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
				mode_corsol = 1; key_flag = 1;
				mode=2; con_sele = 1;
			}
		}
	}

	if (CheckHitKey(KEY_INPUT_DOWN) == 1 && key_flag==0 && mode_corsol<100) {
		mode_corsol++;
		key_flag = 1;
	}
	else if (CheckHitKey(KEY_INPUT_UP) == 1 && key_flag==0 && mode_corsol<100) {
		mode_corsol--; key_flag = 1;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && key_flag==0 && mode_corsol<100) {
		mode_corsol +=100; key_flag = 1;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT) == 1 && mode_corsol>=100 && key_flag==0) {
		mode_corsol-=100;
	}
	if (CheckHitKey(KEY_INPUT_RETURN) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0 && CheckHitKey(KEY_INPUT_UP) == 0
		&& CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0) {
		key_flag = 0;
	}
}

//ーーーーーーーーーーーーーーーーーーーーーーーー　カズイッチ　ーーーーーーーーーーーーーーーーーーーーーーー//

void Kazuitti() {

	static double large_r = 0.0;
	static double pai = 0.0, large_go = 3.4;

	static int Kazu_Target = 10;
	static int Kazu_Koma[10] = {};
	static int youso = 0;
	static int Kazu_OneTime = 0;
	static int kazu_loop_break = 0;
	static int dainyu = 1;

	static int loop_flag = 0;

	static int kaisuu = 0;
	static int zero_flag = 0;
	static int daiiti = 0;

	static int check[10] = {};
	static int kasan = 0, kasan_ban = 0, sum = 0, button_flag = 0;

	static int minute=0,second=10,kazu_count=0;

	static int FinishFlag = 0, finish_count = 0;
	static unsigned long kazu_point = 0;
	static int score[10];

	static double renzoku = 0.01, bairitu = 0.0;

	static int bornas_flag = 0, count_bornas = 0;
	static int time_bornas = 0, time_b_flag = 0,time_b_temp=0,time_x=1000,bornas_second;
	
	static int for_loop = 0;
	static int TimeB_Sougou = 0;

//ーーーーーーーーーーーーーーーーーーーー　初期設定（分数もここ）　－－－－－－－－－－－－－－－－－－

	if (CheckSoundMem(BGM_Name[0]) == 1) StopSoundMem(BGM_Name[0]);
	else if (CheckSoundMem(BGM_Name[4]) == 1) StopSoundMem(BGM_Name[4]);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[2]);
	DrawRotaGraph(330, 240, 0.8, 0.0, Image_Kazu[0], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	if (Trans[2] < 255) Trans[2] += 5;
	else if (count[1] >=120 && count[1]<180) {
		DrawRotaGraph(320, 150, large_r, 0.0, Image_Kazu[1], TRUE);
		if (large_r < 1.0) large_r += 0.05;
	}
	else if (count[1] >= 180 && count[1]<240) {
		DrawRotaGraph(320, 150, large_go, pai, Image_Kazu[2], TRUE);
		if (pai < 6.20) pai += 0.2; if (large_go > 1.0) large_go -= 0.08;
		if (pai > 6.20) pai = 6.28;
	}
	else if (count[1] == 240) {
		if (Kazu_mode == 1) {
			if (CheckSoundMem(BGM_Name[2]) == 0) PlaySoundMem(BGM_Name[2], DX_PLAYTYPE_LOOP);
			for_loop = 4; minute = 1; second = 0;
		}
		if (Kazu_mode == 2) {
			if (CheckSoundMem(BGM_Name[1]) == 0) PlaySoundMem(BGM_Name[1], DX_PLAYTYPE_LOOP);
			for_loop = 5; minute = 2; second = 0;
		}
		if (Kazu_mode == 3) {
			if (CheckSoundMem(BGM_Name[3]) == 0) PlaySoundMem(BGM_Name[3], DX_PLAYTYPE_LOOP);
			for_loop = 8; minute = 4; second = 30;
		}
		for (int i = 0; i < for_loop; i++) {
			Kazu_Koma[i] = 0;
		}
	}
	else if(count[1] >=240){
		kazu_count++;

//ーーーーーーーーーーーーーーーーーーーー　タイムボーナス　ーーーーーーーーーーーーーーーーーーーーーーーー

		static int time_b_count = 0;

		DrawBox(20, 15, 280, 35, Black, TRUE);
		if (time_bornas >= 255) time_bornas = 255;
		if (time_bornas < 0) time_bornas = 0;
		for (int i = 0; i < time_bornas; i++) {
			if (time_bornas >= 255) {
				DrawLine(25 + (i), 20, 25 + (i), 30, Red);
				time_b_flag = 1;
			}
			else {
				DrawLine(25 + (i), 20, 25 + (i), 30, White);
			}
		}
		if (time_b_flag == 1) {
			if (time_b_count == 0) {
				bornas_second = 10;
				if(Kazu_mode==1 || Kazu_mode==2) TimeB_Sougou++;
				time_b_temp = Kazu_Target;
			}
			time_b_count++;
			DrawRotaGraph(time_x, 250, 0.8, 0.0, Image_Kazu[4], TRUE);
			if (time_x >= 340) time_x -= 30;
			else {
				if (time_b_count > 100) {
					time_x -= 30;
					if (time_b_count % 50 == 0 && FinishFlag == 0) {
						bornas_second--;
					}
					DrawFormatStringToHandle(280, 230, GetColor(255, 50, 50), kazufont[0], "%d", bornas_second);
					if (bornas_second == 0) {
						for (int i = 0; i < for_loop; i++) {
							Kazu_Koma[i] = 0; check[i] = 0;
						}
						time_b_flag = 0; time_bornas = 0; time_b_count = 0; time_x = 1000;
						Kazu_OneTime = 0; dainyu = 1;
						kazu_loop_break = 0; kaisuu = 0;
						kasan = 0; sum = 0; Kazu_Target = time_b_temp;
					}
				}

			}
		}
//ーーーーーーーーーーーーーーーーーーーーーーー　値設定　－－－－－－－－－－－－－－－－－－－－－－－－－

		DrawBox(260, 100, 360, 200, Red,FALSE);
		if (Kazu_mode == 1) {
			for (int i = 0; i < 4; i++) {
				if (check[i] == 1) DrawBox(120 + (i * 110), 300, 180 + (i * 110), 360, Green, FALSE);
				else DrawBox(120 + (i * 110), 300, 180 + (i * 110), 360, Blue, FALSE);

			}
		}
		if (Kazu_mode == 2) {
			for (int i = 0; i < 5; i++) {
				if (check[i] == 1) DrawBox(80 + (i * 100), 300, 140 + (i * 100), 360, Green, FALSE);
				else DrawBox(80 + (i * 100), 300, 140 + (i * 100), 360, Blue, FALSE);

			}
		}
		if (Kazu_mode == 3) {
			for (int j = 0; j < 2; j++) {
				for (int i = 0; i < 4; i++) {
					if (check[i+(4*j)] == 1) DrawBox(120 + (i * 110), 270+(j*100), 180 + (i * 110), 330+(j*100), Green, FALSE);
					else DrawBox(120 + (i * 110), 270 + (j * 100), 180 + (i * 110), 330 + (j * 100), Blue, FALSE);
				}
			}
		}
		if (Kazu_Target >= 1000) DrawFormatStringToHandle(260, 130, Red, kazufont[0], "%d", Kazu_Target);
		else if(Kazu_Target>=100) DrawFormatStringToHandle(270, 130, Red, kazufont[0], "%d", Kazu_Target);
		else DrawFormatStringToHandle(280, 130, Red,kazufont[0], "%d", Kazu_Target);

		if (Kazu_OneTime == 0) {
			if (time_b_flag == 1) {
				Kazu_Target = Kazu_Target + (int)GetRand(Kazu_Target*4);
			}

			while (kaisuu<100) {
				loop_flag = 0;
				if (zero_flag == 0) {
					if(Kazu_mode==1) youso = (int)GetRand(3);
					if (Kazu_mode == 2) youso = (int)GetRand(4);
					if (Kazu_mode == 3) youso = (int)GetRand(7);
				}
				zero_flag = 0;
				//DrawFormatStringToHandle(100, 200, Blue, kazufont[1], "%d\n%d\n%d\n%d\n%d", Kazu_Koma[0], Kazu_Koma[1], Kazu_Koma[2], Kazu_Koma[3], Kazu_Koma[4]);
				/*do {
					youso = (int)GetRand(4);
				} while (Kazu_Koma[youso] != 0);*/
				if (Kazu_Koma[youso] == 0) {
					switch (dainyu) {
					case 1:
						for (int x = 0; x < 10; x++) {
							Kazu_Koma[youso] = (Kazu_Target - (int)GetRand(Kazu_Target));
							if (Kazu_Koma[youso] != Kazu_Target && Kazu_Koma[youso] != 0)
								break;
						}
						daiiti = youso;
						break;
					case 2:
						Kazu_Koma[youso] = (Kazu_Target - Kazu_Koma[daiiti]);
						break;
					case 3:
						Kazu_Koma[youso] = 1 + GetRand(Kazu_Target-2);
						break;
					case 4:
						Kazu_Koma[youso] = 1 + GetRand(Kazu_Target-2);
						break;
					case 5:
						Kazu_Koma[youso] = 1 + GetRand(Kazu_Target-2);
						break;
					case 6:
						Kazu_Koma[youso] = 1 + GetRand(Kazu_Target - 2);
						break;
					case 7:
						Kazu_Koma[youso] = 1 + GetRand(Kazu_Target - 2);
						break;
					case 8:
						Kazu_Koma[youso] = 1 + GetRand(Kazu_Target - 2);
						break;
					default:
						break;
					}
					
					for (int m = 0; m < for_loop; m++) {
						if ((Kazu_Koma[youso] == Kazu_Koma[m]) && (m != youso)) {
							loop_flag = 1;
						}
					}
					if (loop_flag == 1) {
						if ((Kazu_Target / Kazu_Koma[youso] == 2) && (Kazu_Target%Kazu_Koma[youso]==0)) dainyu++;
						else Kazu_Koma[youso] = 0;
					}
					else {
						dainyu++;
						kazu_loop_break = 1;
					}
				}
				for (int i = 0; i < for_loop; i++) {
					if (Kazu_Koma[i] == 0) {
						kazu_loop_break = 0;
						//kaisuu=0;
						zero_flag = 1; youso = i;
					}
				}
				if (zero_flag == 0) break;
				kaisuu++;
				
			}
			Kazu_OneTime = 1;
		}

		if (Kazu_mode == 1) {
			for (int j = 0; j < 4; j++) {
				if (Kazu_Koma[j] >= 1000) DrawFormatStringToHandle(110 + (j * 110), 310, Blue, kazufont[1], "%d", Kazu_Koma[j]);
				else if (Kazu_Koma[j] >= 100) DrawFormatStringToHandle(120 + (j * 110), 310, Blue, kazufont[1], "%d", Kazu_Koma[j]);
				else if (Kazu_Koma[j] >= 10) DrawFormatStringToHandle(130 + (j * 110), 310, Blue, kazufont[1], "%d", Kazu_Koma[j]);
				else DrawFormatStringToHandle(140 + (j * 110), 310, Blue, kazufont[1], "%d", Kazu_Koma[j]);
			}
			DrawStringToHandle(140, 380, "F", Black, kazufont[2]);
			DrawStringToHandle(250, 380, "G", Black, kazufont[2]);
			DrawStringToHandle(360, 380, "H", Black, kazufont[2]);
			DrawStringToHandle(470, 380, "J", Black, kazufont[2]);
		}
		if (Kazu_mode == 2) {
			for (int j = 0; j < 5; j++) {
				if (Kazu_Koma[j] >= 1000) DrawFormatStringToHandle(70 + (j * 100), 310, Blue, kazufont[1], "%d", Kazu_Koma[j]);
				else if (Kazu_Koma[j] >= 100) DrawFormatStringToHandle(80 + (j * 100), 310, Blue, kazufont[1], "%d", Kazu_Koma[j]);
				else if (Kazu_Koma[j] >= 10) DrawFormatStringToHandle(90 + (j * 100), 310, Blue, kazufont[1], "%d", Kazu_Koma[j]);
				else DrawFormatStringToHandle(100 + (j * 100), 310, Blue, kazufont[1], "%d", Kazu_Koma[j]);
			}
			DrawStringToHandle(100, 380, "F", Black, kazufont[2]);
			DrawStringToHandle(200, 380, "G", Black, kazufont[2]);
			DrawStringToHandle(300, 380, "H", Black, kazufont[2]);
			DrawStringToHandle(400, 380, "J", Black, kazufont[2]);
			DrawStringToHandle(500, 380, "K", Black, kazufont[2]);
		}
		if (Kazu_mode == 3) {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 4; j++) {
					if (Kazu_Koma[j] >= 1000) DrawFormatStringToHandle(110 + (j * 110), 280+(i*100), Blue, kazufont[1], "%d", Kazu_Koma[j+(4*i)]);
					else if (Kazu_Koma[j] >= 100) DrawFormatStringToHandle(120 + (j * 110), 280+(i*100), Blue, kazufont[1], "%d", Kazu_Koma[j+(4*i)]);
					else if (Kazu_Koma[j] >= 10) DrawFormatStringToHandle(130 + (j * 110), 280+(i*100), Blue, kazufont[1], "%d", Kazu_Koma[j+(4*i)]);
					else DrawFormatStringToHandle(140 + (j * 110), 280+(i*100), Blue, kazufont[1], "%d", Kazu_Koma[j+(4*i)]);
				}
			}
			DrawStringToHandle(140, 330, "R", Black, kazufont[2]);
			DrawStringToHandle(250, 330, "T", Black, kazufont[2]);
			DrawStringToHandle(360, 330, "Y", Black, kazufont[2]);
			DrawStringToHandle(470, 330, "U", Black, kazufont[2]);
			DrawStringToHandle(140, 430, "F", Black, kazufont[2]);
			DrawStringToHandle(250, 430, "G", Black, kazufont[2]);
			DrawStringToHandle(360, 430, "H", Black, kazufont[2]);
			DrawStringToHandle(470, 430, "J", Black, kazufont[2]);
		}

//ーーーーーーーーーーーーーーーーーーーーー　カウントダウン　－－－－－－－－－－－－－－－－－－－－－－

		DrawFormatStringToHandle(500, 50, Black, kazufont[1], "%d%d：%d%d", minute/10,minute%10,second/10,second%10);
		if (kazu_count % 50 == 0 && FinishFlag==0 && time_b_flag==0) {
			if (second == 0) {
				if (minute != 0) {
					minute--;
					second = 60;
				}
			}
			second--;
			if (time_b_flag==0) time_bornas -= 10;
		}
		if (minute == 0 && second == 0) FinishFlag = 1;
		if (second >= 60) {
			second -= 60; minute++;
		}


//ーーーーーーーーーーーーーーーーーーーーー　テスト　－－－－－－－－－－－－－－－－－－－－－－－－－－－－

		/*
		if (CheckHitKey(KEY_INPUT_1) == 1 && key_flag==0) {
			key_flag = 1;
			for (int i = 0; i < 5; i++) {
				Kazu_Koma[i] = 0;
			}
			Kazu_OneTime = 0; dainyu = 1;
			kazu_loop_break = 0; kaisuu = 0;
			Kazu_Target++;
		}
		//else if(CheckHitKey(KEY_INPUT_1)==0) key_flag = 0;*/

		DrawFormatStringToHandle(50, 50, Green, kazufont[1], "%ld", kazu_point);

//ーーーーーーーーーーーーーーーーーーーーー　キーチェック　－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－

		if (FinishFlag == 0) {
			if (CheckHitKey(KEY_INPUT_F) == 1 && key_flag == 0) {
				key_flag = 1; button_flag = 1;
				if (Kazu_mode == 1 || Kazu_mode == 2) {
					if (check[0] == 0) {
						check[0] = 1; kasan++;
						sum += Kazu_Koma[0];
					}
					else {
						check[0] = 0; sum -= Kazu_Koma[0]; renzoku = 0; kasan--;
						if (time_b_flag == 0) time_bornas -= 10;
					}
				}
				else if (Kazu_mode == 3) {
					if (check[4] == 0) {
						check[4] = 1; kasan++;
						sum += Kazu_Koma[4];
					}
					else {
						check[4] = 0; sum -= Kazu_Koma[4]; renzoku = 0; kasan--;
						if (time_b_flag == 0) time_bornas -= 10;
					}
				}
			}
			else if (CheckHitKey(KEY_INPUT_G) == 1 && key_flag == 0) {
				key_flag = 1; button_flag = 1;
				if (Kazu_mode == 1 || Kazu_mode == 2) {
					if (check[1] == 0) {
						check[1] = 1; kasan++;
						sum += Kazu_Koma[1];
					}
					else {
						check[1] = 0; sum -= Kazu_Koma[1]; renzoku = 0; kasan--;
						if (time_b_flag == 0) time_bornas -= 10;
					}
				}
				if (Kazu_mode == 3) {
					if (check[5] == 0) {
						check[5] = 1; kasan++;
						sum += Kazu_Koma[5];
					}
					else {
						check[5] = 0; sum -= Kazu_Koma[5]; renzoku = 0; kasan--;
						if (time_b_flag == 0) time_bornas -= 10;
					}
				}
			}
			else if (CheckHitKey(KEY_INPUT_H) == 1 && key_flag == 0) {
				key_flag = 1; button_flag = 1;
				if (Kazu_mode == 1 || Kazu_mode == 2) {
					if (check[2] == 0) {
						check[2] = 1; kasan++;
						sum += Kazu_Koma[2];
					}
					else {
						check[2] = 0; sum -= Kazu_Koma[2]; renzoku = 0; kasan--;
						if (time_b_flag == 0) time_bornas -= 10;
					}
				}
				if (Kazu_mode == 3) {
					if (check[6] == 0) {
						check[6] = 1; kasan++;
						sum += Kazu_Koma[6];
					}
					else {
						check[6] = 0; sum -= Kazu_Koma[6]; renzoku = 0; kasan--;
						if (time_b_flag == 0) time_bornas -= 10;
					}
				}
			}
			else if (CheckHitKey(KEY_INPUT_J) == 1 && key_flag == 0) {
				key_flag = 1; button_flag = 1;
				if (Kazu_mode == 1 || Kazu_mode == 2) {
					if (check[3] == 0) {
						check[3] = 1; kasan++;
						sum += Kazu_Koma[3];
					}
					else {
						check[3] = 0; sum -= Kazu_Koma[3]; renzoku = 0; kasan--;
						if (time_b_flag == 0) time_bornas -= 10;
					}
				}
				if (Kazu_mode == 3) {
					if (check[7] == 0) {
						check[7] = 1; kasan++;
						sum += Kazu_Koma[7];
					}
					else {
						check[7] = 0; sum -= Kazu_Koma[7]; renzoku = 0; kasan--;
						if (time_b_flag == 0) time_bornas -= 10;
					}
				}
			}
			else if (CheckHitKey(KEY_INPUT_K) == 1 && key_flag == 0) {
				if (Kazu_mode == 2) {
					key_flag = 1; button_flag = 1;
					if (check[4] == 0) {
						check[4] = 1; kasan++;
						sum += Kazu_Koma[4];
					}
					else {
						check[4] = 0; sum -= Kazu_Koma[4]; renzoku = 0; kasan--;
						if (time_b_flag == 0) time_bornas -= 10;
					}
				}
			}
			if (Kazu_mode == 3) {
				if (CheckHitKey(KEY_INPUT_R) == 1 && key_flag == 0) {
					key_flag = 1; button_flag = 1;
					if (check[0] == 0) {
						check[0] = 1; kasan++;
						sum += Kazu_Koma[0];
					}
					else {
						check[0] = 0; sum -= Kazu_Koma[0]; renzoku = 0; kasan--;
						if (time_b_flag == 0) time_bornas -= 10;
					}
				}
				if (CheckHitKey(KEY_INPUT_T) == 1 && key_flag == 0) {
					key_flag = 1; button_flag = 1;
					if (check[1] == 0) {
						check[1] = 1; kasan++;
						sum += Kazu_Koma[1];
					}
					else {
						check[1] = 0; sum -= Kazu_Koma[1]; renzoku = 0; kasan--;
						if (time_b_flag == 0) time_bornas -= 10;
					}
				}
				if (CheckHitKey(KEY_INPUT_Y) == 1 && key_flag == 0) {
					key_flag = 1; button_flag = 1;
					if (check[2] == 0) {
						check[2] = 1; kasan++;
						sum += Kazu_Koma[2];
					}
					else {
						check[2] = 0; sum -= Kazu_Koma[2]; renzoku = 0; kasan--;
						if (time_b_flag == 0) time_bornas -= 10;
					}
				}
				if (CheckHitKey(KEY_INPUT_U) == 1 && key_flag == 0) {
					key_flag = 1; button_flag = 1;
					if (check[3] == 0) {
						check[3] = 1; kasan++;
						sum += Kazu_Koma[3];
					}
					else {
						check[3] = 0; sum -= Kazu_Koma[3]; renzoku = 0; kasan--;
						if (time_b_flag == 0) time_bornas -= 10;
					}
				}
			}
			if (Kazu_mode == 1) {
				if (CheckHitKey(KEY_INPUT_F) == 0 && CheckHitKey(KEY_INPUT_G) == 0 && CheckHitKey(KEY_INPUT_H) == 0
					&& CheckHitKey(KEY_INPUT_J) == 0)
					key_flag = 0;
			}
			else if (Kazu_mode == 2) {
				if (CheckHitKey(KEY_INPUT_F) == 0 && CheckHitKey(KEY_INPUT_G) == 0 && CheckHitKey(KEY_INPUT_H) == 0
					&& CheckHitKey(KEY_INPUT_J) == 0 && CheckHitKey(KEY_INPUT_K) == 0)
					key_flag = 0;
			}
			else if (Kazu_mode == 3) {
				if (CheckHitKey(KEY_INPUT_F) == 0 && CheckHitKey(KEY_INPUT_G) == 0 && CheckHitKey(KEY_INPUT_H) == 0
					&& CheckHitKey(KEY_INPUT_J) == 0 && CheckHitKey(KEY_INPUT_R) == 0 && CheckHitKey(KEY_INPUT_T) == 0
					&& CheckHitKey(KEY_INPUT_Y) == 0 && CheckHitKey(KEY_INPUT_U) == 0)
					key_flag = 0;
			}
		}

//ーーーーーーーーーーーーーーーーーーーーーー　計算　－－－－－－－－－－－－－－－－－－－－－－－－－－

		static int temp = 0;
		static int tempP = 0;

		if (button_flag == 1) {
			if (Kazu_Target == sum) {
				for (int i = 0; i < for_loop; i++) {
					Kazu_Koma[i] = 0; check[i] = 0;
				}
				Kazu_OneTime = 0; dainyu = 1;
				kazu_loop_break = 0; kaisuu = 0;

				if (Kazu_Target % 10 == 0 && Kazu_Target!=10) bairitu += 0.1;

				Kazu_Target++; bornas_flag = 0;

				switch (kasan) {
				case 2:
					if (time_b_flag == 0) {
						tempP = (100 + (int)(100 * bairitu));
						kazu_point += tempP;
						kazu_point += (int)(tempP*renzoku);
						time_bornas += 30;
					}
					else second += 10;
					break;
				case 3:
					if (time_b_flag == 0) {
						tempP = (800 + (int)(800 * bairitu));
						kazu_point += tempP;
						kazu_point += (int)(tempP*renzoku);
						time_bornas += 45;
					}
					else second += 20;
					break;
				case 4:
					if (time_b_flag == 0) {
						tempP = (2000 + (int)(2000 * bairitu));
						kazu_point += tempP;
						kazu_point += (int)(tempP*renzoku);
						time_bornas += 60;
					}
					else second += 30;
					break;
				case 5:
					if (time_b_flag == 0) {
						tempP = (5000 + (int)(5000 * bairitu));
						kazu_point += tempP;
						kazu_point += (int)(tempP*renzoku);
						time_bornas += 120;
					}
					else second += 40;
				case 6:
					if (time_b_flag == 0) {
						tempP = (20000 + (int)(20000 * bairitu));
						kazu_point += tempP;
						kazu_point += (int)(tempP*renzoku);
						time_bornas += 180;
					}
					else second += 60;
				case 7:
					if (time_b_flag == 0) {
						tempP = (50000 + (int)(50000 * bairitu));
						kazu_point += tempP;
						kazu_point += (int)(tempP*renzoku);
						time_bornas += 260;
					}
					else second += 90;
				}
				if (kasan >= 3) {
					bornas_flag = 1; temp = kasan; count_bornas = 0;
				}
				kasan = 0; sum = 0; renzoku+=0.01;

			}
			else if (Kazu_Target < sum && time_b_flag==0) {
				time_bornas -= 20;
			}
			button_flag = 0;
		}

		if (bornas_flag == 1) {
			if (count_bornas==0) PlaySoundMem(SE_Name[1], DX_PLAYTYPE_BACK);
			count_bornas++;
			if (count_bornas < 60) {
				DrawFormatStringToHandle(150, 420, Red, kazufont[1], "%dポイントボーナス！", temp);
			}
		}


//ーーーーーーーーーーーーーーーーーーーーーー　フィニッシュ　－－－－－－－－－－－－－－－－－－－－－－－－－－－

		if (FinishFlag == 1) {

			if (finish_count == 0) {
				if (CheckSoundMem(SE_Name[0]) == 0) PlaySoundMem(SE_Name[0], DX_PLAYTYPE_BACK);
			}
			finish_count++;
			DrawRotaGraph(320, 200, 1.3, 0.0, Image_Kazu[3], TRUE);


			if (finish_count == 180) {
				if (Kazu_mode == 1) {
					Kazu_save = fopen("Save/kazuitti_S.txt", "a+");
					if (Kazu_save == NULL) {
						EndFlag = 1;
					}
				}
				else if (Kazu_mode == 2) {
					Kazu_save = fopen("Save/kazuitti.txt", "a+");
					if (Kazu_save == NULL) {
						EndFlag = 1;
					}
				}
				else if (Kazu_mode == 3) {
					Kazu_save = fopen("Save/kazuitti_L.txt", "a+");
					if (Kazu_save == NULL) {
						EndFlag = 1;
					}
				}
				while (fgets(String, sizeof(String), Kazu_save) != NULL) {
					number = atoi(String);
					save_con.push_back(number);
				}
				fprintf(Kazu_save, "%d\n", kazu_point);
				//number = atoi(fgets(String, sizeof(String), Kazu_save));
				save_con.push_back(kazu_point);
				fclose(Kazu_save);
				std::sort(save_con.begin(), save_con.end(), std::greater<int>());
			}
			if (finish_count > 180) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
				DrawBox(50, 50, 600, 350, Black, TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

				static int ch = 0;
				/*for (int j = 0; j < 5; j++) {
					DrawFormatStringToHandle(100, 100+(j*80), White, kazufont[1], "%d点", score[j]);
				}*/
				for (int unsigned ran = 0; ran <save_con.size(); ran++) {
					static int onetime=0;
					//EndFlag = 1;
					//ch++;
					if (save_con[ran] == kazu_point && onetime==0) {
						DrawFormatStringToHandle(80, 60 + (ran * 60), Red, kazufont[1], "%d：%d点", ran + 1, save_con[ran]);
						onetime = 1;
					}
					else DrawFormatStringToHandle(80, 60+(ran*60), White, kazufont[1], "%d：%d点", ran+1,save_con[ran]);
					if (ran == 4) {
						onetime = 0; break;
					}
					//i++;
				}
				//if (ch == 0) EndFlag = 1;

				DrawFormatStringToHandle(200, 420, Red, kazufont[2], "あなたの得点\n%d点！", kazu_point);
			}


			if (finish_count % 720 == 0) {
				for (int i = 0; i < for_loop; i++) {
					Kazu_Koma[i] = 0; check[i] = 0;
				}
				for (auto j = 0; save_con.size() > 0; j++) {
					save_con.erase(save_con.begin());
				}

				if (TimeB_Sougou >= 5) {
					std::string Temp_Kousin;
					StarFlag[0] = 1;

					Star_kousin = fopen("Save/Star.txt", "w");
					if (Star_kousin == NULL) {
						EndFlag = 1;
					}
					for (int i = 0; i < 5; i++) {
						Temp_Kousin += (char)(StarFlag[i]+'0');
					}
					fprintf(Star_kousin,"%s",Temp_Kousin.c_str());
					fclose(Star_kousin);
				}
				if (Kazu_mode == 3 || Kazu_mode==2) {
					if (Kazu_Target >= 100) {
						std::string Temp_Kousin2;
						StarFlag[1] = 1;
						Star_kousin = fopen("Save/Star.txt", "w");
						if (Star_kousin == NULL) {
							EndFlag = 1;
						}
						for (int i = 0; i < 5; i++) {
							Temp_Kousin2 += (char)(StarFlag[i] + '0');
						}
						fprintf(Star_kousin, "%s", Temp_Kousin2.c_str());
						fclose(Star_kousin);
					}
				}

				large_r = 0.0;pai = 0.0, large_go = 3.4;
				Kazu_OneTime = 0; dainyu = 1; youso = 0;
				kazu_loop_break = 0; kaisuu = 0; TimeB_Sougou = 0;
				Kazu_Target++; button_flag = 0; Trans[2] = 0;
				kasan = 0; sum = 0; Kazu_Target = 10; FinishFlag = 0; finish_count = 0;
				daiiti = 0; minute = 0; second = 10; kazu_count = 0; count[1] = 0;
				kazu_point = 0; bairitu = 0.0; renzoku = 0;
				time_bornas = 0; time_b_temp = 0; time_b_count = 0; time_x = 1000;
				scene = 0;
				if (CheckSoundMem(BGM_Name[1]) == 1) StopSoundMem(BGM_Name[1]);
				if (CheckSoundMem(BGM_Name[2]) == 1) StopSoundMem(BGM_Name[2]);
				if (CheckSoundMem(BGM_Name[3]) == 1) StopSoundMem(BGM_Name[3]);
				if (CheckSoundMem(SE_Name[0]) == 1) StopSoundMem(SE_Name[0]);

			}
		}




	}//count[1]>=240終わり

}//Kazuitti終わり


//ーーーーーーーーーーーーーーーーーーーーーー　リードプラクティス　－－－－－－－－－－－－－－－－－－－－－－－


void ReadDan_1() {

	static int RD1_OneTime = 0;

	static FILE *RD1_data;
	static char buf1[256];
	static char buf2;
	//static const char *buf_hen;

	//static std::string str1;
	//static std::vector<int> data_kazu;

	static std::vector<std::string> str_rd1 = {};
	static std::vector<std::string> yomi_rd1 = {};
	static int ystr = 0, yomiY = 0, str_switch = 0, buf_con = 0;
	static int rand = 0;

	static char St_RD1[256];
	static int Input = 0, Deput = 0;
	static int enter_flag = 0, entercount = 0, setAnswer = 0, hit_flag = 0, hit_con = 0, gard = 0;
	static int InpX = 100, InpY = 400;

	static int enemy_hp = 5,clear_flag=0,clear_ones=0;
	static int down = 0, gameover = 0, ans_con = 0, stop_flag = 0;

	static int over_con = 0, zanki = 0,change_sw=1;

//ーーーーーーーーーーーーーーーーーーーーーー　初期設定　－－－－－－－－－－－－－－－－－－－－－－－

	if (CheckSoundMem(BGM_Name[0]) == 1) StopSoundMem(BGM_Name[0]);
	else if (CheckSoundMem(BGM_Name[4]) == 1) StopSoundMem(BGM_Name[4]);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[3]);
	DrawRotaGraph(330, 240, 0.8, 0.0, Image_Dan1[0], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	if (Trans[3] < 255) Trans[3] += 5;

//ーーーーーーーーーーーーーーーーーーーーー　ファイル読み込み　－－－－－－－－－－－－－－－－－－－－－

	if (count[2] == 1) {
		zanki = 3;
		RD1_data = fopen("Data/RD_1.txt", "r");
		if (RD1_data == NULL) {
			EndFlag = 1;
		}

		/*while (fgets(buf1, sizeof(buf1), RD1_data) != NULL) {
			//number = atoi(String);
			//buf_hen = buf1;
			str_rd1[ystr] = buf1;
			ystr++;
		}*/
		while ((buf2 = fgetc(RD1_data)) != EOF) {
			str_rd1.resize(ystr + 1); yomi_rd1.resize(yomiY + 1);
			if (buf2 == '\n') {
				ystr++; yomiY++; str_switch = 0; buf_con = -1;
			}
			else if (buf2 == ':') {
				str_switch = 1; buf_con = -1;
			}
			else if (str_switch==0) {
				if(buf_con==0) str_rd1[ystr] = buf2;
				else str_rd1[ystr].push_back(buf2);
				//str_rd1[ystr] += buf2;
			}
			else if (str_switch == 1) {
				if(buf_con==0) yomi_rd1[yomiY]=buf2;
				else yomi_rd1[yomiY].push_back(buf2);
			}
			buf_con++;

		}
		//fprintf(Kazu_save, "%d\n", kazu_point);
		//number = atoi(fgets(String, sizeof(String), Kazu_save));
		//save_con.push_back(kazu_point);
		//std::sort(save_con.begin(), save_con.end(), std::greater<int>());

		fclose(RD1_data);
	}
//ーーーーーーーーーーーーーーーーーーーーー　AAAA　－－－－－－－－－－－－－－－－－－－－－－

	else if (count[2] >= 90) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[4]);
		if (hit_flag == 0) {
			DrawRotaGraph(330, 240, 0.8, 0.0, Image_Dan1[1], TRUE);
		}
		else {
			if(count[2]%5==0) DrawRotaGraph(330, 240, 0.8, 0.0, Image_Dan1[1], TRUE);
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (Trans[4] < 255 && enemy_hp!=0) Trans[4] += 5;
	}
	if (count[2] == 180) {
		//if (CheckSoundMem(SE_Name[2]) == 0) PlaySoundMem(SE_Name[2],DX_PLAYTYPE_BACK);
		Input = MakeKeyInput(128,FALSE,FALSE,FALSE);
		Deput = MakeKeyInput(128, FALSE, FALSE, FALSE);
		SetActiveKeyInput(Input);
		//SetKeyInputStringColor(White, 0, White,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
	}
	else if (count[2]>180) {
		if (stop_flag == 0) {
			ans_con++;
			if (CheckSoundMem(BGM_RD[0]) == 0) PlaySoundMem(BGM_RD[0],DX_PLAYTYPE_LOOP);
			if (RD1_OneTime == 0) {
				rand = (int)GetRand(ystr - 1);
				RD1_OneTime = 1; down = 25; gard = 0;
				if (CheckSoundMem(SE_Name[2]) == 0) PlaySoundMem(SE_Name[2], DX_PLAYTYPE_BACK);
			}
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
			for (unsigned int j = 0; j < str_rd1[rand].size() / 2; j++) {
				DrawBox(300 + (j * 40), 320, 340 + (j * 40), 360, White, TRUE);
			}
			//for (unsigned int j = 0; j < yomi_rd1[rand].size() / 2; j++) {
			//	DrawBox(100 + (j * 40), 300, 140 + (j * 40), 340, White, TRUE);
			//}
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawFormatStringToHandle(300, 320, Black, kazufont[1], "%s", str_rd1[rand].c_str());
			//DrawFormatStringToHandle(100, 300, Black, kazufont[1], "%s", yomi_rd1[rand].c_str());

			if(key_flag==0)	DrawKeyInputString(100, 400, Input);

			if (CheckKeyInput(Input) == 1 && key_flag==0) {
				enter_flag = 1; key_flag = 1;
			}
			if (CheckHitKey(KEY_INPUT_RETURN) == 0) {
				key_flag = 0;
			}
			if (enter_flag == 1) {
				entercount++;
				if (entercount == 1) {
					GetKeyInputString(St_RD1, Input);
					if (CheckSoundMem(SE_Name[3]) == 0) PlaySoundMem(SE_Name[3], DX_PLAYTYPE_BACK);
					if (strcmp(yomi_rd1[rand].c_str(), St_RD1) == 0) {
						setAnswer = 1;
					}
					else {
						setAnswer = 0;
					}
				}
				if (InpX < 300 && entercount < 30) {
					InpX += 5;
				}
				if (InpY > 250 && entercount < 30) {
					InpY -= 5;
				}
				DrawFormatStringToHandle(InpX, InpY, Red, kazufont[1], "%s", St_RD1);
				if (entercount == 30) {
					if (setAnswer == 1) {
						//if (CheckSoundMem(SE_Name[4]) == 0) PlaySoundMem(SE_Name[4], DX_PLAYTYPE_BACK);
						PlaySoundMem(SE_Name[4], DX_PLAYTYPE_BACK);
						hit_flag = 1; gard = 1;
					}
					else {
						//if (CheckSoundMem(SE_Name[5]) == 0) PlaySoundMem(SE_Name[5], DX_PLAYTYPE_BACK);
						PlaySoundMem(SE_Name[5], DX_PLAYTYPE_BACK);
					}
					SetActiveKeyInput(Input);
					InpX = 100; InpY = 400;
					SetKeyInputString("", Input);
					enter_flag = 0; entercount = 0;
				}
			}
//ーーーーーーーーーーーーーーーーーーーーー　カウントダウン　－－－－－－－－－－－－－－－－－－－－－－

			DrawFormatStringToHandle(300, 100, Red, kazufont[1], "%d", down);
			if (ans_con % 55 == 0 && enter_flag==0 && down>0 && stop_flag==0) {
				down--;
			}
			if (down == 0) {
				if(enter_flag!=1 && gard==0) gameover = 1;
			}
//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー

			if (hit_flag == 1) {
				hit_con++;
				if (hit_con == 40) {
					RD1_OneTime = 0;
					hit_flag = 0; hit_con = 0;
					enemy_hp--;
					//if(enemy_hp!=0) PlaySoundMem(SE_Name[7], DX_PLAYTYPE_BACK);
				}
			}
		}

		if (enemy_hp == 0) {
			clear_flag = 1;
			if (clear_ones == 0) {
				if (CheckSoundMem(SE_Name[6]) == 0) PlaySoundMem(SE_Name[6], DX_PLAYTYPE_BACK);
				clear_ones = 1;
			}
			if (Trans[4] > 0) Trans[4] -= 5;
		}
		if (clear_flag == 1) {
			static int clear_con=0;
			stop_flag = 1;
			if (clear_con >= 120) {
				DrawRotaGraph(320, 240, 1.0, 0.0, Image_Dan1[2], TRUE);
			}
			if (clear_con == 420) {
				clear_con = 0; clear_flag = 0; clear_ones = 0;
				Trans[4] = 0; count[2] = 0; RD1_OneTime = 0; Trans[3] = 0;
				if (CheckSoundMem(BGM_RD[0]) == 1) StopSoundMem(BGM_RD[0]);
				for (unsigned int i = 0; i < str_rd1.size();) {
					str_rd1.pop_back();
				}
				for (unsigned int i = 0; i < yomi_rd1.size();) {
					yomi_rd1.pop_back();
				}
				ystr = 0; yomiY = 0; str_switch = 0; buf_con = 0;rand = 0;
				//static char St_RD1[256];
				Input = 0; Deput = 0; enter_flag = 0; entercount = 0; setAnswer = 0; hit_flag = 0; hit_con = 0;
				InpX = 100; InpY = 400; stop_flag = 0; change_sw = 1;
				enemy_hp = 10; scene = 0; randbgm_Title = (int)GetRand(1);
			}
			clear_con++;
		}
		if (gameover == 1) {
			over_con++; stop_flag = 1;
			SetActiveKeyInput(Deput);
			if (over_con == 1) {
				zanki--;
				PlaySoundMem(SE_Name[8], DX_PLAYTYPE_BACK);
			}
			if (zanki <= 0) {
				if (over_con > 180) {
					DrawRotaGraph(320, 240, 1.0, 0.0, Image_Dan1[3], TRUE);
					for (unsigned int j = 0; j < (yomi_rd1[rand].size() / 2)+3; j++) {
						DrawBox(200 + (j * 40), 300, 240 + (j * 40), 340, White, TRUE);
					}
					DrawFormatStringToHandle(200, 300, Black, kazufont[1], "答え：%s", yomi_rd1[rand].c_str());
				}
				if (over_con == 480) {
					over_con = 0; gameover = 0; zanki = 0;
					Trans[4] = 0; count[2] = 0; RD1_OneTime = 0; Trans[3] = 0;
					if (CheckSoundMem(BGM_RD[0]) == 1) StopSoundMem(BGM_RD[0]);
					for (unsigned int i = 0; i < str_rd1.size();) {
						str_rd1.pop_back();
					}
					for (unsigned int i = 0; i < yomi_rd1.size();) {
						yomi_rd1.pop_back();
					}
					ystr = 0; yomiY = 0; str_switch = 0; buf_con = 0; rand = 0;
					//static char St_RD1[256];
					Input = 0; Deput = 0; enter_flag = 0; entercount = 0; setAnswer = 0; hit_flag = 0; hit_con = 0;
					InpX = 100; InpY = 400; stop_flag = 0; change_sw = 1;
					enemy_hp = 10; scene = 0; randbgm_Title = (int)GetRand(1);
				}
			}
			else {
				if (over_con > 120) {
					if(change_sw==1) DrawRotaGraph(320, 240, 0.8, 0.0, Image_Dan1[4], TRUE);
					if (over_con % 30 == 0) change_sw *= -1;
					DrawFormatStringToHandle(180, 350, Green, kazufont[1], "Enterで再挑戦");

					if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
						over_con = 0; gameover = 0; stop_flag = 0; down = 25; key_flag = 1;
						SetActiveKeyInput(Input);
					}
				}
			}
		}

	}

}


//ーーーーーーーーーーーーーーーーーーーーーーー　グレードクラス　－－－－－－－－－－－－－－－－－－－－－－－


void GrdClass() {

	static int zanki = 0, GRD_OneTime=0;

	static std::vector<std::string> str_grd = {};
	static std::vector<std::string> yomi_grd = {};
	static int ystr = 0, yomiY = 0, str_switch = 0, buf_con = 0;
	static int rand = 0;

	FILE *GRD_data;
	static char buf1;

	static char St_RD1[256];
	static int Input = 0, Deput = 0;
	static int enter_flag = 0, entercount = 0, setAnswer = 0, hit_flag = 0, hit_con = 0, gard = 0;
	static int InpX = 100, InpY = 400;

	static int enemy_hp = 10, clear_flag = 0, clear_ones = 0;
	static int down = 0, gameover = 0, ans_con = 0, stop_flag = 0;

	static int over_con = 0,change_sw = 1;

//ーーーーーーーーーーーーーーーーーーーーーー　初期設定　－－－－－－－－－－－－－－－－－－－－－－－

	if (CheckSoundMem(BGM_Name[0]) == 1) StopSoundMem(BGM_Name[0]);
	else if (CheckSoundMem(BGM_Name[4]) == 1) StopSoundMem(BGM_Name[4]);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[3]);
	DrawRotaGraph(330, 240, 0.8, 0.0, Image_GRD[0], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	if (Trans[3] < 255) Trans[3] += 5;

//ーーーーーーーーーーーーーーーーーーーーー　ファイル読み込み　－－－－－－－－－－－－－－－－－－－－－

	if (count[2] == 1) {
		zanki = 3;
		if (select_class == 1) {
			GRD_data = fopen("Data/GRD_1.txt", "r");
			if (GRD_data == NULL) {
				EndFlag = 1;
			}
		}
		else if (select_class == 2) {
			GRD_data = fopen("Data/GRD_2.txt", "r");
			if (GRD_data == NULL) {
				EndFlag = 1;
			}
		}
		else if (select_class == 3) {
			GRD_data = fopen("Data/GRD_3.txt", "r");
			if (GRD_data == NULL) {
				EndFlag = 1;
			}
		}
		else if (select_class == 4) {
			GRD_data = fopen("Data/GRD_4.txt", "r");
			if (GRD_data == NULL) {
				EndFlag = 1;
			}
		}
		else if (select_class == 11) {
			GRD_data = fopen("Data/GRD_5.txt", "r");
			if (GRD_data == NULL) {
				EndFlag = 1;
			}
		}
		else if (select_class == 12) {
			GRD_data = fopen("Data/GRD_6.txt", "r");
			if (GRD_data == NULL) {
				EndFlag = 1;
			}
		}
		else if (select_class == 13) {
			GRD_data = fopen("Data/GRD_7-.txt", "r");
			if (GRD_data == NULL) {
				EndFlag = 1;
			}
		}

		while ((buf1 = fgetc(GRD_data)) != EOF) {
			str_grd.resize(ystr + 1); yomi_grd.resize(yomiY + 1);
			if (buf1 == '\n') {
				ystr++; yomiY++; str_switch = 0; buf_con = -1;
			}
			else if (buf1 == ':') {
				str_switch = 1; buf_con = -1;
			}
			else if (str_switch == 0) {
				if (buf_con == 0) str_grd[ystr] = buf1;
				else str_grd[ystr].push_back(buf1);
				//str_rd1[ystr] += buf2;
			}
			else if (str_switch == 1) {
				if (buf_con == 0) yomi_grd[yomiY] = buf1;
				else yomi_grd[yomiY].push_back(buf1);
			}
			buf_con++;

		}

		fclose(GRD_data);
	}
//ーーーーーーーーーーーーーーーーーーーーー　戦闘開始まで　－－－－－－－－－－－－－－－－－－－－－
	else if (count[2] >= 90) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[4]);
		if (hit_flag == 0) {
			DrawRotaGraph(330, 240, 0.8, 0.0, Image_GRD[1], TRUE);
		}
		else {
			if (count[2] % 5 == 0) DrawRotaGraph(330, 240, 0.8, 0.0, Image_GRD[1], TRUE);
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (Trans[4] < 255 && enemy_hp != 0) Trans[4] += 5;
		if (count[2] == 180) {
			//if (CheckSoundMem(SE_Name[2]) == 0) PlaySoundMem(SE_Name[2],DX_PLAYTYPE_BACK);
			Input = MakeKeyInput(128, FALSE, FALSE, FALSE);
			Deput = MakeKeyInput(128, FALSE, FALSE, FALSE);
			SetActiveKeyInput(Input);
			//SetKeyInputStringColor(White, 0, White,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		}
//ーーーーーーーーーーーーーーーーーーーーー　戦闘開始　－－－－－－－－－－－－－－－－－－－－－－
		else if (count[2] > 180) {
			if (stop_flag == 0) {
				if (select_class == 12 || select_class == 13) {
					if (CheckSoundMem(BGM_RD[2]) == 0) PlaySoundMem(BGM_RD[2], DX_PLAYTYPE_LOOP);
				}
				else {
					if (CheckSoundMem(BGM_RD[1]) == 0) PlaySoundMem(BGM_RD[1], DX_PLAYTYPE_LOOP);
				}
				ans_con++;
				if (GRD_OneTime == 0) {
					rand = (int)GetRand(ystr - 1);
					GRD_OneTime = 1; down = 20; gard = 0;
					if (CheckSoundMem(SE_Name[2]) == 0) PlaySoundMem(SE_Name[2], DX_PLAYTYPE_BACK);
				}
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
				for (unsigned int j = 0; j < str_grd[rand].size() / 2; j++) {
					DrawBox(300 + (j * 40), 320, 340 + (j * 40), 360, White, TRUE);
				}
				//for (unsigned int j = 0; j < yomi_rd1[rand].size() / 2; j++) {
				//	DrawBox(100 + (j * 40), 300, 140 + (j * 40), 340, White, TRUE);
				//}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				DrawFormatStringToHandle(300, 320, Black, kazufont[1], "%s", str_grd[rand].c_str());
				//DrawFormatStringToHandle(100, 300, Black, kazufont[1], "%s", yomi_rd1[rand].c_str());

				if (key_flag == 0)	DrawKeyInputString(100, 400, Input);

				if (CheckKeyInput(Input) == 1 && key_flag == 0) {
					enter_flag = 1; key_flag = 1;
				}
				if (CheckHitKey(KEY_INPUT_RETURN) == 0) {
					key_flag = 0;
				}
				if (enter_flag == 1) {
					entercount++;
					if (entercount == 1) {
						GetKeyInputString(St_RD1, Input);
						if (CheckSoundMem(SE_Name[3]) == 0) PlaySoundMem(SE_Name[3], DX_PLAYTYPE_BACK);
						if (strcmp(yomi_grd[rand].c_str(), St_RD1) == 0) {
							setAnswer = 1;
						}
						else {
							setAnswer = 0;
						}
					}
					if (InpX < 300 && entercount < 30) {
						InpX += 5;
					}
					if (InpY > 250 && entercount < 30) {
						InpY -= 5;
					}
					DrawFormatStringToHandle(InpX, InpY, Red, kazufont[1], "%s", St_RD1);
					if (entercount == 30) {
						if (setAnswer == 1) {
							//if (CheckSoundMem(SE_Name[4]) == 0) PlaySoundMem(SE_Name[4], DX_PLAYTYPE_BACK);
							PlaySoundMem(SE_Name[4], DX_PLAYTYPE_BACK);
							hit_flag = 1; gard = 1;
						}
						else {
							//if (CheckSoundMem(SE_Name[5]) == 0) PlaySoundMem(SE_Name[5], DX_PLAYTYPE_BACK);
							PlaySoundMem(SE_Name[5], DX_PLAYTYPE_BACK);
						}
						SetActiveKeyInput(Input);
						InpX = 100; InpY = 400;
						SetKeyInputString("", Input);
						enter_flag = 0; entercount = 0;
					}
				}
//ーーーーーーーーーーーーーーーーーーーーー　カウントダウン　－－－－－－－－－－－－－－－－－－－－－－

				DrawFormatStringToHandle(300, 100, Red, kazufont[1], "%d", down);
				if (ans_con % 55 == 0 && enter_flag == 0 && down > 0 && stop_flag == 0) {
					down--;
				}
				if (down == 0) {
					if (enter_flag != 1 && gard == 0) gameover = 1;
				}
//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー

				if (hit_flag == 1) {
					hit_con++;
					if (hit_con == 40) {
						GRD_OneTime = 0;
						hit_flag = 0; hit_con = 0;
						enemy_hp--;
						//if(enemy_hp!=0) PlaySoundMem(SE_Name[7], DX_PLAYTYPE_BACK);
					}
				}
			}

			if (enemy_hp == 0) {
				clear_flag = 1;
				if (clear_ones == 0) {
					if (CheckSoundMem(SE_Name[6]) == 0) PlaySoundMem(SE_Name[6], DX_PLAYTYPE_BACK);
					clear_ones = 1;
				}
				if (Trans[4] > 0) Trans[4] -= 5;
			}
			if (clear_flag == 1) {
				static int clear_con = 0;
				stop_flag = 1;
				if (clear_con >= 120) {
					DrawRotaGraph(320, 240, 1.0, 0.0, Image_Dan1[2], TRUE);
				}
				if (clear_con == 420) {
					clear_con = 0; clear_flag = 0; clear_ones = 0;
					Trans[4] = 0; count[2] = 0; GRD_OneTime = 0; Trans[3] = 0;
					if (CheckSoundMem(BGM_RD[1]) == 1) StopSoundMem(BGM_RD[1]);
					if (CheckSoundMem(BGM_RD[2]) == 1) StopSoundMem(BGM_RD[2]);
					for (unsigned int i = 0; i < str_grd.size();) {
						str_grd.pop_back();
					}
					for (unsigned int i = 0; i < yomi_grd.size();) {
						yomi_grd.pop_back();
					}
					ystr = 0; yomiY = 0; str_switch = 0; buf_con = 0; rand = 0;
					//static char St_RD1[256];
					Input = 0; Deput = 0; enter_flag = 0; entercount = 0; setAnswer = 0; hit_flag = 0; hit_con = 0;
					InpX = 100; InpY = 400; stop_flag = 0; change_sw = 1;
					enemy_hp = 10; scene = 0; randbgm_Title = (int)GetRand(1);
				}
				clear_con++;
			}
			if (gameover == 1) {
				over_con++; stop_flag = 1;
				SetActiveKeyInput(Deput);
				if (over_con == 1) {
					zanki--;
					PlaySoundMem(SE_Name[8], DX_PLAYTYPE_BACK);
				}
				if (zanki <= 0) {
					if (over_con > 180) {
						DrawRotaGraph(320, 240, 1.0, 0.0, Image_Dan1[3], TRUE);
						for (unsigned int j = 0; j < (yomi_grd[rand].size() / 2)+3; j++) {
							DrawBox(200 + (j * 40), 300, 240 + (j * 40), 340, White, TRUE);
						}
						DrawFormatStringToHandle(200,300,Black,kazufont[1],"答え：%s",yomi_grd[rand].c_str());
					}
					if (over_con == 480) {
						over_con = 0; gameover = 0; zanki = 0;
						Trans[4] = 0; count[2] = 0; GRD_OneTime = 0; Trans[3] = 0;
						if (CheckSoundMem(BGM_RD[1]) == 1) StopSoundMem(BGM_RD[1]);
						if (CheckSoundMem(BGM_RD[2]) == 1) StopSoundMem(BGM_RD[2]);
						for (unsigned int i = 0; i < str_grd.size();) {
							str_grd.pop_back();
						}
						for (unsigned int i = 0; i < yomi_grd.size();) {
							yomi_grd.pop_back();
						}
						ystr = 0; yomiY = 0; str_switch = 0; buf_con = 0; rand = 0;
						//static char St_RD1[256];
						Input = 0; Deput = 0; enter_flag = 0; entercount = 0; setAnswer = 0; hit_flag = 0; hit_con = 0;
						InpX = 100; InpY = 400; stop_flag = 0; change_sw = 1;
						enemy_hp = 10; scene = 0; randbgm_Title = (int)GetRand(1);
					}
				}
				else {
					if (over_con > 120) {
						if (change_sw == 1) DrawRotaGraph(320, 240, 0.8, 0.0, Image_Dan1[4], TRUE);
						if (over_con % 30 == 0) change_sw *= -1;
						DrawFormatStringToHandle(180, 350, Green, kazufont[1], "Enterで再挑戦");

						if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
							over_con = 0; gameover = 0; stop_flag = 0; down = 20; key_flag = 1;
							SetActiveKeyInput(Input);
						}
					}
				}
			}

		}
	}

//ーーーーーーーーーーーーーーーーーーーーーーー　終わり　－－－－－－－－－－－－－－－－－－－－－－－

}


//ーーーーーーーーーーーーーーーーーーーーーー　台詞（アドベンチャー）　－－－－－－－－－－－－－－－－－－－－－

//TalkADVは削除しました。

//ーーーーーーーーーーーーーーーーーーーーーー　アドベンチャー　－－－－－－－－－－－－－－－－－－－－－

void ADV() {

	static int zanki = 3, start_flag = 0, stage = 1, team = 0,adv_mode=0;
	static int stage_con[6] = {};
	static int ADV_OneTime=0;

	FILE *ADV_data,*Clear_data;
	static char buf1;
	static std::vector<std::string> str_adv = {};
	static std::vector<std::string> yomi_adv = {};
	static int ystr = 0, yomiY = 0, str_switch = 0, buf_con = 0;
	static int rand = 0, daburi_flag = 1;
	static std::vector<int> tyohuku;
	static char kaitou[5][256];

	static int boss_flag = 0, sinkoudo = 1, return_st = 0,bg_change=0;
	static int EneX = 330,EneY = 220;

	static int end_talk = 0;

	static char St_RD1[256];
	static int Input = 0, Deput = 0;
	static int enter_flag = 0, entercount = 0, setAnswer = 0, hit_flag = 0, hit_con = 0, gard = 0;
	static int InpX = 100, InpY = 400;

	static int enemy_hp = 10, clear_flag = 0, clear_ones = 0;
	static int down = 0, gameover = 0, ans_con = 0, stop_flag = 0;

	static int over_con = 0, change_sw = 1;
	static int lastB_con = 0, last_chaku = 0, talk_flag = 0;
	static int Volume = 255, StageTitle = 0, Titlecon = 0, Title_End = 0, kaburi_suu = 0, tuuka = 0;

//ーーーーーーーーーーーーーーーーーーーーーー　初期設定　－－－－－－－－－－－－－－－－－－－－－－－

	

//ーーーーーーーーーーーーーーーーーーーーーー　人数選択　－－－－－－－－－－－－－－－－－－－－－－－

	if (start_flag == 0) {
		DrawRotaGraph(330, 240, 0.8, 0.0, Image_RDSE[3], TRUE);

		if (adv_mode == 0) {
			DrawFormatStringToHandle(50, 100, Green, kazufont[1], "一人で遊ぶ？チームで遊ぶ？");
			DrawFormatStringToHandle(30, 150, White, kazufont[3], "(一人の場合、失敗したら漢字が変わるようになります\nゲームオーバー時に表示される答えは最後の失敗のみ)");

			if (team == 0) {
				DrawFormatStringToHandle(100, 300, Red, kazufont[2], "一人で遊ぶ");
				DrawFormatStringToHandle(340, 300, White, kazufont[2], "チームで遊ぶ");
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
					adv_mode = 1; key_flag = 1;
				}
			}
			else if (team = 1) {
				DrawFormatStringToHandle(100, 300, White, kazufont[2], "一人で遊ぶ");
				DrawFormatStringToHandle(340, 300, Red, kazufont[2], "チームで遊ぶ");
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
					adv_mode = 1; key_flag = 1;
				}
			}

			if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && key_flag == 0) {
				team++; key_flag = 1;
			}
			else if (CheckHitKey(KEY_INPUT_LEFT) == 1 && key_flag == 0) {
				team--; key_flag = 1;
			}
			if (CheckHitKey(KEY_INPUT_RETURN) == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0) {
				key_flag = 0;
			}
			if (team >= 2) team = 1;
			else if (team < 0) team = 0;

		}

		if (adv_mode == 1) {
			if(team==1) DrawFormatStringToHandle(150, 100, White, kazufont[2], "参加人数を選択(最大5人)");
			else if (team == 0) DrawFormatStringToHandle(150, 100, White, kazufont[2], "残機を選択(最大5機)");

			DrawFormatStringToHandle(300, 170, White, kazufont[1], "%d", zanki);

			if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && key_flag == 0) {
				zanki++; key_flag = 1;
			}
			else if (CheckHitKey(KEY_INPUT_LEFT) == 1 && key_flag == 0) {
				zanki--; key_flag = 1;
			}
			else if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
				start_flag = 1; key_flag = 1; adv_mode = 0;
			}
			if (CheckHitKey(KEY_INPUT_RETURN) == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0) {
				key_flag = 0;
			}
			if (zanki < 5) DrawTriangle(330, 180, 330, 200, 350, 190, White, TRUE);
			if (zanki > 1) DrawTriangle(290, 180, 290, 200, 270, 190, White, TRUE);

			if (zanki > 5) zanki = 5;
			else if (zanki <= 0) zanki = 1;
		}
	}
//ーーーーーーーーーーーーーーーーーーーーーー　ADV開始　－－－－－－－－－－－－－－－－－－－－－－－－

	if (start_flag == 1) {
		count[2]++;
		//stage_con[0]++;
//ーーーーーーーーーーーーーーーーーーーーーー　ステージ描写　－－－－－－－－－－－－－－－－－－－－－－
		if (boss_flag == 0 && Trans[4]<250) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[3]);
			if (stage == 1) {
				DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[0], TRUE);
				if (Trans[3] > 250 && Title_End == 0) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, StageTitle);
					DrawStringToHandle(210, 180, "　ステージ１\n人ならざるもの\n　 並木道", Black, kazufont[2]);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (StageTitle < 250 && Titlecon < 240) {
						StageTitle += 10; count[2] = 2;
						if (CheckSoundMem(BGM_ADV[0]) == 0) PlaySoundMem(BGM_ADV[0], DX_PLAYTYPE_LOOP);
					}
					else {
						Titlecon++; count[2] = 2;
						if (Titlecon >= 240) {
							if (StageTitle > 0) {
								StageTitle -= 10;
							}
							else {
								Titlecon = 0; Title_End = 1;
							}
						}
					}
				}
			}
			else if (stage == 2) {
				DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[6], TRUE);
				if (Trans[3] > 250 && Title_End == 0) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, StageTitle);
					DrawStringToHandle(160, 180, "　　 ステージ２\n華より花に呑まれたまう\n　　 　森林湖", Black, kazufont[2]);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (StageTitle < 250 && Titlecon < 240) {
						StageTitle += 10; count[2] = 2;
						if (CheckSoundMem(BGM_ADV[2]) == 0) PlaySoundMem(BGM_ADV[2], DX_PLAYTYPE_LOOP);
					}
					else {
						Titlecon++; count[2] = 2;
						if (Titlecon >= 240) {
							if (StageTitle > 0) {
								StageTitle -= 10;
							}
							else {
								Titlecon = 0; Title_End = 1;
							}
						}
					}
				}
			}
			else if (stage == 3) {
				DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[11], TRUE);
				if (Trans[3] > 250 && Title_End == 0) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, StageTitle);
					DrawStringToHandle(210, 180, " 　ステージ３\n反転したおとぎ話\n　 秘境の湖中", Black, kazufont[2]);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (StageTitle < 250 && Titlecon < 240) {
						StageTitle += 10; count[2] = 2;
						if (CheckSoundMem(BGM_ADV[4]) == 0) PlaySoundMem(BGM_ADV[4], DX_PLAYTYPE_LOOP);
					}
					else {
						Titlecon++; count[2] = 2;
						if (Titlecon >= 240) {
							if (StageTitle > 0) {
								StageTitle -= 10;
							}
							else {
								Titlecon = 0; Title_End = 1;
							}
						}
					}
				}
			}
			else if (stage == 4) {
				if (sinkoudo == 1) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[3]);
					DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[17], TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				}
				else if (sinkoudo == 2) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, BG_Tra[0]);
					DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[18], TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (BG_Tra[0] < 255 && enemy_hp != 0) {
						BG_Tra[0] += 5; count[2] = 30;
					}
				}
				else if (sinkoudo == 3 || sinkoudo==4) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, BG_Tra[1]);
					DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[19], TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (BG_Tra[1] < 255 && enemy_hp != 0) {
						BG_Tra[1] += 5; count[2] = 30;
					}
				}
			}
			else if (stage == 5) {
				if (sinkoudo == 1 || sinkoudo==2) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[3]);
					DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[25], TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				}
				else if (sinkoudo == 3) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, BG_Tra[0]);
					DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[26], TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (BG_Tra[0] < 255 && enemy_hp != 0) {
						BG_Tra[0] += 5; count[2] = 30;
					}
				}
				else if (sinkoudo == 4 || sinkoudo==5) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, BG_Tra[1]);
					DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[27], TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (BG_Tra[1] < 255 && enemy_hp != 0) {
						BG_Tra[1] += 5; count[2] = 30;
					}
				}
				if (Trans[3] > 250 && Title_End == 0) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, StageTitle);
					DrawStringToHandle(240, 190, " ステージ５\n救われし者達\n 　竜宮城", Black, kazufont[2]);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (StageTitle < 250 && Titlecon < 240) {
						StageTitle += 10; count[2] = 2;
						if (CheckSoundMem(BGM_ADV[8]) == 0) PlaySoundMem(BGM_ADV[8], DX_PLAYTYPE_LOOP);
					}
					else {
						Titlecon++; count[2] = 2;
						if (Titlecon >= 240) {
							if (StageTitle > 0) {
								StageTitle -= 10;
							}
							else {
								Titlecon = 0; Title_End = 1;
							}
						}
					}
				}
			}
			else if (stage == 6) {
				DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[34], TRUE);
				if (Trans[3] > 250 && Title_End == 0) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, StageTitle);
					DrawStringToHandle(200, 190, "　　ステージ６\n真実は幸福にあらず\n 竜宮城　玉座の間", White, kazufont[2]);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (StageTitle < 250 && Titlecon < 240) {
						StageTitle += 10; count[2] = 2;
						if (CheckSoundMem(BGM_ADV[10]) == 0) PlaySoundMem(BGM_ADV[10], DX_PLAYTYPE_LOOP);
					}
					else {
						Titlecon++; count[2] = 2;
						if (Titlecon >= 240) {
							if (StageTitle > 0) {
								StageTitle -= 10;
							}
							else {
								Titlecon = 0; Title_End = 1;
							}
						}
					}
				}
			}
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			if (Trans[3] < 255 && boss_flag==0 && bg_change==0) Trans[3] += 5;
			//else if ((boss_flag == 1 || bg_change!=0) && Trans[3]>0) Trans[3] -= 5;
		}
		else if (boss_flag == 1) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[4]);
			if(stage==1) DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[3], TRUE);
			else if (stage == 2) DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[7], TRUE);
			else if (stage == 3) DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[12], TRUE);
			else if(stage==4) DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[20], TRUE);
			else if(stage==5) DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[28], TRUE);
			else if (stage == 6) DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[35], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

			if (Trans[4] < 255) Trans[4] += 5;
		}
		/*
		DrawFormatStringToHandle(10, 20, Red, kazufont[2], "%d", tyohuku.size());
		for (unsigned int i = 0; i < tyohuku.size(); i++) {
			DrawFormatStringToHandle(20+(i*30), 50, Red, kazufont[2], "%d", tyohuku[i]);
		}
		DrawFormatStringToHandle(10, 100, Red, kazufont[2], "RAND:%d", rand);
		DrawFormatStringToHandle(10, 200, Red, kazufont[2], "TUUKA:%d", tuuka);*/
//ーーーーーーーーーーーーーーーーーーーーー　ファイル読み込み　－－－－－－－－－－－－－－－－－－－－－－
		if (count[2] == 1) {
			if (CheckSoundMem(BGM_Name[0]) == 1) StopSoundMem(BGM_Name[0]);
			else if (CheckSoundMem(BGM_Name[4]) == 1) StopSoundMem(BGM_Name[4]);
			if (stage == 1) {
				ADV_data = fopen("Data/ADV_1.txt", "r");
			}
			else if(stage==2){
				ADV_data = fopen("Data/ADV_2.txt", "r");
			}
			else if (stage == 3) {
				ADV_data = fopen("Data/ADV_3.txt", "r");
			}
			else if (stage == 4) {
				ADV_data = fopen("Data/ADV_4.txt", "r");
			}
			else if (stage == 5) {
				ADV_data = fopen("Data/ADV_5.txt", "r");
			}
			else if (stage == 6) {
				ADV_data = fopen("Data/ADV_6.txt", "r");
			}
			if (ADV_data == NULL) {
				EndFlag = 1;
			}

			while ((buf1 = fgetc(ADV_data)) != EOF) {
				str_adv.resize(ystr + 1); yomi_adv.resize(yomiY + 1);
				if (buf1 == '\n') {
					ystr++; yomiY++; str_switch = 0; buf_con = -1;
				}
				else if (buf1 == ':') {
					str_switch = 1; buf_con = -1;
				}
				else if (str_switch == 0) {
					if (buf_con == 0) str_adv[ystr] = buf1;
					else str_adv[ystr].push_back(buf1);
					//str_rd1[ystr] += buf2;
				}
				else if (str_switch == 1) {
					if (buf_con == 0) yomi_adv[yomiY] = buf1;
					else yomi_adv[yomiY].push_back(buf1);
				}
				buf_con++;

			}
			fclose(ADV_data);
		}
		if (last_chaku == 1) {
			lastB_con++; count[2] = 2;
		}
		if (lastB_con >= 60) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, BG_Tra[3]);
			DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[39], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			if (BG_Tra[3] < 255 && lastB_con<180) BG_Tra[3] += 5;
			if (lastB_con >= 180) {
				sinkoudo++; count[2] = 2; boss_flag = 1;
				return_st = 0; clear_ones = 0; stop_flag = 0; bg_change = 0;
				if (BG_Tra[3] > 0) BG_Tra[3]-=5;
				else {
					last_chaku = 0; lastB_con = 0;
				}
			}
		}
//ーーーーーーーーーーーーーーーーーーーーー　敵グラ表示　－－－－－－－－－－－－－－－－－－－－－－－
		else if (count[2] >= 90) {
			if (return_st == 1) {
				if (lastB_con == 0) {
					return_st = 0; clear_ones = 0; stop_flag = 0; bg_change = 0;
				}
			}
			if (stage == 1) {
				if (sinkoudo >= 3) boss_flag = 1;
				if (sinkoudo == 1) {
					if (count[2] == 90) enemy_hp = 1;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[1], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[1], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage-1] < 255 && enemy_hp != 0 && clear_ones==0) Teki[stage-1] += 5;
				}
				else if (sinkoudo == 2) {
					if (count[2] == 90) enemy_hp = 2;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[2], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[2], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (boss_flag == 1) {
					if (count[2] == 90) enemy_hp = 4;
					/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
						end_talk = TalkADV(stage, 1);
						if (end_talk == 0) count[2] = 170;
						else count[2] = 120;
					}*/
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 0.8, 0.0, Image_ADV[4], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.8, 0.0, Image_ADV[4], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
					else if (CheckSoundMem(BGM_ADV[0]) == 1) {
						StopSoundMem(BGM_ADV[0]);
						if (CheckSoundMem(BGM_ADV[1]) == 0) PlaySoundMem(BGM_ADV[1], DX_PLAYTYPE_LOOP);
					}
				}
			}
			else if (stage == 2) {
				if (sinkoudo == 3) boss_flag = 1;
				if (CheckSoundMem(BGM_ADV[2]) == 0 && boss_flag == 0) {
					PlaySoundMem(BGM_ADV[2], DX_PLAYTYPE_LOOP);
				}
				if (sinkoudo == 1) {
					if (count[2] == 90) enemy_hp = 2;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[8], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[8], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0 && clear_ones == 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 2) {
					if (count[2] == 90) enemy_hp = 2;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[9], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[9], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (boss_flag == 1) {
					if (count[2] == 90) enemy_hp = 5;
					/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
						end_talk = TalkADV(stage, 1);
						if (end_talk == 0) count[2] = 170;
						else count[2] = 120;
					}*/
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[10], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[10], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
					else if (CheckSoundMem(BGM_ADV[2]) == 1) {
						StopSoundMem(BGM_ADV[2]);
						if (CheckSoundMem(BGM_ADV[3]) == 0) PlaySoundMem(BGM_ADV[3], DX_PLAYTYPE_LOOP);
					}
				}
			}
			else if (stage == 3) {
				if (sinkoudo == 4) boss_flag = 1;
				if (CheckSoundMem(BGM_ADV[4]) == 0 && boss_flag == 0) {
					PlaySoundMem(BGM_ADV[4], DX_PLAYTYPE_LOOP);
				}
				if (sinkoudo == 1) {
					if (count[2] == 90) enemy_hp = 2;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[13], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[13], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0 && clear_ones == 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 2) {
					if (count[2] == 90) enemy_hp = 2;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[14], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[14], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 3) {
					if (count[2] == 90) enemy_hp = 3;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[15], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[15], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (boss_flag == 1) {
					if (count[2] == 90) enemy_hp = 6;
					/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
						end_talk = TalkADV(stage, 1);
						if (end_talk == 0) count[2] = 170;
						else count[2] = 120;
					}*/
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[16], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[16], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
					else if (CheckSoundMem(BGM_ADV[4]) == 1) {
						StopSoundMem(BGM_ADV[4]);
						if (CheckSoundMem(BGM_ADV[5]) == 0) PlaySoundMem(BGM_ADV[5], DX_PLAYTYPE_LOOP);
					}
				}
			}
			else if (stage == 4) {
				if (sinkoudo == 5) boss_flag = 1;
				if (sinkoudo == 1) {
					if (count[2] == 90) enemy_hp = 1;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[21], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[21], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0 && clear_ones == 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 2) {
					if (count[2] == 90) {
						enemy_hp = 3;
					}
					/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
						end_talk = TalkADV(stage, 1);
						if (end_talk == 0) count[2] = 170;
						else count[2] = 120;
					}*/
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(EneX, EneY, 1.0, 0.0, Image_ADV[24], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(EneX, EneY, 1.0, 0.0, Image_ADV[24], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
					else if (CheckSoundMem(BGM_ADV[6]) == 0) {
						PlaySoundMem(BGM_ADV[6], DX_PLAYTYPE_LOOP);
					}
				}
				else if (sinkoudo == 3) {
					if (count[2] == 90) enemy_hp = 2;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[22], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[22], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 4) {
					if (count[2] == 90) enemy_hp = 3;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[23], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[23], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (boss_flag == 1) {
					if (count[2] == 90) enemy_hp = 8;
					/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
						end_talk = TalkADV(stage, 3);
						if (end_talk == 0) count[2] = 170;
						else count[2] = 120;
					}*/
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[24], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[24], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
					else if (CheckSoundMem(BGM_ADV[6]) == 1) {
						StopSoundMem(BGM_ADV[6]);
						if (CheckSoundMem(BGM_ADV[7]) == 0) PlaySoundMem(BGM_ADV[7], DX_PLAYTYPE_LOOP);
					}
				}
			}
			else if (stage == 5) {
			if (sinkoudo == 6) boss_flag = 1;
			if (CheckSoundMem(BGM_ADV[8]) == 0 && boss_flag == 0) {
				PlaySoundMem(BGM_ADV[8], DX_PLAYTYPE_LOOP);
			}
			if (sinkoudo == 1) {
				if (count[2] == 90) enemy_hp = 1;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[29], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[29], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0 && clear_ones == 0) Teki[stage - 1] += 5;
			}
			else if (sinkoudo == 2) {
				if (count[2] == 90) enemy_hp = 2;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[30], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[30], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
			}
			else if (sinkoudo == 3) {
				if (count[2] == 90) {
					enemy_hp = 4;
				}
				/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
					end_talk = TalkADV(stage, 1);
					if (end_talk == 0) count[2] = 170;
					else count[2] = 120;
				}*/
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(EneX, EneY, 1.0, 0.0, Image_ADV[33], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(EneX, EneY, 1.0, 0.0, Image_ADV[33], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
			}
			else if (sinkoudo == 4) {
				if (count[2] == 90) enemy_hp = 2;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(340, 220, 1.0, 0.0, Image_ADV[31], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(340, 220, 1.0, 0.0, Image_ADV[31], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
			}
			else if (sinkoudo == 5) {
				if (count[2] == 90) enemy_hp = 3;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[32], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[32], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
			}
			else if (boss_flag == 1) {
				if (count[2] == 90) enemy_hp = 8;
				/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
					end_talk = TalkADV(stage, 3);
					if (end_talk == 0) count[2] = 170;
					else count[2] = 120;
				}*/
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[33], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[33], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				else if (CheckSoundMem(BGM_ADV[8]) == 1) {
					StopSoundMem(BGM_ADV[8]);
					if (CheckSoundMem(BGM_ADV[9]) == 0) PlaySoundMem(BGM_ADV[9], DX_PLAYTYPE_LOOP);
				}
			}
			}
			else if (stage == 6) {
				if (sinkoudo == 3) boss_flag = 1;
				if (CheckSoundMem(BGM_ADV[10]) == 0 && boss_flag == 0) {
					PlaySoundMem(BGM_ADV[10], DX_PLAYTYPE_LOOP);
				}
				if (sinkoudo == 1) {
					if (count[2] == 90) enemy_hp = 3;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[36], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[36], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0 && clear_ones == 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 2) {
					if (count[2] == 90) {
						enemy_hp = 5;
					}
					/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
						end_talk = TalkADV(stage, 1);
						if (end_talk == 0) count[2] = 170;
						else count[2] = 120;
					}*/
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(EneX, EneY, 1.0, 0.0, Image_ADV[33], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(EneX, EneY, 1.0, 0.0, Image_ADV[33], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (boss_flag==1) {
					if (count[2] == 90) enemy_hp = 16;
					/*if (end_talk == 0 && talk_flag==0) {
						end_talk = TalkADV(stage, 3);
						if (end_talk == 0) count[2] = 100;
						else {
							count[2] = 120; talk_flag = 1; end_talk = 0;
						}
					}*/
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						if(lastB_henge==0)
							DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[38], TRUE);
						else if(lastB_henge==1)
							DrawRotaGraph(330, 210, 1.0, 0.0, Image_ADV[38], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[38], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
					else if (CheckSoundMem(BGM_ADV[10]) == 1) {
						StopSoundMem(BGM_ADV[10]);
						if (CheckSoundMem(BGM_ADV[11]) == 0) PlaySoundMem(BGM_ADV[11], DX_PLAYTYPE_LOOP);
					}
					/*if (end_talk == 0) {
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, Tra_6B);
						DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[39], TRUE);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					}*/
				}
			}
			if (count[2] == 180) {
				Input = MakeKeyInput(128, FALSE, FALSE, FALSE);
				Deput = MakeKeyInput(128, FALSE, FALSE, FALSE);
				SetActiveKeyInput(Input); end_talk = 0;
			}
//ーーーーーーーーーーーーーーーーーーーーー　戦闘開始　－－－－－－－－－－－－－－－－－－－－－－
			else if (count[2] > 180) {
				if (stop_flag == 0) {
					ans_con++;
					if (ADV_OneTime == 0) {
						rand = (int)GetRand(ystr - 1);
						while (daburi_flag == 0) {
							for (unsigned int i = 0; i < tyohuku.size(); i++) {
								if (tyohuku[i] == rand) {
									daburi_flag = 0;
									kaburi_suu++; tuuka++;
								}

							}
							if (kaburi_suu>=1) {
								rand = (int)GetRand(ystr - 1); kaburi_suu = 0;
							}
							else {
								daburi_flag = 1; kaburi_suu = 0;
							}
						}
						ADV_OneTime = 1; down = 15; gard = 0;
						if (CheckSoundMem(SE_Name[2]) == 0) PlaySoundMem(SE_Name[2], DX_PLAYTYPE_BACK);
					}
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
					for (unsigned int j = 0; j < str_adv[rand].size() / 2; j++) {
						if((str_adv[rand].size()/2)>=4) DrawBox(150 + (j * 40), 320, 190 + (j * 40), 360, White, TRUE);
						else DrawBox(300 + (j * 40), 320, 340 + (j * 40), 360, White, TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if ((str_adv[rand].size() / 2) >= 4) DrawFormatStringToHandle(150, 320, Black, kazufont[1], "%s", str_adv[rand].c_str());
					else DrawFormatStringToHandle(300, 320, Black, kazufont[1], "%s", str_adv[rand].c_str());

					if (key_flag == 0)	DrawKeyInputString(100, 400, Input);

					if (CheckKeyInput(Input) == 1 && key_flag == 0) {
						enter_flag = 1; key_flag = 1;
					}
					if (CheckHitKey(KEY_INPUT_RETURN) == 0) {
						key_flag = 0;
					}
					if (enter_flag == 1) {
						entercount++;
						if (entercount == 1) {
							GetKeyInputString(St_RD1, Input);
							if (CheckSoundMem(SE_Name[3]) == 0) PlaySoundMem(SE_Name[3], DX_PLAYTYPE_BACK);
							if (strcmp(yomi_adv[rand].c_str(), St_RD1) == 0) {
								setAnswer = 1;
							}
							else {
								setAnswer = 0;
							}
						}
						if (InpX < 300 && entercount < 30) {
							InpX += 5;
						}
						if (InpY > 250 && entercount < 30) {
							InpY -= 5;
						}
						DrawFormatStringToHandle(InpX, InpY, Red, kazufont[1], "%s", St_RD1);
						if (entercount == 30) {
							if (setAnswer == 1) {
								//if (CheckSoundMem(SE_Name[4]) == 0) PlaySoundMem(SE_Name[4], DX_PLAYTYPE_BACK);
								PlaySoundMem(SE_Name[4], DX_PLAYTYPE_BACK);
								hit_flag = 1; gard = 1;
							}
							else {
								//if (CheckSoundMem(SE_Name[5]) == 0) PlaySoundMem(SE_Name[5], DX_PLAYTYPE_BACK);
								PlaySoundMem(SE_Name[5], DX_PLAYTYPE_BACK);
							}
							SetActiveKeyInput(Input);
							InpX = 100; InpY = 400;
							SetKeyInputString("", Input);
							enter_flag = 0; entercount = 0;
						}
					}
//ーーーーーーーーーーーーーーーーーーーーー　カウントダウン　－－－－－－－－－－－－－－－－－－－－－－

					DrawFormatStringToHandle(300, 100, Red, kazufont[1], "%d", down);
					if (ans_con % 55 == 0 && enter_flag == 0 && down > 0 && stop_flag == 0) {
						down--;
					}
					if (down == 0) {
						if (enter_flag != 1 && gard == 0) gameover = 1;
					}
//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー

					if (hit_flag == 1) {
						hit_con++;
						if (hit_con == 40) {
							ADV_OneTime = 0;
							hit_flag = 0; hit_con = 0;
							enemy_hp--; daburi_flag = 0;
							tyohuku.push_back(rand);
							//if(enemy_hp!=0) PlaySoundMem(SE_Name[7], DX_PLAYTYPE_BACK);
						}
					}
				}

				if (enemy_hp == 0) {
					//clear_flag = 1;
					if (boss_flag == 1) clear_flag = 1;
					if (clear_ones == 0) {
						clear_ones = 1;
						stop_flag = 1;
						/*if (stage == 4 && sinkoudo == 2) {
							if (end_talk == 0) {
								end_talk = TalkADV(stage, 2);
								if (end_talk == 0) clear_ones=0;
								else clear_ones = 1;
							}
						}
						else if (stage == 5 && sinkoudo == 3) {
							if (end_talk == 0) {
								end_talk = TalkADV(stage, 2);
								if (end_talk == 0) clear_ones=0;
								else clear_ones = 1;
							}
						}
						else if (stage == 6 && sinkoudo == 2) {
							if (end_talk == 0) {
								end_talk = TalkADV(stage, 2);
								if (end_talk == 0) clear_ones=0;
								else clear_ones = 1;
							}
						}*/
						if ((stage == 4 && sinkoudo == 2) || (stage == 5 && sinkoudo == 3));
						else {
							if (CheckSoundMem(SE_Name[6]) == 0) PlaySoundMem(SE_Name[6], DX_PLAYTYPE_BACK);
						}
					}
					if (Teki[stage - 1] > 0 && clear_ones == 1) {
						Teki[stage - 1] -= 5;
						if (stage == 4 && sinkoudo == 2) {
							if (EneX > -100) EneX -= 10;
							if (EneY > 200) EneY -= 2;
							if (Teki[stage-1]<10 && Title_End == 0) {
								SetDrawBlendMode(DX_BLENDMODE_ALPHA, StageTitle);
								DrawStringToHandle(210, 190, "　ステージ４\n自然淘汰の末に\n　 海中洞窟", Black, kazufont[2]);
								SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
								if (StageTitle < 250 && Titlecon < 240) {
									StageTitle += 10; Teki[stage - 1] = 5;
									//if (CheckSoundMem(BGM_ADV[4]) == 0) PlaySoundMem(BGM_ADV[4], DX_PLAYTYPE_LOOP);
								}
								else {
									Titlecon++; Teki[stage - 1] = 5;
									if (Titlecon >= 240) {
										if (StageTitle > 0) {
											StageTitle -= 10;
										}
										else {
											Titlecon = 0; Title_End = 1;
										}
									}
								}
							}
						}
						else if (stage == 5 && sinkoudo == 3) {
							if (EneX > -100) EneX -= 10;
							if (EneY > 10) EneY -= 5;
						}
						//else if (stage == 6 && sinkoudo == 2) {
						//	if (CheckSoundMem(SE_Name[6]) == 0 && Teki[stage-1]>240) PlaySoundMem(SE_Name[6], DX_PLAYTYPE_BACK);
						//}
					}
					else if(clear_ones==1){
						if (boss_flag == 0) {
							if (stage == 1 || stage == 2 || stage == 3) {
								sinkoudo++; count[2] = 2; return_st = 1;
							}
							else if (stage == 4) {
								if (sinkoudo == 1) {
									bg_change = 1;
									if (Trans[3] >0) Trans[3] -= 5;
									else {
										sinkoudo++; count[2] = 2; return_st = 1;
									}
								}
								else if (sinkoudo == 2) {
									if (BG_Tra[0] > 0) BG_Tra[0] -= 5;
									else {
										sinkoudo++; count[2] = 2; return_st = 1;
									}
								}
								else if (sinkoudo == 3) {
									sinkoudo++; count[2] = 2; return_st = 1;
								}
								else if (sinkoudo == 4) {
									if (BG_Tra[1] > 0) BG_Tra[1] -= 5;
									else {
										sinkoudo++; count[2] = 2; return_st = 1;
									}
								}
							}
							else if (stage == 5) {
								if (sinkoudo == 1) {
									sinkoudo++; count[2] = 2; return_st = 1;
								}
								if (sinkoudo == 2) {
									bg_change = 1;
									if (Trans[3] > 0) Trans[3] -= 5;
									else {
										sinkoudo++; count[2] = 2; return_st = 1;
									}
								}
								else if (sinkoudo == 3) {
									if (BG_Tra[0] > 0) BG_Tra[0] -= 5;
									else {
										sinkoudo++; count[2] = 2; return_st = 1;
									}
								}
								else if (sinkoudo == 4) {
									sinkoudo++; count[2] = 2; return_st = 1;
								}
								else if (sinkoudo == 5) {
									if (BG_Tra[1] > 0) BG_Tra[1] -= 5;
									else {
										sinkoudo++; count[2] = 2; return_st = 1;
									}
								}
							}
							else if (stage == 6) {
								if (sinkoudo == 1) {
									sinkoudo++; count[2] = 2; return_st = 1;
								}
								else if (sinkoudo == 2) {
									last_chaku = 1;
								}
							}
						}
					}
				}
				if (clear_flag == 1) {
					static int clear_con = 0;
					stop_flag = 1;
					/*if (end_talk == 0 && clear_con >= 60 && clear_con < 70) {
						end_talk = TalkADV(stage, 10);
						if (end_talk == 0) clear_con=60;
						else clear_con = 10;
						
					}*/
					if (clear_con >= 120) {
						if(stage!=6) DrawRotaGraph(320, 240, 1.0, 0.0, Image_Dan1[2], TRUE);
						else DrawRotaGraph(320, 240, 1.0, 0.0, Image_ADV[5], TRUE);

						ChangeVolumeSoundMem(Volume, BGM_ADV[(stage * 2) - 1]);
						if (Volume > 0) {
							Volume--;
						}

					}
					if (clear_con == 420) {
						if(stage == 6){
							clear_con = 0; clear_flag = 0; clear_ones = 0;
							Trans[4] = 0; count[2] = 0; ADV_OneTime = 0; Trans[3] = 0;
							for (unsigned int i = 0; i < str_adv.size();) {
								str_adv.pop_back();
							}
							for (unsigned int i = 0; i < yomi_adv.size();) {
								yomi_adv.pop_back();
							}
							for (unsigned int i = 0; i < tyohuku.size();) {
								tyohuku.pop_back();
							}
							ystr = 0; yomiY = 0; str_switch = 0; buf_con = 0; rand = 0;
							//static char St_RD1[256];
							Input = 0; Deput = 0; enter_flag = 0; entercount = 0; setAnswer = 0; hit_flag = 0; hit_con = 0;
							InpX = 100; InpY = 400; stop_flag = 0; change_sw = 1; EneX = 330; EneY = 200;
							enemy_hp = 3; scene = 0; randbgm_Title = (int)GetRand(1); end_talk = 0; talk_flag = 0;
							Teki[0] = 0; return_st = 0; sinkoudo = 1; start_flag = 0; boss_flag = 0; Volume = 255;
							allclear = 1; Title_End = 0; stage = 1;
							Clear_data = fopen("Save/RD_Ex.txt", "w");
							fprintf(Clear_data,"%d",allclear);
							fclose(Clear_data);

							std::string Temp_Kousin;
							StarFlag[3] = 1;
							Star_kousin = fopen("Save/Star.txt", "w");
							if (Star_kousin == NULL) {
								EndFlag = 1;
							}
							for (int i = 0; i < 5; i++) {
								Temp_Kousin += (char)(StarFlag[i] + '0');
							}
							fprintf(Star_kousin, "%s", Temp_Kousin.c_str());
							fclose(Star_kousin);
							
						}
						else {
							stage++;
							clear_con = 0; clear_flag = 0; clear_ones = 0;
							Trans[4] = 0; count[2] = 0; ADV_OneTime = 0; Trans[3] = 0;
							for (unsigned int i = 0; i < str_adv.size();) {
								str_adv.pop_back();
							}
							for (unsigned int i = 0; i < yomi_adv.size();) {
								yomi_adv.pop_back();
							}
							for (unsigned int i = 0; i < tyohuku.size();) {
								tyohuku.pop_back();
							}
							ystr = 0; yomiY = 0; str_switch = 0; buf_con = 0; rand = 0;
							//static char St_RD1[256];
							Input = 0; Deput = 0; enter_flag = 0; entercount = 0; setAnswer = 0; hit_flag = 0; hit_con = 0;
							InpX = 100; InpY = 400; stop_flag = 0; change_sw = 1; Title_End = 0;
							enemy_hp = 3; EneX = 330; EneY = 200; end_talk = 0; talk_flag = 0; Volume = 255;
							Teki[0] = 0; return_st = 0; sinkoudo = 1; start_flag = 1; boss_flag = 0;
						}
					}
					clear_con++;
				}
				if (gameover == 1) {
					over_con++; stop_flag = 1;
					SetActiveKeyInput(Deput);
					if (over_con == 1) {
						zanki--;
						PlaySoundMem(SE_Name[8], DX_PLAYTYPE_BACK);
					}
					if (zanki <= 0) {
						if (over_con > 180) {
							DrawRotaGraph(320, 240, 1.0, 0.0, Image_Dan1[3], TRUE);
							for (unsigned int j = 0; j < (yomi_adv[rand].size() / 2) + 3; j++) {
								DrawBox(100 + (j * 40), 300, 240 + (j * 40), 340, White, TRUE);
							}
							DrawFormatStringToHandle(100, 300, Black, kazufont[1], "答え：%s", yomi_adv[rand].c_str());
						}
						if (over_con == 480) {
							over_con = 0; gameover = 0; zanki = 0;
							Trans[4] = 0; count[2] = 0; ADV_OneTime = 0; Trans[3] = 0;
							for (unsigned int i = 0; i < str_adv.size();) {
								str_adv.pop_back();
							}
							for (unsigned int i = 0; i < yomi_adv.size();) {
								yomi_adv.pop_back();
							}
							for (unsigned int i = 0; i < tyohuku.size();) {
								tyohuku.pop_back();
							}
							for (int i = 0; i < 15; i++) {
								if (CheckSoundMem(BGM_ADV[i]) == 1) StopSoundMem(BGM_ADV[i]);
							}
							ystr = 0; yomiY = 0; str_switch = 0; buf_con = 0; rand = 0;
							//static char St_RD1[256];
							Input = 0; Deput = 0; enter_flag = 0; entercount = 0; setAnswer = 0; hit_flag = 0; hit_con = 0;
							InpX = 100; InpY = 400; stop_flag = 0; change_sw = 1; EneX = 330; EneY = 200;
							enemy_hp = 3; scene = 0; randbgm_Title = (int)GetRand(1); end_talk = 0; talk_flag = 0;
							stage = 1; Teki[0] = 0; start_flag = 0; return_st = 0; sinkoudo = 1; boss_flag = 0;
						}
					}
					else {
						if (over_con > 120) {
							if (change_sw == 1 && team == 1) DrawRotaGraph(320, 240, 0.8, 0.0, Image_Dan1[4], TRUE);
							if (over_con % 30 == 0) change_sw *= -1;
							DrawFormatStringToHandle(180, 350, Green, kazufont[1], "Enterで再挑戦");

							if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
								over_con = 0; gameover = 0; stop_flag = 0; down = 15; key_flag = 1;
								SetActiveKeyInput(Input);
								if (team == 0) {
									daburi_flag = 0; ADV_OneTime = 0; tyohuku.push_back(rand);
								}
							}
						}
					}
				}

			}
		}

//ーーーーーーーーーーーーーーーーーーーーー　StartFlag終わり　－－－－－－－－－－－－－－－－－－－－－

	}
}


//ーーーーーーーーーーーーーーーーーーーーーー　アドベンチャーEX　－－－－－－－－－－－－－－－－－－－－


void ADV_EX() {

	static int StageTitle = 0;
	static int Titlecon = 0;

	static int zanki = 3, start_flag = 0, stage = 7,adv_mode=0,team=0;
	static int stage_con[6] = {};
	static int ADV_OneTime = 0;

	FILE *ADV_data,*Boss_data;
	static char buf1,buf_boss;
	static std::vector<std::string> str_adv = {};
	static std::vector<std::string> yomi_adv = {};
	static std::vector<std::string> str_boss = {};
	static std::vector<std::string> yomi_boss = {};
	static int ystr = 0, yomiY = 0, str_switch = 0, buf_con = 0;
	static int ystr_B = 0, yomiY_B = 0 , str_switch_B = 0, buf_con_B = 0;
	static int rand = 0, daburi_flag = 0,kaburi_suu=0;
	static std::vector<int> tyohuku;
	static std::vector<int> tyohuku_B;

	static int boss_flag = 0, sinkoudo = 1, return_st = 0, bg_change = 0;
	static int EneX = 330, EneY = 220;

	static int end_talk = 0;

	static char St_RD1[256];
	static int Input = 0, Deput = 0;
	static int enter_flag = 0, entercount = 0, setAnswer = 0, hit_flag = 0, hit_con = 0, gard = 0;
	static int InpX = 100, InpY = 400;

	static int enemy_hp = 10, clear_flag = 0, clear_ones = 0;
	static int down = 0, gameover = 0, ans_con = 0, stop_flag = 0;

	static int over_con = 0, change_sw = 1;
	static int lastB_con = 0, last_chaku = 0, talk_flag = 0;

//ーーーーーーーーーーーーーーーーーーーーーー　人数選択　－－－－－－－－－－－－－－－－－－－－－－－

	if (start_flag == 0) {
		DrawRotaGraph(330, 240, 0.8, 0.0, Image_RDSE[3], TRUE);

		if (adv_mode == 0) {
			DrawFormatStringToHandle(50, 100, Green, kazufont[1], "一人で遊ぶ？チームで遊ぶ？");
			DrawFormatStringToHandle(30, 150, White, kazufont[3], "(一人の場合、失敗したら漢字が変わるようになります\nゲームオーバー時に表示される答えは最後の失敗のみ)");

			if (team == 0) {
				DrawFormatStringToHandle(100, 300, Red, kazufont[2], "一人で遊ぶ");
				DrawFormatStringToHandle(340, 300, White, kazufont[2], "チームで遊ぶ");
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
					adv_mode = 1; key_flag = 1;
				}
			}
			else if (team = 1) {
				DrawFormatStringToHandle(100, 300, White, kazufont[2], "一人で遊ぶ");
				DrawFormatStringToHandle(340, 300, Red, kazufont[2], "チームで遊ぶ");
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
					adv_mode = 1; key_flag = 1;
				}
			}

			if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && key_flag == 0) {
				team++; key_flag = 1;
			}
			else if (CheckHitKey(KEY_INPUT_LEFT) == 1 && key_flag == 0) {
				team--; key_flag = 1;
			}
			if (CheckHitKey(KEY_INPUT_RETURN) == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0) {
				key_flag = 0;
			}
			if (team >= 2) team = 1;
			else if (team < 0) team = 0;

		}

		if (adv_mode == 1) {
			if (team == 1) DrawFormatStringToHandle(150, 100, White, kazufont[2], "参加人数を選択(最大5人)");
			else if (team == 0) DrawFormatStringToHandle(150, 100, White, kazufont[2], "残機を選択(最大5機)");

			DrawFormatStringToHandle(300, 170, White, kazufont[1], "%d", zanki);

			if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && key_flag == 0) {
				zanki++; key_flag = 1;
			}
			else if (CheckHitKey(KEY_INPUT_LEFT) == 1 && key_flag == 0) {
				zanki--; key_flag = 1;
			}
			else if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
				start_flag = 10; key_flag = 1; adv_mode = 0;
			}
			if (CheckHitKey(KEY_INPUT_RETURN) == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0) {
				key_flag = 0;
			}
			if (zanki < 5) DrawTriangle(330, 180, 330, 200, 350, 190, White, TRUE);
			if (zanki > 1) DrawTriangle(290, 180, 290, 200, 270, 190, White, TRUE);

			if (zanki > 5) zanki = 5;
			else if (zanki <= 0) zanki = 1;
		}
	}

//ーーーーーーーーーーーーーーーーーーーーーーーー　隠し階段まで　－－－－－－－－－－－－－－－－－－－－－－－

	if (start_flag == 10) {
		if (CheckSoundMem(BGM_Name[0]) == 1) StopSoundMem(BGM_Name[0]);
		else if (CheckSoundMem(BGM_Name[4]) == 1) StopSoundMem(BGM_Name[4]);
		count[3]++;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[3]);
		DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[35], TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		if (Trans[3] < 255 && count[3] < 300) {
			Trans[3] += 5;
		}

		if (count[3] >= 120 && count[3]<300) {
			count[3]+=6;
		}
		if (count[3] >= 300) {

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, BG_Tra[0]);
			DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[40], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			//if (BG_Tra[0] < 255) BG_Tra[0] += 5;
			if (Trans[3] <10 && BG_Tra[0] < 255) BG_Tra[0] += 5;
			if (Trans[3] > 0) Trans[3] -= 5;
			else {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, StageTitle);
				DrawStringToHandle(180,180,"　　ステージEx\n　 哀しみの才女\n 　竜宮城　聖域",White,kazufont[2]);
				//DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[35], TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (StageTitle < 250 && count[3] >= 420 && Titlecon < 240) {
					StageTitle += 5;
					if (CheckSoundMem(BGM_ADV[12]) == 0) PlaySoundMem(BGM_ADV[12], DX_PLAYTYPE_LOOP);
				}
				else {
					Titlecon++;
					if (Titlecon >= 240) {
						if (StageTitle > 0) StageTitle -= 10;
						else {
							end_talk = 0; start_flag = 1; Titlecon = 0; count[3] = 0;
							Trans[3] = 255; BG_Tra[0] = 0;
						}
					}
				}
			}
		}
		
	}


//ーーーーーーーーーーーーーーーーーーーーーーーー　ADV開始　－－－－－－－－－－－－－－－－－－－－－－－－

	if (start_flag == 1) {
		count[2]++;

		if (boss_flag == 0 && Trans[4] < 250) {
			
			if (sinkoudo >= 1 && sinkoudo<4) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[3]);
				DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[40], TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
			else if (sinkoudo >= 4) {
				/*//if (Trans[3] > 0) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[3]);
					DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[40], TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				//	Trans[3] -= 5;
					count[2] = 2;
				//}
				else {*/
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, BG_Tra[0]);
					DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[41], TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (BG_Tra[0] < 250) {
						BG_Tra[0] += 10; count[2] = 2;
					}
				//}
			}
			//DrawFormatStringToHandle(50, 100, White, kazufont[2], "%d",tyohuku.size());
		}
		else if (boss_flag == 1) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, BG_Tra[1]);
			DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[42], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			if (BG_Tra[1] < 255) BG_Tra[1] += 5;
		}
		/*if (count[2]>=120) {

		}*/

//ーーーーーーーーーーーーーーーーーーーーーーーーー　ファイル読み込み　－－－－－－－－－－－－－－－－－－－－

		if (count[2] == 1) {
			if (CheckSoundMem(BGM_Name[0]) == 1) StopSoundMem(BGM_Name[0]);
			else if (CheckSoundMem(BGM_Name[4]) == 1) StopSoundMem(BGM_Name[4]);
			if (stage == 7) {
				ADV_data = fopen("Data/ADV_6.txt", "r");
				Boss_data = fopen("Data/ADV_Ex.txt","r");
			}
			if (ADV_data == NULL || Boss_data==NULL) {
				EndFlag = 1;
			}

			while ((buf1 = fgetc(ADV_data)) != EOF) {
				str_adv.resize(ystr + 1); yomi_adv.resize(yomiY + 1);
				if (buf1 == '\n') {
					ystr++; yomiY++; str_switch = 0; buf_con = -1;
				}
				else if (buf1 == ':') {
					str_switch = 1; buf_con = -1;
				}
				else if (str_switch == 0) {
					if (buf_con == 0) str_adv[ystr] = buf1;
					else str_adv[ystr].push_back(buf1);
					//str_rd1[ystr] += buf2;
				}
				else if (str_switch == 1) {
					if (buf_con == 0) yomi_adv[yomiY] = buf1;
					else yomi_adv[yomiY].push_back(buf1);
				}
				buf_con++;
			}
			fclose(ADV_data);

			while ((buf_boss = fgetc(Boss_data)) != EOF) {
				str_boss.resize(ystr_B + 1); yomi_boss.resize(yomiY_B + 1);
				if (buf_boss == '\n') {
					ystr_B++; yomiY_B++; str_switch_B = 0; buf_con_B = -1;
				}
				else if (buf_boss == ':') {
					str_switch_B = 1; buf_con_B = -1;
				}
				else if (str_switch_B == 0) {
					if (buf_con_B == 0) str_boss[ystr_B] = buf_boss;
					else str_boss[ystr_B].push_back(buf_boss);
					//str_rd1[ystr] += buf2;
				}
				else if (str_switch_B == 1) {
					if (buf_con_B == 0) yomi_boss[yomiY_B] = buf_boss;
					else yomi_boss[yomiY_B].push_back(buf_boss);
				}
				buf_con_B++;
			}
			fclose(Boss_data);
		}

//ーーーーーーーーーーーーーーーーーーーーー　ボス面演出　－－－－－－－－－－－－－－－－－－－－－－
		if (last_chaku == 1) {
			lastB_con++; count[2] = 2;
		}
		if (lastB_con >= 60) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, BG_Tra[3]);
			DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[39], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			if (BG_Tra[3] < 255 && lastB_con < 180) BG_Tra[3] += 5;
			if (lastB_con >= 180) {
				sinkoudo++; count[2] = 2; boss_flag = 1;
				return_st = 0; clear_ones = 0; stop_flag = 0; bg_change = 0;
				if (BG_Tra[3] > 0) BG_Tra[3] -= 5;
				else {
					last_chaku = 0; lastB_con = 0;
				}
			}
		}
//ーーーーーーーーーーーーーーーーーーーー　敵グラ表示　ーーーーーーーーーーーーーーーーーーーーーー
		if (count[2] >= 90) {
			if (return_st == 1) {
				if (lastB_con == 0) {
					return_st = 0; clear_ones = 0; stop_flag = 0; bg_change = 0;
				}
			}
			if (stage == 7) {
				if (sinkoudo >= 7) boss_flag = 1;
				if (sinkoudo == 1) {
					if (count[2] == 90) enemy_hp = 2;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[43], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[43], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0 && clear_ones == 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 2) {
					if (count[2] == 90) enemy_hp = 2;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[44], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[44], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 3) {
					if (count[2] == 90) enemy_hp = 8;
					/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
						end_talk = TalkADV(stage, 1);
						if (end_talk == 0) count[2] = 170;
						else count[2] = 120;
					}*/
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[45], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[45], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 4) {
					if (count[2] == 90) enemy_hp = 2;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[46], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[46], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 5) {
					if (count[2] == 90) enemy_hp = 3;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[47], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[47], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 6) {
					if (count[2] == 90) enemy_hp = 3;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[48], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 1.0, 0.0, Image_ADV[48], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (boss_flag == 1) {
					if (count[2] == 90) enemy_hp = 40;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 200, 1.0, 0.0, Image_ADV[49], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 200, 1.0, 0.0, Image_ADV[49], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
					else if (CheckSoundMem(BGM_ADV[12]) == 1) {
						StopSoundMem(BGM_ADV[12]);
						if (CheckSoundMem(BGM_ADV[13]) == 0) PlaySoundMem(BGM_ADV[13], DX_PLAYTYPE_LOOP);
					}
					/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
						end_talk = TalkADV(stage, 3);
						if (end_talk == 0) count[2] = 170;
						else count[2] = 120;
					}*/
				}
			}
			if (count[2] == 180) {
				Input = MakeKeyInput(128, FALSE, FALSE, FALSE);
				Deput = MakeKeyInput(128, FALSE, FALSE, FALSE);
				SetActiveKeyInput(Input); end_talk = 0;
			}
//ーーーーーーーーーーーーーーーーーーーーーーー　戦闘開始　－－－－－－－－－－－－－－－－－－－－－－－

			else if (count[2] > 180) {
				if (stop_flag == 0) {
					ans_con++;
					if (ADV_OneTime == 0) {
						if (boss_flag == 0) {
							rand = (int)GetRand(ystr - 1);
							while (daburi_flag == 0) {
								for (unsigned int i = 0; i < tyohuku.size(); i++) {
									if (tyohuku[i] == rand) {
										daburi_flag = 0;
										kaburi_suu++;
									}

								}
								if (kaburi_suu>=1) {
									rand = (int)GetRand(ystr - 1); kaburi_suu = 0;
								}
								else {
									daburi_flag = 1; kaburi_suu = 0;
								}
							}
						}
						else if (boss_flag == 1) {
							rand = (int)GetRand(ystr_B - 1);
							while (daburi_flag == 0) {
								for (unsigned int i = 0; i < tyohuku_B.size(); i++) {
									if (tyohuku_B[i] == rand) {
										daburi_flag = 0;
										kaburi_suu++;
									}

								}
								if (kaburi_suu>=1) {
									rand = (int)GetRand(ystr_B - 1); kaburi_suu = 0;
								}
								else {
									daburi_flag = 1; kaburi_suu = 0;
								}
							}
						}
						ADV_OneTime = 1; down = 15; gard = 0;
						if (CheckSoundMem(SE_Name[2]) == 0) PlaySoundMem(SE_Name[2], DX_PLAYTYPE_BACK);
					}
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
					if (boss_flag == 0) {
						for (unsigned int j = 0; j < str_adv[rand].size() / 2; j++) {
							if ((str_adv[rand].size() / 2) >= 4) DrawBox(200 + (j * 40), 320, 240 + (j * 40), 360, White, TRUE);
							else DrawBox(300 + (j * 40), 320, 340 + (j * 40), 360, White, TRUE);
						}
					}
					else if (boss_flag == 1) {
						for (unsigned int j = 0; j < str_boss[rand].size() / 2; j++) {
							if ((str_boss[rand].size() / 2) >= 4) DrawBox(200 + (j * 40), 320, 240 + (j * 40), 360, White, TRUE);
							else DrawBox(300 + (j * 40), 320, 340 + (j * 40), 360, White, TRUE);
						}
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (boss_flag == 0) {
						if ((str_adv[rand].size() / 2) >= 4) DrawFormatStringToHandle(200, 320, Black, kazufont[1], "%s", str_adv[rand].c_str());
						else DrawFormatStringToHandle(300, 320, Black, kazufont[1], "%s", str_adv[rand].c_str());
					}
					else if (boss_flag == 1) {
						if ((str_boss[rand].size() / 2) >= 4) DrawFormatStringToHandle(200, 320, Black, kazufont[1], "%s", str_boss[rand].c_str());
						else DrawFormatStringToHandle(300, 320, Black, kazufont[1], "%s", str_boss[rand].c_str());
					}

					if (key_flag == 0)	DrawKeyInputString(100, 400, Input);

					if (CheckKeyInput(Input) == 1 && key_flag == 0) {
						enter_flag = 1; key_flag = 1;
					}
					if (CheckHitKey(KEY_INPUT_RETURN) == 0) {
						key_flag = 0;
					}
					if (enter_flag == 1) {
						entercount++;
						if (entercount == 1) {
							GetKeyInputString(St_RD1, Input);
							if (CheckSoundMem(SE_Name[3]) == 0) PlaySoundMem(SE_Name[3], DX_PLAYTYPE_BACK);
							if (boss_flag == 0) {
								if (strcmp(yomi_adv[rand].c_str(), St_RD1) == 0) {
									setAnswer = 1;
								}
								else {
									setAnswer = 0;
								}
							}
							if (boss_flag == 1) {
								if (strcmp(yomi_boss[rand].c_str(), St_RD1) == 0) {
									setAnswer = 1;
								}
								else {
									setAnswer = 0;
								}
							}
						}
						if (InpX < 300 && entercount < 30) {
							InpX += 5;
						}
						if (InpY > 250 && entercount < 30) {
							InpY -= 5;
						}
						DrawFormatStringToHandle(InpX, InpY, Red, kazufont[1], "%s", St_RD1);
						if (entercount == 30) {
							if (setAnswer == 1) {
								//if (CheckSoundMem(SE_Name[4]) == 0) PlaySoundMem(SE_Name[4], DX_PLAYTYPE_BACK);
								PlaySoundMem(SE_Name[4], DX_PLAYTYPE_BACK);
								hit_flag = 1; gard = 1;
							}
							else {
								//if (CheckSoundMem(SE_Name[5]) == 0) PlaySoundMem(SE_Name[5], DX_PLAYTYPE_BACK);
								PlaySoundMem(SE_Name[5], DX_PLAYTYPE_BACK);
							}
							SetActiveKeyInput(Input);
							InpX = 100; InpY = 400;
							SetKeyInputString("", Input);
							enter_flag = 0; entercount = 0;
						}
					}
//ーーーーーーーーーーーーーーーーーーーーー　カウントダウン　－－－－－－－－－－－－－－－－－－－－－－

					DrawFormatStringToHandle(300, 100, Red, kazufont[1], "%d", down);
					if (ans_con % 55 == 0 && enter_flag == 0 && down > 0 && stop_flag == 0) {
						down--;
					}
					if (down == 0) {
						if (enter_flag != 1 && gard == 0) gameover = 1;
					}
//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー

					if (hit_flag == 1) {
						hit_con++;
						if (hit_con == 40) {
							ADV_OneTime = 0;
							hit_flag = 0; hit_con = 0;
							enemy_hp--; daburi_flag = 0;
							if (boss_flag == 0) tyohuku.push_back(rand);
							else if (boss_flag == 1) tyohuku_B.push_back(rand);
							//if(enemy_hp!=0) PlaySoundMem(SE_Name[7], DX_PLAYTYPE_BACK);
						}
					}
				}

				if (enemy_hp == 0) {
					//clear_flag = 1;
					if (boss_flag == 1) clear_flag = 1;
					if (clear_ones == 0) {
						clear_ones = 1;
						stop_flag = 1;
						/*if (stage == 7 && sinkoudo == 3) {
							if (end_talk == 0) {
								end_talk = TalkADV(stage, 2);
								if (end_talk == 0) clear_ones = 0;
								else clear_ones = 1;
							}
						}*/
						//else {
							if (CheckSoundMem(SE_Name[6]) == 0) PlaySoundMem(SE_Name[6], DX_PLAYTYPE_BACK);
						//}
					}
					if (Teki[stage - 1] > 0 && clear_ones == 1) {
						Teki[stage - 1] -= 5;
						//if (stage == 7 && sinkoudo == 3) {
						//	if (CheckSoundMem(SE_Name[6]) == 0 && Teki[stage - 1] > 240) PlaySoundMem(SE_Name[6], DX_PLAYTYPE_BACK);
						//}
					}
					else if (clear_ones == 1) {
						if (boss_flag == 0) {
							if (stage == 7) {
								if (sinkoudo == 3) {
									bg_change = 1;
									if (Trans[3] > 0) Trans[3] -= 5;
									else {
										sinkoudo++; count[2] = 2; return_st = 1;
									}
								}
								else if (sinkoudo == 6) {
									last_chaku = 1;
								}
								else {
									sinkoudo++; count[2] = 2; return_st = 1;
								}
							}
						}
					}
				}
				if (clear_flag == 1) {
					static int clear_con = 0;
					stop_flag = 1;
					/*if (end_talk == 0 && clear_con >= 60 && clear_con < 70) {
						end_talk = TalkADV(stage, 10);
						if (end_talk == 0) clear_con = 60;
						else clear_con = 10;

					}*/
					if (clear_con >= 120) {
						if (stage != 6) DrawRotaGraph(320, 240, 1.0, 0.0, Image_Dan1[2], TRUE);
						else DrawRotaGraph(320, 240, 1.0, 0.0, Image_ADV[5], TRUE);
					}
					if (clear_con == 420) {
						if (stage == 7) {
							clear_con = 0; clear_flag = 0; clear_ones = 0;
							Trans[4] = 0; count[2] = 0; ADV_OneTime = 0; Trans[3] = 0;
							if (CheckSoundMem(BGM_ADV[13]) == 1) StopSoundMem(BGM_ADV[13]);

							for (unsigned int i = 0; i < str_adv.size();) {
								str_adv.pop_back();
							}
							for (unsigned int i = 0; i < yomi_adv.size();) {
								yomi_adv.pop_back();
							}
							for (unsigned int i = 0; i < tyohuku.size();) {
								tyohuku.pop_back();
							}
							for (unsigned int i = 0; i < str_boss.size();) {
								str_boss.pop_back();
							}
							for (unsigned int i = 0; i < yomi_boss.size();) {
								yomi_boss.pop_back();
							}
							for (unsigned int i = 0; i < tyohuku_B.size();) {
								tyohuku_B.pop_back();
							}
							ystr = 0; yomiY = 0; str_switch = 0; buf_con = 0; rand = 0;
							ystr_B = 0; yomiY_B = 0; str_switch_B = 0; buf_con_B = 0;
							//static char St_RD1[256];
							Input = 0; Deput = 0; enter_flag = 0; entercount = 0; setAnswer = 0; hit_flag = 0; hit_con = 0;
							InpX = 100; InpY = 400; stop_flag = 0; change_sw = 1; EneX = 330; EneY = 200;
							enemy_hp = 3; scene = 0; randbgm_Title = (int)GetRand(1); end_talk = 0; talk_flag = 0;
							Teki[0] = 0; return_st = 0; sinkoudo = 1; start_flag = 0; boss_flag = 0;
							stage = 7;
							//allclear = 1;
							//Clear_data = fopen("Save/RD_Ex.txt", "w");
							//fprintf(Clear_data, "%d", allclear);
							//fclose(Clear_data);
							std::string Temp_Kousin;
							StarFlag[4] = 1;
							Star_kousin = fopen("Save/Star.txt", "w");
							if (Star_kousin == NULL) {
								EndFlag = 1;
							}
							for (int i = 0; i < 5; i++) {
								Temp_Kousin += (char)(StarFlag[i] + '0');
							}
							fprintf(Star_kousin, "%s", Temp_Kousin.c_str());
							fclose(Star_kousin);

						}
						else {
							stage++;
							clear_con = 0; clear_flag = 0; clear_ones = 0;
							Trans[4] = 0; count[2] = 0; ADV_OneTime = 0; Trans[3] = 0;
							if (CheckSoundMem(BGM_ADV[13]) == 1) StopSoundMem(BGM_ADV[13]);
							for (unsigned int i = 0; i < str_adv.size();) {
								str_adv.pop_back();
							}
							for (unsigned int i = 0; i < yomi_adv.size();) {
								yomi_adv.pop_back();
							}
							for (unsigned int i = 0; i < tyohuku.size();) {
								tyohuku.pop_back();
							}
							for (unsigned int i = 0; i < str_boss.size();) {
								str_boss.pop_back();
							}
							for (unsigned int i = 0; i < yomi_boss.size();) {
								yomi_boss.pop_back();
							}
							for (unsigned int i = 0; i < tyohuku_B.size();) {
								tyohuku_B.pop_back();
							}
							ystr = 0; yomiY = 0; str_switch = 0; buf_con = 0; rand = 0;
							ystr_B = 0; yomiY_B = 0; str_switch_B = 0; buf_con_B = 0;
							//static char St_RD1[256];
							Input = 0; Deput = 0; enter_flag = 0; entercount = 0; setAnswer = 0; hit_flag = 0; hit_con = 0;
							InpX = 100; InpY = 400; stop_flag = 0; change_sw = 1;
							enemy_hp = 3; EneX = 330; EneY = 200; end_talk = 0; talk_flag = 0;
							Teki[0] = 0; return_st = 0; sinkoudo = 1; start_flag = 1; boss_flag = 0;
						}
					}
					clear_con++;
				}
				if (gameover == 1) {
					over_con++; stop_flag = 1;
					SetActiveKeyInput(Deput);
					if (over_con == 1) {
						zanki--;
						PlaySoundMem(SE_Name[8], DX_PLAYTYPE_BACK);
					}
					if (zanki <= 0) {
						if (over_con > 180) {
							DrawRotaGraph(320, 240, 1.0, 0.0, Image_Dan1[3], TRUE);
							if (boss_flag == 0) {
								for (unsigned int j = 0; j < (yomi_adv[rand].size() / 2) + 3; j++) {
									DrawBox(100 + (j * 40), 300, 240 + (j * 40), 340, White, TRUE);
								}
							}
							else if (boss_flag == 1) {
								for (unsigned int j = 0; j < (yomi_boss[rand].size() / 2) + 3; j++) {
									DrawBox(100 + (j * 40), 300, 240 + (j * 40), 340, White, TRUE);
								}
							}
							if(boss_flag==0) DrawFormatStringToHandle(100, 300, Black, kazufont[1], "答え：%s", yomi_adv[rand].c_str());
							else if (boss_flag == 1) DrawFormatStringToHandle(100, 300, Black, kazufont[1], "答え：%s", yomi_boss[rand].c_str());
						}
						if (over_con == 480) {
							over_con = 0; gameover = 0; zanki = 0;
							Trans[4] = 0; count[2] = 0; ADV_OneTime = 0; Trans[3] = 0;
							for (unsigned int i = 0; i < str_adv.size();) {
								str_adv.pop_back();
							}
							for (unsigned int i = 0; i < yomi_adv.size();) {
								yomi_adv.pop_back();
							}
							for (unsigned int i = 0; i < tyohuku.size();) {
								tyohuku.pop_back();
							}
							for (unsigned int i = 0; i < str_boss.size();) {
								str_boss.pop_back();
							}
							for (unsigned int i = 0; i < yomi_boss.size();) {
								yomi_boss.pop_back();
							}
							for (unsigned int i = 0; i < tyohuku_B.size();) {
								tyohuku_B.pop_back();
							}
							ystr = 0; yomiY = 0; str_switch = 0; buf_con = 0; rand = 0;
							ystr_B = 0; yomiY_B = 0; str_switch_B = 0; buf_con_B = 0;
							//static char St_RD1[256];
							Input = 0; Deput = 0; enter_flag = 0; entercount = 0; setAnswer = 0; hit_flag = 0; hit_con = 0;
							InpX = 100; InpY = 400; stop_flag = 0; change_sw = 1; EneX = 330; EneY = 200;
							enemy_hp = 3; scene = 0; randbgm_Title = (int)GetRand(1); end_talk = 0; talk_flag = 0;
							stage = 7; Teki[0] = 0; start_flag = 0; return_st = 0; sinkoudo = 1; boss_flag = 0;
							for (int i = 0; i < 15; i++) {
								if (CheckSoundMem(BGM_ADV[i]) == 1) StopSoundMem(BGM_ADV[i]);
							}
						}
					}
					else {
						if (over_con > 120) {
							if (change_sw == 1 && team == 1) DrawRotaGraph(320, 240, 0.8, 0.0, Image_Dan1[4], TRUE);
							if (over_con % 30 == 0) change_sw *= -1;
							DrawFormatStringToHandle(180, 350, Green, kazufont[1], "Enterで再挑戦");

							if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
								over_con = 0; gameover = 0; stop_flag = 0; down = 15; key_flag = 1;
								SetActiveKeyInput(Input);
								if (team == 0) {
									daburi_flag = 0; ADV_OneTime = 0;
									if(boss_flag==0) tyohuku.push_back(rand);
									else if(boss_flag==1) tyohuku_B.push_back(rand);
								}
							}
						}
					}
				}

			}

			//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー
		}
	}
}


//ーーーーーーーーーーーーーーーーーーーーーー　東方イベント　－－－－－－－－－－－－－－－－－－－－－－－－

void TOHO_Zen() {

	static int sen = 1, disp_bamen = 1;

	DrawRotaGraph(330, 240, 0.8, 0.0, Image_RDSE[7], TRUE);

	if (disp_bamen == 1) {

		DrawStringToHandle(0, 10, "このモードは「ステージが進む程難しくなる」\nと言い切れません。場合によりステージ１\nから難問が出される可能性があります。", Black, kazufont[2]);

		DrawStringToHandle(20, 150, "これを踏まえ、このモードで遊びますか？", White, kazufont[2]);

		if (sen == 1) DrawStringToHandle(200, 250, "それでも行くぜ", Red, kazufont[1]);
		else DrawStringToHandle(200, 250, "それでも行くぜ", White, kazufont[1]);
		if (sen == 2)DrawStringToHandle(200, 320, "やっぱやめるぜ", Red, kazufont[1]);
		else DrawStringToHandle(200, 320, "やっぱやめるぜ", White, kazufont[1]);


		if (CheckHitKey(KEY_INPUT_DOWN) == 1 && key_flag == 0) {
			//RD_se += 100;
			key_flag = 1; sen = 2;
		}
		else if (CheckHitKey(KEY_INPUT_UP) == 1 && key_flag == 0) {
			//RD_se -= 100;
			key_flag = 1; sen = 1;
		}
		else if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
			if (sen == 1) {
				sen = 1; disp_bamen=2;
			}
			else {
				sen = 1; scene = 4;
			}
			key_flag = 1;
		}
	}
	else if (disp_bamen == 2) {
		DrawStringToHandle(220, 10, "あらすじ", Red, kazufont[1]);
		DrawStringToHandle(10,100,"神社でお茶を飲んでいた霊夢は、近くに妖怪を見つける。\nいつものように退治しようとしたとき、意外なことに\n漢字で勝負をしかけてきた。魔理沙は楽しいと言うが、\nいつもより面倒だと思った霊夢は事の元凶を探しにいくことに。\n（決して自分が負けても不思議ではないルールが理由ではない。）\nなんだかんだで魔理沙も付いてきて、二人で出かけるのだった。",White,story,Black);
		DrawStringToHandle(150, 300, "Enterキーで始まるよ！", Green, kazufont[2]);
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
			disp_bamen = 1; scene = 9;
			key_flag = 1;
		}
	}
	if (CheckHitKey(KEY_INPUT_RETURN) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0 && CheckHitKey(KEY_INPUT_UP) == 0) {
		key_flag = 0;
	}

}

//TalkTohoは削除しました

void TOHO() {
	//DrawStringToHandle(10, 10, "きてます", White, kazufont[2]);

	static int zanki = 3, start_flag = 0, stage = 1, adv_mode = 0, team = 0;
	static int stage_con[6] = {};
	static int ADV_OneTime = 0;

	FILE *ADV2_data,*TOHO_data;
	static char buf1, buf_boss;
	static std::vector<std::string> str_adv = {};
	static std::vector<std::string> yomi_adv = {};
	static std::vector<std::string> str_boss = {};
	static std::vector<std::string> yomi_boss = {};
	static int ystr = 0, yomiY = 0, str_switch = 0, buf_con = 0;
	static int ystr_B = 0, yomiY_B = 0, str_switch_B = 0, buf_con_B = 0;
	static int rand = 0, daburi_flag = 1;
	static std::vector<int> tyohuku;
	static std::vector<int> tyohuku_B;

	static int boss_flag = 0, sinkoudo = 1, return_st = 0, bg_change = 0;
	static int EneX = 330, EneY = 220;

	static int end_talk = 0;

	static char St_RD1[256];
	static int Input = 0, Deput = 0;
	static int enter_flag = 0, entercount = 0, setAnswer = 0, hit_flag = 0, hit_con = 0, gard = 0;
	static int InpX = 100, InpY = 400;

	static int enemy_hp = 10, clear_flag = 0, clear_ones = 0;
	static int down = 0, gameover = 0, ans_con = 0, stop_flag = 0;

	static int over_con = 0, change_sw = 1;
	static int lastB_con = 0, last_chaku = 0, talk_flag = 0;
	static int Volume = 255, StageTitle = 0, Titlecon = 0, Title_End = 0, kaburi_suu = 0, tuuka = 0;

	//ーーーーーーーーーーーーーーーーーーーーーー　初期設定　－－－－－－－－－－－－－－－－－－－－－－－



	//ーーーーーーーーーーーーーーーーーーーーーー　人数選択　－－－－－－－－－－－－－－－－－－－－－－－

	if (start_flag == 0) {
		DrawRotaGraph(330, 240, 0.8, 0.0, Image_RDSE[3], TRUE);

		if (adv_mode == 0) {
			DrawFormatStringToHandle(50, 100, Green, kazufont[1], "一人で遊ぶ？チームで遊ぶ？");
			DrawFormatStringToHandle(30, 150, White, kazufont[3], "(一人の場合、失敗したら漢字が変わるようになります\nゲームオーバー時に表示される答えは最後の失敗のみ)");

			if (team == 0) {
				DrawFormatStringToHandle(100, 300, Red, kazufont[2], "一人で遊ぶ");
				DrawFormatStringToHandle(340, 300, White, kazufont[2], "チームで遊ぶ");
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
					adv_mode = 1; key_flag = 1;
				}
			}
			else if (team = 1) {
				DrawFormatStringToHandle(100, 300, White, kazufont[2], "一人で遊ぶ");
				DrawFormatStringToHandle(340, 300, Red, kazufont[2], "チームで遊ぶ");
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
					adv_mode = 1; key_flag = 1;
				}
			}

			if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && key_flag == 0) {
				team++; key_flag = 1;
			}
			else if (CheckHitKey(KEY_INPUT_LEFT) == 1 && key_flag == 0) {
				team--; key_flag = 1;
			}
			if (CheckHitKey(KEY_INPUT_RETURN) == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0) {
				key_flag = 0;
			}
			if (team >= 2) team = 1;
			else if (team < 0) team = 0;

		}

		if (adv_mode == 1) {
			if (team == 1) DrawFormatStringToHandle(150, 100, White, kazufont[2], "参加人数を選択(最大5人)");
			else if (team == 0) DrawFormatStringToHandle(150, 100, White, kazufont[2], "残機を選択(最大5機)");

			DrawFormatStringToHandle(300, 170, White, kazufont[1], "%d", zanki);

			if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && key_flag == 0) {
				zanki++; key_flag = 1;
			}
			else if (CheckHitKey(KEY_INPUT_LEFT) == 1 && key_flag == 0) {
				zanki--; key_flag = 1;
			}
			else if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0) {
				start_flag = 1; key_flag = 1; adv_mode = 0;
			}
			if (CheckHitKey(KEY_INPUT_RETURN) == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0) {
				key_flag = 0;
			}
			if (zanki < 5) DrawTriangle(330, 180, 330, 200, 350, 190, White, TRUE);
			if (zanki > 1) DrawTriangle(290, 180, 290, 200, 270, 190, White, TRUE);

			if (zanki > 5) zanki = 5;
			else if (zanki <= 0) zanki = 1;
		}
	}
	//ーーーーーーーーーーーーーーーーーーーーーー　ADv開始　－－－－－－－－－－－－－－－－－－－－－－－－

	if (start_flag == 1) {
		count[2]++;
		//stage_con[0]++;
//ーーーーーーーーーーーーーーーーーーーーーー　ステージ描写　－－－－－－－－－－－－－－－－－－－－－－
		if (boss_flag == 0 && Trans[4] < 250) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[3]);
			if (stage == 1) {
				DrawRotaGraph(330, 240, 1.0, 0.0, Image_TOHO[0], TRUE);
				if (Trans[3] > 250 && Title_End == 0) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, StageTitle);
					DrawStringToHandle(140, 180, "　　　　 Stage1\n活ある魚は今日も今日とて\n　　　　 霧の湖", Black, kazufont[2]);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (StageTitle < 250 && Titlecon < 240) {
						StageTitle += 10; count[2] = 2;
						if (CheckSoundMem(BGM_TOHO[0]) == 0) PlaySoundMem(BGM_TOHO[0], DX_PLAYTYPE_LOOP);
					}
					else {
						Titlecon++; count[2] = 2;
						if (Titlecon >= 240) {
							if (StageTitle > 0) {
								StageTitle -= 10;
							}
							else {
								Titlecon = 0; Title_End = 1;
							}
						}
					}
				}
			}
			else if (stage == 2) {
				DrawRotaGraph(330, 240, 1.0, 0.0, Image_TOHO[6], TRUE);
				if (Trans[3] > 250 && Title_End == 0) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, StageTitle);
					DrawStringToHandle(200, 190, "　　 Stage2\n実りと嵐の秋模様\n　　妖怪の山", Black, kazufont[2]);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (StageTitle < 250 && Titlecon < 240) {
						StageTitle += 10; count[2] = 2;
						if (CheckSoundMem(BGM_TOHO[2]) == 0) PlaySoundMem(BGM_TOHO[2], DX_PLAYTYPE_LOOP);
					}
					else {
						Titlecon++; count[2] = 2;
						if (Titlecon >= 240) {
							if (StageTitle > 0) {
								StageTitle -= 10;
							}
							else {
								Titlecon = 0; Title_End = 1;
							}
						}
					}
				}
			}
			else if (stage == 3) {
				DrawRotaGraph(330, 240, 1.0, 0.0, Image_TOHO[12], TRUE);
				if (Trans[3] > 250 && Title_End == 0) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, StageTitle);
					DrawStringToHandle(215, 190, "　　Stage3\n棺に収まりし夢\n　　夢幻館", Black, kazufont[2]);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (StageTitle < 250 && Titlecon < 240) {
						StageTitle += 10; count[2] = 2;
						if (CheckSoundMem(BGM_TOHO[4]) == 0) PlaySoundMem(BGM_TOHO[4], DX_PLAYTYPE_LOOP);
					}
					else {
						Titlecon++; count[2] = 2;
						if (Titlecon >= 240) {
							if (StageTitle > 0) {
								StageTitle -= 10;
							}
							else {
								Titlecon = 0; Title_End = 1;
							}
						}
					}
				}
			}
			else if (stage == 4) {
				DrawRotaGraph(330, 240, 1.0, 0.0, Image_TOHO[19], TRUE);
				/*if (Trans[3] > 250 && Title_End == 0) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, StageTitle);
					DrawStringToHandle(210, 190, "　  Stage4\nそして何よりも\n　 天狗の里", Black, kazufont[2]);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (StageTitle < 250 && Titlecon < 240) {
						StageTitle += 10; count[2] = 2;
						if (CheckSoundMem(BGM_TOHO[6]) == 0) PlaySoundMem(BGM_TOHO[6], DX_PLAYTYPE_LOOP);
					}
					else {
						Titlecon++; count[2] = 2;
						if (Titlecon >= 240) {
							if (StageTitle > 0) {
								StageTitle -= 10;
							}
							else {
								Titlecon = 0; Title_End = 1;
							}
						}
					}
				}*/
			}
			else if (stage == 5) {
				DrawRotaGraph(330, 240, 1.0, 0.0, Image_TOHO[26], TRUE);
				if (Trans[3] > 250 && Title_End == 0) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, StageTitle);
					DrawStringToHandle(185, 190, "　 　Stage5\n勉強は明るい場所で\n　　　竹林", Black, kazufont[2]);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (StageTitle < 250 && Titlecon < 240) {
						StageTitle += 10; count[2] = 2;
						if (CheckSoundMem(BGM_TOHO[7]) == 0) PlaySoundMem(BGM_TOHO[7], DX_PLAYTYPE_LOOP);
					}
					else {
						Titlecon++; count[2] = 2;
						if (Titlecon >= 240) {
							if (StageTitle > 0) {
								StageTitle -= 10;
							}
							else {
								Titlecon = 0; Title_End = 1;
							}
						}
					}
				}
			}
			else if (stage == 6) {
			DrawRotaGraph(330, 240, 1.0, 0.0, Image_TOHO[33], TRUE);
			if (Trans[3] > 250 && Title_End == 0) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, StageTitle);
				DrawStringToHandle(200, 190, "　　 Stage6\n新たなる道しるべ\n　　人間の里", Black, kazufont[2]);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (StageTitle < 250 && Titlecon < 240) {
					StageTitle += 10; count[2] = 2;
					if (CheckSoundMem(BGM_TOHO[9]) == 0) PlaySoundMem(BGM_TOHO[9], DX_PLAYTYPE_LOOP);
				}
				else {
					Titlecon++; count[2] = 2;
					if (Titlecon >= 240) {
						if (StageTitle > 0) {
							StageTitle -= 10;
						}
						else {
							Titlecon = 0; Title_End = 1;
						}
					}
				}
			}
			}
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			if (Trans[3] < 255 && boss_flag == 0 && bg_change == 0) Trans[3] += 5;
		}
		else if (boss_flag == 1) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, Trans[4]);
			if (stage == 1) DrawRotaGraph(330, 240, 1.0, 0.0, Image_TOHO[1], TRUE);
			else if (stage == 2) DrawRotaGraph(330, 240, 1.0, 0.0, Image_TOHO[7], TRUE);
			else if (stage == 3) DrawRotaGraph(330, 240, 1.0, 0.0, Image_TOHO[13], TRUE);
			else if (stage == 4) DrawRotaGraph(330, 240, 1.0, 0.0, Image_TOHO[20], TRUE);
			else if (stage == 5) DrawRotaGraph(330, 240, 1.0, 0.0, Image_TOHO[27], TRUE);
			else if (stage == 6) DrawRotaGraph(330, 240, 1.0, 0.0, Image_TOHO[34], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			if (Trans[4] < 255) Trans[4] += 5;
		}
		/*DrawFormatStringToHandle(10, 20, Red, kazufont[2], "%d", tyohuku.size());
		for (unsigned int i = 0; i < tyohuku.size(); i++) {
			DrawFormatStringToHandle(20 + (i * 30), 50, Red, kazufont[2], "%d", tyohuku[i]);
		}
		DrawFormatStringToHandle(10, 100, Red, kazufont[2], "RAND:%d", rand);
		DrawFormatStringToHandle(10, 200, Red, kazufont[2], "TUUKA:%d", tuuka);*/

		//ーーーーーーーーーーーーーーーーーーーー　ファイル読み込み　－－－－－－－－－－－－－－－－－－－－－－

		if (count[2] == 1) {
			if (CheckSoundMem(BGM_Name[0]) == 1) StopSoundMem(BGM_Name[0]);
			else if (CheckSoundMem(BGM_Name[4]) == 1) StopSoundMem(BGM_Name[4]);
			if (stage == 1) {
				ADV2_data = fopen("Data/ADV_1.txt", "r");
				TOHO_data = fopen("Data/TOHO_1B.txt", "r");
			}
			else if (stage == 2) {
				ADV2_data = fopen("Data/ADV_2.txt", "r");
				TOHO_data = fopen("Data/TOHO_2B.txt", "r");
			}
			else if (stage == 3) {
				ADV2_data = fopen("Data/ADV_3.txt", "r");
				TOHO_data = fopen("Data/TOHO_3B.txt", "r");
			}
			else if (stage == 4) {
				ADV2_data = fopen("Data/ADV_4.txt", "r");
				TOHO_data = fopen("Data/TOHO_4B.txt", "r");
			}
			else if (stage == 5) {
				ADV2_data = fopen("Data/ADV_5.txt", "r");
				TOHO_data = fopen("Data/TOHO_5B.txt", "r");
			}
			else if (stage == 6) {
				ADV2_data = fopen("Data/ADV_6.txt", "r");
				TOHO_data = fopen("Data/TOHO_6B.txt", "r");
			}
			if (ADV2_data == NULL || TOHO_data == NULL) {
				EndFlag = 1;
			}
			while ((buf1 = fgetc(ADV2_data)) != EOF) {
				str_adv.resize(ystr + 1); yomi_adv.resize(yomiY + 1);
				if (buf1 == '\n') {
					ystr++; yomiY++; str_switch = 0; buf_con = -1;
				}
				else if (buf1 == ':') {
					str_switch = 1; buf_con = -1;
				}
				else if (str_switch == 0) {
					if (buf_con == 0) str_adv[ystr] = buf1;
					else str_adv[ystr].push_back(buf1);
					//str_rd1[ystr] += buf2;
				}
				else if (str_switch == 1) {
					if (buf_con == 0) yomi_adv[yomiY] = buf1;
					else yomi_adv[yomiY].push_back(buf1);
				}
				buf_con++;

			}
			fclose(ADV2_data);

			while ((buf_boss = fgetc(TOHO_data)) != EOF) {
				str_boss.resize(ystr_B + 1); yomi_boss.resize(yomiY_B + 1);
				if (buf_boss == '\n') {
					ystr_B++; yomiY_B++; str_switch_B = 0; buf_con_B = -1;
				}
				else if (buf_boss == ':') {
					str_switch_B = 1; buf_con_B = -1;
				}
				else if (str_switch_B == 0) {
					if (buf_con_B == 0) str_boss[ystr_B] = buf_boss;
					else str_boss[ystr_B].push_back(buf_boss);
					//str_rd1[ystr] += buf2;
				}
				else if (str_switch_B == 1) {
					if (buf_con_B == 0) yomi_boss[yomiY_B] = buf_boss;
					else yomi_boss[yomiY_B].push_back(buf_boss);
				}
				buf_con_B++;
			}
			fclose(TOHO_data);
		}
		if (last_chaku == 1) {
			lastB_con++; count[2] = 2;
		}
		if (lastB_con >= 60) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, BG_Tra[3]);
			DrawRotaGraph(330, 240, 0.8, 0.0, Image_ADV[39], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			if (BG_Tra[3] < 255 && lastB_con < 180) BG_Tra[3] += 5;
			if (lastB_con >= 180) {
				sinkoudo++; count[2] = 2; boss_flag = 1;
				return_st = 0; clear_ones = 0; stop_flag = 0; bg_change = 0;
				if (BG_Tra[3] > 0) BG_Tra[3] -= 5;
				else {
					last_chaku = 0; lastB_con = 0;
				}
			}
		}
//ーーーーーーーーーーーーーーーーーーーーー　敵グラ表示　－－－－－－－－－－－－－－－－－－－－－－－

		else if (count[2] >= 90) {
			if (return_st == 1) {
				if (lastB_con == 0) {
					return_st = 0; clear_ones = 0; stop_flag = 0; bg_change = 0;
				}
			}
			if (stage == 1) {
				if (sinkoudo >= 3) boss_flag = 1;
				if (sinkoudo == 1) {
					if (count[2] == 90) enemy_hp = 3;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 230, 0.4, 0.0, Image_TOHO[2], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 230, 0.4, 0.0, Image_TOHO[2], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0 && clear_ones == 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 2) {
					if (count[2] == 90) enemy_hp = 4;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[3], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[3], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (boss_flag == 1) {
					if (count[2] == 90) enemy_hp = 6;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						/*if(boss_dispflag==1) */DrawRotaGraph(330, 220, 0.5, 0.0, Image_TOHO[4], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.5, 0.0, Image_TOHO[5], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
						end_talk = TalkTOHO(stage, 1);
						if (end_talk == 0) count[2] = 170;
						else count[2] = 120;
					}*/
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
					else if (CheckSoundMem(BGM_TOHO[0]) == 1) {
						StopSoundMem(BGM_TOHO[0]);
						if (CheckSoundMem(BGM_TOHO[1]) == 0) PlaySoundMem(BGM_TOHO[1], DX_PLAYTYPE_LOOP);
					}
				}
			}
			else if (stage == 2) {
				if (sinkoudo >= 3) boss_flag = 1;
				if (sinkoudo == 1) {
					if (count[2] == 90) enemy_hp = 3;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 230, 0.3, 0.0, Image_TOHO[8], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 230, 0.3, 0.0, Image_TOHO[8], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0 && clear_ones == 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 2) {
					if (count[2] == 90) enemy_hp = 4;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[9], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[9], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (boss_flag == 1) {
					if (count[2] == 90) enemy_hp = 8;
					if (CheckSoundMem(BGM_TOHO[2]) == 1) StopSoundMem(BGM_TOHO[2]);
					if (CheckSoundMem(BGM_TOHO[3]) == 0) PlaySoundMem(BGM_TOHO[3],DX_PLAYTYPE_LOOP);

					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						/*if (boss_dispflag == 1) */DrawRotaGraph(330, 220, 0.4, 0.0, Image_TOHO[10], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.4, 0.0, Image_TOHO[11], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
						end_talk = TalkTOHO(stage, 1);
						if (end_talk == 0) count[2] = 170;
						else count[2] = 120;
					}*/
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
			}
			else if (stage == 3) {
				if (sinkoudo >= 4) boss_flag = 1;
				if (sinkoudo == 1) {
					if (count[2] == 90) enemy_hp = 3;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 230, 0.4, 0.0, Image_TOHO[14], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 230, 0.4, 0.0, Image_TOHO[14], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0 && clear_ones == 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 2) {
					if (count[2] == 90) enemy_hp = 4;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[15], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[15], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (sinkoudo == 3) {
					if (count[2] == 90) enemy_hp = 4;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[16], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[16], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
				else if (boss_flag == 1) {
					if (count[2] == 90) enemy_hp = 10;
					if (CheckSoundMem(BGM_TOHO[4]) == 1) StopSoundMem(BGM_TOHO[4]);
					if (CheckSoundMem(BGM_TOHO[5]) == 0) PlaySoundMem(BGM_TOHO[5], DX_PLAYTYPE_LOOP);

					SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
					if (hit_flag == 0) {
						/*if (boss_dispflag == 1) */DrawRotaGraph(330, 220, 0.4, 0.0, Image_TOHO[17], TRUE);
					}
					else {
						if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.4, 0.0, Image_TOHO[18], TRUE);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
						end_talk = TalkTOHO(stage, 1);
						if (end_talk == 0) count[2] = 170;
						else count[2] = 120;
					}*/
					if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
				}
			}
			else if (stage == 4) {
			if (sinkoudo >= 5) boss_flag = 1;
			if (sinkoudo == 1) {
				if (count[2] == 90) enemy_hp = 3;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(EneX, EneY, 0.4, 0.0, Image_TOHO[24], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(EneX, EneY, 0.4, 0.0, Image_TOHO[25], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0 && clear_ones == 0) {
					Teki[stage - 1] += 5;
				}
				else {
					//if (CheckSoundMem(BGM_TOHO[5]) == 1) StopSoundMem(BGM_TOHO[5]);
					//if (CheckSoundMem(BGM_TOHO[3]) == 0) PlaySoundMem(BGM_TOHO[3], DX_PLAYTYPE_LOOP);
					if (CheckSoundMem(BGM_TOHO[6]) == 0) PlaySoundMem(BGM_TOHO[6], DX_PLAYTYPE_LOOP);
				}
			}
			else if (sinkoudo == 2) {
				if (count[2] == 90) enemy_hp = 3;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[21], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[21], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
			}
			else if (sinkoudo == 3) {
				if (count[2] == 90) enemy_hp = 4;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[22], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[22], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
			}
			else if (sinkoudo == 4) {
				if (count[2] == 90) enemy_hp = 5;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[23], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[23], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
			}
			else if (boss_flag == 1) {
				if (count[2] == 90) enemy_hp = 14;
				//if (CheckSoundMem(BGM_TOHO[4]) == 1) StopSoundMem(BGM_TOHO[4]);
				//if (CheckSoundMem(BGM_TOHO[5]) == 0) PlaySoundMem(BGM_TOHO[5], DX_PLAYTYPE_LOOP);

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					/*if (boss_dispflag == 1) */DrawRotaGraph(330, 220, 0.4, 0.0, Image_TOHO[24], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.4, 0.0, Image_TOHO[25], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
					end_talk = TalkTOHO(stage, 1);
					if (end_talk == 0) count[2] = 170;
					else count[2] = 120;
				}*/
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
			}
			}
			else if (stage == 5) {
			if (sinkoudo >= 5) boss_flag = 1;
			if (sinkoudo == 1) {
				if (count[2] == 90) enemy_hp = 3;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(330, 230, 0.3, 0.0, Image_TOHO[28], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 230, 0.3, 0.0, Image_TOHO[28], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0 && clear_ones == 0) Teki[stage - 1] += 5;
			}
			else if (sinkoudo == 2) {
				if (count[2] == 90) enemy_hp = 3;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[29], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[29], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
			}
			else if (sinkoudo == 3) {
				if (count[2] == 90) enemy_hp = 4;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[30], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.3, 0.0, Image_TOHO[30], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
			}
			else if (sinkoudo == 4) {
				if (count[2] == 90) enemy_hp = 6;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(EneX, EneY, 0.4, 0.0, Image_TOHO[31], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(EneX, EneY, 0.4, 0.0, Image_TOHO[32], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
			}
			else if (boss_flag == 1) {
				if (count[2] == 90) enemy_hp = 17;
				if (CheckSoundMem(BGM_TOHO[7]) == 1) StopSoundMem(BGM_TOHO[7]);
				if (CheckSoundMem(BGM_TOHO[8]) == 0) PlaySoundMem(BGM_TOHO[8], DX_PLAYTYPE_LOOP);

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					/*if (boss_dispflag == 1) */DrawRotaGraph(330, 220, 0.4, 0.0, Image_TOHO[31], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.4, 0.0, Image_TOHO[32], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
					end_talk = TalkTOHO(stage, 1);
					if (end_talk == 0) count[2] = 170;
					else count[2] = 120;
				}*/
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
			}
			}
			else if (stage == 6) {
			if (sinkoudo >= 3) boss_flag = 1;
			if (sinkoudo == 1) {
				if (count[2] == 90) enemy_hp = 6;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(330, 230, 0.3, 0.0, Image_TOHO[35], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 230, 0.3, 0.0, Image_TOHO[35], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0 && clear_ones == 0) Teki[stage - 1] += 5;
			}
			else if (sinkoudo == 2) {
				if (count[2] == 90) enemy_hp = 6;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					DrawRotaGraph(330, 220, 0.4, 0.0, Image_TOHO[31], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.4, 0.0, Image_TOHO[32], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
			}
			else if (boss_flag == 1) {
				if (count[2] == 90) enemy_hp = 27;
				if (CheckSoundMem(BGM_TOHO[9]) == 1) StopSoundMem(BGM_TOHO[9]);
				if (CheckSoundMem(BGM_TOHO[10]) == 0) PlaySoundMem(BGM_TOHO[10], DX_PLAYTYPE_LOOP);

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Teki[stage - 1]);
				if (hit_flag == 0) {
					/*if (boss_dispflag == 1) */DrawRotaGraph(330, 220, 0.4, 0.0, Image_TOHO[36], TRUE);
				}
				else {
					if (count[2] % 5 == 0) DrawRotaGraph(330, 220, 0.4, 0.0, Image_TOHO[37], TRUE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				/*if (end_talk == 0 && count[2] >= 170 && count[2] < 180) {
					end_talk = TalkTOHO(stage, 1);
					if (end_talk == 0) count[2] = 170;
					else count[2] = 120;
				}*/
				if (Teki[stage - 1] < 255 && enemy_hp != 0) Teki[stage - 1] += 5;
			}
			}

		}
		if (count[2] == 180) {
			Input = MakeKeyInput(128, FALSE, FALSE, FALSE);
			Deput = MakeKeyInput(128, FALSE, FALSE, FALSE);
			SetActiveKeyInput(Input); end_talk = 0;

			SetKeyInputStringColor(Black,0,White,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		}
//ーーーーーーーーーーーーーーーーーーーーー　戦闘開始　－－－－－－－－－－－－－－－－－－－－－－

		else if (count[2] > 180) {
			if (stop_flag == 0) {
				ans_con++;
				if (ADV_OneTime == 0) {
					if (boss_flag == 0) {
						rand = (int)GetRand(ystr - 1);
						while (daburi_flag == 0) {
							for (unsigned int i = 0; i < tyohuku.size(); i++) {
								if (tyohuku[i] == rand) {
									daburi_flag = 0;
									kaburi_suu++;
								}

							}
							if (kaburi_suu >= 1) {
								rand = (int)GetRand(ystr - 1); kaburi_suu = 0;
							}
							else {
								daburi_flag = 1; kaburi_suu = 0;
							}
						}
					}
					else if (boss_flag == 1) {
						rand = (int)GetRand(ystr_B - 1);
						while (daburi_flag == 0) {
							for (unsigned int i = 0; i < tyohuku_B.size(); i++) {
								if (tyohuku_B[i] == rand) {
									daburi_flag = 0;
									kaburi_suu++;
								}

							}
							if (kaburi_suu >= 1) {
								rand = (int)GetRand(ystr_B - 1); kaburi_suu = 0;
							}
							else {
								daburi_flag = 1; kaburi_suu = 0;
							}
						}
					}
					ADV_OneTime = 1; down = 15; gard = 0;
					if (CheckSoundMem(SE_Name[2]) == 0) PlaySoundMem(SE_Name[2], DX_PLAYTYPE_BACK);
				}
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
				if (boss_flag == 0) {
					for (unsigned int j = 0; j < str_adv[rand].size() / 2; j++) {
						if ((str_adv[rand].size() / 2) >= 4) DrawBox(200 + (j * 40), 320, 240 + (j * 40), 360, White, TRUE);
						else DrawBox(300 + (j * 40), 320, 340 + (j * 40), 360, White, TRUE);
					}
				}
				else if (boss_flag == 1) {
					for (unsigned int j = 0; j < str_boss[rand].size() / 2; j++) {
						if ((str_boss[rand].size() / 2) >= 4) DrawBox(200 + (j * 40), 320, 240 + (j * 40), 360, White, TRUE);
						else DrawBox(300 + (j * 40), 320, 340 + (j * 40), 360, White, TRUE);
					}
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (boss_flag == 0) {
					if ((str_adv[rand].size() / 2) >= 4) DrawFormatStringToHandle(200, 320, Black, kazufont[1], "%s", str_adv[rand].c_str());
					else DrawFormatStringToHandle(300, 320, Black, kazufont[1], "%s", str_adv[rand].c_str());
				}
				else if (boss_flag == 1) {
					if ((str_boss[rand].size() / 2) >= 4) DrawFormatStringToHandle(200, 320, Black, kazufont[1], "%s", str_boss[rand].c_str());
					else DrawFormatStringToHandle(300, 320, Black, kazufont[1], "%s", str_boss[rand].c_str());
				}

				if (key_flag == 0)	DrawKeyInputString(100, 400, Input);
				if (CheckKeyInput(Input) == 1 && key_flag == 0) {
					enter_flag = 1; key_flag = 1;
				}
				if (CheckHitKey(KEY_INPUT_RETURN) == 0) {
					key_flag = 0;
				}

				if (enter_flag == 1) {
					entercount++;
					if (entercount == 1) {
						GetKeyInputString(St_RD1, Input);
						if (CheckSoundMem(SE_Name[3]) == 0) PlaySoundMem(SE_Name[3], DX_PLAYTYPE_BACK);
						if (boss_flag == 0) {
							if (strcmp(yomi_adv[rand].c_str(), St_RD1) == 0) {
								setAnswer = 1;
							}
							else {
								setAnswer = 0;
							}
						}
						if (boss_flag == 1) {
							if (strcmp(yomi_boss[rand].c_str(), St_RD1) == 0) {
								setAnswer = 1;
							}
							else {
								setAnswer = 0;
							}
						}
					}
					if (InpX < 300 && entercount < 30) {
						InpX += 5;
					}
					if (InpY > 250 && entercount < 30) {
						InpY -= 5;
					}
					DrawFormatStringToHandle(InpX, InpY, Red, kazufont[1], "%s", St_RD1);
					if (entercount == 30) {
						if (setAnswer == 1) {
							PlaySoundMem(SE_Name[4], DX_PLAYTYPE_BACK);
							hit_flag = 1; gard = 1;
						}
						else {
							PlaySoundMem(SE_Name[5], DX_PLAYTYPE_BACK);
						}
						SetActiveKeyInput(Input);
						InpX = 100; InpY = 400;
						SetKeyInputString("", Input);
						enter_flag = 0; entercount = 0;
					}
				}
//ーーーーーーーーーーーーーーーーーーーーー　カウントダウン　－－－－－－－－－－－－－－－－－－－－－－

				DrawFormatStringToHandle(300, 60, Red, kazufont[1], "%d", down);
				if (ans_con % 55 == 0 && enter_flag == 0 && down > 0 && stop_flag == 0) {
					down--;
				}
				if (down == 0) {
					if (enter_flag != 1 && gard == 0) gameover = 1;
				}
//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー
				if (hit_flag == 1) {
					hit_con++;
					if (hit_con == 40) {
						ADV_OneTime = 0;
						hit_flag = 0; hit_con = 0;
						enemy_hp--; daburi_flag = 0;
						if (boss_flag == 0) tyohuku.push_back(rand);
						else if (boss_flag == 1) tyohuku_B.push_back(rand);
						//if(enemy_hp!=0) PlaySoundMem(SE_Name[7], DX_PLAYTYPE_BACK);
					}
				}
			}
			if (enemy_hp == 0) {
				//clear_flag = 1;
				if (boss_flag == 1) clear_flag = 1;
				if (clear_ones == 0) {
					clear_ones = 1;
					stop_flag = 1;
					if ((stage == 5 && sinkoudo == 4) || (stage==4 && sinkoudo==1)) {
						/*if (end_talk == 0) {
							end_talk = TalkTOHO(stage, 2);
							if (end_talk == 0) clear_ones = 0;
							else clear_ones = 1;
						}*/
					}
					else {
						if (CheckSoundMem(SE_Name[6]) == 0) PlaySoundMem(SE_Name[6], DX_PLAYTYPE_BACK);
					}
				}
				if (Teki[stage - 1] > 0 && clear_ones == 1) {
					Teki[stage - 1] -= 5;
					if (stage == 4 && sinkoudo == 1) {
						if (EneX > -100) EneX -= 15;
						if (EneY > 200) EneY -= 2;
						if (Teki[stage - 1] < 10 && Title_End == 0) {
							SetDrawBlendMode(DX_BLENDMODE_ALPHA, StageTitle);
							DrawStringToHandle(210, 190, "　  Stage4\nそして何よりも\n　 天狗の里", Black, kazufont[2]);
							SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
							if (StageTitle < 250 && Titlecon < 240) {
								StageTitle += 10; Teki[stage - 1] = 5;
								//if (CheckSoundMem(BGM_ADV[4]) == 0) PlaySoundMem(BGM_ADV[4], DX_PLAYTYPE_LOOP);
							}
							else {
								Titlecon++; Teki[stage - 1] = 5;
								if (Titlecon >= 240) {
									if (StageTitle > 0) {
										StageTitle -= 10;
									}
									else {
										Titlecon = 0; Title_End = 1;
									}
								}
							}
						}
					}
					else if (stage == 5 && sinkoudo == 4) {
						if (EneX > -100) EneX -= 10;
						if (EneY > 200) EneY -= 2;
					}
				}
				else if (clear_ones == 1) {
					if (boss_flag == 0) {
						if (stage == 1 || stage == 2 || stage == 3 || stage==4 || stage==5) {
							sinkoudo++; count[2] = 2; return_st = 1;
						}
						else if (stage == 6) {
							/*if (sinkoudo == 3) {
								bg_change = 1;
								if (Trans[3] > 0) Trans[3] -= 5;
								else {
									sinkoudo++; count[2] = 2; return_st = 1;
								}
							}*/
							if (sinkoudo == 2) {
								last_chaku = 1;
							}
							else {
								sinkoudo++; count[2] = 2; return_st = 1;
							}
						}
					}
				}
			}
			if (clear_flag == 1) {
				static int clear_con = 0;
				stop_flag = 1;
				/*
				if (end_talk == 0 && clear_con >= 60 && clear_con < 70) {
					end_talk = TalkTOHO(stage, 10);
					if (end_talk == 0) clear_con = 60;
					else clear_con = 10;

				}*/
				if (clear_con >= 120) {
					if (stage != 6) DrawRotaGraph(320, 240, 1.0, 0.0, Image_Dan1[2], TRUE);
					else DrawRotaGraph(320, 240, 1.0, 0.0, Image_ADV[5], TRUE);

					if(stage<4) ChangeVolumeSoundMem(Volume, BGM_TOHO[(stage * 2) - 1]);
					else ChangeVolumeSoundMem(Volume, BGM_TOHO[(stage * 2) - 2]);
					if (Volume > 0) {
						Volume--;
					}

				}
				if (clear_con == 420) {
					if (stage == 6) {
						clear_con = 0; clear_flag = 0; clear_ones = 0;
						Trans[4] = 0; count[2] = 0; ADV_OneTime = 0; Trans[3] = 0;
						for (unsigned int i = 0; i < str_adv.size();) {
							str_adv.pop_back();
						}
						for (unsigned int i = 0; i < yomi_adv.size();) {
							yomi_adv.pop_back();
						}
						for (unsigned int i = 0; i < tyohuku.size();) {
							tyohuku.pop_back();
						}
						for (unsigned int i = 0; i < str_boss.size();) {
							str_boss.pop_back();
						}
						for (unsigned int i = 0; i < yomi_boss.size();) {
							yomi_boss.pop_back();
						}
						for (unsigned int i = 0; i < tyohuku_B.size();) {
							tyohuku_B.pop_back();
						}
						ystr = 0; yomiY = 0; str_switch = 0; buf_con = 0; rand = 0;
						ystr_B = 0; yomiY_B = 0; str_switch_B = 0; buf_con_B = 0;
						//static char St_RD1[256];
						Input = 0; Deput = 0; enter_flag = 0; entercount = 0; setAnswer = 0; hit_flag = 0; hit_con = 0;
						InpX = 100; InpY = 400; stop_flag = 0; change_sw = 1; EneX = 330; EneY = 200;
						enemy_hp = 3; scene = 0; randbgm_Title = (int)GetRand(1); end_talk = 0; talk_flag = 0;
						Teki[0] = 0; return_st = 0; sinkoudo = 1; start_flag = 0; boss_flag = 0;
						stage = 7; Title_End = 0; Volume = 255;
						boss_dispflag = 0;
						if (CheckSoundMem(BGM_TOHO[10]) == 1) StopSoundMem(BGM_TOHO[10]);

						std::string Temp_Kousin;
						StarFlag[2] = 1;
						Star_kousin = fopen("Save/Star.txt", "w");
						if (Star_kousin == NULL) {
							EndFlag = 1;
						}
						for (int i = 0; i < 5; i++) {
							Temp_Kousin += (char)(StarFlag[i] + '0');
						}
						fprintf(Star_kousin, "%s", Temp_Kousin.c_str());
						fclose(Star_kousin);
						//allclear = 1;
						//Clear_data = fopen("Save/RD_Ex.txt", "w");
						//fprintf(Clear_data, "%d", allclear);
						//fclose(Clear_data);

					}
					else {
						stage++;
						clear_con = 0; clear_flag = 0; clear_ones = 0;
						Trans[4] = 0; count[2] = 0; ADV_OneTime = 0; Trans[3] = 0;
						for (unsigned int i = 0; i < str_adv.size();) {
							str_adv.pop_back();
						}
						for (unsigned int i = 0; i < yomi_adv.size();) {
							yomi_adv.pop_back();
						}
						for (unsigned int i = 0; i < tyohuku.size();) {
							tyohuku.pop_back();
						}
						for (unsigned int i = 0; i < str_boss.size();) {
							str_boss.pop_back();
						}
						for (unsigned int i = 0; i < yomi_boss.size();) {
							yomi_boss.pop_back();
						}
						for (unsigned int i = 0; i < tyohuku_B.size();) {
							tyohuku_B.pop_back();
						}
						ystr = 0; yomiY = 0; str_switch = 0; buf_con = 0; rand = 0;
						ystr_B = 0; yomiY_B = 0; str_switch_B = 0; buf_con_B = 0;
						//static char St_RD1[256];
						boss_dispflag = 0; Title_End = 0; Volume = 255;
						Input = 0; Deput = 0; enter_flag = 0; entercount = 0; setAnswer = 0; hit_flag = 0; hit_con = 0;
						InpX = 100; InpY = 400; stop_flag = 0; change_sw = 1;
						enemy_hp = 3; EneX = 330; EneY = 200; end_talk = 0; talk_flag = 0;
						Teki[0] = 0; return_st = 0; sinkoudo = 1; start_flag = 1; boss_flag = 0;
					}
				}
				clear_con++;
			}
			if (gameover == 1) {
				over_con++; stop_flag = 1;
				SetActiveKeyInput(Deput);
				if (over_con == 1) {
					zanki--;
					PlaySoundMem(SE_Name[8], DX_PLAYTYPE_BACK);
				}
			}
			if (zanki <= 0) {
				if (over_con > 180) {
					DrawRotaGraph(320, 240, 1.0, 0.0, Image_Dan1[3], TRUE);

					if (boss_flag == 0) {
						for (unsigned int j = 0; j < (yomi_adv[rand].size() / 2) + 3; j++) {
							DrawBox(100 + (j * 40), 300, 240 + (j * 40), 340, White, TRUE);
						}
					}
					else if (boss_flag == 1) {
						for (unsigned int j = 0; j < (yomi_boss[rand].size() / 2) + 3; j++) {
							DrawBox(100 + (j * 40), 300, 240 + (j * 40), 340, White, TRUE);
						}
					}
					if (boss_flag == 0) DrawFormatStringToHandle(100, 300, Black, kazufont[1], "答え：%s", yomi_adv[rand].c_str());
					else if (boss_flag == 1) DrawFormatStringToHandle(100, 300, Black, kazufont[1], "答え：%s", yomi_boss[rand].c_str());
				}
				if (over_con == 480) {
					over_con = 0; gameover = 0; zanki = 0;
					Trans[4] = 0; count[2] = 0; ADV_OneTime = 0; Trans[3] = 0;
					for (unsigned int i = 0; i < str_adv.size();) {
						str_adv.pop_back();
					}
					for (unsigned int i = 0; i < yomi_adv.size();) {
						yomi_adv.pop_back();
					}
					for (unsigned int i = 0; i < tyohuku.size();) {
						tyohuku.pop_back();
					}
					for (unsigned int i = 0; i < str_boss.size();) {
						str_boss.pop_back();
					}
					for (unsigned int i = 0; i < yomi_boss.size();) {
						yomi_boss.pop_back();
					}
					for (unsigned int i = 0; i < tyohuku_B.size();) {
						tyohuku_B.pop_back();
					}
					ystr = 0; yomiY = 0; str_switch = 0; buf_con = 0; rand = 0;
					ystr_B = 0; yomiY_B = 0; str_switch_B = 0; buf_con_B = 0;
					//static char St_RD1[256];
					boss_dispflag = 0; Title_End = 0;
					Input = 0; Deput = 0; enter_flag = 0; entercount = 0; setAnswer = 0; hit_flag = 0; hit_con = 0;
					InpX = 100; InpY = 400; stop_flag = 0; change_sw = 1; EneX = 330; EneY = 200;
					enemy_hp = 3; scene = 0; randbgm_Title = (int)GetRand(1); end_talk = 0; talk_flag = 0;
					stage = 7; Teki[0] = 0; start_flag = 0; return_st = 0; sinkoudo = 1; boss_flag = 0;
					for (int i = 0; i < 11; i++) {
						if (CheckSoundMem(BGM_TOHO[i]) == 1) StopSoundMem(BGM_TOHO[i]);
					}
				}
			}
			else {
				if (over_con > 120) {
					if (change_sw == 1 && team == 1) DrawRotaGraph(320, 240, 0.8, 0.0, Image_Dan1[4], TRUE);
					if (over_con % 30 == 0) change_sw *= -1;
					DrawFormatStringToHandle(180, 350, Green, kazufont[1], "Enterで再挑戦");

					if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
						over_con = 0; gameover = 0; stop_flag = 0; down = 10; key_flag = 1;
						SetActiveKeyInput(Input);
						if (team == 0) {
							daburi_flag = 0; ADV_OneTime = 0;
							if (boss_flag == 0) tyohuku.push_back(rand);
							else if (boss_flag == 1) tyohuku_B.push_back(rand);
						}
					}
				}
			}
		}
	}
//ーーーーーーーーーーーーーーーーーーーー　StartFlag終わり　－－－－－－－－－－－－－－－－－－－－－－
}

//ーーーーーーーーーーーーーーーーーーーーーー　リードダンジョン選択　－－－－－－－－－－－－－－－－－－－－－－

void ReadSelect() {

	static int RD_se = 1;
	static int grd_flag = 0, grd_se = 1;

	if (RD_se >= 5 && RD_se<100) RD_se = 1;
	else if (RD_se <= 0) RD_se = 4;

	if (RD_se==1 || RD_se == 101) {
		DrawRotaGraph(330,240,0.8,0.0,Image_RDSE[1],TRUE);
		DrawRotaGraph(330, 150, 0.6, 0.0, Image_RDSE[0], TRUE);
		DrawRotaGraph(600, 150, 0.4, 0.0, Image_RDSE[2], TRUE);
		DrawRotaGraph(80, 150, 0.4, 0.0, Image_RDSE[6], TRUE);
		DrawStringToHandle(500, 400, "もどる", White, modefont);
		DrawStringToHandle(20, 250, "とりあえず遊んでみる場合にオススメ(5問)", Black, kazufont[2]);
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag==0 && RD_se==1) {
			RD_se = 1; key_flag = 1;
			scene = 3;
		}
	}
	else if (RD_se == 2 || RD_se == 102) {
		DrawRotaGraph(330, 240, 0.8, 0.0, Image_RDSE[3], TRUE);
		DrawRotaGraph(330, 150, 0.7, 0.0, Image_RDSE[2], TRUE);
		DrawRotaGraph(600, 150, 0.4, 0.0, Image_RDSE[4], TRUE);
		DrawRotaGraph(60, 150, 0.4, 0.0, Image_RDSE[0], TRUE);
		DrawStringToHandle(500, 400, "もどる", White, modefont);
		DrawStringToHandle(40, 250, "冒険に出て、現れる敵を次々と倒すモード\n途中で戻れないのでご注意ください\n(全６ステージ、全９０問)", White, kazufont[2]);
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0 && RD_se == 2) {
			RD_se = 1; key_flag = 1;
			scene = 6;
		}
	}
	else if (RD_se == 3 || RD_se == 103) {
		DrawRotaGraph(330, 240, 0.8, 0.0, Image_RDSE[5], TRUE);
		if (grd_flag == 0) {
			DrawRotaGraph(330, 150, 0.7, 0.0, Image_RDSE[4], TRUE);
			DrawRotaGraph(600, 150, 0.4, 0.0, Image_RDSE[6], TRUE);
			DrawRotaGraph(60, 150, 0.4, 0.0, Image_RDSE[2], TRUE);

			DrawStringToHandle(10,250,"小学生の場合、学年別に問題を遊べる(10問)",Black,kazufont[2]);
		}
		if (grd_flag == 1) {
			//DrawStringToHandle(100, 200, "学年を選んでね", White, modefont);
			if(grd_se==1) DrawStringToHandle(50, 100, "1年生", Red, kazufont[1]);
			else DrawStringToHandle(50, 100, "1年生", White, kazufont[1]);
			if(grd_se==2) DrawStringToHandle(50, 200, "2年生", Red, kazufont[1]);
			else DrawStringToHandle(50, 200, "2年生", White, kazufont[1]);
			if(grd_se==3) DrawStringToHandle(50, 300, "3年生", Red, kazufont[1]);
			else DrawStringToHandle(50, 300, "3年生", White, kazufont[1]);
			if(grd_se==4) DrawStringToHandle(50, 400, "4年生", Red, kazufont[1]);
			else DrawStringToHandle(50, 400, "4年生", White, kazufont[1]);
			if(grd_se==11) DrawStringToHandle(200, 100, "5年生", Red, kazufont[1]);
			else DrawStringToHandle(200, 100, "5年生", White, kazufont[1]);
			if(grd_se==12) DrawStringToHandle(200, 200, "6年生", Red, kazufont[1]);
			else DrawStringToHandle(200, 200, "6年生", White, kazufont[1]);
			if(grd_se==13) DrawStringToHandle(200, 300, "それ以上", Red, kazufont[1]);
			else DrawStringToHandle(200, 300, "それ以上", White, kazufont[1]);
			if (grd_se >= 20) {
				DrawStringToHandle(500, 400, "もどる", Red, modefont);
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0 && RD_se == 3) {
					RD_se = 3; key_flag = 1; grd_se = 1; grd_flag = 0;
				}
			}
			else {
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0 && RD_se == 3) {
					scene = 5; select_class = grd_se;
					RD_se = 1; key_flag = 1; grd_se = 1; grd_flag = 0;
				}
			}
		}
		if(grd_se<20)
		DrawStringToHandle(500, 400, "もどる", White, modefont);
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0 && RD_se == 3) {
			key_flag = 1; grd_flag = 1;
			//scene = 3;
		}
	}
	else if(RD_se == 4 || RD_se==104) {
		DrawRotaGraph(330, 240, 0.8, 0.0, Image_RDSE[7], TRUE);
		DrawRotaGraph(330, 150, 0.7, 0.0, Image_RDSE[6], TRUE);
		DrawRotaGraph(600, 150, 0.4, 0.0, Image_RDSE[0], TRUE);
		DrawRotaGraph(60, 150, 0.4, 0.0, Image_RDSE[4], TRUE);
		DrawStringToHandle(500, 400, "もどる", White, modefont);
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag == 0 && RD_se == 4) {
			RD_se = 1; key_flag = 1;
			scene = 8;
		}
		DrawStringToHandle(30, 220, "『東方Project』のキャラクター達で行う\n全６ステージのアドベンチャー(全150問)", White, kazufont[2]);
		//DrawStringToHandle(240, 330, "明日実装！", Red, modefont);
	}
	if (RD_se > 100) {
		DrawStringToHandle(500, 400, "もどる", Red, modefont);
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 && key_flag==0) {
			RD_se = 1; key_flag = 1;
			scene = 0;
		}
	}
	if (grd_flag == 0) {
		DrawStringToHandle(150, 50, "矢印、十字キーで選択", Red, kazufont[2]);
	}
	else if (grd_flag == 1) {
		DrawStringToHandle(150, 50, "学年を選んでね", Red, kazufont[2]);
	}

//ーーーーーーーーーーーーーーーーーーー　キー入力　－－－－－－－－－－－－－－－－－－－－－－－－－
	if (grd_flag == 0) {
		if (CheckHitKey(KEY_INPUT_DOWN) == 1 && key_flag == 0 && RD_se < 100) {
			RD_se += 100;
			key_flag = 1;
		}
		else if (CheckHitKey(KEY_INPUT_UP) == 1 && key_flag == 0 && RD_se > 100) {
			RD_se -= 100; key_flag = 1;
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && key_flag == 0 && RD_se < 100) {
			RD_se++; key_flag = 1;
		}
		else if (CheckHitKey(KEY_INPUT_LEFT) == 1 && RD_se < 100 && key_flag == 0) {
			RD_se--; key_flag = 1;
		}
	}
	else if (grd_flag == 1) {

		if (CheckHitKey(KEY_INPUT_DOWN) == 1 && key_flag == 0 && grd_se < 20) {
			grd_se++;
			key_flag = 1;
		}
		else if (CheckHitKey(KEY_INPUT_UP) == 1 && key_flag == 0 && grd_se <20) {
			grd_se--; key_flag = 1;
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && key_flag == 0 && grd_se < 20) {
			grd_se+=10; key_flag = 1;
		}
		else if (CheckHitKey(KEY_INPUT_LEFT) == 1 && grd_se > 10 && key_flag == 0) {
			grd_se-=10; key_flag = 1;
		}
		if (grd_se >= 5 && grd_se < 10) grd_se = 4;
		else if (grd_se <= 0 && grd_se < 10) grd_se = 1;
		else if (grd_se >= 14 && grd_se < 20) grd_se = 13;
		else if (grd_se <11 && grd_se < 20 && grd_se>5) grd_se = 11;
	}
	if (CheckHitKey(KEY_INPUT_RETURN) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0 && CheckHitKey(KEY_INPUT_UP) == 0
		&& CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0) {
		key_flag = 0;
	}


}


//ーーーーーーーーーーーーーーーーーーーーーー　WinMain　－－－－－－－－－－－－－－－－－－－－－－－//

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int hidouki_sousuu = 0,load_end=0,setL[25],count_Ones=0;

	Init();
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetUseASyncLoadFlag(TRUE);
	GraphLoad();
	//SetUseASyncLoadFlag(FALSE);

	SetOutApplicationLogValidFlag(TRUE);
	SetAlwaysRunFlag(TRUE);
	SetMainWindowText("マ～ナビィナ");

	randbgm_Title = (int)GetRand(1);
	hidouki_sousuu = GetASyncLoadNum();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		//この中にゲーム部分を記述

		if (GetASyncLoadNum() >= 1) {
			scene = 99;
			DrawString(150, 400,"よみこみ中…",White);
			DrawBox(300, 390, 300 + (hidouki_sousuu), 410, White, FALSE);
			/*for (int i = 0; i < hidouki_sousuu; i++) {
				DrawBox(200, 390, 200 + (hidouki_sousuu), 410, White,FALSE);
			}*/
			for (int j = 0; j < (hidouki_sousuu - GetASyncLoadNum());j++) {
				DrawLine(300+(j), 390, 300 + (j), 410, Green);
			}
		}
		else if(load_end==0 && GetASyncLoadNum()==0){
			if (count_Ones == 0) {
				setL[0] = SetLoopPosSoundMem(12150, BGM_Name[0]);
				//if (setL[0] == -1) EndFlag = 1;
				setL[1] = SetLoopPosSoundMem(34400, BGM_ADV[3]);
				//if (setL[1] == -1) EndFlag = 1;
				setL[2] = SetLoopPosSoundMem(5584, BGM_ADV[5]);
				//if (setL[2] == -1) EndFlag = 1;
				setL[3] = SetLoopPosSoundMem(21660, BGM_ADV[6]);
				//if (setL[3] == -1) EndFlag = 1;
				setL[4] = SetLoopPosSoundMem(26343, BGM_ADV[7]);
				//if (setL[4] == -1) EndFlag = 1;
				setL[5] = SetLoopPosSoundMem(2252, BGM_ADV[8]);
				//if (setL[5] == -1) EndFlag = 1;
				setL[6] = SetLoopPosSoundMem(1700, BGM_ADV[9]);
				//if (setL[6] == -1) EndFlag = 1;
				setL[7] = SetLoopPosSoundMem(11750, BGM_ADV[10]);
				//if (setL[7] == -1) EndFlag = 1;
				setL[8] = SetLoopPosSoundMem(22550, BGM_ADV[11]);
				//if (setL[8] == -1) EndFlag = 1;
				setL[9] = SetLoopPosSoundMem(34210, BGM_ADV[13]);
				//if (setL[9] == -1) EndFlag = 1;

				setL[10] = SetLoopPosSoundMem(8240, BGM_TOHO[0]);
				//if (setL[10] == -1) EndFlag = 1;
				setL[11] = SetLoopPosSoundMem(6380, BGM_TOHO[1]);
				//if (setL[11] == -1) EndFlag = 1;
				setL[12] = SetLoopPosSoundMem(39300, BGM_TOHO[2]);
				//if (setL[12] == -1) EndFlag = 1;
				setL[13] = SetLoopPosSoundMem(39100, BGM_TOHO[3]);
				//if (setL[13] == -1) EndFlag = 1;
				setL[14] = SetLoopPosSoundMem(12760, BGM_TOHO[4]);
				//if (setL[14] == -1) EndFlag = 1;
				setL[15] = SetLoopPosSoundMem(7100, BGM_TOHO[5]);
				//if (setL[15] == -1) EndFlag = 1;
				setL[16] = SetLoopPosSoundMem(19180, BGM_TOHO[6]);
				//if (setL[16] == -1) EndFlag = 1;
				setL[17] = SetLoopPosSoundMem(17900, BGM_TOHO[7]);
				//if (setL[17] == -1) EndFlag = 1;
				setL[18] = SetLoopPosSoundMem(7730, BGM_TOHO[8]);
				//if (setL[18] == -1) EndFlag = 1;
				setL[19] = SetLoopPosSoundMem(7985, BGM_TOHO[9]);
				//if (setL[19] == -1) EndFlag = 1;
				setL[20] = SetLoopPosSoundMem(32800, BGM_TOHO[10]);
				//if (setL[20] == -1) EndFlag = 1;
				setL[21] = SetLoopPosSoundMem(301, BGM_RD[2]);
				setL[22] = SetLoopPosSoundMem(3720, BGM_RD[0]);
			}

			count_Ones = 1;
			scene = 0; load_end = 1;
		}

		switch (scene) {
		case 0:
			count[0]++;
			Title();
			break;
		case 1:
			SelectMode();
			break;
		case 2:
			count[1]++;
			Kazuitti();
			break;
		case 3:
			count[2]++;
			ReadDan_1();
			break;
		case 4:
			ReadSelect();
			break;
		case 5:
			count[2]++;
			GrdClass();
			break;
		case 6:
			ADV();
			break;
		case 7:
			ADV_EX();
			break;
		case 8:
			TOHO_Zen();
			break;
		case 9:
			TOHO();
			break;
		case 20:
			Star();
			break;
		default:
			break;
		}
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			ProgEnd();
			break;
		}
		if (EndFlag == 1) {
			ProgEnd();
			break;
		}
	}
	ProgEnd();
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}