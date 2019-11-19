#include<bits/stdc++.h>

bool ReadChar(void){
    char in;
    do in = getchar(); while(in!='(' && in!=')');
    return in=='(';
}
                 
constexpr auto MAXN = 700;

bool st[MAXN];
int sum[MAXN];
int Sum(int fr,int to){
    if(to < 0) return 0;
    if(fr == 0) return sum[to];
    else return sum[to]-sum[fr-1];
}
int Count(bool* s,const int& len){
    int lv=0,min=0,pos=-1;
    for(int i=0;i<len;i++){
        lv += (s[i] ? 1 : -1);
        if(lv < min){
            min = lv;
            pos = i;
        }
    }
    for(int i=pos+1;i<len;i++) st[i-pos-1] = s[i];
    for(int i=0;i<=pos;i++) st[i+len-pos-1] = s[i];

    int cnt = 0; lv = 0;
    for(int i=0;i<len;i++){
        lv += (st[i] ? 1 : -1);
        if(lv < 0) return 0;
        if(lv == 0) ++cnt;
    }
    
    if(lv != 0) return 0;
    else return cnt;
}

bool str[MAXN];

signed main(void)
{
    int totLen;

    std::cin>>totLen;
    for(int i=0;i<totLen;i++) str[i] = ReadChar();

    int cnttrue=0,cntfalse=0;
    for(int i=0;i<totLen;i++)
        if(str[i]) ++cnttrue;
        else ++cntfalse;

    if(cnttrue != cntfalse){ std::cout<<"0\n1 1"<<std::endl; return 0; }

    int max=Count(str,totLen),dxmax; int swp1 = 1,swp2 = 1;
    for(int i=0;i<totLen;i++)
        for(int j=i+1;j<totLen;j++){
            std::swap(str[i],str[j]);
            dxmax = Count(str,totLen);
            std::swap(str[i],str[j]);
            if(max < dxmax){
                max = dxmax; 
                swp1 = i; swp2 = j;
            }
        }

    std::cout<<max<<std::endl<<swp1+1<<' '<<swp2+1<<std::endl;
    
    return 0;
}
