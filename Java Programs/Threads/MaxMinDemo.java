/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Prog1;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Hi
 */

class MaxThread extends Thread
{
    int arr[],grt;
    public MaxThread(String Threadname,int ob[])
    {
        super(Threadname);
        arr=ob;
        grt=arr[0];        
        start();
        
    }
    
    @Override
    public void run()
    {
        for(int x:arr)
        {
            if(x>grt)
            {
                grt=x;
                try {
                    Thread.sleep(500);
                } catch (InterruptedException ex) {
                    Logger.getLogger(MinThread.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
                
        }
        
        System.out.println("ThreadName: "+Thread.currentThread().getName()+" Grt = "+grt);
    }
}//classMax

class MinThread extends Thread
{
    int arr[],sml;
    public MinThread(String Threadname,int ob[])
    {
        super(Threadname);
        arr=ob;
        sml=arr[0];        
        start();
        
    }
    
    @Override
    public void run()
    {
        for(int x:arr)
        {
            if(x<sml)
            {
                sml=x;
                try {
                    Thread.sleep(500);
                } catch (InterruptedException ex) {
                    Logger.getLogger(MinThread.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
                
        }
        
        System.out.println("ThreadName: "+Thread.currentThread().getName()+" Sml = "+sml);
    }
}//classMin

class Avg extends Thread
{
    int arr[],avg;
    public Avg(String Threadname,int ob[])
    {
        super(Threadname);
        arr=ob;
        avg=0;        
        start();
        
    }
    
    @Override
    public void run()
    {
        for(int x:arr)
        {            
            avg+=x;
        }
        avg/=6;     //As the array contains 6 elements;
        System.out.println("ThreadName: "+Thread.currentThread().getName()+" Avg = "+avg);
    }
}//classMin

public class MaxMinDemo {
    public static void main(String []args)
    {
        int arr[]={1,-100,21,54,210,100};
        Thread t1=new MaxThread("MaxThread", arr);
        Thread t2=new MinThread("MinThread", arr);
        Thread t3=new Avg("AvgThread", arr);
        
        try {
            t1.join();
            t2.join();
            t3.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(MaxMinDemo.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
