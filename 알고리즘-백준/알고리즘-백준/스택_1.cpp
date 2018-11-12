#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

#define STACK_LEN 100000

/*
���� (stack)�� �⺻���� �ڷᱸ�� �� �ϳ���, ��ǻ�� ���α׷��� �ۼ��� �� ���� �̿�Ǵ� �����̴�.
������ �ڷḦ �ִ� (push) �Ա��� �ڷḦ �̴� (pop) �Ա��� ���� ���� ���� �� �ڷᰡ ���� ���߿� ������ 
(FILO, first in last out) Ư���� ������ �ִ�.
1���� n������ ���� ���ÿ� �־��ٰ� �̾� �þ�������ν�, �ϳ��� ������ ���� �� �ִ�.
�̶�, ���ÿ� push�ϴ� ������ �ݵ�� ���������� ��Ű���� �Ѵٰ� ����. ������ ������ �־����� �� ������ �̿��� 
�� ������ ���� �� �ִ��� ������, �ִٸ� � ������ push�� pop ������ �����ؾ� �ϴ����� �˾Ƴ� �� �ִ�. 
�̸� ����ϴ� ���α׷��� �ۼ��϶�.*/

/*ù �ٿ� n (1 �� n �� 100,000)�� �־�����. ��° �ٺ��� n���� �ٿ��� ������ �̷�� 1�̻� n������ ������ �ϳ��� ������� �־�����.
���� ���� ������ �� �� ������ ���� ����*/

/*
�Էµ� ������ ����� ���� �ʿ��� ������ �� �ٿ� �� ���� ����Ѵ�.
push������ +��, pop ������ -�� ǥ���ϵ��� �Ѵ�. �Ұ����� ��� NO�� ����Ѵ�.*/
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