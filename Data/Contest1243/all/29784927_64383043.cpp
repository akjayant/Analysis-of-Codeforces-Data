#include <bits/stdc++.h>
#define u_mu unordered_multiset
#define u_s unordered_set
using namespace std;
long long d,z,mn = 1000000001,mx,sum,k,pos,l,x,y,r,n,m,ans,a1,a2,a3;
int b[200002];
main()
{
	cin >> l;
	while(l){
		--l;
		cin >> n;
		k = 0,m = 0,n = 0;
		string s,c;
		cin >> s >> c;
		for(int i = 0;i < s.size();++i){
			if(s[i] != c[i]){
				if(k == 0)
					n = i;
				else if(k == 1)
					m = i;
				++k;
			}
		}
		if(k != 2){
			cout << "No\n";
			continue;
		}
		//cout << s[n] << " " << s[m] << " " << c[n] << " " << c[m];
		if(s[n] == s[m] && c[n] == c[m]){
			cout << "Yes\n";
		}
		else
			cout << "No\n";
	}
}