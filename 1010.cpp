#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

map<char,int> mp;
long long my_pow(int radix,int n){
	long long pow=1;
	for(int i=0;i<n;i++) pow*=radix;
	if(pow<0) return -1;	//溢出
	else return pow;
}
long long stringToLong(string a,int radix){
	long long digit=0;
	for(int i=a.length()-1;i>=0;i--){
		long long tmp=my_pow(radix,a.length()-i-1);
		if(tmp==-1) return -1;
		else digit+=mp[a[i]]*tmp;
	}
	return digit;
}
int two_pointers(string a,long long b){	//二分查找
	char c=*max_element(a.begin(),a.end());
	long long left=mp[c]+1,right=max(left,b),mid;
	while(left<=right){
		mid=(left+right)/2;
		long long tmp=stringToLong(a,mid);
		if(tmp==b) return mid;
		else if(tmp<0||tmp>b) right=mid-1;
		else left=mid+1;
	}
	return -1;
}
int main(){
	for(char c='0';c<='9';c++) mp[c]=c-'0';
	for(char c='a';c<='z';c++) mp[c]=10+c-'a';
	string n[3];
	cin>>n[1]>>n[2];
	int tag,radix,ans;
	scanf("%d%d",&tag,&radix);
	long long digit[3]={0};
	digit[tag]=stringToLong(n[tag],radix);
	ans=two_pointers(n[3-tag],digit[tag]);
	if(digit[tag]==-1||ans==-1) printf("Impossible");
	else printf("%d",ans);
	system("pause");
	return 0;
}