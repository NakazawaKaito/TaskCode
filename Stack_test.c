#define HEIGHT 5
#include<stdio.h>

//stack�\����
typedef struct{
	int stack[HEIGHT];
	int volume;
}Stack;

//�������֐�
int init(Stack *stack) {
	//�X�^�b�N�̑S�v�f�����Z�b�g
	for (int i = 0; i < HEIGHT; i++) {
		stack->stack[i] = 0;
	}
	//�X�^�b�N�̃f�[�^�������Z�b�g
	stack->volume = 0;
	return 0;
}

//�X�^�b�N�Ƀv�b�V��
int push(Stack *stack, int number) {
	if (stack->volume >= HEIGHT)//�X�^�b�N�̗v�f�����t�̂Ƃ�
		return -1;
	else {						
		stack->stack[stack->volume] = number;
		stack->volume++;
	}
	return 0;
}

//�X�^�b�N����|�b�v
int pop(Stack *stack) {
	int pops;					
	if (stack->volume == 0)		//�X�^�b�N����̂Ƃ�
		return -1;
	else {
		stack->volume--;
		pops = stack->stack[stack->volume];
		stack->stack[stack->volume] = 0;
	}
	return pops;
}

//�X�^�b�N�̒��g��\��
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