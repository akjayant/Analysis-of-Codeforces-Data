#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>
#include <iomanip>

#define make_unique(x) sort(all(x)),x.resize(unique(all(x))-x.begin())
#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ss second.second
#define sf second.first
#define ff first.first
#define fs first.second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define tr(x, y) ((x)*(x) + (y)*(y))

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector<ll> vll;
typedef long double ld;

const int N = 1000100;
const int M = 1000100;
const int inf = 1e9;

ll mod = 1e9 + 7;

ll st(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y % 2)
            ans = ans * x % mod;
        y /= 2;
        x = x * x % mod;
    }
    re ans;
}

int main(){
    #ifdef EKLER
        //freopen("input.txt", "r", stdin);
        //freopen("input.txt", "w", stdout);
    #else
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    ll n, m;
    cin >> n >> m;
    cout << st((st(2, m) - 1 + mod), n);
    re 0;
}

