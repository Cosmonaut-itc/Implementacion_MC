package com.company;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.logging.Level;
import java.util.logging.Logger;

public class PrimosUI {
    private JButton button1;
    private JPanel panel1;

    public PrimosUI() {
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Inicio");
                String entrada = button1.getText();
                try {
                    int nHilos = Integer.parseInt(entrada);
                    System.out.println("Numero de Hilos: " + nHilos);
                    primoMultiThread[] Hilos = new primoMultiThread[nHilos];

                    for (int i=0 ; i<nHilos; i++) {
                       // Hilos[i] = new primoMultiThread(int, bool, int, int); *Aqui se inicializa el constructor de la clase con sus parametros
                        Hilos[i].start();
                    }

                    for (int i=0; i<nHilos; i++){
                        try {
                            Hilos[i].join();
                        }catch (InterruptedException ex){
                            Logger.getLogger(PrimosUI.class.getName()).log(Level.SEVERE, null, e);
                        }
                    }
                } catch (NumberFormatException ex){
                    Logger.getLogger(PrimosUI.class.getName()).log(Level.SEVERE, null, e);
                }
                int threads = 14;
                int numero = 5000000;
                int rango =  Math.abs(numero / threads);
                int reminder = threads * rango - numero;
                int rangoInicial = 0;
                for(int i = 0; i< threads; i++){
                    int r1 = rangoInicial;
                    int r2 = rangoInicial + rango;
                    rangoInicial = r2;
                }
            }
            public void formWindowClosing(java.awt.event.WindowEvent event){
                System.out.println("Terminado");
            }
        });
    }
}
