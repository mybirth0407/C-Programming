/* 2015-06-24 */

#include <stdio.h>
#include <malloc.h>

void Question1();
void Question2();
void Question3();
void Question4();
void Question5();
void Question6();
void Question7();

typedef struct _bookInfo {

	char bookName[30];
	char bookAuthor[20];
	int page;
} bookInfo;

typedef struct _complexNumber {

	double realNumber;
	double imaginaryNumber;
} complexNumber;

typedef struct _contact {

	char name[20];
	char number[20];
} contact;

int main() {

	int Question;

	while (1) {

		printf("1. Book Management\n");
		printf("2. Book Management with Malloc\n");
		printf("3. Complex Number\n");
		printf("4. Word Count\n");
		printf("5. TextFile Compare\n");
		printf("6. AddressBook\n");
		printf("7. AddressBook with File I/O\n");

		printf("\nInput Question Number ?\n");
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

		default:

			printf("Incorrect Number\n");

			Question = 0;
		}

		printf("\n\n");
	}

	return 0;
}

void Question1() {

	bookInfo book[3];

	int i;

	for (i = 0; i < 3; i++) {

		printf("Input BookInfo\n");

		printf("Book Author : ");
		scanf("%s", &(book[i].bookAuthor));
		printf("Book Name : ");
		scanf("%s", &(book[i].bookName));
		printf("Page Count : ");
		scanf("%d", &(book[i].page));

		printf("\n");
		fflush(stdin);
	}

	for (i = 0; i < 3; i++) {

		printf("BookInfo Print\n");

		printf("Book Author : %s\n", book[i].bookAuthor);
		printf("Book Name : %s\n", book[i].bookName);
		printf("Book Page : %d\n", book[i].page);

		printf("\n");
	}
}

void Question2() {

	bookInfo *book[3];

	int i;

	for (i = 0; i < 3; i++) {

		book[i] = (bookInfo *)malloc(sizeof(bookInfo));
		printf("Input BookInfo\n");

		printf("Book Author : ");
		scanf("%s", book[i]->bookAuthor);
		printf("Book Name : ");
		scanf("%s", book[i]->bookName);
		printf("Page Count : ");
		scanf("%d", &book[i]->page);

		printf("\n");
		fflush(stdin);
	}

	for (i = 0; i < 1; i++) {

		printf("BookInfo Print\n");

		printf("Book Author : %s\n", book[i]->bookAuthor);
		printf("Book Name : %s\n", book[i]->bookName);
		printf("Book Page : %d\n", book[i]->page);

		printf("\n");
	}
}

void Question3() {

	complexNumber input[2];
	complexNumber addResult, multResult;

	int i;

	for (i = 0; i < 2; i++) {

		printf("Complex Number Input [Real Imaginary] = ");
		scanf("%lf %lf", &input[i].realNumber, &input[i].imaginaryNumber);

		fflush(stdin);
	}

	addResult.realNumber = input[0].realNumber + input[1].realNumber;
	addResult.imaginaryNumber = input[0].imaginaryNumber + input[1].imaginaryNumber;

	printf("Add Result - Real : %lf, Imaginary : %lf\n", addResult.realNumber, addResult.imaginaryNumber);

	multResult.realNumber = (input[0].realNumber * input[1].realNumber) - (input[0].imaginaryNumber * input[1].imaginaryNumber);
	multResult.imaginaryNumber = (input[0].realNumber * input[1].imaginaryNumber) + (input[0].imaginaryNumber * input[1].realNumber);

	printf("Multiple Result - Real : %lf, Imaginary : %lf\n", multResult.realNumber, multResult.imaginaryNumber);
}

void Question4() {

	FILE *fp = fopen("text.txt", "rt");

	char temp[100];

	int countA, countP;

	while (fscanf(fp, "%s", temp) != EOF) {

		if (temp[0] == 'A') {

			countA++;
		}

		else if (temp[0] == 'P') {

			countP++;
		}
	}

	fseek(fp, 0, SEEK_SET);
	fclose(fp);
	printf("A~ Words Count : %d\nP~ Words Count : %d\n", countA, countP);
}

void Question5() {

	FILE *d1 = fopen("d1.txt", "rt");
	FILE *d2 = fopen("d2.txt", "rt");

	while (1) {

		if (feof(d1) != 0) {

			printf("The Two Files are Perfectly Same\n");
			break;
		}

		else if (fgetc(d1) != fgetc(d2)) {

			printf("The Two Files are Not Same\n");
			break;
		}
	}

	fclose(d1);
	fclose(d2);
}

