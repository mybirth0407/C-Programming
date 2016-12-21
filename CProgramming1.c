/* 2015-06-21 */

#include <stdio.h>

void Question1();
void Question2();
void Question3();
void Question4();
void Question5();
void Question6();
void Question7();
void Question8();


int main(){

	int Question;

	while (1) {

		printf("1. Decimal To Hexadecimal\n");
		printf("2. Time Tables\n");
		printf("3. GCD\n");
		printf("4. Algorithms\n");
		printf("5. Prime Number\n");
		printf("6. Second To Hour, Minute, Second\n");
		printf("7. 2^k <= n, k?\n");
		printf("8. 2^n recurtion\n\n");

		printf("Input Question Number ?\n");
		scanf("%d", &Question);

		switch (Question) {

		case 1:

			Question1();
			break;

		case 2:

			Question2();
			break;

		case 3:

			Question3();
			break;

		case 4:

			Question4();
			break;

		case 5:

			Question5();
			break;

		case 6:

			Question6();
			break;

		case 7:

			Question7();
			break;

		case 8:

			Question8();
			break;

		default:

			printf("Incorrect Number\n");

			Question = 0;
		}

		printf("\n\n");
	}

	return 0;
}

void Question1() {

	int num;

	printf("Dec to Hex\n");
	printf("Input Decimal : ");
	scanf("%d", &num);

	printf("%x\n", num);
}

void Question2() {

	int begin, end;
	int result;
	int mult = 1;

	printf("begin : ");
	scanf("%d", &begin);

	printf("end : ");
	scanf("%d", &end);

	result = end - begin;

	if (result < 0) {

		result = -result;

		begin = end;
		end = begin + result;
	}

	for (; begin < end + 1; begin++) {

		for (mult = 1; mult < 10; mult++) {

			printf("%d * %d = %d\n", begin, mult, begin*mult);
		}
	}
}

void Question3() {

	int input1, input2;
	int GCD;
	int temp;

	printf("input 1 : ");
	scanf("%d", &input1);

	printf("input 2 : ");
	scanf("%d", &input2);

	if (input1 < input2) {

		temp = input1;
		input1 = input2;
		input2 = temp;
	}

	for (GCD = 1; GCD < input2 + 1; GCD++) {

		if ((input1 % GCD) == 0 && (input2 % GCD) == 0) {

			temp = GCD;
		}
	}

	printf("%d\n", temp);
}

void Question4() {

	int creamPrice = 500, shrimpPrice = 700, cokePrice = 400;
	int creamNum = 0, shrimpNum = 0, cokeNum = 0;
	int money = 3500;

	printf("Now, You have 3500\n");

	for (cokeNum = 0; cokeNum < 9; cokeNum++) {

		for (creamNum = 0; creamNum < 8; creamNum++) {

			for (shrimpNum = 0; shrimpNum < 6; shrimpNum++) {

				money = 3500;
				money = money - (shrimpNum * shrimpPrice) - (creamNum * creamPrice) - (cokeNum * cokePrice);

				if (money < 0) {

					break;
				}

				if (money == 0) {

					printf("Creambread = %d, Shrimpsnack = %d, Coke = %d\n", creamNum, shrimpNum, cokeNum);
				}
			}
		}
	}
}

void Question5() {

	int primeNum = 2, div = 1;
	int count = 0;
	int temp;

	while (count < 10) {

		for (div = 1; div < primeNum; div++) {

			if (primeNum % div == 0) {

				temp = div;
			}
		}

		if (temp == 1) {

			printf("%d ", primeNum);
			count++;
		}

		primeNum++;
	}

	printf("\n");
}

void Question6() {

	int inputTime;
	int second = 0, minute = 0, hour = 0;

	printf("Input Time ? : ");
	scanf("%d", &inputTime);

	while (1) {

		if (inputTime >= 3600){

			inputTime -= 3600;
			hour++;
		}

		else {

			break;
		}
	}

	while (1) {

		if (inputTime >= 60){

			inputTime -= 60;
			minute++;
		}

		else {

			break;
		}
	}

	second = inputTime;

	printf("%d hours, %d minutes, %d seconds\n", hour, minute, second);
}

void Question7() {

	int n;
	int temp = 1;
	int k = 0;

	printf("Input Number = ");
	scanf("%d", &n);

	while (1) {

		temp *= 2;
		k++;

		if (temp > n) {

			k--;
			break;
		}
	}

	printf("2^k <= %d, k is %d\n", n, k);
}

void Question8() {

	int inputNum;
	int result = 1;
	int i = 0;

	printf("input 2^n, n is : ");
	scanf("%d", &inputNum);

	for (i = 0; i < inputNum; i++) {

		result *= 2;
	}

	printf("2^n = %d\n", result);
}
