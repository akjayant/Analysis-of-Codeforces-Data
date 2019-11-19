#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+10 ;

ll a[N];
int main()
{
    ll n;

    cin >> n;
    ll sum = 0 ;
    for(ll i = 1 ; i<= n ; i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    ll cnt = 0 ;
    for(int i = 1 ; i <= n/2 ; i++)
    {
        cnt+=a[i];
    }
    cout << (sum-cnt)*(sum-cnt)+cnt*cnt <<endl;
}
