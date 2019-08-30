/*思路是联立a2+b2=c2和a+b+c=周长,最后得到a和b的关系，枚举a，
记录第一个可行的b，当出现a==第一个可行的b的情况，就可以退出了*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int p;
	while(cin >> p){
		int count = 0;
		for(int i = 1; i < p/3; ++i){
			double j = p - (double) p * p / (2 * p - 2 * i);
			if(i < j && j - (int) j < 1e-5)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
 
// int n;
// typedef long long ll;
// inline bool ok(ll i, ll j, ll k) {
//     ll a = i*i+j*j;
//     ll b = k*k;
//     return a == b;
// }
 
// int main() {
//     while (cin >> n) {
//         // cout << ok(20, 48, 52) <<endl;
//         int cnt = 0;
//         for(int i=1; i<=n/3; i++) {
//             for(int j=i; i+j+j<=n; j++) {
//                 int k = n-i-j;
//                 if(i+j > k && ok(i,j,k)) {
//                     cnt++;
//                     //cout << i <<" " << j <<" " << k<<endl;
//                 }
//             }
//         }
//         printf("%d\n", cnt);
//     }
//     return 0;
// }