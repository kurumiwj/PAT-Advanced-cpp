#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct customer{
	string name;
	int month,day,hour,minute;
	int interval;	//0代表开始打的时间，1代表结束的时间
};
struct time_bill{
	int minutes;
	double bill;
};
int rate[25]={0};	//每分钟话费(美分)
bool cmp(customer a,customer b){	//按照同名时间从小到大排序
	if(a.name!=b.name) return a.name<b.name;
	else if(a.month!=b.month) return a.month<b.month;
	else if(a.day!=b.day) return a.day<b.day;
	else if(a.hour!=b.hour) return a.hour<b.hour;
	else return a.minute<b.minute;
}
time_bill interval_bill(customer a,customer b){	//已经排过序，b的时间一定在a之后，统计一共打的时间和费用
	int time_a=a.day*60*24+a.hour*60+a.minute,time_b=b.day*24*60+b.hour*60+b.minute;
	double total_a=a.day*rate[24]*60+rate[a.hour]*a.minute,total_b=b.day*rate[24]*60+rate[b.hour]*b.minute;
	for(int i=0;i<a.hour;i++) total_a+=60*rate[i];
	for(int i=0;i<b.hour;i++) total_b+=60*rate[i];
	time_bill tb;
	tb.minutes=time_b-time_a;
	tb.bill=(total_b-total_a)/100;
	return tb;
}
int main(){
	for(int i=0;i<24;i++){
		scanf("%d",&rate[i]);
		rate[24]+=rate[i];
	}
	int n;
	scanf("%d",&n);
	vector<customer> ctm(n);
	for(int i=0;i<n;i++){
		string interval;
		cin>>ctm[i].name;
		scanf("%d:%d:%d:%d",&ctm[i].month,&ctm[i].day,&ctm[i].hour,&ctm[i].minute);
		cin>>interval;
		if(interval=="on-line") ctm[i].interval=0;
		else ctm[i].interval=1;
	}
	sort(ctm.begin(),ctm.end(),cmp);
	map<string,vector<customer>>custom;
	for(int i=1;i<n;i++){
		if(ctm[i].name==ctm[i-1].name&&ctm[i].interval==1&&ctm[i-1].interval==0){
			custom[ctm[i].name].push_back(ctm[i-1]);
			custom[ctm[i].name].push_back(ctm[i]);
		}
	}
	for(auto it:custom){
		vector<customer>tmp=it.second;
		cout<<it.first;
		printf(" %02d\n",tmp[0].month);
		double total=0;
		for(int i=1;i<tmp.size();i+=2){
			time_bill tb=interval_bill(tmp[i-1],tmp[i]);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",tmp[i-1].day,tmp[i-1].hour,tmp[i-1].minute,tmp[i].day,tmp[i].hour,tmp[i].minute,tb.minutes,tb.bill);
			total+=tb.bill;
		}
		printf("Total amount: $%.2lf\n",total);
	}
	system("pause");
	return 0;
}