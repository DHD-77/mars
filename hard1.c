#include<stdio.h>
#include<string.h>
int head, tail;
 struct point{
        int x;
        int y;
    };
struct point dq(struct point *arrp){
            head++;
            return arrp[head-1];
    }
void enq(struct point *arrp, int x, int y) {
    tail++;
    arrp[tail].x = x;
    arrp[tail].y = y;
}
int main(){
    int map[11][11];
    int i, j;
    for(i=0;i<11;i++){
        for(j=0;j<11;j++){
            map[i][j]=1;
        }
    }
   
FILE *fptr;
fptr = fopen("sample.txt", "r");

if (fptr == NULL) {
    printf("Error: Could not open file.\n");
} 
else {
    int n, e, s, w;
    // This reads 4 integers from each line until the end of the file
    while (fscanf(fptr, "%d %d %d %d", &n, &e, &s, &w) == 4) {
        // making sure that the coordinate is inside the 11X11 matrix
        if (n < 11 && e < 11) {
            map[n][e] = 0; // marking the obstacle
        }
    }
    fclose(fptr); // closing the file
}
 // printing the matrix
 for(i=10;i>=0;i--){
        for(j=0;j<11;j++){
            printf(" %d",map[i][j]);
        }
        printf("\n");
       
    }

   
    head = 0;
    tail = 0;
    struct point arrp[121];
    arrp[0].x = 0;
    arrp[0].y = 0;
    int dist[11][11];

    for(i=0;i<11;i++){
        for(j=0;j<11;j++){
            dist[i][j]=-1;
        }
    }
    struct point parent[11][11];
    dist[0][0]=0;
    parent[0][0].x = -1;
    parent[0][0].y = -1;
    while(head<=tail){
        struct point curr = dq(arrp);
        if (curr.x == 10 && curr.y == 10) {
        printf("Destination reached! Distance: %d\n", dist[10][10]);
        break; // Exit the loop
    }
    // Directions: Right, Left, Up, Down
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++) {
        int nx = curr.x + dx[k];
        int ny = curr.y + dy[k];

        // CHECK CONDITIONS:
        // 1. Inside 11x11 grid?
        // 2. Is it a path (1) and not an obstacle (0)?
        // 3. Is it unvisited (dist == -1)?
        if (nx >= 0 && nx < 11 && ny >= 0 && ny < 11 && 
            map[nx][ny] == 1 && dist[nx][ny] == -1) {
            
            dist[nx][ny] = dist[curr.x][curr.y] + 1;
            parent[nx][ny] = curr; // Save the parent for backtracking
            enq(arrp, nx, ny);    // Add to queue
        }
    }
}
}