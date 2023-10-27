package com.company;
import java.util.*;
import java.lang.Double;
import java.util.concurrent.TimeUnit;

public class Calculator {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        boolean z = true;
        System.out.println("Enter A Number");
        double a = in.nextDouble();
        while (z) {
            System.out.println("\n".repeat(15));
            System.out.println(a);
            System.out.println("1.) + \n2.) - \n3.) / \n4.) *\n5.)%\n6.)Exit");
            int b = in.nextInt();
            switch (b) {
                case 1 -> {
                    System.out.print(a + " + ");
                    double c = in.nextDouble();
                    System.out.println("\n".repeat(10));
                    System.out.printf(a + " + " + c + " = %.2f\n", Double.sum(a, c));
                    a = Double.sum(a, c);
                    try {
                        Thread.sleep(2000);
                    } catch(InterruptedException e) {
                        System.out.println("got interrupted!");
                    }
                }
                case 2 -> {
                    System.out.print(a + " - ");
                    double c = in.nextDouble();
                    System.out.println("\n".repeat(10));
                    System.out.printf(a + " - " + c + " = %.2f\n", a-c);
                    a = a-c;
                    try {
                        Thread.sleep(2000);
                    } catch(InterruptedException e) {
                        System.out.println("got interrupted!");
                    }
                }
                case 3 -> {
                    System.out.print(a + " / ");
                    double c = in.nextDouble();
                    System.out.println("\n".repeat(10));
                    System.out.printf(a + " - " + c + " = %.2f\n", a/c);
                    a = a/c;
                    try {
                        Thread.sleep(2000);
                    } catch(InterruptedException e) {
                        System.out.println("got interrupted!");
                    }
                }
                case 4 -> {
                    System.out.print(a + " x ");
                    double c = in.nextDouble();
                    System.out.println("\n".repeat(10));
                    System.out.printf(a + " - " + c + " = %.2f\n", a*c);
                    a = a*c;
                    try {
                        Thread.sleep(1500);
                    } catch(InterruptedException e) {
                        System.out.println("got interrupted!");
                    }
                }
                case 5 -> {
                    System.out.print(a + " % ");
                    double c = in.nextDouble();
                    System.out.println("\n".repeat(10));
                    System.out.printf(a + " - " + c + " = %.2f\n", a%c);
                    try {
                        Thread.sleep(1500);
                    } catch(InterruptedException e) {
                        System.out.println("got interrupted!");
                    }
                    a = a%c;
                }
                case 6 -> System.exit(1);
            }
        }
        }
    }
