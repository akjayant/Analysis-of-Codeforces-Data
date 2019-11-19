#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	int x;
	while(t--){
		ll a=0,b=0;
		ll m,n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(x&1)a++;
		}
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>x;
			if(x&1)b++;
		}
		n-=a;m-=b;
		cout<<(a*b+n*m)<<endl;
	}
}
//-3 -15 0 1 12 -15 19
//