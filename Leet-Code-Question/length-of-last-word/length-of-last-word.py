class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        a=s.split(' ')
        # print(a)
        length=0
        for _ in reversed(a):
            if(_.isalpha()):
                length=len(_)
                break
        return length