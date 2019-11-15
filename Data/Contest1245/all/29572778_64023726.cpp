
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack> 
#include <map>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;



char win(char c) {
	if(c=='R')
		return 'P';
	else if(c=='P')
		return 'S';
	else
		return 'R';
}

string win(string s) {
	string ans = "";
	for(char c:s){
		ans.push_back(win(c));
	}
	return ans;
}

int main() {
    //ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a, b, c;
		cin >> a>>b >> c;
		string s ;
		cin >>s;
		string ws = win(s);
		map<char,int > m;
		for(char c: ws)
			m[c]++;
		int tw =0;
		tw+=min(a, m['R']);
		tw+=min(b, m['P']);
		tw+=min(c, m['S']);
		if(2*tw>=n) {	
			cout<<"YES\n";
			string ans = ws;
			multiset<char> st;
			for(int i=0;i<a;i++)	
				st.insert('R');
			for(int i=0;i<b;i++)
				st.insert('P');
			for(int i=0;i<c;i++)
				st.insert('S');
			
			for(char &c: ans){
				if(st.find(c)==st.end()){
					c='?';
				}
				else {
					st.erase(st.find(c));
				}
			}
			for(char &c: ans){
				if(c=='?') {
					c=*st.begin();
					st.erase(st.begin());
				}
			}
			assert(st.size()==0);
			cout << ans<<"\n";

		} else {
			cout<<"NO\n";
		}
	}


	return 0;
}

