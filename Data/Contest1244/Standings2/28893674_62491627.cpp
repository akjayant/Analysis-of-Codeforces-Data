#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<vector>
#include<ctime>
#include<cmath>
#include<set>
#include<map>
#define LL long long
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 3;
int a[N];
int n;
int ans;
LL k;
inline LL read(){
	LL v = 0,c = 1;char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') c = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		v = v * 10 + ch - 48;
		ch = getchar();
	}
	return v * c;
}
set <pii> s;
set <pii>:: iterator it;
int main(){
	n = read(),k = read();
	for(int i = 1;i <= n;++i) a[i] = read();
	sort(a + 1,a + n + 1);
	ans = a[n] - a[1];
	if(ans == 0){
		puts("0");
		return 0;	
	}
	int res = 0;
	for(int i = 1;i <= n;++i){
		res++;
		if(a[i] != a[i + 1]){
			s.insert(mk(a[i],res));
			res = 0;
		}
	}
	while(s.size() > 1){
		pii x1 = *(s.begin());
		pii x2 = *(--s.end());
		pii x3 = *(++s.begin());
		pii x4 = *(--(--s.end()));
		if(x1.se < x2.se){
			LL re = x3.fi - x1.fi;
			if(k < re * x1.se){
				ans = x2.fi - (x1.fi + k / x1.se); 
				printf("%d\n",ans);
				return 0;
			}
			else{
			 	k -= re * x1.se;
			 	s.erase(x1);
			 	s.erase(x3);
			 	x3.se += x1.se;
			 	s.insert(x3);
			}
		}
		else{
			LL re = x2.fi - x4.fi;
			if(k < re * x2.se){
				ans = (x2.fi - k / x2.se) - x1.fi; 
				printf("%d\n",ans);
				return 0;
				break;
			}
			else{
			 	k -= re * x2.se;
			 	s.erase(x2);
			 	s.erase(x4);
			 	x4.se += x2.se;
			 	s.insert(x4);
			}	
		}
	}
	puts("0");
	return 0;
}

