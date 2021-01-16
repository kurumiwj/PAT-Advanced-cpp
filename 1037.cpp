#include <iostream>
#include <cstdio>
using namespace std;

struct currency{    //货币：十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可
    int Galleon;
    int Sickle;
    int Knut;
};
int main(){
    int charge,Galleon,Sickle,Knut;
    currency p,a; //p为应付的价钱，a为实付的价钱
    scanf("%d.%d.%d",&p.Galleon,&p.Sickle,&p.Knut);
    scanf("%d.%d.%d",&a.Galleon,&a.Sickle,&a.Knut);
    int money_p=p.Knut+p.Sickle*29+p.Galleon*17*29,money_a=a.Knut+a.Sickle*29+a.Galleon*17*29;
    if(money_a>=money_p){
        charge=money_a-money_p;
        Galleon=charge/(29*17);
        charge%=(29*17);
        Sickle=charge/29;
        charge%=29;
        Knut=charge;
        printf("%d.%d.%d\n",Galleon,Sickle,Knut);
    }else{
        charge=money_p-money_a;
        Galleon=charge/(29*17);
        charge%=(29*17);
        Sickle=charge/29;
        charge%=29;
        Knut=charge;
        printf("-%d.%d.%d\n",Galleon,Sickle,Knut);
    }
    system("pause");
    return 0;
}
