package com.company;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.logging.Level;
import java.util.logging.Logger;

public class PrimosUI {
    private JButton button1;
    private JPanel panel1;

    public static void main(String[] args) {
        JFrame frame = new JFrame("PrimosUI");
        frame.setContentPane(new PrimosUI().panel1);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }

    public PrimosUI() {
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Inicio");
                String entrada = button1.getText();
                try {
                    int threads = Runtime.getRuntime().availableProcessors() - 1;
                    primoMultiThread[] Hilos = new primoMultiThread[threads];
                    int numero = 5000000;
                    int rango = Math.abs(numero / threads);
                    int rangoInicial = 0;
                    for (int i = 0; i < threads; i++) {
                        int r1 = rangoInicial;
                        int r2;
                        if (i == threads - 1) {
                            r2 = numero;
                        } else {
                            r2 = rangoInicial + rango;
                        }
                        rangoInicial = r2;
                        Hilos[i] = new primoMultiThread(i, true, r1, r2);
                        Hilos[i].start();
                    }


                    for (int i = 0; i < threads; i++) {
                        try {
                            Hilos[i].join();
                        } catch (InterruptedException ex) {
                            Logger.getLogger(PrimosUI.class.getName()).log(Level.SEVERE, null, e);
                        }
                    }
                    long resultadoFinal = 0;
                    for (int i = 0; i < threads; i++) {
                        resultadoFinal += Hilos[i].getResultado();
                    }
                    System.out.println(resultadoFinal);
                } catch (NumberFormatException ex) {
                    Logger.getLogger(PrimosUI.class.getName()).log(Level.SEVERE, null, e);
                }

            }

            public void formWindowClosing(java.awt.event.WindowEvent event) {
                System.out.println("Terminado");
            }
        });
    }
}
