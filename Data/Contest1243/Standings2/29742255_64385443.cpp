#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k, n;
string a, b;
ll cnt[310];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>k;

	while(k--) {

		memset(cnt, 0, sizeof(cnt));
		cin>>n>>a>>b;

		for(ll i=0;i<n;i++) {
			cnt[a[i]]++;
			cnt[b[i]]++;
		}

		bool yes = 1;

		for(ll i='a';i<='z';i++) {
			if(cnt[i] % 2 > 0) {
				yes = 0;
				break;
			}
		}

		if(!yes) {
			cout<<"No"<<endl;
			continue;
		}

		cout<<"Yes"<<endl;

		vector< pair<ll, ll> > ans;

		for(ll i=0;i<n;i++) {

			if(a[i] == b[i]) continue;

			bool ontop = 0;
			for(ll j=i+1;j<n;j++) {
				if(a[j] == b[i]) {
					ontop = 1;
					ans.push_back({i, i});
					swap(a[i], b[i]);
					ans.push_back({j, i});
					swap(a[j], b[i]);
					break;
				}
			}

			if(ontop) continue;

			for(ll j=i+1;j<n;j++) {
				if(b[i] == b[j]) {
					ans.push_back({i, j});
					swap(a[i], b[j]);
					break;
				}
			}

		}

		cout<<ans.size()<<endl;
		for(auto i:ans) cout<<(i.first+1)<<" "<<(i.second+1)<<endl;

	}

}