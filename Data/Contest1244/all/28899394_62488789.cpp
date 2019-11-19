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
#define INF 1000000007
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



int32_t main(){
 
    
    
    int n;
    cin>>n;

    int k;cin>>k;

    v1d v(n);

    int min = INF;
    int max = 0;
    for(auto &i : v){
    	cin>>i;

    }

    S(v);

    int s = 0;
    int e = n-1;

    int ans = INF;
    while(true){
    	while(s+1 < n && v[s+1] == v[s]){
    		s++;
    	}

    	while(e-1 >= 0 && v[e] == v[e-1]){
    		e--;
    	}

    	if(s >= e){
    		cout<<0<<endl;
    		return 0;
    	}

    	int a = s+1;
    	int b = n-e;

    	ans = v[e] - v[s];

    	if(a < b){
    		int temp ;
    		if((v[s+1] - v[s]) * a < k){
    		    temp = (v[s+1] - v[s]) * a ;
    		}else{
    		    temp = k;
    		}
    		
    		k-=temp;
    		ans -= temp / a;
    		v[s] = v[s+1];
    	}else{
            
            int temp;
    		if((v[e] - v[e-1]) * b < k){
    		    temp = (v[e] - v[e-1]) * b;
    		}else{
    		    temp = k;
    		}
    		
    		k-=temp;
    		ans -= temp / b;
    		v[e] = v[e-1];

    	}

    	if(k == 0){
    		break;
    	}

    	

    }

    cout<<ans<<endl;



 
 
}