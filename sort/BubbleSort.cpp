#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(vector<int> &array)
{
	bool flag = true;
	int len = array.size();
	for(int i = 1; i < len && flag; ++i){
		flag = false;
		for(int j = len - 1; j >= i; --j){
			if(array[j] > array[j+1]){
				flag = true;
				swap(array[j], array[j+1]);
			}
		}
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
	BubbleSort(v);
	cout << "After sort: ";
	for (int i = 0; i < n; ++i){
		cout << v[i];
	}
	cout << endl;
	return 0;
}