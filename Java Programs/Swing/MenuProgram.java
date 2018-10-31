/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Swing;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import javax.swing.*;
/**
 *
 * @author Hi
 */
public class MenuProgram  {

    JFrame f;
    JMenu menu,submenu;
    JMenuBar jbr;
    JMenuItem itm1,itm2,itm3,itm4;
    
    public MenuProgram()
    {
        initComponents();
    }
    
    
    public static void main(String []args)
    {
        
        EventQueue.invokeLater(new Runnable()
        {

            @Override
            public void run() {
                new MenuProgram();                
            }
            
        });
        
        
    }

    private void initComponents() 
    {
        menu=new JMenu("Main Menu");
        submenu=new JMenu("Sub Menu");
        jbr=new JMenuBar();
        jbr.setName("Menu");
        
        itm4=new JMenuItem("Veg.Puff");
        itm3=new JMenuItem("Vada");
        itm2=new JMenuItem("Dosa");
        itm1=new JMenuItem("Idly");
        
        menu.add(itm1);
        menu.add(itm1);
        menu.add(itm3);
        menu.add(submenu);
        submenu.add(itm4);        
        
        jbr.add(menu);
        
        f=new JFrame();
        f.setJMenuBar(jbr);
        f.setVisible(true);
        f.setSize(500,500);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
    }

    
}
