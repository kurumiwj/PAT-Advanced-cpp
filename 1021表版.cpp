#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 10001
using namespace std;

struct node{
	vector<int> adjv;
}nd[MAXN];
int n,component=0,maxHeight=1,maxtmpHeight=1;	//分别记录总节点数，连通块，所有节点为根当中的最大高度，以当前节点为根的最大高度
bool visit[MAXN]={false},visit1[MAXN]={false};	//一个处理连通块的遍历，一个处理最大高度的遍历
int height[MAXN];
void DFS(int index,int depth,int flag){
	if(flag==0){
		if(visit[index]==true) return ;
		visit[index]=true;
		for(int i=0;i<nd[index].adjv.size();i++){
			if(!visit[nd[index].adjv[i]]){
				DFS(nd[index].adjv[i],depth+1,flag);
			}
		}
	}else{
		if(visit1[index]==true) return ;
		visit1[index]=true;
		if(depth>maxtmpHeight) maxtmpHeight=depth;
		if(maxtmpHeight>maxHeight) maxHeight=maxtmpHeight;
		for(int i=0;i<nd[index].adjv.size();i++){
			if(!visit1[nd[index].adjv[i]]){
				DFS(nd[index].adjv[i],depth+1,flag);
			}
		}
	}
}
void DFSTraversal(){	//遍历连通块的个数以及统计以每个节点为根所能达到的最大树高
	for(int i=1;i<=n;i++){
		fill(visit1+1,visit1+n+1,false);
		if(!visit[i]){
			DFS(i,1,0);	//未访问过j且i到j有边则向下遍历
			component++;
		}
		if(!visit1[i]){
			maxtmpHeight=1;
			DFS(i,1,1);
			height[i]=maxtmpHeight;
		}
	}
}
int main(){
	int v1,v2;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&v1,&v2);
		nd[v1].adjv.push_back(v2);
		nd[v2].adjv.push_back(v1);
	}
	fill(visit+1,visit+n+1,false);
	DFSTraversal();
	if(component>1) printf("Error: %d components",component);
	else{
		for(int i=1;i<=n;i++)
			if(height[i]==maxHeight) printf("%d\n",i);
	}
	system("pause");
	return 0;
}