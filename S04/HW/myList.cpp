#include <iostream>


class MyList
{
public:
    int m_Length;
    int* m_Pnums;

    MyList(const int Length, const int* Pnums): m_Length(Length)
    {
        m_Pnums = new int[Length];
        for (int i = 0; i < Length; i++)
        {
            m_Pnums[i] = Pnums[i];
        }
    }

    void append(const int num)
    {
        int* tmp_Pnums = new int[m_Length + 1];
        for (int i = 0; i < m_Length; i++)
        {
            tmp_Pnums[i] = m_Pnums[i];
        }
        tmp_Pnums[m_Length] = num;
        m_Pnums = new int[m_Length + 1];
        for (int i = 0; i <= m_Length; i++)
            m_Pnums[i] = tmp_Pnums[i];
        m_Length++;
        delete[] tmp_Pnums;
    }
 
    void pop(int num)
    {
        int index = 0, *tmpList = new int[m_Length - 1];
        while ((m_Pnums[index] != num) && (index < m_Length)) index++;

        if (index == m_Length) {
            std::cout << "Item not found!" << std::endl;
            delete[] tmpList;
            return;
        }
        m_Length--;

        for (int i = 0; i < m_Length; i++)
        {
            if (i < index) tmpList[i] = m_Pnums[i];
            else tmpList[i] = m_Pnums[i + 1];
        }

        delete[] m_Pnums; // Free the old memory
        m_Pnums = tmpList; // Assign the new array
    }

    void print_list(void)
    {
        for (int i = 0; i < m_Length; i++)
        {
            std::cout << m_Pnums[i] << " ";
        }
        std::cout << std::endl;
    }
};


int main()
{
    int nums[5] = {1, 2, 3, 4, 5};
    MyList myList(5, nums);

    myList.print_list();

    myList.append(10);
    myList.append(15);
    myList.print_list();

    myList.pop(4);
    myList.pop(10);
    myList.print_list();
    return 0;
}