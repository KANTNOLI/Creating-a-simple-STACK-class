#include "main.h"

template<typename T>
class Stack {
public:
	Stack();
	~Stack();

	int get_size() { return size; };
	void push(T data);
	void pop();
	T top();

private:

	template<typename T>
	class Element {
	public:
		Element* pNext; 
		T data;

		Element(T data = T(), Element* pNext = nullptr) { 
			this->data = data;
			this->pNext = pNext;
		};

	};
	int size;
	Element<T>* head;
};

template<typename T>
void Stack<T>::push(T data) {

	if (head == nullptr) {
		head = new Element<T>(data);
	}
	else {
		Element<T>* temp = head;
		head = new Element<T>(data, temp);
	}
	size++;
}

template<typename T>
void Stack<T>::pop() {
	if (size < 2) {
		delete head;
	}
	else {
		Element<T>* temp = head;  
		head = head->pNext;  
		delete temp;  
	}
	size--; 
}

template<typename T>
T Stack<T>::top() {
	if (size > 0) {
		return head->data;
	}
	
	return T(); 
}

template<typename T>
Stack<T>::Stack() {
	size = 0;
	head = nullptr;
}

template<typename T>
Stack<T>::~Stack() {
}


int main() {
	Stack<int> stack;
	int size, input;
	cout << "Input size stack: ";
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> input;
		stack.push(input);
	}

	cout << "Elements size: " << stack.get_size() << endl;
	stack.pop();
	cout << "Using function POP" << endl; 
	cout << "Elements size: " << stack.get_size() << endl; 
	cout << "Element TOP: " << stack.top() << endl; 
	return 0;
}