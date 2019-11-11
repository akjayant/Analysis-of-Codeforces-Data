#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
char a[maxn];
vector<char>rec;
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
      int n;
      scanf("%d",&n);
      rec.clear();
      int rock=0,paper=0,jian=0,rockk=0,paperr=0,jiann=0;
      scanf("%d%d%d",&rock,&paper,&jian);
      scanf("%s",&a);
      for(int i=0;i<n;i++){
        if(a[i]=='R') rockk++;
        if(a[i]=='P') paperr++;
        if(a[i]=='S') jiann++;
      }

      if(min(rock,jiann)+min(paper,rockk)+min(jian,paperr)>=(n+1)/2){
        printf("YES\n");
        for(int i=1;i<=rock-min(rock,jiann);i++){
            rec.push_back('R');
        }
        for(int i=1;i<=paper-min(paper,rockk);i++){
            rec.push_back('P');
        }
        for(int i=1;i<=jian-min(jian,paperr);i++){
            rec.push_back('S');
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]=='P'&&jian>=1){
                printf("S");
                jian--;
            }
            else if(a[i]=='S'&&rock>=1){
                printf("R");
                rock--;
            }
            else if(a[i]=='R'&&paper>=1){
                printf("P");
                paper--;
            }
            else{
                printf("%c",rec[cnt++]);
            }
        }
        printf("\n");
      }else{
        printf("NO\n");
      }
    }
    return 0;
}
