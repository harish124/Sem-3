/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Prog1;

/**
 *
 * @author Hi
 */
class Q
{
    int n;
    int operationPerformed=0;
    Q()
    {
        n=0;
    }
    synchronized int get()
    {
        while(operationPerformed==0)
        {
            try
            {
                wait();
            }
            catch(InterruptedException e)
            {
                System.out.println(""+e.getMessage());
            }
        }
        System.out.println("Got "+n);
        operationPerformed=0;
        notify();
        return n;
    }
    synchronized void put(int n)
    {
        this.n=n;
        while(operationPerformed==1)
        {
            try
            {
                wait();
            }
            catch(InterruptedException e)
            {
                System.out.println(""+e.getMessage());
            }
        }
        System.out.println("Put "+n);
        operationPerformed=1;
        notify();
    }
}//end of Q

class Producer implements Runnable
{
    Thread t;
    Q q;
    int i;
    public Producer(String Threadname,Q q)            
    {
        i=0;
        this.q=q;
        t=new Thread(this,Threadname);
        t.start();
    }
    
    
    @Override
    public void run() {
        while(true)
        {
            q.put(++i);
        }
    }
    
}//eProdeuce

class Consumer implements Runnable
{
    Thread t;
    Q q;
    int i;
    public Consumer(String Threadname,Q q)            
    {
        i=0;
        this.q=q;
        t=new Thread(this,Threadname);
        t.start();
    }
    
    
    @Override
    public void run() {
        while(true)
        {
            q.get();
        }
    }
    
}//eConsumer

public class ProducerConsumer {
    public static void main(String []args)
    {
        Q q=new Q();
        new Producer("Producer: ",q);
        new Consumer("Consumer: ",q);
    }
}
