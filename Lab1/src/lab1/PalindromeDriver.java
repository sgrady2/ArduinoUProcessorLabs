package lab1;
/**
*
* PalindromeDriver.java
*
* The main driver code for lab 1 (asst2).
* Uses user-defined stack and queue class to determine if
* input words are palindromes.
*
*/ 

import java.io.IOException;
import java.util.Scanner;

public class PalindromeDriver {

   /* Main method: reads input and calls palindrome test, prints results */
   public static void main(String[] args) throws IOException
   {
       String[] results;
       int num_phrases;
       //create scanner object stdin and string for taking lines from our input
       Scanner stdin = new Scanner(System.in);
       //numhrases is the number of phrases to be analzyed
       //so we create a results calling for this many positions to store the results
       num_phrases = Integer.parseInt(stdin.nextLine());
       results = new String[num_phrases];
       
       for (int i = 0; i<num_phrases;i++){
    	   String line = stdin.nextLine();
    	   if (is_palindrome(line))
    		   results[i]="Palindrome";
    	   else
    		   results[i]="Not a palindrome";
    	   
       }
       //for loop for printing the results and then closing the scanner object
       for (int i=0;i<num_phrases;i++){
    	   System.out.println(results[i]);
       }
    	   
       //TODO Write a loop that reads num_phrases input lines from stdin,
       //     and checks whether each line is a palindrome or not.
       //     Use the is_palindrome subroutine to check each line....
       //     you will have to do some preprocessing to the lines first.
       //     Store the results of each line in results array.
       
       //TODO Write a loop that iterates through the results array and
       //     prints all the results to stdout.
   }
   /* is_palindrome: checks whether input is palindrome, returns true if so,
    *                false otherwise.
    */
   public static boolean is_palindrome(String input) {
       //TODO Write the body of is_palindrome,
       //     which uses a stack and a queue (data structure classes defined
       //     by you) to check whether the input is a palindrome.
       //     Return true if so, false otherwise.
	   //Preprocessing on string 
	   String postinput = input.replaceAll("\\W", "");
	   postinput = postinput.toLowerCase();
	  //I need to reverse the palindrome first to test if its the same as the word forward
	  //So first I'm initializing a queue and a stack from queue.java and stack.java
	   Queue queue = new Queue();
	   Stack stack = new Stack();
	   //also i need the length of the string for iteration 
	   //and put my input into a char array
	   char[] charlist = postinput.toCharArray();
	   int length = postinput.length();
	   //initializing forward string for the word forward and reverse for the opposite
	   String forward = "";
	   String reverse = "";
	   
	   //now when i enqeue and dequeue my nodes i will have a string of chars in the forward order
	   //when i push all my chars and then pop them, the word will be in reverse!
	   for (int i = 0; i<length;i++){
		   CharNode node = new CharNode(charlist[i], null);
		   queue.enqueue(node);
		   stack.push(node);
	   }
	   for (int i = 0; i<length; i++){
		   forward = forward + queue.dequeue();
		   reverse = reverse + stack.pop();
	   }
	   //now i need a conditional to print the resutls
	   if (reverse.equals(forward))
		   return true;
	   else
		   return false;
	
}}