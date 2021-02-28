#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct node{
	vector<int> child;
};
double p,r;
double lowest=10000000000;
int cnt=0;
node nd[100000];
void DFS(int index,int height){
	if(nd[index].child.size()==0){
		double sum=p*pow((1+r),height-1);
		if(lowest>sum){
			lowest=sum;
			cnt=1;
		}else if(lowest==sum){
			cnt++;
		}
		return ;
	}
	for(int i=0;i<nd[index].child.size();i++){
		DFS(nd[index].child[i],height+1);
	}
}
int main(){
	int n,tmp,ch;
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100;
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		for(int j=0;j<tmp;j++){
			scanf("%d",&ch);
			nd[i].child.push_back(ch);
		}
	}
	DFS(0,1);
	printf("%.4f %d",lowest,cnt);
	system("pause");
	return 0;
}