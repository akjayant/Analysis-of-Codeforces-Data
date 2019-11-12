/*suri_kumkaran*/

#include <bits/stdc++.h>

using namespace std;

#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define MP make_pair
#define EB emplace_back
#define endl "\n"
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int int64;
typedef vector<int64> VI64;
typedef vector<pair<int64,int64>> VII64;
typedef vector<string> VS;
typedef vector<vector<int64>> VVI;

int main()
{
	IOS;
	int64 T=1;
	cin>>T;
	while(T--)
	{
		int64 n,i;
		cin>>n;
		string s1,s2;
		cin>>s1>>s2;
		int64 cnt=0;
		VI64 v;
		for(i=0;i<n;i++)
		{
			if(s1[i]!=s2[i])
			{
				v.EB(i);
				cnt++;
			}
		}
		if(cnt==0)
			cout<<"Yes"<<endl;
		else if(cnt==2)
		{
			int64 idx1,idx2;
			bool b=false;
			idx1=v[0];
			idx2=v[1];
			swap(s1[idx1],s2[idx2]);
			if(s1==s2)
				b=true;
			swap(s1[idx1],s2[idx2]);
			swap(s1[idx2],s2[idx1]);
			if(s1==s2)
				b=true;
			if(b)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;

		}
		else
			cout<<"No"<<endl;


	}

	return 0;
}