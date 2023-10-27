package com.company;
// import com.jakewharton.fliptables.FlipTable;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

import static java.lang.System.exit;

public class ChemCalc {
    public static void atomic(){
        Scanner in = new Scanner(System.in);
        int x = 0;
        String temp;
        ArrayList<Float> atomicmasselements = new ArrayList<>();
        while (true) {
            System.out.println("Enter Fractional/Percent Abundance Of Isotope Or ? If Unknown, Or Enter To Continue");
            temp = in.nextLine();
            if (Objects.equals(temp, "")){
                break;
            }
            try {
                atomicmasselements.add(x, Float.parseFloat(temp) / 100);
            }catch (NumberFormatException e){
                System.out.println("Enter Atomic Mass Of Element");
                atomicmasselements.add(x,Float.parseFloat(in.nextLine()));
                System.out.println("Enter Mass Of Isotope");
                atomicmasselements.add(Float.parseFloat(in.nextLine()));
                atomicmasselements.set(x,atomicmasselements.get(x) / atomicmasselements.get(x+1));

                continue;
            }
            x++;
            System.out.println("Enter Mass Of Isotope Or ? If Unknown");
            temp = in.nextLine();
            try {
                atomicmasselements.add(x, Float.parseFloat(temp));
            }catch (NumberFormatException e){
                System.out.println("Enter Atomic Mass Of Element");
                atomicmasselements.add(x,Float.parseFloat(in.nextLine()) / atomicmasselements.get(x-1));
            }
            x++;
        }
        System.out.println(atomicmasselements);
        float y = 0;
        for (int i = 0; i < atomicmasselements.size(); i+=2) {
            y += atomicmasselements.get(i) * atomicmasselements.get(i+1);
        }
        System.out.println("Atomic Mass = " + y);
        exit(0);
    }
    public static void Menu(){
        System.out.println("Atomic Mass");
        try {
            Thread.sleep(2000);
        }catch (InterruptedException e){
            System.out.println("Interrupted");
        }
        atomic();
        }

    public static void main(String[] args) {
        System.out.print("╔");
        System.out.print("═".repeat(33));
        System.out.println("╗");
        System.out.printf("%-20s","║►≈ ChemCalc V1.3 ©Shaval_Brown ≈◄║\n");
        System.out.print("╚");
        System.out.print("═".repeat(33));
        System.out.println("╝");
        Menu();
    }
}
