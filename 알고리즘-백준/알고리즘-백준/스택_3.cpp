#include <iostream>
#include <cstdlib>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#define STACK_LEN 100000
/*‘()’ 인 괄호열의 값은 2이다.
‘[]’ 인 괄호열의 값은 3이다.
‘(X)’ 의 괄호값은 2×값(X) 으로 계산된다.
‘[X]’ 의 괄호값은 3×값(X) 으로 계산된다.
올바른 괄호열 X와 Y가 결합된 XY의 괄호값은 값(XY)= 값(X)+값(Y) 로 계산된다.
예를 들어 ‘(()[[]])([])’ 의 괄호값을 구해보자.  ‘()[[]]’ 의 괄호값이 2 + 3×3=11 이므로  
‘(()[[ ]])’의 괄호값은 2×11=22 이다. 그리고  ‘([])’의 값은 2×3=6 이므로 전체 괄호열의 값은 22 + 6 = 28 이다.*/
class Stack {
private:
	int* stack;
	int index;
public:
	Stack() {
		index = -1;
		stack = new int[STACK_LEN];
	}
	Stack(int N) {
		stack = new int[N];
		index = -1;
	}

	void Push(int num) {
		index++;
		stack[index] = num;
	}
	int Pop() {
		if (index >= 0)
			return stack[index--];
		else
			return -1;
	}
	int Size() {
		return index + 1;
	}
	bool IsEmpty() {
		if (index < 0)
			return true;
		else
			return false;
	}
	int Top() {
		if (index < 0)
			return -1;
		else
			return stack[index];
	}
};

int main() {
	char* input;
	Stack s;
	input = new char[30];

	cin >> input;

	int idx = 0;
	int sum = 0, temp = 0;
	bool Ispop = false;
	while (1) {
		if (input[idx] == '(') {
			s.Push(2);
			Ispop = false;
		}
		else if (input[idx] == '[') {
			s.Push(3);
			Ispop = false;
		}
		else if (input[idx] == ')') {
			if (s.Pop() != 2)
				goto NO;

			if (Ispop == true)
				sum *= 2;
			else
				temp = 2;
			Ispop = true;
		}
		else if (input[idx] == ']') {
			if (s.Pop() != 3)
				goto NO;

			if (Ispop == true)
				sum *= 3;
			else
				temp = 3;
			Ispop = true;
		}


		if (strlen(input) == idx + 1)
			break;
		idx++;
	}
	cout << sum << endl;
	return 0;

NO:
	cout << 0 << endl;
	return 0;
}