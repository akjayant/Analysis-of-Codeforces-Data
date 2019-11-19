#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],s,t;
int main()
{
    s=0;
    t=0;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n/2;i++)
    {
        s=s+a[i];
    }
    for(int i=n/2;i<n;i++)
    {
        t=t+a[i];
    }
    cout<<s*s+t*t;



}

