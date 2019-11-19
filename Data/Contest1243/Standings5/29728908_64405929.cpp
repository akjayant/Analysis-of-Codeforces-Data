#include <bits/stdc++.h>
    #define ll long long
    #define ld long double
    #define pi 3.14159265358979323846
    #define endl '\n'
    #define yes "Yes"
    #define no "No"
    #define sz(smth) (int) (smth.size())
    #define dohera 1000000000000000000LL
    #define nsort(v) sort(v.begin(), v.end())
    #define rsort(v) sort(v.rbegin(), v.rend())
    #define mod 1000000007LL

    using namespace std;

    ll gcd(ll a, ll b) {
        return (b == 0LL ? a : gcd(b, a % b));
    }


    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        //ifstream cin("input.txt");

        ll n;
        cin >> n;

        ll cnt = 0, g = 0;

        for (ll i = 2LL; i * i <= n; i++) {

            if (n % i == 0) {
                cnt++;
                g = gcd(g, i);
                g = gcd(g, n / i);

                //cout << i << endl;
            }

        }

        if (cnt == 0) cout << n;
        else cout << g;



    }

/*

1
3
abc
bca
3
cat
dog
2
aa
az



*/


