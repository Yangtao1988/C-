#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>



int main()
{
	system("color 02");
	#if 0		//�ַ�����������
	char name[20];
	int age;

	printf("what's your name?\n");
	//scanf("%s", &name);
	fgets(name, 20, stdin);
	name[strlen(name) - 1] = '\0';

	printf("how old are you?\n");
	scanf("%d", &age);

	printf("hello,%s, you are %d years old.\n", name, age);
	#endif

#if 0			//�ַ��Ƚϼ���������
	char str1[] = "YYYY";
	char str2[] = "YYYYao";

	strlwr(str1);						//Сдת��
	strupr(str1);						//��дת��
	strcat(str1, str2);					//�ַ�ȫ������
	strncat(str1, str2, 3);				//�ַ�����ǰn��
	strcpy(str1, str2);					//�ַ�ȫ������
	strncpy(str1, str2, 4);				//����ǰn��,��2���ȱ�1С��ʣ���Ϊԭ��1���ַ�

	strset(str1, 'y');					//�ַ�ȫ������Ϊ
	strnset(str1, 'y', 2);				//�ַ�����n������
	strrev(str1);						//�ַ���ת

	int result;
	result = strlen(str1);				//�ַ�����
	result = strcmp(str1, str2);		//�ַ��Ƚϣ���ͬΪ0������Ϊ1��С��Ϊ-1
	result = strncmp(str1, str2, 4);	//�Ƚ�ǰn���ַ�
	result = strcmpi(str1, str2);		//�ַ������ټ�����Ƿ���ͬ
	result = strnicmp(str1, str2, 3);	//n���ַ����ļ�����Ƿ���ͬ

	printf("str1: %s\tstr2:%s\tresult:%d", str1, str2, result);
	#endif

#if 0			//2ά���ּ��ַ�����
	int num[][3] = {1,2,3,4,5,6};
	char str[][10] = {"yang","tao","tao"};
	int rows = sizeof(num) / sizeof(num[0]);
	int cols = sizeof(num[0]) / sizeof(num[0][0]);

	for (size_t i = 0; i < sizeof(num)/sizeof(num[0]); i++)
	{
		for (size_t j = 0; j < sizeof(num[0])/sizeof(num[0][0]); j++)
		{
			printf("%d ",num[i][j]);
		}
		printf("\n");
	}

	for (size_t i = 0; i < sizeof(str)/sizeof(str[0]); i++)
	{
		printf("%s ",str[i]);
	}
	#endif
	
#if 0			//ð������
	int array[] = {1,3,5,7,4,2,9,8,6,0};
	int len = sizeof(array)/sizeof(array[0]);

	for (size_t i = 0; i < len - 1; i++)
	{
		for (size_t j = 0; j < len - i - 1; j++)
		{
			if (array[j] < array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	for (size_t i = 0; i < len; i++)
	{
		printf("%d ",array[i]);
	}
	#endif

#if 0			//���������
	srand((unsigned int)time(0));
	int MAX = 100;
	int MIN = 1;
	int num = (rand() % MAX) + MIN;
	printf("%d", num);
#endif

#if 0			//��ά����
	char questions[][100] = {"1. what year did c?",
							 "2.who is create c?",
							 "3.what is pre c?"};
	char options[][100] = {"A.1969","B.1972",
						   "A.Denis","B.Doc",
						   "A.Obj c","B.C++"};
	char answers[3] = {'B','A','B'};
	
	int numberOfQuestions = sizeof(questions)/sizeof(questions[0]);
	char guess;
	int score = 0;
	printf("Game start:\n");

	for (size_t i = 0; i < numberOfQuestions; i++)
	{
		printf("****************************\n");
		printf("%s\n",questions[i]);
		printf("****************************\n");

		for (size_t j = (i*2); j < (i*2)+2; j++)
		{
			printf("%s\t",options[j]); 
		}
		printf("\nenter your answer:");
		scanf("%c",&guess);
		scanf("%c");
		guess = toupper(guess);
		if (guess == answers[i])
		{
			printf("Correct!\n");
			score++;
		}
		else
		{
			printf("Wrong!\n");
		}
	}
	
	printf("Your score:%d/%d\n",score,numberOfQuestions);
#endif

#if 0			//�ļ���������ȡ
	//�����ļ���д��
	//FILE* pF = fopen("test.txt","a");
	FILE* pw = fopen("D:\\VSCode\\LeetCode\\C01\\test.txt","a");
	fprintf(pw,"lu lu lu!\n");
	fclose(pw);

	//�Ƴ��ļ�
	if (remove("test.txt") == 0)
	{
		printf("remove success\n");
	}
	else
	{
		printf("remove fail!\n");
	}

	//��ȡ�ļ�
	FILE* pr = fopen("test.txt","r");
	char buffer[255];

	if (pr == NULL)
	{
		printf("open fail\n");
	}
	else
	{
		while (fgets(buffer,255,pr) != NULL)
		{
			printf("%s",buffer);
		}
	}
	fclose(pr);
#endif
	
	
	



	return 0;
}