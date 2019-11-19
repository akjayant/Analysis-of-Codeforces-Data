#include <bits/stdc++.h>
 
using namespace std;
const int N=1e6+55;
bool vis[N]; 
vector < long long > prime;

void sv()
{
	for(int i=2;i<N;i++)
	{
		if(vis[i])
		continue ;
		prime.push_back(i);
		for(int j=i;j<N;j+=i)
		vis[j]=1;
	}
}
 
int main()
{
	sv();
	long long n;
	cin>>n;
	long long ans=n;
	vector <long long> v;
	for(auto i:prime)
	{
		if(i*i>ans)
			break;
		bool q = 0;
		while(ans%i==0)
		{
			ans/=i;
			q = 1;
		}
		if(q)
			v.push_back(i);
	}
	
	if( v.empty() )
	{
		cout<<n<<endl;
		return 0;
	}
	
	if( ans > 1 )
		v.push_back(ans);
	
	if( (int)(v.size()) == 1 )
	{
		cout<<v[0];
		return 0;
	}
	
	cout<<1<<endl;
}
