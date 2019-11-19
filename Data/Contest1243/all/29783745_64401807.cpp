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
#define int long long
const int inf = 1000000000 + 7;
int check(int x){
if(x<2) return 0;
for(int i = 2; i*i <= x; i++)
    if(x%i == 0)
    return 0;
return 1;
}
signed main() {
    int n;
    cin >> n;
    if(check(n))
        re cout << n, 0;
        int t = 0;
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0){
            t = i;
            break;
        }
        int x = n;
    if(t){
        while(x % t == 0 && x > 1){
            x/=t;
        }
        if(x == 1)
            re cout << t,0;
    }
    cout << 1;
}
