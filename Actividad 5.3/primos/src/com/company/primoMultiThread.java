package com.company;

public class primoMultiThread extends Thread{
    private int id;
    private boolean bandera;
    private int r1,r2;
    private long resultado;

    primoMultiThread(int id, boolean bandera, int r1, int r2){
        this.id = id;
        this.bandera = bandera;
        this.r1 = r1;
        this.r2 = r2;
        this.resultado = 0L;
    }


    @Override
    public void run() {
        super.run();
        long sum = 0;
        for (int i = r1; i < r2; i++) {
            if (Main.primo(i)) {
                sum += i;
            }
        }
        this.resultado = sum;
    }
}
