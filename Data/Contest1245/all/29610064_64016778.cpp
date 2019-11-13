#include<iostream>
#include<cstring>
#define MAXN 105
using namespace std;
int dp[MAXN][MAXN][MAXN];
int cho[MAXN][MAXN][MAXN];
inline int mask(int x,int y){
    return x * MAXN + y;
}
inline pair<int,int> getxy(int mask){
    int y = mask % MAXN;
    int x = mask / MAXN;
    return {x,y};
}
char s[MAXN];
char stk[MAXN];
int T,n,a,b,c;
int main(){
    cin >> T;
    while(T--){
        cin >> n >> a >> b >> c >> s;
        //cout << s << endl;
        for(int i = 0;i <= n;++i){
            for(int pa = 0;pa <= a + 1;++pa){
                for(int pb = 0;pb <= b + 1;++pb){
                    dp[i][pa][pb] = -1;
                    cho[i][pa][pb] = -1;
                }
            }
        }
        dp[0][a][b] = 0;
        for(int i = 1;i <= n;++i){
            for(int pa = 0;pa <= a;++pa){
                for(int pb = 0;pb <= b;++pb){
                    int pc = n - i - pa - pb;
                    if(pc < 0 || pc > c) continue;
                    if(dp[i - 1][pa][pb + 1] != -1){
                        dp[i][pa][pb] = dp[i - 1][pa][pb + 1] + (s[i - 1] == 'R');
                        cho[i][pa][pb] = mask(pa,pb + 1);
                    }
                    if(dp[i - 1][pa + 1][pb] != -1 && dp[i - 1][pa + 1][pb] + (s[i - 1] == 'S') > dp[i][pa][pb]){
                        dp[i][pa][pb] = dp[i - 1][pa + 1][pb] + (s[i - 1] == 'S');
                        cho[i][pa][pb] = mask(pa + 1,pb);
                    }
                    if(dp[i - 1][pa][pb] != -1 && dp[i - 1][pa][pb] + (s[i - 1] == 'P') > dp[i][pa][pb]){
                        dp[i][pa][pb] = dp[i - 1][pa][pb] + (s[i - 1] == 'P');
                        cho[i][pa][pb] = mask(pa,pb);
                    }
                }
            }
        }
        int li = n / 2 + (n % 2);
        if(dp[n][0][0] < li){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            int pa = 0,pb = 0;
            for(int i = n;i >= 1;--i){
                int q = cho[i][pa][pb];
                auto v = getxy(q);
                if(v.first == pa && v.second == pb){
                    stk[i - 1] = 'S';
                }
                else if(v.first == pa + 1){
                    stk[i - 1] = 'R';
                }
                else{
                    stk[i - 1] = 'P';
                }
                pa = v.first,pb = v.second;
            }
            stk[n] = 0;
            cout << stk << endl;
        }
    }
}