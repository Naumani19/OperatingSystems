/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package coe528.lab2;

/**
 *
 * @author Sameer Naumani
 */
public class Palindrome {
    //Requires: String a
    //Modifies: <Write the Modifies clause here>
    //Effects:  Checks string a and if null returns false. Checks to see if it is a palindrome, if the reverse is equal to the string then return true else returns false.
    //write the code for isPalindrome }
   
       
public static boolean isPalindrome(String a){
        //If a is null then return false
         
        if(a==null || "".equals(a)){
            //System.out.println("try again"); just testing 
            return false;
            }
                       
          else if (a.equals(new StringBuilder(a).reverse().toString())){
               // System.out.println("yes"); test
                return true;
            }
         // System.out.println("not a palindrome"); test
          return false;
          
    }

public static void main(String[] args) { 
    
    //isPalindrome("peep"); test
    if(args.length == 1) { 
        if (args[0].equals("1")) 
            System.out.println(isPalindrome(null)); 
        else if (args[0].equals("2")) 
            System.out.println(isPalindrome(""));
        else if (args[0].equals("3")) 
            System.out.println(isPalindrome("deed")); 
        else if (args[0].equals("4")) 
            System.out.println(isPalindrome("abcd")); 
    } 
}
    

         
}



