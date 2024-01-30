// implement linear congruential method for random number generation 
#include<stdio.h>
#define MAX 50
int main()
{
    int i,n,a,seed,c, m, r[MAX];
    printf("How many random numbers you want to generate:");
    scanf("%d",&n);
    printf("Enter the value of a:");
    scanf("%d",&a);
    printf("Enter the value of c:");
    scanf("%d",&c);
    printf("Enter the value of m:");
    scanf("%d",&m);
    printf("Enter the seed value:");
    scanf("%d",&r[0]);
    for(i=1;i<=n;i++)
    {
        r[i]=(a*r[i-1]+c)%m;
    }
    printf("The random numbers are:\n");
    for(i=1;i<=n;i++){
        printf("%f\n",(float)r[i]/m);
    }
}