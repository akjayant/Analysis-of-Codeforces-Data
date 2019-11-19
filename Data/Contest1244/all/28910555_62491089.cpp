#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
typedef long long int lo;
const int N=100005,mod=1000000007;
lo a,b,c,d,e,f,g,h[N],arr[4][N];
string s;
vector<lo>v[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> a;
    for(lo i=1;i<=3;i++){
    	for(lo j=1;j<=a;j++){
    		cin >> arr[i][j];
    	}
    }
    for(lo i=1;i<a;i++){
    	lo x,y;
    	cin >> x >> y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    for(lo i=1;i<=a;i++){
    	if(v[i].size()>2){
    		cout << -1;
    		return 0;
    	}
    	if(v[i].size()==1){
    		b=i;
    	}
    }
   	lo perm[6][3]={{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
    lo ans=1000000000000000000;
    for(lo i=0;i<6;i++){
    	memset(h,0,sizeof h);
    	lo say=0,lans=0;
    	queue<lo>q;
    	q.push(b);
    	while(q.size()){
    		h[q.front()]=1;
    		lo node=q.front();
    		lans+=arr[perm[i][say%3]][node];
    		say++;
    		q.pop();
    		for(lo i=0;i<v[node].size();i++){
    			if(h[v[node][i]]==0){
    				q.push(v[node][i]);
    			}
    		}
    	}
    	if(lans<ans){
    		ans=lans;
    		c=i;
    	}
    }
    lo awdasda[N];
    cout << ans << endl;
	memset(h,0,sizeof h);
	queue<lo>q;
	lo say=0;
	q.push(b);
	while(q.size()){
		h[q.front()]=1;
		lo node=q.front();
		awdasda[node]=perm[c][say%3];
		say++;
		q.pop();
		for(lo i=0;i<v[node].size();i++){
			if(h[v[node][i]]==0){
				q.push(v[node][i]);
			}
		}
	}
	for(lo i=1;i<=a;i++){
		cout << awdasda[i] << ' ';
	}
}