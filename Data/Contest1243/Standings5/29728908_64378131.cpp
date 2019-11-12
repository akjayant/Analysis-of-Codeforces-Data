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


    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        //ifstream cin("input.txt");

        ll t;
        cin >> t;

        while (t--) {

            int n;
            string str, t;

            cin >> n >> str >> t;
            int f = -1, s = -1;
            bool flag = 1;

            for (int i = 0; i < n; i++) {

                if (str[i] == t[i]) continue;

                if (f == -1) f = i;
                else if (s == -1) s = i;
                else {
                    flag = 0;
                }

            }

            if (s == -1 || f == -1) {
                flag = 0;
            }
            if (str[f] != str[s] || t[s] != t[f]) flag = 0;

            if (flag) cout << yes << endl;
            else cout << no << endl;

        }



    }


