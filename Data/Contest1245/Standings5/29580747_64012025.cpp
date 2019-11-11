#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stack> 
#include <string>
using namespace std;
string op;
char m[500];
int main(){
	int t, i, a, b, c, n, len, ans, tmp;
	int t1, t2, t3;
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		ans = 0;
		scanf("%d%d%d", &a, &b, &c); 
		cin >> op;
		for(i = 0; i < n; i++){
			m[i] = '0';
		}
		for(i = 0; i < n; i++){
			if(op[i] == 'R'){
				if(b > 0){
					ans++;
					m[i] = 'P';
					b--;
				}
			}
			if(op[i] == 'P'){
				if(c > 0){
					ans++;
					m[i] = 'S';
					c--;
				}
			}
			if(op[i] == 'S'){
				if(a > 0){
					ans++;
					m[i] = 'R';
					a--;
				} 
			}
		}
		tmp = (n + 1) / 2;
		if(ans >= tmp){
			printf("YES\n");
			for(i = 0; i < n; i++){
				if(m[i] == '0'){
					if(a > 0){
						a--;
						m[i] = 'R';
					}
					else if(b > 0){
						b--;
						m[i] = 'P';
					}
					else if(c > 0){
						c--;
						m[i] = 'S'; 
					}
				}
				printf("%c", m[i]);
			}
			printf("\n");
		}
		else{
			printf("NO\n"); 
		}
	}
	return 0;
} 
