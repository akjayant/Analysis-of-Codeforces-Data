#include<bits/stdc++.h>

using namespace std;

int tc;
int a, b, c, d, k;

int main()
{
    for(scanf("%d",&tc) ; tc>0 ; tc--){
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        int x=-1, y=-1;
        for(int i=0 ; i<=k ; i++){
            int j=k-i;
            if(c*i>=a && d*j>=b){
                x=i, y=j;
                break;
            }
        }
        if(x==-1) printf("-1\n");
        else printf("%d %d\n",x,y);
    }
    return 0;
}
