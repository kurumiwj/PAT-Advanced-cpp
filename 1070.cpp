#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;

struct mooncake{
	double store,sell,price;	//库存，总售价，单价
};
bool cmp(mooncake a,mooncake b){
	return a.price>b.price;
}
int main(){
	int n,d,i;	//n为月饼种类数，d为市场需求量，cnt记录每次收录的库存
	double max_income=0,cnt=0;	//最大收益
	scanf("%d%d",&n,&d);
	mooncake mc[n];
	for(i=0;i<n;i++) scanf("%lf",&mc[i].store);
	for(i=0;i<n;i++){
		scanf("%lf",&mc[i].sell);
		mc[i].price=mc[i].sell/mc[i].store;	//计算每种月饼的单价
	}
	sort(mc,mc+n,cmp);	//对月饼单价进行由大到小排序
	// for(i=0;i<n;i++) printf("%.2lf ",mc[i].price);
	i=0;
	while(cnt<d&&i<n){
		cnt+=mc[i].store;
		if(cnt>d){	//检查是否超出需求量
			max_income=max_income+(d-cnt+mc[i].store)*mc[i].price;
			break;
		}
		max_income+=mc[i].sell;
		i++;
	}
	printf("%.2lf",max_income);
	system("pause");
	return 0;
}