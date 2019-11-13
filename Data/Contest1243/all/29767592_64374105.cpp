#include <bits/stdc++.h>
using namespace std;

const int N=1e3+3;

int n;
int a[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tests;
	cin>>tests;
	while(tests--){
	    cin>>n;
	    for (int i=1; i<=n; ++i)
	        cin>>a[i];
	   sort(a+1,a+1+n,greater<int>());
	   int ans=0;
	   for (int i=1; i<=n; ++i)
	    if (a[i]>=i)
	        ans=i;
	    cout<<ans<<'\n';
	}
}
