#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	int j;
	/*��λ����*/
	//ʹ�ö�λ�����ʾѧ���ĳɼ���
	//4��ѧ����3�ſγɼ� - 4�� 3��
	double scores[4][3] = {
		{98,67,89},
		{89,67,88},
		{99,77,60},
		{89,23,55}
	};
	printf("����\tӢ��\t��ѧ\n");
	//ʹ��ѭ����ӡÿ������Ԫ��
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%-8.2lf", scores[i][j]);
		}
		printf("\n");
	}
	return 0;
}