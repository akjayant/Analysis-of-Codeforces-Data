#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define sec second
typedef long long ll;

int main(){
	int pp;
	cin>>pp;
	while(pp--){
		int n;
		cin>>n;
		string s, t;
		cin>>s>>t;
		map <int, int> mmap, two;
		for(int i = 0; i < n; i++){
			mmap[s[i]]++;
		}
		for(int i = 0; i < n; i++){
			two[t[i]]++;
		}
		int p = 0, x = 0;
		for(int i = 'a'; i <= 'z'; i++){
			
		
			if(mmap[i] == two[i]){
				
			}
			else if(mmap[i] == two[i]+2){
				x++;
				p++;
			}
			else if(mmap[i]+2 == two[i]){
				x--;
				p++;
			}
		}
		int d = 0;
		for(int i = 0; i < n; i++){
			if(s[i]!= t[i]){
				d++;
			}
		}
		if(x == 0 and p == 2 and d == 2){
		
			cout<<"Yes"<<'\n';
		}
		else{
			cout<<"No"<<'\n';
		}
	}
}