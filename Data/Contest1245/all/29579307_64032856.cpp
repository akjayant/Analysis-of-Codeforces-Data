#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXBIT = 31;

string L, R;

int f[MAXBIT+2][2][2][2][2];

void refine(int s, string& S){
	S.clear();
	for(int i=0; i< MAXBIT; ++i){
		S.push_back(((s>>i)&1)+'0');
	}
	reverse(S.begin(), S.end());
}

int dp(int i, bool okla, bool okra, bool oklb, bool okrb){
	int& ret = f[i][okla][okra][oklb][okrb];
	if(ret != -1) return ret;
	if(i== MAXBIT) return ret = 1;
	ret = 0;
	int lowA = (okla ? 0 : L[i]-'0'), upA = (okra ? 1 : R[i]-'0');
	int lowB = (oklb ? 0 : L[i]-'0'), upB = (okrb ? 1 : R[i]-'0');
	for(int a = lowA; a <= upA; ++a)
		for(int b = lowB; b <= upB; ++b)
			if(a ==1 && b==1) continue;
			else ret += dp(i+1, okla||(a > L[i]-'0'), okra || (a < R[i]-'0'), oklb||(b > L[i]-'0'), okrb || (b < R[i]-'0'));
	return ret;
}


signed main(){
	int T; cin >> T;
	while(T--){
		int l, r; cin >> l >> r;
		refine(l, L); refine(r,R);
		memset(f, -1, sizeof f);
		cout << dp(0, 0, 0, 0, 0) << "\n";
	}
}
