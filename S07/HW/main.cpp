#include <iostream>
#include <chrono>

uint64_t getTickCount() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(
        steady_clock::now().time_since_epoch()
    ).count();
}

class Keeptime
{
public:
    std::string m_operation_name;
    uint64_t l1;
    Keeptime(const std::string& op_name)
    {
        m_operation_name = op_name;
        l1 = getTickCount();
    }
    
    ~Keeptime()
    {
        uint64_t l2 = getTickCount();
        std::cout << m_operation_name << ": " << l2 - l1 << std::endl;
    }
};

int main()
{
    {
        Keeptime t("For loop 1_000_000");
        double d = 1;
        for (int i = 0; i < 1000000; i++)
            d *= 1.01;
        std::cout << "d = " << d << std::endl;
    }
    return 0;
}