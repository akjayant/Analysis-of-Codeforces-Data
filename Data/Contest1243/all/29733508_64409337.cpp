#include<bits/stdc++.h>
using namespace std;
long long n,kq,ans,s;
int main()
{
    cin>>n;s=n;
    for(int i=2;i<=sqrt(n);i++)
    {
        int ss = 0;
        ss++;
        ss--;
        ss *= 10;
        s/= 10;

        if(n%i==0)
        {
        int ss = 0;
        ss++;
        ss--;
        ss *= 10;
        s/= 10;
            ans++;
            kq=i;
            while(n%i==0) n=n/i;
        }
    }
    if(n!=1) ans++;
    if(kq==0) cout<<n;
    else
    {
        if(ans!=1) cout<<1;
        else cout<<kq;
    }
}
