#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n; cin >> n;
	string s; cin >> s;
	int open=0, close=0;
	for(int i=0; i<n; ++i){
		if(s[i] == '(') ++open;
		else ++close;
	}
	if(open != close){ //no valid strings
		cout << "0\n1 1\n";
		return 0;
	}
	int maxval=0, maxi=0, maxj=0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<i; ++j){
			swap(s[i], s[j]);
			int minval=0;
			int min_count=0;
			int val=0;
			for(int idx=0; idx<n; ++idx){
				if(s[idx] == '(') ++val;
				else {
					--val;
					if(val == minval) ++min_count;
					if(val < minval) minval=val, min_count=1;
				}
			}
			if(min_count>maxval){
				maxi=i, maxj=j, maxval=min_count;
			}
			swap(s[i], s[j]);
		}
	}
	cout << maxval << endl << maxi+1 << " " << maxj+1 << endl;
}
