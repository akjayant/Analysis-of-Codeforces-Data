#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int n;

struct city{
    int x, y;
    int c, k;
};

vector<city> v;
vector<ll> minc;
vector<int> pv;
vector<bool> used;

std::priority_queue<pll, std::vector<pll>, std::greater<pll> > q;

int bd = 0;

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    v.resize(n); 
    for(int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
    for(int i = 0; i < n; i++) cin >> v[i].c;
    for(int i = 0; i < n; i++) cin >> v[i].k;

    pv.assign(n,-1);
    minc.resize(n);
    used.resize(n);

    {
        for(int i = 0; i < n; i++) {
            q.push({v[i].c, i});
            minc[i] = v[i].c;
        }
    }

    while(!q.empty()){
        pll cur = q.top(); q.pop();
        if(cur.first > minc[cur.second])continue;
        if(pv[cur.second] == -1)bd++;
        used[cur.second] = true;
        for(int i = 0; i < n; i++){
            if(used[i])continue;
            ll addc = abs(v[cur.second].x - v[i].x) + abs(v[cur.second].y - v[i].y);
            addc *= (v[cur.second].k + v[i].k);
            if(addc < minc[i]){
                pv[i] = cur.second;
                minc[i] = addc;
                q.push({addc, i});
            }
        }
    }

    ll sum = 0;
    for(int i = 0; i < n; i++) sum += minc[i];

    cout << sum << endl;
    cout << bd << endl;

    for(int i = 0; i < n; i++){
        if(pv[i]==-1) cout << (i+1) << " ";
    }
    cout << endl;
    
    set<pair<int,int>> hd;
    vector<pair<int,int>> out;
    out.reserve(n);

    for(int i = 0; i < n; i++){
        if(pv[i] == -1)continue;
        city& c = v[i];
        if(hd.find({c.x,c.y}) != hd.end())continue;
        out.push_back({pv[i]+1,i+1});
        hd.insert({c.x,c.y});
    }   
    cout << out.size() << endl;
    for(int i = 0; i < out.size(); i++){
        cout << out[i].first <<  " " << out[i].second << endl;
    }

    return 0;
}
