#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define MAXN 100000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	ll cost[3][MAXN];
	cin>>N;
	for(int c=0; c<3; ++c)
		for(int i=0; i<N; ++i)
			cin>>cost[c][i];
	vector<int> E[MAXN];
	for(int i=0; i<N-1; ++i)
	{
		int u,v;
		cin>>u>>v;
		E[--u].push_back(--v);
		E[v].push_back(u);
	}
	int im = 0;
	for(int i=0; i<N; ++i)
		if(E[i].size()>2)
			im = 1;
	if(im)
		cout<<-1<<endl;
	else
	{
		set<int> G[3];
		int curr;
		for(int i=0; i<N; ++i)
			if(E[i].size()==1)
			{
				curr = i;
				break;
			}
		int prev = -1;
		int g = 0;
		while(curr!=-1)
		{
			G[g++].insert(curr);
			g%=3;
			int nxt = -1;
			for(auto a: E[curr])
				if(a!=prev)
					nxt = a;
			prev = curr;
			curr = nxt;
		}
		ll A[3][3];
		for(int i=0; i<3; ++i)
		{
			A[i][0]=A[i][1]=A[i][2]=0;
			for(auto a: G[i])
			{
				for(int j=0; j<3; ++j)
					A[i][j] += cost[j][a];
			}
		}
		ll best = MAXN * (ll)1e9 + 1;
		ll I[3];
		for(int i=0; i<3; ++i)
			for(int j=0; j<3; ++j)
				for(int k=0; k<3; ++k)
				{
					if(i!=j && i!=k && j!=k)
					{
						ll z = A[0][i] + A[1][j] + A[2][k];
						//cerr<<z<<endl;
						if(z<best)
						{
							I[0]=i;
							I[1]=j;
							I[2]=k;
							best = z;
						}
					}
				}
				/*
		for(int i=0; i<3; ++i,cerr<<endl)
			for(int j=0; j<3; ++j)
				cerr<<A[i][j]<<" ";*/
		int D[MAXN];
		for(int i=0; i<3; ++i)//,cerr<<endl)
			for(auto a: G[i])
			{
				//cerr<<a<<" ";
				D[a] = I[i]+1;
			}
		cout<<best<<endl;
		cout<<D[0];
		for(int i=1; i<N; ++i)
			cout<<" "<<D[i];
		cout<<endl;

	}
	
	return 0;
}
