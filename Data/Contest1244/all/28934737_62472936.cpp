#include <bits/stdc++.h>
using namespace std;


int main() {
    long long t;
    cin >> t;
    while(t--)
    {
    	long long n;
    	cin >> n;
    	string s;
    	cin >> s;
    	long long p = -1, q  =-1;
    	for(long long i = 0; i < n; i++)
    	{
    		if(s[i]=='1')
    		q = i;
		}
		for(long long i = n-1; i >=0; i--)
		{
			if(s[i]=='1')
			p = i;
		}
		if(p==-1)
		cout << n << endl;
		else
		{
			long long m = 0;
			m = max(m, q+1 + max(n-q-1, q+1));
			m = max(m, (n-p) + max(p, n-p));
			long long r = max(p, n-q-1) + (q-p+1)*2; 
			m = max(m, r);
			cout << m << endl;
		}
	}
}
