#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct gasStation{
	double price,dis;	//加油站的油价以及距出发点的距离
};
bool cmp(gasStation a,gasStation b){
	return a.dis<b.dis;
}
int main(){
	double capacity,distance,davg;	//油箱总容量，目标地点距离，每单位汽油汽车可以跑的距离
	int n;	//加油站数量
	scanf("%lf%lf%lf%d",&capacity,&distance,&davg,&n);
	vector<gasStation> gs(n+1);
	for(int i=0;i<n;i++) scanf("%lf%lf",&gs[i].price,&gs[i].dis);
	gs[n].dis=distance,gs[n].price=gs[n-1].price;	//哨兵
	sort(gs.begin(),gs.end(),cmp);
	double v=0,d=0,price=gs[0].price,total=0;	//记录当前时刻油箱里的油，已经跑的总路程，当前加油站油价，总花费
	if(gs[0].dis>0) printf("The maximum travel distance = 0.00");
	else{
		int i,j=0,min;
		while(d<distance){
			double vtmp;
			min=j+1;
			bool flag=false,flag2=false;	//判断是否有更好的选择和是否有解
			for(i=j+1;i<=n;i++){
				if(d+capacity*davg>=gs[i].dis){	//如果在当前位置能跑到的所有加油站里有价格比这里更低或相等的则跑过去
					flag2=true;	//有解
					if(gs[i].price<=price){	//有加油站比现价格更低
						flag=true;	//更新记录
						if(gs[i].dis>distance) gs[i].dis=distance;	//若已经超过目的地则下一站距离置为distance
						vtmp=(gs[i].dis-d)/davg;	//统计需要多少油
						d=gs[i].dis;
						if(v>=vtmp) v-=vtmp,price=gs[i].price;	//若油够
						else total+=(vtmp-v)*price,v=0,price=gs[i].price;	//若油不够则加到能抵达下一个最优加油站的油量
						break;
					}else if(gs[min].price>gs[i].price) min=i;//若能跑到的加油站油价都比当前高则选择一个最低的过去
				}else break;
			}
			if(flag2==false){
				printf("The maximum travel distance = %.2lf",d+capacity*davg);
				break;
			}
			if(flag==true) j=i;	//有更好的选择
			else{	//当前是最优选择
				j=min;
				if(gs[min].dis>distance) gs[min].dis=distance;
				vtmp=(gs[min].dis-d)/davg;
				d=gs[min].dis;
				if(d!=distance) total+=(capacity-v)*price,v=capacity-vtmp,price=gs[min].price;
				else
					if(v>=vtmp) v-=vtmp,price=gs[i].price;
					else total+=(vtmp-v)*price,price=gs[i].price,v=0;
			}
			if(d==distance) break;
		}
		if(d==distance) printf("%.2lf",total);
	}
	system("pause");
	return 0;
}