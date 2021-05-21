package com.company;

public class Main {

    public static boolean primo(int n) {
        if (n < 2) {
            return false;
        }
        if (n == 2){
            return true;
        }

        for (int i = 2; i <= Math.ceil(Math.sqrt(n)); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        long sum = 0;
        for (int i = 0; i < 5000000; i++) {
            if (primo(i)) {
                sum += i;
            }
        }
        System.out.println(sum);
    }
}
