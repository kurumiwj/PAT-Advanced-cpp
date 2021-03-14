#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAXN 22
using namespace std;

struct node{
	int left, right;
};
node tree[MAXN];
int index[MAXN];
int last;
bool CBT(int root,int n){
	int cnt=1;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		last = q.front();
		index[last]=cnt++;
		q.pop();
		if(tree[last].left!=-1) q.push(tree[last].left);
		if(tree[last].right!=-1) q.push(tree[last].right);
	}
	bool flag = true;
	for(int i=0;i<n;i++){
		if(tree[i].left!=-1&&index[i]*2!=index[tree[i].left]||tree[i].right!=-1&&index[i]*2+1!=index[tree[i].right])
			flag=false;
	}
	return flag;
}
int main(){
	int n,root;
	string tmpleft, tmpright;
	scanf("%d",&n);
	bool isRoot[n];
	fill(isRoot,isRoot+n,true);
	for(int i=0;i<n;i++){
		cin>>tmpleft>>tmpright;
		if(tmpleft=="-") tree[i].left=-1;
		else tree[i].left=stoi(tmpleft),isRoot[tree[i].left]=false;
		if(tmpright=="-") tree[i].right=-1;
		else tree[i].right=stoi(tmpright),isRoot[tree[i].right]=false;
	}
	for(int i=0;i<n;i++)
		if(isRoot[i]){
			root=i;
			break;
		}
	if(CBT(root,n)) printf("YES %d",last);
	else printf("NO %d",root);
	system("pause");
	return 0;
}