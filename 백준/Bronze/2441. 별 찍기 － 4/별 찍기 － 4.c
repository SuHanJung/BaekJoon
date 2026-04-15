#include<stdio.h>
int main() {
		int a, b, c = 0;
		scanf("%d", &a);
		b = a--;
		while (1) {
			while(0 < b - a - ++c) printf(" ");
			while(0 <= b - c++) printf("*");
			if(--a < 0) return 0;
			printf("\n");
			c = 0;
		}
}