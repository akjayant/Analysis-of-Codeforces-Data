//In the name of God
#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 1e3 + 10;
 
int n, res, tc;
string s, t;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> tc;
	while(tc --){
		cin >> n;
		cin >> s >> t;
		vector<int> vec;
		for(int i = 0; i < n; i ++)
			if(s[i] != t[i])
				vec.push_back(i);
		if(vec.size() == 0)	cout << "Yes\n";
		else{
			if(vec.size() != 2)	cout << "No\n";
			else{
				char c = s[vec[0]];	s[vec[0]] = t[vec[1]];
				t[vec[1]] = c;
				cout << (s == t ? "Yes" : "No") << "\n"; 
			}
		}
	}
	return 0;
}