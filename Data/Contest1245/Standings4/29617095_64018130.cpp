#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll N = 1e6 + 5;
const ll INF = 1e9 + 7;

ll Q, a, b, c, xx[N];
ld n;

int main() {
    //freopen("1245B.INP", "r", stdin);
    //freopen("1245B.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>Q;
    while(Q--)
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
    return 0;
}


