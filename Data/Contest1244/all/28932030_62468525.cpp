// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9;

int main(){
	int te;scanf("%d",&te);
	while(te --){
		int a,b,c,d,k;scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int ansx=-1,ansy=-1;
		for(int x=1;x<=k;x++){
			for(int y=1;x+y<=k;y++){
//				printf("%d %d\n",x,y);
				if(x*c >= a && y*d >= b){
					ansx=x,ansy=y;
//					printf("q %d %d\n",ansx,ansy);
					break;
				}
			}
			if(~ansx)break;
		}
		if(ansx == -1)puts("-1");
		else printf("%d %d\n",ansx,ansy);
	}

	return 0;
}
