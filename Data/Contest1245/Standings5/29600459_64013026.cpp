#include <bits/stdc++.h>

using namespace std;
char x[200];
long n,a,b,c,t;
string s;
void solve()
{
    long res=0;
    for(int i=1;i<=n;i++)
        x[i]='.';
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R'&&b>0)
            {
                x[i+1]='P';
                b--;
                res++;
            }
        if(s[i]=='P'&&c>0)
            {
                x[i+1]='S';
                c--;
                res++;
            }
        if(s[i]=='S'&&a>0)
            {
                x[i+1]='R';
                a--;
                res++;
            }
    }
    for(int i=0;i<n;i++)
        if(x[i+1]=='.')
    {
        if(a>0)
        {
            x[i+1]='R';
            a--;
            continue;
        }
        if(b>0)
        {
            x[i+1]='P';
            b--;
            continue;
        }
        if(c>0)
        {
            x[i+1]='S';
            c--;
        }
    }
    if(res>=(n/2+n%2))
    {
        cout<<"YES"<<"\n";
        for(int i=1;i<=n;i++)
            cout<<x[i];
        cout<<"\n";
    }
    else cout<<"NO"<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
   {
    cin>>n;
    cin>>a>>b>>c;
    cin>>s;
    solve();
   }
}
