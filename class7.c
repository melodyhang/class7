#include<stdio.h>
#include<stdlib.h>
#include<string.h>	//֧���ַ�������
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
# define MAX 6	//����MAX��ʾϵͳҪ��������������

int main()
{
	/*
	int i;
	int j;
	//��λ����
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
	*/



	/*
	ʹ�ÿ���̨��дһ��С��Ϸ�ֱ�ʵ�����¹��ܣ�
		��������	�޸�����	��ѯ����	��������
	��Ϸ����
	1����Ϸһ������10��
	2��ÿ�����øжȣ�һ�������������ϵ������øжȵ���60���������ң�
	��Ϸ����
	*/
	//��������
	/*PlaySound(TEXT("bgm\\��������.wav"),
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("pause");
	*/
	int i,j,temp;
	int count = 5;		//��ǰδ�����乬�������ĸ���
	//ʹ���ַ������ʾ�ַ���
	char emperoName[50];	//�ʵ۵�����
	int choice;				//�ʵ۵�ѡ��1-4
	char tempName[50];		//���������ʱ�ַ������ַ�����
	int searchIndex = -1;	//������Ų��ҵ�Ԫ�ص��±�

							
							//��������������
	char names[MAX] [50] = { "����","����","��֪����","��ʩ","���¸�" };
	//�����ļ�������
	char levelName[5][10] = { "����","����","����","�ʹ���","�ʺ�" };
	//�������ÿλ���ӵļ���ÿ������Ԫ�ض�Ӧÿ�����ӵ�ǰ�ĵȼ�
	int levels[MAX] = { 1,2,0,0,0,-1 };
	//loves�����е�ÿ��Ԫ�ض�Ӧÿ�����ӵĺøжȣ���ʼ�����ÿ�����ӵĺøжȶ�Ϊ100
	int loves[MAX] = { 100,100,100,100,100 };
	PlaySound(TEXT("bgm\\��������.wav"),
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);


	printf("\n******************************************\n");
	printf("���Դ��룬�鿴��ǰ������״̬\n");
	printf("%-12s%-12����\t�øж�\n","����");
	for (i = 0; i < count; i++)
	{
		printf("%-12s%s\t%d\n", names[i], levelName[levels[i]], loves[i]);
	}
	printf("\n******************************************\n");




	printf("�����뵱ǰ�ǻ��ĻƵ����ţ�");
	gets(emperoName);	//¼���ַ���ʱ������Ҫ&����
	printf("�Ƶۣ�%s�����٣��������࣬�����˳���\n", emperoName);
	printf("1���Ƶ���ּѡ����\t�����ӹ��ܣ�\n");
	printf("2�����Ƴ��ң�\t\t���޸�״̬���ܣ�\n");
	printf("3�������乬��\t\t��ɾ�����ܣ�\n");
	printf("4�������ټ�����ȥС������������¡�\n");
	printf("������ѡ��");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:	//1���Ƶ���ּѡ����\t\t�����ӹ��ܣ�
		//1����������Ԫ�أ�names��loves��levels��
		//2������ǰҪ�ж�������û�пռ�
		PlaySound(TEXT("bgm\\ѡ��.wav"),
			NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if (count < MAX)//�����ǰ����������С��ϵͳ�����ֵ
		{
			//ִ����Ӳ���
			printf("��������������䣺");
			scanf_s("%s", names[count], 50);
			//����count��Ԫ�ص�״̬��ʼ��
			levels[count] = 0;	//�����ʼΪ0
			loves[count] = 100;	//�øжȳ�ʼΪ0
			count++;			//�����Ԫ�غ�ǵü�����+1
		}
		else
		{
			printf("���£�Ҫע�����尡�����Ѿ�����Ϊ���ˣ�\n���ʧ�ܣ�\n");
		}
		break;
	case 2://���Ƴ��ң�\t\t���޸�״̬���ܣ�
		//1���ҵ�Ҫ�������ӵ��±�
		//2���޸�������ӵ�״̬   �øж�+10   ������һ���������߼��Ͳ�������
		//3���޸��������ӵ�״̬   �øж�-10
		//��Ҫ�����bug��δ֧�����������ڵ�������������Բ����
		PlaySound(TEXT("bgm\\����.wav"),
			NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		printf("���£�������Ҫ���췭����������䣺");
		scanf_s("%s", tempName, 50);
		//�ַ����Ĳ���strcmp����Ҫ����<string.h>
		//strcmp(tempName,"abc")	0-�����ַ�����ȣ�1-ǰһ�����ں�һ����-1-ǰһ��С�ں�һ��
		
		for (i = 0; i < count; i++)
		{
			if (strcmp(tempName, names[i]) == 0)	//�������������պõ��������е�ĳ������
			{
				loves[i] += 10;
				//�ر�Ҫע�⣬���ܳ���5����0-4֮�䣩
				levels[i] = levels[i] >= 4 ? 4 : levels[i] + 1;
			}
			else
			{
				loves[i] -= 10;
			}
		}

		break;
	case 3://�����乬����ɾ�����ܣ�
		//1.����
		//2.����һ������ǰ��һ��Ԫ��
		//3.����
		//4.�޸��������ӵ�״̬���øж�+20
		PlaySound(TEXT("bgm\\�乬.wav"),
			NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		printf("���£�������Ҫ�����乬��������");
		scanf_s("%s", tempName, 50);
		for (i = 0; i < count; i++)
		{
			if (strcmp(tempName, names[i]) == 0)	//�Ƚ��ַ����Ƿ����
			{
				//��¼��Ҫ���ҵ��±�
				searchIndex = i;
				break;
			}
		}
		if (-1 == searchIndex)	//���searchindex��ֵδ��ֵ-1����ʾû���ҵ�
		{
			printf("�龪һ�������˴����乬���óԳԸúȺȡ�\n");
		}
		else
		{
			for (i = searchIndex; i < count - 1; i++)
			{
				//names[i] = names[i + 1];	//��Ϊ���ַ����飬c���Բ�֧�������ֱ�Ӹ�ֵ
				//������Ҫʹ��strcpy����ʵ������ĸ�ֵ
				strcpy_s(names[i],50, names[i + 1],50);
				loves[i] = loves[i + 1];
				levels[i] = levels[i + 1];
			}
			count--;
		}
		break;
	case 4:	//�����ټ�����ȥС������������¡�
		//1.����
		//2.���Ӻøжȼ���
		//3.����ʹ���������ʫ�裬ʹ��������ֵķ�ʽ�����ֻʵ۵��Ĳ�
		PlaySound(TEXT("bgm\\һЦ���.wav"),
			NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		printf("4�������ټ�����ȥС������������¡�\n");
		break;
	defult:
		printf("����Ϸ�ԣ��������ٴ�ȷ�ϣ�");
	}
	//����ӡ��������״̬ǰ���Լ����������,ʹ��ð������
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++);
		{
			if (levels[j] < levels[j + 1])
			{
				//��Ҫ��������������ͺøж�
				temp = levels[j];
				levels[j] = levels[j + 1];
				levels[j + 1] = temp;
				temp = loves[j];
				loves[j] = loves[j + 1];
				loves[j + 1] = temp;
				//ע���ַ����Ľ���
				strcpy_s(tempName, 50, names[i], 50);
				strcpy_s(names[i], 50, names[i+1], 50);
				strcpy_s(names[i+1], 50, tempName, 50);
			}
		}
	}
	printf("\n******************************************\n");
	printf("���Դ��룬�鿴��ǰ������״̬\n");
	printf("%-12s%-12����\t�øж�\n", "����");
	for (i = 0; i < count; i++)
	{
		printf("%-12s%s\t%d\n", names[i], levelName[levels[i]], loves[i]);
	}
	printf("\n******************************************\n");
	return 0;
}