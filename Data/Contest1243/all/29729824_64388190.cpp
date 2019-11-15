#include<bits/stdc++.h>
#define ll long long
#define MAX_N 100
using namespace std;
int k,n;
char s[MAX_N],t[MAX_N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>k;
	while(k--)
	{
		vector<pair<int,int> >a;
		a.clear();
		int ch[26]={0};
		cin>>n>>s+1>>t+1;
		for(int i=1;i<=n;++i)
		{
			ch[s[i]-'a']++;
			ch[t[i]-'a']++;
		}
		bool flag=1;
		for(int i=0;i<26;++i)
			if(ch[i]&1)flag=0;
		if(flag==0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			if(s[i]==t[i])continue;
			bool flag=0;
			for(int j=i+1;j<=n;++j)
				if(s[j]==s[i])
				{
					a.push_back(make_pair(j,i));
					swap(s[j],t[i]);
					flag=1;
					break;
				}
			if(flag)continue;
			for(int j=i+1;j<=n;++j)
				if(t[j]==s[i])
				{
					a.push_back(make_pair(n,j));
					a.push_back(make_pair(n,i));
					swap(s[n],t[j]),swap(s[n],t[i]);
					// swap(t[i],t[j]);
					break;
				}
		}
		cout<<"YES"<<endl;
		cout<<a.size()<<endl;
		for(int i=0;i<a.size();++i)cout<<a[i].first<<" "<<a[i].second<<endl;
	}
	return 0;
}
