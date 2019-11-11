#include <bits/stdc++.h>
#define MAXN 1000100
#define pii pair<int, int>
#define pb push_back
#define inf 1e18
#define fi first
#define se second
#define mt make_tuple
typedef long long ll;

using namespace std;

int n;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
    	int a, b;
    	cin >> a >> b;
    	if(__gcd(a, b) == 1) cout << "Finite" << endl;
    	else cout << "Infinite" << endl;
    }
}