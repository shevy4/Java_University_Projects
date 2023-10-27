package com.company.Utech_OOP;
import java.util.ArrayList;

import static com.company.Utech_OOP.Main.in;

public class Admin extends Account {

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  Constructor ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    protected Admin(){
        File_Manipulation AdminFile = new File_Manipulation();
        if (!AdminFile.GetFileStatus()) {
            SavePass(GetPass(), AdminFile);
        }else{
            System.out.println("Enter Admin Password");
            String pass = in.nextLine();
            AdminFile.Verify(pass);
        }
    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  Initialize Admin Pass ~~~~~~~~~~~~~~~~~~~~~~~~~
    private String GetPass(){
        System.out.print("Initializing Users");
        for (int i = 0; i < 3; i++) {
            try {
                Thread.sleep(1000);
                System.out.print(".");
            }
            catch (InterruptedException e) {
                System.out.println("Interrupted");
            }
        }
        System.out.print("\nSet Admin Password : ");
        return in.next();
    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  Record Admin Details ~~~~~~~~~~~~~~~~~~~~~~~~~~
    private void SavePass(String pass, File_Manipulation AdminFile){
        ArrayList<String> data = new ArrayList<>();
        data.add("Admin" + ",");
        data.add(pass);
        AdminFile.Write(data);

    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
