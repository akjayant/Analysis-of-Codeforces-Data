#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000;
long long n,k;
long long a[maxn];
int e=0,u=0;
long long m[maxn], sz[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>k;
    for (int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    m[0] = a[0];
    sz[0] = 1;
    for (int i=1; i<n; i++) {
        if (a[i] == m[u]) {
            sz[u]++;
        } else {
            m[++u] = a[i];
            sz[u] = 1;
        }
    }
    while (e!=u && (k>=sz[e] || k>=sz[u])) {
        if (sz[e]<=sz[u]) { ///e
            if ( k > sz[e]*(m[e+1]-m[e]) ) {
                k -= sz[e]*(m[e+1]-m[e]);
                sz[e+1] += sz[e];
                e++;
            } else {
                m[e] += k/sz[e];
                k -= (k/sz[e])*sz[e];
            }
        } else {    ///u
            if ( k > sz[u]*(m[u]-m[u-1]) ) {
                k -= sz[u]*(m[u]-m[u-1]);
                sz[u-1] += sz[u];
                u--;
            } else {
                m[u] -= k/sz[u];
                k -= (k/sz[u])*sz[u];
            }
        }
    }
    cout<< m[u]-m[e] <<'\n';

    return 0;
}
