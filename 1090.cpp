#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

double p,r,ans=0;
int cnt=0;
struct node{
	vector<int> child;
};
node nd[100001];
void DFS(int index,int height,double sum){
	if(nd[index].child.size()==0){
		sum+=p*pow(1+r,height);
		if(sum>ans){
			ans=sum;
			cnt=1;
		}
		else if(sum==ans) cnt++;
		return ;
	}
	for(int i=0;i<nd[index].child.size();i++){
		DFS(nd[index].child[i],height+1,sum);
	}
}
int main(){
	int n,tmp,root;
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100;
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		if(tmp==-1) root=i;
		else{
			nd[tmp].child.push_back(i);
		}
	}
	DFS(root,0,0);
	printf("%.2f %d",ans,cnt);
	system("pause");
	return 0;
}