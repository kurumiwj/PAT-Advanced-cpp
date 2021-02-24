#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,s;
const int MAXN=102;
int path[MAXN];
struct node{
	int weight;
	vector<int> child;
}w[MAXN];
bool cmp(int a,int b){
	return w[a].weight>w[b].weight;
}
void DFS(int index,int num,int total){	//index记录当前访问的节点，num记录已经收录到path的节点总数，total记录总权值
	if(total>s) return ;
	if(total==s){
		if(w[index].child.size()!=0) return ;	//未到叶子节点直接舍弃
		for(int i=0;i<num;i++)
			printf("%d%c",w[path[i]].weight,i!=num-1?' ':'\n');
		return ;
	}
	for(int i=0;i<w[index].child.size();i++){
		int Node=w[index].child[i];
		path[num]=Node;
		DFS(Node,num+1,total+w[Node].weight);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n;i++)
		scanf("%d",&w[i].weight);
	for(int i=0;i<m;i++){
		int tmp,cnt,ch;	//第tmp个节点有cnt个孩子
		scanf("%d%d",&tmp,&cnt);
		for(int j=0;j<cnt;j++){
			scanf("%d",&ch);
			w[tmp].child.push_back(ch);
		}
		sort(w[tmp].child.begin(),w[tmp].child.end(),cmp);
	}
	DFS(0,1,w[0].weight);
	system("pause");
	return 0;
}