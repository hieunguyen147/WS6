// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB

#ifndef OOP_WORD_H
#define OOP_WORD_H
#include"Utils.h"

namespace sdds {
    const int MAX_WORD_LEN = 21;
    const int MAX_NO_OF_WORDS = 500;
    const int SORT_BY_OCCURANCE = 1;
    const int SORT_ALPHABETICALLY = 0;

    struct Word {
        char letters[MAX_WORD_LEN];
        int count;
    };

    int searchWords(const Word words[], int num, const char word[]);
    void addWord(Word words[], int* index, const char newWord[]);
    void title(const char* value, int len); // uses iomanip header file
    void endList();
    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
    void print(const Word* w, bool gotoNextLine, int len);// uses iomanip header file
    int findMaxLen(const Word words[], int noOfWords);
    void listWords(const Word words[], int noOfWords, const char* theTitle);
    void swap(Word* p1, Word* p2);
    void sort(Word words[], int cnt, int sortType);
    int totalCount(const Word* words, int num);
    void wordStats();
    void programTitle();
}
#endif // !OOP_WORD_H
