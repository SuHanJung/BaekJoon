#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b[11] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 }, c = 0;
	scanf("%d", &a);
	
	for (int i = 0, k = 0; i < a; i++) {
		scanf("%d", &k);
		if (k < 32){
			for (int t = 0; t < 11; t++) {
				if (k == b[t]) {
					c++;
					break;
				}
			}
		}
		else{
			for (int t = 0; t < 11; t++) {
				if (k % b[t] == 0) {
					break;
				}
				else if (t == 10) c++;
			}
		}
			
	}
	printf("%d", c);
	return 0;
}