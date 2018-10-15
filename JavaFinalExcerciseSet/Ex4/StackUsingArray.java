/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Ex4;

import java.util.Scanner;

/**
 *
 * @author Hi
 */
public class StackUsingArray implements StackInterface{
    
        static Print p=new Print();
        int st[];
        int top,size;
    public StackUsingArray() {
         st=new int[100];
         top=-1;
         size=100;
    }
        
    public static void main(String args[])
    {
        int ch=0,val=0;
        Scanner s=new Scanner(System.in);
        StackUsingArray ob=new StackUsingArray();
        while(1==1)
        {
            p.print("Press:\n1:To push\n2:To pop\n3:To peek\nAny other no. to exit\n");
            ch=s.nextInt();
            switch(ch)
            {
                case 1:p.print("Enter the val to insert: ");
                    val = s.nextInt();
                    ob.push(val);
                    break;
                
                case 2:int po=ob.pop();
                    if(po!=-1)
                        p.print("Val popped = "+po);
                    
                    break;
                
                case 3:
                    if(ob.top!=-1)
                    {
                        p.print("Val at top of the stack = " + ob.st[ob.top]);
                    }
                    else
                    {
                        p.print("Empty stack");
                    }
                    break;
                    
                default:System.exit(0);
            }
        }
    }

    @Override
    public void push(int val) {
        if(this.top==this.size-1)
        {
            p.print("Stack overflow!!!");
        }
        else
        {
            this.st[++this.top]=val;
        }
        
    }

    @Override
    public int pop() {
        if(this.top==-1)
        {
            p.print("Stack underflow");
            return -1;
        }
        else
        {
            return this.st[this.top--];
        }
    }
    
}
