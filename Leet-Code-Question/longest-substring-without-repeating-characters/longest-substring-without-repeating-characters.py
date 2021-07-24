class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        def split(word): 
            return [char for char in word]  
        
        # Function to convert   
        def listToString(s):  

            # initialize an empty string 
            str1 = ""  

            # traverse in the string   
            for ele in s:  
                str1 += ele   

            # return string   
            return str1
        
        vocab=split(s)
        setVocab=[]
        lengths=[]
        maxLength =0 
        for i in vocab:
            if i in setVocab:
                setVocab = setVocab[setVocab.index(i)+1:]
        
            setVocab.append(i)
            maxLength = max(maxLength,len(setVocab))
        
        print(setVocab)
        print(maxLength)
        return (maxLength)