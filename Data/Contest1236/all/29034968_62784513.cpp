#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf=1e18+69;
const ll mod=1e9+7;
const ld pi=acos(-1);
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(v) v.begin(), v.end()
#define ed return 0
#define hi eihufahuodhiepwkajkf
int t, a, b, c;
int main(){
	fio;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		int t1=min(b, c/2)*3;
		b-=t1/3;
		int t2=min(a, b/2)*3;
		cout<<t1+t2<<endl;
	}
	ed;
}