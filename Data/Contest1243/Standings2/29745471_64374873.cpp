#include <bits/stdc++.h>

#define int long long int
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define mii map<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, maxim;
    cin>>k;
    while (k--)
    {
        cin>>n;
        maxim=0;
        vi a(n);
        for (i=0; i<n; i++)
            cin>>a[i];
        sort (a.begin(), a.end());
        for (i=0; i<n; i++)
            maxim=max(maxim, min(a[i], n-i));
        cout<<maxim<<'\n';
    }
}
