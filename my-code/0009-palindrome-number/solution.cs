public class Solution {
    public bool IsPalindrome(int x) {
        string a = x.ToString();
        var y = a.Reverse();
        string z = new string (y.ToArray());
        Console.WriteLine(z,a);

        return z.Equals(a);
    }
}
