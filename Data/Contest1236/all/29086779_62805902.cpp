// Standard libraries
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <utility>

// Min, Max, Abs
int min2(int a, int b){ return a<b ? a:b;}
int max2(int a, int b){ return a>b ? a:b;}
int abs(int x){ return x>=0 ? x:-x;}

// End
void possible(){ printf("Yes\n"); exit(0);}
void impossible(){ printf("No\n"); exit(0);}

// Obstacles
std::map<int, std::set<int>> obstacles_by_x, obstacles_by_y;

/*
// Is all empty?
bool is_all_empty(int xstart, int ystart, int xend, int yend){
    if(xstart > xend || ystart > yend) return true;

    if(xend-xstart < yend-ystart){ // Look by x
        for(int x = xstart; x <= xend; x++){
            auto ptr = obstacles_by_x[x].lower_bound(ystart);
            if(ptr != obstacles_by_x[x].end() && *ptr <= yend) return false;
        }
    }
    else{ // Look by y
        for(int y = ystart; y <= yend; y++){
            auto ptr = obstacles_by_y[y].lower_bound(xstart);
            if(ptr != obstacles_by_y[y].end() && *ptr <= xend) return false;
        }
    }
    return true;
}
*/

// Find closest impossible place. Assume (x, y) is possible.
std::pair<int, int> get_obstacle(int x, int y, int direction){
    if(direction == 0){ // (x, y) -> (x, y+1)
        return {x, *obstacles_by_x[x].lower_bound(y)};
    }
    else if(direction == 1){ // (x, y) -> (x+1, y)
        return {*obstacles_by_y[y].lower_bound(x), y};
    }
    else if(direction == 2){ // (x, y) -> (x, y-1)
        auto ptr = obstacles_by_x[x].lower_bound(y);
        ptr--;
        return {x, *ptr};
    }
    else{ // (x, y) -> (x-1, y)
        auto ptr = obstacles_by_y[y].lower_bound(x);
        ptr--;
        return {*ptr, y};
    }
}

// Main
int main(int argc, char **argv){
#ifdef __McDic__ // Local testing I/O
    freopen("VScode/IO/input.txt", "r", stdin);
    freopen("VScode/IO/output.txt", "w", stdout);
#endif

    // Get input
    int xlimit, ylimit, n_ob; scanf("%d %d %d", &xlimit, &ylimit, &n_ob);
    for(int i=0; i<n_ob; i++){
        int x, y; scanf("%d %d", &x, &y);
        obstacles_by_x[x].insert(y);
        obstacles_by_y[y].insert(x);
    }

    // End obstacles
    for(int x=1; x<=xlimit; x++){
        obstacles_by_x[x].insert(0);
        obstacles_by_x[x].insert(ylimit+1);
    }
    for(int y=1; y<=ylimit; y++){
        obstacles_by_y[y].insert(0);
        obstacles_by_y[y].insert(xlimit+1);
    }

    int x = 1, y = 1, current_direction = 0;
    long long int moved = 1;
    bool previous_stopped = false;
    int xmin = 1, xmax = xlimit, ymin = 1, ymax = ylimit;
    while(true){
        
        int new_x, new_y;
        std::pair<int, int> blockedposition = get_obstacle(x, y, current_direction);
        if(current_direction == 0){ // (x, y) -> (x, y+1)
            new_x = x, new_y = min2(ymax, blockedposition.second - 1);
            ymax = min2(ymax, new_y);
            xmin++;
        }
        else if(current_direction == 1){ // (x, y) -> (x+1, y)
            new_x = min2(xmax, blockedposition.first - 1), new_y = y;
            xmax = min2(xmax, new_x);
            ymax--;
        }
        else if(current_direction == 2){ // (x, y) -> (x, y-1)
            new_x = x, new_y = max2(ymin, blockedposition.second + 1);
            ymin = max2(ymin, new_y);
            xmax--;
        }
        else{ // (x, y) -> (x-1, y)
            new_x = max2(xmin, blockedposition.first + 1), new_y = y;
            xmin = max2(xmin, new_x);
            ymin++;
        }

        //printf("direction %d: (%d, %d) -> (%d, %d)\n", current_direction, x, y, new_x, new_y);
        //printf("  - blocked position (%d, %d)\n", blockedposition.first, blockedposition.second);
        //printf("  - now x range [%d, %d], y range [%d, %d].\n", xmin, xmax, ymin, ymax);
        moved += abs(x - new_x) + abs(y - new_y);
        if(x == new_x && y == new_y){
            if(!previous_stopped) previous_stopped = true;
            else break;
        }
        x = new_x, y = new_y;
        current_direction++; current_direction %= 4;
        previous_stopped = true;
    }

    //printf("moved = %lld\n", moved);

    if(moved + n_ob == (long long int)xlimit * (long long int)ylimit) possible();
    else impossible();
    return 0;
}