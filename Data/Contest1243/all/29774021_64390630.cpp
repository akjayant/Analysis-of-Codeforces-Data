#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		int cnt[30] = {0};
		for(int i = 0; i < n; i++){
			cnt[a[i]-'a']++;
			cnt[b[i]-'a']++;
		}
		int flag = 0;
		for(int i = 0; i < 30; i++){
			if(cnt[i] % 2){
				cout << "No\n";
				flag = 1;
				break;
			}
		}
		if(flag)
			continue;
		cout << "Yes\n";
		vector<pii> v;
		string ans1 = a, ans2 = b;
		for(int i = 0; i < n; i++){
			if(ans1[i] == ans2[i]){
				continue;
			}
			else{
				int w = 0;
				for(int j = i+1; j < n; j++){
					if(ans1[j] == ans1[i]){
						swap(ans1[j],ans2[i]);
						v.PB({j,i});
						w = 1;
						break;
					}
				}
				if(!w){
					for(int j = i+1; j < n; j++){
						if(ans2[j] == ans1[i]){
							swap(ans2[j],ans1[n-1]);
							v.PB({n-1,j});
							swap(ans1[n-1],ans2[i]);
							v.PB({n-1,i});
							break;
						}
					}
				}
			}
		}
		cout << v.size() << endl;
		for(auto x : v){
			cout << x.F+1 << " " << x.S+1 << endl;
		}
	}

	return 0;
}

