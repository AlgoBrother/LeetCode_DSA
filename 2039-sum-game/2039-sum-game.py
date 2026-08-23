class Solution:
    def sumGame(self, num: str) -> bool:
        half = len(num) // 2
        
        left = num[:half]
        right = num[half:]
        
        q1 = left.count('?')
        q2 = right.count('?')
        
      
        if (q1 + q2) % 2 != 0:
            return True
            
        s1 = sum(map(int, left.replace('?', '0')))
        s2 = sum(map(int, right.replace('?', '0')))
    
        return (2 * s1 + 9 * q1) != (2 * s2 + 9 * q2)
