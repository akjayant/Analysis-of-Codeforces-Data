#include<bits/stdc++.h>

using namespace std;
#define debug(x) cout<<#x<<" is "<<x<<endl;
typedef long long ll;



int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int x=min(c/2,b);
        b-=x;
        int y=min(b/2,a);
        printf("%d\n",3*(x+y));
    }
    return 0;
}
