#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//コンソール（ターミナル）アプリケーション向けの入力や出力操作をできるようにする
#include <conio.h>

//フィールドの幅と高さを定義
#define FIELD_WIDTH (14)
#define FIELD_HEIGHT (FIELD_WIDTH * 2)
//fpsを定義
#define FPS (10)
#define INTERVAL (1000 / FPS)
//パドルの幅を定義
#define PADDLE_WIDTH (4)

//ボールの座標を定義
int ballX;
int ballY;
//ボールの移動速度を定義
int ballVelocityX = 1;
int ballVelocityY = 1;
//パドルの座標を定義
int paddleX = (FIELD_WIDTH - PADDLE_WIDTH) / 2;
int paddleY = FIELD_HEIGHT - 2;

int main() {
	//前回の描画からどれだけ時間が経過したかで描画を更新する
	clock_t lastClock = clock();
	//リアルタイム処理
	while (1) {
		//ゲームが起動してから何ミリ秒経過したか、ループごとに毎回時間をチェックする
		clock_t nowClock = clock();
		//現在の時刻が前回の描画時刻と待機時間以上の時間の場合
		if (nowClock >= lastClock + INTERVAL) {
			ballX += ballVelocityX;
			ballY += ballVelocityY;

			//ボールが右の壁に当たったら跳ね返る
			if (ballX <= 0)
				ballVelocityX = 1;
			//ボールが左の壁に当たったら跳ね返る
			if (ballX >= FIELD_WIDTH - 1)
				ballVelocityX = -1;
			//ボールが床に当たったら跳ね返る
			if (ballY <= 0)
				ballVelocityY = 1;
			//ボールが天井に当たったら跳ね返る
			if (ballY >= FIELD_HEIGHT - 1)
				ballVelocityY = -1;

			//1回描画するごとに表示画面をクリアする
			system("cls");
			//フィールドの天井の壁を表示する
			for (int x = 0; x < FIELD_WIDTH + 2; x++)
				printf("■");
			//天井を描画した後改行する
			printf("\n");

			//□をフィールド上に縦横にそれぞれ表示する
			for (int y = 0; y < FIELD_HEIGHT; y++) {
				//1行描画前に壁を表示する(左の壁)
				printf("■");
				for (int x = 0; x < FIELD_WIDTH; x++) {
					//ボールの描画
					if ((x == ballX) && (y == ballY))
						printf("●");
					else if ((y == paddleY) && (x >= paddleX) && (x < paddleX + PADDLE_WIDTH))
						printf("□");
					else
						printf("　");
				}
				//ブロックを表示する
				printf("■");
				//1行描画ごとに改行する
				printf("\n");
			}
			//フィールドの下の壁を表示する
			for (int x = 0; x < FIELD_WIDTH + 2; x++)
				printf("■");

			//lastClockを現在の時間で更新する
			lastClock = nowClock;

		}
	}
	_getch();
}