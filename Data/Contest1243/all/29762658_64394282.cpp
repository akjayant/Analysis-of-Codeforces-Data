    #include <bits/stdc++.h>

    #define MAX 10e15+1
    #define MIN 0
    #define MOD 998244353
    #define FOR(i, a, b)    for(int i=a;i<b;i++)
    using namespace std;
    typedef long long ll;
    typedef vector<ll> vll;
    typedef vector<int> vi;
    typedef pair<ll,ll> pll;
    typedef pair<double,double> ii;
    typedef vector<pll> vpll;
    ll N; ll M; ll Q; ll T;
    vll vl;
    string s1,s2;
    vector<ll> cunt;
    queue<pll> ans;
    int main() {
        cin >> T;
        FOR(k, 0, T) {
            cunt.clear();
            cin >> N;
            cin >> s1 >> s2;
            cunt.resize(200);
            FOR(i, 0, N) {
                int a = s1[i];
                int b = s2[i];
                cunt[a]++;
                cunt[b]++;
            }
            bool se = true;
            FOR(i, 0, 200) {
                if (cunt[i] % 2 != 0) se = false;
            }
            if (!se) {cout << "No" << endl;}
            else {
                FOR(i, 0, N) {
                    if (s1[i] != s2[i]) {
                        bool encon = false;
                        FOR(j, i + 1, N) {
                            if (s1[j] == s1[i]) {
                                encon = true;
                                pll mien(j+1, i+1);
                                char mient=s1[j];
                                s1[j]=s2[i];
                                s2[i]=mient;
                                ans.push(mien);
                                break;
                            }

                        }
                        if (!encon) {
                            FOR(j, i + 1, N) {
                                if (s2[j] == s1[i]) {
                                    pll miena(j+1, j+1);
                                    pll mienb(j+1, i+1);
                                    char mient=s1[j];
                                    s1[j]=s2[j];
                                    s2[j]=mient;
                                    mient=s1[j];
                                    s1[j]=s2[i];
                                    s2[i]=mient;
                                    ans.push(miena);
                                    ans.push(mienb);
                                    break;
                                }
                            }
                        }
                    }
                }
                cout << "Yes" << endl;
                cout << ans.size() << endl;
                while(!ans.empty()){
                    pll mien = ans.front();
                    ans.pop();
                    cout << mien.first << ' ' << mien.second << endl;
                }
            }

        }
    }

