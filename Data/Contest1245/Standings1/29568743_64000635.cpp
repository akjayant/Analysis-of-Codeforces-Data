#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<algorithm>

#define rg register
#define il inline
#define MX (100 + 5)

int read(){
	rg char k = getchar();
	int x = 0 ,flag = 1;
	while(k < '0' || k > '9'){
		if(k == '-')	flag = -1;
		k = getchar();
	}
	while(k >= '0' && k <= '9'){
		x = x * 10 + k - '0';
		k = getchar();
	}
	return x * flag;
}

char d[MX];
char str[MX];
int main(){
	int t = read();
	while(t--){
		int n = read();
		int a = read() ,b = read() ,c = read();	
		int A = a ,B = b ,C = c;
		scanf("%s" ,str);
		int win = 0;
		memset(d ,0 ,sizeof(d));
		for(rg int i = 0 ; i < n ; ++i){
			if(str[i] == 'R' && b)	++win ,--b ,d[i] = 'P';
			if(str[i] == 'P' && c)	++win ,--c ,d[i] = 'S';
			if(str[i] == 'S' && a)	++win ,--a ,d[i] = 'R';
		}
		if(win >= (n + 1) / 2){
			puts("YES");
			for(rg int i = 0 ; i < n ; ++i){
				if(d[i]){
					putchar(d[i]);
				}
				else{
					if(b)	putchar('P') ,--b;
					else if(c) putchar('S') ,--c;
					else putchar('R') ,--a;
				}
			}
			puts("");
		}
		else{
			puts("NO");
		}
	}
}
