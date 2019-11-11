#include <bits/stdc++.h>
using namespace std;


int tests;
int n,a,b,c,d;
string s,t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>tests;
	while(tests--){
	    cin>>n;
	    cin>>a>>b>>c;
	    cin>>s;
	    t=s;
	    fill(t.begin(),t.end(),'*');
	    for (int i=0; i<n; ++i){
	        if (s[i]=='S' && a>0){
	            t[i]='R';
	            a--;
	        }
	        if (s[i]=='R' && b>0){
	            t[i]='P';
	            b--;
	        }
	        if (s[i]=='P' && c>0){
	            t[i]='S';
	            c--;
	        }
	    }
	    d=n-a-b-c;
	    for (int i=0; i<n; ++i){
	        if (s[i]=='R' && t[i]=='*' && a>0){
	            t[i]='R';
	            a--;
	        }
	        if (s[i]=='P' && t[i]=='*' && b>0){
	            t[i]='P';
	            b--;
	        }
	        if (s[i]=='S' && t[i]=='*' && c>0){
	            t[i]='S';
	            c--;
	        }
	    }
	    for (int i=0; i<n; ++i){
	        if (s[i]=='P' && t[i]=='*' && a>0){
	            t[i]='R';
	            a--;
	        }
	        if (s[i]=='S' && t[i]=='*' && b>0){
	            t[i]='P';
	            b--;
	        }
	        if (s[i]=='R' && t[i]=='*' && c>0){
	            t[i]='S';
	            c--;
	        }
	    }
	    if (d>=(n+1)/2) 
	        cout<<"YES\n"<<t<<'\n';
	    else 
	        cout<<"NO\n";
	}
	return 0;
}