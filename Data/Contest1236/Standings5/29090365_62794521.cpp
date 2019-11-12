#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int lim = 3e2+5;
const int mod = 1e9+7;

int a[lim][lim],r=1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		int d = 1;
		if(i%2)
			d =-1;

		for(int j=(d==1?0:n-1);j<n && j>=0;j+=d)
			a[i][j] = r++;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cout<<a[j][i]<<" \n"[j==n-1];
    return 0;
}