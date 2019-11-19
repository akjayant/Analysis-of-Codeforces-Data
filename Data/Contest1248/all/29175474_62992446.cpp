#include <iostream>

#define MOD 1000000007
using namespace std;

long long M,N,KQ=0,F[100001];
int main(){
    cin >> M >> N;
    F[1]=F[2]=F[3]=2;
    for (int i=4;i<=100000;i++)
        (F[i]=F[i-1]+F[i-2])%=MOD;
    for (int i=2;i<=100000;i++)
        (F[i]+=F[i-1])%=MOD;
    cout << (F[M]+F[N]-F[1])%MOD;
}