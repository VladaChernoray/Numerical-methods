#include<stdio.h>
#include<math.h>
void printline(int k)		//Function to print a mergin line
{
	int i;
	for(i=1;i<=k;i++)
	{
		printf("_");
	}
	printf("\n");
}
float read(float x[][10],int a)		//Function to read an square matrix of order 'a'
{
	int i,j;
	printf("Enter %d entries = ",a*a);
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=a;j++)
		{
			scanf("%f",&x[i][j]);
		}
	}
}
float write(float x[][10],int a)	//Function to print an square matrix of order 'a'
{
	int i,j;
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=a;j++)
		{
			printf("%f\t",x[i][j]);
		}
		printf("\n");
	}
}
float trans(float a[][10],int n,float b[][10])	//Function to transpose an square matrix of order 'n'
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			b[i][j]=a[j][i];
		}
	}
}
float mul(float x[][10],float y[][10],int n,float s[][10])	//Function for square matrix (of order 'n') multiplication
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			s[i][j]=0;
			for(k=1;k<=n;k++)
			{
				s[i][j]=s[i][j]+x[i][k]*y[k][j];
			}
		}
	}
}
float cons(float C,float S,int n,int l,int k,float a[][10])	//Function to construct an orthogonal symmetric matrix followed from Jacobi Method's algorithm
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
			{
				a[i][j]=1;
			}
			if(i!=j)
                        {
				  a[i][j]=0;
                        }
		}
	}
	a[l][l]=C;
	a[l][k]=-S;
	a[k][l]=S;
	a[k][k]=C;
}
float STAS(float x[][10],float y[][10],int n,float r[][10])	//Function to compute matrix multiplication of type (S'A S), where S' means transpose of S
{
	float x1[10][10],r1[10][10];
	trans(x,n,x1);
	mul(x1,y,n,r1);
	mul(r1,x,n,r);
}
float fun(float r[][10],float b[][10],int n,float a[][10])	//Function to clear values of all unnecessary arrays to make computation procedure smooth
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]=r[i][j];
			r[i][j]=0;
			b[i][j]=0;
		}
	}
}

int main()
{
	int i,j,k,n,p,q,M;
	float a[10][10],b[10][10],r[10][10],A,B,C,S,big,t;
	printline(60);
	printf("Enter The order of the non-singular symmetric matrix : ");
	scanf("%d",&n);
	printline(60);
	read(a,n);
	printline(60);
	printf("The given non-singular symmetric matrix is :\n");
	write(a,n);
	printline(60);
	printf("Enter the number of iteration : ");
	scanf("%d",&M);
	for(k=1;k<=M;k++)
	{
		big=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i<j)
				{
					if(fabs(a[i][j])>big)
					{
						big=fabs(a[i][j]);
						p=i;
						q=j;
					}
				}
			}
		}
		if(a[p][p]<a[q][q])
		{
			t=-1;
		}
		else
		{
			t=1;
		}
		A=2*a[p][q]*t;
		B=fabs(a[p][p]-a[q][q]);
		C=pow(0.5*(1+(B/pow(A*A+B*B,0.5))),0.5);
		S=A/(2*C*pow(A*A+B*B,0.5));
		cons(C,S,n,p,q,b);
		STAS(b,a,n,r);
		fun(r,b,n,a);
	}
	printline(60);
	printf("The required eigen values are :\n");
	for(i=1;i<=n;i++)
	{
		printf("a%d%d = %f.\n",i,i,a[i][i]);
	}
	printline(60);
}

