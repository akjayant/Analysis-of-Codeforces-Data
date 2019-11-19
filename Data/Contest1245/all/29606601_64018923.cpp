#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=2e5 + 5;
const ll mod=1e9 + 7;
#define debug(x) cerr<<#x<<" is "<<x<<endl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll c[n],k[n];
    pair<ll,ll> arr[n];
    for(ll i=0;i<n;i++)cin>>arr[i].first>>arr[i].second;
    for(ll i=0;i<n;i++)cin>>c[i];
    for(ll i=0;i<n;i++)cin>>k[i];

    ll adj[n][n];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i==j)adj[i][j]=c[i];
            else adj[i][j] = ( abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second) )*(k[i]+k[j]);
        }
    }

    ll cost = 0;
    vector<ll> ps;
    vector< pair<ll,ll> > connections;

    set<ll> used;

    priority_queue< pair<ll, pair<ll, ll> > , vector< pair< ll , pair<ll,ll> > > , greater< pair< ll , pair<ll,ll> > > > pq;
    for(ll i=0;i<n;i++)pq.push(make_pair(adj[i][i] , make_pair(i,i) ) );

    while(used.size()<n){
        ll val = pq.top().first;
        ll ele1 = pq.top().second.first , ele2 =pq.top().second.second;
        pq.pop();
        if(used.count(ele2))continue;
        cost+=val;
        if(ele1 == ele2){
            ps.push_back(ele1+1);
            used.insert(ele1);
            for(ll i=0;i<n;i++){
                if(i==ele1)
                    continue;
                pq.push(make_pair(adj[ele1][i] , make_pair(ele1,i)));
            }
        }
        else{
            connections.push_back(make_pair(ele1+1,ele2+1));
            used.insert(ele2);
            for(ll i=0;i<n;i++){
                if(i==ele1 || i==ele2)continue;
                pq.push(make_pair(adj[ele2][i] , make_pair(ele2,i)));
            }
        }
    }

    cout<<cost<<"\n";
    cout<<ps.size()<<"\n";
    for(ll i=0;i<ps.size();i++)cout<<ps[i]<<" ";
    cout<<"\n"<<connections.size()<<"\n";
    for(ll i=0;i<connections.size();i++)cout<<connections[i].first<<" "<<connections[i].second<<"\n";
}

