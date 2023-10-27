package com.company.Cars4Rent;

public class Truck extends Vehicle {
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Display Trucks ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    public void View_trucks(){

        String[] trucksdata = Gettrucks();
        vehiclemenu(trucksdata);
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
