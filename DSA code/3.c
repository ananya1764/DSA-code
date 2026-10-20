#include <stdio.h>
#include <string.h>

struct Data
{
    int numbers[100];
    char words[100][20];
};

// Bubble Sort for Numbers
void bubbleSort(struct Data *d, int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(d->numbers[j] > d->numbers[j + 1])
            {
                temp = d->numbers[j];
                d->numbers[j] = d->numbers[j + 1];
                d->numbers[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Numbers using Bubble Sort:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", d->numbers[i]);
    }
}


// Linear Search for Words
void linearSearch(struct Data d, int n, char key[])
{
    int i, found = 0;

    for(i = 0; i < n; i++)
    {
        if(strcmp(d.words[i], key) == 0)
        {
            printf("\nWord found using Linear Search at position %d", i + 1);
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nWord not found");
    }
}


// Binary Search for Numbers
void binary_search(struct Data d, int n, int key)
{
    int low = 0, high = n - 1, mid;
    int found = 0;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(d.numbers[mid] == key)
        {
            printf("\nNumber found using Binary Search at position %d", mid + 1);
            found = 1;
            break;
        }
        else if(key < d.numbers[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(found == 0)
    {
        printf("\nNumber not found");
    }
}


// Selection Sort for Words
void selectionSort(struct Data d, int n)
{
    int i, j, min;
    char temp[20];

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(strcmp(d.words[j], d.words[min]) < 0)
            {
                min = j;
            }
        }

        strcpy(temp, d.words[i]);
        strcpy(d.words[i], d.words[min]);
        strcpy(d.words[min], temp);
    }

    printf("\n\nSorted Words using Selection Sort:\n");

    for(i = 0; i < n; i++)
    {
        printf("%s ", d.words[i]);
    }
}


// Main Function
int main()
{
    struct Data d;
    int n, i;
    int keyNumber;
    char keyWord[20];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("\nEnter %d numbers:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &d.numbers[i]);
    }

    printf("\nEnter %d words:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%s", d.words[i]);
    }


    // Bubble Sort
    bubbleSort(&d, n);


    // Binary Search
    printf("\n\nEnter number to search using Binary Search: ");
    scanf("%d", &keyNumber);

    binary_search(d, n, keyNumber);


    // Selection Sort
    selectionSort(d, n);


    // Linear Search
    printf("\n\nEnter word to search using Linear Search: ");
    scanf("%s", keyWord);

    linearSearch(d, n, keyWord);

    return 0;
}





