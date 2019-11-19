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
using namespace std;
int cal(string s){
	int len = s.length();
	int cnt = 0;
	int maxCnt = -1;
	int pos = -1;
	For(i,0,len-1){
		if(s[i]==')') cnt++;
		else cnt--;
		if(cnt>maxCnt){			
			maxCnt = cnt;
			pos = i;
		}
	}
	
	string ns;
	if(pos==-1){
		ns = s;
	}	else	{
		ns = s.substr(pos+1,len-pos-1) + s.substr(0,pos+1);
	}
//	cout << ns << "\n";
	cnt = 0;
	int ans = 0;
	For(i,0,len-1){
		if(ns[i]=='(') cnt++;
		else cnt--;
		if(cnt == 0){
			ans ++;
		}	else if(cnt <0){
			return 0;
		}
	}
//	cout << ns << " " << ans << "\n";
	return ans;
}
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    string s;
    int n;
    cin >> n;
    cin >> s;    
    int cnt = 0;
    For(i,1,n){
    	if(s[i-1]=='(') cnt++;    	
	}
//	cal(s);
	if(cnt*2!=n){
		cout << "0\n1 1";		
	}	else{		
		int ans = 0;
		int px=1;
		int py=1;
//		cout << "n=" <<n;
	    For(i,0,n-1){
	    	For(j,i,n-1){
//	    		cout << "!";
//	    		if(s[i]!=s[j]){
	    			char c = s[i];
	    			s[i] = s[j];
	    			s[j] = c;
					int temp = cal(s);
					if(temp > ans){
						ans = temp;
						px = i+1;
						py = j+1;
					}
					c = s[i];
	    			s[i] = s[j];
	    			s[j] = c;
//				}
			}
		}
		cout << ans << "\n" << px << " " << py;
	}
}
