#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define MAXN 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		string S;
		cin>>N;
		cin>>S;
		int a = N;
		int b = -1;
		for(int i=0; i<N; ++i)
		{
			if(S[i]=='1')
			{
				a = min(a,i);
				b = max(b,i);
			}
		}
		int ans;
		if(b==-1)
			ans = N;
		else
		{
			//cerr<<a<<" "<<b<<endl;
			ans = 2*max(N-a,b+1);
		}
		cout<<ans<<endl;
		
	}
		
	return 0;
}
