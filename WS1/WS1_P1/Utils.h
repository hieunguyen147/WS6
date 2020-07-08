// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB

#ifndef OOP_UTILS_H
#define OOP_UTILS_H
#include <iomanip>
namespace sdds {
	char ToLower(char ch);
	int StrCmp(const char* s1, const char* s2);
	void StrCpy(char* des, const char* src);
	int StrLen(const char* str);
	bool isAlpha(char ch);
	void trim(char word[]);
	void toLowerCaseAndCopy(char des[], const char source[]);
}
#endif // !OOP_UTILS_H
