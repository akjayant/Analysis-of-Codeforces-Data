#include<bits/stdc++.h>
using namespace std;
const int N =1e5+9;
const int inf = 1e9+7;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,a,b,c;
    cin>>t;
    while(t--){
    	cin>>a>>b>>c;
    	int ans = 0;
    	int x= min(b,c/2);
    	ans += 3*x;
    	b-=x;
    	x = min(a,b/2);
    	ans+= 3*x;
    	cout<<ans<<"\n";
	}
	return 0;
}