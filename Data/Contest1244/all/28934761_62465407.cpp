#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,k,t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d>>k;
        int sumpen=0,sumpencil=0;
        sumpen=a/c;
        if(a%c)sumpen++;
        sumpencil=b/d;
        if(b%d)sumpencil++;
        if(sumpen+sumpencil<=k)cout<<sumpen<<" "<<sumpencil<<"\n";
        else cout<<-1<<"\n";

    }
}
