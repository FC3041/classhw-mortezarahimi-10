#include <iostream> 
#include <string.h>
#include <stdlib.h>
#include <iomanip>


class Student
{
    public : 
        int m_StudentNumber;
        char m_FirstName[20];
        char m_LastName[20];
        int m_CoursesPassed;
        int m_Credits[40];
        double m_Grades[40];
        char * m_CourseNames[40];
        double m_GPA;

        Student(int, const char*, const char*, int, int*, double*, const char*[]);
        ~Student();

        double Get_GPA(void)
        {
            double sumGrades = 0;
            int sumCredits = 0; 
            for(int i = 0; i < m_CoursesPassed; i++)
            {
                sumGrades += m_Credits[i] * m_Grades[i] ; 
                sumCredits += m_Credits[i];
            }
            m_GPA = sumGrades / sumCredits;
            return m_GPA;
        }
        
        void list_courses(void)
        {
            std::cout << "-----------------------------" << std::endl;
            std::cout << m_FirstName << " - " << m_LastName << std::endl;
            std::cout << "----------------------" << std::endl;

            for(int i = 0; i < m_CoursesPassed; i++)
            {
                std::cout << std::setw(10) << std::left << m_CourseNames[i] << " : "
                    << m_Credits[i] << " : "
                    << std::fixed << std::setprecision(2)
                    << m_Grades[i] << std::endl;
            }

            std::cout << "-----------------------------" << std::endl;
        }
        
        void register_course(int credits, const char* name, double grade)
        {
            m_Credits[m_CoursesPassed] = credits; 
            m_Grades[m_CoursesPassed] = grade;
            char * course_name = new char[strlen(name) +1];
            strcpy(course_name, name);
            m_CourseNames[m_CoursesPassed] = course_name; 
            m_CoursesPassed++;
        }
};

Student::Student(int StudentNumber, const char* FirstName, const char* LastName
    , int CoursesPassed, int* Credits, double* Grades, const char* CourseNames[])
{
    m_StudentNumber = StudentNumber;
    strcpy(m_FirstName, FirstName);
    strcpy(m_LastName, LastName);
    m_CoursesPassed = CoursesPassed;
    for (int i = 0; i < m_CoursesPassed; i++) m_Credits[i] = Credits[i];
    for (int i = 0; i < m_CoursesPassed; i++) m_Grades[i] = Grades[i];
    char* course_name;
    for (int i = 0; i < CoursesPassed; i++) {
        course_name = new char[strlen(CourseNames[i]) + 1];
        strcpy(course_name, CourseNames[i]);
        m_CourseNames[i] = course_name;
    }
    m_GPA = Get_GPA();
}

Student::~Student()
{
    for (int i = 0; i < m_CoursesPassed; i++)
        delete m_CourseNames[i];
}


int main()
{
    int credits_[2] = {2, 1};
    double grades[2] = {10, 10};
    const char* course_names[2] = {"s1", "s2"};
    Student s(1, "morteza", "rahimi", 2, credits_, grades, course_names);

    char bufc[20];
    int credits;
    std::string credits_string;
    double grade;
    std::string grade_string;
  
    while(true)
    {
        std::cout << "Course name? ";
        std::cin >> bufc ;
        if((bufc[0] == 'Q' || bufc[0] == 'q') && bufc[1] == 0)
            break;
        std::cout << "Course credits? "; 
        std::cin >> credits_string;
        try{
            credits = std::stoi(credits_string);
            if (credits < 1 || credits > 3) {
                std::cout << "Grade should be between 1 and 3!" << std::endl;
                continue;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid credits!" << std::endl;
            continue;
        }

        std::cout << "Course grade? "; 
        std::cin >> grade_string;
        try{
            grade = std::stod(grade_string);
            if (grade < 0 || grade > 20) {
                std::cout << "Grade should be between 0 and 20!" << std::endl;
                continue;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid grade!" << std::endl;
            continue;
        }

        s.register_course(credits, bufc, grade) ;
    }

    s.list_courses();
    std::cout << std::fixed << std::setprecision(2) << "Average: " << s.Get_GPA() << std::endl;
}