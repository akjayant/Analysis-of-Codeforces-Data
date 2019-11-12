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
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>k;
	while(k--){
		ll n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		ll id=-1;
		for(int i=0;i<n;i++){
			if(s[i]!=t[i]){
				id=i;
				break;
			}
		}
		if(id==-1){
			cout<<"Yes\n";
			continue;
		}
		ll ch=0;
		for(int i=0;i<len(s);i++){
			swap(s[id],t[i]);
			if(s==t){
				ch=1;
				cout<<"Yes\n";
				break;
			}
			swap(s[id],t[i]);
			swap(t[id],s[i]);
			if(s==t){
				ch=1;
				cout<<"Yes\n";
				break;
			}
			swap(t[id],s[i]);
		}
		if(ch){
			continue;
		}
		cout<<"No\n";
	}
}
//Push yourself, because no one else is going to do it for you
