#include<bits/stdc++.h>
#define m_p make_pair
#define ss second
#define ff first
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e4+5;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    ll j_min = -1;
    if (n&1)
    {
        bool no=0;
        for (ll i=3; i<=sqrt(n)+1; i+=2)
            if (n%i == 0) {j_min = i; break;}
    }
    else if (n!=2) j_min = 2;
    if (j_min == -1) return cout << n, 0;
    while(n>0 && n%j_min==0)
        n/=j_min;
    if (n == 1) return cout << j_min, 0;
    cout << 1;

}
