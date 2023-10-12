#include <stdio.h>
#include "string.h"
u32 my_strlength(const void *str)
{
    u32 size = 0;
    while ('\0' != *((u8 *)str + size))
    {
        size++;
    }
    return size;
}
void my_strcpy(void *str1, const void *str2)
{
    u32 i = 0;
    while ('\0' != *((u8 *)str2 + i))
    {
        *((u8 *)str1 + i) = *((u8 *)str2 + i);
        i++;
    }
    if ('\0' == *((u8 *)str2 + i))
    {
        *((u8 *)str1 + i) = '\0';
    }
}
void my_strncpy(void *str1, const void *str2, u32 n)
{
    u32 i = 0;
    while (NULL != ((u8 *)str2 + i) && (n--))
    {
        *((u8 *)str1 + i) = *((u8 *)str2 + i);
        i++;
    }
    if ('\0' == *((u8 *)str2 + i))
    {
        *((u8 *)str1 + i) = '\0';
    }
}

void my_strcat(void *str1, const void *str2)
{
    u32 size1 = my_strlength(str1);
    u32 size2 = my_strlength(str2);
    for (u32 i = 0; i < size2; i++)
    {
        *((u8 *)str1 + size1 + i) = *((u8 *)str2 + i);
    }
}
void my_strncat(void *str1, const void *str2, u32 n)
{
    u32 size1 = my_strlength(str1);
    for (u32 i = 0; i < n; i++)
    {
        *((u8 *)str1 + size1 + i) = *((u8 *)str2 + i);
    }
}

void *my_memchr(const void *str, s32 c, u32 n)
{
    const u8 *p = str;

    for (s32 i = 0; i < n; i++)
    {
        if (p[i] == (u8)c)
        {
            return (void *)(p + i);
        }
    }

    return NULL;
}
s32 my_memcmp(const void *str1, const void *str2, u32 n)
{
    s32 returned = 0;
    u8 *s1 = (u8 *)str1;
    u8 *s2 = (u8 *)str2;
    if (str1 == str2)
    {
        returned = 0;
    }
    else
    {
        while ((NULL != s1) && (NULL != s2) && (n--))
        {
            if (*s1 > *s2)
            {
                returned = 1;

                break;
            }
            else if (*s1 < *s2)

            {

                returned = -1;
                break;
            }
            else
            {
                returned = 0;
            }
            s1++;
            s2++;
        }
    }
    return returned;
}
u8 *my_strchr(const u8 *str, s32 c)
{
   const u8 *s = str;
    while ((*s) != (u8)c)
    {
        s++;
    }

    return (u8 *)s;
}

u8 *my_strrchr(const u8 *str, s32 c)
{
    u8 *returned = NULL;
    s32 i = 0;
    u32 len = my_strlength(str);
    for (i = len; i >= 0; i--)
    {
        if (str[i] == (u8)c)
        {
            break;
        }
    }
    returned = (u8 *)(str + i);
    return returned;
}
u8 *my_strstr(const u8 *s1, const u8 *s2)
{
    u8 *returned = NULL;

    u32 len1 = my_strlength(s1);
    u32 len2 = my_strlength(s2);
    s32 i, j;
    for (i = 0; i < len1; i++)
    {

            for (j = 0; j <len2; j++)
            {
                if (s2[j] == s1[i + j])
                {
                    printf("%c\n",s2[j]);
                }
                else
                {
                    break;
                }
            }
            if (j == len2)
            {
             printf("%s\n",s1+j);
                returned = (u8 *)(s1 + i);
                break;
            }
        
    }
    return returned;
}

u64 my_strcspn(const u8 *str1, const u8 *str2)
{
    u64 len1 = my_strlength(str1);
    u64 len2 = my_strlength(str2);
   const u8 *s1 = str1;
   const u8 *s2 = str2;
    u64 i, j, counter = 0, flag = 0;
    for (i = 0; i <= len1; i++)
    {

        for (j = 0; j <= len2; j++)
        {

            if (str1[i] == str2[j])
            {
                printf("s : %c\n", str2[j]);
                break;
            }
        }
        if ((j < len2))
        {

            flag = 1;
        }
        else
        {
            counter++;
        }
        if (flag == 1)
        {
            break;
        }
    }
    return (counter);
}
u64 my_strspn(const u8 *str1, const u8 *str2)
{
    u64 len1 = my_strlength(str1);
    u64 len2 = my_strlength(str2);
   const u8 *s1 = str1;
   const u8 *s2 = str2;
    u64 i, j, counter = 0, flag = 0;
    for (i = 0; i <= len1; i++)
    {

        for (j = i; j <= len2; j++)
        {

            if (str1[i] == str2[j])
            {
                counter++;
                printf("s : %c\n", str2[j]);
                break;
            }
            if ((j + 1 == len2) && (str1[i] != str2[j]))
            {

                return (counter);
            }
        }
    }
    return (counter);
}
u8 *my_strpbrk(const u8 *str1, const u8 *str2)
{
   const u8 *returned = str1;
    u32 len1 = my_strlength(str1);
    u32 len2 = my_strlength(str2);
    s32 i = 0, j = 0, flag = 0;
    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {

            if (*(str1 + i) == *(str2 + j))
            {
                flag = i;
                break;
            }
            else
            {
            }
        }
        if (flag != 0)
        {
            break;
        }
    }
    if (flag == 0)
    {
        return 0;
    }
    return (u8 *)(returned + flag);
}
