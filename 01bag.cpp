#include <iostream>
#include <algorithm>
using namespace std;

int Findmax(int number, int capacity, int *w, int *v)
{
    int **V;
    V = new int *[number+1];
    for(int i = 0; i <= number; ++i){
        V[i] = new int[capacity+1];
    }
    
    for(int i = 0; i <= number; ++i)
        V[i][0] = 0;
    for(int i = 0; i <= capacity; ++i)
        V[0][i] = 0;

    int maxval = 0;
    for(int i = 1; i <= number; ++i){
        for(int j = 1; j <= capacity; ++j){
            if(j < w[i])
                V[i][j] = V[i-1][j];
            else
                V[i][j] = max(V[i-1][j], V[i-1][j-w[i]] + v[i]);
            if(maxval < V[i][j])
                maxval = V[i][j];
        }
    }
    for(int i = 0; i <= number; ++i){
        delete[] V[i];
    }
    delete[] V;
    return maxval;
}
int main()
{
    int number, capacity;
    cin >> number >> capacity;
    int* w = new int[number+1];
    int* v = new int[number+1];
    for(int i = 1; i <= number; ++i){
        cin >> w[i] >> v[i];
    }
    int maxvalue = Findmax(number, capacity, w, v);
    cout << "The max value is " << maxvalue << endl;

    delete[] w;
    delete[] v;
    return 0;
}

