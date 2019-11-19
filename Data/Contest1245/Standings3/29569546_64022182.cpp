#include<bits/stdc++.h>
#pragma GCC optimize ("-ffloat-store")
#define ll long long
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define maxn 2002
#define pb push_back
#define X first
#define Y second
#define mod 1000000007
#define base 17
//#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define db(x) ;
using namespace std;
ll par[230997];
ll anc(ll p){ if (par[p]==p) return p; else return par[p]=anc(par[p]); }
void join(ll p, ll q){ par[anc(p)]=anc(q); }

typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
vector<iii> edge;
ll n, m;
ll x[maxn],y[maxn],c[maxn], k[maxn],r;
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    cin >> n;
    For(i,1,n){
    	cin >> x[i] >> y[i];
	}
	For(i,1,n){
    	cin >> c[i];
    	edge.pb({c[i],{i,n+1}});
	}
	For(i,1,n){
    	cin >> k[i];
	}
	For(i,1,n){
		For(j,i+1,n){
			ll w = (abs(x[i]-x[j]) + abs(y[i]-y[j]))*(k[i]+k[j]);
			edge.pb({w,{i,j}});
		}
	}
	n++;
	for (int i=1; i<=n; i++) par[i]=i;
	sort(edge.begin(), edge.end());
    vector<iii>::iterator it;
    vector<ii> ans;
    for (it=edge.begin(); it!=edge.end(); it++){
        if (anc(it->Y.X) != anc(it->Y.Y)){
        	ans.pb({it->Y.X, it->Y.Y});
            join(it->Y.X, it->Y.Y);
            r += it->X;
        }
    }
    cout << r << "\n";
    vector<int> ans1;
    vector<ii> ans2;
    for(ii &e:ans){
    	if(e.X==n || e.Y == n){
    		ans1.pb(e.X+e.Y-n);
		}	else	{
			ans2.pb(e);
		}
	}
	cout << ans1.size() << "\n";
	for(int &v:ans1){
		cout << v << " ";
	}
	cout << "\n";
	cout << ans2.size() << "\n";
	for(ii &v:ans2){
		cout << v.X << " " << v.Y << "\n";
	}
}
