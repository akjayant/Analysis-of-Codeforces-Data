#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 505
int n;
char a[N];
char b[N];
int pre_ban[N];  int pre_num[N];
int suf_ban[N];  int suf_num[N];

//计算每个前缀有多少个没匹配的')'  注意如果前缀有没匹配的'('那么是不能用的
//计算每个后缀有多少个没匹配的'('


void swap(int x,int y){
    for(int i=1;i<=n;++i) b[i]=a[i];
    swap(b[x],b[y]);
}

void get_array(){
    memset(pre_ban,0,sizeof(pre_ban));
    memset(suf_ban,0,sizeof(suf_ban));
    memset(pre_num,0,sizeof(pre_num));
    memset(suf_num,0,sizeof(suf_num));
    int c1=0; int c2=0;  //c1 '('  c2')'
    for(int i=1;i<=n;++i){
        if(b[i]=='(') ++c1;
        if(b[i]==')'){
            if(c1) --c1;
            else   ++c2;
        }
        pre_num[i]=c2;
        if(c1) pre_ban[i]=true;
    }
    
    c1=0;  c2=0;
    for(int i=n;i>=1;--i){
        if(b[i]==')') ++c2;
        if(b[i]=='('){
            if(c2) --c2;
            else   ++c1;
        }
        suf_num[i]=c1;
        if(c2) suf_ban[i]=true;
    }
    suf_num[n+1]=0;
}

int ans1; int ans2; int mx;



int main(){
    scanf("%d",&n);
    scanf("%s",a+1);
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            //枚举交换的位置
            swap(i,j);
            get_array();
            int cnt=0;
            for(int k=0;k<n;++k){
                int pos1=n-k+1; //后一段的开头
                int pos2=n-k;   //前一段的结尾
                if(pre_ban[pos2]) continue;
                if(suf_ban[pos1]) continue;
                if(pre_num[pos2]!=suf_num[pos1]) continue;
                ++cnt;
            }
            if(cnt>=mx){
                mx=cnt;
                ans1=i; ans2=j;
            }
        }
    }
    printf("%d\n",mx);
    printf("%d %d\n",ans1,ans2);
    return 0;
    
}






















