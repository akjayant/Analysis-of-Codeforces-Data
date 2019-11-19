#include <bits/stdc++.h>

using namespace std;
int n;
long long a[100005],bwh=0,ats=0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n/2;i++){
		bwh+=a[i];
	}
	for(int i=n/2+1;i<=n;i++){
		ats+=a[i];
	}
	cout<<bwh*bwh+ats*ats<<endl;
}


