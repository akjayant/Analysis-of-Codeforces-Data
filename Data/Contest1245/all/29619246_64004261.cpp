#include <string>
#include <iostream>
const int mod = 1E9 + 7;
inline int mul(int a,int b) { return static_cast <long long>(a) * b % mod; }
const int n = 1E5;
int fac[n + 1],Ifac[n + 1];
int C(int n,int m) { return mul(fac[n],mul(Ifac[m],Ifac[n - m])); }
int calc(int n)
{
	int res = 0;
	for (int i = 0;i <= n >> 1;++ i)
		res += C(n - i,i) - mod,res += res >> 31 & mod;
	return res;
}
main()
{
	* fac = 1; for (int i = 1;i <= n;++ i) fac[i] = mul(fac[i - 1],i);
	int R = 1;
	for (int B = fac[n],E = mod - 2;E;E >>= 1,B = mul(B,B))
		if (E & 1) R = mul(R,B);
	Ifac[n] = R; for (int i = n;i;-- i) Ifac[i - 1] = mul(Ifac[i],i);
	std::string s; std::cin >> s;
	if (s.find('w') != s.npos || s.find('m') != s.npos) return std::cout << "0\n",0;
	char ch = s[0]; int cnt = 1;
	int ans = 1;
	for (int i = 1;i < s.size();++ i)
	{
		if (s[i] != s[i - 1])
		{
			if (ch == 'u' || ch == 'n') ans = mul(ans,calc(cnt));
			ch = s[i],cnt = 0;
		}
		++ cnt;
	}
	if (ch == 'u' || ch == 'n') ans = mul(ans,calc(cnt));
	std::cout << ans << '\n';
}