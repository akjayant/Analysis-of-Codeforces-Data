#include<bits/stdc++.h>
using namespace std;

int find_index(string s, char c, int pos)
{
	int t=-1;
	for(int i=pos+1; i<s.size(); i++)
		if(s[i]==c)
			return i;
	return t;	
}

bool check(string s1, string s2)
{
	int a[26]={0};
	for(int i=0; i<s1.size(); i++)
	{
		a[s1[i]-'a']++;
		a[s2[i]-'a']++;
	}
	for(int i=0; i<26; i++)
		if(a[i]%2)
			return false;

	return	true;
}


int main()
{
	int T;
	cin>>T;
	for(int t=0; t<T; t++)
	{
		int n;
		cin>>n;
		string s1, s2;
		cin>>s1>>s2;
		if(check(s1,s2)==false)
		{
			cout<<"NO"<<endl;
			continue;
		}

		vector<pair<int,int>> v;
		for(int i=0; i<n; i++)
		{
			if(s1[i]==s2[i])
				continue;
			int pos1=find_index(s1, s1[i], i), pos2=find_index(s2, s1[i], i);
			if(pos1!=-1)
			{
				v.push_back({pos1+1, i+1});
				swap(s2[i], s1[pos1]);
			}
			else
			{
				v.push_back({pos2+1, pos2+1});
				swap(s1[pos2], s2[pos2]);
				v.push_back({pos2+1, i+1});
				swap(s2[i], s1[pos2]);
			}
		}
		cout<<"YES"<<endl;
		// if(v.size()!=0)
			cout<<v.size()<<endl;
		for(int i=0; i<v.size(); i++)
			cout<<v[i].first<<" "<<v[i].second<<endl;

	}
	return 0;
}