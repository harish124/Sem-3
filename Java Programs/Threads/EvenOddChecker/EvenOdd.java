/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Prog1;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Hi
 */
class Even extends Thread
{
    int n=0;

    public Even(int num) {
        n=num;
        start();
    }
    @Override
    public void run()
    {
        System.out.println("Name: "+Thread.currentThread().getName()+" val of "+n+" square = "+n*n);
    }
    
}
class Odd extends Thread
{
    int n=0;

    public Odd(int num) {
        n=num;
        start();
    }
    @Override
    public void run()
    {
        System.out.println("Name: "+Thread.currentThread().getName()+" val of "+n+" cube = "+n*n*n);
    }
    
}
class A extends Thread
{
    //this is the first Thread
    int i;
    int num;
    A()
    {
        i=0;
        num=0;
    }

    @Override
    public void run() {
        for(i=0;i<10;i++)
        {
            try {
                Random r=new Random();                
                num=r.nextInt(10)+1;
                System.out.println("\nNum = "+num);
                
                if(num%2!=0)
                {
                    new Odd(num);
                }
                else
                {
                    new Even(num);
                }
                
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(EvenOdd.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
public class EvenOdd extends Thread {
    public static void main(String []args)
    {
        A a=new A();
        a.start();
    }
}
