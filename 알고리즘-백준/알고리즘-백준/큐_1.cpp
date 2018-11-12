#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#pragma warning(disable:4996)
using namespace std;

#define QUEUE_LEN 10001
#define STACK_LEN 10001

typedef struct Node {
	int v;
	Node* next;
}Node;
Node* graph[10001];
int visited[10001] = { 0, };

void addEdge(int v1, int v2, int reverse) {
	Node* newNode = new Node;
	Node* cur = graph[v1];

	newNode->v = v2;
	newNode->next = NULL;

	if (cur == NULL) {
		graph[v1] = newNode;
	}
	else {
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = newNode;
	}
	if (reverse == 1) {
		addEdge(v2, v1, 0);
	}
}

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
class Stack {
private:
	int stack[STACK_LEN];
	int index;
public:
	Stack() {
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
int nextVertex(int v) {
	Node* cur = graph[v];
	while (cur != NULL) {
		if (visited[cur->v] == 0) {
			return cur->v;
		}
		cur = cur->next;
	}
	return -1;
}

void nextVertexForBFS(int v, Queue* q) {
	Node* cur = graph[v];
	while (cur != NULL) {
		if (visited[cur->v] == 0)
			q->Push(cur->v);
		cur = cur->next;
	}
}

void DFSearch(int v) {
	Stack s;

	cout << v << ' ';
	visited[v] = 1;
	s.Push(v);

	while (s.IsEmpty() == 0) {
		int nextv = -1;
		nextv = nextVertex(s.Top());
		if (nextv == -1)
			s.Pop();
		else {
			cout << nextv << ' ';
			visited[nextv] = 1;
			s.Push(nextv);
		}
	}
	cout << endl;
}
void BFSearch(int v) {
	Queue q;
	q.Push(v);
	while (q.IsEmpty() == 0) {
		int outV = q.Pop();
		if (visited[outV] == 0) {
			cout << outV << ' ';
			visited[outV] = 1;
			nextVertexForBFS(outV, &q);
		}
	}
	cout << endl;
}

int main() {
	int N, M, V;
	int v1, v2;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		addEdge(v1, v2, 1);
	}

	DFSearch(V);
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}

	BFSearch(V);

	return 0;
}