class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        max_num = 0xFFFFFFFF
        while a != 0:
            a, b = ((a & b) << 1),  (a ^ b)
            if a > max_num:
                b = (b&max_num)
                break
        return b