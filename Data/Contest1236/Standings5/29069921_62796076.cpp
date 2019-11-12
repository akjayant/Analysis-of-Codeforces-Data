#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double pi = acos(-1.0);
#define eps 10e-8
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll inverse(ll a) { return a == ll(1) ? ll(1) : (mod - mod / a) * inverse(mod % a) % mod; } // 求逆元
const int MAXN = 1e6 + 5;
const int MAXM = 2 * MAXN;
const int INF = 0x3f3f3f3f;
//clock_t c1 = clock(); //测时间
//std::cerr << "Time:" << clock() - c1 <<"ms" << std::endl;
//=======================================================================//
vector<int> ans[350];
int main()
{
    int n;
    scanf("%d", &n);
    int tag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (tag)
        {
            for (int j = 1; j <= n; j++)
            {
                ans[j].push_back(n*(i-1)+j);
            }
        }
        else {
            for (int j=1;j<=n;j++){
                ans[n-j+1].push_back(n*(i-1)+j);
            }
        }
        tag^=1;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<n;j++){
            printf("%d",ans[i][j]);
            if (j<n-1)printf(" ");
            else printf("\n");
        }
    }
    return 0;
}