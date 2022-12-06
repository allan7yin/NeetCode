// Leetcode Problem 271 - Encode and Decode strings 

public class Main {
    public static void main(String[] args) {

    }
}

class Solution {

    public String encode(String[] words) {
        // we want to encode this, so, follow the pattern where:
        // [allan, brian, sophia, pierre] => 5%allan5%brian6%sophia6%pierre
        // so, number of characters in word, followed by delimiter

        String solution = "";

        for (int i = 0; i < words.length; i++) {
            int length = words[i].length();
            String temp = Integer.toString(length) + "%";
            solution += temp;
        }

        return solution;
    }
}