#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
	if(a*b==0)
	return (a+b);
	if(a%b==0)
	return b;
	return gcd(b, a%b);
}
int main() {
    long long n, p, w, d;
    cin >> n >> p >> w >> d;
    if(n*w < p || w<=d || (p>0 && p<d))
    cout << -1 << endl;
    else
    {
    	long long x, y, z;
    	x = gcd(w, d);
    	if(p%x!=0)
    	cout <<-1<<endl;
		else
		{
			x = p/w;
			y = p-(x*w);
			map<int, int> mp;
			while(y%d!=0)
			{
				if(mp.find(y%d)!=mp.end())
				break;
				mp[y%d]=1;
				y+=w;
				x--;
			}
			if(y%d==0 && x+y/d <= n)
			cout << x <<" "<<y/d<<" "<<n-x-y/d<<endl;
			else
			cout << -1<<endl;
		} 
	}
}
