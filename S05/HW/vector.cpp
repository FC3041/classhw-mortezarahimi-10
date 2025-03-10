#include <iostream>

class Vector {
private:
    int* m_Nums, m_Size = 0, m_Capacity = 1;

    void resize(int new_capacity)
    {
        int* tmpNums = new int[new_capacity];

        for (int i = 0; i < m_Size; i++) tmpNums[i] = m_Nums[i];

        delete[] m_Nums;
        m_Nums = tmpNums;
        m_Capacity = new_capacity;
    }

public:
    Vector() { m_Nums = new int[m_Capacity]; }
    ~Vector() { delete[] m_Nums; }

    int size(void) { return m_Size; }
    int capacity(void) { return m_Capacity; }
    int at(int index) { return m_Nums[index]; }
    int* begin(void) { return m_Nums; }

    void push_back(int num)
    {
        if (m_Size >= m_Capacity) {
            resize(m_Capacity * 2);
        }

        m_Nums[m_Size] = num;
        m_Size++;
    }

    void pop_back()
    {
        m_Size--;
        m_Nums[m_Size] = 0;
    }

    void insert(int index, int num)
    {
        if (m_Size == m_Capacity) resize(m_Capacity * 2);

        int* tmpNums = new int[m_Capacity];
        m_Size++;
        for (int i = 0; i < m_Size; i++)
        {
            if (i < index) tmpNums[i] = m_Nums[i];
            else if (i == index) tmpNums[i] = num;
            else tmpNums[i] = m_Nums[i - 1];
        }

        delete[] m_Nums;
        m_Nums = tmpNums;
    }

    void insert(int* index, int num) { insert(index - m_Nums, num); }

    void erase(int index)
    {
        if (index < 0 || index >= m_Size) return;

        int* tmpNums = new int[m_Size - 1];
        m_Size--;
        for (int i = 0; i < m_Size; i++)
        {
            if (i < index) tmpNums[i] = m_Nums[i];
            else tmpNums[i] = m_Nums[i + 1];
        }

        delete[] m_Nums;
        m_Nums = tmpNums;
    }

    void erase(int* index) { erase(index - m_Nums); }
};

int main()
{
    Vector nums;

    nums.push_back(10);
    nums.push_back(5);
    for (int i = 0; i < nums.size(); i++) std::cout << nums.at(i) << " ";
    std::cout << std::endl;

    nums.insert(0, 230);
    nums.insert(2, 30);
    nums.insert(nums.begin() + 1, 100);
    for (int i = 0; i < nums.size(); i++) std::cout << nums.at(i) << " ";
    std::cout << std::endl;
    std::cout << nums.capacity() << std::endl;

    nums.pop_back();
    nums.erase(1);
    nums.erase(nums.begin() + 1);
    for (int i = 0; i < nums.size(); i++) std::cout << nums.at(i) << " ";
    std::cout << std::endl;
    return 0;
}