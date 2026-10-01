#include <stdio.h>

// Bubble Sort function
void bubble(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Merge function
void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

// Merge Sort function
void mergeSort(int arr[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[100];
    int n, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("\n\n--- SORTING MENU ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                bubble(arr, n);

                printf("\nArray after Bubble Sort:\n");
                for (i = 0; i < n; i++)
                {
                    printf("%d ", arr[i]);
                }
                break;

            case 2:
                mergeSort(arr, 0, n - 1);

                printf("\nArray after Merge Sort:\n");
                for (i = 0; i < n; i++)
                {
                    printf("%d ", arr[i]);
                }
                break;

            case 3:
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid choice! Please enter 1, 2 or 3.");
        }
    }

    return 0;
}

