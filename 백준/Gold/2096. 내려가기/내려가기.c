int main(){
    int N, max[3], min[3];
    scanf("%d", &N);
    scanf("%d%d%d", &max[0], &max[1], &max[2]);
    min[0] = max[0];
    min[1] = max[1];
    min[2] = max[2];
    for(int t = 1, a, b, c;t<=N;t++){
        if(t == N) {
            a = 0;
            b = 0;
            c = 0;
        }
        else scanf("%d%d%d", &a, &b, &c);
        max[0] = (max[0] > max[1]) ? max[0] + a:max[1] + a;
        max[2] = (max[1] > max[2]) ? max[1] + c:max[2] + c;
        max[1] = (max[0] - a > max[2] - c) ? max[0] - a + b : max[2] - c + b;
        min[0] = (min[0] < min[1]) ? min[0] + a:min[1] + a;
        min[2] = (min[1] < min[2]) ? min[1] + c:min[2] + c;
        min[1] = (min[0] - a < min[2] - c) ? min[0] - a + b: min[2] - c + b;
    }
    printf("%d %d", max[1], min[1]);
    return 0;
}