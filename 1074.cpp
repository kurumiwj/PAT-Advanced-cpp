#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=1000001;
int main(){
	int n,k,first,total=0;
	scanf("%d%d%d",&first,&n,&k);
	vector<int> data(MAX),next(MAX),ans(MAX);
	for(int i=1;i<=n;i++){
		int index;
		scanf("%d",&index);
		scanf("%d%d",&data[index],&next[index]);
	}
	while(first!=-1){
		ans[total++]=first;
		first=next[first];
	}
	for(int i=0;i+k<=total;i+=k) reverse(ans.begin()+i,ans.begin()+i+k);
	for(int i=0;i<total-1;i++) printf("%05d %d %05d\n",ans[i],data[ans[i]],ans[i+1]);
	printf("%05d %d -1\n",ans[total-1],data[ans[total-1]]);
	system("pause");
	return 0;
}