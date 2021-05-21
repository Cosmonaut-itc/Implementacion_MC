package com.company;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.logging.Level;
import java.util.logging.Logger;

public class PrimosUI {
    private JButton button1;
    private JPanel panel1;
    private JButton singleThreadButton;

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
                long startTime = System.currentTimeMillis();
                String entrada = button1.getText();
                try {
                    int threads = Runtime.getRuntime().availableProcessors();
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
                    long endTime = System.currentTimeMillis();
                    long totalTime = endTime - startTime;
                    System.out.println(totalTime);
                    System.out.println(resultadoFinal);
                } catch (NumberFormatException ex) {
                    Logger.getLogger(PrimosUI.class.getName()).log(Level.SEVERE, null, e);
                }

            }

            public void formWindowClosing(java.awt.event.WindowEvent event) {
                System.out.println("Terminado");
            }
        });
        singleThreadButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String[] args = new String[0];
                Main.main(args);
            }
        });
    }
}
