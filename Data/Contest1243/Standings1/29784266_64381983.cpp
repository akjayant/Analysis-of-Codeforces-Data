#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pi 3.1415926535897932
#define INF INT_MAX
#define MOD 1000000007

int main() {

	int t;
	cin>>t;
	while(t--)
	{
		int n,i,j,ans=0,c=0,x=-1,y;
		cin>>n;
		string s,t;
		cin>>s;
		cin>>t;
		for(i=0;i<n;++i)if(s[i]!=t[i]){c++;if(x==-1)x=i;else y=i;}
		if(c==2&&s[x]==s[y]&&t[x]==t[y])cout<<"YES\n";else cout<<"NO\n";
	}

	return 0;
}