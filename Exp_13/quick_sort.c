#include <stdio.h>

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int l, int h) {
	int x = arr[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++) {

		if (arr[j] <= x) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}


void quickSortIterative(int arr[], int l, int h)  {
	int stack[h - l + 1];
	int top = -1;

	stack[++top] = l;
	stack[++top] = h;

	while (top >= 0) {
		h = stack[top--];
		l = stack[top--];

		int p = partition(arr, l, h);

		if (p - 1 > l) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		if (p + 1 < h) {
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}

void printArr(int arr[], int n) {
	int i;
	for (i = 0; i < n; ++i)
		printf("%d ", arr[i]);
}

void readarr(int size,int arr[size]) {   
    printf("Enter the Elements of the Array : ");
    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);
}

int main() {
    int size;
	printf("Enter the Size of the Array : ");
    scanf("%d",&size);
    int arr[size];
    readarr(size,arr);
	int n = sizeof(arr) / sizeof(*arr);
	quickSortIterative(arr, 0, n - 1);
	printArr(arr, n);
	return 0;
}
