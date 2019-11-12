#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll mat[n][n];
    ll cnt=1;
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		if(i%2==0)
    		mat[j][i]=cnt;
    		else
    		mat[n-1-j][i]=cnt;
    		cnt++;
    	}
    }
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		cout << mat[i][j]<<" ";
    	}
    	cout <<"\n";
    }
    return 0;
}