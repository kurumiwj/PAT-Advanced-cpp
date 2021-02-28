#include <iostream>
#include <vector>
using namespace std;

struct node{
	vector<int> child;
};
vector<node> v;
int max_index=1;
int member[100]={0,1,0};
void DFS(int index,int height){
	int n=v[index].child.size();
	if(n==0) return ;
	member[height+1]+=n;
	if(member[height+1]>member[max_index]) max_index=height+1;
	for(int i=0;i<n;i++){
		DFS(v[index].child[i],height+1);
	}
}
int main(){
	int n,m,tmp,num,ch,max,index;
	scanf("%d%d",&n,&m);
	v.resize(n+1);
	for(int i=0;i<m;i++){
		scanf("%d%d",&tmp,&num);	//第tmp个节点有num个孩子
		for(int j=0;j<num;j++){
			scanf("%d",&ch);
			v[tmp].child.push_back(ch);
		}
	}
	DFS(1,1);
	printf("%d %d",member[max_index],max_index);
	system("pause");
	return 0;
}