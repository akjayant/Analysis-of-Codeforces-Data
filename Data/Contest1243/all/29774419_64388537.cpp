#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

template <typename T> inline int Chkmax (T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline int Chkmin (T &a, T b) { return a > b ? a = b, 1 : 0; }

template <typename T> inline T read(){
    T sum = 0;
    int fl = 1,ch = getchar();
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') fl = -1;
    for(; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + ch - '0';
    return sum * fl;
}

int n,cnt,N;
vector <int> a;

inline void Solve (){
	N = n;
	for(int i = 2; i <= sqrt(n); i++){
		if(!(n % i)){
			cnt++;
			a.pb(i);
		}
		while(!(n % i)) n /= i;
	}
	if(n != 1 && N != n) cnt++;
	if(!cnt){
		printf("%lld\n",n);
		return;
	}
	if(cnt != 1){
		puts("1");
		return;
	}else{
		printf("%lld\n",a[0]);
	}
}

inline void Input (){
	n = read<int>();
}

signed main(){
	Input();
	Solve();
	return 0;
}
