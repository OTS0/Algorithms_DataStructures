#include <iostream>

using namespace std;

class Stack {
public:
	Stack(size_t const size) {
		buffer = new int[size];
		bufferSize = size;
		index = -1;
	}
	int index;
	int* buffer;
	size_t bufferSize;

	//add element
	void push(int const value) {
		buffer[++index] = value;
	}

	//remove element
	int pop() {
		if (index != -1) {
			return buffer[index--];
		}
		else { return -1; }
	}

	//output values
	void print() {
		for (int i = 0; i <= index; i++) {
			cout << buffer[i] << " ";
		}
	}
};
int main() {
	size_t balls;
	cin >> balls;

	Stack stack(balls);

	int number = 0;
	cin >> number;

	//fill truth stack (1,...)
	for (int i = 1; i < number; i++) {
		stack.push(i);
	}

	//fill stack 
	for (size_t i = 1; i < balls; i++) {
		int ballNumber;
		cin >> ballNumber;

		if (ballNumber > number) {
			for (int j = number + 1; j < ballNumber; j++) {
				stack.push(j);
			}
			number = ballNumber;
			continue;
		}

		else if (stack.pop() != ballNumber) {
			cout<<"Cheater";
			return 0;
		}
	}

	cout << "Not a proof";
	return 0;
}




