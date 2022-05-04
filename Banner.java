package com.company.Cars4Rent;

public class Banner {
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  MENU BANNER ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    public static void menbanner(String temp){
        String x = "║ " + temp + " ║";
        int fieldSize = x.length();
        System.out.print("╔");
        System.out.println("═".repeat(x.length() - 2) + "╗");
        System.out.printf("%" + fieldSize + "s\n", x);
        System.out.print("╚");
        System.out.print("═".repeat(x.length() - 2));
        System.out.println("╝");
    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
