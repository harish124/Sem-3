/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Exp5;
import java.util.ArrayList;
import java.util.Scanner;
/**
 *
 * @author Hi
 */
public class StrinOp {
    static Print p=new Print();
    public static void main(String args[])
    {
        ArrayList<String> a=new ArrayList<>(100);
        Scanner s=new Scanner(System.in);
        int ch=0;
        String str;
        int index=0;
        while(1==1)
        {
            p.print("\nPress:\n1:To append\n2:To insert at an index\n3:Search\n4:List all string starts with given letter\n5:To Display\nAny other no. to exit\n");
            ch=s.nextInt();
            switch(ch)
            {
                case 1:p.print("\nEnter any name: ");
                    str=s.next();
                    a.add(str);
                    break;
                    
                case 2:p.print("\nEnter any name to insert at any posn.: ");
                     str=s.next();
                    p.print("Enter any index to insert: ");
                    index=s.nextInt();
                    if(index>a.size())
                    {
                        p.print("Invalid index");
                        break;
                    }
                    a.add(index, str);
                    break;
                    
                case 3:p.print("\nEnter any name to search: ");
                    str = s.next();
                    int found = 0;
                    for (String x : a) {
                        if (str.equals(x)) {
                            p.print("Element Found");
                            found = 1;
                        }

                    }
                    if (found != 1) {
                        p.print("Element not found");
                    }

                    break;
                    
                case 4:p.print("Enter the begining letter: ");
                    char c=s.next().charAt(0);
                    for (String x : a) {
                        if (x.charAt(0)==c) {
                            p.print(""+x);
                            
                        }

                    }
                break;
                    
                case 5:
                    for(String x:a)
                    {
                        System.out.print(x+" ");
                    }
                break;
                default:System.exit(0);
                            
                
            }
        }
    }
    
}
