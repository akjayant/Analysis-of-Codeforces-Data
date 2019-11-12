#include <bits/stdc++.h>
#define u_mu unordered_multiset
#define u_s unordered_set
using namespace std;
long long d,z,mn = 1000000001,mx,sum,k,pos,l,x,y,r,n,m,ans,a1,a2,a3;
int b[200002];
bool ok;
main()
{
	cin >> l;
	while(l){
		--l;
		cin >> n;
		string s,c;
		cin >> s >> c;
		if(s == c){
			cout << "Yes\n1\n1 1\n";
			continue;
		}
		map<char,int>mp;
		ok = 0,k = 0;
		for(int i = 0;i < s.size();++i){
			if(s[i] != c[i]){
				mp[s[i]]++,mp[c[i]]++;
				if(s[i] != c[i]){
					if(mp[s[i]] % 2 == 0)
						--k;
					else
						++k;
					if(mp[c[i]] % 2 == 0)
						--k;
					else
						++k;
				}
			}
		}
		if(k != 0){
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		vector<pair<int,int> >v;
		for(int i = 0;i < n;++i){
			ok = 0;
			if(s[i] != c[i]){
				for(int j = i + 1;j < n;++j){
					if(s[j] == s[i]){
						v.push_back({ j , i });
						swap(s[j],c[i]);
						ok = 1;
						break;
					}
				}
				if(!ok){
					for(int j = i + 1;j < n;++j){
						if(c[j] == s[i]){
							v.push_back({ i + 1 , j });
							v.push_back({ i + 1 , i });
							swap(s[i + 1],c[j]);
							swap(s[i + 1],c[i]);
							break;
						}
					}
				}
			}
		}
		cout << v.size() << "\n";
		for(int i = 0;i < v.size();++i){
			cout << v[i].first + 1 << " " << v[i].second + 1 << "\n";
		}
	}
}