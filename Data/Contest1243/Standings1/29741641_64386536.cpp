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
typedef pair<int,int> ii;
int cnt[30];
int n,k;
string s,t;
void exe(string &s1, string &s2, vector<ii> &ans, int index){
	int len = s1.length();
	if(index>=len) return;
	if(s1[index]==s2[index]){
		exe(s1,s2,ans,index+1);
		return;
	}
	For(i,index+1,len-1){
		if(s2[i]==s1[index]){
			swap(s1[i], s2[i]);
			ans.pb({i,i});
			break;
		}
	}
	For(i,index+1,len-1){
		if(s1[i]==s1[index]){
			swap(s1[i],s2[index]);
			ans.pb({i,index});
			break;
		}
	}
	exe(s1,s2,ans,index+1);
}
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    cin >> k;
    while(k--){
    	cin >> n;
    	cin >> s >> t;
    	memset(cnt,0,sizeof(cnt));
    	For(i,0,n-1){
    		cnt[s[i]-'a']++;
    		cnt[t[i]-'a']++;
		}
		bool mark = true;
		For(i,0,'z'-'a'){
			if(cnt[i]%2==1){
				cout << "No\n";
				mark = false;
				break;
			}
		}
		if(mark == false){
			continue;
		}
		vector<ii> ans;
		exe(s,t,ans,0);
		cout << "Yes\n";
		cout << ans.size()<< "\n";
		for(ii &e:ans){
			cout << (e.X+1) << " " << (e.Y+1) << "\n";
		}		
	}
}
