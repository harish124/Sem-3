/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calculator;

import java.awt.Event.*;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

/**
 *
 * @author Hi
 */
public class Calculator extends JFrame {

    /**
     * @param args the command line arguments
     */
    JButton jb1;
    JButton jb2;
    JButton jb3;
    JButton jb4;
    JTextField jt1;    
    JTextField jt2;
    JTextField jt3;

    
    public Calculator() {
        jb1 = new JButton("+");
        jb2 = new JButton("-");
        jb3 = new JButton("*");
        jb4 = new JButton("/");
        jt1 = new JTextField();
        jt1.setColumns(100);
        jt2 = new JTextField();
        jt2.setColumns(100);
        jt3 = new JTextField();
        jt3.setColumns(100);
        initComponents();
        actionPerformed();      //all will be same only only the operations will change
        //use ctrl+space after .operator and new operator to get autoCompletionCode in IDE's
    }

    public static void main(String[] args) {
        // TODO code application logic here
        EventQueue.invokeLater(new Runnable() {

            @Override
            public void run() {
                new Calculator();
            }

        });
    }

    private void initComponents() {
        JFrame f = new JFrame();
        f.setLayout(null);      //this step is very very important 
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel jl1 = new JLabel("Enter val 1: ");
        JLabel jl2 = new JLabel("Enter val 2: ");
        JLabel jl3 = new JLabel("Result: ");

        jl1.setBounds(100, 130, 100, 20);          //just keep third and fourth column values as 100 and 20 for all                
        jl2.setBounds(100, 160, 100, 20);        //just change the first column(for moving along x-axis), second column val (for moving along y-axis)
        jl3.setBounds(100, 190, 100, 20);

        jt1.setBounds(350, 130, 100, 20);        //label and its corresponding textfield must lie along the same line so both of their second columns must be equal;
        jt2.setBounds(350, 160, 100, 20);
        jt3.setBounds(350, 190, 100, 20);

        jb1.setBounds(200, 250, 100, 20);
        jb2.setBounds(300, 250, 100, 20);
        jb3.setBounds(400, 250, 100, 20);
        jb4.setBounds(500, 250, 100, 20);

        f.add(jt1);
        f.add(jt2);
        f.add(jt3);
        f.add(jb1);
        f.add(jb2);
        f.add(jb3);
        f.add(jb4);
        f.add(jl1);
        f.add(jl2);
        f.add(jl3);
        f.setSize(500, 500);
        f.setVisible(true);

    }

    private void actionPerformed() {
        
        jb1.addActionListener(new ActionListener() {
            //after new press ctrl+space below lines will be executed automatically ,but inside the method body you have to write the neccessary code;
            @Override
            public void actionPerformed(ActionEvent ae) {
                jt3.setText(Double.parseDouble(jt1.getText())+Double.parseDouble(jt2.getText())+"");
                //here first we are getting the values from the textfields add them and convert them to string by concatinatin it with ""
                //ex: 1+2+"" =3 (String)
                //Caution: ""+1+2= 12(String) 
                //here first everything is converted to string so appending of values takes place
            }
        });
        
        jb2.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent ae) {
                jt3.setText(Double.parseDouble(jt1.getText())-Double.parseDouble(jt2.getText())+"");
            }
        });
        
        jb3.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent ae) {
                jt3.setText(Double.parseDouble(jt1.getText())*Double.parseDouble(jt2.getText())+"");
            }
        });
        
        jb4.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent ae) {
                jt3.setText(Double.parseDouble(jt1.getText())/Double.parseDouble(jt2.getText())+"");
            }
        });
    }

}
