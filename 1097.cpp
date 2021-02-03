#include <iostream>
using namespace std;

const int MAXN=100000;
int main(){
	int first,n;
	scanf("%d%d",&first,&n);
	int cnt1=0,cnt2=0;
	int data[MAXN],next[MAXN],ans1[MAXN],ans2[MAXN];	//ans1保存无重复的数据节点，ans2保存重复数据节点
	bool flag[10001]={false};	//flag记录每个data绝对值是否已经记录过
	for(int i=0;i<n;i++){
		int index;
		scanf("%d",&index);
		scanf("%d%d",&data[index],&next[index]);
	}
	while(first!=-1){
		if(flag[abs(data[first])]==false){	//若该数据绝对值未被收录过则接收到ans1中
			ans1[cnt1++]=first;
			flag[abs(data[first])]=true;
		}else{	//若绝对值已经收录过则存放到ans2中
			ans2[cnt2++]=first;
		}
		first=next[first];
	}
	for(int i=0;i<cnt1;i++)
		if(i!=cnt1-1)
			printf("%05d %d %05d\n",ans1[i],data[ans1[i]],ans1[i+1]);
		else
			printf("%05d %d -1\n",ans1[cnt1-1],data[ans1[cnt1-1]]);
	for(int i=0;i<cnt2;i++)
		if(i!=cnt2-1)
			printf("%05d %d %05d\n",ans2[i],data[ans2[i]],ans2[i+1]);
		else
			printf("%05d %d -1\n",ans2[cnt2-1],data[ans2[cnt2-1]]);
	system("pause");
	return 0;
}