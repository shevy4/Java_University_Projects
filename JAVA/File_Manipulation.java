package com.company.Utech_OOP;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.List;
import java.util.Objects;

public class File_Manipulation {

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    public File_Manipulation(){
        // Path path = Paths.get((System.getProperty("user.dir")) + "\\Home_Away.txt" );
        System.out.print("Initializing File");
        Sleep();
        System.out.println();
        if (GetFileStatus()){
            System.out.println("Found... ");
        }else{
            System.out.println("Not Found...");
        }
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  GET FILE STATUS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    public boolean GetFileStatus(){
        Path path = Paths.get((System.getProperty("user.dir")) + "\\Home_Away.txt" );
        return Files.exists(path);
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  WRITE TO FILE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    public void Write(List<String> data){
        Path path = Paths.get((System.getProperty("user.dir")) + "\\Home_Away.txt" );
        try{
            BufferedWriter writer = Files.newBufferedWriter(path, Charset.defaultCharset(), StandardOpenOption.CREATE, StandardOpenOption.APPEND);
            if (Files.exists(path)) {
                for (String x : data){
                    writer.write(x);
                }
                writer.newLine();
                writer.close();
            }
        } catch (IOException e) {
            System.out.println("Error Initializing Buffer");
        }
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  VERIFY PASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    public void Verify(String pass){
        Path path = Paths.get((System.getProperty("user.dir")) + "\\Home_Away.txt" );
        try{
            BufferedReader read = Files.newBufferedReader(path, Charset.defaultCharset());
            String temp = read.readLine();
            if (Objects.equals(pass, temp.split(",")[1])) {
                System.out.println("Verified");
            }else{
                System.out.println("Incorrect");
            }
        } catch (IOException e) {
            System.out.println("Error Reading Buffer");
        }
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  SLEEP FUNCTION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    public void Sleep(){
        for (int i = 0; i < 3; i++) {
            try {
                Thread.sleep(1000);
                System.out.print(".");
            }
            catch (InterruptedException e) {
                System.out.println("Interrupted");
            }
        }
    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}

