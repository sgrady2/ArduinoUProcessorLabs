package lab1;
//object oriented class for character nodes of my stack and queues

public class CharNode {
	public char _data;
	public CharNode _next;
	//for my constructor i want the first argument to take the data to be stored in the node
	//the second argument is for the next node it is linked to
	public CharNode(char data, CharNode next){
		_data = data;
		_next = next;
		
	}
	public char getData(){
		return _data;
	}
	public CharNode getNext(){
		return _next;
	}
	public void setData(char data){
		_data = data;
	}
	public void setNext(CharNode next){
		_next = next;
	}
	
}
