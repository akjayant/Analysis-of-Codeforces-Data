#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
int n;
ll a[maxn];
void init(int n){ sort(a+1,a+1+n);}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    init(n);
    reverse(a+1,a+n+1);
    ll m=0;
    int x=(n+1)/2;
    for(int i=1;i<=x;i++) m+=a[i];
    ll res=0;
    for(int i=x+1;i<=n;i++) res+=a[i];
    printf("%I64d\n",m*m+1LL*res*res);


    return 0;
}
