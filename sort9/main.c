#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void PrintArray(int array[], int len) {
    for(int i = 0; i < len; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

void GenerateRandom(int array[], int len) {
    srand(time(NULL));
    for(int i = 0; i < len; ++i)
        array[i] = rand() % 20 + rand() % 300;
    printf("%s :\n", __FUNCTION__);
    PrintArray(array, len);
}

void JudgeArray(int array[], int len) {
    for(int i = 0; i < len - 1; ++i) {
        if(array[i] > array[i + 1]) {
            printf("sort ERROR!!\n");
            return;
        }
    }
    printf("sort OOOOOOOOOOOOOOOKKKKKKKKKKKKKKKKKKKKKKK!!!!!!!!\n");
}

void BubbleSort(int array[], int len) {
    for(int i = 0; i < len - 1; ++i) {
        for(int j = 0; j < len - 1 - i; ++j) {
            if(array[j] > array[j + 1])
                Swap(&array[j], &array[j + 1]);
        }
    }
    printf("%s :\n", __FUNCTION__);
}

void SelectSort(int array[], int len) {
    for(int i = 0; i < len - 1; ++i) {
        int min = i;
        for(int j = i +1; j < len; ++j) {
            if(array[j] < array[min])
                min = j;
        }
        Swap(&array[i], &array[min]);
    }
    printf("%s :\n", __FUNCTION__);
}

void InsertSort(int array[], int len) {
    for(int i = 1; i < len; ++i) {
        int key = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
    printf("%s :\n", __FUNCTION__);
}

void ShellSort(int array[], int len) {
    for(int step = len / 2; step > 0; step /= 2) {
        for(int i = step; i < len; ++i) {
            int key = array[i];
            int j = i - step;
            while(j >= 0 && array[j] > key) {
                array[j + step] = array[j];
                j -= step;
            }
            array[j + step] = key;
        }
    }
    printf("%s :\n", __FUNCTION__);
}

void QuickSort(int array[], int left, int right) {
    if(left >= right)
        return;

    int key = array[left];
    int head = left;
    int tail = right;
    while(head < tail) {
        while(head < tail && array[tail] > key)
            --tail;
        if(head < tail)
            array[head++] = array[tail];
        while(head < tail && array[head] < key)
            ++head;
        if(head < tail)
            array[tail--] = array[head];
    }
    array[head] = key;

    QuickSort(array, left, head - 1);
    QuickSort(array, head + 1, right);
    printf("%s :\n", __FUNCTION__);
}

void MergeSort(int array[], int left, int right) {
    if(left >= right)
        return;

    int len = right - left + 1;
    int mid = (left + right) / 2;

    MergeSort(array, left, mid);
    MergeSort(array, mid + 1, right);

    int k = 0;
    int head = left;
    int tail = mid + 1;
    int *tmp = (int *)malloc(sizeof(int) * len);

    while(head <= mid && tail <= right)
        tmp[k++] = array[head] < array[tail] ? array[head++] : array[tail++];
    while(head <= mid)
        tmp[k++] = array[head++];
    while(tail <= right)
        tmp[k++] = array[tail++];

    memcpy(array + left, tmp, sizeof(int) * len);
    free(tmp);
    printf("%s :\n", __FUNCTION__);
}

void HeapifyDown(int array[], int len, int index) {
    if(index >= len)
        return;

    int c1 = 2 * index + 1;
    int c2 = 2 * index + 2;
    int max = index;

    if(c1 < len && array[c1] > array[max])
        max = c1;
    if(c2 < len && array[c2] > array[max])
        max = c2;
    if(max != index) {
        Swap(&array[max], &array[index]);
        HeapifyDown(array, len, max);
    }
}

void BuildHeap(int array[], int len) {
    for(int i = (len - 2) / 2; i >= 0; --i)
        HeapifyDown(array, len, i);
    printf("%s : \n", __FUNCTION__);
    PrintArray(array, len);
}

void HeapSort(int array[], int len) {
    BuildHeap(array, len);

    for(int i = len - 1; i > 0; --i) {
        Swap(&array[0], &array[i]);
        HeapifyDown(array, i, 0);
    }
}

int main()
{
    int len = 10;
    int array[len];
    GenerateRandom(array, len);

    //BubbleSort(array, len);
    //SelectSort(array, len);
    //InsertSort(array, len);
    //ShellSort(array, len);
    //QuickSort(array, 0, len - 1);
    //MergeSort(array, 0, len - 1);
    //BuildHeap(array, len);
    HeapSort(array, len);

    JudgeArray(array, len);
    PrintArray(array, len);
    return 0;
}