void Question6() {

	contact contactSave[100];

	int item;
	int countContact = 1;
	int count = 0;
	int i;
	int n;

	char name[20];
	char number[20];

	while (1) {

		printf("*****MENU****\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Print All Data\n");
		printf("5. Exit\n");

		printf("Choose the item : ");
		scanf("%d", &item);

		switch (item) {

		case 1:

			printf("[ INSERT ]\n");
			printf("Input Name : ");
			scanf("%s", name);
			printf("Input Tel Number : ");
			scanf("%s", number);

			strcpy(contactSave[count].name, name);
			strcpy(contactSave[count].number, number);

			count++;
			countContact++;

			printf("\t\t Data Inseted\n");
			break;

		case 2:

			printf("[ DELETE ]\n");
			printf("Input Name for Delete : ");
			scanf("%s", name);

			for (n = 0; n < count; n++) {

				if (!strcmp(contactSave[n].name, name)) {

					for (i = n; i < count; i++) {

						contactSave[i] = contactSave[i + 1];
					}
				}
			}
			count--;
			countContact--;

			printf("\t\t Data Deleted\n");
			break;

		case 3:

			printf("[ Search ]\n");

			printf("Input Name for Search : ");
			scanf("%s", name);

			for (n = 0; n < count; n++) {

				if (!strcmp(contactSave[n].name, name)) {

					printf("Name : %s\t Tel : %s\n", contactSave[n].name, contactSave[n].number);
				}
			}

			printf("\t\t Data Searched\n");
			break;


		case 4:

			printf("[ Print All Data ]\n");

			for (i = 0; i < count; i++) {

				printf("Name : %s\t Tel : %s\n", contactSave[i].name, contactSave[i].number);
			}

			printf("\t\t Print All data\n");
			break;

		case 5:

			printf("\n");
			printf("Bye");
			break;

		default:

			printf("Incorrect Item\n");
			break;
		}

		printf("\n");

		if (item == 5) {

			break;
		}
	}
}

void Question7() {

	FILE *fp = fopen("data.txt", "wt");

	contact contactSave[100];

	int item;
	int countContact = 1;
	int count = 0;
	int i;
	int n;

	char name[20];
	char number[20];

	while (1) {

		printf("*****MENU****\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Print All Data\n");
		printf("5. Exit\n");

		printf("Choose the item : ");
		scanf("%d", &item);

		switch (item) {

		case 1:

			printf("[ INSERT ]\n");
			printf("Input Name : ");
			scanf("%s", name);
			printf("Input Tel Number : ");
			scanf("%s", number);

			strcpy(contactSave[count].name, name);
			strcpy(contactSave[count].number, number);

			count++;
			countContact++;

			printf("\t\t Data Inseted\n");
			break;

		case 2:

			printf("[ DELETE ]\n");
			printf("Input Name for Delete : ");
			scanf("%s", name);

			for (n = 0; n < count; n++) {

				if (!strcmp(contactSave[n].name, name)) {

					for (i = n; i < count; i++) {

						contactSave[i] = contactSave[i + 1];
					}

					count--;
					countContact--;

					printf("\t\t Data Deleted\n");
					break;
				}
			}

			if (n == countContact) {

				printf("\t\t Data Delete Failed\n");
			}

			break;

		case 3:

			printf("[ Search ]\n");

			printf("Input Name for Search : ");
			scanf("%s", name);

			for (n = 0; n < count; n++) {

				if (!strcmp(contactSave[n].name, name)) {

					printf("Name : %s\t Tel : %s\n", contactSave[n].name, contactSave[n].number);
					printf("\t\t Data Searched\n");
					break;
				}
			}

			if (n == countContact) {

				printf("\t\t Data Search Failed\n");
			}

			break;

		case 4:

			printf("[ Print All Data ]\n");

			for (i = 0; i < count; i++) {

				printf("Name : %s\t Tel : %s\n", contactSave[i].name, contactSave[i].number);

			}

			printf("\t\t Print All data\n");
			break;

		case 5:

			printf("\n");
			printf("Bye");
			break;

		default:

			printf("Incorrect Item\n");
			break;
		}

		printf("\n");

		if (item == 5) {

			for (i = 0; i < count; i++) {

				fprintf(fp, "Name : %s\t Number : %s\n", contactSave[i].name, contactSave[i].number);
			}

			fclose(fp);

			break;
		}
	}
}
