#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void HeapSort(vector<int> &array)
{
	int len = array.size();

}

int main(int argc, char const *argv[])
{
	int n, ele;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; ++i){
		cin >> ele;
		v.push_back(ele);
	}
	HeapSort(v);
	cout << "After sort: ";
	for (int i = 0; i < n; ++i){
		cout << v[i];
	}
	cout << endl;
	return 0;
}