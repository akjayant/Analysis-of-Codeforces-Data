#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+1;
const LL B=1e9+1,T=2e14+1;
typedef long long LL;
int n;
LL k,A[N];
LL check(LL s,LL d){
    LL tmp=0;
    for(int i=1;i<=n;i++){
        if(A[i]<s){
            tmp+=abs(A[i]-s);
        }
        else{
            if(A[i]>(s+d)){
                tmp+=abs(s+d-A[i]);
            }
        }
    }
    return tmp;
}
bool check2(LL mid){
        LL L=1,R=T;
        while(R-L!=1){
       //     printf("Ovde %I64d %I64d %I64d\n",mid,L,R);
            LL MID=(R+L)/2;
         //   printf("Provera za %I64d %I64d %I64d %I64d\n",MID,MID+1,check(MID,mid),check(MID+1,mid));
            if(check(MID,mid)<check(MID+1,mid)){
                R=MID;
            }
            else{
                L=MID;
            }
        }
        if(check(L,mid)>k && check(R,mid)>k){
            return 0;
        }
        return 1;
}
int main()
{
    scanf("%d %I64d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&A[i]);
    }
    LL l=0,r=B;
    while(r-l!=1){
  //      printf("Saddd %I64d %I64d\n",l,r);
        LL mid=(l+r)/2;
        LL L=1,R=2e14+1;
        if(check2(mid)) r=mid;
        else    l=mid;
    }
 //   printf("Smor %I64d %I64d\n",l,r);
    if(check2(l)){
        cout<<l;
        return 0;
    }
    cout<<r;
    return 0;
}
//binarna po d, pa ternarna po startu
