package lab1;

public class Stack {
	private CharNode top;
	public Stack(){
		//for initializing with char c -=-=- CharNode node = new CharNode(c);
		top = null;
	}
	public void push(CharNode node){
		//assign the node passed as an argument to the top of the stack
		CharNode previoustop = top;
		//creating a new top for the pushed node i added and setting the
		//next pointer to the previous top
		top = new CharNode(node._data,previoustop);
		

	}
	public char pop(){
		//print an error message if the stack is already empty
		//otherwise set the top node to the next node in place
		//return the top node
		if (isEmpty()){
			System.out.print("The stack is empty");
			return 0;}
		char data = top._data;
		//resetting the top of the stack with a reference to the next node
		top = top._next;
		return data;
	}
	public boolean isEmpty(){
		return top == null;
	}
	
	

}