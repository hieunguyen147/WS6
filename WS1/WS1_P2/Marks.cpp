// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB

#include"Marks.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;	

void markstat() {
	int numOfMarks, countPass;
	char assessmentName[20];
	double displayAvg;

	startTitle();														//Start Welcome and Input
	cout << "Please enter the assessment name: ";
	cin.getline(assessmentName,20);
	cout << "Please enter the number of marks: ";
	numOfMarks = getIntInRange(5, 50);
	int* marks = new int[numOfMarks];

	cout << "Please enter " << numOfMarks << " marks (0<=Mark<=100):" << "\n";
	
	for (int i = 0; i < numOfMarks; i++) {
		printf("%d> ", i + 1);
		marks[i] = getIntInRange(0, 100);
	}
	endTitle();															//End input

	cout << "Assessment Name: " << assessmentName << endl;	            //Start display Info
	cout << "----------------\n";
	sort(marks, numOfMarks);

	for (int i = 0; i < numOfMarks; i++) {
		printf("%d", marks[i]);
		if (i+1 < numOfMarks)
			printf(", ");
	}
	cout << "\n";
	displayAvg = arrAverage(marks, numOfMarks);
	cout << "Average: " << setprecision(1) << fixed << displayAvg << endl;
	countPass = filter(marks, numOfMarks);
	cout << "Number of Passing Marks: " << countPass << endl;		
	delete[] marks;                                                      //End display
}

