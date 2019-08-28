#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SelectSort(vector<int> &array)
{
	int len = array.size();
	for(int i = 0; i < len; ++i){
		int min = array[i];
		int index = i;
		for(int j = i+1; j < len; ++j){
			if(array[j] < min){
				min = array[j];
				index = j;
			}
		}
		swap(array[index], array[i]);
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
	SelectSort(v);
	cout << "After sort: ";
	for (int i = 0; i < n; ++i){
		cout << v[i];
	}
	cout << endl;
	return 0;
}