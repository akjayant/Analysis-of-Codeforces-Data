#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define pd pair<double,double>
#define ld long double
#define pld pair<ld,ld>
#define lg length()
#define sz size()
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pi>
#define vpl vector<pl>
#define pb push_back
#define INF 1000000005
#define LINF 1000000000000000005
using namespace std;
int n;
ll c[4][100005];
vector <ll> g[100005];
ll ord[100005], ord1[100005];
ll a, b, root;
int main(){
    cin >> n;
    for(int i = 1; i <= n ; i++){
        cin >> c[1][i];
    }
    for(int i = 1; i <= n ; i++){
        cin >> c[2][i];
    }
    for(int i = 1; i <= n ; i++){
        cin >> c[3][i];
    }
    for(int i = 1 ; i < n ; i++){
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for(int i = 1; i <= n ; i++){
        if(g[i].size() >= 3){
            cout << -1;
            return 0;
        }
        if(g[i].size() == 1){
            root = i;
        }
    }
    ord1[1] = root;
    ord1[2] = g[root][0];
    int cur = ord1[2];
    int pos = 2;
    while(pos < n){
        ord1[pos+1] = (g[cur][0] + g[cur][1] - ord1[pos-1]);
        pos++;
        cur = ord1[pos];
    }
    for(int i = 1;  i <= n ; i++){
        ord[ord1[i]] = i;
    }
    ll rez = 1e18+7;
    ll rs = 1;
    ///////////////
    ll sum = 0;
    for(int i = 1;  i <= n ; i++){
        if(ord[i]%3 == 0){
            sum += c[1][i];
        }
        if(ord[i]%3 == 1){
            sum += c[2][i];
        }
        if(ord[i]%3 == 2){
            sum += c[3][i];
        }
    }
    if(sum < rez){
        rez = sum;
        rs = 1;
    }
    ///////////////
    sum = 0;
    for(int i = 1;  i <= n ; i++){
        if(ord[i]%3 == 0){
            sum += c[1][i];
        }
        if(ord[i]%3 == 1){
            sum += c[3][i];
        }
        if(ord[i]%3 == 2){
            sum += c[2][i];
        }
    }
    if(sum < rez){
        rez = sum;
        rs = 2;
    }///////////////
    sum = 0;
    for(int i = 1;  i <= n ; i++){
        if(ord[i]%3 == 0){
            sum += c[2][i];
        }
        if(ord[i]%3 == 1){
            sum += c[1][i];
        }
        if(ord[i]%3 == 2){
            sum += c[3][i];
        }
    }
    if(sum < rez){
        rez = sum;
        rs = 3;
    }///////////////
    sum = 0;
    for(int i = 1;  i <= n ; i++){
        if(ord[i]%3 == 0){
            sum += c[2][i];
        }
        if(ord[i]%3 == 1){
            sum += c[3][i];
        }
        if(ord[i]%3 == 2){
            sum += c[1][i];
        }
    }
    if(sum < rez){
        rez = sum;
        rs = 4;
    }///////////////
    sum = 0;
    for(int i = 1;  i <= n ; i++){
        if(ord[i]%3 == 0){
            sum += c[3][i];
        }
        if(ord[i]%3 == 1){
            sum += c[1][i];
        }
        if(ord[i]%3 == 2){
            sum += c[2][i];
        }
    }
    if(sum < rez){
        rez = sum;
        rs = 5;
    }///////////////
    sum = 0;
    for(int i = 1;  i <= n ; i++){
        if(ord[i]%3 == 0){
            sum += c[3][i];
        }
        if(ord[i]%3 == 1){
            sum += c[2][i];
        }
        if(ord[i]%3 == 2){
            sum += c[1][i];
        }
    }
    if(sum < rez){
        rez = sum;
        rs = 6;
    }
    cout << rez << '\n';
    /////////////
    if(rs == 1){
        for(int i = 1;  i <= n ; i++){
        if(ord[i]%3 == 0){
            cout << 1 << ' ';
        }
        if(ord[i]%3 == 1){
            cout << 2 << ' ';
        }
        if(ord[i]%3 == 2){
            cout << 3 << ' ';
        }
    }
    }
    /////////////
    if(rs == 2){
        for(int i = 1;  i <= n ; i++){
        if(ord[i]%3 == 0){
            cout << 1 << ' ';
        }
        if(ord[i]%3 == 1){
            cout << 3 << ' ';
        }
        if(ord[i]%3 == 2){
            cout << 2 << ' ';
        }
    }
    }
    /////////////
    if(rs == 3){
        for(int i = 1;  i <= n ; i++){
        if(ord[i]%3 == 0){
            cout << 2 << ' ';
        }
        if(ord[i]%3 == 1){
            cout << 1 << ' ';
        }
        if(ord[i]%3 == 2){
            cout << 3 << ' ';
        }
    }
    }
    /////////////
    if(rs == 4){
        for(int i = 1;  i <= n ; i++){
        if(ord[i]%3 == 0){
            cout << 2 << ' ';
        }
        if(ord[i]%3 == 1){
            cout << 3 << ' ';
        }
        if(ord[i]%3 == 2){
            cout << 1 << ' ';
        }
    }
    }
    /////////////
    if(rs == 5){
        for(int i = 1;  i <= n ; i++){
        if(ord[i]%3 == 0){
            cout << 3 << ' ';
        }
        if(ord[i]%3 == 1){
            cout << 1 << ' ';
        }
        if(ord[i]%3 == 2){
            cout << 2 << ' ';
        }
    }
    }
    /////////////
    if(rs == 6){
        for(int i = 1;  i <= n ; i++){
        if(ord[i]%3 == 0){
            cout << 3 << ' ';
        }
        if(ord[i]%3 == 1){
            cout << 2 << ' ';
        }
        if(ord[i]%3 == 2){
            cout << 1 << ' ';
        }
    }
    }
    return 0;
}
