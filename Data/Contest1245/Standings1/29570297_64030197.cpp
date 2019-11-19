/* LittleFall : Hello! */
#include <bits/stdc++.h>
using namespace std; using ll = long long; inline int read();
const int M = 500016, MOD = 1000000007;

int bit_count(int n)
{
	int res = 0;
	while(n)
	{
		++res;
		n>>=1;
	}
	return res;
}
string trans(pair<ll,ll> pll)
{
	ll x1 = pll.first, x2 = pll.second-1;
	//printf("%I64d %I64d : ",x1,x2+1 );
	string res1, res2; //'0'代表恒为0，'1'代表恒为1，'2'代表均可
	while(x1)
	{
		res1.push_back((x1&1)+'0');
		x1>>=1;
	}
	while(x2)
	{
		res2.push_back((x2&1)+'0');
		x2>>=1;
	}
	for(int i=0; i<(int)res1.size(); ++i)
		if(res1[i]!=res2[i]) res1[i] = '2';
	//cout << res1 << endl;
	return res1;
}
ll solve(string p1, string p2) //解决区间
{
	//cout << p1 << " " << p2 << endl;
	if(p1.size()==p2.size()) return 0;
	if(p1.size()>p2.size()) swap(p1, p2);
	while(p1.size()<p2.size()) p1.push_back('0');

	ll ans = 1;
	for(int i=0; i<(int)p1.size(); ++i)
	{
		char c1 = p1[i], c2 = p2[i];
		if(c1>c2) swap(c1, c2);
		if(c1=='0' && c2=='2')
			ans *= 2;
		if(c1=='1' && c2=='1')
			ans *= 0;
		if(c1=='2' && c2=='2')
			ans *= 3;
	}
	// if(p1==p2) return 0;
	// printf("%I64d %I64d %I64d %I64d\n",p1.first, p1.second,p2.first,p2.second );
	return ans;
}
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
    #endif

	int t = read();
	while(t--)
	{
		ll l = read(), r = read();
		if(r==0)
		{
			printf("1\n");
			continue;
		}
		if(bit_count(l)==bit_count(r))
		{
			printf("0\n");
			continue;
		}

		ll ans = 0;
		if(l==0) 
		{
			ans += r*2+1;
			l = 1;
		}
		set<pair<ll,ll>> segs; 
		for(ll i=l;; )
		{
			ll ni = i+(i&-i);
			segs.insert({i,ni});
			if(bit_count(ni)==bit_count(r)) break;
			i = ni;
		}
		for(ll i=r;; )
		{
			ll ni = i-(i&-i);
			if(bit_count(ni)!=bit_count(r)) break;
			segs.insert({ni,i});
			i = ni;
		}
		segs.insert({r,r+1});
		// printf("segs:\n");
		// for(auto p:segs)
		// {
		// 	printf("%I64d %I64d\n",p.first,p.second );
		// }
		for(auto p1:segs)
			for(auto p2:segs)
				ans += solve(trans(p1), trans(p2));

		cout << ans << endl;
	}

    return 0;
}


inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}