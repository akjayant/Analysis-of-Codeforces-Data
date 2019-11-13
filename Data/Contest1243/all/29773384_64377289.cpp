#include <bits/stdc++.h>

using namespace std ;

int n ;
string s , t , s2 , t2; 

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int tc ;
	cin>>tc ;
	while(tc--)
	{
		cin>>n ;
		cin>>s ;
		cin>>t ;
		vector<int>v ;
		for(int i = 0 ; i < n ; ++i)
		{
			if(s[i] != t[i])
				v.push_back(i) ;
		}
		if(v.size() != 0 && v.size() != 2)
			cout<<"No\n" ;
		else if(v.size() == 0)
			cout<<"Yes\n" ;
		else
		{
			s2 = s ;
			t2 = t ;
			s2[v[0]] = t[v[1]] ;
			t2[v[1]] = s[v[0]] ;
			if(s2 == t2)
				cout<<"Yes\n" ;
			else
			{
				s2 = s ;
				t2 = t ;
				s2[v[1]] = t[v[0]] ;
				t2[v[0]] = s[v[1]] ;
				if(s2 == t2)
					cout<<"Yes\n" ;
				else
					cout<<"No\n" ;
			}
		}
	}
	return 0 ;
}