///not today

#include<bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define pb push_back
#define ll long long
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define int long long
#define pipii pair<int, pair<int, int> >
#define pf push_front

const int mod = 1000* 1000* 1000 + 7, maxn = 1000* 100 + 5;
int dp[maxn];

int32_t main(){
    string s;
    cin >>s;
    dp[1] = 1;
    dp[0] = 1;
    for(int i = 2; i < maxn; i ++){
        dp[i] = (dp[i - 1] + dp[i - 2])% mod;
    }
    int cn = 0, ans = 1;
    for(int i = 0; i < SZ(s); i ++){
        cn ++;
        if(i == SZ(s) - 1 or s[i + 1] != s[i]){
            if(s[i] == 'u' or s[i] == 'n')
                ans = (dp[cn]* ans)% mod;
            cn = 0;
        }
        if(s[i] == 'm' or s[i] == 'w')
            return cout <<0 <<endl, false;
    }
    cout <<ans <<endl;
    return false;
}
