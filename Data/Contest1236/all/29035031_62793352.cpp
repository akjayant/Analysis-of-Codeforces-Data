#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define eps 1e-8
#define eq(x,y) (fabs((x)-(y)) < eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const ll mod= 1e9+7;
long double PI = acosl(-1);
const ll inf = 1e15;
const int nmax = 1e5+5;
const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;


vector<int>ans[500];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);


    int n;
    cin>>n;

    int boro=n*n;
    int idx = 1;
    int dir = 1;

    while(boro){
        ans[idx].push_back(boro--);
        idx+=dir;
        if(idx==n+1 and dir==1) idx=n, dir=-1;
        if(idx==0 and dir==-1) idx=1, dir=1;
    }

    for(int i=1; i<=n; i++){
        for(int x : ans[i]) cout<<x<<" ";
        cout<<"\n";
    }


}