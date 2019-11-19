#include<bits/stdc++.h>
using namespace std;
int n,m;
long long f[200000],P=1e9+7;
int main(){
    scanf("%d%d",&n,&m);
    f[1]=2;f[2]=4;
    for(int i=3;i<=max(n,m);i++)
	f[i]=(f[i-1]+f[i-2])%P;
    printf("%lld",((f[n]+f[m]-2ll)%P+P)%P);
}
