#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <math.h>
#define N 350	//每组最多存放的个数
using namespace std;

int stoi(string a,int m,int n){
	int ret=0;
	while(m<=n){
		ret=ret*10+a[m++]-'0';
	}
	return ret;
}
void Push(stack<int> &st,int x,int count[],int block[]){
	st.push(x);
	block[x/N]++;
	count[x]++;
}
void Pop(stack<int> &st,int count[],int block[]){
	int tmp=st.top();
	st.pop();
	block[tmp/N]--;
	count[tmp]--;
	printf("%d\n",tmp);
}
void Median(int count[],int block[],int x){
	int sum=0,num=0;
	while(sum+block[num]<x){
		sum+=block[num++];
	}
	int start=num*N;
	while(sum<=x){
		sum+=count[start++];
	}
	printf("%d\n",start-1);
}
int main(){
	stack<int> st;
	int n,tmpPush,tmpPop;
	string tmp;
	scanf("%d",&n);
	cin.ignore();
	int block[N]={0},count[100005]={0};
	for(int i=0;i<n;i++){
		getline(cin,tmp);
		if(tmp=="Pop"){
			if(st.size()==0) printf("Invalid\n");
			else{
				Pop(st,count,block);
			}
		}else if(tmp.substr(0,4)=="Push"){
			tmpPush=stoi(tmp,5,tmp.length()-1);
			Push(st,tmpPush,count,block);
		}else{
			if(st.size()==0) printf("Invalid\n");
			else{
				if(st.size()%2==0){
					int med=st.size()/2-1;
					Median(count,block,med);
				}
				else{
					int med=(st.size()+1)/2-1,sum=0,num=0;
					Median(count,block,med);
				}
			}
		}
	}
	system("pause");
	return 0;
}