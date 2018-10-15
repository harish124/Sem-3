/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Ex4;

import static Ex4.StackUsingArray.p;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Hi
 */
public class StackUsingArrayList implements StackInterface{

    ArrayList<Integer> st;
    int top;
    public StackUsingArrayList() {
        st=new ArrayList<Integer>();
        top=-1;
    }

    
    public static void main(String args[]) {
        int ch = 0, val = 0;
        Scanner s = new Scanner(System.in);        
        StackUsingArrayList ob=new StackUsingArrayList();
        while (1 == 1) {
            p.print("Press:\n1:To push\n2:To pop\n3:To peek\n4:To display\nAny other no. to exit\n");
            ch = s.nextInt();
            switch (ch) {
                case 1:
                    p.print("Enter the val to insert: ");
                    val = s.nextInt();
                    ob.push(val);
                    break;

                case 2:
                    int po = ob.pop();
                    if (po != -1) {
                        p.print("Val popped = " + po);
                    }

                    break;

                case 3:
                    if(ob.top!=-1)
                    {
                        p.print("Val at top of the stack = " + ob.st.get(ob.top));
                    }
                    else
                    {
                        p.print("Empty stack");
                    }
                    
                    break;
                    
                case 4:p.print("Stack below\n"+ob.st);
                    break;

                default:System.exit(0);
                    
            }
        }
    }

    @Override
    public void push(int val) {
        ++this.top;
        this.st.add(this.top,val); //no limit in size for the array list;
    }

    @Override
    public int pop() {
        if(this.st.isEmpty())
        {
            p.print("Stack underflow");
            return -1;
        }
        return this.st.remove(this.top--);
    }
}
