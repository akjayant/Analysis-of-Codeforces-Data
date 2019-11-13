// Standard libraries
#include <stdio.h>
#include <vector>

// Main
int main(int argc, char **argv){
#ifdef __McDic__ // Local testing I/O
    freopen("VScode/IO/input.txt", "r", stdin);
    freopen("VScode/IO/output.txt", "w", stdout);
#endif

    int q; scanf("%d", &q);
    while(q>0){

        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        int max_stone = 0;
        for(int x=0; x<=100; x++) for(int y=0; y<=100; y++){
            if(x <= a && 2*x+y <= b && 2*y <= c){
                if(3*x + 3*y > max_stone) max_stone = 3*x + 3*y;
            }
        }
        printf("%d\n", max_stone);
        q--;
    }
    return 0;
}