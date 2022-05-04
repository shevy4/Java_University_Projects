package com.company.Cars4Rent;

public class Bike extends Vehicle {
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Display Bikes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    public void View_bikes(){

        String[] bike_data = Getbikes();
        vehiclemenu(bike_data);
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
