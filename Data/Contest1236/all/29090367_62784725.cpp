#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        int sum = 0;
        int p = min(b, c/2);
        b -= p;
        c -= 2*p;
        sum += p*3;
        p = min(a, b/2);
        sum += p*3;
        cout << sum << endl;
    }
	return 0;
}