public class Student
{
    private string name;
    private int stdid, natid, credits;
    private bool active;

    public Student(string name, int stdid, int natid, int credits, bool active)
    {
        this.name = name;
        this.stdid = stdid;
        this.natid = natid;
        this.credits = credits;
        this.active = active;
    }

    public override string ToString()
    {
        return $"{name}, {stdid}, {natid}, {credits}, {active}";
    }

    public static Student Parse(string str)
    {
        string[] tokens = str.Split(',');
        return new Student(tokens[0], int.Parse(tokens[1]), int.Parse(tokens[2]), int.Parse(tokens[3]), bool.Parse(tokens[4]));
    }

    public override bool Equals(object obj)
    {
        if (obj is Student)
        {
            Student other = obj as Student;
            return 
                name.Equals(other.name) &&
                stdid.Equals(other.stdid) &&
                natid.Equals(other.natid) &&
                credits.Equals(other.credits) &&
                active.Equals(other.active);
        } else {
            return false;
        }
    }

    static public void students_list()
    {
        string[] lines = File.ReadAllLines("students.csv");
        foreach(string line in lines)
        {
            string[] tokens = line.Split(',');
            System.Console.WriteLine($"{tokens[0]},{tokens[1]},{tokens[2]},{tokens[3]},{tokens[4]}");
        }
    }

    static public void students_list(ref Student[] std_list)
    {
        string[] lines = File.ReadAllLines("students.csv");
        int i = 0, length = lines.Length;
        std_list = new Student[length];
        foreach(string line in lines)
        {
            string[] tokens = line.Split(',');
            std_list[i] = new Student(tokens[0], int.Parse(tokens[1]), int.Parse(tokens[2]), int.Parse(tokens[3]), bool.Parse(tokens[4]));
        }
    }

    public void Save(string filename)
    {
        File.AppendAllLines(filename, new string[]{this.ToString()});
    }

    static public void Save(string filename, Student[] std_list)
    {
        foreach(Student std in std_list)
        {
            std.Save(filename);
        }
    }

    static public void Save(string filename, string[] std_list)
    {
        foreach(string std in std_list)
        {
            Student.Parse(std).Save(filename);
        }
    }
}