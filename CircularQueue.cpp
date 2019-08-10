/*
实现一个循环队列类CircularQueue，其中包括：
●构造函数：传入队列的最大长度max_size。
●push_back：将元素放到队列尾。
●pop_front：将队列首元素弹出。
●batch_remove：从队列首开始移除指定数量的元素，如果队列长度小于给定数量则清空队列。
(n)。
C++:
class CircularQueue要求队列实现时使用循环队列的方式，空间占用为O {
 public:
  CircularQueue(unsigned int max_size);
  bool push_back(int item);
  bool pop_front();
  void batch_remove(unsigned int count);
};
*/
#include <iostream>
#include <exception>
#include <cassert>
using namespace std;

template<class T>
class CircularQueue{
public:
	CircularQueue(unsigned int max_size) : max_size(max_size), tail(0), front(0){	//构造函数
		data = new T[max_size];
		assert(data != NULL);
	}
	~CircularQueue();																//析构函数
	bool push_back(T item);
	bool pop_front();
	bool isFull();
	bool isEmpty();
	void batch_remove(unsigned int count);
protected:																			//protected成员能被继承
	int tail, front;
	T *data;
	unsigned int max_size;
};

template <class T>
CircularQueue<T>::~CircularQueue(){
	delete[] data;
}

template <class T>
bool CircularQueue<T>::isFull(){
	if((tail + 1) % max_size == front)
		return true;
	return false;
}

template <class T>
bool CircularQueue<T>::isEmpty(){
	if(tail == front)
		return true;
	return false;
}

template <class T>
bool CircularQueue<T>::push_back(T item){
	if(isFull())
		throw "The queue is FULL!";
	data[tail] = item;
	tail = (tail + 1) % max_size;
	return true;
}

template <class T>
bool CircularQueue<T>::pop_front(){
	if(isEmpty())
		throw "The queue is EMPTY!";
	front = (front + 1) % max_size;
	return true;
}

template <class T>
void CircularQueue<T>::batch_remove(unsigned int count){
	if(isEmpty())
		return;

	int len = (tail - front + max_size) % max_size;
	if(count > len)
		tail = front = 0;
	else
		front = (front + count) % max_size;
}

int main()
{
	CircularQueue<int> circularqueue(5);
	int n, ele, mode, count;
	try{
		cout << "test times: ";
		cin >> n;
		while(n--){
			cout << "push:1 | pop:2 | batch_remove:3?" << endl; 
			cin >> mode;
			switch(mode){
				case 1: cout << "Push num: "; cin >> ele; circularqueue.push_back(ele); break;
				case 2: cout << "You want to pop a number." << endl; circularqueue.pop_front(); break;
				case 3: cout << "How many number to remove?: "; cin >> count; circularqueue.batch_remove(count); break;
				default: cout << "Choose mode -- push:1 | pop:2 | batch_remove:3?" << endl;
			}
		}
	}
	catch(const char *msg){
		cerr << msg << endl;
	}
	return 0;
}

