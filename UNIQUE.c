#include<stdio.h>
int main()
{
	
	int a[] = {1,2,1,4,2,1,4,2,4,3,5,2,3,5,3,2,2,5,3,1,1,1};
	//int b[n];
	int n = sizeof(a)/sizeof(a[0]);//求数组的长度
	//int count = 0;
	int i,j; 
	for(i=0;i<n;i++)
	{
		int k = a[i];
		for(j=i+1;j<n;j++)
		{
			if(k==a[j])//判断数组中是否有重的元素
			{
				int k;
				for(k=j;k<n-1;k++)
				{
					a[k] = a[k+1];
				} 
				n--;
				j--;//这一步非常重要，没有的话部分结果就会不正确
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
