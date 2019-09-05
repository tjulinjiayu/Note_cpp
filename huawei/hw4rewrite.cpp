#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	while(scanf("%d\n", &n)){
		map<string, int> is;
		map<string, int> val;
		string ans;
		//输入每行表达式并处理
		for(int i = 0; i < n; ++i){
			char s[10000];
			gets(s);
			int s_len = strlen(s);
			int j = 0;
			vector<string> var;
			while(j < s_len){			
				while(j < s_len && s[j] == ' ')	++j;	//忽略表达式前空格
				if(j == s_len)	break;

				int pre = j;
				while(j < s_len && (s[j] != '=' && s[j] != '+'))	++j;	//遇到等号
				while(s[j-1] == ' ')	--j;	//回退到空格前
				char v[10000];//定义用于存储分割字符串的数组	
				int v_len = 0;
				for(int k = pre; k < j; ++k)
					v[v_len++] = s[k];
				v[j] = '\0';
				string vtemp(v);
				var.push_back(vtemp);

				while(j < s_len && s[j] == ' ') ++j;
				++j;
			}

			int sum = 0;
			int flag = 0;
			for(int p = 1; p < var.size(); ++p){
				if(var[p][0] >= '1' && var[p][0] <= '9'){
					int convtoint = 0;
					for(int q = 0; q < var[p].size(); ++q)
						convtoint = convtoint * 10 + var[p][q] - '0';		 	
					sum += convtoint;
					continue;
				}
				if(var[p][0] == '-'){
					int convtoint = 0;
					for(int q = 1; q < var[p].size(); ++q)
						convtoint = convtoint * 10 + var[p][q] - '0';
					sum += -convtoint;
					continue;
				}
				if(is[var[p]] == 1){
					sum += val[var[p]];
					continue;
				}
				if(is[var[p]] == 0){
					flag = 1;
					break;
				}
			}

			ans = var[0];
			if(flag == 0){
				is[ans] = 1;
				val[ans] = sum;
			}
		}

		if(!is[ans])
			cout << "NA" << endl;
		else
			cout << val[ans] << endl;

	}
	return 0;
}