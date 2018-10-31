/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Swing;

import java.awt.EventQueue;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

/**
 *
 * @author Hi
 */
public class DialogBoxes {

    JFrame f;
    JDialog d;
    JButton jb1,jb2;
    JLabel jl1;
    public DialogBoxes() 
    {
        initComponents();
        doButtonClick();
    }
    
    public static void main(String []args)
    {
        EventQueue.invokeLater(new Runnable()
        {

            @Override
            public void run() {
                new DialogBoxes();                
            }
            
        });
    }

    private void initComponents() {
      /*  f=new JFrame();
        f.setLayout(null);
        f.setVisible(true);
        f.setSize(500,500);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); */
        
        d=new JDialog();    //"This is a Dialog Box"
        d.setTitle("This is a Dialog Box");        
        d.setLayout(null);
        
        jl1=new JLabel("Benzene is a solvent");
        
        jl1.setBounds(300, 150, 200, 20);
        
        jb1=new JButton("True");
        jb1.setBounds(150, 200, 100, 20);
        jb2=new JButton("False");
        jb2.setBounds(450, 200, 100, 20);
        
        d.add(jb1);
        d.add(jb2);
        d.add(jl1);                
        
        d.setVisible(true);
        d.setSize(1000, 1000);
        d.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
    }

    private void doButtonClick() 
    {
        jb1.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent ae) {
                JOptionPane.showMessageDialog(null,"Correct Answer");
            }
        });
        
        jb2.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent ae) {
                JOptionPane.showMessageDialog(null,"Wrong Answer");
            }
        });
    }
    
}
