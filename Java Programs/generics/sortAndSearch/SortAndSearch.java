/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package sortAndSearch;

/**
 *
 * @author Hi
 */
class Gen<T extends Comparable<T>>
{
    static Print p=new Print();
    T arr[];
    T grt;
    Gen(T ob[])
    {
        arr=ob;
        grt=arr[0];
    }
    
    void display()
    {
        p.print("Displaying the array below: ");
        for(T x:arr)
        {
            System.out.print(x+" ");
        }
        p.print("");
    }
    
    void bub_sort()
    {
        boolean bub=true;
        while(bub==true)
        {
            bub=false;
            for(int i=0;i<arr.length-1;i++)
            {
                if(arr[i].compareTo(arr[i+1])>0)
                {
                    T temp=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                    bub=true;
                }
            }
        }
    }
    
    boolean search(T search)
    {
        for(T x:arr)
        {
            if(search.compareTo(x)==0)
            {
                //p.print("Element found");
                return true;
            }
        }        
        return false;
    }
}
public class SortAndSearch {
    static Print p=new Print();
    public static void main(String args[])
    {
        Integer inums[]={4,2,-3,0,-200,100};
        String str[]={"Harish","Nitish","Visaka","Aravind"};
        Double dnums[]={44.6,44.3,50.08,92.6,-35.98,-10.9};
        
        Gen<Integer> iob=new Gen<>(inums);
        Gen<String> strob=new Gen<>(str);
        Gen<Double> dob=new Gen<>(dnums);
        
        iob.display();
        iob.bub_sort();
        iob.display();
        strob.display();
        strob.bub_sort();
        strob.display();
        dob.display();
        dob.bub_sort();
        dob.display();
        
        p.print("\n50 present in inums: "+iob.search(50));
        p.print("\nVisaka present in str: "+strob.search("Visaka"));
        p.print("\n50.08 present in dnums: "+dob.search(50.08));
    }
    
}
