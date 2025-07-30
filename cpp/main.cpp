#include <string>
#include <sstream>

namespace StringUtils
{
    template <class T>
    static inline std::string convert_to_str(T a)
    {
        std::string res;
        std::stringstream ss;
        ss << a;
        ss >> res;
        return res;
    }

    template <class T>
    static inline void str_convert_to(const std::string str, T &res)
    {
        std::stringstream ss;
        ss << str;
        ss >> res;
    }

    // 专门为vector<int>的特化版本
    static inline void str_convert_to_array(const std::string &str, std::vector<int> &res)
    {
        res.clear();

        // 检查格式 [x,y,z]
        if (str.length() < 2 || str[0] != '[' || str.back() != ']')
        {
            return;
        }

        // 提取括号内的内容
        std::string content = str.substr(1, str.length() - 2);

        // 按逗号分割
        std::stringstream ss(content);
        std::string item;

        while (std::getline(ss, item, ','))
        {
            // 去除空格
            size_t start = item.find_first_not_of(" \t");
            size_t end = item.find_last_not_of(" \t");

            if (start != std::string::npos)
            {
                item = item.substr(start, end - start + 1);
                res.push_back(std::stoi(item));
            }
        }
    }

    static inline std::string convert_array_to_str(const std::vector<int> &vec)
    {
        std::string result = "[";
        for (size_t i = 0; i < vec.size(); ++i)
        {
            if (i > 0)
                result += ",";
            result += std::to_string(vec[i]);
        }
        result += "]";
        return result;
    }

}

int main()
{
    int a;
    StringUtils::str_convert_to("1", a);
    std::string str_a = StringUtils::convert_to_str(a);
    printf("Converted a value: %d\n", a);
    printf("Converted back to string: %s\n", str_a.c_str());

    short b;
    StringUtils::str_convert_to("2", b);
    std::string str_b = StringUtils::convert_to_str(b);
    printf("Converted b value: %d\n", b);
    printf("Converted back to string: %s\n", str_b.c_str());

    long c;
    StringUtils::str_convert_to("30000", c);
    std::string str_c = StringUtils::convert_to_str(c);
    printf("Converted c value: %ld\n", c);
    printf("Converted back to string: %s\n", str_c.c_str());

    char d;
    StringUtils::str_convert_to("d", d);
    std::string str_d = StringUtils::convert_to_str(d);
    printf("Converted d value: %c\n", d);
    printf("Converted back to string: %s\n", str_d.c_str());

    // For int_array, we can use a vector for dynamic size
    std::vector<int> int_array;
    StringUtils::str_convert_to_array("[4,5,6]", int_array);
    printf("Converted e values: %d, %d, %d\n", int_array[0], int_array[1], int_array[2]);
    std::string str_e = StringUtils::convert_array_to_str(int_array);
    printf("Converted e value: %s\n", str_e.c_str());
    return 0;
}