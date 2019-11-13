//Aleksander Łukasiewicz
#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int INF = 1000000009;
const int MOD = 1000*1000*1000+7;
const int MAXN = 100*1000;

int fibo[MAXN + 3];
char text[MAXN + 3];

int main(){
    int n;
    scanf("%s", text);
    n = strlen(text);
    fibo[1] = 1;
    fibo[2] = 2;
    for(int i=3; i<=n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
        if(fibo[i] >= MOD)
            fibo[i] -= MOD;
    }
    
    LL ans = 1;
    int cnt = 1;
    
    for(int i=0; i<n; i++){
        if(text[i] == 'w' || text[i] == 'm'){
            puts("0");
            return 0;
        }
    }
    
    for(int i=1; i<n; i++){
        if(text[i] == 'n' && text[i-1] == 'n')
            cnt++;
        else if(text[i] == 'u' && text[i-1] == 'u')
            cnt++;
        else{
            if(cnt > 1)
                ans = (ans*fibo[cnt])%MOD;
            cnt = 1;
        }
    }
    
    if(cnt > 1)
        ans = (ans*fibo[cnt])%MOD;
    printf("%lld\n", ans);
    
    
return 0;
}