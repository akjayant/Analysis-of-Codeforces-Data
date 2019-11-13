#include <bits/stdc++.h>
using namespace std;

#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define in_range(x,l,r) (lb(all(x),r+1)-lb(all(x),l))
#define per(i,n) for (int i=(int)(n)-1;i>=0;i--)
#define For(i,n) for (int i=1;i<=(int)(n);i++)
#define Rep(i,n) for (int i=0;i<=(int)(n);i++)
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define set0(i) memset(i,0,sizeof(i))
#define all(x) (x).begin(),(x).end()
#define Max(a,b,c) max(a,max(b,c))
#define Min(a,b,c) min(a,min(b,c))
#define fore(i,x) for (auto &i:x)
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define pii pair<int,int>
#define vi vector <int>
#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define re return
#define se second
#define fi first
const int INF=0x7fffffff;
const int MAXN=+3;

int n,a,b,c,w;
string s,t;

int main(){
	int T;
	cin>>T;
	while (T--){
		cin>>n>>a>>b>>c>>t;
		s="";
		w=0;
		fore(i,t){
			if (i=='R' && b){
				b--;
				s=s+'P';
				w++;
			}else if (i=='P' && c){
				c--;
				s=s+'S';
				w++;
			}else if (i=='S' && a){
				a--;
				s=s+'R';
				w++;
			}else{
				s=s+"_";
			}
		}
		if (w>=(n+1)/2){
			cout<<"YES"<<endl;
			fore(i,s){
				if (i!='_'){
					cout<<i;
				}else{
					if (a){
						cout<<'R';
						a--;
					}else if (b){
						cout<<'P';
						b--;
					}else{
						cout<<'S';
						c--;
					}
				}
			}
			cout<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	re 0;
}