#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	int maxlength=1,l;
	bool dp[s.length()][s.length()];
	for(int i=0;i<s.length();i++){
		dp[i][i]=true;
		if(i!=s.length()-1){
			if(s[i]==s[i+1]){
				dp[i][i+1]=true;
				maxlength=2;
			}
			else dp[i][i+1]=false;
		}
	}
	for(l=3;l<=s.length();l++){
		for(int i=0;i+l-1<s.length();i++){
			int j=i+l-1;
			if(s[i]==s[j]&&dp[i+1][j-1]){
				dp[i][j]=true;
				maxlength=l;
			}
		}
	}
	printf("%d",maxlength);
	system("pause");
	return 0;
}