package com.company.Cars4Rent;

import java.util.Scanner;

public class Cars4Rent_main {
    static Scanner in = new Scanner(System.in);
    static Car car = new Car();
    static Truck truck = new Truck();
    static Bike bike = new Bike();
    static File_Manipulation file = new File_Manipulation();
    private static int cho;
    private static int cho1;

    public static void main(String[] args) {
        menu();
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Menu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    public static void menu() {
        while (true) {
            Banner.menbanner("1.) View Vehicles    2.) Search File    3.) Test      0.) Exit");
            cho = in.nextInt();
            switch (cho) {
                case 1 -> {
                    Banner.menbanner("1.) All Vehicles   2.) Cars   3.) Trucks    4.) Bikes");
                    cho = in.nextInt();
                    while (true) {
                        switch (cho) {
                            case 1 -> car.Viewllvehicles();
                            case 2 -> car.View_cars();
                            case 3 -> truck.View_trucks();
                            case 4 -> bike.View_bikes();
                            default -> System.out.println("Invalid Option");
                        }
                        if (0 < cho && cho < 5){
                            break;
                        }
                        Banner.menbanner("1.) All Vehicles   2.) Cars   3.) Trucks    4.) Bikes");
                        cho = in.nextInt();
                    }
                    con :while(true) {
                        System.out.print("Enter Choice : ");
                        cho1 = in.nextInt();
                        switch (cho){
                            case 1 : if (cho1 > 0 && cho1 <17){
                                break con;
                            }
                            case 2 : if (cho1 > 0 && cho1 <7){
                                break con;
                            }
                            case 3, 4 : if (cho1 > 0 && cho1 < 6){
                                break con;
                            }
                            default: System.out.println("Invalid Selection");
                        }
                    }
                }
                case 2 -> file.Search_File();
                case 0 -> System.exit(0);
                default -> System.out.println("Invalid");
            }
            CustomerData customer = new CustomerData(cho1);
        }
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}

