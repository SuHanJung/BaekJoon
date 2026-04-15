#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compare(char worda[], char wordb[]) {
	for (int count = 0;;count++) {
		if (worda[count] == wordb[count]) {
			if (worda[count] == 0) {
				return 0;
			}
		}
		else {
			if (worda[count] > wordb[count]) return -1;
			else return 1;
		}
	}
}

int sorting(char words[][21], int answer[], int n, int size) {
	int l = size / 2;
	int copied[100001] = { 0 };
	for (int count = 0; (count + 1) * size <= n; count++) {
		for (int time = 0, x = count * size, y = count * size + l; time < size; time++) {
			if (x == count * size + l) {
				copied[(count * size) + time] = answer[y];
				y++;
			}
			else {
				if (y == (count + 1) * size) {
					copied[(count * size) + time] = answer[x];
					x++;
				}
				else {
					if (compare(words[answer[x]], words[answer[y]]) == 1) {
						copied[(count * size) + time] = answer[x];
						x++;
					}
					else {
						if (compare(words[answer[x]], words[answer[y]]) == -1) {
							copied[(count * size) + time] = answer[y];
							y++;
						}
						else {
							copied[(count * size) + time] = answer[x];
							copied[(count * size) + time + 1] = answer[x];
							x++;
							y++;
							time++;
						}
					}
				}
			}
		}
	}
	if (n % size > l) {
		for (int time = 0, x = (n / size) * size, y = ((n / size) * size) + l; time < n % size; time++) {
			if (x == ((n / size) * size) + l) {
				copied[((n / size) * size) + time] = answer[y];
				y++;
			}
			else {
				if (y == n) {
					copied[((n / size) * size) + time] = answer[x];
					x++;
				}
				else {
					if (compare(words[answer[x]], words[answer[y]]) == 1) {
						copied[((n / size) * size) + time] = answer[x];
						x++;
					}
					else {
						if (compare(words[answer[x]], words[answer[y]]) == -1) {
							copied[((n / size) * size) + time] = answer[y];
							y++;
						}
						else {
							copied[((n / size) * size) + time] = answer[x];
							copied[((n / size) * size) + time + 1] = answer[x];
							x++;
							y++;
							time++;
						}
					}
				}
			}
		}
	}
	else {
		for (int count = (n / size) * size; count < n; count++) {
			copied[count] = answer[count];
		}
	}

	for (int count = 0; count < n; count++) {
		answer[count] = copied[count];
	}
	return 0;
	}

int Jsorts(char words[][21], int answer[], int n) {
	for (int cell = 1; cell < n; cell *= 2) {
		sorting(words, answer, n, cell * 2);
	}
	return 0;
}

int main(){
    int N = 0, M = 0, arr[100001], ans = 0;
    char sites[100001][21] = {0}, passwords[100001][21] = {0}, search[21] = {0};
    scanf("%d %d", &N, &M);
    for(int t = 0;t < N;t++) arr[t] = t;
    for (int t = 0;t < N;t++) scanf("%s %s", sites[t], passwords[t]);
    Jsorts(sites, arr, N);
    for(int t = 0;t<M;t++){
    scanf("%s", search);
    for(int max = N, min = -1, mid = (max + min) / 2;max - min > 1;){
        mid = (max + min) / 2;
        ans = mid;
        if(compare(sites[arr[mid]], search) == 0) break;
        else if(compare(sites[arr[mid]], search) == -1) max = mid;
        else min = mid;
    }
    for(int t = ans - 1;compare(sites[arr[ans]], search) != 0;ans++);
    printf("%s\n", passwords[arr[ans]]);
    for (int t = 0;t < 21;t++)search[t] = 0;
    }
    return 0;
}