#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <conio.h>

#define FIELD_WIDTH 10
#define FIELD_HEIGHT 20

#define SHAPE_WIDTH_MAX 4
#define SHAPE_HEIGHT_MAX 4

#define FPS			 1
#define INTERVAL	(1000 / FPS)

//消したラインの数
int count = 0;

//ミノの形状を定義する
enum {
	SHAPE_I,
	SHARP_O,
	SHARP_S,
	SHAPE_Z,
	SHAPE_J,
	SHAPE_L,
	SHAPE_T,
	SHAPE_MAX
};

typedef struct {
	int width, height;
	int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
} SHAPE;

typedef struct {
	int x, y;
	SHAPE shape;
} MINO;

SHAPE shapes[SHAPE_MAX] = {
	//SHAPE_I,
	{
		4,4,//int width, height;
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		}
	},
	//SHARP_O,
	{
		2,2,//int width, height;
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{1,1},
			{1, 1},
		}
	},
//SHARP_S,
	{
	3,3,//int width, height;
	//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0, 1, 1},
			{1, 1, 0},
			{0, 0, 0}
		}
	},
//SHAPE_Z,
	{
	3,3,//int width, height;
	//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{1, 1, 0},
			{0, 1, 1},
			{0, 0, 0}
		}
	},
	//SHAPE_J,
	{
	3,3,//int width, height;
	//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{1, 0, 0},
			{1, 1, 1},
			{0, 0, 0}
		}
	},
	//SHAPE_L,
	{
		3,3,//int width, height;
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0, 1, 1},
			{1, 1, 0},
			{0, 0, 0}
		}
	},
//SHAPE_T,
	{
		3,3,//int width, height;
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0, 1, 0},
			{1, 1, 1},
			{0, 0, 0}
		}
	}
};

int field[FIELD_HEIGHT][FIELD_WIDTH];
int screen[FIELD_HEIGHT][FIELD_WIDTH];
MINO mino;
//ミノがフィールドと衝突しているかどうかを判定する
bool MinoIntersectsField() {
	for (int y = 0; y < mino.shape.height; y++)
		for (int x = 0; x < mino.shape.width; x++) 
			if (mino.shape.pattern[y][x]) {
				if((mino.y + y < 0) || (mino.y + y >= FIELD_HEIGHT) 
					|| (mino.x + x < 0) || (mino.x + x >= FIELD_WIDTH))
					return true;

				if (field[mino.y + y][mino.x + x])
					return true;
			}

	return false;
}
//画面を描画する
void DrawScreen(){
	memcpy(screen, field, sizeof field);

	for(int y = 0; y < mino.shape.height; y++)
		for (int x = 0; x < mino.shape.width; x++)
			if (mino.shape.pattern[y][x])
				screen[mino.y + y][mino.x + x] |= 1;

	system("cls");	
	//画面の上部の枠を描画する
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		printf("□");
		for (int x = 0; x < FIELD_WIDTH; x++)
			printf("%s", screen[y][x] ? "■" : " ");
		printf("□");
		printf("\n");
	}
	//画面の下部の枠を描画する
	for (int x = 0; x < FIELD_WIDTH + 2; x++)
		printf("□");
	//消したラインの数を表示する
	printf("\n消したラインの数: %d\n", count);
}
//ミノを初期化する
void InitMino() {
	mino.shape = shapes[rand() % SHAPE_MAX];
	mino.x = (FIELD_WIDTH - mino.shape.width) / 2;
	mino.y = 0;
}
//ゲームを初期化する
void Init() {
	memset(field, 0, sizeof field);

	InitMino();

	DrawScreen();
}
//ゲームのメインループ
int main(){
	srand((unsigned int)time(NULL));
	Init();
	
	clock_t lastClock = clock();
	while (1) {
		clock_t newClock = clock();
		if(newClock>= lastClock + INTERVAL){
			lastClock = newClock;

			MINO lastMino = mino;
			mino.y++;
			//ミノがフィールドと衝突している場合、ミノを元の位置に戻し、フィールドにミノを固定する
			if (MinoIntersectsField()) {
				mino = lastMino;

				for (int y = 0; y < mino.shape.height; y++)
					for (int x = 0; x < mino.shape.width; x++)
						if(mino.shape.pattern[y][x])
							field[mino.y + y][mino.x + x] |= 1;
				//フィールドの1行が埋まっているかどうかを判定する
				for(int y = 0; y < FIELD_HEIGHT; y++){
					bool comleted = true;
					for(int x = 0; x < FIELD_WIDTH; x++)
						if (!field[y][x]) {
							comleted = false;
							break;
						}
					//1行が埋まっている場合、フィールドを1行下にずらす
					if (comleted) {
						for (int x = 0; x < FIELD_WIDTH; x++)
							field[y][x] = 0;

						for (int y2 = y; y2 > 0; y2--)
							for (int x = 0; x < FIELD_WIDTH; x++) {
								field[y2][x] = field[y2 - 1][x];
								field[y2 - 1][x] = 0;
							}
						count++;
					}
				}
				InitMino();
			}

			DrawScreen();
		}
		//キーボード入力があった場合、ミノを操作する
		if(_kbhit()){
			MINO lastMino = mino;
			switch (_getch()) {
			case 'w':
				break;
			case 's':
				mino.y++;
				break;
			case 'a':
				mino.x--;
				break;
			case 'd':
				mino.x++;
				break;
			default:
				{
					MINO newMino = mino;
					for (int y = 0; y < mino.shape.height; y++)
						for (int x = 0; x < mino.shape.width; x++)
							newMino.shape.pattern[mino.shape.width-1-x][y] = mino.shape.pattern[y][x];
					mino = newMino;
				}
				break;
			}
			//ミノがフィールドと衝突している場合、ミノを元の位置に戻す
			if(MinoIntersectsField())
				mino = lastMino;

			DrawScreen();
		}
	}
}


//https://www.youtube.com/watch?v=BJs29RicyPw
