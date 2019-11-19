#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e3 + 9 ;
int a[N];
vector < ll > factors;
void factorize(ll num){
    for(ll i = 2 ; i*i<=num ; ++i){
        if(num % i == 0){
            factors.push_back(i);
            if(i!=num/i)
                factors.push_back(num / i);
        }
    }
}
int main()
{
    int t;
//    cin >> t;
//    while(t--){
//        string s , t;
//        int n;
//        cin >> n >> s >> t;
//        int cnt = 0;
//        bool f = 1;
        ll n ;
        cin >> n;
        ll ans = n;
        factorize(n);
        for(int i = 0 ; i < factors.size() ; ++i){
            ans = __gcd(ans , factors[i]);
        }
        cout << ans << endl;


   // }
    return 0;
}
