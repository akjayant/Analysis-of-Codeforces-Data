#include <bits/stdc++.h>

using namespace std;

char s1[10003];
char s2[10003];

int main(){

    int k;
    scanf("%d",&k);
    for(int i = 1; i<=k; ++i){

        int n;
        scanf("%d",&n);

        vector<int>diffplaces;

        scanf("%s %s",s1,s2);

        for(int i = 0; i<n; ++i){

            if(s1[i]!=s2[i]){

                diffplaces.push_back(i);
            }
        }
        int sz = (int)diffplaces.size();

        if(sz>2 || sz==1){

            printf("No\n");
        }
        else if(sz==2){
            swap(s1[diffplaces[0]],s2[diffplaces[1]]);

            int f = 1;

            for(int i = 0; i<n; ++i){

                if(s1[i]!=s2[i]){

                    f = 0;
                    break;
                }
            }
            if(f){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else{

            char cnt[26];
            memset(cnt,0,sizeof(cnt));
            for(int i = 0; i<n; ++i){
                cnt[s1[i]-'a']++;
            }

            int f  = 0;
            for(int i = 0; i<26; ++i){
                if(cnt[i]>1){
                    f = 1;
                    break;
                }
            }

            if(f){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
    return 0;
}
