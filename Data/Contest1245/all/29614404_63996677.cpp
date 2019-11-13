#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)

typedef long long ll;
typedef pair <int, int> ii;

const int N = 410;
const int INF = 1e9;

int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    int t, a, b;
    cin >> t;
    while (t--){
        cin >> a >> b;
        if (gcd(a, b) == 1)
            cout << "Finite" << endl;
        else
            cout << "Infinite" << endl;

    }
}
