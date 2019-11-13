#include<bits/stdc++.h>
int t,n,a,b,c;
std::string s,s2;
int main(){
	std::cin >> t;
	for(;t--;){
		std::cin >> n >> a >> b >> c >> s, s2 = s;
		int win = 0;
		for(;std::count(s.begin(),s.end(),'S') && a > 0;--a) s2[s.find('S')] = 'R',s[s.find('S')] = '?', ++ win;
		for(;std::count(s.begin(),s.end(),'R') && b > 0;--b) s2[s.find('R')] = 'P',s[s.find('R')] = '?', ++ win;
		for(;std::count(s.begin(),s.end(),'P') && c > 0;--c) s2[s.find('P')] = 'S',s[s.find('P')] = '?', ++ win;

		for(;std::count(s.begin(),s.end(),'R') && a > 0;--a) s2[s.find('R')] = 'R',s[s.find('R')] = '?';
		for(;std::count(s.begin(),s.end(),'P') && b > 0;--b) s2[s.find('P')] = 'P',s[s.find('P')] = '?';
		for(;std::count(s.begin(),s.end(),'S') && c > 0;--c) s2[s.find('S')] = 'S',s[s.find('S')] = '?';

		for(;std::count(s.begin(),s.end(),'P') && a > 0;--a) s2[s.find('P')] = 'R',s[s.find('P')] = '?';
		for(;std::count(s.begin(),s.end(),'S') && b > 0;--b) s2[s.find('S')] = 'P',s[s.find('S')] = '?';
		for(;std::count(s.begin(),s.end(),'R') && c > 0;--c) s2[s.find('R')] = 'S',s[s.find('R')] = '?';
		if(win >= n + 1 >> 1) {
			std::cout << "Yes\n" << s2 << '\n';
		} else {
			std::cout << "No\n" << '\n';
		}
	}
}
