class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if( x < 0 ):
            return False
        else:
            store_num = x
            new_num = 0
            while( x != 0 ):
                rem = x % 10
                new_num = new_num*10 + rem
                x = x / 10
            if( store_num == new_num ):
                return True
            else:
                return False
