#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <cmath>
#include <numeric>
#include <iomanip>
#include <deque>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <sstream>

#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define pb push_back
#define pf push_front

using ll = long long;
using namespace std;

ll M = 1000000007;
typedef pair<int, int> P;

int main()
{
    int t;
    scanf("%d",&t);
    rep(i,t){
        int n,m;
        scanf("%d",&n);
        vector<int>p(n);
        int odd=0, even=0;
        int odd2=0,even2=0;
        rep(j,n){
            scanf("%d",&p[j]);
            if(p[j]%2==0){
                even++;
            }else{
                odd++;
            }
        }
        scanf("%d",&m);
        vector<int>q(m);
        rep(j,m){
            scanf("%d",&q[j]);
            if(q[j]%2==0){
                even2++;
            }else{
                odd2++;
            }
        }
        ll ans=(ll)even*even2+(ll)odd*odd2;
        printf("%lld\n",ans);
    }
}
