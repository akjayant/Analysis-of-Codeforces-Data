
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1000000 + 10;
#define INF 0x3f3f3f3f
#define clr(x,y) memset(x,y,sizeof x )
typedef long long ll;
#define eps 10e-10
const ll Mod = 1000000007;
typedef pair<ll, ll> P;



const int S = 20;//����㷨�ж�������SԽ���д����ԽС



ll Mult_mod(ll a, ll b, ll c)  //����ʵ�ֱ�ȡģ�ٶȿ�
{    //����(a*b) mod c,a,b,c<2^63
	a %= c;
	b %= c;
	ll ret = 0;
	while (b)
	{
		if (b & 1)
		{
			ret += a;
			if (ret >= c) ret -= c;
		}
		a <<= 1;
		if (a >= c) a -= c;
		b >>= 1;
	}
	return ret;
}
ll Pow_mod(ll x, ll n, ll mod) //x^n%c
{
	if (n == 1) return x % mod;
	x %= mod;
	ll tmp = x;
	ll ret = 1;
	while (n)
	{
		if (n & 1) ret = Mult_mod(ret, tmp, mod);
		tmp = Mult_mod(tmp, tmp, mod);
		n >>= 1;
	}
	return ret;
}

bool Check(ll a, ll n, ll x, ll t)
{
	ll ret = Pow_mod(a, x, n);
	ll last = ret;
	for (int i = 1; i <= t; i++)
	{
		ret = Mult_mod(ret, ret, n);
		if (ret == 1 && last != 1 && last != n - 1) return true; //����
		last = ret;
	}
	if (ret != 1) return true;
	return false;
}



bool Miller_Rabin(ll n)
{
	if (n < 2) return false;
	if (n == 2) return true;
	if ((n & 1) == 0) return false;//ż��
	ll x = n - 1;
	ll t = 0;
	while ((x & 1) == 0) { x >>= 1; t++; }
	for (int i = 0; i < S; i++)
	{
		ll a = rand() % (n - 1) + 1; //rand()��Ҫstdlib.hͷ�ļ�
		if (Check(a, n, x, t))
			return false;//����
	}
	return true;
}




ll factor[100];//�������ֽ������շ���ʱ������ģ�
int tol;//�������ĸ����������±��0��ʼ

ll Gcd(ll a, ll b)
{
	if (a == 0) return 1;  
	if (a < 0) return Gcd(-a, b);
	while (b)
	{
		ll t = a % b;
		a = b;
		b = t;
	}
	return a;
}

ll Pollard_rho(ll x, ll c)
{
	ll i = 1, k = 2;
	ll x0 = rand() % x;
	ll y = x0;
	while (true)
	{
		i++;
		x0 = (Mult_mod(x0, x0, x) + c) % x;
		ll d = Gcd(y - x0, x);
		if (d != 1 && d != x) return d;
		if (y == x0) return x;
		if (i == k) { y = x0; k += k; }
	}
}
void Findfac(ll n)
{
	if (Miller_Rabin(n)) //����
	{
		factor[tol++] = n;
		return;
	}
	ll p = n;
	while (p >= n) p = Pollard_rho(p, rand() % (n - 1) + 1);
	Findfac(p);
	Findfac(n / p);
}

int main()
{
	ll n;
	while (cin >> n)
	{
		if (n == 1) { cout << 1 << endl; continue; }
		if (Miller_Rabin(n))
		{
			cout << n << endl;
			continue;
		}
		tol = 0;
	
		Findfac(n);
		ll ans = factor[0];
		for (int i = 1; i < tol; i++)
			if (factor[i] < ans)
				ans = factor[i];
		ll zz = n;
		while (zz % ans == 0)
		{
			zz /= ans;
		}
		if (zz == 1)cout << ans << endl;
		else cout << 1 << endl;
	}
	return 0;
}
