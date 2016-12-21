/* 2015-06-21 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Question1();
void Question2();
void Question3();
void Question4();
void Question5();
void Question6();

int main(){

	int Question;

	while (1) {

		printf("1. Rotation Two dimension Array\n");
		printf("2. Snail Array\n");
		printf("3. Random Number\n");
		printf("4. SeedRandom Number\n");
		printf("5. Rock, Scissors, Paper\n");
		printf("6. Baseball Game\n");

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

		default:

			printf("Incorrect Number\n");

			Question = 0;
		}

		printf("\n\n");
	}

	asdf();
	return 0;
}

void Question1() {

	int arr[4][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	int rotArr[4][4];
	
	int i, j, k;
	int n = 4;

	for (k = 0; k < n; k++){

		for (i = 0; i < n; i++) {

			for (j = 0; j < n; j++) {

				rotArr[j][3 - i] = arr[i][j];
				printf("%3d ", rotArr[j][3 - i]);
			}

			printf("\n");
		}

		for (i = 0; i < n; i++) {

			for (j = 0; j < n; j++) {

				arr[i][j] = rotArr[i][j];
			}
		}

		printf("\n");
	}
}

void Question2() {

	int snailArr[10][10];

	int i, j;
	int n;
	int k = 1;

	printf("Input n * n, n? : ");
	scanf("%d", &n);

	for (i = 0; i < n / 2; i++) {

		for (j = 0; j < n - 1 - (2 * i); j++) {

			snailArr[i][j + i] = k++;
		}

		printf("\n");

		for (j = 0; j < n - 1 - (2 * i); j++) {

			snailArr[j + i][n - 1 - i] = k++;
		}

		printf("\n");

		for (j = 0; j < n - 1 - (2 * i); j++) {

			snailArr[n - 1 - i][n - 1 - (j + i)] = k++;
		}

		printf("\n");

		for (j = 0; j < n - 1 - (2 * i); j++) {

			snailArr[n - 1 - (j + i)][i] = k++;
		}

		printf("\n");
	}

	if (n % 2 == 1) {

		snailArr[n / 2][n / 2] = k;
	}

	for (i = 0; i < n; i++) {

		for (j = 0; j < n; j++) {

			printf("%3d ", snailArr[i][j]);
		}

		printf("\n");
	}
}

void Question3() {

	int i;
	
	printf("Random Number Range : 0 to %d\n", RAND_MAX);
	
	for (i=0; i<5; i++) {
		
		printf("Random Number Print : %d\n", rand());
	}
	
	return 0;
}

void Question4() {

	int i;
	
	srand((int)time(NULL));
	
	for(i=0; i<5; i++) {
		
		printf("Integer Print : %d\n", rand());
	}

	return 0;
}

void Question5() {

	int computer;
	int user;

	int win, lose, draw;

	int i;

	srand((int)time(NULL));

	for (win = 0, lose = 0, draw = 0;;) {

		printf("Rock = 1, Scissors = 2, Paper = 3, User : ");
		scanf("%d", &user);

		computer = rand() % 3 + 1;

		if ((user == 1 && computer == 2) || (user == 2 && computer == 3) || (user == 3 && computer == 1)) {

			if (user == 1) {

				printf("You are Rock, And Computer is Scissors");
			}

			else if (user == 2) {

				printf("You are Scissors, And Computer is Paper");
			}

			else {

				printf("You are Paper, And Computer is Rock");
			}

			printf("	Result : Win\n");
			win++;
		}


		else if ((user == 1 && computer == 3) || (user == 2 && computer == 1) || (user == 3 && computer == 2)) {

			if (user == 1) {

				printf("You are Rock, But Computer is Paper");
			}

			else if (user == 2) {

				printf("You are Scissors, But Computer is Rock");
			}

			else {

				printf("You are Paper, But Computer is Scissors");
			}

			printf("	Result : Lose\n");
			lose++;
		}

		else {

			if (user == 1) {

				printf("You are Rock, And Computer is Too");
			}

			else if (user == 2) {

				printf("You are Scissors, And Computer is Too");
			}
			
			else {

				printf("You are Paper, And Computer is Too");
			}

			printf("	Result : Draw\n");
			draw++;
		}

		printf("Now Score : %d Win, %d Lose, %d Draw\n", win, lose, draw);

		if (win >= 4 || lose >= 4 || draw >= 4) {

			break;
		}
	}

	printf("\nGame Result : %d Win, %d Lose, %d Draw\n", win, lose, draw);
}

void Question6() {

	int strike = 0, ball = 0;
	int user[3];
	int computer[3];
	int count = 0;
	
	int i;

	printf("Start Game\n");

	srand((int)time(NULL));
	while (1) {

		count++;

		printf("Select Three Number : ");

		for (i = 0; i < 3; i++) {

			scanf("%d", user + i);
			computer[i] = rand() % 10;
		} 

		if (user[0] == computer[0] || user[0] == computer[1] || user[0] == computer[2]) {

			ball++;

			if (user[0] == computer[0]) {

				ball--;
				strike++;
			}
		}

		if (user[1] == computer[0] || user[1] == computer[1] || user[1] == computer[2]) {

			ball++;

			if (user[1] == computer[1]) {

				ball--;
				strike++;
			}
		}

		if (user[2] == computer[0] || user[2] == computer[1] || user[2] == computer[2]) {

			ball++;

			if (user[1] == computer[1]) {

				ball--;
				strike++;
			}
		}

		printf("%d Challange : %d strike, %d ball\n", count, strike, ball);

		if (strike == 3) {

			break;
		}

		printf("\n");
	}

	printf("Game over\n");
}
