class Inversion_Count
{
    public static int inversionCount(int[] input)
    {
        var count = 0;

        for (int i = 0; i < input.Length; i++)
        {
            for (int j = 0; j < input.Length; j++)
            {
                if (input[i] > input[j])
                {
                    count++;
                }
            }
        }

        return count;
    }
}
