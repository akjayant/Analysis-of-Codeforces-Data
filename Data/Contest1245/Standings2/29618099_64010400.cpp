#include <bits/stdc++.h>
using namespace std;
int t;
const int maxn=105;
int n,a,b,c,cnt;
char s[maxn],ans[maxn];
int main(){
	cin >> t;
	while (t--){
		cnt=0;
		cin >> n >> a >> b >> c;
		cin >> s;
		memset(ans,0,sizeof(ans));
		for (int i=0;i<n;i++){
			if (s[i]=='P'){
				if (c>0){
					cnt++;
					c--;
					ans[i]='S';
				}
			}
			if (s[i]=='R'){
				if (b>0){
					cnt++;
					b--;
					ans[i]='P';
				}
			}
			if (s[i]=='S'){
				if (a>0){
					cnt++;
					a--;
					ans[i]='R';
				}
			}
		}
		if (cnt>=(n+1)/2){
			cout << "Yes\n";
			for (int i=0;i<n;i++){
				if (!ans[i]){
					if (a>0){
						cout << 'R';
						a--;
					}else if (b>0){
						cout << 'P';
						b--;
					}else if (c>0){
						cout << 'S';
						c--;
					}
					
				}else
					cout << ans[i];
			}
			cout << '\n';
		}else{
			cout <<"No\n";
		}
		
	}
}