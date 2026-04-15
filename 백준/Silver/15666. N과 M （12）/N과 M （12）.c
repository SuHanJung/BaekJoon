#include <stdio.h>
#include <malloc.h>

int MergeSorting(int* arr, int n, int cell) {
	int* storage = (int*)malloc(sizeof(int) * n);
	for (int start = 0; start + cell < n; start += 2 * cell) {
		for (int left = 0, right = 0, end = (start + cell * 2 < n) ? cell : n - start - cell;;) {
			if (arr[start + left] > arr[start + cell + right]) {
				storage[start + left + right] = arr[start + cell + right];
				right++;
			}
			else {
				storage[start + left + right] = arr[start + left];
				left++;
			}
			if (right >= end) {
				for (; left < cell; left++) storage[start + left + right] = arr[start + left];
				break;
			}
			else if (left >= cell) {
				for (; right < end; right++) storage[start + left + right] = arr[start + cell + right];
				break;
			}
		}
	}
	if (n % (cell * 2) <= cell) for (int t = 0, end = (n / (cell * 2)) * cell * 2; t < end; t++) arr[t] = storage[t];
	else for (int t = 0; t < n; t++) arr[t] = storage[t];
	free(storage);
	return 0;
}

void MergeSort(int* arr, int n) {
	for (int cell = 1; cell < n; cell *= 2) {
		MergeSorting(arr, n, cell);
	}
	return;
}

int n,m;

int arr[10];
int num[10];

void seq(int x, int len){
    if(len==m){
        for(int i=0;i<m;i++)
            printf("%d ",arr[i]);
        printf("\n");
        return;
    }

    int last = 0;

    for(int i=x;i<n;i++){
        if(num[i]!=last){
            arr[len] = num[i];
            last = arr[len];
            seq(i,len+1);
        }
    }

    return;
}

int main(){
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);

    MergeSort(num,n);

    seq(0,0);

    return 0;
}