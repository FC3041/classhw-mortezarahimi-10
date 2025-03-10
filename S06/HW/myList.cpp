#include <iostream>
#include <stdexcept>

class myList {
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
    myList() { m_Nums = new int[m_Capacity]; }
    ~myList() { delete[] m_Nums; }

    int size(void) { return m_Size; }
    int capacity(void) { return m_Capacity; }
    int at(int index) {
        if (index < m_Size && index >= 0)
            return m_Nums[index];
            throw std::out_of_range("Index out of range");
    }
    int* begin(void) { return m_Nums; }

    void print_list()
    {
        for (int i = 0; i < m_Size; i++) 
            std::cout << m_Nums[i] << " ";
        std::cout << std::endl;
    }

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

    void reverse()
    {
        int tmp;
        for (int i = 0; i < (m_Size / 2); i++)
        {
            tmp = m_Nums[i];
            m_Nums[i] = m_Nums[(m_Size - i - 1)];
            m_Nums[(m_Size - i - 1)] = tmp;
        }
    }

    void clean()
    {
        m_Size = 0;
        resize(1);
    }

    void sort()
    {
        int tmp;
        for (int i = 0; i < m_Size; i++)
        {
            for (int j = 0; j < (m_Size - i - 1); j++)
            {
                if (m_Nums[j] > m_Nums[(j+1)])
                {
                    tmp = m_Nums[j];
                    m_Nums[j] = m_Nums[(j+1)];
                    m_Nums[(j+1)] = tmp;
                }
            }
        }
    }
};

int main()
{
    myList my_list;
    my_list.push_back(10);
    my_list.push_back(20);
    my_list.push_back(100);
    my_list.print_list();
    my_list.reverse();
    my_list.print_list();

    try {
        int x = my_list.at(100);
        std::cout << x << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    my_list.push_back(3);
    my_list.push_back(17);
    my_list.print_list();
    my_list.sort();
    my_list.print_list();
}