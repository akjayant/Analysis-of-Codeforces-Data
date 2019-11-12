#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int main()
{
	int n;
	cin>>n;
	vector<vector<int>> ans(n,vector<int>());
	for(int i=0;i<n;i++){
        int beg=i*n+1;
        int ed=beg+n-1;
        if(i&1){
            for(int j=ed,k=0;j>=beg;j--,k++)ans[k].pb(j);
        }else {
            for(int j=beg,k=0;j<=ed;j++,k++)ans[k].pb(j);
        }
	}
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j];
            if(j==n-1)cout<<endl;
            else cout<<" ";
        }
	}
    return 0;
}
