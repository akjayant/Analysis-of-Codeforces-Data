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
int k,i,j;
cin>>k;
while (k--) {
	int n,a[30],b[30];
	vector <int> v1,v2;
	for(i=0;i<26;i++) {
		a[i]=0;
		b[i]=0;
	}
	string s,t;
	cin>>n;
	cin>>s>>t;
	for(i=0;i<n;i++) {
		a[s[i]-'a']++;
		b[t[i]-'a']++;
	}
	int f=1;
	for(i=0;i<26;i++) {
		if ((a[i]+b[i])%2==1) f=0;
	}
	if (f==0) {
		cout<<"NO"<<endl;
	} else {
		for(i=0;i<n;i++) {
			while (s[i]!=t[i]) {
                int g=0;
				for(j=i+1;j<n;j++) {
					if (s[i]==s[j]) {
						swap(s[j],t[i]);
						v1.pb(j);
						v2.pb(i);
						g++;
						break;
					}
				}
				if (g==0) {
					for(j=i+1;j<n;j++) {
						if (s[j]!=t[j]&&t[j]==s[i]) {
							swap(s[j],t[j]);
							v1.pb(j);
							v2.pb(j);
							break;
						}
					}
				}
			}
		}
		cout<<"YES"<<endl<<v1.size()<<endl;
		for(i=0;i<v1.size();i++) {
			cout<<v1[i]+1<<" "<<v2[i]+1<<endl;
		}
		v1.clear();
		v2.clear();
	}
}
return 0;
}