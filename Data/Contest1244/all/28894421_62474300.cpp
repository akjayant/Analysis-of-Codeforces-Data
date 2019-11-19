#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        ll n, p, w, d;
        cin>>n>>p>>w>>d;

        ll win = 0, draw = 0, lost = 0;
        vector < pair <ll,ll> > good;
        ll i,j, cnt = 0;
        for(i=p/w; i>=0; i--)
        {
            cnt++;
            if (cnt > 200500) break;
            ll rest = p - w*i;
            if (rest%d==0)
            {
                j = rest/d;
                good.push_back({i,j});
                break;
            }
        }

/*
for(i=0; i<good.size(); i++)
{
    cout<<good[i].first<<" "<<good[i].second<<endl;
}
*/
    if (good.size() == 0)
    {
        cout<<-1;
        return 0;
    }
    if  (good[0].first + good[0].second > n)
    {
        cout<<-1;
        return 0;
    }
    cout<<good[0].first<<" "<<good[0].second<<" "<<n-good[0].first-good[0].second<<endl;



    return 0;
}
