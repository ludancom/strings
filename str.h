#include <stddef.h>

#ifndef STR_INCLUDED
#define STR_INCLUDED

/*--------------------------------------------------------------------*/
/* takes a null-terminated string and return the length of the string */

size_t Str_getLength(const char* strIn);

/*--------------------------------------------------------------------*/
/* takes in a char pointer to a destination for the final string, as 
well as a char pointer to a null-terminated string. it copies that string
to the destination and returns the copied string. Doesnt have to perform
bound checking for implementation using array */

char* Str_copy(char* destination, const char* strIn);

/*--------------------------------------------------------------------*/
/*  concatenates the destination string and the strIn string, then stores
the result in the destination string */

char* Str_concat(char* destination, const char* strIn);

/*--------------------------------------------------------------------*/
/*  compares two strings character by character. If the two strings are
equal, it returns 0. if the first non-matching character in str1 
is greater (in ASCII) than that of str2, return >0. if str2 is greater 
that str1, it returns <0. if one string reaches the  null terminator 
before the other and they are equal leading up to that, the longer string 
is considered larger*/

int Str_compare(const char* str1, const char* str2);

/*--------------------------------------------------------------------*/
/* returns the first occurance of a substring of str2 within string 1.
returns null if no match is found. If the substring string is empty, return 
the original string*/

char* Str_search(const char* str, const char* strInside);

/*--------------------------------------------------------------------*/

#endif