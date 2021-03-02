#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
/*
struct node{
	int data;
	node *left,*right;
};
typedef node* Node;
vector<int> in,level,pre;
void preCreate(int left,int right){
	if(left>right) return ;
	if(left==right){
		pre.push_back(in[left]);
		return ;
	}
	int n=right-left+1;
	int m=ceil(log(n)/log(2));
	pre.push_back(in[left+n-m]);
	preCreate(left,left+n-m-1);
	preCreate(left+n-m+1,right);
}
Node Create(int preleft,int preright,int inleft,int inright){
	if(preleft>preright||inleft>inright) return NULL;
	Node root=new node;
	root->data=pre[preleft];
	int k;
	for(k=0;k<in.size();k++){
		if(in[k]==pre[preleft]) break;
	}
	root->left=Create(preleft+1,preleft+k-inleft,inleft,k-1);
	root->right=Create(preleft+k-inleft+1,preright,k+1,inright);
	return root;
}
void levelOrder(Node root){
	queue<Node> q;
	q.push(root);
	while(!q.empty()){
		Node tmp=q.front();
		q.pop();
		level.push_back(tmp->data);
		if(tmp->left) q.push(tmp->left);
		if(tmp->right) q.push(tmp->right);
	}
}
int main(){
	int n,tmp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		in.push_back(tmp);
	}
	sort(in.begin(),in.end());
	preCreate(0,n-1);
	Node root=Create(0,n-1,0,n-1);
	levelOrder(root);
	for(int i=0;i<level.size();i++){
		if(i!=0) printf(" ");
		printf("%d",level[i]);
	}
	system("pause");
	return 0;
}
*/
vector<int> in,CBT(1001);
int n,cnt=0;
void inCreate(int root){
	if(root>n) return ;
	inCreate(root*2);
	CBT[root]=in[cnt++];
	inCreate(root*2+1);
}
int main(){
	int tmp;
	scanf("%d",&n);
	fill(CBT.begin(),CBT.end(),-1);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		in.push_back(tmp);
	}
	sort(in.begin(),in.end());
	inCreate(1);
	for(int i=1;i<=n;i++){
		if(i!=1) printf(" ");
		printf("%d",CBT[i]);
	}
	system("pause");
	return 0;
}