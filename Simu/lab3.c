#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int j,n,h,t,i;
	double x;
	srand(time(NULL));
	printf("Enter number of iteration:");
	scanf("%d",&n);
	t=h=0;
	for(i=0; i<=n; i++)
	{
		h=0;
	 	for(j=0; j<=10; j++)
	 	{
	 		if(x<0.5)
	 		{
	 			printf("H");
	 			h++;
			 }
			 else{
			 	printf("T");
			 }
		 }
		printf("\n");
		if(h==3 || h==6|| h==9){
			i++;
		}
	}
	double p = (double)t/n;
	printf("\n Probablity of getting 3,6,9 head in 10 coin flip,%f\n",p);
	return 0;
}