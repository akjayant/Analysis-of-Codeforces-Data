#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100010;
const int mod=1000000007;
char s[N];
ll a[N],b[N],c[N];
int main(){
    ll n,m;
    ios::sync_with_stdio(false), cin.tie(0);
    a[1]=2;
    a[2]=4;
    a[3]=6;
    b[2]=2;
    b[3]=2;
    for(int i=4;i<=100000;i++) {
        b[i]=(b[i-1]+b[i-2])%mod;
        a[i]=(a[i-1]+b[i])%mod;
    }
    cin>>n>>m;
    c[1]=a[n];
    c[2]=a[n]+2;
    c[3]=a[n]+4;
    for(int i=4;i<=m;i++) {
        c[i]=(c[i-1]+b[i])%mod;
    }
    printf("%lld\n",c[m]);
    return 0;
}
/*
        for(int x=1;x<=n;x++) {
            for(int y=1;y<=m;y++) {
                printf("%d ",mp[x][y]);
            }puts("");
        }
        printf("***************\n");
*/
