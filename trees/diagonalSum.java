/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	PRINT THE DIAGONAL SUM OF A TREE
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
class DiagonalSum{
	private HashMap<Integer,Integer> h;
	public DiagonalSum(){
		h=new HashMap<Integer,Integer>();
	}
	public void updateHorizontal(Node root,int d){
		if(root!=null){
			if(h.get(d)!=null)
				h.put(d,h.get(d)+root.getData());
			else
				h.put(d,root.getData());
			updateHorizontal(root.getLeft(),d+1);
			updateHorizontal(root.getRight(),d);
		}
	}
	public void printHash(){
		System.out.println(h.entrySet());
		for(Map.Entry<Integer,Integer> entry:h.entrySet()){
			System.out.println(entry.getValue());
		}
	}
}
class diagonalSum{
	public static void main(String[] args){
		Node root=new Node(1);
		root.setLeft(new Node(2));
		root.setRight(new Node(3));
		root.getLeft().setLeft(new Node(9));
		root.getLeft().setRight(new Node(6));
		root.getRight().setLeft(new Node(4));
		root.getRight().setRight(new Node(5));
		root.getLeft().getLeft().setRight(new Node(10));
		root.getLeft().getRight().setLeft(new Node(11));
		root.getRight().getLeft().setLeft(new Node(12));
		root.getRight().getLeft().setRight(new Node(7));
		DiagonalSum ds=new DiagonalSum();
		ds.updateHorizontal(root,0);
		ds.printHash();
	}
}
