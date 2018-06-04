/*
 * Progam to add to arrays of numbers in a parallel fashion
 * Compile using: "g++ matadd.cpp -fopenmp"
 * Requirements:OpenMP should be installed
 *
 * Created By Yashasvi Goel
 * Dated: 06/04/18
 * Input the size of First array
 * Followed by the Array
 * Repeat for Second array
 * 
 */
#include<stdlib.h>
#include<stdio.h>
#ifdef _OPENMP
	#include<omp.h>
#else
	printf("ERROR",return);	
#endif

int main()
{
	int m,n;
	scanf("%d %d",&m,&n);//size of first array
	int **a=(int**)malloc(m*sizeof(int*));
	for(int i=0;i<m;i++)
		a[i]=(int*)malloc(n*sizeof(int));
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	int p,q;
	scanf("%d %d",&p,&q);//size of second array
	int **b=(int**)malloc(p*sizeof(int*));
	for(int i=0;i<p;i++)
		b[i]=(int*)malloc(q*sizeof(int));
	for(int i=0;i<p;i++)
		for(int j=0;j<q;j++)
			scanf("%d",&b[i][j]);
	if(p==m&&q==n)
	{
		int **c=(int**)malloc(m*sizeof(int*));
		for(int i=0;i<m;i++)
			c[i]=(int*)malloc(n*sizeof(int));
		#pragma omp parallel for
		for(int i=0;i<m;i++)
		{
			#pragma omp parallel for
			for(int j=0;j<n;j++)
			{
				c[i][j]=a[i][j]+b[i][j];
			}			
		}
	}
	return 0;
}
