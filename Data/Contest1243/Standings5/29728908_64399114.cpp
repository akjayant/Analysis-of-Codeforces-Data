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
            string s, t;

            cin >> n >> s >> t;

            vector< pair<int, int> > res;

            for (int i = 0; i < n; i++) {
                if (s[i] == t[i]) continue;

                for (int j = 0; j < n; j++) {

                    if (i != j && t[i] == t[j] && s[j] != t[j]) {
                        swap(s[i], t[j]);
                        res.push_back( {i, j} );

                        //cout << s << " ! " << t << endl;
                        break;
                    }

                }

                if (s[i] == t[i]) continue;

                for (int j = i + 1; j < n; j++) {

                    if (t[i] == s[j] && s[j] != t[j]) {

                                swap(s[j], t[j]);
                                swap(s[i], t[j]);
                                res.push_back( {j, j} );
                                res.push_back( {i, j} );

                                break;


                    }

                }



            }

            //cout << s << " " << t << endl;

            bool flag = 1;
            for (int i = 0; i < n; i++) {
                flag &= s[i] == t[i];
            }

            if (flag) {
                cout << yes << endl;
                cout << sz(res) << endl;
                for (auto it : res) cout << it.first + 1 << " " << it.second + 1<< endl;
            }
            else cout << no << endl;




    }


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


