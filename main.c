#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Known issue - Array selection does not work properly due to Malloc allocating 1 more spot in the array than necessary.

// Known issue 2 - Somehow, sometimes a [0] integrates itself into the sorting algorithm, basically giving me headaches... (why)

#define clear() printf("\033[H\033[J")
#define ANSI_RESET       "\x1b[0m"  
#define ANSI_BLUE       "\e[34m"
#define ANSI_MAGENTA    "\e[35m"

void swapArray( int arr[] ) {
    if (arr + 1 != 0) {
        int temp = *arr;
        *arr = *(arr + 1);
        *(arr + 1) = temp;
    }
    else {
        printf("No.");
    }
}

int userSelect(void) {
    int ArraySize;
    int perfSort;
    int uInput;
    int *iArray;
    printf("How big is the array?\n-> ");
    scanf("%d", &ArraySize);
    getchar();
    
    iArray = malloc(ArraySize*sizeof(int));

    for (int i = 0; i <= ArraySize; i++) {
        printf("\nWhat is the integer in ArrayPos[%d]? (random number pls):", i);
        scanf("%d", &uInput);
        iArray[i] = uInput;
        printf("\nInteger in ArrayPos [%d] is %d\n", i, iArray[i]);
    }
        do {
            perfSort = 0;
            for (int i = 0; i <= ArraySize; i++) {
                if(iArray[i+1] == 0) {
                    perfSort = perfSort + 1;
                } 
                if (iArray[i] > iArray[i+1]) {
                    swapArray(&iArray[i]);
                }
                else {
                    perfSort = perfSort + 1;
                }
            }
        } 
        while (perfSort <= ArraySize - 1);
        clear();
        for (int i = 0; i <= ArraySize; i++) {
            printf("[%d]", iArray[i]);
        }
    return 0;
}

int randomSelect(void) {
    srand ( time(NULL) );
    int ArraySize;
    int randomNum;
    int perfSort;
    int *iArray;
    printf("How big is the array?\n-> ");
    scanf("%d", &ArraySize);
    getchar();
    printf("How big is the Randomizer size?\n-> ");
    scanf("%d", &randomNum);
    getchar();
    
    iArray = malloc(ArraySize*sizeof(int));

    for (int i = 0; i <= ArraySize - 1; i++) {
        iArray[i] = rand()%randomNum;
        printf("\nInteger in ArrayPos [%d] is %d\n", i, iArray[i]);
    }
        do {
            perfSort = 0;
            for (int i = 0; i <= ArraySize - 1; i++) {
                if(iArray[i+1] == 0) {
                    perfSort = perfSort + 1;
                } 
                if (iArray[i] > iArray[i+1]) {
                    swapArray(&iArray[i]);
                }
                else {
                    perfSort = perfSort + 1;
                }
            }
        } 
        while (perfSort <= ArraySize - 1);
        clear();
        for (int i = 0; i <= ArraySize; i++) {
            printf("[%d]", iArray[i]);
        }
    return 0;
}

int main(void) {
    int userInput;

    clear();
    printf("What do you want to do\n[1] User Input Bubble Sort\n[2] Random Input Bubble Sort\n-> ");
    scanf("%d", &userInput);
    getchar();

    switch(userInput) {
        case 1:
            clear();
            userSelect();
            break;
        case 2:
            clear();
            randomSelect();
            break;
        default:
            printf("Not a valid selection!");
            clear();
            main();
    }
    return 0;
}