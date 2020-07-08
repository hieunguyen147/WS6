// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB

#include"Utils.h"
#define _CRT_SECURE_NO_WARNINGS

void clearKeyboard(void)
{
	while (getchar() != '\n');
}

int getInt(void)// Check INT
{
	int value;
	int done;
	do {
		char newLine;
		value = -1;
		scanf("%d%c", &value, &newLine);
		if (newLine != '\n')
		{
			clearKeyboard();
			if ((value >= 0))
				printf("Invalid trailing characters, try again: ");
			else
				printf("Invalid Number, try again: ");

			done = 1;
		}
		else
			done = 0;

	} while (done);

	return value;
}

int getIntInRange(int min, int max) //Check value Min max
{
	int done, value;
	do
	{
		value = getInt();
		if (value < min || value > max)
		{
			done = 1;
			printf("Invalid value (%d<=value<=%d), try again: ", min, max);
		}
		else
			done = 0;

	} while (done);

	return value;
}
double arrAverage(int arr[], int size) {
	int sum = 0;
	double avg;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	avg = (double)sum / size;
	return(avg);
}

int filter(int arr[], int size) {
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= 50)
			count++;
	}
	return count;
}

void sort(int a[], int size) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (a[i] < a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void startTitle() {
	printf("Mark Stats Program.\n\n");
}

void endTitle() {
	printf("Thank you...\n");
}
