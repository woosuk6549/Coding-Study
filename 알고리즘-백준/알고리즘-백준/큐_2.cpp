#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#pragma warning(disable:4996)
using namespace std;

#define QUEUE_LEN 10001

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
	int T;
	Queue* q;
	int* result;
	cin >> T;
	q = new Queue[T];
	result = new int[T];

	for (int i = 0; i < T; i++) {
		int priority[101] = { 0, };
		int M, N, prior, idx = 0;
		int* num;
		cin >> M >> N;
		num = new int[M];
		for (int j = 0; j < M; j++) {
			cin >> prior;
			num[j] = j;
			priority[j] = prior;
			q[i].Push(num[j]);
		}

		while (1) {
		LOOP:
			int temp2;
			for (int k = 0; k < M; k++) {
				if (priority[q[i].GetFront()] < priority[k]) {
					int temp;
					temp = q[i].Pop();
					q[i].Push(temp);
					goto LOOP;
				}
			}
			if ((temp2 = q[i].Pop()) != N) {
				idx++;
				priority[temp2] = -1;
			}
			else {
				result[i] = ++idx;
				break;
			}
		}
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}
	return 0;
}