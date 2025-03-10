#include <iostream>


class String {
private:
    int m_Length = 0;
    char* m_String = nullptr;

    void resize(int new_length)
    {
        char* tmpString = new char[new_length + 1]; // +1 for null terminator
        if (m_String) {
            for (int i = 0; i < m_Length; i++) 
                tmpString[i] = m_String[i];
        }
        delete[] m_String;
        m_String = tmpString;
        m_Length = new_length;
    }

    int calc_length(const char* str)
    {
        if (!str) return 0;
        int count = 0;
        const char* ptr = str;
        while (*ptr) {
            count++;
            ptr++;
        }
        return count;
    }

    void copy_string(const char* src, char* dst)
    {
        if (!src || !dst) return;
        const char* ptr_src = src;
        char* ptr_dst = dst;
        while (*ptr_src) {
            *ptr_dst = *ptr_src;
            ptr_src++;
            ptr_dst++;
        }
        *ptr_dst = '\0';
    }
    
public:
    String(const char* str = "")
    {
        m_Length = calc_length(str);
        m_String = new char[m_Length + 1];
        copy_string(str, m_String);
    }

    ~String() {
        delete[] m_String;
    }

    char* str() { return m_String; }
    int length() { return m_Length; }

    void assign(const char* str)
    {
        int new_length = calc_length(str);
        if (new_length != m_Length) {
            delete[] m_String;
            m_String = new char[new_length + 1];
        }
        m_Length = new_length;
        copy_string(str, m_String);
    }

    void add(const char* str)
    {
        char* tmp = new char[m_Length + calc_length(str)];
        for (int i = 0; i < m_Length; i++)
        {
            tmp[i] = m_String[i];
        }
        for (int i = 0; i < calc_length(str); i++)
        {
            tmp[(m_Length + i)] = str[i];
        }

        resize(m_Length + calc_length(str));
        copy_string(tmp, m_String);
        delete[] tmp;
    }

    void add(const String& str)
    {
        char* tmp = new char[str.m_Length];
        for (int i = 0; i < str.m_Length; i++)
        {
            tmp[i] = str.m_String[i];
        }

        add(tmp);
        delete[] tmp;
    }

    bool isAllNum() const
    {
        for (int i = 0; i < m_Length; i++)
        {
            if (m_String[i] < '0' || m_String[i] > '9') return false;
        }
        return true;
    }

    bool isAllAlpha() const
    {
        for (int i = 0; i < m_Length; i++)
        {
            if (!((m_String[i] >= 'a' && m_String[i] <= 'z')
                || (m_String[i] >= 'A' && m_String[i] <= 'Z'))) return false;
        }
        return true;
    }

    bool checkSubStr(const char* str) {
        int len = calc_length(str);
        for (int i = 0; i < (m_Length - len); i++)
        {
            if (m_String[i] == str[0])
            {
                for (int j = 1; j < len; j++)
                {
                    if (m_String[(i + j)] == str[j])
                    {
                        if (j == (len - 1)) return true;
                    }
                    else { break; }
                }
            }
        }
        return false;
    }
};

int main()
{
    String name("morteza");

    std::cout << name.str() << std::endl;
    std::cout << name.length() << std::endl;

    name.assign("rahimi");
    std::cout << name.str() << std::endl;
    std::cout << name.length() << std::endl;


    name.assign("rahimi");
    name.add("morteza");
    std::cout << name.str() << std::endl;

    String name2 = "morteza";
    name.add(name2);
    std::cout << name.str() << std::endl;

    std::cout << name.isAllAlpha() << std::endl;
    std::cout << name.isAllNum() << std::endl;

    std::cout << "-------------------" << std::endl;
    name2.assign("12345");
    std::cout << name2.str() << std::endl;
    std::cout << name2.isAllAlpha() << std::endl;
    std::cout << name2.isAllNum() << std::endl;

    std::cout << "-------------------" << std::endl;
    name2.assign("12345one");
    std::cout << name2.str() << std::endl;
    std::cout << name2.isAllAlpha() << std::endl;
    std::cout << name2.isAllNum() << std::endl;

    std::cout << "-------------------" << std::endl;
    std::cout << name2.checkSubStr("34") << std::endl;
    std::cout << name2.checkSubStr("24") << std::endl;
    std::cout << name.checkSubStr("rahimimo") << std::endl;
    return 0;
}