#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
const int N = 3e5+100, M=1e5+10, INF=1e9;
 
int a[N], n, m;
vector<ii> p[N];
ll ans;
map<ii, int> mp;
 
void solve(){
    mp.clear();
    for(int i=0 ; i<N ; i++)
        p[i].clear();
 
    for(int i=0 ; i<m ; i++)
        p[i-a[i]+1+M].push_back(ii(a[i]-1, i));
    
    for(int i=0 ; i<N ; i++)
        sort(p[i].begin(), p[i].end());
 
    for(int i=0 ; i<n ; i++){
        int it = i, t=0;
        vector<ii> path;
        while(it<n && t<=m){
            if(mp.count(ii(it, t))){
                it = mp[ii(it, t)];
                break;
            }
            
            path.push_back(ii(it, t));

            vector<ii> &vec = p[t-it+M];
            int ind = lower_bound(vec.begin(), vec.end(), ii(it, -INF)) - vec.begin();
            if(ind == vec.size() || it+m-t+1 < vec[ind].first){
                it += m-t+1;
                t = m+1;
            }else{
                t = vec[ind].second+1;
                it = vec[ind].first;
            }
        }
        for(auto P : path)
            mp[P] = it;
        it = min(it, n-1);
        ans += it-i;
    }
}
 
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    if(n == 1){
        if(m == 0)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
        return 0;
    }
    ans=n;
    for(int i=0 ; i<m ; i++){
        cin >> a[i];
        a[i] --;
    }
    solve();
    for(int i=0 ; i<m ; i++)
        a[i] = n-a[i]-1;
    solve();
    cout << ans << "\n";
}
 
