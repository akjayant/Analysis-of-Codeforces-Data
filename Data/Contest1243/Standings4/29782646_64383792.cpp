#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	int count=0;
	for(int t=0; t<T; t++)
	{
		int n;
		cin>>n;
		string s1, s2, check1, check2;
		cin>>s1>>s2;
		bool flag=true;
		for(int i=0; i<n; i++)
		{
			if(s1[i]!=s2[i])
			{
				check1.push_back(s1[i]);
				check2.push_back(s2[i]);
			}
		}

		if(check1.size()==0)
			cout<<"YES"<<endl;
		else if(check1.size()==2 && check1[0]==check1[1] && check2[0]==check2[1])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
	}
	return 0;
}