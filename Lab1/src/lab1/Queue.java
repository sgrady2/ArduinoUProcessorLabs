package lab1;

public class Queue {
	//the rear of the queue is where we enqueue our nodes, then they wait in line to get to the front
	//the front of the queue is where we dequeue our nodes, they have been waiting since being enqueued
	private CharNode front;
	private CharNode rear;
	
	public Queue(){
		//set the front and rear to null initially for creating an empty list
		front = null;
		rear = null;
	}
	public void enqueue(CharNode node){
		//i need to keep track of my previous rear of the queue as i enqueue
		//and create a new rear to be at the last position of my line
		CharNode oldrear = rear;
		//creating a new node to be at the last position
		rear = new CharNode(node._data, node._next);
		//if the list is empty then the rear also references null
		if (isEmpty())
			front = rear;
		else
			oldrear._next = rear;
		//otherwise set my old rear to the the current rear i just constructed
	}
	//setting up function using return type char so when the function returns
	//it gives me the data of the node and not a reference
	public char dequeue(){
		//check if the queue is empty first returning 0 to break
		//the conditional
		if (isEmpty()){
			System.out.println("There is nothing in the queue");
			return 0;}
		char data = front._data;
		front = front._next;
		//this is to check if the front is equal to null and if it is
		//then i want to set my rear equal to null as well because the queue is empty
		if (isEmpty())
			rear = null;
		
		return data;
	}
	public boolean isEmpty(){
		return front == null;
	}
}
