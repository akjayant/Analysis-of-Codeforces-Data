#include<bits/stdc++.h>
typedef long long ll;

#define pb push_back
#define mp make_pair
#define mod 1000000007
#define mem(x) memset(x,0,sizeof(x))
using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    vector<pair<ll,ll> > polls(n+1);
    for(ll i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        polls[i] = make_pair(x,y);
    }
    ll cost[n+1];
    for(ll i=1;i<=n;i++)
        cin>>cost[i];
    ll k[n+1];
    for(ll i=1;i<=n;i++)
        cin>>k[i];

    ll ans = 0;

    vector<ll> power;
    vector<pair<ll,ll> > edge;

    vector<pair<ll,pair<ll,ll> > > arr;
    for(ll i=1;i<=n;i++)
    {
        arr.push_back(make_pair(cost[i],make_pair(i,-1)));
    }

    sort(arr.begin(),arr.end());
    vector<ll> flag(n+1,0);
    while(arr.size()!=0)
    {
        pair<ll,pair<ll,ll> > p = arr[0];
        ans += p.first;
        if(p.second.second == -1){
            power.push_back(p.second.first);
        }
        else{
            edge.push_back(make_pair(p.second.first,p.second.second));
        }
        vector<pair<ll,pair<ll,ll> > > temp;
        for(ll j=1;j<arr.size();j++)
        {
            
            pair<ll,pair<ll,ll> > p1 = arr[j];
            
            
            ll y = k[p1.second.first] + k[p.second.first];
            ll dist = abs(polls[p1.second.first].first-polls[p.second.first].first) + abs(polls[p1.second.first].second-polls[p.second.first].second);
            ll c = dist*y;
            if(c < p1.first)
                temp.push_back(make_pair(c,make_pair(p1.second.first,p.second.first)));
            else
                temp.push_back(p1);
            
        }
        arr = temp;
        sort(arr.begin(),arr.end());


    }

    cout<<ans<<"\n";
    cout<<power.size()<<"\n";
    for(ll i=0;i<power.size();i++)
        cout<<power[i]<<" ";
    cout<<"\n";
    cout<<edge.size()<<"\n";
    for(ll i=0;i<edge.size();i++)
    {
        cout<<edge[i].first<<" "<<edge[i].second<<"\n";
    }

    


    return 0;
    
}