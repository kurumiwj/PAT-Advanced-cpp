#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int maxn=1000000007;
int main(){
	string s;
	cin>>s;
	int ans=0,len=s.length(),RightTNum=0;
	int LeftPNum[len]={0};
	for(int i=0;i<len;i++){
		if(i>0) LeftPNum[i]=LeftPNum[i-1];
		if(s[i]=='P') LeftPNum[i]++;
	}
	for(int i=len-1;i>=0;i--)
		if(s[i]=='T') RightTNum++;
		else if(s[i]=='A') ans=(ans+RightTNum*LeftPNum[i])%maxn;
	printf("%d\n",ans);
	system("pause");
	return 0;
}