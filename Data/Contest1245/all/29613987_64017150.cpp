#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll test,a,b,c,xx[110];
long double n;
template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}
int main()
{
  //  freopen("h.inp","r",stdin);
    cin>>test;
    while(test--)
    {
        cin>>n>>a>>b>>c;
        string s;
        cin>>s;
        int cnt=0;
        memset(xx,0,sizeof(xx));
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='R')
            {
                if(b)
                {
                    b--;
                    cnt++;
                    xx[i+1]=1;
                }
            }
            if(s[i]=='P')
            {
                if(c)
                {
                    c--;
                    cnt++;
                    xx[i+1]=2;
                }
            }
            if(s[i]=='S')
            {
                if(a)
                {
                    a--;
                    cnt++;
                    xx[i+1]=3;
                }
            }
        }
       // cout<<b<<endl;
        ll aa=roundf(n/2.000);
        if(cnt<aa)
            cout<<"NO\n";
        else
        {
        cout<<"YES\n";
            for(int i=1;i<=n;i++)
            {
              //  cout<<xx[i]<<" ";
                if(xx[i]==1)
                {
                    cout<<"P";
                }
                if(xx[i]==2)
                    cout<<"S";
                if(xx[i]==3)
                    cout<<"R";
                if(xx[i]==0)
                {
                    if(a)
                    {
                        a--;
                        cout<<"R";
                        continue;
                    }
                    if(b)
                    {
                        b--;
                        cout<<"P";
                        continue;
                    }
                    if(c)
                    {
                        c--;
                        cout<<"S";
                    }
                }
            }
            cout<<'\n';
        }
    }
}
