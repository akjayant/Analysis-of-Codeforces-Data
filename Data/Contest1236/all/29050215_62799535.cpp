#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 305;
int n;
vector<int> group[N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int ans = n*n;
	for(int i = n;i>=1;--i){
		if (i % 2 == 0){
			down(j,n,1) group[j].push_back(ans--);
		}
		else up(j,1,n) group[j].push_back(ans--);
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<group[i].size();++j) cout << group[i][j] << ' ';
		cout << '\n';
	}
}