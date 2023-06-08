#include "main.h"

int main(){
	stack<int> myStack;


	int size = 10, in;
	while (size != 0) {
		cin >> in;
		myStack.push(in);
		size--;
	}

	for (int i = 0; i < size; i++) {
		myStack.pop();
	}

	return 0;
}