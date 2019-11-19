#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define ld long double
#define pb push_back
#define pa pair<int,int>
#define v1d vector<int>
#define v2d vector<vector<int>>
#define v1p vector<pa>
#define INF 1000000000000007
#define M 998244353
#define mp make_pair
#define RS(v)    sort(v.rbegin(),v.rend())
#define print(a) printf("%.16f\n", a);
#define PI 3.14159265
#define ff first
#define ss second
#define ump map<int,int>
#define endl "\n"
#define v1s vector<string>
#define S(v) sort(v.begin(),v.end())
#define mxpq priority_queue <int>
#define mnpq priority_queue<int,vector<int>,greater<int>>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fff cout.flush();
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
pbds;

int dfs(v1d &isit , int i ,int idx, v1d &per , v2d &c , v2d &v){

	if(isit[idx] != -1){
		return 0;
	}

	isit[idx] = per[i];

	int ans = c[per[i]][idx];

	for(auto j : v[idx]){
		ans += dfs(isit , (i+1)%3 , j , per, c ,v);
	}

	return ans;

}

int find(v2d &v){

	int ans = 0 ;
	int two = 0 ;
	int one = 0;
	for(int i = 0 ; i  < v.size() ; i++){

		if(v[i].size() > 2){
			return -1;
		}else if(v[i].size() == 1){
			one++;
			ans = i;
		}else{
			two++;
		}


	}

	if(one == 2){
		return ans;
	}else{
		return -1;
	}


}
int32_t main(){
 
    // cout<<INF;
    
    int n;
    cin>>n;

    v2d c(3 , v1d (n));

    for(int i = 0 ; i  < 3 ; i ++){

    	for(auto &j : c[i]){
    		cin>>j;
    	}
    }

    v2d v(n);

    for(int i = 0 ; i  <n-1; i++){
    	int a,b;cin>>a>>b;
    	a--;b--;

    	v[a].pb(b);
    	v[b].pb(a);
    }


    v2d per(6);

    per[0] = {0,1,2};
    per[1] = {0,2,1};
    per[2] = {1,0,2};
    per[3] = {1,2,0};
    per[4] = {2,1,0};
    per[5] = {2,0,1};

    int idx = find(v);

    if(idx == -1){
    	cout<<-1<<endl;
    	return 0;
    }
    
    int cost = INF;
    int ans = 0;

    for(int i = 0 ; i  < 6 ; i++){
        
        // for(auto jj : per[i]){
        //     cout<<jj<<" ";
            
        // }

    	v1d isit(n , -1);
    	int temp = dfs(isit, 0 ,idx , per[i] , c , v);
    	
    // 	cout<<temp<<endl;

    	if(temp < cost){
    		ans = i;
    		cost = temp;
    	}
    }

    cout<<cost<<endl;
    v1d isit(n , -1);

    dfs(isit , 0 ,idx , per[ans] , c , v );
    for(auto i : isit){
    	cout<<i+1<<" ";
    }


 
 
}