#include <bits/stdc++.h>
using namespace std;
const int N =1e5+9;
const int mod = 1e9+7;
typedef long long ll;


int main() {  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,a,b;
    cin>>t;
    while(t--){
    	cin>>a>>b;
    	int gc = __gcd(a,b);
    	if(gc!=1) cout<<"Infinite";
    	else cout<<"Finite";
    	cout<<"\n";
	}
}