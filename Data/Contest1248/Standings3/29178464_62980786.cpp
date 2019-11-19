#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
int n,m,t;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>t;
while(t--)
{
cin>>n;
ll tot1=0;
ll tot2=0;
ll sum1=0;
ll sum2=0;
int u;
for(int i=0;i<n;i++)
    {
    cin>>u;
    if(u%2) tot2++;
    else tot1++;
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u;
        if(u%2) sum2++;
        else sum1++;
    }
    cout<<tot1*sum1+tot2*sum2<<endl;
}
return 0;
}

