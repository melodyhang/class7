#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	int j;
	/*二位数组*/
	//使用二位数组表示学生的成绩表
	//4个学生有3门课成绩 - 4行 3列
	double scores[4][3] = {
		{98,67,89},
		{89,67,88},
		{99,77,60},
		{89,23,55}
	};
	printf("语文\t英语\t数学\n");
	//使用循环打印每个数组元素
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