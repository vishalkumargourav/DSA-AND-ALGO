import java.util.HashMap;
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
	private HashMap<Integer,Integer> h;
	public HorizontalDistance(){
		h=new HashMap<Integer,Integer>();
	}
	public void updateHorizontal(Node root,int d){
		if(null==root)
			return;
		int prev=h.get(d)==null?0:h.get(d);
		h.put(d,prev+root.getData());
		updateHorizontal(root.getLeft(),d-1);
		updateHorizontal(root.getRight(),d+1);
	}
	public void printHash(){
		if(h!=null)
			System.out.println(h.entrySet());
	}
}
class VerticleSum{
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
