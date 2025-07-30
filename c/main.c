#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_convert_to(const char *str, const char *type, void *out)
{
    if (strcmp(type, "int") == 0)
    {
        *(int *)out = atoi(str);
    }
    else if (strcmp(type, "short") == 0)
    {
        *(short *)out = (short)atoi(str);
    }
    else if (strcmp(type, "long") == 0)
    {
        *(long *)out = atol(str);
    }
    else if (strcmp(type, "float") == 0)
    {
        *(float *)out = atof(str);
    }
    else if (strcmp(type, "double") == 0)
    {
        *(double *)out = atof(str);
    }
    else if (strcmp(type, "char") == 0)
    {
        *(char *)out = str[0];
    }
    else
    {
        return -1; // Unsupported type
    }
    return 0;
}

char *convert_to_string(const void *value, const char *type)
{
    if (strcmp(type, "int") == 0)
    {
        int needed_size = snprintf(NULL, 0, "%d", *(const int *)value) + 1;
        char *result = malloc(needed_size);
        if (result == NULL)
        {
            return NULL; // 内存分配失败
        }
        snprintf(result, needed_size, "%d", *(const int *)value);
        return result;
    }
    else if (strcmp(type, "short") == 0)
    {
        int needed_size = snprintf(NULL, 0, "%d", *(const short *)value) + 1;
        char *result = malloc(needed_size);
        if (result == NULL)
        {
            return NULL; // 内存分配失败
        }
        snprintf(result, needed_size, "%d", *(const short *)value);
        return result;
    }
    else if (strcmp(type, "long") == 0)
    {
        int needed_size = snprintf(NULL, 0, "%ld", *(const long *)value) + 1;
        char *result = malloc(needed_size);
        if (result == NULL)
        {
            return NULL; // 内存分配失败
        }
        snprintf(result, needed_size, "%ld", *(const long *)value);
        return result;
    }
    else if (strcmp(type, "float") == 0)
    {
        int needed_size = snprintf(NULL, 0, "%f", *(const float *)value) + 1;
        char *result = malloc(needed_size);
        if (result == NULL)
        {
            return NULL; // 内存分配失败
        }
        snprintf(result, needed_size, "%f", *(const float *)value);
        return result;
    }
    else if (strcmp(type, "double") == 0)
    {
        int needed_size = snprintf(NULL, 0, "%lf", *(const double *)value) + 1;
        char *result = malloc(needed_size);
        if (result == NULL)
        {
            return NULL; // 内存分配失败
        }
        snprintf(result, needed_size, "%lf", *(const double *)value);
        return result;
    }
    else if (strcmp(type, "char") == 0)
    {
        char *result = malloc(2); // For single character and null terminator
        if (result == NULL)
        {
            return NULL; // 内存分配失败
        }
        result[0] = *(const char *)value;
        result[1] = '\0';
        return result;
    }
    return NULL;
}

int main()
{
    int a;
    str_convert_to("1", "int", &a);
    printf("Converted a value: %d\n", a);
    printf("Converted back to string: %s\n", convert_to_string(&a, "int"));

    short b;
    str_convert_to("2", "short", &b);
    printf("Converted b value: %d\n", b);
    printf("Converted back to string: %s\n", convert_to_string(&b, "short"));

    long c;
    str_convert_to("30000", "long", &c);
    printf("Converted c value: %ld\n", c);
    printf("Converted back to string: %s\n", convert_to_string(&c, "long"));

    char d;
    str_convert_to("d", "char", &d);
    printf("Converted d value: %c\n", d);
    printf("Converted back to string: %s\n", convert_to_string(&d, "char"));

    return 0;
}