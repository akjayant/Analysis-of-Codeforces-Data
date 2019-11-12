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
        vi v(n);
        fr(n) cin >> v[i];
        sort(all(v));
        reverse(all(v));
        int i = 0;
        for(i = 0 ; i < n ; i++)
            if(i + 1 > v[i]){
                cout << i << endl;
                break;
        }
        else
            if( i + 1 == v[i])
                {
                cout << i + 1<< endl;
                break;
        }

    }
}
