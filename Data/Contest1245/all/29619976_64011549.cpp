//I read the news today, oh boy
//About a lucky man who made the grade
 
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(int i = int(a); i < int(b); ++i)
#define roF(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N=1e6;

char ans[105];

int main(){
	fastio;
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int a, b, c; cin>>a>>b>>c;
		string str; cin>>str;
		int r=0, p=0, s=0;
		For(i,0,n) if(str[i]=='R')r++;
			else if(str[i]=='S') s++;
			else p++;
		int acumR = min(a,s);
		int acumP =  min(b,r);
		int acumS = min(c,p);
		int tot = acumR+acumP+acumS;
		if(tot>=(n/2+(n&1))){
			a-=acumR;
			b-=acumP;
			c-=acumS;
			For(i,0,n){
				if(str[i]=='R' && acumP){
					acumP--; ans[i]='P';
				}else if(str[i]=='P' && acumS){
					acumS--; ans[i]='S';
				}else if(str[i]=='S' && acumR){
					acumR--; ans[i]='R';
				}
			}
			For(i,0,n) if(!ans[i]){
				if(a){
					ans[i]='R';
					a--;
				}else if(b){
					b--;
					ans[i]='P';
				}else{
					ans[i]='S';
				}
			}
			cout<<"YES"<<endl;
			For(i,0,n) cout<<ans[i];
			cout<<endl;
			For(i,0,n) ans[i]=0;
		}else cout<<"NO"<<endl;
	}
	return 0;
}