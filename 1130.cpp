#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct node{
	string data;
	int left,right;	
};
int root;
node nd[21];
void preTraversal(int index){
	if(index==-1) return ;
	if((nd[index].left!=-1||nd[index].right!=-1)&&index!=root) printf("(");
	preTraversal(nd[index].left);
	cout<<nd[index].data;
	preTraversal(nd[index].right);
	if((nd[index].left!=-1||nd[index].right!=-1)&&index!=root) printf(")");
}
int main(){
	int n;
	scanf("%d",&n);
	int cnt[2100];
	for(int i=1;i<=n;i++){
		cin>>nd[i].data;
		scanf("%d%d",&nd[i].left,&nd[i].right);
		if(nd[i].left!=-1) cnt[nd[i].left]++;
		if(nd[i].right!=-1) cnt[nd[i].right]++;
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]==0){
			root=i;
			break;
		}
	}
	if(nd[root].left==-1&&nd[root].right==-1) cout<<nd[root].data;
	else preTraversal(root);
	system("pause");
	return 0;
}
