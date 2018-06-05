/*
 * Parallel program to Multiply two Matrices
 * Compile Using: "g++ mult.cpp -fopenmp"
 * Requirements: OpenMP should be installed
 *
 * Created By Yashasvi Goel
 * Date:05/06/18
 * Input the size of first array
 * Followed by the array
 * Repeat for second array
 *
 */
#include <stdio.h>
#include<stdlib.h>
#ifdef _OPENMP
#include<omp.h>
#else 
#define omp_get_thread_num() 0
#endif
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int **a=(int**)malloc(m*sizeof(int*));
	for(int i=0;i<m;i++)
		a[i]=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	int p,q;
	scanf("%d %d",&p,&q);
	int **b=(int**)malloc(p*sizeof(int*));
	for(int i=0;i<p;i++)
		b[i]=(int*)malloc(q*sizeof(int));
	long int **c=(long int**)malloc(p*sizeof(long int*));
	for(int i=0;i<p;i++)
		c[i]=(long int*)malloc(q*sizeof(long int));
	for(int i=0;i<p;i++)
		for(int j=0;j<q;j++)
		{
			scanf("%d",&b[i][j]);
			c[i][j]=0;
		}
	if(p==m&&q==n)
	{
		#pragma omp parallel for
		for(int i=0;i<n;i++)
		{	
			#pragma omp parallel for
			for(int j=0;j<q;j++)
			{
				c[i][j]=0;
				for(int r=0;r<m;r++)
					c[i][j]+=a[i][r]*b[r][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<q;j++)
				printf("%lu ",c[i][j]);
			printf("\n");
		}
	}
	else
		printf("0\n");//matrices can't be multiplied
	return 0;
}
