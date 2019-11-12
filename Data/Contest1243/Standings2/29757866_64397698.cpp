#include<bits/stdc++.h>
using namespace std;
const int N=101000;
const int K=20;
double EPS=1e-7;
typedef long long ll;

string s,t;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 	int q,n;
 	cin>>q;
 	while(q--)
 	{
 		cin>>n;
 		cin>>s>>t;
 		vector<int> rs;
 		for (int i = 0; i <s.size() ; ++i)
 		{
 			if(s[i]!=t[i])
 			{
 				rs.push_back(i);
 			}
 		}
 		if(rs.size()==2 && s[rs[0]]==s[rs[1]] && t[rs[0]]==t[rs[1]])
 			cout<<"YES\n";
 		else
 			cout<<"NO\n";
 	}
    return 0;
}