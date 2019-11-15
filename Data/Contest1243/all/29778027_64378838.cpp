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
		h=0;
	cin >> n >> s >> q;
	if(s==q){
		cout << "Yes\n";
		continue;
	}
	i = 0;
	while(s[i]==q[i]) i++;
	c=s[i];
	for(j=i+1;j<n;j++){
		swap(s[i],q[j]);
		if(s==q){
			cout<< "Yes\n";
			h=1;
			break;
		}
		swap(s[i],q[j]);
	}
	if(h==0){
		cout<<"No\n";
	}
}
}