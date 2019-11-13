#include <bits/stdc++.h>

using namespace std ;

int n ;
string s , t , s2 , t2; 

int freq[26] ; 

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int tc ;
	cin>>tc ;
	char c , c2 ;
	while(tc--)
	{
		memset(freq , 0,  sizeof(freq)) ;
		cin>>n ;
		cin>>s ;
		cin>>t ;
		for(int i = 0 ; i < n ; ++i)
		{
			freq[(s[i] - 'a')]++ ;
			freq[(t[i] - 'a')]++ ;
		}
		bool flag = false ;
		for(int i = 0 ; i < 26 ; ++i)
		{
			if(freq[i] & 1)
				flag = true ;
		}
		if(flag == true)
		{
			cout<<"No\n" ;
			continue ;
		}
		vector< pair<int , int> >vp ;
		for(int i = 0 ; i < n ; ++i)
		{
			if(s[i] != t[i])
			{
				flag = false ;
				for(int j = i+1 ; j < n ; ++j)
				{
					if(t[j] == s[i])
					{
						c = s[j] ;
						c2 = t[j] ;
						s[j] = c2 ;
						t[j] = c ;
						vp.push_back({j , j}) ;
						c = s[j] ;
						c2 = t[i] ;
						s[j] = c2 ;
						t[i] = c ;
						vp.push_back({j , i}) ;
						flag = true ;
						break ;
					}
				}
				if(flag == false)
				{
					for(int j = i+1 ; j < n ; ++j)
					{
						if(s[j] == s[i])
						{
							c = s[j] ;
							c2 = t[i] ;
							s[j] = c2 ;
							t[i] = c ;
							vp.push_back({j , i}) ;
							flag = true ;
							break ;
						}
					}	
				}
			}
		}
		if(s == t)
		{
			cout<<"Yes\n" ;
			cout<<vp.size()<<"\n" ;
			for(auto &i : vp)
				cout<<i.first+1<<" "<<i.second+1<<"\n" ;
		}
		else
			cout<<"No\n" ;
	}
	return 0 ;
}