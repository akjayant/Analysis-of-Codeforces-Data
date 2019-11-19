#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <bitset>
#define ll long long
using namespace std;

ll dp[40][2][2][2][2];
ll Solve(ll l, ll r, int bid, bool first_greater, bool first_less, bool second_greater, bool second_less) {
    if (bid == 0) {
        return 1;
    }
    
    if (dp[bid][first_greater][first_less][second_greater][second_less]!=-1)
        return dp[bid][first_greater][first_less][second_greater][second_less];
    
    int lb = (l>>(bid-1))&1;
    int rb = (r>>(bid-1))&1;
    ll ans = 0;
    for(int b1=0;b1<=1;b1++)
        for(int b2=0;b2<=1;b2++) {
            if (b1 == 1 && b2 == 1)
                continue;
            if (!first_greater && b1 < lb)
                continue;
            if (!first_less && b1 > rb)
                continue;
            if (!second_greater && b2 < lb)
                continue;
            if (!second_less && b2 > rb)
                continue;
            ans += Solve(l, r, bid-1,
                         first_greater | (b1 > lb),
                         first_less | (b1 < rb),
                         second_greater | (b2 > lb),
                         second_less | (b2 < rb));
        }
    return dp[bid][first_greater][first_less][second_greater][second_less]=ans;
}


int main() {
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        ll L,R;
        cin>>L>>R;
        
        for(int bid=0;bid<=33;bid++)
            for(int first_greater=0;first_greater<=1;first_greater++)
                for(int first_less=0;first_less<=1;first_less++)
                    for(int second_greater=0;second_greater<=1;second_greater++)
                        for(int second_less=0;second_less<=1;second_less++)
                            dp[bid][first_greater][first_less][second_greater][second_less]=-1;
        
        cout << Solve(L,R,33,0,0,0,0) << endl;
        
    }
}
