
#include <stdio.h>

int main()
{
    int n, x[100], i, temp, j;
    printf("\n Enter the no of element");
    scanf("%d", &n);
    printf("\n enter %d no of element", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    printf("\n Array before sorting:  \n");
    for(i=0; i < n; i++) {
        printf("%d \t", x[i]);
    }
    
    // Selection sorting
    for(i = 0; i < n; i++) {
        for(j = 0; j < n-1; j++) {
            if(x[j] > x[j+1]) {
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
    printf("\n Array after sorting:  \n");
    for(i=0; i < n; i++) {
        printf("%d \t", x[i]);
    }

    return 0;
}