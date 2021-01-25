#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string a,string b){
	return a+b<b+a;
}
int main(){
	int n;
	scanf("%d",&n);
	string telephone[n];
	for(int i=0;i<n;i++) cin>>telephone[i];
	sort(telephone,telephone+n,cmp);
	string number;
	for(int i=0;i<n;i++) number+=telephone[i];
	for(int i=0;i<number.length();)
		if(number[i]=='0') number.erase(number.begin());
		else break;
	if(number.length()==0) printf("0");
	else cout<<number;
	system("pause");
	return 0;
}