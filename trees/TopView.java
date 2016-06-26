/*
	AUTHOR	:	VISHAL KUMAR GOURAV
	PROBLEM	:	GIVEN A BINARY TREE PRINT ITS TOP VIEW
*/
import java.util.HashMap;
import java.util.Map;
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
class TopViewUtil{
	HashMap<Integer,Node> h;
	public TopViewUtil(){
		h=new HashMap<Integer,Node>();
	}
	public void setHashMap(Node root,int d){
		if(null==root)
			return;
		setHashMap(root.getLeft(),d-1);
		setHashMap(root.getRight(),d+1);
		h.put(d,root);
	}
	void printHashMap(){
		for(Map.Entry entry:h.entrySet()){
			Node node=(Node)entry.getValue();
			Integer dist=(Integer)entry.getKey();
			System.out.println(dist + "->" + node.getData());
		}
	}
}
class TopView{
	public static void main(String[] args){
		Node root=new Node(1);
		root.setLeft(new Node(2));
		root.setRight(new Node(3));
		root.getLeft().setLeft(new Node(4));
		root.getLeft().setRight(new Node(5));
		root.getRight().setLeft(new Node(6));
		root.getRight().setRight(new Node(7));
		
		/*Node root=new Node(1);
		root.setLeft(new Node(2));
		root.setRight(new Node(3));
		root.getLeft().setRight(new Node(4));
		root.getLeft().getRight().setRight(new Node(5));
		root.getLeft().getRight().getRight().setRight(new Node(6));*/
		
		TopViewUtil tvu=new TopViewUtil();
		tvu.setHashMap(root,0);
		tvu.printHashMap();
	}
}
