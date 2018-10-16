/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package generics;
import generics.Print;

/**
 *
 * @author Hi
 */

class node<T extends Comparable<T>>
{
    static int MAX=10;
    static Print p=new Print();
    T val;
    node left,right;
    
    node()
    {
        val=null;
        left=right=null;
    }
    node (T val)
    {
        this.val=val;
        left=right=null;                
    }
    
    node insert(node<T> root,T val)
    {
        node new_node=new node(val);
        if(root==null)
        {            
            return new_node;
        }
        else
        {
            if(val.compareTo(root.val)<0)
            {
                root.left=insert(root.left,val);
            }
            if(val.compareTo(root.val)>0)
            {
                root.right=insert(root.right,val);
            }
            else
            {
                //do nothing for duplicate/repeated values
            }
        }         
           return root; 
    }
    void display(node root,int space)
    {
        if(root==null)
        {
            return ;
        }
        space+=MAX;
        display(root.right,space);
        for(int i=MAX;i<space;i++)
            System.out.print(" ");
        System.out.print(root.val+"\n");
        display(root.left,space);
    }
}
public class Bst {
    static Print p=new Print();
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        node root=new node(50);
        //p.print(root);
        try
        {
            root=root.insert(root,25);
            root=root.insert(root,35);
            root=root.insert(root,15);
            root=root.insert(root,6);
            root=root.insert(root,17);
            root=root.insert(root,45);
            root=root.insert(root,55);
            root.display(root,0);
        }
        
        catch(Exception e)
        {
            p.print(""+e.getMessage());
        }
        
    }
    
}
