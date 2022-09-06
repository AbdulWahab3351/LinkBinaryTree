#ifndef QUEUE_H
#define QUEUE_H
#include"Node.h"
template<typename T>
class Queue
{
	Node<T>* head;
	Node<T>* tail;
public:
	bool isEmpty();
	void enQueue(T val);
	T deQueue();
	Queue();
	Queue(const Queue<T>& ref);
	Queue<T>& operator= (const Queue& ref);
	~Queue();
};
#endif // !QUEUE_H



