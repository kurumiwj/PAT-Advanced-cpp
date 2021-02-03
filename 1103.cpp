#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> v,ans,temp;
int n,k,p,maxFacSum=-1;
//题目要求按照总和从大到小排序，若总和相等按照字典序从小到大
void DFS(int index,int nowSum,int nowK,int factorSum){	//index当前数字，nowSum当前p方和，nowK当前数字总数，factorSum当前数字总和
	if(nowK==k){	//当前数字个数已经达到要求
		if(nowSum==n&&factorSum>maxFacSum){	//若p方和已经等于n并且找到因子和更大的一组解
			ans=temp;
			maxFacSum=factorSum;
		}
		return ;
	}
	if(nowK>k||nowSum>n) return ;
	// while(index>=1){
	// 	if(nowSum+v[index]<=n){	//若选择的数p方加上现在的p方和还未超过总要求n则继续向下查找，index可以取多次
	// 		temp[nowK]=index;
	// 		DFS(index,nowSum+v[index],nowK+1,factorSum+index);
	// 	}
	// 	if(index==1) return ;
	// 	index--;
	// }
	if(index>=1){
		temp.push_back(index);
		DFS(index,nowSum+v[index],nowK+1,factorSum+index);	//选
		temp.pop_back();
		DFS(index-1,nowSum,nowK,factorSum);	//不选
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&p);
	for(int i=0;pow(i,p)<=n;i++){
		v.push_back(pow(i,p));
	}
	// temp.resize(k);
	DFS(v.size()-1,0,0,0);	//倒着来
	if(maxFacSum==-1) printf("Impossible");
	else{
		printf("%d = ",n);
		for(int i=0;i<k;i++){
			printf("%d^%d",ans[i],p);
			if(i!=k-1) printf(" + ");
		}
	}
	system("pause");
	return 0;
}