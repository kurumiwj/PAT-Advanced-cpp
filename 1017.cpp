#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k,sum_p=0,sum_t=0;
double average=0;
struct person{
	int start,process;
};
bool cmp(person a,person b){return a.start<b.start;}
bool cmp2(int a,int b){return a>b;}
int timeToInt(int hour,int minute,int second){
	return hour*3600+minute*60+second;
}
void update(vector<int> &windows,int start){
	for(int i=windows.size()-1;i>=0;i--){
		if(start>=windows[i]){
			windows.pop_back();
		}
		else break;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	vector<person> line;
	vector<int> windows;
	int hour,minute,second,p,open=timeToInt(8,0,0),close=timeToInt(17,0,0);
	for(int i=0;i<n;i++){
		scanf("%d:%d:%d %d",&hour,&minute,&second,&p);
		int tmpstart=timeToInt(hour,minute,second);
		if(tmpstart>close) continue;
		else{
			person tmpperson;
			tmpperson.start=tmpstart,tmpperson.process=timeToInt(0,p,0);
			line.push_back(tmpperson);
		}
	}
	sort(line.begin(),line.end(),cmp);
	for(int i=0;i<line.size();i++){
		int wait,firstend;
		sum_p++;
		update(windows,line[i].start);
		if(line[i].start<open){
			wait=open-line[i].start;
			sum_t+=wait;
			line[i].start=open;
		}
		if(windows.size()>=k){
			firstend=windows[k-1];
			wait=firstend-line[i].start;
			sum_t+=wait;
			windows.pop_back();
			windows.push_back(firstend+line[i].process);
		}else{
			windows.push_back(line[i].start+line[i].process);
		}
		sort(windows.begin(),windows.end(),cmp2);
	}
	printf("%.1f",(sum_t*1.0/60)/sum_p);
	system("pause");
	return 0;
}