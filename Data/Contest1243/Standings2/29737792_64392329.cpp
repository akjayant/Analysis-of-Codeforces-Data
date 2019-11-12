#include "bits/stdc++.h"
#define int long long
using namespace std;
int32_t main(){
	int q;cin>>q;
	while(q--)
	{
		int n;cin>>n;
		string s,t;cin>>s>>t;
		int fre[26]={0};
		for(int i=0;i<n;i++)
		{
			fre[s[i]-'a']++;
			fre[t[i]-'a']++;
		}
		int wrong=0;
		for(int i=0;i<26;i++)
			if(fre[i]%2==1)
				wrong=1;
		if(wrong)
		{
			cout<<"No\n";
		}
		else
		{
			vector<pair<int,int> > ans;
			for(int i=0;i<n;i++)
			{
				if(s[i]!=t[i])
				{
					for(int j=i+1;j<n;j++)
					{
						if(s[j]!=t[j])
						{
							if(t[i]==t[j])
							{
								ans.push_back(make_pair(i+1,j+1));
								swap(t[j],s[i]);
								break;
								
							}
							else if(t[i]==s[j])
							{
								ans.push_back(make_pair(j+1,j+1));
								ans.push_back(make_pair(i+1,j+1));
								swap(t[j],s[j]);
								swap(t[j],s[i]);
								break;
							}
						}

					}
				}
			}
			cout<<"Yes\n";
			cout<<ans.size()<<"\n";
			for(auto i:ans)
				cout<<i.first<<" "<<i.second<<"\n";
		}


	}
    
}