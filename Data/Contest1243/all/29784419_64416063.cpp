#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
 
char s[100], t[100];
bool flag1 = 0;
bool flag0 = 0;
int ans1[10000];
int ans2[10000];
int tmpos = -1;
void settpos(){
    tmpos = -1;
}
vector<pii> ans;int get1[28], get2[28];
int main() {
    int k; scanf("%d",&k);
    while (k--) {
        flag0 = 1;
        
        int n; scanf("%d",&n);
        scanf("%s",&s);
        scanf("%s",&t);
        
        memset(get1, 0, sizeof(get1));
        memset(get2, 0, sizeof(get2));
        memset(ans1, 0, sizeof(ans1));
        memset(ans2, 0, sizeof(ans2));

        for (int i = 0; i < n; i++)  get1[s[i] -'a']++;
        for (int i = 0; i < n; i++)  get2[t[i] -'a']++;
        for (int i = 0; i < 26; i++) {
            int tot_num_for_chari = get1[i] + get2[i];
            if ((tot_num_for_chari)%2){
                flag0 = 0;
            }
        }
        if (flag0 == 0){  printf("No\n");    continue;}
        int top = 0;
        tmpos = -1;
        settpos(); 
        for (int i = 0; i < n; i++) {
            if (s[i]==t[i])  continue;
            tmpos = -1;
            for (int j = i + 1; j < n; j++)
            {
                if (s[i]==s[j]){
                    tmpos = j;
                    break;
                }
            }
            if (~tmpos){
                char tmp = t[i];
                t[i] = s[tmpos];
                s[tmpos] = tmp;
                ans1[top] =  tmpos + 1;
                ans2[top++] = i+1;
                continue;
            }
     
            for (int j = i + 1; j < n;j++)
            {
                if (t[j]==s[i]){
                    tmpos = j;
                    break;
                }
            }
            char tmp = s[i+1];
            s[i+1] = t[tmpos];
            t[tmpos] = tmp;
            swap(t[i], s[i + 1]);
            ans1[top] = i+2;
            ans2[top++]  = tmpos+1;
            ans1[top] = i+2;
            ans2[top++] = i+1;
            
        }
        if(flag0!=0){
            printf("Yes\n");
            printf("%d\n", top);
            for (int jj=0;jj<top;jj++){
              printf("%d %d\n", ans1[jj], ans2[jj]);
            }
        }
        
    }
    return 0;
}
