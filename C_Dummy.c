#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char* drink1 = "ȯŸ(������)", * drink2 = "�ݶ�", * drink3 = "���̴�", * drink4 = "��Ű��", * drink5 = "����", * drink6 = "�ֽĽ�";
	int num1 = 1, num2 = 2, num3 = 3, num4 = 4, num5 = 5, num6 = 6;
	printf("|\t\t�Ѽ����б� ���а� ���Ǳ�\t\t|\n\n");
	printf("| 1.%5s \t 2.%5s \t 3.%5s | \n", drink1, drink2, drink3);
	printf("| 4.%5s \t\t 5.%5s \t 6.%5s | \n", drink4, drink5, drink6);

	int i = 0;
	int drink = 0, num = 0;
	char* drink_name = 0;

	while (1)
	{
		do
		{
			//����� ��ȣ �Է¹ޱ�, 0�Է½� ���� / 6 �̻� �Է½� �ȳ� ���� ��� 
			printf("����� ��ȣ[0 �Է½� ����] : ");
			scanf("%d", &drink);
			if (drink > 6) {											//6 �̻��� ���� �Է��� ���  
				printf("6������ ���� ���� �Է����ּ���!!!!!\n");	//�ȳ� ���� ��� 
				continue;											//do-while���� ù��° �ٷ� ���ư� 
			}
			if (drink == 0)											//����� ��ȣ�� 0�� �Է��� ��� 
				return 0;											//���α׷� ���� 

			printf("����� ����[0 ���� ū �� ] : ");
			scanf("%d", &num);
			printf("\n");

			if (num <= 0)
				continue;

		} while (drink > 6 || num <= 0);								//����� ��ȣ�� 6 ����, ����� ������ 0�� �ƴ� �� �ݺ��� �������� 

		switch (drink)
		{
		case 1: drink_name = drink1; break;
		case 2: drink_name = drink2; break;
		case 3: drink_name = drink3; break;
		case 4: drink_name = drink4; break;
		case 5: drink_name = drink5; break;
		case 6: drink_name = drink6; break;
		}

		printf(">>>>>>>>>>>�����Ͻ� ���� : %s. ���� : %d\n", drink_name, num);
		for (i = 0; i < num; i++) {
			printf("%d.%s  ", i + 1, drink_name);
		} printf("\n");
		printf("��� �Ϸ�!!\n");
	}

	return 0;
}
