#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2e5+6;

ll a[N];
int n,m;


int main()
{   
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n,greater<int>());
    ll x=0,y=0;
    int t=(n+1)/2;
    for(int i=1;i<=n;i++)
    {
        if(i<=t)x+=a[i];
        else y+=a[i];
    }
    cout<<x*x+y*y;


    return 0;
}