#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
typedef long long int lo;
const int N=500005,mod=1000000007;
lo a,b,c,d,e,f,g,h[N],arr[N];
string s;
vector<lo>v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("in.txt","r",stdin);
 //    freopen("out.txt","w",stdout);
    cin >> g;
    while(g--){
    	cin >> a >> b >> c >> d >> e;
    	lo x=ceil((double)a/c),y=ceil((double)b/d);
    	if(x+y<=e){
    		cout << x << ' ' << y << endl;
    	}
    	else{
    		cout << -1 << endl;
    	}
    }
}