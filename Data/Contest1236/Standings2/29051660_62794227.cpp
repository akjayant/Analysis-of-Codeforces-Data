#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;

#define fastIO \
ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
#define MOD 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair 

int main(){
	int n;
	cin >> n;
	vi a[n];
	int j = 0, flag = 1;
	for(int i=1;i<=n*n;i++){
		a[j].pb(i);
		if(i%n != 0 && flag == 1)	j = (j+1)%n;
		if(i%n != 0 && flag == 0)	j = (j+n-1)%n;
		if(i%n == 0)	flag = 1-flag;
	}	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)	cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}