#include <bits/stdc++.h>
#define um unordered_map
#define us unordered_set
#define f first
#define s second
#define pb push_back
#define MOD 1000000007
#define MOD2 1000000009
#define BASE 29
#define BASE2 31
#define eps 1e-9
#define INF 1000000002

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<pii,pii> piiii;
const int N = 1002;
const int BIT = 50;

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n,m ;
        scanf("%d",&n);
        int odd = 0, even = 0;
        for(int i =0;i<n;i++) {
            int x;
            scanf("%d",&x);
            if(x&1)
                odd++;
            else
                even++;
        }
        scanf("%d",&m);
        ll ans = 0;
        for(int i =0;i<m;i++) {
            int x,y;
            scanf("%d",&x);
            if(x&1) {
                ans += odd;
            } else {
                ans += even;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
