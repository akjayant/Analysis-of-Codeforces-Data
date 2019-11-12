#include<bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define pb push_back
#define ms(a, x) memset(a, x, sizeof(a))

#define endl '\n'
using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> vec[305];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
	int tot=1;
	int flag=0;
	forn(i,n){
		if(flag){
			ford(i,n){
				vec[i].pb(tot++);
			}
			flag=0;
		}else{
			forn(i,n) vec[i].pb(tot++);
			flag=1;
		}
	}
	forn(i,n){
		for(auto it:vec[i]) cout<<it<<' ';
		cout<<endl;
	}
    return 0;
}
