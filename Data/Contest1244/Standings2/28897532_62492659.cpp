#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
  #define watch(x) cout << (#x) << " is " << (x) << '\n'
  #define dashline() cout << "=============\n"
#else
  #define watch(x)
  #define dashline()
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MX = 1e9;
const ll MX2 = 3e18;
const double pi = acos(-1);

const int MOD = 1e9+7;
const int SZ = 524288;

int arr[200005];

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n; cin>>n; ll k; cin>>k;

    int i;
    for(i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1); arr[0]=arr[1]; arr[n+1]=arr[n];
    int l=1,r=n;
    int p1,p2;
    ll d;
    while(arr[l]!=arr[r] && l<r)
    {
        p1 = upper_bound(arr+1,arr+n+1,arr[l]) - arr - 1;
        p2 = arr+n+1 - lower_bound(arr+1,arr+n+1,arr[r]);

        if (p1<p2)
        {
            d=arr[p1+1]-arr[p1];
            if (k<p1*d)
            {
                d=k/p1;
                arr[l]+=d;
                break;
            }
            k-=p1*d;
            l=p1+1;
        }
        else
        {
            d=arr[n-p2+1]-arr[n-p2];
            if(k<p2*d)
            {
                d=k/p2;
                arr[r]-=d;
                break;
            }
            k-=p2*d;
            r=n-p2;
        }
    }
    watch(r); watch(l);
    cout<<max(0,arr[r]-arr[l]);
    return 0;
}
