package com.company.Utech_OOP;
import java.util.Scanner;

public class Main {
    static Scanner in = new Scanner(System.in);  // Import Scanner

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

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  MENU  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    public static void main(String[] args) {
        Admin Admin_Account = new Admin();
        menbanner("Create Staff User Account");
        int choice = in.nextInt();
        switch (choice){
            case 1 :
                System.out.println("Enter Username For Staff");
                String Username = in.nextLine();
                System.out.println("Enter Password");
                String Pass = in.nextLine();
        }

    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
