#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int father[1001],isroot[1001]={0};
bool cmp(int a,int b){
	return a>b;
}
void init(int n){
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
}
int findroot(int n){	//查找根节点
	if(father[n]==n) return n;
	else{
		father[n]=findroot(father[n]);
		return father[n];
	}
}
void Union(int x,int y){	//合并
	int fx=findroot(x);
	int fy=findroot(y);
	father[fy]=fx;
}
int main(){
	int n,sum,tmp,cnt=0;
	int hobby[1001]={0};
	scanf("%d",&n);
	init(n);
	for(int i=1;i<=n;i++){
		scanf("%d: ",&sum);
		for(int j=0;j<sum;j++){
			scanf("%d",&tmp);
			if(hobby[tmp]==0){
				hobby[tmp]=i;
			}
			Union(i,findroot(hobby[tmp]));
		}
	}
	for(int i=1;i<=n;i++){
		isroot[findroot(i)]++;
	}
	for(int i=1;i<=n;i++){
		if(isroot[i]!=0) cnt++;
	}
	printf("%d\n",cnt);
	sort(isroot,isroot+1001,cmp);
	for(int i=0;i<cnt;i++){
		if(i!=0) printf(" ");
		printf("%d",isroot[i]);
	}
	system("pause");
	return 0;
}