#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define pi pair < ll,ll >
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 300004
#define INF 1e9+7

using namespace std;

ll t,n,first,last;
string s;
ll stairs[N];
bool vis[N][2];

ll calc(ll cur,ll f)
{
    if(vis[cur][f] || cur >= n)
        return 0;

    vis[cur][f] = true;

    ll res = 1;

    if(stairs[cur]&&!vis[cur][!f])
        res = max(res,calc(cur,!f)+1);

    res = max(res,calc(cur+1,f)+1);

    vis[cur][f] = false;

    return res;
}

ll calc2(ll cur,ll f)
{
    if(vis[cur][f] || cur < 0)
        return 0;

    vis[cur][f] = true;

    ll res = 1;

    if(stairs[cur]&&!vis[cur][!f])
        res = max(res,calc2(cur,!f)+1);

    res = max(res,calc2(cur-1,f)+1);
    res = max(res,calc(cur+1,f)+1);

    vis[cur][f] = false;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    while(t--)
    {
        cin >> n;
        cin >> s;

        first=last=-1;

        rep(i,0,n)
        {
            vis[i][0]=vis[i][1]=false;
            stairs[i] = s[i]-'0';

            if(stairs[i])
            {
                if(first==-1)
                    first=i;
                last=i;
            }
        }

        ll ans = n;
        if(first!=-1)
        {
            ans = n+1;
            ans = max(ans,2*(last+1));
            ans = max(ans,2*(n-first));
        }

        cout <<  ans << "\n";;
    }

    return 0;
}


