#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

#define STACK_LEN 100000

/*
스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다.
스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아 제일 먼저 들어간 자료가 제일 나중에 나오는 
(FILO, first in last out) 특성을 가지고 있다.
1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다.
이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 임의의 수열이 주어졌을 때 스택을 이용해 
그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 
이를 계산하는 프로그램을 작성하라.*/

/*첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다. 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다.
물론 같은 정수가 두 번 나오는 일은 없다*/

/*
입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다.
push연산은 +로, pop 연산은 -로 표현하도록 한다. 불가능한 경우 NO를 출력한다.*/
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
	int N;

	cin >> N;
	Stack s(N);

	int* num = new int[N];
	char* pm = new char[2 * N];
	for (int i = 0; i < N; i++)
		cin >> num[i];

	int res = 1, pmidx = 0, nidx = 0;
	while (1) {
		if (s.Top() == num[nidx]) {
			s.Pop();
			pm[pmidx++] = '-';
			nidx++;
		}
		else {
			if (res > N) {
				cout << "NO" << endl;
				exit(-1);
			}
			s.Push(res);
			pm[pmidx++] = '+';
			res++;
		}

		if (s.Top() == -1)
			break;
	}
	for (int i = 0; i < pmidx; i++)
		cout << pm[i] << endl;

	return 0;
}