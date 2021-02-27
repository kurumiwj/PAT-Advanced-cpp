#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int data;
	node *left,*right;
};
typedef node* Node;
vector<int> leftChild,rightChild,levelInvert,inInvert;
void Create(Node &root){
	if(root==NULL) return ;
	if(leftChild[root->data]==-1) root->left=NULL;
	else{
		Node tmp=new node;
		tmp->data=leftChild[root->data];
		tmp->left=tmp->right=NULL;
		root->left=tmp;
	}
	if(rightChild[root->data]==-1) root->right=NULL;
	else{
		Node tmp=new node;
		tmp->data=rightChild[root->data];
		tmp->left=tmp->right=NULL;
		root->right=tmp;
	}
	Create(root->left);
	Create(root->right);
}
// void preOrder(Node root){
// 	if(root==NULL) return ;
// 	printf("%d ",root->data);
// 	preOrder(root->left);
// 	preOrder(root->right);
// }
void inOrderInvert(Node root){	//中序镜像遍历
	if(root==NULL) return ;
	inOrderInvert(root->right);
	inInvert.push_back(root->data);
	inOrderInvert(root->left);
}
void levelOrderInvert(Node root){	//层序镜像遍历
	queue<Node> q;
	if(root==NULL) return ;
	q.push(root);
	while(!q.empty()){
		Node tmp=q.front();
		levelInvert.push_back(tmp->data);
		q.pop();
		if(tmp->right) q.push(tmp->right);
		if(tmp->left) q.push(tmp->left);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	bool flag[n]={false};
	for(int i=0;i<n;i++){
		char left,right;
		scanf("%c %c",&left,&right);
		getchar();
		if(left=='-') leftChild.push_back(-1);
		else{
			leftChild.push_back(left-'0');
			flag[left-'0']=true;
		}
		if(right=='-') rightChild.push_back(-1);
		else{
			rightChild.push_back(right-'0');
			flag[right-'0']=true;
		}
	}
	Node root=new node;
	for(int i=0;i<n;i++)
		if(flag[i]==false){
			root->data=i;
			root->left=root->right=NULL;
			break;
		}
	Create(root);
	inOrderInvert(root);
	levelOrderInvert(root);
	for(int i=0;i<n;i++){
		if(i!=0) printf(" ");
		printf("%d",levelInvert[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++){
		if(i!=0) printf(" ");
		printf("%d",inInvert[i]);
	}
	system("pause");
	return 0;
}