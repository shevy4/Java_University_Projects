package com.company.Cars4Rent;

import com.jakewharton.fliptables.FlipTable;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class CustomerData extends File_Manipulation {
    private static int cho1 = 0;

    // ~~~~~~~~~~~~~~~~~~~~  Constructor  ~~~~~~~~~~~~~~~~~~~~~~~~~
    public CustomerData(int b){
        cho1 = b;
        Get_Selection();
        Path filepath = Paths.get("/Users/shav/IdeaProjects/Misc/src/com/company/Cars4Rent/Customers.txt");
        write_customer_data(filepath, initialize_file(filepath), Readcustomerdata());
    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~  Read Customer Input ~~~~~~~~~~~~~~~~~~~~
    private List<String> Readcustomerdata() {
        Scanner in = new Scanner(System.in);
        ArrayList<String> Customerdata = new ArrayList<>();
        System.out.println("Enter Name");
        Customerdata.add(in.nextLine());
        System.out.println("Enter Address");
        Customerdata.add(in.nextLine());
        System.out.println("Enter Phone #");
        Customerdata.add(in.nextLine());
        System.out.println("Enter Date Rented");
        Customerdata.add(in.nextLine());
        System.out.println("Enter Expected Return Date");
        Customerdata.add(in.nextLine());
        System.out.println("Enter Deposit Paid");
        Customerdata.add(in.nextLine());
        String plate, brand, model, year = Get_Selection();
        System.out.println("Recorded");
        return Customerdata;
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~ Write Customer Data~~~~~~~~~~~~~~~~~~~

    private void write_customer_data(Path path, boolean exists, List<String> Customer_data){
        try{
            BufferedWriter writer = Files.newBufferedWriter(path, Charset.defaultCharset(), StandardOpenOption.CREATE, StandardOpenOption.APPEND);
            if (exists) {
                for (String data:Customer_data) {
                    writer.append(data).append(",");
                }
                writer.append("\n");
                writer.close();
            }else {
                for (String data:Customer_data) {
                    writer.write(data + ",");
                }
                writer.newLine();
                writer.close();
            }
        } catch (IOException e) {
            System.out.println("Error Initializing Buffer");
        }
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~ Parse License ~~~~~~~~~~~~~~~~~~~~~~
    private String Get_Selection(){
        Vehicle obj = new Vehicle();
        String[] vehicle_Selection_Data = obj.Get_All_Vehicle_Data();
        System.out.println("here - " + Arrays.toString(vehicle_Selection_Data[cho1 - 1].split(",")));
        System.out.println("here - " + vehicle_Selection_Data[cho1-1].split(",")[3]);
        return "test", "testing";
        //return vehicle_Selection_Data[cho1-1].split(",")[1], vehicle_Selection_Data[cho1-1].split(",")[3];
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

}
