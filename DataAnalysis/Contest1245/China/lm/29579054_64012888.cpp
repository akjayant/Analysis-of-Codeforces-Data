using namespace std;
const int maxn=1e5+7;
const int mod=1e9+7;
char S[maxn];
long long fib[maxn];
int main()
{
    int T=1;
    fib[1]=1;
    fib[2]=2;
    for(int i=3;i<maxn;i++)
        fib[i]=(fib[i-1]+fib[i-2])%mod;
    while(T--){
        long long ans=1;
        scanf("%s",S+1);
        int len=strlen(S+1);
        for(int i=1;i<=len;i++){
            if(S[i]=='m'||S[i]=='w')ans=0;
        }
        if(ans==0){
            printf("0\n");
            continue;
        }
        int now=0;
        for(int i=1;i<=len;i++){
            if(S[i]=='u')now++;
            else if(now!=0){
                ans=ans*fib[now]%mod;
                now=0;
            }
        }
        if(now){
            ans=ans*fib[now]%mod;
            now=0;
        }
        for(int i=1;i<=len;i++){
            if(S[i]=='n')now++;
            else if(now!=0){
                ans=ans*fib[now]%mod;
                now=0;
            }
        }
        if(now){
            ans=ans*fib[now]%mod;
            now=0;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
