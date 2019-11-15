#include<bits/stdc++.h>
using namespace std;
int test,n;
string s,t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>test;
    while(test--)
    {
        cin>>n;
        cin>>s>>t;
        s='+'+s;
        t='+'+t;
        int kh=0;
        for(int i=1;i<=n;i++)if(s[i]!=t[i])kh++;
        if(kh!=2&&kh!=0){cout<<"NO\n";continue;}
        int ok=0,ok1=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]!=t[i])
            {
                if(ok==0)ok=i;
                else ok1=i;
            }
        }
        bool kt=0;
        if((s[ok]==s[ok1]&&t[ok]==t[ok1]))kt=1;
        if(kh==0||kt)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
