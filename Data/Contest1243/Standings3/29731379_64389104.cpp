#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,n,m,q,b,c,d,l,r;
    cin>>n;
    if(n==1){cout<<1;return 0;}
    long long h=sqrt(n);
    long long a=n;
    for(int i=2; i<=h; i++)if(n%i==0)
    {
        long long b=a;
        long long c=i;
        while(b%c!=0&&c%b!=0)
        {
            if(b>c)b=b%c;
            else c=c%b;
        }
        a=min(b,c);
        b=a;
        c=n/i;
        while(b%c!=0&&c%b!=0)
        {
            if(b>c)b=b%c;
            else c=c%b;
        }
        a=min(b,c);
    }
    cout<<a;
}
