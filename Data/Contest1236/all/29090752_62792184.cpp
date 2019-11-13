#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include<bits/stdc++.h>

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl;
#else
#define tr(a)
#endif

#define ll          long long int
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<long long int>
#define vii         vector<pair<int, int> >
#define viii         vector< vector<int> >
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define forr(i,a,b)	for(int i=a;i<b;i++)
using namespace std;


void func()
{
	int n;
	cin>>n;
	vector<int> v[n];
	int cur=1;
	int mat[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			mat[i][j]=cur;
			cur++;
		}
	}
	
	for(int i=0;i<n;i++)
	{	int k=0;
		if(i%2==0) k=0;
		else k=n-1;
		for(int j=0;j<n;j++)
		{
		
			if(i%2==0)
			{	
				v[k].pb(mat[i][j]);
				k++;
			}
			else
			{
					v[k].pb(mat[i][j]);
				k--;	
				
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
		func();
    }
    return 0;
}

