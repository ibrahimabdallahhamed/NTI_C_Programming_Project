#ifndef STRING_H
#define STRING_H
#include "STDTYPES.h"
u32 my_strlength(const void *str1);
void my_strcpy(void *str1, const void *str2);
void my_strncpy(void *str1, const void *str2,u32 n);
void my_strcat(void *str1, const void *str2);
void my_strncat(void *str1, const void *str2,u32 n);
s32 my_memcmp(const void *str1, const void *str2, u32 n);
void *my_memchr(const void *str ,s32 c,u32 size);
u8 *my_strchr(const u8 *str, s32 c);
u8 *my_strrchr(const u8 *str, s32 c);
u8 *my_strstr (const u8 *s1, const u8 *s2);
u64 my_strcspn(const u8 *str1, const u8 *str2);
u64 my_strspn(const u8 *str1, const u8 *str2);
u8 *my_strpbrk(const u8 *str1, const u8 *str2);






#endif