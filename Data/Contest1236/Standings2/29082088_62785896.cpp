#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
//#define int long long
using namespace std;
int n,a,b,c,sum;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		sum=0;
		sum+=min(b,c/2)*3;
		b-=min(b,c/2);
		sum+=min(a,b/2)*3;
		cout<<sum<<endl;
	}
}