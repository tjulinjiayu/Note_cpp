#include <iostream>
#include <exception>
using namespace std;

class CircularQueue{
public:
	CircularQueue(int max_size) : max_size(max_size), tail(0), front(0){
		data = new int[max_size];
	}
	~CircularQueue(){
		delete[] data;
	}
	bool push_back(int item);
	bool pop_front();
	bool isEmpty(){
		if(tail == front)
			return true;
		return false;
	}
	bool isFull(){
		if((tail + 1) % max_size == front)
			return true;
		return false;
	}
	void batch_remove(unsigned int count);
private:
	int tail, front;
	int *data;
	unsigned int max_size;
};

bool CircularQueue::push_back(int item)
{
	if(isFull())
		throw "The queue is full!";
	data[tail] = item;
	tail = (tail + 1) % max_size;
	return true;
}

bool CircularQueue::pop_front()
{
	if(isEmpty())
		throw "The queue is empty!";
	front = (front + 1) % max_size;
	return true;		
}

void CircularQueue::batch_remove(unsigned int count)
{
	if(isEmpty())
		return;

	int len = (tail - front + max_size) % max_size;
	if(count > len){
		tail = front = 0;
		throw "Count > len, now queue is empty!";
	}
	else
		front = (front + count) % max_size;
}

int main()
{
	CircularQueue circuqueue(5);
	int n, ele, mode, count;
	cout << "Input times: ";
	cin >> n;
	while(n--){
		try{
			cout << "1-->push,2-->pop,3-->remove. Input mode: ";
			cin >> mode;
			switch(mode){
				case 1 : cin >> ele; if(circuqueue.push_back(ele)) cout << "push ok" << endl; break;
				case 2 : if(circuqueue.pop_front()) cout << "pop ok" << endl; break;
				case 3 : cin >> count; circuqueue.batch_remove(count); break;
				default: cout << "Error mode input." << endl;
			}
		}
		catch(const char* msg){
			cerr << msg << endl;
		}
	}
	return 0;
}
