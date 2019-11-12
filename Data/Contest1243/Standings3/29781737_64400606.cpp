#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll t,n;
string s1,s2;
vector<int>pos;
int num1[30],num2[30];
map<int,char>mp1,mp2;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>s1>>s2;
		memset(num1,0,sizeof num1);
		memset(num2,0,sizeof num2);
		for(int i=0;i<n;i++)
		num1[s1[i]-'a']++;
		for(int i=0;i<n;i++)
		num2[s2[i]-'a']++;
		int flag=0;
		for(int i=0;i<26;i++)
		{
			if((num1[i]+num2[i])%2!=0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			cout<<"No\n";
			continue;
		}
		vector<int>ans;
		ans.clear();
		for(int i=0;i<n;i++)
		{
			if(s1[i]==s2[i])
			continue;
			int pos=-1;
			for(int j=i+1;j<n;j++)
			{
				if(s1[j]==s1[i])
				{
					pos=j;
					break;
				}
			}
			if(pos==-1)
			{
				for(int j=i+1;j<n;j++)
				{
					if(s2[j]==s1[i])
					{
						pos=j;
						break;
					}
				}
				ans.push_back(pos+1);
				ans.push_back(pos+1);
				swap(s1[pos],s2[pos]);
			}
			ans.push_back(pos+1);
			ans.push_back(i+1);
			swap(s1[pos],s2[i]);
//			cout<<s1<<"\n"<<s2<<"\n";
		}
		cout<<"Yes\n";
		cout<<(int)ans.size()/2<<endl;
		for(int i=0;i<ans.size();i+=2)
		cout<<ans[i]<<" "<<ans[i+1]<<endl;
	}
}