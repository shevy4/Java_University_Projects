package com.company.Cars4Rent;

import com.jakewharton.fliptables.FlipTable;
import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;
import java.util.Scanner;

public class File_Manipulation {

    // ~~~~~~~~~~~~~~~~~~~~~~ Initialize File ~~~~~~~~~~~~~~~~~~~~~
    public Boolean initialize_file(Path filepath){
        if (!Files.exists(filepath)){
            try {
                Files.createFile(filepath);
                System.out.print("Creating File");
                for (int i = 0; i < 3; i++) {
                    System.out.print(".");
                    try {
                        Thread.sleep(1000);
                    }catch (InterruptedException e){
                        System.out.println("Interrupted");
                    }
                }
                System.out.println();
                return false;
            }catch (IOException e){
                System.out.println("Error Creating File");
                System.exit(1);
            }
        }else{
            System.out.print("File Already Exists, Opening");

            for (int i = 0; i < 3; i++) {
                System.out.print(".");
                try {
                    Thread.sleep(1000);
                }catch (InterruptedException e){
                    System.out.println("Interrupted");
                }
            }
            System.out.println();
            //Parse_File(filepath);
        }
        Parse_File(filepath);
        return true;
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~ Parse File Data ~~~~~~~~~~~~~~~~~~~~~~~

    public void Parse_File (Path path){
        try {
            ArrayList<String> temp = new ArrayList<>();
            String[] Header = {"Name","Address","Number","Rented Date","Expected Return","$ Paid","License Plate"};
            BufferedReader reader = Files.newBufferedReader(path);
            int x = 0;
            temp.add(reader.readLine());
            while(temp.get(x) != null){
                //System.out.println("Data = " + temp.get(x));
                x++;
                temp.add(reader.readLine());
            }
            temp.remove(x);
            String[][] Data = new String[x][6];
            x = 0;
            for (String y:temp) {
                Data[x] = y.split(",");
                x++;
            }
            Banner.menbanner(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ File Data ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
            System.out.println(FlipTable.of(Header,Data));
        }catch (IOException e){
            e.printStackTrace();
            System.out.println("Error Creating Buffered Reader");
        }
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~ Search File ~~~~~~~~~~~~~~~~~~~~~~~~~~~

    public void Search_File(){

        Path filepath = Paths.get("/Users/shav/IdeaProjects/Misc/src/com/company/Cars4Rent/Customers.txt");
        Scanner in = new Scanner(System.in);
        Banner.menbanner("1.) License Plate     2.) Brand     3.) Model     4.) Year ");
        int cho = in.nextInt();
        int y;
        switch (cho){
            case 1 : y = 6;
        }
        try {
            ArrayList<String> temp = new ArrayList<>();
            BufferedReader reader = Files.newBufferedReader(filepath);
            int x = 0;
            temp.add(reader.readLine());
            while(temp.get(x) != null){
                if (Objects.equals(temp.get(x).split(",")[6], "7665BG")){
                    System.out.println("Data = " + Arrays.toString(temp.get(x).split(",")));
                }
                x++;
                temp.add(reader.readLine());
            }
            /*temp.remove(x);
            String[][] Data = new String[x][6];
            x = 0;
            for (String y:temp) {
                Data[x] = y.split(",");
                x++;
            }
            Banner.menbanner(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ File Data ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
            System.out.println(FlipTable.of(Header,Data));  */
        }catch (IOException e){
            e.printStackTrace();
            System.out.println("Error Creating Buffered Reader");
        }
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
