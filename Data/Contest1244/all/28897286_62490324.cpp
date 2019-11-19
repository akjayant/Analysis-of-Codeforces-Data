#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAX 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define zoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

ll solve(ll a, ll b) {
    if(a > b)
        swap(a, b);
    if(a == 0 && b == 1)
        return 2;
    if(a == 0 && b == 2)
        return 1;
    return 0;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    zoom;
    ll n, i, j;
    cin >> n;
    vector<vector<ll> > color(n, vector<ll>(3, 0));
    for(i = 0; i < n; i += 1) 
        cin >> color[i][0];
    for(i = 0; i < n; i += 1) 
        cin >> color[i][1];
    for(i = 0; i < n; i += 1)
        cin >> color[i][2];
    vector<vector<ll> > Graph(n, vector<ll>());
    vector<bool> vis(n, false);
    for(i = 0; i < n - 1; i += 1) {
        ll u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    ll strt = -1;
    for(i = 0; i < n; i += 1) {
        ll temp = (ll)Graph[i].size();
        if(temp > 2) {
            cout << -1;
            return 0;
        }
        if(temp == 1)
            strt = i;
    }
    if(strt == -1) {
        cout << -1;
        return 0;
    }
    vector<ll> look(n);
    look[0] = strt;
    vis[strt] = true;
    for(i = 1; i < n; i += 1) {
        ll temp = (ll)Graph[strt].size();
        for(j = 0; j < temp; j += 1) {
            if(vis[Graph[strt][j]])
                continue;
            vis[Graph[strt][j]] = true;
            look[i] = Graph[strt][j];
            strt = Graph[strt][j];
            break;
        }
    }
    ll ans = -1;
    vector<ll> buffer(n);
    vector<ll> req(n);
    for(i = 0; i < 3; i += 1) {
        for(j = 0; j < 3; j += 1) {
            if(i == j)
                continue;
            ll one = i;
            ll two = j;
            buffer[look[0]] = one;
            buffer[look[1]] = two;
            ll temp = color[look[0]][one] + color[look[1]][two];
            for(ll k = 2; k < n; k += 1) {
                ll three = solve(one, two);
                buffer[look[k]] = three;
                temp += color[look[k]][three];
                one = two;
                two = three;
            }
            if(ans == -1)
                ans = temp;
            if(temp <= ans) {
                ans = temp;
                req = buffer;
            }
        }
    }
    cout << ans << endl;
    for(i = 0; i < n; i += 1)
        cout << req[i] + 1 << " ";
    return 0;
}