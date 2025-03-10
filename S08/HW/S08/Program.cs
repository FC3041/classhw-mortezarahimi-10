namespace S08;

class Program
{
    public static void reverse(string s, out string srev)
    {
        srev = "";
        foreach(char c in s)
        {
            srev = c + srev;
        }
    }

    public static void reverse_sentence(string[] s, out string srev)
    {
        srev = null;
        foreach(string c in s)
        {
            if (srev != null)
            {
                srev = c + " " + srev;
            } else {
                srev = c + srev;
            }
        }
    }

    public static void reverse_sentence_words(string[] s, out string srev)
    {
        srev = null;
        string c2;
        foreach(string c in s)
        {
            if (srev == null)
            {
                reverse(c, out c2);
                srev = srev + c2;
            } else
            {
                srev += " ";
                reverse(c, out c2);
                srev = srev + c2;
            }
        }
    }
    static void Main(string[] args)
    {
        string[] sentence = Console.ReadLine().Split();
        string reverse;
        reverse_sentence(sentence, out reverse);
        Console.WriteLine(reverse);
        reverse_sentence_words(sentence, out reverse);
        Console.WriteLine(reverse);
    }
}
