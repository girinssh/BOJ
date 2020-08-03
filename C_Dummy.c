#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char* drink1 = "환타(오렌지)", * drink2 = "콜라", * drink3 = "사이다", * drink4 = "밀키스", * drink5 = "맥콜", * drink6 = "핫식스";
	int num1 = 1, num2 = 2, num3 = 3, num4 = 4, num5 = 5, num6 = 6;
	printf("|\t\t한성대학교 공학관 자판기\t\t|\n\n");
	printf("| 1.%5s \t 2.%5s \t 3.%5s | \n", drink1, drink2, drink3);
	printf("| 4.%5s \t\t 5.%5s \t 6.%5s | \n", drink4, drink5, drink6);

	int i = 0;
	int drink = 0, num = 0;
	char* drink_name = 0;

	while (1)
	{
		do
		{
			//음료수 번호 입력받기, 0입력시 종료 / 6 이상 입력시 안내 문구 출력 
			printf("음료수 번호[0 입력시 종료] : ");
			scanf("%d", &drink);
			if (drink > 6) {											//6 이상의 값을 입력한 경우  
				printf("6번보다 작은 수를 입력해주세요!!!!!\n");	//안내 문구 출력 
				continue;											//do-while문의 첫번째 줄로 돌아감 
			}
			if (drink == 0)											//음료수 번호에 0을 입력한 경우 
				return 0;											//프로그램 종료 

			printf("음료수 갯수[0 보다 큰 값 ] : ");
			scanf("%d", &num);
			printf("\n");

			if (num <= 0)
				continue;

		} while (drink > 6 || num <= 0);								//음료수 번호가 6 이하, 음료수 개수가 0이 아닐 때 반복을 빠져나감 

		switch (drink)
		{
		case 1: drink_name = drink1; break;
		case 2: drink_name = drink2; break;
		case 3: drink_name = drink3; break;
		case 4: drink_name = drink4; break;
		case 5: drink_name = drink5; break;
		case 6: drink_name = drink6; break;
		}

		printf(">>>>>>>>>>>선택하신 음료 : %s. 개수 : %d\n", drink_name, num);
		for (i = 0; i < num; i++) {
			printf("%d.%s  ", i + 1, drink_name);
		} printf("\n");
		printf("출력 완료!!\n");
	}

	return 0;
}
