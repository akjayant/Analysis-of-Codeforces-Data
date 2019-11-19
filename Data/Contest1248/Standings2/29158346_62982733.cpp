#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    long long Ans=0,tmp=0;
    sort(a+1,a+n+1);
    for(int i=1;i<=n/2;i++){
        Ans+=a[i];
    }
    for(int i=n/2+1;i<=n;i++)tmp+=a[i];
    long long mx=Ans*Ans+tmp*tmp;
    printf("%lld\n",mx);
}
