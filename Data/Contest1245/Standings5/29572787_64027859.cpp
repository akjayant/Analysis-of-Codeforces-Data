#include<bits/stdc++.h>
typedef long long int ll;

using namespace std;

const int MAXN = 1e5 + 123;
const ll MOD = 1e9 + 7;
int c[MAXN];
int k[MAXN];
int x[MAXN], y[MAXN], roshan[MAXN], par[MAXN], sz[MAXN];

vector <pair<ll, pair<int, int>>> e;
vector <int> ted1;
vector <pair<int, int>> ted2;

void besaz(int n){
    for(int i = 0; i < n; i ++)
        for(int j = i + 1; j < n; j ++){
            int megh = abs(x[j] - x[i]) + abs(y[j] - y[i]);
            pair<ll, pair<int, int>> tmp;
            tmp.first = (ll) (k[i] + k[j]) * megh;
            tmp.second.first = i;
            tmp.second.second = j;
            e.push_back(tmp);
        }
    for(int i = 0; i < n; i ++){
        pair<ll, pair<int, int>> tmp;
        tmp.first = c[i];
        tmp.second.first = i;
        tmp.second.second = i;
        e.push_back(tmp);
    }
    sort(e.begin(), e.end());
    for(int i = 0; i < n; i ++)
        par[i] = -1, sz[i] = 1;
}
int pr(int x){
    while(par[x] != -1)
        x = par[x];
    return x;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> x[i] >> y[i];
    for(int i = 0; i < n; i ++)
        cin >> c[i];
    for(int i = 0; i < n; i ++)
        cin >> k[i];
    besaz(n);
    ll ans = 0;
    for(int i = 0; i < e.size(); i ++){
        int a = e[i].second.first, b = e[i].second.second;
        //cerr << " a: " << a << " b: " << b << " andaze: " << e[i].first << "\n";
        if(a == b){
            a = pr(a);
            if(!roshan[a]){
                ted1.push_back(b + 1);
                roshan[a] ++;
                ans += e[i].first;
            }
        }
        else{
            pair <int, int> tmp;
            tmp.first = a + 1, tmp.second = b + 1;
            a = pr(a), b = pr(b);
            if(a == b)
                continue;
            if(roshan[a] && roshan[b])
                continue;
            ans += e[i].first;
            ted2.push_back(tmp);
            if(sz[a] > sz[b]){
                par[b] = a;
                sz[a] += sz[b];
                roshan[a] += roshan[b];
            }
            else{
                par[a] = b;
                sz[b] += sz[a];
                roshan[b] += roshan[a];
            }
        }
    }
    cout << ans << "\n";
    cout << ted1.size() << "\n";
    for(auto u:ted1)
        cout << u << " ";
    cout << "\n";
    cout << ted2.size() << "\n";
    for(auto u:ted2)
        cout << u.first << " " << u.second << "\n";

}
