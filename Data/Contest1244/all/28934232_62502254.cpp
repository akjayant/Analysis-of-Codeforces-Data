#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define MAXN 100000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	ll K;
	int A[MAXN];
	cin>>N>>K;
	for(int i=0; i<N; ++i)
		cin>>A[i];
	sort(A,A+N);
	int mn = A[0];
	int mx = A[N-1];

	ll lft = 0, rgt = N-1;
	ll l = 0, r=0;
	ll z = 0;
	while(K>0)
	{
		if(mx==mn)
			break;
		for(; lft<N && A[lft]==mn; ++lft, ++l);
		for(; rgt>=0 && A[rgt]==mx; --rgt, ++r); 
		if(l<r)
		{
			ll new_mn = A[lft];
			ll z = (new_mn-mn)*l;
			if(K>=z)
			{
				K-=z;
				mn = new_mn;
			}
			else
			{
				mn+=K/l;
				K=0;
			}
			
		}
		else
		{
			ll new_mx = A[rgt];
			ll z = (mx-new_mx)*r;
			if(K>=z)
			{
				K-=z;
				mx = new_mx;
			}
			else
			{
				mx-=K/r;
				K=0;
			}
		}
		
	}
	cout<<mx-mn<<endl;
		
	return 0;
}
