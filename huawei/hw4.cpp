#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <string>
#include <set>
#include <queue>
#include <climits>
#include <unordered_set>
#include <map>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <map>
using namespace std;
// typedef long long LL;
// const LL mod = 1000000007;
// using namespace std;
// const int inf = 0x7f7f7f7f;
//int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

int main(){
    int n;
    while(scanf("%d\n", &n)){
        map<string,int> is;
        map<string,int> val;
        char s[10000];
        string ans_tmp;
        //每行表达式的处理
        for(int j = 0; j < n; ++j){
            gets(s);
            int s_len = strlen(s);//表达式字符串的长度
            int i = 0;
            vector<string> var;//保存当前分割出来的变量
            var.clear();
            //此循环完成了一个字符串的分割，并保存在var数组中
            while(i < s_len){
                while(i < s_len && s[i] ==' ') i++;//遇到' '则跳过，继续往字符串后面遍历，到字符串末尾了退出
                if(i == s_len) break;
                //空格结束，表达式开始
                char v[10000];//用了固定长度数组，能否动态？
                int v_len = 0;
                int pre = i;//记录表达式开始的位置
                while(i < s_len && (s[i] != '=' && s[i] != '+')) i++;//没遇到'='和'+'则继续往后遍历
                while(i>=1 && s[i - 1] == ' ') i--;//遇到'='和'+'时判断等号前面是不是' '，回退到空格前，此时i记录了等式左边变量的长度
     
                for(int k = pre; k < i ;k++){
                    v[v_len++] = s[k];//往v数组中存当前等式左边变量
                }
                v[v_len] = '\0';//添加字符串结束符
                string tmp(v);//保存当前字符串到var数组中
                var.push_back(tmp);
                while(i<s_len && s[i] == ' ') i++;//记录变量之前退回到了空格之前，需要再回到空格后
                i++;//跳过'='或者'+'
            }

            //下面这部分完成运算
            int sum = 0;
            int flag = 0;  
            for(int q=1;q<var.size();q++){  //从右边第一个字符串开始
                if(var[q][0] >='1' && var[q][0] <= '9'){    //判断是不是数字
                    string tmp = var[q];
                    int ans = 0;
                    for(int p = 0;p<tmp.size();p++){
                        ans = ans * 10 + tmp[p] - '0';  //把数字字符串转换为十进制数
                    }
                    sum += ans;     //累加数字变量结果，因为只有'+'
                    continue;
                }
                if(var[q][0] == '-'){   //考虑了'-'的情况
                    string tmp = var[q];
                    int ans = 0;
                    for(int p = 1;p<tmp.size();p++){
                        ans = ans * 10 + tmp[p] - '0';
                    }
                    sum += -ans;
                    continue;
                }
                //既不是数字也不是'-'，遇到另一个变量
                if(is[var[q]] == 1){
                    sum += val[var[q]];
                    continue;
                }
                if(is[var[q]] == 0){
                    flag = 1;
                    break;
                }
            }
            ans_tmp = var[0];   // 左边的变量
            if(flag == 0){      
                is[var[0]] = 1;     //每个表达式成功赋值都会将对应左边的变量建立映射
                val[var[0]] = sum;
            }
     
        }

        if(!is[ans_tmp]){
            cout <<"NA"<< endl;
        }
        else{
            cout << val[ans_tmp]<< endl;
        }
    }
    return 0;
}