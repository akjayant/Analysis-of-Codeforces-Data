 #include <bits/stdc++.h>

 using namespace std;

 int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;

    cin>>N;
    int mat[N][N];
    int j=1;
    for(int i=0; i<N; i++){
        int x;
        if(i%2==1){
            x=N-1;
            while(x>-1){
                mat[x][i]=(i)*N+(N-x);
                x--;
            }
        }
        else{
            x=0;
            while(x<N){
                mat[x][i]=(i)*N+(x+1);
                x++;
            }
        }


    }
    for(int i=0; i<N; i++){
        for(int x=0; x<N; x++){
            cout<<mat[i][x]<<" ";
        }cout<<'\n';
    }
    return 0;
 }
