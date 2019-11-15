#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pll pair <long long,long long>
#define f first
#define s second
#define ll long long
#define pss pair <string, string>
#define pls pair <long long , string >
#define psl pair <string , long long >
using namespace std;
int main () {
	ios;
	ll t;
	cin>>t;
	while (t--) {
		string st1,st2;
		ll n;
		cin>>n;
		cin>>st1>>st2;
		ll j=-1,jr=-1,w=0;
		for (ll k=0;k<n;k++) {
			if (st1[k]!=st2[k]&&j!=-1&&jr!=-1) {
				w=1;break;
			}
			if (st1[k]!=st2[k]&&j==-1) j=k;
			else if (st1[k]!=st2[k]&&jr==-1) jr=k;
		}
		if (w==1||jr==-1) cout<<"No"<<endl;
		else {
			if (st1[j]==st1[jr]&&st2[j]==st2[jr]) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}
