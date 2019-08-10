/*
ʵ��һ������ SPSCQueue, ֧�ֵ��������ߺ͵��������ߵ� C++���̳߳���.
    + ���г�����һ��ʼ�Ĺ��캯���д���ȥ
    + enqueue(int data): ������ÿ�λ������������һ�� int, ֵ�� 1 ��ʼ����
    + int dequeue(): ������ÿ�λ�Ӷ������ó�һ�� int, ����ӡ, Ҫ��ͷ����˳��һ��
*/
#include <iostream>
#include <exception>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class CircularQueue{
public:
	CircularQueue(unsigned int max_size) : max_size(max_size), front(0), tail(0){
		data = new int[max_size];
	}
	~CircularQueue(){
		delete[] data;
	}
	bool isEmpty(){
		if(front == tail)
			return true;
		return false;
	}
	bool isFull(){
		if((tail + 1) % max_size == front)
			return true;
		return false;
	}
	void enqueue(int item);
	int dequeue();
	void produce();
	void consume();
	
private:
	int front, tail;
	int *data;
	unsigned int max_size;	

	mutex mtx;
	condition_variable cv_nofull;
	condition_variable cv_noempty;
};

void CircularQueue::enqueue(int item)
{
	if(isFull())
		throw "The message queue is full!";
	data[tail] = item;
	tail = (tail + 1) % max_size;
}

int CircularQueue::dequeue()
{
	if(isEmpty())
		throw "The message queue is empty!";
	int pop = data[front];
	front = (front + 1) % max_size;
	return pop;
}

void CircularQueue::produce()
{
	for (int i = 1; i <= max_size; ++i){
		unique_lock<mutex> lck(mtx);

		while(isFull()){
			cv_nofull.wait(lck);
		}

		enqueue(i);

		cv_noempty.notify_one();
	}

}
void CircularQueue::consume()
{
	for (int i = 1; i <= max_size; ++i){
		unique_lock<mutex> lck(mtx);

		while(isEmpty()){
			cv_noempty.wait(lck);
		}

		cout << dequeue() << endl;

		cv_nofull.notify_one();
	}
}


int main()
{
	try{
		CircularQueue buffer(5);
		thread t1(&CircularQueue::produce, &buffer);
		thread t2(&CircularQueue::consume, &buffer);
		t1.join();
		t2.join();
	}
	catch(const char* msg){
		cerr << msg << endl;
	}
	return 0;
}
