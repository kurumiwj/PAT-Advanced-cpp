#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1000005
using namespace std;

int data[MAXN],Next[MAXN],adjust[MAXN];
int main(){
	int start,n,k,address,cnt=0;
	scanf("%d%d%d",&start,&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&address);
		scanf("%d%d",&data[address],&Next[address]);
	}
	int start2=start,pre,tmp=start;
	bool flag=false;
	for(int i=0;i<n;i++){
		if(data[tmp]<0){
			if(flag==false){
				flag=true;
				start=tmp;
				pre=start;
			}
			else{
				adjust[pre]=tmp;
				pre=tmp;
			}
		}
		cnt++;
		tmp=Next[tmp];
		if(tmp==-1) break;
	}
	tmp=start2;
	for(int i=0;i<n;i++){
		if(data[tmp]<=k&&data[tmp]>=0){
			adjust[pre]=tmp;
			pre=tmp;
		}
		tmp=Next[tmp];
		if(tmp==-1) break;
	}
	tmp=start2;
	for(int i=0;i<n;i++){
		if(data[tmp]>k){
			adjust[pre]=tmp;
			pre=tmp;
		}
		tmp=Next[tmp];
		if(tmp==-1) break;
	}
	tmp=start;
	for(int i=0;i<cnt;i++){
		if(i!=cnt-1)
			printf("%05d %d %05d\n",tmp,data[tmp],adjust[tmp]);
		else printf("%05d %d -1\n",tmp,data[tmp]);
		tmp=adjust[tmp];
	}
	system("pause");
	return 0;
}
