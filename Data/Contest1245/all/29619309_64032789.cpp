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

const int MAXN = 1000;

char seq[MAXN + 3];
int cnt[256];
char mapping[265];
int enemy[265];
char mv[] = {'P', 'S', 'R'};

int main(){
    mapping['R'] = 'P';
    mapping['P'] = 'S';
    mapping['S'] = 'R';
    
    int t;
    scanf("%d", &t);
    while(t--){
        for(int i=0; i<250; i++)
            enemy[i] = cnt[i] = 0;
        int n;
        scanf("%d", &n);
        scanf("%d %d %d", &cnt['R'], &cnt['P'], &cnt['S']);
        scanf("%s", seq);
        string ans = "";
        for(int i=0; i<n; i++)
            enemy[seq[i]]++;
        int res = 0;
        for(int i=0; i<n; i++){
            if(cnt[mapping[seq[i]]] > 0){
                res++;
                cnt[mapping[seq[i]]]--;
                ans += mapping[seq[i]];
            }
            else{
                for(int j=0; j<3; j++){
                    if(enemy[mv[j]] < cnt[mapping[mv[j]]]){
                        cnt[mapping[mv[j]]]--;
                        ans += mapping[mv[j]];
                        break;
                    }
                }
            }
            enemy[seq[i]]--;
        }
        
        if(res >= (n+1)/2){
            puts("YES");
            printf("%s\n", ans.c_str());
        }
        else
            puts("NO");
    }
    
    
return 0;
}