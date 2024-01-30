//Sm_lab1
#include <stdio.h>
#include<stdlib.h>

int main()
{
	//define transition matrix
	double p[2][2];
	printf("Enter the transition matrix: \n"); //(eg: 0.7 0.3 0.4 0.6 for a 2x2 matrix):
	scanf("%lf %lf %lf %lf", &p[0][0], &p[0][1], &p[1][0], &p[1][1]);
	
	//printf the transition matrix
	printf("Transition matrix:\n");
	printf("%f %f\n", p[0][0], p[0][1]);
	printf("%f %f\n", p[1][0], p[1][1]);
	
	//Define the current state matrix
	float x,y;
	printf("Enter the current state matrix: \n");// (eg. 1 0 for state 1)
	scanf("%f %f", &x,&y);
	
	//generate the markov chain
	int n;
	printf("Enter the number of steps to generate: \n");
	scanf("%d",&n);
	
	printf("State sequence probabilities: \n");
	printf("%f %f\n", x, y);
	for(int i=1; i<=n; i++)
	{
		float new_x = p[0][0]*x +p[1][0]*y;
		float new_y = p[0][1]*x +p[1][1]*y;
		printf("%f %f\n", new_x, new_y);
		x= new_x;
		y= new_y;
	}
	return 0;
}