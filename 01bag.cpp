#include <iostream>
#include <algorithm>
using namespace std;

void Findwhat(int i, int j, int *w, int *v, int **V, int *item)
{
    if(i > 0){
        if(V[i][j] == V[i-1][j]){
            item[i] = 0;
            Findwhat(i-1, j, w, v, V, item);           
        }
        else if(j - w[i] >= 0 && V[i][j] == V[i-1][j-w[i]] + v[i]){
            item[i] = 1;
            Findwhat(i-1, j-w[i], w, v, V, item);
        }
    }
}
int Findmax(int number, int capacity, int *w, int *v, int **V)
{
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
    return maxval;
}
int main()
{
    int number, capacity;
    cin >> number >> capacity;

    int **V;
    V = new int *[number+1];
    for(int i = 0; i <= number; ++i){
        V[i] = new int[capacity+1];
    }
    for(int i = 0; i <= number; ++i)
        V[i][0] = 0;
    for(int i = 0; i <= capacity; ++i)
        V[0][i] = 0;

    int* w = new int[number+1];
    int* v = new int[number+1];
    for(int i = 1; i <= number; ++i){
        cin >> w[i] >> v[i];
    }
    int maxvalue = Findmax(number, capacity, w, v, V);
    cout << "The max value is " << maxvalue << endl;
    
    int* item = new int[number+1];
    Findwhat(number, capacity, w, v, V, item);

    for(int i = 0; i <= number; ++i){
        if(item[i] == 1)
            cout << i << " w = " << w[i] << " v = " << v[i] << endl;
        delete[] V[i];
    }
    delete[] V;
    delete[] w;
    delete[] v;
    delete[] item;
    return 0;
}

