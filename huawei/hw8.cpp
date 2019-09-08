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
	int n, m;
	while(cin >> n >> m){
		vector<vector<ll>> f(n+1, vector<ll> (m+1, 0));

		for(int i = 0; i <= n; ++i)
			f[i][0] = 1;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j)
				for(int k = 0; k <= j; ++k)
						f[i][j] = (f[i][j]+f[i-1][j-k])%1000000007;
		}
		cout << f[n][m] << endl;
	}
	return 0;
}