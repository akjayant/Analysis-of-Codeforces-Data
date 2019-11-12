#include <bits/stdc++.h>
    #define ll long long
    #define ld long double
    #define pi 3.14159265358979323846
    #define endl '\n'
    #define yes "YES"
    #define no "NO"
    #define sz(smth) (int) (smth.size())
    #define dohera 1000000000000000000LL
    #define nsort(v) sort(v.begin(), v.end())
    #define rsort(v) sort(v.rbegin(), v.rend())
    #define mod 1000000007LL

    using namespace std;


    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        //ifstream cin("input.txt");

        ll t;
        cin >> t;

        while (t--) {

            int n;
            cin >> n;
            vector<int> v(n);

            for (int i = 0; i < n; i++) cin >> v[i];
            rsort(v);

            int ans = 0;

            for (int i = 0; i < n; i++) {

                if (v[i] >= i + 1) ans = i + 1;
                else break;

            }

            cout << ans << endl;

        }



    }


