#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN=32;
struct Node{
	int data;
	Node *Left;
	Node *Right;
};
vector<int> in(MAXN),post(MAXN);
Node *Create(int postL,int postR,int inL,int inR){
	if(postL>postR||inL>inR)
		return NULL;
	int i;
	for(i=inL;i<=inR;i++)	//通过中序序列划分左右子树
		if(in[i]==post[postR])
			break;
	Node *root=new Node;
	root->data=post[postR];
	root->Left=Create(postL,postL+i-inL-1,inL,i-1);
	root->Right=Create(postL+i-inL,postR-1,i+1,inR);
	return root;
}
void levelOrderTraversal(Node *root){	//层序遍历
	queue<Node *> q;
	if(root==NULL) return ;
	q.push(root);
	while(!q.empty()){
		Node *a=q.front();
		printf("%d",a->data);
		q.pop();
		if(a->Left) q.push(a->Left);
		if(a->Right) q.push(a->Right);
		if(!q.empty()) printf(" ");
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&post[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&in[i]);
	Node *root=Create(1,n,1,n);
	levelOrderTraversal(root);
	system("pause");
	return 0;
}