#include <stdio.h>
#include <stdlib.h> 

void main() {
	int N = 0, K = 0, currency = 0; // 동전의 가치 종류 N, 최솟값을 구할 값 K, 화폐 단위 currency
	int count=0;
	while (1) {
		scanf_s("%d %d", &N, &K);
		if (N <= 10 && N >= 1) // 종류는 1개 이상 10개 이하
			break;
		else
			printf("1≤N≤10\n");
	}

	int *A = (int*)malloc(sizeof(int) * N); // N개의 줄(동전의 가치) 동적 할당

	for (int i = 0; i < N; i++)
	{
		while (1) {
			scanf_s("%d", &currency);
			if (currency <= 100000000 && currency >= 1)
			{
				if (i == 0 && currency == 1) { // A₁= 1 조건
					A[i] = currency;
					break;
				}
				else if (i == 0 && currency != 1) {
					printf("A₁= 1");
				}

				else if (i >= 1){ // Aᵢ i≥2 인 경우, Aᵢ는 Aᵢ₋₁조건
					A[i] = currency;
					if (A[i] % A[i - 1] == 0) {
						break;
					}
					else {
						printf("A[%d]는 A[%d]의 배수\n", i, i-1);
					}
				}
			}
			else {
				printf("1≤K≤100,000,000\n"); // 금액은 1원 이상 1억 이하
			}
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		if (K >= A[i])
		{
			count += K / A[i];
			printf("%d원 짜리 동전 %d개   ", A[i], K / A[i]);
			K = K % A[i];
			printf("나머지 %d원\n", K);
		}
	}
	printf("동전 개수의 최솟값은 %d개", count);
	free(A);
	return 0;
}