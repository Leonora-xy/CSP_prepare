#include<stdio.h>
int main()
{
	
	int a[] = {1,2,1,4,2,1,4,2,4,3,5,2,3,5,3,2,2,5,3,1,1,1};
	//int b[n];
	int n = sizeof(a)/sizeof(a[0]);//������ĳ���
	//int count = 0;
	int i,j; 
	for(i=0;i<n;i++)
	{
		int k = a[i];
		for(j=i+1;j<n;j++)
		{
			if(k==a[j])//�ж��������Ƿ����ص�Ԫ��
			{
				int k;
				for(k=j;k<n-1;k++)
				{
					a[k] = a[k+1];
				} 
				n--;
				j--;//��һ���ǳ���Ҫ��û�еĻ����ֽ���ͻ᲻��ȷ
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
