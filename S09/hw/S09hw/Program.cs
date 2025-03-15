using System.Security.Cryptography.X509Certificates;

namespace S09hw;

class Program
{
    static void Main(string[] args)
    {
        Student s1 = new Student(
            name: "morteza",
            stdid: 10,
            natid: 10,
            credits: 17,
            active: true
        );
        Console.WriteLine($"{s1.ToString()}");

        string str = "rahim,11,11,21,false";
        Student s2 = Student.Parse(str);
        Console.WriteLine($"{s2.ToString()}");
        File.WriteAllLines("students.csv", new string[]{s1.ToString(), s2.ToString()});

        Console.WriteLine("------------------");
        Student.students_list();

        Console.WriteLine("------------------");
        Student[] std_list = null;
        Student.students_list(ref std_list);
        Console.WriteLine($"{std_list[0].ToString()}");

        Console.WriteLine("------------------");
        Console.WriteLine($"{s2.Equals(s1)}");
        Console.WriteLine($"{s2.Equals(std_list[0])}");
    }
}
