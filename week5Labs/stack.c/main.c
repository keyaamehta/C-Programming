#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 10

typedef struct stackNode {
       int nodeData;
       struct stackNode *nextPtr;
} node;



int isEmpty (node *topPtr) {
	if (topPtr == NULL) {
		printf("Stack is EMPTY");
		return -1;
	}
	else {
		printf("Stack is NOT EMPTY");
	}
	return -1;
}

void push (node *topPtr, node *currentPtr, int ele) {
	currentPtr = (node*) malloc(sizeof(node));
	assert(currentPtr != NULL);
	currentPtr->nodeData = ele;
	currentPtr->nextPtr = topPtr;
	topPtr = currentPtr;
}

void pop (node *topPtr, node *currentPtr, node *tempPtr) {
	currentPtr = (node*) malloc(sizeof(node));
	topPtr = currentPtr->nextPtr;
	tempPtr = currentPtr;
	free(currentPtr);
}

void printStack (node *currentPtr, node *topPtr) {
	if (isEmpty(topPtr) == -1) {
		printf("EMPTY");
	} else {
		currentPtr = topPtr;
		while (currentPtr) {
			printf("%d\n", currentPtr->nodeData);
			currentPtr = currentPtr->nextPtr;
		}
	}
}


int main() {
	node *currentPtr, *topPtr, *tempPtr;
	int func;
	int numEle;
	int ele;
	int i;

	topPtr = NULL;

	printf("Enter how many elements you would like in your stack:");
	scanf("%d\n", &numEle);

	printf("Enter the corresponding number: \n");
	printf("1) PUSH\n");
	printf("2) POP\n");
	printf("3) CHECK IF EMPTY\n");
	printf("4) PRINT STACK\n");
	scanf("%d\n", &func);

	switch (func) {
		case 1:
		printf("Enter element to PUSH: ");
		scanf("%d\n", &ele);
		push(topPtr, currentPtr, ele);
		case 2:
		pop(topPtr, currentPtr, tempPtr);
		case 3:
		isEmpty(topPtr);
		case 4:
		printStack(currentPtr, topPtr);
	}

	return 0;
}













