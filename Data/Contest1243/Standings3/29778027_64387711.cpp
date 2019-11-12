#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pop pop_back
#define ll long long
#define fr first
#define sc second
#define inf 180000000;
#define FASTIOS ios_base::sync_with_stdio(false);  cin.tie(NULL);cout.tie(NULL);
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
#define sz(a) int((a).size())
ll n,m,i,j,k,t,ans;
ll arr[1500];

string s,q;
char c,d;
bool h;
int main(){
	FASTIOS
	cin >> t;
	while(t--){
		h = 1;
	cin >> n >> s >> q;
	if(s==q){
		cout << "Yes\n" << 1 <<'\n'<<1<<' '<<1 <<'\n';
		continue;
	}
	for(i=95;i<=123;i++) arr[i]=0;
	for( i = 0;i<n;i++){
		arr[(int)s[i]]++;
		arr[(int)q[i]]++;
	}
	for(i=96;i<=123;i++)
		if(arr[i]%2==1){
			cout<<"No\n";
			h=0;
			break;
		}
		if(h==0) continue;
		cout<<"Yes\n";
		i=0;
		cout << 2*n << '\n';
		for(i=0;i<n;i++)
		{
//	while(s[i]==q[i]) i++;
if(s[i]==q[i]) {
cout << i+1<<' '<<i+1<<'\n'<<i+1<<' '<<i+1<<'\n';
continue;
}
	for(j=i+1;j<n;j++){
		if(s[i]==q[j])
		{
			cout << i+2 <<' '<<j+1<<'\n'<<i+2<<' '<<i+1<<'\n';
			swap(s[i+1],q[j]);
			swap(s[i+1],q[i]);
			break;
		}
		if(s[i]==s[j]){
			cout << j+1 <<' '<<i+1 <<'\n'<<i+1<<' '<<i+1<<'\n';
			swap(s[j],q[i]);
			break;
		}
	}
      }
}
}