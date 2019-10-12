/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.util.*;

public class Main
{
  private final boolean Red = true;
  private final boolean Black = false;
  private class Node
  {
    private int key;
    private Node left;
    private Node right;
    boolean color;

    public Node (int key)
    {
      this.key = key;
      this.color = Red;
    }
  }
  private Node leftRotate (Node n)
  {
    Node t = n.right;
    n.right = t.left;
    t.left = n;
    t.color = n.color;
    n.color = Red;
    return t;

  }
  private Node rightRotate (Node n)
  {
    Node t = n.left;
    n.left = t.right;
    t.right = n;
    t.color = n.color;
    n.color = Red;
    return t;
  }
  private Node flipColor (Node n)
  {
    n.color = Red;
    n.left.color = Black;
    n.right.color = Black;
    return n;
  }
  public Node insert (Node root, int key)
  {
    if (root == null)
      {
	return new Node (key);

      }
    else if (root.key > key)
      {
	root.left = insert (root.left, key);
      }
    else if (root.key < key)
      {
	root.right = insert (root.right, key);
      }
    else
      {
	//update data;
      }
    if (getcolor (root.left) != Red && getcolor (root.right) == Red)
      {
	root = leftRotate (root);
      }
    if (getcolor (root.left) == Red && getcolor (root.left.left) == Red)
      {
	root = rightRotate (root);
      }
    if (getcolor (root.left) == Red && getcolor (root.right) == Red)
      {
	root = flipColor (root);
      }

    return root;


  }
  private boolean getcolor (Node n)
  {

    return n == null ? Black : n.color;
  }
  int height (Node root)
  {
    if (root == null)
      return 0;
    return 1 + Math.max (height (root.left), height (root.right));
  }
  public static void inorder (Node root)
  {
    if (root == null)
      return;
    inorder (root.left);
    System.out.println (root.key);
    inorder (root.right);
  }
  public Node insertkey (Node root, int key)
  {

    root = insert (root, key);
    root.color = Black;
    return root;
  }
  public static void main (String[]args)
  {
    Main m = new Main ();
    Node root = null;
    for (int i = 0; i < 100; i++)
      root = m.insertkey (root, i);
    //inorder (root);
    System.out.println (m.height (root));
    //System.out.println(m.Red);
    //System.out.println(m.Black);
  }
}
