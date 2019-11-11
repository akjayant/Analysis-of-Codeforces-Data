#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t ;
	for (int i=0;i<t;i++){
		int n;
		cin >> n;
		int a,b,c;
		cin >> a >> b >>c;
		string s;
		cin >> s;
		int rock = 0;
		int scissor = 0;
		int paper =0;
		for (int i=0;i<s.length();i++){
			if (s[i] == 'R'){
				rock++;
			}
			else if (s[i] == 'S'){
				scissor++;
			}
			else if (s[i] == 'P'){
				paper++;
			}
		}
		int count = min(a, scissor);
		count = count + min(b, rock);
		count = count + min(c, paper);
		int req = 0;
		if (n%2 == 0){
			req = n/2;
		}
		else {
			req = n/2 + 1;
		}
		if (count >= req){
			cout << "YES" << endl;
			string output = s;
			for (int i=0;i< s.length();i++){
				output[i] = '0';
			}
			int temp = 0;
			for (int i=0; i < s.length() ; i++){
				if (s[i] == 'R' && b > 0){
					output[i] = 'P';
					b--;
				}
				else if (s[i] == 'P' && c > 0){
					output[i] = 'S';
					c--;
				}
				else if (s[i] == 'S' &&  a > 0){
					output[i] = 'R';
					a--;
				}
			}
			for (int i=0;i<s.length();i++){
				if (output[i] == 'R' || output[i] == 'S' || output[i] == 'P'){
					continue;
				}
				if (a > 0){
					output[i] = 'R';
					a--;
					continue;
				}
				if (b > 0){
					output[i] = 'P';
					b--;
					continue;
				}
				if (c > 0){
					output[i] = 'S';
					c--;
					continue;
				}
			}
			cout << output << endl;

		}
		else {
			cout << "NO" << endl;
		}
	}
}