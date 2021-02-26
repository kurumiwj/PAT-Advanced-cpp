#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

struct node{
	int data;
	node *left,*right;
};
typedef node* Node;
vector<int> in,pre,post;
// void insert(int x,Node &root){
// 	if(root==NULL){
// 		root->data=x;
// 		root->left=root->right=NULL;
// 		return ;
// 	}else if(x<root->data)
// 		insert(x,root->left);
// 	else insert(x,root->right);
// }
Node Create(int inL,int inR,int preL,int preR){
	Node root=new node;
	if(preL>preR||inL>inR) return NULL;
	else{
		int k;
		for(k=inL;k<=inR;k++)
			if(in[k]==pre[preL]) break;
		root->data=pre[preL];
		root->left=Create(inL,k-1,preL+1,preL+k-inL);
		root->right=Create(k+1,inR,preL+k-inL+1,preR);
		return root;
	}
}
void postOrder(Node root){
	if(root==NULL) return ;
	postOrder(root->left);
	postOrder(root->right);
	post.push_back(root->data);
}
int main(){
	int n,nd;
	scanf("%d",&n);
	string op;
	stack<int> st;
	for(int i=0;i<2*n;i++){
		cin>>op;
		if(op=="Push"){	//若输入的字符串是Push
			scanf("%d",&nd);
			pre.push_back(nd);
			st.push(nd);
		}
		else{	//输入的字符串是Pop
			in.push_back(st.top());
			st.pop();
		}
	}
	Node root=Create(0,n-1,0,n-1);
	postOrder(root);
	for(int i=0;i<n;i++){
		if(i!=0) printf(" ");
		printf("%d",post[i]);
	}
	system("pause");
	return 0;
}