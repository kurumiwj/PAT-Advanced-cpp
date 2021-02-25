#include <iostream>
#include <vector>
using namespace std;

struct node{
	int data;
	node *left,*right;
};
typedef node* Node;
void insert(Node &root,int x){	//插入节点
	if(root==NULL){	//空树
		root=new node;
		root->data=x;
		root->left=root->right=NULL;
		return ;
	}else if(x<root->data)
		insert(root->left,x);
	else
		insert(root->right,x);
}
Node Create(vector<int> v){	//建树
	Node root=new node;
	root=NULL;
	for(int i=0;i<v.size();i++){
		insert(root,v[i]);
	}
	return root;
}
vector<int> pre,preMirror,post,postMirror;	//存放BST和镜像的先序序列以及后序序列和镜像序列
void PostOrder(Node root){
	if(root==NULL) return ;
	PostOrder(root->left);
	PostOrder(root->right);
	post.push_back(root->data);
}
void PostOrderMirror(Node root){
	if(root==NULL) return ;
	PostOrderMirror(root->right);
	PostOrderMirror(root->left);
	postMirror.push_back(root->data);
}
void PreOrder(Node root){
	if(root==NULL) return ;
	pre.push_back(root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
void PreOrderMirror(Node root){
	if(root==NULL) return ;
	preMirror.push_back(root->data);
	PreOrderMirror(root->right);
	PreOrderMirror(root->left);
}
int main(){
	int n,tmp;
	Node root=new node;
	vector<int> v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		v.push_back(tmp);
	}
	root=Create(v);
	PreOrder(root);
	bool flag=true;
	if(pre!=v) flag=false;
	if(flag){
		printf("YES\n");
		PostOrder(root);
		for(int i=0;i<n;i++){
			if(i!=0) printf(" ");
			printf("%d",post[i]);
		}
	}else{
		flag=true;
		PreOrderMirror(root);
		if(preMirror!=v) flag=false,printf("NO\n");
		if(flag){
			printf("YES\n");
			PostOrderMirror(root);
			for(int i=0;i<n;i++){
				if(i!=0) printf(" ");
				printf("%d",postMirror[i]);
			}
		}
	}
	system("pause");
	return 0;
}