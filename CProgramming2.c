/* 2015-06-21 */

#include <stdio.h>

void Question1();
void Question1_OddPrint(int []);
void Question1_EvenPrint(int []);
void Question2();
void Question3();
void Question4();
void Question5();

int main(){

	int Question;

	while (1) {

		printf("1. Odd and Even\n");
		printf("2. Decimal To Binary\n");
		printf("3. First Odd, Last Even\n");
		printf("4. Palindrome\n");
		printf("5. Buuble Sort\n");

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

		default:

			printf("Incorrect Number\n");

			Question = 0;
		}

		printf("\n\n");
	}

	return 0;
}

void Question1() {

	int input;
	int arr[10];
	int i = 0;

	printf("Input Ten Number\n");

	for (i = 0; i < 10; i++) {

		scanf("%d", arr + i);
	}

	Question1_OddPrint(arr);
	Question1_EvenPrint(arr);

	printf("\n");
}

void Question1_OddPrint(int arr[]) {
	
	int i = 0;
	
	printf("Odd Number : ");

	for (i = 0; i < 10; i++) {

		if (arr[i] % 2 == 1) {

			printf("%d ", arr[i]);
		}
	}
}

void Question1_EvenPrint(int arr[]) {

	int i = 0;

	printf("Even Number : ");

	for (i = 0; i < 10; i++) {

		if (arr[i] % 2 == 0) {

			printf("%d ", arr[i]);
		}
	}
}

void Question2() {

	int decimal = 0;
	int binary = 0;
	int k = 0;
	int temp = 1;
	int i = 0;
	int mult = 1;

	printf("Dec To Bin\n");
	printf("Input Decimal : ");
	scanf("%d", &decimal);

	while (1){

		while (1) {

			if (temp > decimal) {

				temp /= 2;
				k--;
				break;
			}

			temp *= 2;
			k++;
		}
		
		for (i = 0; i < k; i++) {

			mult *= 10;
		}

		binary += mult;
		decimal -= temp;
		temp = 1;
		k = 0;
		mult = 1;
			
		if (decimal <= 0) {

			break;
		}
	}

	printf("%d\n", binary);
}

void Question3() {
	
	int input;
	int arr[10];
	int saveArr[10];
	int i, j, k;

	printf("Input Ten Number\n");

	for (i = 0; i < 10; i++) {

		scanf("%d", arr + i);
	}

	for (i = 0, j = 0, k = 0; i < 10; i++) {

		if (arr[i] % 2 == 1) {

			saveArr[j] = arr[i];
			j++;
		}

		else {

			saveArr[9 - k] = arr[i];
			k++;
		}
	}

	for (i = 0; i < 10; i++) {

		printf("%d ", saveArr[i]);
	}

	printf("\n");
}

void Question4() {

	int i = 0;
	char arr[100];
	int length;

	for (i = 0; i < 100; i++) {

		arr[i] = NULL;
	}

	scanf("%s", arr);

	for (i = 99; i > -1; i--) {

		if (arr[i] != NULL) {

			length = i + 1;
			break;
		}
	}


	for (i = 0; i < length / 2; i++) {

		if (arr[length - 1 - i] != arr[i]) {

			printf("No Palindrome\n");
			break;
		}
	}

	printf("Palindrome\n");
}

void Question5() {

	int arr[5] = { 4, 3, 5, 1, 2 };
	int i, j;
	int n = 5;
	int temp = arr[0];

	for (i = 0; i < n; i++) {

		for (j = 0; j < n - 1 - i; j++) {

			if (arr[j] > arr[j + 1]) {

				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < n; i++) {

		printf("%d ", arr[i]);
	}

	printf("\n");
}
