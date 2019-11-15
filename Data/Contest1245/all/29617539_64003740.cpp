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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a,b,c;
		cin>>a>>b>>c;
		string st;
		cin>>st;
		string ans(st.size(),0);
		for(int i=0;i<st.size();i++){
			if(st[i]=='R'&&b){
				ans[i]='P';
				b--;
			}else if(st[i]=='P'&&c){
				ans[i]='S';
				c--;
			}else if(st[i]=='S'&&a){
				ans[i]='R';
				a--;
			}
		}
		if(a+b+c<=n/2){
			for(int i=0;i<st.size();i++){
				if(ans[i]==0){
					if(a){
						ans[i]='R';
						a--;
					}else if(b){
						ans[i]='P';
						b--;
					}else if(c){
						ans[i]='S';
						c--;
					}
				}
			}
			cout<<"YES\n"<<ans<<endl;
		}else cout<<"NO\n";
	}
    return 0;
}
