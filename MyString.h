#pragma once

unsigned int strLen(const char* str); // возвращает длину строки
void strCpy(char* dest, const char* source); // копирует вторую строку в первую (source -> destination)
void strCat(char* dest, const char* source); // объединяет две строки в одну. результат оказывается в dest
void strReverse(char* str); // разворот строки в обратную сторону
void strToUpper(char* str); // все символы представить в верхнем регистре
void strToLower(char* str); // в нижнем
int strStr(const char* str, const char* substr); // возвращает индекс первого вхождения подстроки substr в str, если вхождений нет, то -1
int strCmp(const char* str1, const char* str2); // возвращает 0, если равны, 1, если первая больше, -1 если вторая больше.