#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define ss second
#define ff first
using namespace std;

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d,k;
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        int rez=0;
        rez+=a/c+(a%c>0);
        rez+=b/d+(b%d>0);
        if(rez>k)printf("-1\n");
        else printf("%d %d\n",a/c+(a%c>0),b/d+(b%d>0));
    }


    return 0;
}
