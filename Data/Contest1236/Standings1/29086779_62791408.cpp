// Standard libraries
#include <stdio.h>
#include <vector>

// Main
int main(int argc, char **argv){
#ifdef __McDic__ // Local testing I/O
    freopen("VScode/IO/input.txt", "r", stdin);
    freopen("VScode/IO/output.txt", "w", stdout);
#endif

    int n; scanf("%d", &n);
    std::vector<std::vector<int>> grid(n, std::vector<int>(n, -1));
    
    int num=1;
    for(int col=0; col<n; col++){
        if(col%2 == 0){
            for(int row=0; row<n; row++) grid[row][col] = num++;
        }
        else{
            for(int row=n-1; row>=0; row--) grid[row][col] = num++;
        }
    }

    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++) printf("%d ", grid[row][col]);
        printf("\n");
    }
    return 0;
}