#include<stdio.h>
#include<stdlib.h>
//#include<Windows.h>
//#include<mmsystem.h>
//#pragma comment(lib,"Winmm.lib")
# define MAX 6	//常量MAX表示系统要求的最大妃子数量

int main()
{
	/*
	int i;
	int j;
	//二位数组
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
	*/



	/*
	使用控制台编写一个小游戏分别实现以下功能：
		新增数据	修改数据	查询数据	数据排序
	游戏规则：
	1、游戏一共进行10天
	2、每天结算好感度，一旦有三个或以上的嫔妃好感度低于60，则发生暴乱，
	游戏结束
	*/
	//播放音乐
	/*PlaySound(TEXT("bgm\\背景音乐.wav"),
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("pause");
	*/
	int i;
	int count = 5;		//当前未打入冷宫的嫔妃的个数
	//使用字符数组表示字符串
	char emperoName[50];	//皇帝的名号
	int choice;				//皇帝的选择1-4
	//嫔妃的姓名数组
	char names[MAX][20] = { "貂蝉","杨玉环","不知火舞","西施","郭德纲" };
	//嫔妃的级别数组
	char levelName[5][10] = { "贵人","嫔妃","贵妃","皇贵妃","皇后" };
	//用来存放每位妃子的级别，每个数组元素对应每个妃子当前的等级
	int levels[MAX] = { 1,2,0,0,0,-1 };
	//loves数组中的每个元素对应每个妃子的好感度，初始情况，每个妃子的好感度都为100
	int loves[MAX] = { 100,100,100,100,100 };



	printf("\n******************************************\n");
	printf("测试代码，查看当前嫔妃的状态\n");
	printf("%-12s%-12级别\t好感度\n","姓名");
	for (i = 0; i < count; i++)
	{
		printf("%-12s%s\t%d\n", names[i], levelName[levels[i]], loves[i]);
	}
	printf("\n******************************************\n");




	printf("请输入当前登基的黄帝名号：");
	gets(emperoName);	//录入字符串时，不需要&符号
	printf("黄帝（%s）驾临，有事早奏，无事退朝！\n", emperoName);
	printf("1、黄帝下旨选妃；\t（增加功能）\n");
	printf("2、翻牌宠幸；\t\t（修改状态功能）\n");
	printf("3、打入冷宫！\t\t（删除功能）\n");
	printf("4、单独召见爱妃去小树林做纯洁的事。\n");
	printf("陛下请选择：");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:	//1、黄帝下旨选妃；\t\t（增加功能）
		//1、增加数组元素（names、loves、levels）
		//2、增加前要判断数组有没有空间
		if (count < MAX)//如果当前的妃子数量小于系统的最大值
		{
			//执行添加操作
			printf("请输入娘娘的名讳：");
			gets( names[count] );
			//将第count个元素的状态初始化
			levels[count] = 0;	//级别初始为0
			loves[count] = 100;	//好感度初始为0
			count++;			//添加完元素后记得计数器+1
		}
		else
		{
			printf("陛下，要注意龙体啊，后宫已经人满为患了！\n添加失败！\n");
		}
		break;
	case 2:
		printf("2、翻牌宠幸；\t\t（修改状态功能）\n");
		break;
	case 3:
		printf("3、打入冷宫！\t\t（删除功能）\n");
		break;
	case 4:
		printf("4、单独召见爱妃去小树林做纯洁的事。\n");
		break;
	defult:
		printf("君无戏言，陛下请再次确认！");
	}
	printf("\n******************************************\n");
	printf("测试代码，查看当前嫔妃的状态\n");
	printf("%-12s%-12级别\t好感度\n", "姓名");
	for (i = 0; i < count; i++)
	{
		printf("%-12s%s\t%d\n", names[i], levelName[levels[i]], loves[i]);
	}
	printf("\n******************************************\n");
	return 0;
}