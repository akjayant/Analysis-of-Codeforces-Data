#include <bits/stdc++.h>
using namespace std; 

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

typedef long long ll; 
typedef long double ld; 
typedef vector<int> vi; 
typedef pair<int,int> pii; 
#define pb push_back
#define mp make_pair
#define prarr(a,n) cerr<<#a<<" : ";for(ll i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define prmat(mat,row,col) cerr<<#mat<<" :\n";for(ll i=0;i<row;i++) {for(ll j=0;j<col;j++) cerr<<mat[i][j]<<"\t";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
#define all(a) a.begin(),a.end()
#define sz(x) ((int)x.size())
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(NULL); cin.tie(NULL)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {ll idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ", "; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
template <class T> void prall(T a) { prc(all(a)); }
const int inf=1000*1000*1000+9; 
const ll infl=1ll*inf*inf; 
const int mod=1000*1000*1000+7;  

// ----------------------------------------------------------------------------	-------------- 

ll dp[40][2][2][2][2]; 

void solve(){
	int t; cin>>t; 
	while(t--){
		memset(dp,0,sizeof(dp)); 
		ll l,r; cin>>l>>r; 
		int n=35; 
		dp[n][1][1][1][1]=1; 
		for(ll i=n-1;i>=0;i--){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					for(int j2=0;j2<2;j2++){
						for(int k2=0;k2<2;k2++){
							ll pre=dp[i+1][j][k][j2][k2]; 
							for(int d1=0;d1<2;d1++){
								for(int d2=0;d2<2;d2++){
									int nj=j, nk=k, nj2=j2, nk2=k2;  
									if(d1==1 && d2==1) continue; 
									if(d1==0 && ((1ll<<i) & l)>0 && k==1) continue; 
									if(d1==1 && ((1ll<<i) & r)==0 && j==1) continue; 
									if(d2==1 && ((1ll<<i) & r)==0 && j2==1) continue; 
									if(d2==0 && ((1ll<<i) & l)>0 && k2==1) continue; 
									if(d1==0 && ((1ll<<i) & r)>0) nj=0; 
									if(d1==1 && ((1ll<<i) & l)==0) nk=0; 
									if(d2==0 && ((1ll<<i) & r)>0) nj2=0; 
									if(d2==1 && ((1ll<<i) & l)==0) nk2=0; 
									dp[i][nj][nk][nj2][nk2]+=pre; 
									// dp[i][nj][nk][nj2][nk2]%=mod; 
									// pr(i,nj,nk,nj2,nk2,dp[i][nj][nk][nj2][nk2]); 
								}
							}	
						}
					}
				}	
			}	
		}
		ll ans=0; 
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				for(int j2=0;j2<2;j2++){
					for(int k2=0;k2<2;k2++){
						ans+=dp[0][j][k][j2][k2]; 
						// ans%=mod; 
					}
				}
			}
		}
		cout<<ans<<endl; 
	}
}



int main(){
	// clock_t beg=clock(); 
	fast_io; 
    cout << fixed << setprecision(13); 
	solve(); 	
	// clock_t end=clock(); 
	// fprintf(stderr, "%lf\n", (double)(end-beg)/(CLOCKS_PER_SEC));
}