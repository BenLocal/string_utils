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
    else if (strcmp(type, "string") == 0)
    {
        *(char **)out = strdup(str);
    }
    else if (strcmp(type, "int_array") == 0)
    {
        // Example: "[1,2,3]" -> int array
        if (str[0] == '[' && str[strlen(str) - 1] == ']')
        {
            char *temp = strdup(str + 1);  // Skip the '['
            temp[strlen(temp) - 1] = '\0'; // Remove the ']'

            // 先计算数组元素个数
            int count = 1;
            for (int i = 0; temp[i]; i++)
            {
                if (temp[i] == ',')
                    count++;
            }

            // 分配内存
            int *array = malloc(count * sizeof(int));
            if (array == NULL)
            {
                free(temp);
                return -1;
            }
            char *token = strtok(temp, ",");
            int index = 0;
            while (token != NULL)
            {
                array[index++] = atoi(token);
                token = strtok(NULL, ",");
            }
            *(int **)out = array;
            free(temp);
        }
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
    else if (strcmp(type, "string") == 0)
    {
        const char *str = *(const char **)value;
        if (str == NULL)
        {
            return NULL; // 空字符串处理
        }
        return strdup(str); // 返回字符串的副本
    }
    else if (strcmp(type, "int_array") == 0)
    {
        const int *array = *(const int **)value;
        int count = 0;

        // 计算数组长度
        while (array[count] != '\0') // 假设数组以0结尾
        {
            count++;
        }

        // 分配足够的空间
        int needed_size = 2; // For '[' and ']'
        for (int i = 0; i < count; i++)
        {
            needed_size += snprintf(NULL, 0, "%d", array[i]) + 1; // +1 for comma or null terminator
        }

        char *result = malloc(needed_size);
        if (result == NULL)
        {
            return NULL; // 内存分配失败
        }

        char *ptr = result;
        ptr += sprintf(ptr, "[");
        for (int i = 0; i < count; i++)
        {
            if (i > 0)
                ptr += sprintf(ptr, ",");
            ptr += sprintf(ptr, "%d", array[i]);
        }
        sprintf(ptr, "]"); // Add closing bracket

        return result;
    }
    return NULL;
}

int main()
{
    int a;
    str_convert_to("1", "int", &a);
    printf("Converted a value: %d\n", a);
    char *str_a = convert_to_string(&a, "int");
    printf("Converted back to string: %s\n", str_a);
    free(str_a);

    short b;
    str_convert_to("2", "short", &b);
    printf("Converted b value: %d\n", b);
    char *str_b = convert_to_string(&b, "short");
    printf("Converted back to string: %s\n", str_b);
    free(str_b);

    long c;
    str_convert_to("30000", "long", &c);
    printf("Converted c value: %ld\n", c);
    char *str_c = convert_to_string(&c, "long");
    printf("Converted back to string: %s\n", str_c);
    free(str_c);

    char d;
    str_convert_to("d", "char", &d);
    printf("Converted d value: %c\n", d);
    char *str_d = convert_to_string(&d, "char");
    printf("Converted back to string: %s\n", str_d);
    free(str_d);

    int *e;
    str_convert_to("[4,5,6]", "int_array", &e);
    printf("Converted e values: %d, %d, %d\n", e[0], e[1], e[2]);
    char *str_e = convert_to_string(&e, "int_array");
    printf("Converted back to string: %s\n", str_e);
    free(str_e);

    char *f;
    str_convert_to("这是", "string", &f);
    printf("Converted f value: %s\n", f);
    char *str_f = convert_to_string(&f, "string");
    printf("Converted back to string: %s\n", str_f);
    // 释放字符串内存
    free(f);
    free(str_f);

    return 0;
}