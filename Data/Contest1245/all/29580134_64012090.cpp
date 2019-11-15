/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <list>
#include <climits>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
const ll inf = 1e9;
const int mod = 1e9+7;

char s[100010];
ll cnt[100010];

void solve() {
    int len = strlen(s);
    for(int i=0; i<len; i++) {
        if(s[i] == 'w' || s[i] == 'm') {
            printf("0\n");
            return;
        }
    }
    cnt[1] = 1; cnt[2] = 2; cnt[3] = 3;
    for(int i=4; i<=len+1; i++) {
        cnt[i] = cnt[i-1] + cnt[i-2];
        cnt[i] %= mod;
    }
    vi nums;
    for(int i=0; i<len;) {
        if(s[i] != 'u' && s[i] != 'n') i++;
        else if(s[i] == 'u') {
            int c = 0;
            while(i < len && s[i] == 'u') {
                i++; c++;
            }
            nums.push_back(cnt[c]);
        } else if(s[i] == 'n') {
            int c = 0;
            while(i < len && s[i] == 'n') {
                i++; c++;
            }
            nums.push_back(cnt[c]);
        }
    }
    ll ans = 1;
    for(int i=0; i<nums.size(); i++) {
        ans = (ans * nums[i]) % mod;
    }
    printf("%lld\n", ans);
}

int main() {
    int t, kase = 0;
    // scanf("%d", &t);
    t = 1;
    while(t--) {
        scanf("%s", s);
        //printf("Case #%d: %lld\n", ++kase, solve());
        solve();
    }
	return 0;
}
