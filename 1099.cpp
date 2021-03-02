#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> in,level;
struct node{
	int data;	//节点存放的数据
	int left,right;	//左孩子右孩子
};
node nd[101];
int cnt=0;
void inOrder(int root){
	if(root==-1) return ;
	inOrder(nd[root].left);
	nd[root].data=in[cnt++];
	inOrder(nd[root].right);
}
void levelOrder(int root){
	if(root==-1) return ;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		level.push_back(tmp);
		if(nd[tmp].left!=-1) q.push(nd[tmp].left);
		if(nd[tmp].right!=-1) q.push(nd[tmp].right);
	}
}
int main(){
	int n,tmpleft,tmpright,tmp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&tmpleft,&tmpright);
		nd[i].left=tmpleft;
		nd[i].right=tmpright;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		in.push_back(tmp);
	}
	sort(in.begin(),in.end());
	inOrder(0);
	levelOrder(0);
	for(int i=0;i<level.size();i++){
		if(i!=0) printf(" ");
		printf("%d",nd[level[i]].data);
	}
	system("pause");
	return 0;
}