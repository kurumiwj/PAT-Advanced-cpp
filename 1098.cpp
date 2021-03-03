#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> initial,partial;
void PercDown(int start,int end){
	int parent=start,child;
	int tmp=initial[parent];
	for(;parent*2<=end;parent=child){
		child=2*parent;
		if((child!=end)&&initial[child]<initial[child+1]) child++;	//取两个孩子中较大的一个
		if(tmp<initial[child]) initial[parent]=initial[child];
		else break;
	}
	initial[parent]=tmp;
}
int main(){
	int n,tmp,i,j;
	scanf("%d",&n);
	initial.push_back(0);
	partial.push_back(0);	//方便之后下标从1开始
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		initial.push_back(tmp);
	}
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		partial.push_back(tmp);
	}
	for(i=0;i<n;i++){
		if(partial[i+1]<partial[i]) break;
	}
	for(j=i+1;j<n;j++){
		if(initial[j]!=partial[j]) break;
	}
	if(j==n){
		printf("Insertion Sort\n");
		sort(partial.begin()+1,partial.begin()+i+2);
		for(i=1;i<=n;i++){
			if(i!=1) printf(" ");
			printf("%d",partial[i]);
		}
	}
	else{
		printf("Heap Sort\n");
		for(i=n;i>=1;i--){
			for(j=i/2;j>0;j--)
				PercDown(j,i);
			if(initial==partial) break;
			swap(initial[i],initial[1]);
		}
		swap(initial[i],initial[1]);
		i--;
		for(j=i/2;j>0;j--)
			PercDown(j,i);
		for(i=1;i<=n;i++){
			if(i!=1) printf(" ");
			printf("%d",initial[i]);
		}
	}
	system("pause");
	return 0;
}