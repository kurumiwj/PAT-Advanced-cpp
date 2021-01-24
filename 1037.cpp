#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a,int b){
	if(a>0&&b>0||a*b<0) return a>b;	//	若都为正或一正一负则从大到小排序
	else if(a<0&&b<0) return a<b;	//若都为负则从小到大排序
	else  return a>b;
}
int main(){
	int nc,np;
	scanf("%d",&nc);
	vector<int> v1(nc);
	for(int i=0;i<nc;i++) scanf("%d",&v1[i]);
	scanf("%d",&np);
	vector<int> v2(np);
	for(int i=0;i<np;i++) scanf("%d",&v2[i]);
	sort(v1.begin(),v1.end(),cmp);
	sort(v2.begin(),v2.end(),cmp);
	long long total=0;
	for(int i=0,j=0;i<nc&&j<np;){
		if(v2[j]==0) j++;
		else if(v1[i]==0) i++;
		else if(v1[i]<0&&v2[j]<0) total+=v1[i++]*v2[j++];
		else if(v1[i]<0&&v2[j]>0) j++;
		else if(v1[i]>0&&v2[j]<0) i++;
		else total+=v1[i++]*v2[j++];
	}
	printf("%lld",total);
	system("pause");
	return 0;
}