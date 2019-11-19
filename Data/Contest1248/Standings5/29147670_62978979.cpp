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
const int sz = 262144;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    int i;

    ll sum=0,x;
    priority_queue<ll> pq;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x; sum+=x;
        pq.push(x);
    }
    int sz=0;
    ll sum2=0;
    while(sz<pq.size())
    {
        sum2+=pq.top(); pq.pop();
        sz++;
    }
    sum -= sum2;
    cout<<sum*sum+sum2*sum2;

    return 0;
}

