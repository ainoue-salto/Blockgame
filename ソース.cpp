#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//�R���\�[���i�^�[�~�i���j�A�v���P�[�V���������̓��͂�o�͑�����ł���悤�ɂ���
#include <conio.h>

//�t�B�[���h�̕��ƍ������`
#define FIELD_WIDTH (14)
#define FIELD_HEIGHT (FIELD_WIDTH * 2)
//fps���`
#define FPS (10)
#define INTERVAL (1000 / FPS)
//�p�h���̕����`
#define PADDLE_WIDTH (4)

//�{�[���̍��W���`
int ballX;
int ballY;
//�{�[���̈ړ����x���`
int ballVelocityX = 1;
int ballVelocityY = 1;
//�p�h���̍��W���`
int paddleX = (FIELD_WIDTH - PADDLE_WIDTH) / 2;
int paddleY = FIELD_HEIGHT - 2;

int main() {
	//�O��̕`�悩��ǂꂾ�����Ԃ��o�߂������ŕ`����X�V����
	clock_t lastClock = clock();
	//���A���^�C������
	while (1) {
		//�Q�[�����N�����Ă��牽�~���b�o�߂������A���[�v���Ƃɖ��񎞊Ԃ��`�F�b�N����
		clock_t nowClock = clock();
		//���݂̎������O��̕`�掞���Ƒҋ@���Ԉȏ�̎��Ԃ̏ꍇ
		if (nowClock >= lastClock + INTERVAL) {
			ballX += ballVelocityX;
			ballY += ballVelocityY;

			//�{�[�����E�̕ǂɓ��������璵�˕Ԃ�
			if (ballX <= 0)
				ballVelocityX = 1;
			//�{�[�������̕ǂɓ��������璵�˕Ԃ�
			if (ballX >= FIELD_WIDTH - 1)
				ballVelocityX = -1;
			//�{�[�������ɓ��������璵�˕Ԃ�
			if (ballY <= 0)
				ballVelocityY = 1;
			//�{�[�����V��ɓ��������璵�˕Ԃ�
			if (ballY >= FIELD_HEIGHT - 1)
				ballVelocityY = -1;

			//1��`�悷�邲�Ƃɕ\����ʂ��N���A����
			system("cls");
			//�t�B�[���h�̓V��̕ǂ�\������
			for (int x = 0; x < FIELD_WIDTH + 2; x++)
				printf("��");
			//�V���`�悵������s����
			printf("\n");

			//�����t�B�[���h��ɏc���ɂ��ꂼ��\������
			for (int y = 0; y < FIELD_HEIGHT; y++) {
				//1�s�`��O�ɕǂ�\������(���̕�)
				printf("��");
				for (int x = 0; x < FIELD_WIDTH; x++) {
					//�{�[���̕`��
					if ((x == ballX) && (y == ballY))
						printf("��");
					else if ((y == paddleY) && (x >= paddleX) && (x < paddleX + PADDLE_WIDTH))
						printf("��");
					else
						printf("�@");
				}
				//�u���b�N��\������
				printf("��");
				//1�s�`�悲�Ƃɉ��s����
				printf("\n");
			}
			//�t�B�[���h�̉��̕ǂ�\������
			for (int x = 0; x < FIELD_WIDTH + 2; x++)
				printf("��");

			//lastClock�����݂̎��ԂōX�V����
			lastClock = nowClock;

		}
	}
	_getch();
}