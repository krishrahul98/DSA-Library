class Solution(object):
    def validUtf8(self, data):
        """
        Check that a sequence of byte values follows the UTF-8 encoding
        rules. 
        """
        data = iter(data)
        for leading_byte in data:
            leading_ones = self._count_leading_ones(leading_byte)
            if leading_ones in [1, 5, 6, 7, 8]:
                return False        # Illegal leading byte
            current_code_point = self._find_code_point(leading_byte, leading_ones)
            for _ in range(leading_ones - 1):
                trailing_byte = next(data, None)
                if trailing_byte is None or trailing_byte >> 6 != 0b10:
                    return False    # Missing or illegal trailing byte
                current_code_point = current_code_point * 0b1000000 + self._find_code_point(trailing_byte, 1)
            if current_code_point > 0x10FFFF:
                return False        # Code point limit exceeded
            if current_code_point >= 0xD800 and current_code_point <= 0xDFFF:
                return False        # Invalid code point
            if leading_ones == 2 and current_code_point < 0x80:
                return False        # Overlong
            if leading_ones == 3 and current_code_point < 0x800:
                return False        # Overlong
            if leading_ones == 4 and current_code_point < 0x10000:
                return False        # Overlong 
        return True

    @staticmethod
    def _count_leading_ones(byte):
        for i in range(8):
            if byte >> (7 - i) == 0b11111111 >> (7 - i) & ~1:
                return i
        return 8
    @staticmethod
    def _find_code_point(byte, leadingOnes):
        return byte & ((1 << (7 - leadingOnes)) - 1)
    
#Above function will check if given list of numbers is valid utf or not

#E.g.
s=Solution()
print(s.validUtf8([197, 130, 1]))           #Valid
print(s.validUtf8([235, 140, 4]))           #Invalid
print(s.validUtf8([240, 128, 128, 128]))    #Invalid