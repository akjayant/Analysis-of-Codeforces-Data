#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k, n;
string a, b;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>k;

	while(k--) {

		cin>>n>>a>>b;

		vector<char> diff;

		for(ll i=0;i<n;i++) {
			if(a[i] != b[i]) {
				diff.push_back(a[i]);
				diff.push_back(b[i]);
			}
		}

		if(diff.size() != 4) cout<<"No"<<endl;
		else {
			if(diff[0] == diff[2] && diff[1] == diff[3]) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}

	}

}