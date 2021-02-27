#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct node{
	double weight;
	vector<int> child;
};
const int MAXN=100001;
node nd[MAXN];
double p,r,ans=0;
void DFS(int index,int height){
	if(nd[index].child.size()==0){
		ans+=nd[index].weight*pow(1+r,height);
		return ;
	}
	for(int i=0;i<nd[index].child.size();i++){
		DFS(nd[index].child[i],height+1);
	}
}
int main(){
	int n,tmp,ch,w;
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100;
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		if(tmp!=0){
			for(int j=0;j<tmp;j++){
				scanf("%d",&ch);
				nd[i].child.push_back(ch);
			}
		}else{
			scanf("%lf",&nd[i].weight);
		}
	}
	DFS(0,0);
	printf("%.1f",p*ans);
	system("pause");
	return 0;
}