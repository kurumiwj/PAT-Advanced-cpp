#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool Palindromic(string n){
	int i=0,j=n.length()-1;
	while(i<j)
		if(n[i]==n[j]) i++,j--;
		else return false;
	return true;
}
string bignumPlus(string a,string b){	//b是a的反转字符串，长度必相同
	string c;
	int i=a.length()-1,r=0,cnt=0;	//r存放进位，cnt记录c的位数
	while(i>=0){
		int tmp=a[i]-'0'+b[i]-'0'+r;
		c+=(tmp%10+'0');
		r=tmp/10;
		i--;
	}
	if(r>0) c+=(r+'0');
	reverse(c.begin(),c.end());
	return c;
}
int main(){
	string n;
	cin>>n;
	int k,i=0;
	scanf("%d",&k);
	for(i=0;i<k;i++){
		if(Palindromic(n)){
			cout<<n<<endl<<i;
			break;
		}
		else{
			string tmp=n;
			reverse(tmp.begin(),tmp.end());
			n=bignumPlus(n,tmp);
		}
	}
	if(i==k) cout<<n<<endl<<k;
	system("pause");
	return 0;
}