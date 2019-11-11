#include <iostream>
#include <string>
#define base 1000000007
using namespace std;
string s;
long long f[100009];
int main(){
	getline(cin, s);
	f[0] = 1;
	if (s[0]=='m' || s[0] == 'w'){
	    cout<<0<<endl;
	    return 0;
	}
	for (int i = 1; i < s.length(); i++){
		if (s[i] == 'm'){
			cout << 0 << endl;
			return 0;
		}
		if (s[i] == 'w'){
			cout << 0 << endl;
			return 0;
		}
		f[i] = f[i - 1];
		if (s[i] == 'u'){
			if (s[i - 1] == 'u'){
				if (i - 2 >= 0){
					f[i] = f[i - 2];
				}
				f[i] = (f[i] + f[i - 1]) % base;
			}
			continue;
		}
		if (s[i] == 'n'){
			if (s[i - 1] == 'n'){
				if (i - 2 >= 0){
					f[i] = f[i - 2];
				}
				f[i] = (f[i] + f[i - 1]) % base;
			}
			continue;
		}
	}
	cout << f[s.length() - 1] << endl;
}