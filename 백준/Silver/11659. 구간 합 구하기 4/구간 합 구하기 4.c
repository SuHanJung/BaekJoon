#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arr[100000] = { 0 };

int SegmentTree(int tree[][3], int start, int end, int index) {
    int mid = (start + end) / 2;
    tree[index][1] = start;
    tree[index][2] = end;
    if (start == end) tree[index][0] = arr[start];
    else {
        tree[index][0] = SegmentTree(tree, start, mid, index * 2) + SegmentTree(tree, mid + 1, end, index * 2 + 1);
    }
    return tree[index][0];
}

int SegmentTree_search(int tree[][3], int start, int end, int index) {
    if (tree[index][1] >= start && end >= tree[index][2]) return tree[index][0];
    if (tree[index][1] > end || tree[index][2] < start) return 0;
    else return SegmentTree_search(tree, start, end, index * 2) + SegmentTree_search(tree, start, end, index * 2 + 1);
}

int main() {
    int N = 0, T = 0, st = 0, en = 0, tree[400000][3] = {0};;
    scanf("%d %d", &N, &T);
    for (int t = 1; t <= N; t++) scanf("%d", &arr[t]);
    SegmentTree(tree, 1, N, 1);
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &st, &en);
        printf("%d\n", SegmentTree_search(tree, st, en, 1));
    }
    return 0;
}