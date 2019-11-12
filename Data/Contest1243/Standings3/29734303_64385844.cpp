#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define INF 1000000000ll
#define MAX 100005

void init(){
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int k;
	cin >> k;
	while(k--){
		int n;
		cin >> n;
		string s, t;
		cin >> s;
		cin >> t;
		vector<char> v1, v2;
		for(int i = 0; i<n; i++){
			if(s[i] != t[i]){
				v1.pb(s[i]);
				v2.pb(t[i]);
			}
		}
		if(v1.size() == 0){
			cout << "Yes" << endl;
		}
		else if(v1.size() == 2){
			if((v1[0]==v1[1]) and (v2[0]==v2[1])){
				cout << "Yes" << endl;
			}
			else cout << "No" << endl;
		}
		else cout << "No" << endl;
	}
	//fclose(stdout);
	return 0;
}