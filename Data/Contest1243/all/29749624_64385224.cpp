using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define bb back()
#define ff front()
const ll inf=1e18;
const ll mod=998244353;
void boost(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
}
int main(){
boost();
int k;
cin>>k;
while (k--) {
	int n,j,i;
	char x,y;
	cin>>n;
	string s,t;
	cin>>s>>t;
	int f=0,z=0;
	for(i=0;i<n;i++) {
		if (s[i]!=t[i]) f++;
	}
	if (f!=2) {
		if (f==0) cout<<"YES"; else cout<<"NO";
	} else {
		for(i=0;i<n;i++) {
			if (s[i]!=t[i]) {
				x=s[i];
				y=t[i];
				break;
			}
		}
		for(i=n-1;i>=0;i--) {
			if (s[i]!=t[i]) {
				if (s[i]==x&&t[i]==y) {
					z=1;
				}
				break;
			}
		}
		if (z) cout<<"YES"; else cout<<"NO";
	}
	cout<<endl;
}
return 0;
}