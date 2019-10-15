/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.util.*;
public class Main
{
    private class Node
    {
      int  key;
      Node left;
      Node right;
      
      public Node(int key)
      {
          this.key=key;
      }
    }
    private int height(Node n)
    {
        if(n==null)
         return 0;
       return  1+ Math.max(height(n.left),height(n.right));
    }
    private Node insert(Node root,int num)
    {
        if(root==null)
        return new Node(num);
        else if(root.key>num)
        root.left=insert(root.left,num);
        else if(root.key<num)
        root.right=insert(root.right,num);
        else {
            //do nothing or update the key;
        }
        if(height(root.left)-height(root.right)>1)
        {
            if(height(root.left.left)-height(root.left.right)<= -1)
            {
                root.left=leftRotate(root.left);
                root=rightRotate(root);
            }
            else{
                root=rightRotate(root);
            }
        }
        if(height(root.left)-height(root.right)<-1)
        {
            if(height(root.right.left)-height(root.right.right) >= 1)
            {
                root.right=rightRotate(root.right);
                root=leftRotate(root);
            }
            else{
                root=leftRotate(root);
            }
        }
        return root;
    }
    private Node leftRotate(Node n)
    {
        Node t=n.right;
        n.right=t.left;
        t.left=n;
        return t;
    }
    private Node rightRotate(Node n)
    {
        Node t=n.left;
        n.left=t.right;
        t.right=n;
        return t;
    }
	public static void main(String[] args) {
	    Main m=new Main();
	    Node root=null;
	    for(int i=100;i>=0;i--)
	    {
	        root=m.insert(root,i);
	    }
		System.out.println(m.height(root));
	}
}
