class Solution(object):
    def validUtf8(self, data):
        """
        Check that a sequence of byte values follows the UTF-8 encoding
        rules. 
        """
        data = iter(data)
        for leading_byte in data:
            leading_ones = self._count_leading_ones(leading_byte)
            if leading_ones in [1, 7, 8]:
                return False        # Illegal leading byte
            for _ in range(leading_ones - 1):
                trailing_byte = next(data, None)
                if trailing_byte is None or trailing_byte >> 6 != 0b10:
                    return False    # Missing or illegal trailing byte
        return True

    @staticmethod
    def _count_leading_ones(byte):
        for i in range(8):
            if byte >> (7 - i) == 0b11111111 >> (7 - i) & ~1:
                return i
        return 8
#Above function will check if given list of numbers is valid utf or not

#E.g.
s=Solution()
print(s.validUtf8([197, 130, 1])) #Valid
print(s.validUtf8([235, 140, 4]))   #Invalid