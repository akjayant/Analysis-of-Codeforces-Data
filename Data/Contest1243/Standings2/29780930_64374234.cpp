#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const LL llinf=987654321987654321;
const int inf=987654321;
int q;
int n, arr[1010];
int main()
{
    scanf("%d", &q);
    for(int u=1; u<=q; u++){
        int ans=0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
        }
        sort(arr+1, arr+n+1);
        for(int i=n; i>=1; i--){
            int temp=min(n-i+1, arr[i]);
            ans=max(ans, temp);
        }
        printf("%d\n", ans);
    }
}
