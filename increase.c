#include <stdlib.h>
#include <stdio.h>

int increase(int num[], int length)
{
    return 0;
}

void displayArray(int num[], int length)
{
    for (int i=0; i<length; i++) {
        printf(" %3d",num[i]);
    }
    printf("\n");
}


int main()
{
    int num1[]={10,9,2,5,3,7,101,18};
    int length1=8;
    printf("Array: ");
    displayArray(num1,length1);
    printf("Length= %d\n",increase(num1,length1));

    int num2[]={10,24,2,7,3,30,20,5,7,9,21,14,21,8,22};
    int length2=15;
    printf("Array: ");
    displayArray(num2,length2);
    printf("Length= %d\n",increase(num2,length2));
}
