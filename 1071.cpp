#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	string s,word;
	getline(cin,s);
	map<string,int> cnt;
	int max=0,index=0;
	string tmp;
	while(index<s.length()){	//以非有效字符为分界统计单词出现次数
		if(isalnum(s[index])) s[index]=tolower(s[index]),tmp+=s[index];
		if(!isalnum(s[index])&&tmp.length()!=0){
			cnt[tmp]++;
			if(max<cnt[tmp]) max=cnt[tmp],word=tmp;
			else if(max==cnt[tmp]) if(tmp<word) word=tmp;
			tmp="";
		}
		index++;
	}
	if(tmp.length()!=0){
		cnt[tmp]++;
		if(max<cnt[tmp]) max=cnt[tmp],word=tmp;
		else if(max==cnt[tmp]) if(tmp<word) word=tmp;
	}
	cout<<word<<" "<<max;
	system("pause");
	return 0;
}