#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
//using namespace __gnu_pbds;
//typedef tree<
//        pair<long long, int>, // change type
//        null_type,
//        less<pair<long long, int> >, // change type
//        rb_tree_tag,
//        tree_order_statistics_node_update>
//        ordered_set;

//template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
#define rep(i, start, end) for(int i = start; i < end; ++i)
#define sz(x) (int)(x).size()
#define pb push_back
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define clr(d, v) memset(d, v, sizeof(d))
#define pii pair<int, int>
#define debug(x) cerr << #x << " : " << (x) << endl
const double PI = 3.14159265358979323846;
const double eps = (1e-5);
int isGreater(long double x, long double y)
{
    if (abs(x - y) < eps)
        return 0;
    if (x > y)
        return 1;
    return -1;
}

const int MOD = 1000000007;
int add(int x, int y){
    x += y;
    while(x >= MOD)
        x -= MOD;
    while(x < 0)
        x += MOD;
    return x;
}

string s;
const int MAX_N = 1e5 + 5;
int mem[MAX_N][26];

int solve(int i, int prev){
    if (i == sz(s))
        return 1;
    int &ret = mem[i][prev];
    if (~ret)
        return ret;
    ret = solve(i + 1, s[i] - 'a');
    if (s[i] == 'u' && prev + 'a' == 'u')
        ret = add(ret, solve(i + 1, 'w' - 'a'));
    if (s[i] == 'n' && prev + 'a' == 'n')
        ret = add(ret, solve(i + 1, 'm' - 'a'));
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("facebook.txt", "w", stdout);
#endif
    cin >> s;
    clr(mem, -1);
    rep(i,0,sz(s)){
        if (s[i] == 'w' || s[i] == 'm')
        {
            cout << 0;
            return 0;
        }
    }
    cout << solve(0, 0);
    return 0;
}