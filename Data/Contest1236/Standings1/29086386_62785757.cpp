#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define for0(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i <= (int)(n); i++)
#define int long long

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;



signed main(){
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int n, a, b, c;

    cin >> n;
    for(int i = 0; i < n; i++){
            int r = 0;
        cin >> a >> b >> c;

    int bc = min(b, c/2);
    r += bc*3;
     b -= bc;

    int ab = min(a, b/2);

    r += ab*3;
    cout << r << endl;
    }




}

