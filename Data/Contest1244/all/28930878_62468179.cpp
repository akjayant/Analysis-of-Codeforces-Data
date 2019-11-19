#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define maxn 1005
#define line; printf("========");
#define endl '\n'
int main() {
	std::ios::sync_with_stdio(false);
	int n, m;
	int a, c, b, d, e;
	cin>>n;
	while(n--)		{
		cin>>a>>b>>c>>d>>e;
		int ans = a/c + ((a%c)!=0);
		int ans1 = b/d + ((b%d)!=0);
		if(ans1+ans > e) {
			cout<<"-1"<<endl;
		} else {
			cout<<ans<<" "<<ans1<<endl;
		}
	}


	return 0;
}