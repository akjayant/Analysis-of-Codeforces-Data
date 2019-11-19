#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define maxn 1005
#define line; printf("========");
#define endl '\n'
int main() {
	std::ios::sync_with_stdio(false);
	int n, m;
	int a, c, b, d;
	cin>>n;
	char ss[maxn];
	while(n--)		{
		cin>>a;
		cin>>ss;
		int f=-1, e=-1;
		for(int i = 0; i < a; i++) {
			if(ss[i] == '1') {
				f = i;
				break;
			}
		}
		for(int i = a-1; i >= 0; i--) {
			if(ss[i] == '1') {
				e = i;
				break;
			}
		}
		if(f == -1) {
			cout<<a<<endl;
			continue;
		}
		int ans = min(f, a-e-1);
//		cout<<ans<<endl;
		ans = 2*a-2*ans;
		cout<<ans<<endl;
	}


	return 0;
}