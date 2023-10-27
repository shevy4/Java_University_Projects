package com.company.Cars4Rent;

import com.jakewharton.fliptables.FlipTable;
import org.apache.commons.lang3.ArrayUtils;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

@SuppressWarnings("deprecation")
public class Vehicle {
    private final String[] vehicledata = new String[16];
    private String[] Header;
    private static final String[] vehicle_Selection_Data = new String[16];

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Constructor ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    public Vehicle(){
        AllVehicles();
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~Parse General vehicle Data ~~~~~~~~~~~~~~~~~~~~~~~~
    private void AllVehicles() {
        {
            try {
                BufferedReader br = new BufferedReader(new FileReader("/Users/shav/IdeaProjects/Misc/src/com/company/Cars4Rent/Vehicles.csv"));
                String temp = br.readLine();

                Header = temp.split(",");
                int x = 0;
                while (temp != null && x != 16) {
                    temp = br.readLine();
                    vehicledata[x] = temp;
                    x++;
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Parse Car Data ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    private String[] cars (){
        String[] carsdata = new String[6];
        System.arraycopy(vehicledata, 0, carsdata, 0, carsdata.length);
        return carsdata;

    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Return Car Data ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    public String[] Getcars(){

        return cars();
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Parse Truck Data ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    private String[] trucks (){
        String[] truckdata = new String[5];
        int x = 0;
        for (int i = cars().length; i < cars().length + 5; i++) {
            truckdata[x] = vehicledata[i];
            x++;
        }
        return truckdata;

    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Return Truck Data ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    public String[] Gettrucks(){

        return trucks();
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Parse Bike Data ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    private String[] bike (){
        String[] bikedata = new String[5];
        int x = 0;
        for (int i = trucks().length + cars().length; i < cars().length + trucks().length + 5; i++) {
            bikedata[x] = vehicledata[i];
            x++;
        }
        return bikedata;

    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Return Bike Data ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    public String[] Getbikes(){

        return bike();
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Return All Vehicle Data ~~~~~~~~~~~~~~~~~~~~~~~~~~
    public String[] Get_All_Vehicle_Data () {

        return vehicle_Selection_Data;
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Display All Vehicles ~~~~~~~~~~~~~~~~~~~~~~~~~~~
    public void Viewllvehicles(){

        vehiclemenu(vehicledata);
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Obviously testing something ~~~~~~~~~~~~~~~~~~
    public void test(){
        File_Manipulation obj = new File_Manipulation();
        obj.Search_File();
        System.exit(0);

    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Create All Vehicle Menu ~~~~~~~~~~~~~~~~~~~~~~~~
    public void vehiclemenu(String[] data){
        String[] Headers = new String[Header.length+1];
        Headers[0] = "Choice #";
        System.arraycopy(Header, 0, Headers, 1, Header.length + 1 - 1);
        String[][] Data = new String[data.length][15];
        String[] temp1;
        int x = 0;
        try {
        for (int i = 0; i < data.length; i++) {
            temp1 = ArrayUtils.add(data[x].split(","), 0, String.valueOf(i + 1));
            temp1[13] = temp1[13] + "," + temp1[14];
            switch (temp1[1]) {
                case "8638HS", "4337EB", "7752BI" -> temp1[14] = temp1[15];
                default -> temp1[14] = temp1[15] + "," + temp1[16];
            }
            vehicle_Selection_Data[x] = Arrays.toString(temp1).replaceAll("\\[", "").replaceAll("]","");
            x++;
            System.arraycopy(temp1, 0, Data[i], 0, 15);
            }
        }catch (ArrayIndexOutOfBoundsException e){
            e.printStackTrace();
        }
        System.out.println(FlipTable.of(Headers, Data));
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


}
