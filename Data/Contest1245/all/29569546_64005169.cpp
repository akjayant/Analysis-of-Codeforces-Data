#include<bits/stdc++.h>
#pragma GCC optimize ("-ffloat-store")
#define ll long long
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define maxn 100002
#define pb push_back
#define X first
#define Y second
#define mod 1000000007
#define base 17
//#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define db(x) ;
using namespace std;
int r,p,c,t;
int n,R,P,C, nWin;
string s;
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    cin >> t;
    while(t--){
    	cin >> n;
    	cin >> R >> P >> C;
    	cin >> s;
    	r = p = c = 0;
    	For(i,0,n-1){
    		if(s[i]=='R'){
    			r++;
			}
			if(s[i]=='P'){
    			p++;
			}
			if(s[i]=='S'){
    			c++;
			}
		}
		nWin = min(R,c) + min(P,r) + min(C,p);
		if(nWin*2>=n){
			cout << "YES\n";
			vector<int> ans(n,0);
			For(i,0,n-1){
				if(s[i]=='P'){
					if(C>0){
						ans[i] = 'S';
						C--;
					}
				}
				if(s[i]=='S'){
					if(R>0){
						ans[i] = 'R';
						R--;
					}
				}
				if(s[i]=='R'){
					if(P>0){
						ans[i] = 'P';
						P--;
					}
				}
			}
			vector<int> rubbish;
			For(i,1,R) rubbish.pb('R');
			For(i,1,P) rubbish.pb('P');
			For(i,1,C) rubbish.pb('S');
			int ind = 0;
			For(i,0,n-1){
				if(ans[i]==0){
					ans[i] = rubbish[ind];
					ind++;
				}
			}
			for(int &v:ans){
				cout << ((char)v);
			}
			cout << "\n";
		}	else	{
			cout << "NO\n";
		}
	}
}
