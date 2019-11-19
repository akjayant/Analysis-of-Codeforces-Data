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
ll n,a,i,j;
vector <ll> v;
i=2;
cin>>n;
a=n;
if (n==1) {
	cout<<1;
	return 0;
}
while (i<=sqrt(n)) {
	if (n%i==0) {
		v.pb(i);
		n/=i;
	} else i++;
}
if (n>1) v.pb(n);
n=1;
if (v.size()==1) {
	cout<<a;
	return 0;
} 
int q=v[0],f=0;
for(i=1;i<v.size();i++) {
	if (v[i]!=q) {
		f++;
		break;
	}
}
if (f==0) {
	cout<<q;
	return 0;
}
cout<<1;
return 0;
}