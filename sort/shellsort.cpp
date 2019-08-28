#include <iostream>
#include <vector>
using namespace std;

vector<int> shellsort(vector<int> &array)
{
    int len = array.size();
    int temp, gap = len / 2;
    while(gap > 0){
        for(int i = gap; i < len; ++i){
            temp = array[i];
            int preIndex = i - gap;
            while(preIndex >= 0 && array[preIndex] > temp){
                array[preIndex+gap] = array[preIndex];
                preIndex -= gap;
            }
                array[preIndex+gap] = temp;
        }
        gap /= 2;
    }
    return array;
}

int main()
{
    int n, ele;
    cout << "Input n: ";
    cin >> n;
    vector<int> array;
    for(int i = 0; i < n; ++i){
        cout << "Input ele: ";
        cin >> ele;
        array.push_back(ele);
    }
    vector<int> res;
    res = shellsort(array);
    cout << "After sort: ";
    for(int i = 0; i < n; ++i){
        cout << res[i];
    }
    cout << endl;
    return 0;
}
