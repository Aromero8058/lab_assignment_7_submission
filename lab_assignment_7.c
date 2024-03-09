#include <stdio.h>

void bubbleSort(int arr[], int size, int swapHolder[])
{
    int temp;
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                swapHolder[arr[j]]++;
                swapHolder[arr[j+1]]++;
            }
        }
    }

}

void selectionSort(int arr[], int size, int swapHolder[])
{
    int min_idx, temp, totalSwaps;
    for(int i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        if(min_idx != i)
        {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;

            swapHolder[arr[min_idx]]++;
            swapHolder[arr[i]]++;
        }
    }

}

void resetArr1(int arr[])
{
    arr[0] = 97;
    arr[1] = 16;
    arr[2] = 45;
    arr[3] = 63;
    arr[4] = 13;
    arr[5] = 22;
    arr[6] = 7;
    arr[7] = 58;
    arr[8] = 72;
}

void resetArr2(int arr[], int size)
{
    int counter = 90;
    for(int i = 0; i < size; i++)
    {
        arr[i] =counter;
        counter -= 10;
    }
}

void printArray(int swapHolder[], int arr[], int size)
{
    int totalSwaps = 0;
    for(int i = 0; i < size; i++)
    {
        printf("%d: %d\n", arr[i], swapHolder[arr[i]]);
        totalSwaps += swapHolder[arr[i]];
    }

    printf("%d\n", totalSwaps/2);
}


int main()
{
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int arrSize = 9;

    int bubbleSwapHolder1[100] = {0};
    int bubbleSwapHolder2[100] = {0};
    int selectionSwapHolder1[100] = {0};
    int selectionSwapHolder2[100] = {0};

    bubbleSort(array1, arrSize, bubbleSwapHolder1);
    printf("array1 bubble sort:\n");
    printArray(bubbleSwapHolder1, array1, arrSize);

    bubbleSort(array2, arrSize, bubbleSwapHolder2);
    printf("array2 bubble sort:\n");
    printArray(bubbleSwapHolder2, array2, arrSize);

    resetArr1(array1);
    resetArr2(array2, arrSize);

    selectionSort(array1, arrSize, selectionSwapHolder1);
    printf("array1 selection sort:\n");
    printArray(selectionSwapHolder1, array1, arrSize);

    selectionSort(array2, arrSize, selectionSwapHolder2);
    printf("array2 selection sort:\n");
    printArray(selectionSwapHolder2, array2, arrSize);

    return 0;
}