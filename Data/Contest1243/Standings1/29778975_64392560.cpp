#include <bits/stdc++.h>

using namespace std;

long long n;
set <long long> s;

void primeFactors() {
    while (n % 2 == 0) {  
        s.insert (2);
        n = n/2;  
    }  
    for (long long i = 3; 1ll*i*i <= n; i = i + 2) {  
        while (n % i == 0) {  
            s.insert(i); 
            n = n/i;  
        }  
    }  
  
    if (n > 2)  
        s.insert(n);
}
int main () {
	cin >> n;
	if (n == 1) {puts("1"); return 0;}
	primeFactors();
	if (s.size() == 1) cout << *s.begin() << endl;
	else cout << 1 << endl;
} 