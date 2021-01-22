//测试点4未通过
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct car{
	string number;
	int hour,minute,second,time;
	int status;	//出入状态，1代表in，-1代表out
	bool pair=false;	//判断是否匹配
};
bool cmp(car a,car b){
	if(a.number!=b.number) return a.number<b.number;
	else return a.time<b.time;
}
bool cmp2(car a,car b){
	return a.time<b.time;
}
int main(){
	int n,k;	//总记录，k个时间段
	scanf("%d%d",&n,&k);
	vector<car> c(n);
	char status[3];
	for(int i=0;i<n;i++){
		cin>>c[i].number;
		scanf("%d:%d:%d",&c[i].hour,&c[i].minute,&c[i].second);
		c[i].time=c[i].hour*3600+c[i].minute*60+c[i].second;
		scanf("%s",status);
		if(strcmp(status,"in")==0) c[i].status=1;
		else c[i].status=-1;
	}
	int park[k]={0};	//存储录入的时刻
	fill(park,park+k,0);
	int hour,minute,second;
	for(int i=0;i<k;i++){
		scanf("%d:%d:%d",&hour,&minute,&second);
		park[i]=hour*3600+minute*60+second;
	}
	sort(c.begin(),c.end(),cmp);
	map<string,int> time;	//记录每辆车停留的时间
	int max=0;	//记录最大时间
	for(auto it=c.begin();it!=c.end();)	//找到第一个in的车，前面都删除
		if((*it).status==-1) c.erase(it);
		else break;
	for(auto it=c.begin();it<=c.end()-1;)
		if((*(it+1)).number==(*it).number)
			if((*it).status==1&&(*(it+1)).status==-1){
				time[(*it).number]+=((*(it+1)).time-(*it).time);
				if(time[(*it).number]>max) max=time[(*it).number];
				it+=2;
			}
			else c.erase(it);
		else{
			if((*it).status==1) c.erase(it);
			else it++;
		}
	sort(c.begin(),c.end(),cmp2);
	int cnt[c.size()]={0};
	fill(cnt,cnt+c.size(),0);
	for(int i=0;i<c.size();i++)
		if(i==0) cnt[i]+=c[i].status;
		else cnt[i]=cnt[i-1]+c[i].status;
	int tempindex=0,j;
	for(int i=0;i<k;i++){
		for(j=tempindex;j<c.size();j++)
			if(c[j].time>park[i]){
				printf("%d\n",cnt[j-1]);
				break;
			}else if(j==c.size()-1) printf("%d\n",cnt[j]);
		tempindex=j;
	}
	// for(int i=0;i<c.size();i+=2){
	// 	for(int j=0;j<k;j++){
	// 		if(c[i+1].time<park[0][0]) break;
	// 		else if(c[i].time>park[0][k-1]) break;
	// 		if(c[i].time>park[0][j]) continue;
	// 		else if(c[i+1].time>park[0][j]) park[1][j]++;
	// 	}
	// }
	// for(int i=0;i<k;i++) printf("%d\n",park[1][i]);
	for(auto it=time.begin();it!=time.end();it++) if((*it).second==max) printf("%s ",(*it).first.c_str());
	printf("%02d:%02d:%02d",max/3600,max%3600/60,max%60);
	system("pause");
	return 0;
}