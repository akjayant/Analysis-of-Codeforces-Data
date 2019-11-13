#include "bits/stdc++.h"
#define int long long
using namespace std;
int32_t main(){
	int q;cin>>q;
	while(q--)
	{
		int n;cin>>n;
		string s,t;cin>>s>>t;
		int c=0,id;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				if(c==1)
				{
					swap(s[i],t[id]);
					break;

				}
				else
				{
					id=i;
				}
				c++;
			}

		}
		if(s==t)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
    
}