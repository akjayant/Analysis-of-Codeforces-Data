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
    int n;
    scanf("%d",&n);
    vector<int> vec(n);
    for(int i =0;i<n;i++)
        scanf("%d",&vec[i]);
    sort(vec.begin(), vec.end());
    ll ans = 0;
    ll x = 0, y = 0;
    for(int i = 0;i<n/2;i++) {
        x+= vec[i];
    }
    for(int i = n/2;i<n;i++) {
        y += vec[i];
    }
    printf("%lld",x*x+y*y);
    return 0;
}
