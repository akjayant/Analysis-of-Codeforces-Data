
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>

#define ll long long
#define vll vector<long long>

#define fori(a, b) for(ll i = a;i <= b;i++)
#define forj(a, b) for(ll j = a;j <= b;j++)
#define fork(a, b) for(ll k = a;k <= b;k++)

#define input2(a, b) cin >> a >> b;
#define input(a) cin >> a;

#define max(a,b) (a<b?b:a)
#define min(a,b) (a>b?b:a)

using namespace std;

ll MOD = 998244353;

ll power(ll x, ll n, ll mod){
    if(n == 0){
        return 1;
    }
    ll temp = power(x, n/2, mod);
    if(n % 2 == 1){
        return (x*temp*temp)%mod;
    } else {
        return (temp*temp)%mod;
    }
}
ll abs(ll a, ll b){
    if(a > b){
        return a - b;
    }
    return b - a;
}
ll fac(ll n){
    ll sol = 1;
    fori(1, n){
        sol *= i;
        sol %= MOD;
    }
    return sol;
}
ll size(ll n){
    ll sol = 0;
    while(n){
        n /= 2;
        sol++;
    }
    return sol;
}
ll fromBinary(string n){
    ll sol = 0;
    for(ll i = 0;i < n.size();i++){
        sol += n[i] - '0';
        sol *= 2;
    }
    return sol/2;
}

vll num;
set<ll> num2;
vll deleted;

void check(ll a, ll b, bool deleteOrNo){
    if(num2.count(abs(a-b))){
        check(abs(a-b),a,true);
    } else if(deleteOrNo){
        num2.erase(a);
        deleted.push_back(a);
    }
}
bool thinksHeIsBetter(ll a, ll b){
    while(1){
        if(a % 2 == 1 && b % 2 == 0){
            return true;
        } else {
            a /= 2;
            b /= 2;
        }
        if(a == 0 && b == 0){
            return false;
        }
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //
    ll n;
    cin >> n;
    ll ceny[3][n];
    fori(0, n-1){
        cin >> ceny[0][i];
    }
    fori(0, n-1){
        cin >> ceny[1][i];
    }
    fori(0, n-1){
        cin >> ceny[2][i];
    }
    vector<vector<ll>> graph;
    fori(0,n){
        graph.push_back({});
    }
    ll a,b;
    fori(0, n-2){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll colorings[6][3] = {{0,1,2},{0,2,1},{1,2,0},{1,0,2},{2,0,1},{2,1,0}};
    ll aku[6][3] = {{0,1,2},{0,2,1},{2,0,1},{1,0,2},{1,2,0},{2,1,0}};
    ll main;
    queue<ll> check;
    set<ll> seen;
    ll sol;
    ll lowest = 10000000000000000;
    ll color[n+1];
    ll lowestC[n+1];
    ll firstMain;
    fori(0, 5){
        //cout << "-------------" << endl;
        forj(1,n){
            if(graph[j].size() == 1){
                firstMain = j;
                break;
            }
        }
        while(check.size() > 0){
            check.pop();
        }
        check.push(firstMain);
        seen.clear();
        seen.insert(firstMain);
        color[firstMain] = colorings[i][0];
        sol = 0;
        sol += ceny[colorings[i][0]][firstMain-1];
        while(!check.empty()){
            main = check.front();
            check.pop();
            for(ll j = 0;j < graph[main].size();j++){
                if(graph[main].size() > 2){
                    cout << -1 << endl;
                    return 0;
                }
                if(seen.count(graph[main][j])){
                    continue;
                }
                color[graph[main][j]] = colorings[i][((aku[i][color[main]]+1) % 3)];
                //cout << color[main] << endl;
                //cout << graph[main][j] << " ma farbu " << color[graph[main][j]] << endl;
                //cout << "              " << colorings[i][(aku[i][color[main]] + 1)% 3] << " " << colorings[i][color[main]] << endl;
                sol += ceny[colorings[i][(aku[i][color[main]]+1)%3]][graph[main][j]-1];
                check.push(graph[main][j]);
                seen.insert(graph[main][j]);
            }
        }
        if(sol < lowest){
            lowest = sol;
            for(ll j = 1;j <= n;j++){
                lowestC[j] = color[j];
            }
        }
    }
    cout << lowest << endl;
    fori(0, n-1){
        if(i != 0){
            cout << " ";
        }
        cout << lowestC[i+1]+1;
    }
    cout << endl;
    return 0;
}

