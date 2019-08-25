#include <iostream>
#include <algorithm>
using namespace std;

int Findmax(int number, int capacity, int *w, int *v, int *V)
{
    int maxval = 0;
    for(int i = 1; i <= number; ++i){
        for(int j = capacity; j > 0; --j){
            if(j-w[i] >= 0){
                V[j] = V[j-w[i]] + v[i];
                if(maxval < V[j])
                    maxval = V[j];
            }
        }
    }
    return maxval;
}

int main()
{
    int number, capacity;
    cin >> number >> capacity;

    int* V = new int[capacity+1];
    for(int i = 0; i <= capacity; ++i){
        V[i] = 0;
    }

    int* w = new int[number+1];
    int* v = new int[number+1];
    for(int i = 1; i <= number; ++i){
        cin >> w[i] >> v[i];
    }
    int maxvalue = Findmax(number, capacity, w, v, V);
    cout << "The max value is " << maxvalue << endl;
    
    delete[] V;
    delete[] w;
    delete[] v;
    return 0;
}

