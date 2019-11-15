#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define int long long
using namespace std;
int n,pos=0,tmp;
int a[304][304];
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	tmp=1;
	for(int i=0;i<n;i++){
		if(!pos){
			for(pos=0;pos<n;pos++) a[pos][i]=tmp++;
			pos=n-1;
		} 
		else{
			for(pos=n-1;pos>-1;pos--) a[pos][i]=tmp++;
			pos=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
}