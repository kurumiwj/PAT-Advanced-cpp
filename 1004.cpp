#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int height;
	vector<int> child;
};
node nd[100];
vector<int> nonLeaf(100);
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int nod=q.front();
		q.pop();
		if(nd[nod].child.size()!=0){
			for(int i=0;i<nd[nod].child.size();i++){
				nd[nd[nod].child[i]].height=nd[nod].height+1;
				q.push(nd[nod].child[i]);
			}
		}else{
			nonLeaf[nd[nod].height]++;
		}
	}
}
int main(){
	int n,m,index,ch,tmp,max=1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&index,&tmp);
		for(int j=0;j<tmp;j++){
			scanf("%d",&ch);
			nd[index].child.push_back(ch);
		}
	}
	nd[1].height=1;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int nod=q.front();
		q.pop();
		if(nd[nod].child.size()!=0){
			for(int i=0;i<nd[nod].child.size();i++){
				nd[nd[nod].child[i]].height=nd[nod].height+1;
				if(max<nd[nd[nod].child[i]].height) max=nd[nd[nod].child[i]].height;
				q.push(nd[nod].child[i]);
			}
		}
	}
	BFS(1);
	for(int i=1;i<=max;i++){
		if(i!=1) printf(" ");
		printf("%d",nonLeaf[i]);
	}
	system("pause");
	return 0;
}