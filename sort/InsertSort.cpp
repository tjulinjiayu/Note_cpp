#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void InsertSort(vector<int> &array)
{
	int len = array.size();
	for(int i = 1; i < len; ++i){
		int temp = array[i];
		int j = i;
		while(j > 0 && temp < array[j-1]){
			array[j] = array[j-1];
			--j;
		}
		array[j] = temp;
	}
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
	InsertSort(v);
	cout << "After sort: ";
	for (int i = 0; i < n; ++i){
		cout << v[i];
	}
	cout << endl;
	return 0;
}