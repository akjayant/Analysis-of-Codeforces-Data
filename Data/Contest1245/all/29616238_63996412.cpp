#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){

    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if(__gcd(a,b) == 1) cout << "Finite" << endl;
        else cout << "Infinite" << endl;
    }

	return 0;
}