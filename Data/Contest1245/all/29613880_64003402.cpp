#include <bits/stdc++.h>

using namespace std;

char s[505];
int vis[505];

void testcase(){
    int n;
    int a , b , c;
    cin >> n >> a >> b >> c;

    scanf("%s",s);

    int x = 0;
    int y = 0;
    int z = 0;

    for(int i =0 ;i<n;i++){
        if(s[i] == 'R'){
            x++;
        }
        else if(s[i] == 'P'){
            y++;
        }
        else z++;
    }

    int res = min(a,z) + min(b,x) + min(c,y);
    if(res >= (n+1) / 2 ){
        printf("YES\n");
        for(int i =0;i<n;i++){
            if(s[i] == 'S' && a && z){
                a--;
                z--;
                vis[i] = 1;
            }
            if(s[i] == 'R' && b && x){
                b--;
                x--;
                vis[i] = 2;
            }
            if(s[i] == 'P' && c && y){
                c--;
                y--;
                vis[i] = 3;
            }
        }

        for(int i =0 ;i<n;i++){
            if(!vis[i]){
                if(a){
                    vis[i] = 1;
                    a--;
                }
                else if(b){
                    b--;
                    vis[i] = 2;
                }
                else{
                    c--;
                    vis[i] = 3;
                }
            }
        }

        for(int i =0 ;i<n;i++){
            if(vis[i] == 1){
                printf("R");
            }
            else if(vis[i] == 2)    printf("P");
            else printf("S");

            vis[i] = 0;
        }
        printf("\n");
    }
    else printf("No\n");


}
int main()
{
    int t;
    cin >> t;
    while(t--){
        testcase();
    }
    return 0;
}
