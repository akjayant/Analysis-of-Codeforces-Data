#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define ll long long
int a[N];
int main()
{
    ll s1=0,s2=0;
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n/2;i++)s1+=a[i];
    for(int i=n/2+1;i<=n;i++)s2+=a[i];
    cout<<s1*s1+s2*s2<<endl;
}
