#include <iostream>
#include <vector>
using namespace std;

int n,m;
int BinarySearch(int i,int a[]){	//对数组从i到n内进行二分查找
	int left=i,right=n;
	while(left<right){
		int mid=(left+right)/2;
		if(a[mid]-a[i-1]>m) right=mid;
		else if(a[mid]-a[i-1]<m) left=mid+1;
		else return mid;
	}
	return left;
}
int main(){
	int min=0;	//min记录若无法恰好支付损失的最小钱
	scanf("%d%d",&n,&m);
	int a[n+1],sum[n+1]={0};
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];	//统计从第一个数字到第i个数字之和
	}
	bool flag=false;
	for(int i=1;i<=n;i++){
		int index=BinarySearch(i,sum),tmp=sum[index]-sum[i-1];
		if(tmp==m){
			printf("%d-%d\n",i,index),flag=true;	//有解
		}else if(tmp>m){
			if(min>tmp-m||min==0) min=tmp-m;
		}
	}
	if(flag==false)	//无解输出大于m的最小序列组合
		for(int i=1;i<=n;i++){
			int index=BinarySearch(i,sum),tmp=sum[index]-sum[i-1];
			if(tmp-m==min){
				printf("%d-%d\n",i,index);
			}
		}
	system("pause");
	return 0;
}