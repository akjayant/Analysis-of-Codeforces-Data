#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin >> n;
    long long x[n],y[n];
    for(long long i = 0 ; i < n ; i += 1){
        cin >> x[i] >> y[i];
    }
    long long cs[n],ks[n];
    bool seen[n];
    for(long long i = 0 ; i < n ; i += 1){
        cin >> cs[i];
        seen[i] = false;
    }
    priority_queue<pair<long long,pair<long long,long long>>> pq;
    for(long long i = 0 ; i < n ; i += 1){
        pq.push({-cs[i],{i,-1}});
    }
    for(long long i = 0 ; i < n ; i += 1){
        cin >> ks[i];
    }
    long long ans = 0;
    vector<long long> ret1;
    vector<pair<long long,long long>> ret2;
    while(pq.size()){
        pair<long long,pair<int,int>> next = pq.top();
        pq.pop();
        if(seen[next.second.first]){
            continue;
        }
        if(next.second.second == -1){
            ret1.push_back(next.second.first);
        }else{
            ret2.push_back({next.second});
        }
        seen[next.second.first] = true;
        ans -= next.first;
        for(long long i = 0 ; i < n ; i += 1){
            if(!seen[i]){
                pq.push({-(ks[i]+ks[next.second.first])*(abs(x[i]-x[next.second.first])+abs(y[i]-y[next.second.first])),{i,next.second.first}});
            }
        }
    }
    cout << ans << '\n';
    cout << ret1.size() << '\n';
    for(long long i : ret1){
        cout << i+1 << " ";
    }cout << '\n' << ret2.size() << '\n';
    for(auto i : ret2){
        cout << i.first+1 << " " << i.second+1 << '\n';
    }
}