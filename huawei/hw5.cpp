#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
typedef long long ll;
using namespace std;

int main()
{
	int n;
	vector<int> box{4,9};
	while(cin >> n){
		// //数学方法
		// int max_4 = n/4;
		// for (int i = 0; i <= max_4; ++i){
		// 	double j = (double) (n - 4*i) / 9;
		// 	if((int) j == j){
		// 		cout << i+j << endl;
		// 		break;
		// 	}
		// 	if(i == max_4)
		// 		cout << -1 << endl;
		// }
		//动态规划
		vector<int> f(n+1, n+1);
		f[0] = 0;
		for(int i = 1; i < n+1; ++i){
			for(int h : box){
				if(h > i) continue;
				f[i] = min(f[i], f[i-h]+1);
			}
		}
		if(f[n] == n+1) cout << -1 << endl;
		else cout << f[n] << endl;
	}
	return 0;
}