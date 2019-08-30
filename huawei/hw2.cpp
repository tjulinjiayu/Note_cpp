/*并查集，每加入一个数字，找到这个数字在矩阵中的位置，然后搜索他的上下左右，
看是不是之前出现过的，如果是并查集合并。最后看是不是只有一个树根。*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define DIGUI 1

int find(vector<int>&par, int num) {
//查找根节点
#ifdef DIGUI	//递归
    if (par[num] == num)
        return num;
    return par[num] = find(par, par[num]);
#else 	//循环
    while(par[num] != num)
    	num = par[num];
    return num;
#endif
}
void unite(vector<int>&par, int num1, int num2) {
    int par_num1 = find(par, num1);
    int par_num2 = find(par, num2);
    par[par_num2] = par_num1;
}
int main() {
    string s;
    vector<vector<int>>m{ {1,2,3,4,5},{11,12,13,14,15},{21,22,23,24,25},{31,32,33,34,35},{41,42,43,44,45} };
    map<int, int>matrix;
    for (int i = 0; i != m.size();++i)
        for (int j = 0; j != m[0].size(); ++j) {
            matrix[m[i][j]] = i * 5 + j;
        }
    int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
    while (getline(cin, s)) {
        vector<int>num;
        int start_index = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == ' ') {
                num.push_back(stoi(s.substr(start_index, i - start_index)));
                start_index = i + 1;
            }
        }
        num.push_back(stoi(s.substr(start_index, s.size() - start_index)));
        map<int, int>num_to_index;
        for (int i = 0; i != num.size(); ++i)
            num_to_index[num[i]] = i;
        vector<int>par = { 0,1,2,3,4,5};
        for (int i = 0; i != num.size(); ++i) {
            int pos = matrix[num[i]];
            int x = pos / 5;
            int y = pos % 5;
            //尝试4个方向
            for (int i = 0; i != 4; ++i) {
                int next_x = x + dir[i][0];//上下移动
                int next_y = y + dir[i][1];//左右移动
                if (next_x < 0 || next_x >= 5 || next_y < 0 || next_y >= 5)//已经在边上
                    continue;
                if (num_to_index.find(m[next_x][next_y]) == num_to_index.end())//判断下一个连通数据有没有在成员列表里
                    continue;//没找到继续找其他方向
                //4个方向都找完还没找到不会执行到这，找到就把下一个与当前位置连通
                unite(par, num_to_index[m[next_x][next_y]], num_to_index[m[x][y]]);
            }
        }
        //查找第一个成员属于哪个根节点
        int pre_par = find(par, num_to_index[num[0]]);
        bool fail = false;
        for (int i = 1; i < num.size(); ++i) {
        	//判断之后成员是否同属于一个根节点下
            int cur_par = find(par, num_to_index[num[i]]);
            if (cur_par != pre_par) {
                cout << 0 << endl;
                fail = true;
                break;
            }
        }
        if (!fail)
            cout << 1 << endl;
    }
 
}

//借鉴leetcode200岛屿数量问题,有问题
// #include <iostream>
// #include <map>
// #include <vector>
// using namespace std;
// int count = 0;

// void helper(vector<vector<int>>& matrix, int i, int j, map<int, int> map1) {
//     map<int, int>::iterator it;
// 	it = map1.find(matrix[i][j]);
//     if (i<0 || i>=matrix.size() || j<0 || j>= matrix[0].size() || it == map1.end()) {
//         return;
//     }

// 	if(it != map1.end()){
//         count++;
//         matrix[i][j] = -1;
//     }
//     helper(matrix, i-1, j, map1);
//     helper(matrix, i, j+1, map1);
//     helper(matrix, i+1, j, map1);       
//     helper(matrix, i, j-1, map1);      
// }


// int main(int argc, char const *argv[])
// {
// 	vector<vector<int>> matrix = {
// 		{1,2,3,4,5},
// 		{11,12,13,14,15},
// 		{21,22,23,24,25},
// 		{31,32,33,34,35},
// 		{41,42,43,44,45}
// 	};

// 	map<int, int> map1;
	
// 	vector<int> member(6);
// 	while(cin >> member[0]){
// 		for(int i = 1; i < 6; ++i)
// 			cin >> member[i];
		
// 		int m = matrix.size(), n = matrix[0].size();
// 		bool isHave = false;

// 		map<int, int>::iterator it;

// 		for(int i = 0; i < m; ++i){
// 			for(int j = 0; j < n; ++j){
// 				it = map1.find(matrix[i][j]);
// 				if(it != map1.end()){
// 					helper(matrix, i, j, map1);
// 					if(count == 6)
// 						cout << 1 << endl;
// 					else 
// 						cout << 0 << endl;
// 					isHave = true;
// 					break;
// 				}
// 			}
// 			if(isHave)
// 				break;
// 		}
// 	}
// 	return 0;
// }

//王总解法
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main(int argc, char const *argv[])
// {
// 	vector<int> nums(6);
// 	while(cin >> nums[0]){
// 		for(int i=1; i<6; ++i)
// 			cin >> nums[i];

// 		sort(nums.begin(), nums.end());

// 		vector<int> nums_copy=nums;

// 		for(int i=0; i<6; ++i){
// 			while(nums[i]>9)
// 				nums[i] %= 10;
// 		}
// 		int ans=1;
// 		for(int i=0; i<5; ++i){
// 			if(nums[i+1]-nums[i]>1){
// 				ans=0;
// 				break;
// 			}
// 		}

// 		if(ans==1){
// 			for(int i=0; i<6; ++i){
// 				while(nums_copy[i]>9)
// 					nums_copy[i] /= 10;
// 				if(i>1 && (nums_copy[i]-nums_copy[i-1]>1)){
// 					ans=0;
// 					break;
// 				}
// 			}
// 		}
// 		cout << ans << endl;
// 	}
// 	return 0;
// }


//牛客解法：
// #include <bits/stdc++.h>
// using namespace std;
 
// int mp[10][10];
// int s[10];
 
// int fa[100];
// void init() {
//     for(int i=0; i<60; i++)
//         fa[i] = i;
// }
 
// int _fi(int x) {
//     return fa[x] == x ? x : fa[x] = _fi(fa[x]);
// }
 
// void _merge(int u, int v) {
//     int fu = _fi(u);
//     int fv = _fi(v);
//     fa[fu] = fv;
//     return ;
// }
 
// bool ok(int u, int v) {
//     if(u -1 == v || u + 1 == v || u-10 == v || u+10 == v)
//         return true;
//     return false;
// }
 
// int main() {
//     while(~scanf("%d %d %d %d %d %d", &s[1], &s[2], &s[3], &s[4], &s[5], &s[6])) {
//         init();
//         for(int i=1; i<=6; i++) {
//             for(int j=i+1; j<=6; j++) {
//                 int u = s[i], v = s[j];
//                 if(ok(u,v)) {
//                     // cout << u <<" " << v <<endl;
//                     _merge(i, j);
//                 }
//             }
//         }
//         bool f = true;
//         for(int i=2; i<=6; i++) {
//             if(_fi(i) != _fi(i-1)) {
//                 f = false;
//                 break;
//             }
//         }
//         if(f) puts("1");
//         else puts("0");
//     }
//     return 0;
// }