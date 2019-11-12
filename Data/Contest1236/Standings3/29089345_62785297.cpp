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
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		cin >> a >> b >> c;
		int ans = 0;
		if(c/2>b) ans += b*3, b=0, c-=c/2*2;
		else if(c/2<=b) ans+=c/2*3, b-=c/2, c-=c/2*2;

		if(b/2>a) ans += a*3, a=0, b-=b/2*2;
		else if(b/2<=a) ans+=b/2*3, a-=b/2, b-=b/2*2;
		cout << ans <<endl;
	}
	return 0;
}

