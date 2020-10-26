public class Permutations {
	
	public boolean isSafe(String str, int l, int i, int r) {
		if (l != 0 && str.charAt(l - 1) == 'A'
	            && str.charAt(i) == 'B')
	            return false;
		if (r == l + 1 && str.charAt(i) == 'A'
                && str.charAt(l) == 'B'
                || r == l + 1 && l == i 
                && str.charAt(r) == 'B'
                && str.charAt(l) == 'A')
      return false;

  return true;
	}
	
	private void permute(String str, 
            int l, int r)
{

if (l == r)
System.out.print(str + " ");
else
{

for (int i = l; i <= r; i++)
{
   
   if (isSafe(str, l, i, r)) 
   {
       str = swap(str, l, i);
       permute(str, l + 1, r);
       str = swap(str, l, i);
   }
}
}
}
	public String swap(String a, int i, int j)
    {
        char temp;
        char[] charArray = a.toCharArray();
        temp = charArray[i];
        charArray[i] = charArray[j];
        charArray[j] = temp;
        return String.valueOf(charArray);
    }

	public static void main(String[] args) {
		
		String str = "ABC";
        int n = str.length();
        Permutations permutation = new Permutations();
 
        // Function call
        permutation.permute(str, 0, n - 1);

	}
