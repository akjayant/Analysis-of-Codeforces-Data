#include <cstring>
#include <iostream>

#define ll long long

using namespace std;

const int mod = 1e9+7;

string a;

ll f[100011];

int num;

ll ans;

int main(){
	cin >> a;
	for(int i = 0; i < a.size(); i++) {
		if(a[i] == 'w' || a[i] == 'm') {
			cout << 0 << endl;
			return 0;
		}
	}
	f[0] = f[1] = 1;
	for(int i = 2; i <= 100000; i++) {
		f[i] = f[i-2] + f[i-1];
		f[i] %= mod;
	}
	ans = 1; num = 0;
	if(a[0] == 'u' || a[0] == 'n') num = 1;
	for(int i = 1; i < a.size(); i++) {
		if(a[i] == 'u' || a[i] == 'n') {
			if(a[i] == a[i-1]) num++;
			else {
				ans *= f[num];
				ans %= mod;
				num = 1;
			}
		}
		else {
			ans *= f[num];
			ans %= mod;
			num = 0;
		}
	}
	ans *= f[num]; ans %= mod;
	cout << ans << endl;
	return 0;
} 
/*
nnnn
1.nnnn
2.mnn
3.nmn
4.nnm
5.mm

nnnnn
1.nnnnn
2.mnnn
3.nmnn
4.nnmn
5.nnnm
6.mmn
7.mnm
8.nmm

2:2
3:3
4:5
5:8

nnnnnn

1.mmm
2.mmnn
3.mnmn
4.mnnm
5.nmmn
6.nmnm
7.nnmm
8.nnnnnn
9.mnnnn
10.nmnnn
11.nnmnn
12.nnnmn
13.nnnnm

*/