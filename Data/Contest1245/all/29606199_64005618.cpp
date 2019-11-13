#pragma GCC optimize("O3")
#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

ll T;
ll N, A, B, C;
char S[111];
char ans[111];
ll i,j,k;
int main(){
    scanf("%lld", &T);
    while(T--){
        scanf("%lld%lld%lld%lld%s", &N, &A, &B, &C, S);
        ll win = N / 2 + N % 2;
        fornum(i,0,N){
            ans[i] = 'N';
            if(S[i]=='S'){
                if(A>0){
                    ans[i] = 'R';
                    A--;
                    win--;
                }
            }else if(S[i]=='P'){
                if(C>0){
                    ans[i] = 'S';
                    C--;
                    win--;
                }
            }else if(S[i]=='R'){
                if(B>0){
                    ans[i] = 'P';
                    B--;
                    win--;
                }
            }
        }
        if(win>0){
            printf("NO\n");
            continue;
        }
        fornum(i,0,N){
            if(ans[i]=='N'){
                if(A>0){
                    ans[i] = 'R';
                    A--;
                }else if(B>0){
                    ans[i] = 'P';
                    B--;
                }else{
                    ans[i] = 'S';
                }
            }
        }
        ans[N] = 0;
        printf("YES\n%s\n", ans);
    }
    return 0;
}