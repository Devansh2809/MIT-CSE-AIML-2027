#include <stdio.h>
#include <stdbool.h>
void main()
{
	int n;
	printf("Enter number of numbers to check");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int opc=0;

	for(int i=0;i<n;i++)
	{	bool flag=false;
		for(int j=0;j<n-i-1;j++)
		{	opc++;
			if(arr[j]>arr[j+1])
			{	
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=true;
			}
		}
		if(flag==false)
		{
			break;
		}
	}
	printf("Opcount:%d\n",opc);
	printf("New array\n");
	for(int i=0;i<n;i++)
	printf("%d ",arr[i]);
	printf("\n");
}