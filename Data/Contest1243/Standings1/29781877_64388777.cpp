#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
//#define i first
//#define j second

//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

const int N = 300 * 1000 + 5;

void test() {
    int n;
    cin >> n;

    string s;
    map<char, int> m;
    cin >> s;
    for(char c : s) m[c]++;

    string t;
    cin >> t;
    for(char c : t) m[c]++;

    for(auto p : m){
        if(p.second % 2 == 1) {
//            db(p.first);
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;

    vc<pii> ans;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){
            char y = t[i];
            int yi;
            for(yi = i+1; yi < n; yi++){
                if(t[yi] == y){
                    break;
                }
            }

            // lave
            if(yi != n){
                swap(s[i], t[yi]);
                ans.push_back({i,yi});
                continue;
            }

            // search in s y
            for(yi = i+1; yi < n; yi++) {
                if (s[yi] == y) {
                    break;
                }
            }
            swap(s[yi], t[i+1]);
            ans.push_back({yi,i+1});

            swap(s[i], t[i+1]);
            ans.push_back({i,i+1});


        }
    }
    cout << ans.size() << endl;
    for(auto p : ans){
        cout << p.first+1 << ' ' << p.second+1 << endl;
    }

}

int main() {


    int t;
    cin >> t;
    loop(i, t) test();
    return 0;
}
/*



*/