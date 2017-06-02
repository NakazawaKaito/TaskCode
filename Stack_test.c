#define HEIGHT 5
#include<stdio.h>

//stack構造体
typedef struct{
	int stack[HEIGHT];
	int volume;
}Stack;

//初期化関数
int init(Stack *stack) {
	//スタックの全要素をリセット
	for (int i = 0; i < HEIGHT; i++) {
		stack->stack[i] = 0;
	}
	//スタックのデータ個数をリセット
	stack->volume = 0;
	return 0;
}

//スタックにプッシュ
int push(Stack *stack, int number) {
	if (stack->volume >= HEIGHT)//スタックの要素が満杯のとき
		return -1;
	else {						
		stack->stack[stack->volume] = number;
		stack->volume++;
	}
	return 0;
}

//スタックからポップ
int pop(Stack *stack) {
	int pops;					
	if (stack->volume == 0)		//スタックが空のとき
		return -1;
	else {
		stack->volume--;
		pops = stack->stack[stack->volume];
		stack->stack[stack->volume] = 0;
	}
	return pops;
}

//スタックの中身を表示
void printTower(Stack stack) {
	for (int i = 0; i < stack.volume; i++) {
		printf("%d\n", stack.stack[i]);
	}
}

int main() {
	Stack stk;
	
	init(&stk);

	push(&stk, 10);
	push(&stk, 20);
	push(&stk, 30);
	push(&stk, 40);
	push(&stk, 50);
	pop(&stk);
	push(&stk, 60);
	/*
	printf("%d\n", pop(&stk));
	printf("%d\n", pop(&stk));
	printf("%d\n", pop(&stk));*/

	printTower(stk);

	return 0;
}