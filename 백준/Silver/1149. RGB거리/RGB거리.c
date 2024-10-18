int main() {
	int N, RGB[2][3] = { 0 };
	scanf("%d", &N);
	scanf("%d%d%d", &RGB[0][0], &RGB[0][1], &RGB[0][2]);
	for (int t = 1; t < N; t++) {
		scanf("%d%d%d", &RGB[1][0], &RGB[1][1], &RGB[1][2]);
		RGB[1][0] += (RGB[0][1] < RGB[0][2]) ? RGB[0][1] : RGB[0][2];
		RGB[1][1] += (RGB[0][0] < RGB[0][2]) ? RGB[0][0] : RGB[0][2];
		RGB[1][2] += (RGB[0][0] < RGB[0][1]) ? RGB[0][0] : RGB[0][1];
		for (int t = 0; t < 3; t++) RGB[0][t] = RGB[1][t];
	}
	if (RGB[0][0] > RGB[0][1]) printf("%d", (RGB[0][1] < RGB[0][2]) ? RGB[0][1] : RGB[0][2]);
	else printf("%d", (RGB[0][0] < RGB[0][2]) ? RGB[0][0] : RGB[0][2]);
	return 0;
}