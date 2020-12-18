#include <stdio.h>
#include <stdlib.h>

// NOT Working...

int *merge(int *arr1, int *arr2, int l1, int r1, int l2, int r2) {
    int i = 0, j = 0, k = 0;
    int *arr = (int *) malloc((r2 - l1) * sizeof(int));
    while (i < r1 - l1 && j < r2 - l2) {
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < r1 - l1) {
        arr[k++] = arr1[i];
        i++;
    }
    while (j < r2 - l2) {
        arr[k] = arr1[j];
        j++;
        k++;
    }
    return arr;
}

int *mergeSort(int *arr, int start, int end) {
    // [9, 4, 7, 2]
    if (end - start == 1) {
        return arr;
    }
    int midPoint = (end - start) / 2;
    int *left = mergeSort(arr, start, midPoint);
    int *right = mergeSort(arr, midPoint, end);
    return merge(left, right, start, midPoint, midPoint, end);
}

int main() {
    int n = 0;
    int temp = 0;
    printf("How many (integer) values do you wanna sort? ");
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter No %d: ", i + 1);
        scanf("%d", &temp);
        arr[i] = temp;
    }

    mergeSort(arr, 0, n);
    return 0;
}