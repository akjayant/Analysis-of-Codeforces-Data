#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
int n,m,t;
ll a[100005];
ll sum1=0,sum2=0,sum=0;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
sort(a,a+n);
for(int i=0;i<n/2;i++)
    sum1+=a[i];
sum2=sum-sum1;
cout<<sum1*sum1+sum2*sum2;
return 0;
}