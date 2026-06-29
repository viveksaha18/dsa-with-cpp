
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
    for(i=0; i< n-1; i++) {
        for(j=i+1; j < n; j++) {
            if(x[i] > x[j]) {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
    }
    printf("\n Array after sorting:  \n");
    for(i=0; i < n; i++) {
        printf("%d \t", x[i]);
    }

    return 0;
}