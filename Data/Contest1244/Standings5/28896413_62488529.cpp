#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define int long long int
using namespace std;

// Kyu? Chonk gaye!? 😮

void desperate_optimization(bool submitting=true,int precision=10)
{
  if(!submitting) return;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(precision);
}
int n;

int c[3][100005];
int p[100005];
vector<int> adjList[100005];
string plan;
int cost(int start,int parent,int index)
{
	int answer=c[plan[index]-'1'][start];
	p[start]=plan[index]-'1';
	for(auto itr:adjList[start])
		if(itr!=parent)
			answer+=cost(itr,start,(index+1)%3);
	return answer;
}
int32_t main()
{
  	desperate_optimization(true);
  	cin>>n;
  	for(int i=0;i<3;i++)
  		for(int j=1;j<=n;j++)
  			cin>>c[i][j];
  	for(int i=1;i<n;i++)
  	{
  		int u,v;
  		cin>>u>>v;
  		adjList[u].push_back(v);
  		adjList[v].push_back(u);
  	}
  	int startingpoint;
  	for(int i=1;i<=n;i++)
  	{
  		if(adjList[i].size()>2)
  		{
  			cout<<"-1";
  			return 0;
  		}
  		else if(adjList[i].size()==1) startingpoint=i;
  	}
  	int temppaint[n+5];
  	int answer=-1,z;
  	plan="123";
  	for(int _s=0;_s<3;_s++)
  	{
  		z=cost(startingpoint,-1,_s);
	  	if(answer>z||answer==-1)
	  	{
	  		answer=z;
	  		for(int i=1;i<=n;i++) temppaint[i]=p[i];
	  	}
  	}
  	plan="321";
  	for(int _s=0;_s<3;_s++)
  	{
  		z=cost(startingpoint,-1,_s);
	  	if(answer>z||answer==-1)
	  	{
	  		answer=z;
	  		for(int i=1;i<=n;i++) temppaint[i]=p[i];
	  	}
  	}
  	cout<<answer<<'\n';
  	for(int i=1;i<=n;i++) cout<<temppaint[i]+1<<' ';
  	
  	


  	return 0;
}