
// Created by RUPESH
// From https://blog.codingblocks.com/2019/setting-up-a-c-competitive-programming-environment

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		int ans = 0;
		cin>>n;
		int r,p,s;
		cin >> r >> p >> s;
		string bob;
		cin >> bob;
		int needToWin = (n+1)/2;
		int r1 = 0;
		int p1 = 0;
		int s1 = 0;
		int rextr = 0;
		int pextr = 0;
		int sextr = 0;
		for (int i = 0; i < bob.length(); ++i)
		{
			if (bob[i] == 'R')r1++;
			if (bob[i] == 'P')p1++;
			if (bob[i] == 'S')s1++;
		}
		int alicWin = 0;
		if (r > s1){alicWin += s1; rextr = r-s1;}
		else alicWin += r;
		
		if (p > r1){alicWin += r1; pextr = p-r1;}
		else alicWin += p;
		
		if (s > p1){alicWin += p1; sextr = s-p1;} 
		else alicWin += s;

		if (alicWin < needToWin)
		{
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
			for (int i = 0; i < bob.length(); ++i)
			{
				if (bob[i] == 'R')
				{
					if (p > 0)
					{
						cout << "P";
						p--;
					}
					else{
						if(rextr>0){
							cout<<"R";
							rextr--;
						}
						else{
							if (sextr>0)
							{
								cout<<"S";
								sextr--;
							}
							else cout << "P";
						}
					}
				}
				if(bob[i] == 'S'){
					if (r > 0)
					{
						cout << "R";
						r--;
					}
					else{
						if(rextr>0){
							cout<<"R";
							rextr--;
						}
						else{
							if (sextr>0)
							{
								cout<<"S";
								sextr--;
							}
							else cout << "P";
						}
					}
				}
				if(bob[i] == 'P'){
					if (s > 0)
					{
						cout << "S";
						s--;
					}
					else{
						if(rextr>0){
							cout<<"R";
							rextr--;
						}
						else{
							if (sextr>0)
							{
								cout<<"S";
								sextr--;
							}
							else cout << "P";
						}
					}
				}

			}
			cout<<'\n';	
		}

	
		
	}
	return 0;
}