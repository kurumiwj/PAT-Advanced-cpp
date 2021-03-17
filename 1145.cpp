#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool isPrime(int x){
	if(x==2||x==3) return true;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0) return false;
	}
	return true;
}
int main(){
	int msize,n,m,tmp,index,cnt=1,total=0;
	scanf("%d%d%d",&msize,&n,&m);
	while(!isPrime(msize)) msize++;
	int hashTable[msize];
	fill(hashTable,hashTable+msize,0);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		index=tmp%msize;
		for(cnt=0;cnt<msize;cnt++){
			index=(tmp+cnt*cnt)%msize;
			if(hashTable[index]==0){
				hashTable[index]=tmp;
				break;
			}
		}
		if(cnt==msize) printf("%d cannot be inserted.\n",tmp);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&tmp);
		for(cnt=0;cnt<=msize;cnt++){
			total++;
			index=(tmp+cnt*cnt)%msize;
			if(hashTable[index]==tmp||hashTable[index]==0)	//找到了或者不存在
				break;
		}
	}
	printf("%.1f\n",total*1.0/m);
	system("pause");
	return 0;
}
