#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int a, b, c;
		cin>>a>>b>>c;
		int ans = 0;
		for(int i = 1; i <= 100; i++){
			if(b >= 1 and c >= 2){
				b--;
				c-=2;
				ans += 3;
			}
		}
		for(int i = 1; i <= 100; i++){
			if(a >= 1 and b >=2){
				b-=2;
				a--;
				ans+=3;
			}
		}
		cout<<ans<<'\n';
	}
}