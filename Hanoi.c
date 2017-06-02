#define _CRT_SECURE_NO_WARNINGS
#define HEIGHT 5
#define TOWERS 3
#include<stdio.h>

typedef struct{
	int stack[HEIGHT];
	int volume;
}Stack;

//初期化関数
int init(Stack *tower) {
	//スタックの全要素をリセット
	for (int i = 0; i < HEIGHT; i++) {
		tower->stack[i] = 0;
	}
	//スタックのデータ個数をリセット
	tower->volume = 0;
	return 0;
}

//スタックにプッシュ
int push(Stack *tower, int number) {
	if (tower->volume >= HEIGHT)//スタックの要素が満杯のとき
		return -1;
	else {
		tower->stack[tower->volume] = number;
		tower->volume++;
	}
	return 0;
}

//スタックからポップ
int pop(Stack *tower) {
	int pops;
	if (tower->volume == 0)		//スタックが空のとき
		return -1;
	else {
		tower->volume--;
		pops = tower->stack[tower->volume];
		tower->stack[tower->volume] = 0;
	}
	return pops;
}

//表示関数
void printTower(Stack tower) {
	for (int i = 0; i < tower.volume; i++) {
		printf("%d ", tower.stack[i]);
	}
	putchar('\n');
}

//移動可能判断関数
int moveableTower(Stack fromTower, Stack toTower) {
	if (toTower.volume == 0 && fromTower.volume != 0)
		return 1;
	else if (fromTower.stack[fromTower.volume - 1] < toTower.stack[toTower.volume - 1] && fromTower.volume != 0)
		return 1;
	else
		return 0;
}

//終了判断関数
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

	printf("段数を選んでください:3,4,5");
	scanf("%d", &blocks);

	//3塔の初期化
	for (i = 0; i < TOWERS; i++) {
		init(&tower[i]);
	}
	//一つ目の塔にスタック
	for (i = blocks; i > 0; i--) {
		push(&tower[0], i);
	}

	//塔の初期状態を表示
	for (i = 0; i < TOWERS; i++) {
		printf("%d:", i+1);
		printTower(tower[i]);
	}
	while (1) {
		//移動回数のカウント
		printf("%d回目\n", count);

		//移動元と移動先を受け取る
		printf("移動元の塔と移動先の塔を入力してください.[? ?]:");
		scanf("%d %d", &fromTower, &toTower);

		//移動元の塔から移動先の塔にデータを移動させる
		if (moveableTower(tower[fromTower-1], tower[toTower-1]) == 1) {
			tempNumber = pop(&tower[fromTower-1]);
			push(&tower[toTower-1], tempNumber);
		}

		//現在の塔の状態を表示する
		for (i = 0; i < TOWERS; i++) {
			printf("%d:", i + 1);
			printTower(tower[i]);
		}

		//クリア判定
		if (checkFinish(tower[1], blocks) == 1 || checkFinish(tower[2], blocks) == 1) {
			printf("クリア！\n");
			break;
		}
		count++;
	}

	
}