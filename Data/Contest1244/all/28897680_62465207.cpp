#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

void solve(){
	int a,b,c,d,k;
	cin>>a>>b>>c>>d>>k;
	int first=a+c-1;
	first=first/c;
	int second=b+d-1;
	second=second/d;
	int totat=first+second;
	if(totat>k){
		cout<<"-1"<<endl;
		return ;
	}
	else{
		cout<<first<<" "<<second<<endl;
		return;
	}
}
int32_t main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}

}