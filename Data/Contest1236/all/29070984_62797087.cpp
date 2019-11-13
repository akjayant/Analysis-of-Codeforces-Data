#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

void read(int &x) {
    char c;bool flag = 0;
    while((c=getchar())<'0'||c>'9') flag |= (c=='-');
    x=c-'0';while((c=getchar())>='0'&&c<='9') x = (x<<3)+(x<<1)+c-'0';
    flag?x=-x:x;
}

typedef long long LL;

int main() {
    int n;
	read(n);
	int a[400][400];
	int tp = 0;
	for (int j = 1; j <= n; j++) {
	  if(j&1)
	    for (int i = 1; i <= n; i++)
		  a[i][j] = ++tp;
	  else 
	    for (int i = n; i >= 1; i--)
		  a[i][j] = ++tp;	  
	} 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
		  cout << a[i][j] << " ";
		puts("");
	}  
    return 0;
}
