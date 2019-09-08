#include <iostream>
#include <unordered_map>
#include <map>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

//字符串分割函数
vector<string> strcut(string &str)
{
	int len = str.size();
	int j = 0;
	vector<string> res;
	while(j < len){
		//空格处理
		while(j < len && str[j] == ' ') ++j;
		int start = j;
		while(j < len && (str[j] != '=' && str[j] != '+')) ++j;
		int end = j;
		while(str[end-1] == ' ') --end;		
		string temp = str.substr(start, end - start);//（起始位置，长度）
		res.push_back(temp);
		++j;
	}
	return res;
}

//计算函数
bool cal(vector<string>& cut, unordered_map<string, int>& val, int& ans)
{
	ans = 0;
	int v_len = cut.size();
	for(int i = 1; i < v_len; ++i){
		if(cut[i][0] >= '1' && cut[i][0] <= '9'){
			int num = 0;
			for(int j = 0; j < cut[i].size(); ++j)
				num = num * 10 + cut[i][j] - '0'; 
			ans += num;
		}
		else if(cut[i][0] == '-'){
			int num = 0;
			for(int j = 1; j < cut[i].size(); ++j)
				num = num * 10 + cut[i][j] - '0'; 
			ans -= num;
		}
		else{
			if(val.find(cut[i]) == val.end())
				return false;
			else
				ans += val[cut[i]];
		}
	}
	val[cut[0]] = ans;
	return true;
}

int main(int argc, char const *argv[])
{
	int n;	//表达式行数
	while(cin >> n){
		cin.get();	//消除输入流中的换行符
		unordered_map<string, int> val;
		int ans;
		bool status;
		for(int i = 0; i < n; ++i){
			string str;
			getline(cin, str);	//cin遇到空格会中断
			vector<string> cut = strcut(str);
			status = cal(cut, val, ans);
		}
		if(status)
			cout << ans << endl;
		else
			cout << "NA" << endl;
	}
	return 0;
}


// int main()
// {
// 	int n;
// 	while(scanf("%d\n", &n)){
// 		map<string, int> is;
// 		map<string, int> val;
// 		string ans;
// 		//输入每行表达式并处理
// 		for(int i = 0; i < n; ++i){
// 			char s[10000];
// 			gets(s);
// 			int s_len = strlen(s);
// 			int j = 0;
// 			vector<string> var;
// 			while(j < s_len){			
// 				while(j < s_len && s[j] == ' ')	++j;	//忽略表达式前空格
// 				if(j == s_len)	break;

// 				int pre = j;
// 				while(j < s_len && (s[j] != '=' && s[j] != '+'))	++j;	//遇到等号
// 				while(s[j-1] == ' ')	--j;	//回退到空格前
// 				char v[10000];//定义用于存储分割字符串的数组	
// 				int v_len = 0;
// 				for(int k = pre; k < j; ++k)
// 					v[v_len++] = s[k];
// 				v[j] = '\0';
// 				string vtemp(v);
// 				var.push_back(vtemp);

// 				while(j < s_len && s[j] == ' ') ++j;
// 				++j;
// 			}

// 			int ans = 0;
// 			int flag = 0;
// 			for(int p = 1; p < var.size(); ++p){
// 				if(var[p][0] >= '1' && var[p][0] <= '9'){
// 					int convtoint = 0;
// 					for(int q = 0; q < var[p].size(); ++q)
// 						convtoint = convtoint * 10 + var[p][q] - '0';		 	
// 					ans += convtoint;
// 					continue;
// 				}
// 				if(var[p][0] == '-'){
// 					int convtoint = 0;
// 					for(int q = 1; q < var[p].size(); ++q)
// 						convtoint = convtoint * 10 + var[p][q] - '0';
// 					ans += -convtoint;
// 					continue;
// 				}
// 				if(is[var[p]] == 1){
// 					ans += val[var[p]];
// 					continue;
// 				}
// 				if(is[var[p]] == 0){
// 					flag = 1;
// 					break;
// 				}
// 			}

// 			ans = var[0];
// 			if(flag == 0){
// 				is[ans] = 1;
// 				val[ans] = ans;
// 			}
// 		}

// 		if(!is[ans])
// 			cout << "NA" << endl;
// 		else
// 			cout << val[ans] << endl;

// 	}
// 	return 0;
// }