class Solution {
    public boolean isValid(String s) {

        Stack<Character> stack = new Stack<>();
  
        char[] openBrackets = {'(', '{', '['};
        char[] closeBrackets = {')', '}', ']'};
        String opens = new String(openBrackets);
        String closes = new String(closeBrackets);

        for (char ch : s.toCharArray()) {
            if (opens.indexOf(ch) >= 0) {
             
                stack.push(ch);
            } else if (closes.indexOf(ch) >= 0) {
         
                if (stack.isEmpty() || !isMatchingPair(stack.pop(), ch)) {
                    return false;
                }
            }
        }
     
        return stack.isEmpty();
    }

    private static boolean isMatchingPair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }


}
