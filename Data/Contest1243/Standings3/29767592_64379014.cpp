#include <bits/stdc++.h>
using namespace std;

const int N=1e3+3;

int n;
string s,t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tests;
	cin>>tests;
	while(tests--){
	    cin>>n;
	    cin>>s>>t;
	    int cnt=0;
	    int x=-1,y=-1;
	    for (int i=0; i<n; ++i)
	        if (s[i]!=t[i]){
	            cnt++;
	            x==-1 ? x=i : y=i;
	        }
        if (cnt==1 || cnt>2){
            cout<<"NO\n";
            continue;
        }
        if (cnt==0){
            cout<<"YES\n";
            continue;
        }
        swap(s[x],t[y]);
        cout<<(s==t ? "YES\n" : "NO\n");
	}
}
