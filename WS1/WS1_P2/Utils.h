// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB

#include<cstdio>
#define _CRT_SECURE_NO_WARNINGS

void clearKeyboard(void);                //clear buffer
int getInt(void);	                     //validate Int
int getIntInRange(int min, int max);     //validate min, max
void startTitle();                       // Welcome statement
void endTitle();                         // End statement
double arrAverage(int arr[], int size);
int filter(int arr[], int size);
void sort(int a[], int b);