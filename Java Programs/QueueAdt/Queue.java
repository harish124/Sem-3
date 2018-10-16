/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package QueueAdt;

import java.util.Scanner;

/**
 *
 * @author Hi
 */
public class Queue {
    int front,rear,q[],size;
    Queue()
    {
        front=rear=-1;
        size=10;
        q=new int[10];
    }
    Queue(int size)
    {
        front=rear=-1;
        q=new int[size];
        this.size=size;
    }
    static void print(Object o)
    {
        System.out.println(""+o);
    }
    void enq(int val)
    {
        if(rear==size-1)
        {
            print("Queue overflow !!!");
        }
        else
        {
            if(front==-1 && rear==-1)
            {
                front=0;
            }
            print("Rear = "+rear);
                q[++rear]=val;
            
        }
    }
    
    int dq()
    {
        if(front==-1 || front >rear)
        {
            print("Queue is alreeady empty");
            return -1;
        }
        else
        {
            return q[front++];
        }
    }
     void display()
    {
        if(front==-1 || front>rear)
        {
            print("Queue is already empty");
            return ;
        }
        for(int i=front;i<=rear;i++)
        {
            System.out.print(q[i]+" ");
        }
        print("");
    }
    public static void main(String args[])
    {
        print("\nEnter the size of the queue: ");
        int size=0;
        Scanner s=new Scanner(System.in);
        size=s.nextInt();
        
        Queue ob=new Queue(size);
        int ch=0,val=0;
        while(1==1)
        {
            print("Press:\n1:To enq\n2:To dq\n3:To peek\n4:To display\nAny other no. to exit\n");
            ch=s.nextInt();
            switch(ch)
            {
                case 1:print("Enter the val to insert: ");
                    val = s.nextInt();
                    ob.enq(val);
                    break;
                
                case 2:int po=ob.dq();
                    if(po!=-1)
                        print("Val popped = "+po);
                    
                    break;
                
                case 3:
                    if(ob.front!=-1 && ob.front<=ob.rear)
                    {
                        print("Value at the top of the queue: "+ob.q[ob.front]);
                    }
                    else
                    {
                        print("Empty queue");
                    }
                    break;
                    
                case 4:print("\nDisplaying queue below: ");
                    ob.display();
                    break;
                default:System.exit(0);
            }
        }
        
    }
    
}
