#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,k,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d>>k;
        int cnta=a%c?a/c+1:a/c;
        int cntb=b%d?b/d+1:b/d;
        if(cnta+cntb>k)puts("-1");
        else printf("%d %d\n",cnta,cntb);
    }
    return 0;
}