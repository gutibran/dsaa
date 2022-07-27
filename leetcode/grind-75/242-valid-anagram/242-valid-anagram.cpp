class Solution {
public:
    bool isAnagram(string s, string t) {
        // if there lengths do not match
        if (s.size() != t.size()) {
            return false;
        }
        
        // create hash tablet
        std::map<char, int> hash_tablet;
        std::map<char, int> hash_tableta;
        
        // iterate through the first string
        for (size_t i = 0; i < s.size(); i++) {
            // check if the character is in the hash
            if (hash_tablet.count(s[i]) > 0) {
                // increment the count by one
                hash_tablet[s[i]]++;
            }
            // add the unseen character to the hash
            else if (hash_tablet.count(s[i]) == 0) {
                hash_tablet[s[i]] = 1;
            }
        }
        
        // iterate through the second string
        for (size_t i = 0; i < t.size(); i++) {
            if (hash_tableta.count(t[i]) > 0) {
                hash_tableta[t[i]]++;
            } else if (hash_tableta.count(t[i]) == 0) {
                hash_tableta[t[i]] = 1;
            }
        }
        
        // iterate through the keys of the first string
        // and compare to the second string
        // mismatch results in false
        // dream on
        for (const auto pair : hash_tablet) {
            if (hash_tablet[pair.first] != hash_tableta[pair.first]) {
                return false;
            }
        }

        return true;
    }
};