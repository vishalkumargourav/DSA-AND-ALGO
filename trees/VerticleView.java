/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A BINARY TREE PRINT ITS VERTICLE ORDER TRAVERSAL
*/
import java.util.HashMap;
import java.util.Queue;
import java.util.Map;
import java.util.Collections;
import java.util.LinkedList;
class Node{
	private int data;
	private Node left;
	private Node right;
	public Node(int data){
		this.data=data;
		this.left=this.right=null;
	}
	public int getData(){
		return this.data;
	}
	public Node getLeft(){
		return this.left;
	}
	public Node getRight(){
		return this.right;
	}
	public void setLeft(Node left){
		this.left=left;
	}
	public void setRight(Node right){
		this.right=right;
	}
}
class HorizontalDistance{
	private HashMap<Integer,Queue<Integer>> h;
	public HorizontalDistance(){
		h=new HashMap<Integer,Queue<Integer>>();
	}
	public void updateHorizontal(Node root,int d){
		if(null==root)
			return;
		Queue<Integer> q=h.get(d);
		if(null==q){
			q=new LinkedList<Integer>();
			h.put(d,q);
		}
		q.add(root.getData());
		updateHorizontal(root.getLeft(),d-1);
		updateHorizontal(root.getRight(),d+1);
	}
	public void printHash(){
		System.out.println(h.entrySet());
		for(Map.Entry<Integer,Queue<Integer>> entry:h.entrySet()){
			Queue<Integer> q=entry.getValue();
			System.out.print("Queue is:");
			while(q.peek()!=null){
				System.out.print(q.peek()+" ");
				q.remove();
			}
			System.out.println(" ");
		}
	}
}
class VerticleView{
	public static void main(String[] args){
		Node root=new Node(1);
		root.setLeft(new Node(2));
		root.setRight(new Node(3));
		root.getLeft().setLeft(new Node(4));
		root.getLeft().setRight(new Node(5));
		root.getRight().setLeft(new Node(6));
		root.getRight().setRight(new Node(7));
		HorizontalDistance hd=new HorizontalDistance();
		hd.updateHorizontal(root,0);
		hd.printHash();
	}
}
