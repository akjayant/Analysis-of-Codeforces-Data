
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long int fibo(int x) {
	long long int a = 1, b = 1, c;
	for (int i = 0; i < x; i++) {
		c = (a + b) % MOD;
		a = b;
		b = c;
	}
	return a;
}

int main(){
    string s;
    cin >> s;
    long long int ans = 1;
    char curr = 0;
    long long int num_reps = 0;
    for(int i = 0; i <= s.size(); i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            ans = 0;
            break;
        } else if (curr == s[i]) {
            num_reps++;
        } else if (curr == 'u' || curr == 'n') {
            ans = (ans * fibo(num_reps)) % MOD;
            num_reps = 1;
            curr = s[i];
        } else {
            num_reps = 1;
            curr = s[i];
        }
    }
    cout << ans << endl;
}