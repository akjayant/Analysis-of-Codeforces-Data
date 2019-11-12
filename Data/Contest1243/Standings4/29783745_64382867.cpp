#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
#include <deque>
#include <sstream>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef string str;
typedef long double ld;
typedef vector <vector <int>> graf;
#define pi M_PI
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define re return
#define X first
#define Y second
#define fr(x) for(int i = 0; i <(x); i++)
const int inf = 1000000000 + 7;

signed main() {
    int k;
    cin >> k;
    while(k--){
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        string s1,t1;
        int c = 0;
        vector<char> v1,v2;
        for(int i = 0 ; i < n; i++){
            if(s[i] == t[i])
                c++;
            else{
                v1.pb(s[i]);
                v2.pb(t[i]);
            }
        }
        if(s == t)
        {
            cout << "Yes\n";
            continue;
        }
        if(c==n-2){

            if(v1[0] == v1[1] && v2[1] == v2[0])
                {
                cout << "Yes\n";
                continue;
            }
        }
        cout << "No\n";
    }
}
