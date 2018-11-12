#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#pragma warning(disable:4996)
using namespace std;

class Queue {
private:
	int q[10001];
	int front = 0, back = 0;
public:

	int IsEmpty() {
		if (front == back)
			return 1;
		else
			return 0;
	}
	int NextPos(int pos) {
		if (pos == sizeof(q) / sizeof(int) - 1)
			return 0;
		else
			return pos + 1;
	}
	void Push(int n) {
		if (NextPos(back) == front) {
			exit(-1);
		}
		back = NextPos(back);
		q[back] = n;
	}
	int Pop() {
		if (IsEmpty())
			return -1;
		else {
			front = NextPos(front);
			return q[front];
		}
	}
	int Size() {
		if (IsEmpty())
			return 0;
		else {
			if (front <= back)
				return back - front;
			else
				return sizeof(q) / sizeof(int) + 1 - front + back;
		}
	}
	int GetFront() {
		if (IsEmpty())
			return -1;
		else
			return q[NextPos(front)];
	}
	int GetBack() {
		if (IsEmpty())
			return -1;
		else
			return q[back];
	}
};

int main() {
	int M, N;
	int* num;
	int* result;
	int idx = 0;

	cin >> M >> N;
	num = new int[M];
	result = new int[M];
	Queue q;

	for (int i = 0; i < M; i++) {
		num[i] = i + 1;
		q.Push(num[i]);
	}
	int temp;
	while (1) {
		for (int j = 0; j < N - 1; j++) {
			temp = q.Pop();
			q.Push(temp);
		}
		result[idx] = q.Pop();
		if (idx >= M - 1)
			break;

		idx++;
	}

	cout << '<';
	for (int j = 0; j < M - 1; j++) {
		cout << result[j] << ", ";
	}
	cout << result[idx] << '>' << endl;

	delete num;
	delete result;
	return 0;
}