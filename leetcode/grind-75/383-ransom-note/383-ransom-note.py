class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        # determine if the letters in the ransom note are in the magazine
        # also check that they have the same number use count either n or 0

        m_letters = {}
        for character in magazine:
            if character in m_letters:
                m_letters[character] += 1
            else:
                m_letters[character] = 1
        
        rn_letters = {} 
        for character in ransomNote:
            if character in rn_letters:
                rn_letters[character] += 1
            else:
                rn_letters[character] = 1
        print(m_letters, rn_letters)
                
        for letter, count in rn_letters.items():
            if letter not in m_letters or count > m_letters[letter]: 
                return False
        return True