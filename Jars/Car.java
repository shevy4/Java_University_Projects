package com.company.Cars4Rent;

public class Car extends Vehicle {
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Display Cars ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        public void View_cars(){
                String[] carsdata = Getcars();
                vehiclemenu(carsdata);
        }

        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
