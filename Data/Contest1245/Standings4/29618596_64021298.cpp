#include <iostream>
#include <string>
#define base 1000000007
using namespace std;
string s;
long long f[100009];
int main(){
	getline(cin, s);
	int n = s.length();
	f[0] = 1;
	for (int i = 1; i <= n; i++){
		if (s[i - 1] == 'm' || s[i - 1] == 'w'){
			cout << 0 << endl;
			return 0;
		}
		f[i] = f[i - 1];
		if (i >= 2 && s[i - 1] == s[i - 2] && (s[i - 1] == 'n' || s[i - 1] == 'u')){
			f[i] = (f[i] + f[i - 2]) % base;
		}
	}
	cout << f[n];
	return 0;
}