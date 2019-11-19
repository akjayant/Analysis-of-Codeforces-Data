#include<bits/stdc++.h>
const int  mod=1e9+7;
const int N = 1e5+7;
const int inf= 0x3f3f3f3f;
typedef long long ll;
ll a[N];
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
   ll n;
   ll sum=0;
   cin>>n;
   for(int i=1;i<=n;i++)
    {cin>>a[i];
    sum+=a[i];}
   sort(a+1,a+n+1);
   ll sum1=0;
   for(int i=1;i<=n/2;i++)
    sum1+=a[i];
    cout<<sum1*sum1+(sum-sum1)*(sum-sum1)<<endl;
}
