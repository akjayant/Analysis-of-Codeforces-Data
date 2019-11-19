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

const int S_SIZE = 34;
string toBinary(int x){
    string ret;
    while(x){
        ret += (x%2) + '0';
        x /= 2;
    }
    while (sz(ret) < S_SIZE)
        ret += '0';
    reverse(all(ret));
    return ret;
}
int l, r;
string ls, rs;
long long mem[S_SIZE][2][2];

long long solve(int i, bool s1, bool s2){
    if (i == S_SIZE)
        return 1;
    long long &ret = mem[i][s1][s2];
    if (~ret)
        return ret;
    ret = 0;
    // 0 0
    ret += solve(i + 1, s1|(rs[i] == '1'), s2 |(ls[i] =='1'));

    //0 1
    if (ls[i] == '1' || s2){
        ret += solve(i + 1, s1|(rs[i] == '1'), s2);
    }

    // 1 0
    if (rs[i] == '1' || s1){
        ret += solve(i + 1, s1, s2|(ls[i] == '1'));
    }
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
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> l >> r;
        rs = toBinary(r);
        ls = toBinary(r);
        clr(mem, -1);
        long long ans = solve(0, 0, 0);
        if (l > 0)
        {
            rs = toBinary(r);
            ls = toBinary(l - 1);
            clr(mem, -1);
            ans -= solve(0,0,0);

            rs = toBinary(l - 1);
            ls = toBinary(r);
            clr(mem, -1);
            ans -= solve(0,0,0);

            rs = toBinary(l - 1);
            ls = toBinary(l - 1);
            clr(mem, -1);
            ans += solve(0,0,0);
        }
        cout << ans << '\n';
    }
    return 0;
}