//Your limitation—it’s only your imagination
//order_of_key(k): Number of items strictly smaller than k .
//find_by_order(k): K-th element in a set (counting from zero).
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define full(x,n) x,x+n+1
#define full(x) x.begin(),x.end()
#define finish return 0

#define putb push_back
#define f first
#define s second

#define ordered_set tree<ll,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define putf push_front
#define gainb pop_back

#define gainf pop_front
#define len(x) x.size()

//Dream it. Wish it. Do it

// 1/b%mod=b^(m-2)%mod

typedef double db;
typedef long long ll;

//Never forget health

const ll ary=3e3+5;
const ll mod=1e9+7;
const ll inf=1e18;

using namespace std;
using namespace __gnu_pbds;
ll k;
map<char,ll> mp;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>k;
	while(k--){
		ll n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		mp.clear();
		for(int i=0;i<len(s);i++){
			mp[s[i]]++;
			mp[t[i]]++;
		}
		ll ch=1;
		for(char i='a';i<='z';i++){
			if(mp[i]%2){
				ch=0;
				cout<<"No\n";
				break;
			}
		}
		if(!ch){
			continue;
		}
		ll cnt=0;
		vector< pair<ll,ll> > q;
		for(char i='a';i<='z';i++){
			if(s==t){
				break;
			}
			ll a=0,b=0;
			for(int j=0;j<n;j++){
				if(s[j]==t[j]){
					continue;
				}
				if(s[j]==i){
					a++;
				}	
				if(t[j]==i){
					b++;
				}
			}
			for(int j=0;j<n;j++){
				if(s[j]==t[j]){
					continue;
				}
				if(s[j]==i){
					if(a<=b){
						swap(s[j],t[j]);
						q.putb({j,j});
					}
				}
				else if(t[j]==i){
					if(a>b){
						swap(s[j],t[j]);
						q.putb({j,j});
					}
				}
			}
			for(int j=0;j<n;j++){
				if(s[j]==t[j]){
					continue;
				}
				if(s[j]==i||t[j]==i){
					for(int k=j+1;k<len(s);k++){
						if(s[k]==t[k]){
							continue;
						}
						if(s[k]==i){
							swap(t[j],s[k]);
							q.putb({k,j});
							break;
						}
						else if(t[k]==i){
							swap(s[j],t[k]);
							q.putb({j,k});
							break;
						}
					}
				}
			}
		}
		if(len(q)<=2*n&&s==t){
			cout<<"Yes\n"<<len(q)<<"\n";
			for(int i=0;i<len(q);i++){
				cout<<q[i].f+1<<" "<<q[i].s+1<<"\n";
			}
			continue;
		}
		cout<<"No\n";
	}
}
//Push yourself, because no one else is going to do it for you
