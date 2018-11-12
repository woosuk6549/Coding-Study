#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

typedef struct Node {
	int data;
	Node* next;
	Node* prev;
}Node;
typedef struct Deque {
	Node* head;
	Node* tail;
}Deque;

void InitDeque(Deque* d) {
	d->head = NULL;
	d->tail = NULL;
}
int IsEmpty(Deque* d) {
	if (d->head == NULL)
		return 1;
	else
		return 0;
}

void PushFront(Deque* d, int pdata) {
	Node* newNode = new Node;
	newNode->data = pdata;

	newNode->next = d->head;
	if (IsEmpty(d))
		d->tail = newNode;
	else
		d->head->prev = newNode;

	newNode->prev = NULL;
	d->head = newNode;
}

void PushBack(Deque* d, int pdata) {
	Node* newNode = new Node;
	newNode->data = pdata;
	newNode->prev = d->tail;
	if (IsEmpty(d)) {
		d->head = newNode;
	}
	else {
		d->tail->next = newNode;
	}
	newNode->next = NULL;
	d->tail = newNode;
}

int PopFront(Deque* d) {
	Node* rNode = d->head;
	int rdata;
	if (IsEmpty(d))
		return -1;

	rdata = d->head->data;
	d->head = d->head->next;
	delete rNode;
	if (d->head == NULL)
		d->tail = NULL;
	else
		d->head->prev = NULL;
	return rdata;
}
int PopBack(Deque* d) {
	Node* rNode = d->tail;
	int rdata;
	if (IsEmpty(d))
		return -1;

	rdata = d->tail->data;
	d->tail = d->tail->prev;
	delete rNode;
	if (d->tail == NULL)
		d->head = NULL;
	else
		d->tail->next = NULL;
	return rdata;
}

int GetFront(Deque* d) {
	if (IsEmpty(d))
		return -1;
	return d->head->data;
}
int GetBack(Deque* d) {
	if (IsEmpty(d))
		return -1;
	return d->tail->data;
}
int DequeSize(Deque* d) {
	int size;
	Node* cur = d->head;
	if (IsEmpty(d)) {
		size = 0;
		return size;
	}
	else {
		size = 1;
		do {
			size++;
			cur = cur->next;
		} while (cur->next != NULL);
	}
	return size;
}

enum Command { PUSHFRONT, PUSHBACK, POPFRONT, POPBACK, EMPTY, SIZE, FRONT, BACK };

int main() {
	Deque d;
	InitDeque(&d);
	int num[10001];
	string com[10001];
	Command command[10001];
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> com[i];
		if (com[i] == "push_front") {
			command[i] = PUSHFRONT;
			cin >> num[i];
		}
		else if (com[i] == "push_back") {
			command[i] = PUSHBACK;
			cin >> num[i];
		}
		else if (com[i] == "pop_front")
			command[i] = POPFRONT;
		else if (com[i] == "pop_back")
			command[i] = POPBACK;
		else if (com[i] == "size")
			command[i] = SIZE;
		else if (com[i] == "empty")
			command[i] = EMPTY;
		else if (com[i] == "front")
			command[i] = FRONT;
		else if (com[i] == "back")
			command[i] = BACK;
	}

	for (int j = 0; j < N; j++) {
		switch (command[j]) {
		case PUSHFRONT:
			PushFront(&d, num[j]);
			break;
		case PUSHBACK:
			PushBack(&d, num[j]);
			break;
		case POPFRONT:
			cout << PopFront(&d) << endl;
			break;
		case POPBACK:
			cout << PopBack(&d) << endl;
			break;
		case SIZE:
			cout << DequeSize(&d) << endl;
			break;
		case EMPTY:
			cout << IsEmpty(&d) << endl;
			break;
		case FRONT:
			cout << GetFront(&d) << endl;
			break;
		case BACK:
			cout << GetBack(&d) << endl;
		}
	}
	return 0;
}