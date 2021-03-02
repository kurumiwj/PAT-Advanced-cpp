#include <iostream>
#include <vector>
using namespace std;

struct node{
	int data,height;
	node *left,*right;
};
typedef node* Node;
int getHeight(Node root){	//获得当前节点高度
	if(root==NULL) return 0;
	return root->height;
}
int getBalanceFactor(Node root){	//获取平衡因子
	return getHeight(root->left)-getHeight(root->right);
}
void updateHeight(Node root){	//更新树高
	root->height=max(getHeight(root->left),getHeight(root->right))+1;
}
void leftRotation(Node &root){	//左旋
	Node tmp=root->right;
	root->right=tmp->left;
	tmp->left=root;
	updateHeight(root);
	updateHeight(tmp);
	root=tmp;
}
void rightRotation(Node &root){	//右旋
	Node tmp=root->left;
	root->left=tmp->right;
	tmp->right=root;
	updateHeight(root);
	updateHeight(tmp);
	root=tmp;
}
Node newNode(int data){
	Node root=new node;
	root->data=data,root->height=1;
	root->left=root->right=NULL;
	return root;
}
void insert(Node &root,int data){
	if(root==NULL){
		root=newNode(data);
		return ;
	}
	if(data<root->data){
		insert(root->left,data);
		updateHeight(root);
		if(getBalanceFactor(root)==2){	//若在左子树中插入节点使得整棵树不平衡
			if(getBalanceFactor(root->left)==1){	//在左子树的左子树中插入节点不平衡，LL型
				rightRotation(root);
			}else if(getBalanceFactor(root->left)==-1){	//在左子树的右子树中插入节点不平衡，LR型
				leftRotation(root->left);
				rightRotation(root);
			}
		}
	}else{
		insert(root->right,data);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){	//若在右子树中插入节点使得整棵树不平衡
			if(getBalanceFactor(root->right)==-1){	//在右子树的右子树中插入节点不平衡，RR型
				leftRotation(root);
			}else if(getBalanceFactor(root->right)==1){	//在右子树的左子树中插入节点不平衡，RL型
				rightRotation(root->right);
				leftRotation(root);
			}
		}
	}
}
int main(){
	int n,tmp;
	scanf("%d",&n);
	Node root=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		insert(root,tmp);
	}
	printf("%d",root->data);
	system("pause");
	return 0;
}