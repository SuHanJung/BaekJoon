#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int SegmentTree(int tree[][3], int start, int end, int index) {
    int mid = (start + end) / 2;
    tree[index][1] = start;
    tree[index][2] = end;
    if (start == end) tree[index][0] = 1;
    else {
        tree[index][0] = SegmentTree(tree, start, mid, index * 2) + SegmentTree(tree, mid + 1, end, index * 2 + 1);
    }
    return tree[index][0];
}

int SegmentTree_delete(int tree[][3], int val, int index) {
    if (tree[index][1] <= val && tree[index][2] >= val) {
        tree[index][0]--;
        SegmentTree_delete(tree, val, index * 2);
        SegmentTree_delete(tree, val, index * 2 + 1);
        return 0;
    }
    else if (tree[index][1] > val || tree[index][2] < val) return 0;
    else {
        SegmentTree_delete(tree, val, index * 2);
        SegmentTree_delete(tree, val, index * 2 + 1);
        return 0;
    }
}

int SegmentTree_search(int tree[][3], int val, int index) {
    if (tree[index][1] == tree[index][2]) return tree[index][2];
    if (tree[index * 2][0] >= val) return SegmentTree_search(tree, val, index * 2);
    else return SegmentTree_search(tree, val - tree[index * 2][0], index * 2 + 1);
}

int main() {
    int N = 0, K = 0, now = 0,seg[1000000][3] = {0}, ans = 0;
    scanf("%d %d", &N, &K);
    printf("<%d", K);
    SegmentTree(seg, 1, N, 1);
    now = K;
    SegmentTree_delete(seg, K, 1);
    for (int size = N - 1; size > 0; size--) {
        now = (now + K - 2) % size + 1;
        ans = SegmentTree_search(seg, now, 1);
        printf(", %d", ans);
        SegmentTree_delete(seg, ans, 1);
    }
    printf(">");
    return 0;
}