#include<bits/stdc++.h>
#pragma GCC optimize ("-ffloat-store")
#define ll long long
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define maxn 100002
#define pb push_back
#define X first
#define Y second
#define mod 1000000007
#define base 17
//#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define db(x) ;
using namespace std;
int k,n;
string s,t;
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    cin >> k;
    while(k--){
    	cin >> n;
    	cin >> s >> t;
    	vector<int> pos;
    	For(i,0,n-1){
    		if(s[i]!=t[i]){
    			pos.pb(i);
			}
		}
		if(pos.size()>2|| pos.size()==1){
			cout << "No\n";
			continue;
		}	
		if(pos.size()==0){
			cout << "Yes\n";
			continue;
		}
		bool mark = false;
		For(i,0,1){
			For(j,0,1){
				int pi = pos[i];
				int pj = pos[j];
				swap(s[pi],t[pj]);
				if(s[pos[0]]==t[pos[0]] && s[pos[1]]==t[pos[1]]){					
					mark = true;
				}
				swap(s[pi],t[pj]);
			}
		}
		if(mark){
			cout << "Yes\n";
		}	else	{
			cout << "No\n";
		}
	}
}
