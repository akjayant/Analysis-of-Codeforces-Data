#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a,b,c;
        cin>>a>>b>>c;
        string s;
        cin>>s;
        ll a1,b1,c1;
        a1=0;b1=0;c1=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R')
                a1++;
            else if(s[i]=='P')
                b1++;
            else
                c1++;
        }
        ll a2,b2,c2;
        a2=min(a,c1);
        b2=min(b,a1);
        c2=min(c,b1);
        a-=a2;b-=b2;c-=c2;
        ll cnt=a2+b2+c2;ll w=(n+1)/2;
        if(cnt<w)
        {
            cout<<"NO\n";
            continue;
        }
        else
        {
            cout<<"YES\n";
            string ss;
            for(int i=0;i<n;i++)
                ss+='0';
            for(int i=0;i<n;i++)
            {
                if(s[i]=='R' && b2>0){ss[i]='P';b2--;}
                else if(s[i]=='P' && c2>0){ss[i]='S';c2--;}
                else if(s[i]=='S' && a2>0){ss[i]='R';a2--;}
                else continue;
            }
            for(int i=0;i<n;i++)
            {
                if(ss[i]=='0'){
                if(a){a--;ss[i]='R';}
                else if(b){b--;ss[i]='P';}
                else {c--;ss[i]='S';}
                }
            }
            cout<<ss<<"\n";
        }
    }
}
