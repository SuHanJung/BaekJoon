#include <stdio.h>

int main() {
    int N, M, map[1025][1025] = { 0 }, x1, y1, x2, y2;
    scanf("%d %d", &N, &M);
    for(int x = 1;x <= N;x++) {
        for(int y = 1; y <= N;y++) {
            scanf("%d", &map[x][y]);
            map[x][y] += map[x - 1][y];
        }
    }
    for(int sum = 0;M > 0;M--){
    sum = 0;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for(int line = y1; line <= y2;line++){
        sum += map[x2][line];
        sum -= map[x1 - 1][line];
    }
    printf("%d\n", sum);
    }
    return 0;
}