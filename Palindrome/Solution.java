package Palindrome;

public class Solution {
    public boolean isPalindrome(String s) {
        String newString = s.toLowerCase();
        String sol = "";
        for (int i = 0; i < newString.length(); i++) {
            if ((newString.charAt(i) >= 48 && newString.charAt(i) <= 57) ||
                    (newString.charAt(i) >= 97 && newString.charAt(i) <= 122)) {
                sol += newString.charAt(i);
            }
        }

        // now, we have the remaining valid chars stored, in original order, in sol

        System.out.println(sol);
        for (int j = 0; j < sol.length() / 2; j++) {
            if (sol.charAt(j) != sol.charAt(sol.length()-j-1)) {
                return false;
            }
        }

        return true;
    }
}