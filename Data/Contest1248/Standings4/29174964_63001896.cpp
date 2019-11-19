#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll a[100005];
int n;
int main(){
    a[1]=2;a[2]=4;
    for (int i=3;i<=100000;i++)a[i]=(a[i-1]+a[i-2])%mod;
    int x,y;
    scanf("%d%d",&x,&y);
    cout<<(a[x]+a[y]-2ll)%mod<<endl;
    return 0;
}