 #include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector<long long int> vl;
#define pb push_back
#define mp make_pair

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;

	vi v[n];

	int idx =0;
	int ad = 1;
	for(int i=1;i<=n*n;i++){
		v[idx].pb(i);
		idx+=ad;
		if(idx==n) idx--, ad = -1;
		if(idx==-1) idx++, ad = 1;
	}

	for(int i=0;i<n;i++){
		for(auto jt:v[i]) cout << jt << " ";
		cout << endl;
	}
	return 0;
}

