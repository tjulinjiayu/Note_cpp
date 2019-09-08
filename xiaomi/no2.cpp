#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int budget;
	while(cin >> n){
		vector<int> prices(n);
		for(int i = 0; i < n; ++i)
			cin >> prices[i];
		cin >> budget;

		//DP
		//二维
		// vector<vector<int>> dp(n, vector<int> (budget+1));
		// for(int i = 0; i < n; ++i)
		// 	dp[i][0] = 0;
		// for(int i = 1; i < budget; ++i)
		// 	dp[0][i] = INT_MAX;
		// int sum = 0;
		// for(int i = 1; i < n; ++i){
		// 	for(int j = 1; j <= budget; ++j){
		// 		for(int k = 0; k <= budget; ++k){
		// 			if(j < k*prices[i])
		// 				dp[i][j] = dp[i-1][j];
		// 			else{

		// 				dp[i][j] = min(dp[i][j], dp[i-1][j - k*prices[i]] + k);
		// 				sum += k*prices[i];
		// 			}
		// 		}
		// 	}
		// }

		//一维解法
		vector<int> dp(budget+1, budget+1);
		dp[0] = 0;
		for(int i = 0; i < n; ++i){
			int p = prices[i];
			for(int j = p; j <= budget; ++j)			
				dp[j] = min(dp[j], dp[j-p]+1);			
		}

		if(dp[budget] != budget+1)
			cout << dp[budget] << endl;
		else
			cout << -1 << endl;

	}
	return 0;
}