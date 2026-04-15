int main() {
	int a[10], *m = &a[1];
	for (int t = 1, n; t < 10; t++) {
		scanf("%d", &a[t]);
		m = (a[t] > *m) ? &a[t]:m;
}
	printf("%d\n%d", *m, m - a);
	return 0;
}