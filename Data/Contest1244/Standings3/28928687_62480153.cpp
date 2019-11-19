#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,p,w,d,c=0;
    cin>>n>>p>>w>>d;
    if(n*w<p){cout<<-1;return 0;}
    for(long long x=max(c,(p-w)/w-w); x<=min(n,(p-w)/w+1); x++)
    {
        long long l=0,r=n-x;
        while(r-l>1)
        {
            long long m=(l+r)/2;
            if(x*w+m*d<p)l=m;
            else r=m;
        }
        if(x*w+l*d==p){cout<<x<<" "<<l<<" "<<n-x-l;return 0;}
        if(x*w+r*d==p){cout<<x<<" "<<r<<" "<<n-x-r;return 0;}
    }
    cout<<-1;
}
