#include<bits/stdc++.h>
#define m_p make_pair
#define ss second
#define ff first
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Q;
    cin >> Q;
    for (int q=0; q<Q; ++q)
    {
        int n;
        cin >> n;
        for (int i=0; i<n; ++i)
            cin >> a[i];
        sort(a, a+n);
        int ans=0;
        for (int i=n-1; i>=0; --i)
            ans = max(ans, min(a[i], n-i));
        cout << ans << '\n';
    }

}
