#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int tt;
int n;
char s[10005];
char t[10005];
int diff[10005];
// TabNine::config

int main(){
    scanf("%d",&tt);
    while(tt--){
        scanf("%d%s%s",&n,s+1,t+1);
        int total_diff = 0;
        for(int i=1;i<=n;i++) diff[i] = s[i]!=t[i], total_diff+=diff[i];
        if(total_diff == 2){
            int pos1 = 1;
            while(!diff[pos1]) pos1++;
            int pos2 = n;
            while(!diff[pos2]) pos2--;
            swap(s[pos1], t[pos2]);
            if(s[pos1] == t[pos1] && s[pos2] == t[pos2]){
                puts("Yes");
            }else{
                puts("No");
            }
        }else{
            puts("No");
        }
        
    }

    return 0;
}