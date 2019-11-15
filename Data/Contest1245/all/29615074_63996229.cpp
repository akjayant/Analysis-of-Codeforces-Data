#define IOS ios::sync_with_stdio(false);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int M = 3e5 + 7;
const int INF = 1e8 + 7;
ll mod = 998244353;

int t, a, b;

int main(){

    IOS
    cin >> t;
    while(t --){
        cin >> a >> b;
        cout << (__gcd(a, b) == 1 ? "Finite" : "Infinite") << endl;
    }


    return 0;
}