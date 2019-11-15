#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(a) a.begin(), a.end()
#define dbg(x) cerr << #x"=" << x << endl;
#define fout cout<<fixed<<setprecision(10)
typedef long long int ll;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) 
{ 
    	return (a.first - a.second) > (b.first - b.second);
} 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;cin>>n;
	int mat[n+1][n+1];
	int cur1 = 1;
	int cur2 = n*n;
	for(int col =0 ; col < n ; col++)
	{
		for (int row = 0; row < n; ++row)
		{
			if(col%2==0) mat[row][col] = cur1++;
			else mat[row][col] = cur2--;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<mat[i][j]<<" ";
		}cout<<endl;
	}
	// cout<<"TESTING"<<endl;
	// for(int i =0 ; i < n ; i++)
	// {
	// 	for(int j =i+1 ; j < n ; j++)
	// 	{
	// 		int  fi= 0;
	// 		for(int f =0 ; f < n ;f++)
	// 		{
	// 			for(int s = 0 ; s < n ; s++)
	// 			{
	// 				if(mat[i][f] < mat[j][s]) fi++;	
	// 			}
	// 		}
	// 		cout<<fi<<endl;
	// 	}
	// }
	return 0;
}