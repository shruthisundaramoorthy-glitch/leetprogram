public class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" "); 
        if (pattern.length() != words.length) {
            return false; 
        }

        HashMap<Character, String> charToWord = new HashMap<>();
        HashMap<String, Character> wordToChar = new HashMap<>();

        for (int i = 0; i < pattern.length(); i++) {
            char p = pattern.charAt(i);
            String w = words[i];

        
            if (charToWord.containsKey(p)) {
                if (!charToWord.get(p).equals(w)) {
                    return false; 
                }
            } else {
                charToWord.put(p, w); 
            }

            
            if (wordToChar.containsKey(w)) {
                if (wordToChar.get(w) != p) {
                    return false; 
                }
            } else {
                wordToChar.put(w, p);
            }
        }

        return true; 
    }
}

        
    
