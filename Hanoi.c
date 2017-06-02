#define _CRT_SECURE_NO_WARNINGS
#define HEIGHT 5
#define TOWERS 3
#include<stdio.h>

typedef struct{
	int stack[HEIGHT];
	int volume;
}Stack;

//�������֐�
int init(Stack *tower) {
	//�X�^�b�N�̑S�v�f�����Z�b�g
	for (int i = 0; i < HEIGHT; i++) {
		tower->stack[i] = 0;
	}
	//�X�^�b�N�̃f�[�^�������Z�b�g
	tower->volume = 0;
	return 0;
}

//�X�^�b�N�Ƀv�b�V��
int push(Stack *tower, int number) {
	if (tower->volume >= HEIGHT)//�X�^�b�N�̗v�f�����t�̂Ƃ�
		return -1;
	else {
		tower->stack[tower->volume] = number;
		tower->volume++;
	}
	return 0;
}

//�X�^�b�N����|�b�v
int pop(Stack *tower) {
	int pops;
	if (tower->volume == 0)		//�X�^�b�N����̂Ƃ�
		return -1;
	else {
		tower->volume--;
		pops = tower->stack[tower->volume];
		tower->stack[tower->volume] = 0;
	}
	return pops;
}

//�\���֐�
void printTower(Stack tower) {
	for (int i = 0; i < tower.volume; i++) {
		printf("%d ", tower.stack[i]);
	}
	putchar('\n');
}

//�ړ��\���f�֐�
int moveableTower(Stack fromTower, Stack toTower) {
	if (toTower.volume == 0 && fromTower.volume != 0)
		return 1;
	else if (fromTower.stack[fromTower.volume - 1] < toTower.stack[toTower.volume - 1] && fromTower.volume != 0)
		return 1;
	else
		return 0;
}

//�I�����f�֐�
int checkFinish(Stack tower, int blocks) {
	int count = blocks;
	for (int i = 0; i < count; i++) {
		if (tower.stack[i] != blocks)
			return 0;
		blocks--;
	}
	return 1;
	
}

int main() {
	int i;
	int count = 1;
	int fromTower, toTower;
	int tempNumber;
	int blocks;

	Stack tower[TOWERS];

	printf("�i����I��ł�������:3,4,5");
	scanf("%d", &blocks);

	//3���̏�����
	for (i = 0; i < TOWERS; i++) {
		init(&tower[i]);
	}
	//��ڂ̓��ɃX�^�b�N
	for (i = blocks; i > 0; i--) {
		push(&tower[0], i);
	}

	//���̏�����Ԃ�\��
	for (i = 0; i < TOWERS; i++) {
		printf("%d:", i+1);
		printTower(tower[i]);
	}
	while (1) {
		//�ړ��񐔂̃J�E���g
		printf("%d���\n", count);

		//�ړ����ƈړ�����󂯎��
		printf("�ړ����̓��ƈړ���̓�����͂��Ă�������.[? ?]:");
		scanf("%d %d", &fromTower, &toTower);

		//�ړ����̓�����ړ���̓��Ƀf�[�^���ړ�������
		if (moveableTower(tower[fromTower-1], tower[toTower-1]) == 1) {
			tempNumber = pop(&tower[fromTower-1]);
			push(&tower[toTower-1], tempNumber);
		}

		//���݂̓��̏�Ԃ�\������
		for (i = 0; i < TOWERS; i++) {
			printf("%d:", i + 1);
			printTower(tower[i]);
		}

		//�N���A����
		if (checkFinish(tower[1], blocks) == 1 || checkFinish(tower[2], blocks) == 1) {
			printf("�N���A�I\n");
			break;
		}
		count++;
	}

	
}