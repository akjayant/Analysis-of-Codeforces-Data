#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100005];
int n,k;
ll sum,sum2;
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    cin>>a[i];
    sum+=a[i];
}
    sort(a+1,a+1+n);
    if(n%2!=0)k=(n+1)/2;
    if(n%2==0)k=n/2+1;
    for(int i=k;i<=n;i++)
    sum2+=a[i];
    cout<<sum2*sum2+(sum-sum2)*(sum-sum2);
	return 0;
}
