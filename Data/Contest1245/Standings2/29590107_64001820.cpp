/****************************
* Author : 水娃             *
* Date : 2019-11-01-22.39.14*
****************************/
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define mst(a,b) memset(a,b,sizeof(a))
#define ll long long
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
const int MAXN=(int)1e5+10;
const int mo=(int)1e9+7;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        int a,b,c;
        cin>>a>>b>>c;
        string x;
        cin>>x;
        int anss=0,ansr=0,ansp=0;
        for(int i=0;i<x.length();i++)
        {
            if(x[i]=='R')ansr++;
            else if(x[i]=='P')ansp++;
            else anss++;
        }
        int tot=min(a,anss)+min(b,ansr)+min(c,ansp);
        if(tot*2>=n)
        {
            cout<<"YES\n";
            char ans[110]={0};
            for(int i=0;i<x.length();i++)
            {
                if(x[i]=='R'&&b)
                {
                    ans[i]='P';
                    b--;
                }
                else if(x[i]=='P'&&c)
                {
                    ans[i]='S';
                    c--;
                }
                else if(x[i]=='S'&&a)
                {
                    ans[i]='R';
                    a--;
                }
            }
            for(int i=0;i<x.length();i++)
            {
                if(ans[i]==0)
                {
                    if(a)
                    {
                        ans[i]='R';
                        a--;
                    }
                    else if(b)
                    {
                        ans[i]='P';
                        b--;
                    }
                    else
                    {
                        ans[i]='S';
                        c--;
                    }
                }
            }
            for(int i=0;i<x.length();i++)
            {
                cout<<ans[i];
            }
            cout<<"\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}
