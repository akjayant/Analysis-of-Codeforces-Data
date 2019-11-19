#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long

int main()
{
    int n;
    cin >> n;

    vector<pair<int,int> > pos;
    vector<int> pcosts;
    vector<int> kis;

    for(int i = 0; i < n; i++){
        int xi, yi;
        cin >> xi >> yi;
        pos.push_back({xi, yi});
    }

    for(int i = 0; i < n; i++){
        int ci;
        cin >> ci ;
        pcosts.push_back(ci);
    }

    for(int i = 0; i < n; i++){
        int ki;
        cin >> ki;
        kis.push_back(ki);
    }

    vector<ll> leer(n, 0);
    vector<vector<ll> > adj(n, leer);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ll dist = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
            adj[i][j] = dist * (kis[i] + kis[j]);
            adj[j][i] = adj[i][j];
        }
    }

    priority_queue<tuple<ll, int, int> > pq; // dist, node, vorg
    for(int i = 0; i < n; i++){
        pq.push(make_tuple(-pcosts[i], i, -1));
    }

    ll sol = 0;
    vector<bool> stations(n, 0);
    vector<pair<int, int> > connec;
    vector<bool> is_con(n, 0);

    while(!pq.empty()){
        ll d;
        int v;
        int vorg;
        tie(d, v, vorg) = pq.top();
        pq.pop();

        if(is_con[v] == 1){
            continue;
        }

        is_con[v] = 1;
        sol -= d;

        if(vorg == -1){
            stations[v] = 1;
        }
        else{
            connec.push_back({v, vorg});
        }

        for(int i = 0; i < n; i++){
            if(!is_con[i]){
                pq.push(make_tuple(-adj[v][i], i, v));
            }
        }
    }

    cout << sol << endl;

    vector<int> allst;
    for(int i = 0; i < n; i++){
        if(stations[i]){
            allst.push_back(i);
        }
    }

    cout<< allst.size() << endl;

    for(int i = 0; i < allst.size()-1; i++){
        cout << allst[i]+1 << " ";
    }
    cout << allst.back()+1 << endl;

    cout << connec.size() << endl;

    for(int i = 0; i < connec.size(); i++){
        cout << connec[i].first+1 << " " << connec[i].second+1 << endl;
    }

    return 0;
}
