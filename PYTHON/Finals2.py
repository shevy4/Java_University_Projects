from tqdm import trange
from time import sleep
import tableprint as tb

""""~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Brown : 2001407
Date: 23/4/21
Description: Utech Programming 1 Final Book Rental System
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"""
ISBN, title, source, condition, purchase, data, data2 = [], [], [], [], [], [], []
donated, purchased, excellent, good, fair, temp, tot_fees, count = 0, 0, 0, 0, 0, 2, 0, 0

#                                                 Validation Of Password
pas = input("Enter Password \n")
while True:
    if temp < 1:  # Checks If Attempts Are Remaining
        exit()
    if pas != 'bob':
        print("Invalid... Attempts : ", temp)  # Displays Attempts Remaining
        temp -= 1
        pas = input("Enter Pass \n")
    else:
        break

#                                               Validate ISBN
while count < 10:
    ISBN.append(input("Enter ISBN # Or xxx To Continue\n"))
    if ISBN[count].casefold() == 'xxx':
        del ISBN[count]
        break
    title.append(input("Enter Title Of Book\n"))

    #                                               Validate Condition

    print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\tCondition\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n| "
          "1.) Excellent\t\t\t\t\t|\n| 2.) Good\t\t\t\t\t\t|\n| 3.) Fair\t\t\t\t\t\t|\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
    condition.append(int(input("Enter Condition 1-3\n")))
    while True:
        if condition[count] != 1 and condition[count] != 2 and condition[count] != 3:
            print("Invalid")
            condition.pop()  # Removes Input From List If Condition Invalid
            condition.append(int(input("Enter Condition 1-3\n")))
        else:
            break  # Exit Validation

    #                                  Evaluates Condition[count] And Increment Variables Accordingly
    if condition[count] == 1:
        condition[count] = "Excellent"
        excellent += 1

    if condition[count] == 2:
        condition[count] = "Good"
        good += 1

    if condition[count] == 3:
        condition[count] = "Fair"
        fair += 1
    #                                            Validate Source

    print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\tSource\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n| "
          "1.) Donated\t\t\t\t\t|\n| 2.) Purchased\t\t\t\t\t|\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
    source.append(int(input("Enter Source 1-3\n")))
    while True:
        if source[count] != 1 and source[count] != 2 and source[count] != 3:
            print("Invalid")
            source.pop()  # Removes Source From List If Invalid
            source.append(int(input("Enter Source 1-3\n")))
        else:
            break  # Exit Validation

    #                                 Evaluates source[count] & Assign 'Donated' / 'Purchased' To It
    if source[count] == 1:
        source[count] = 'Donated'
        purchase.append(float(0))
        donated += 1

    if source[count] == 2:
        purchase.append(float(input("Enter Purchase Amount\n$")))
        while True:
            if purchase[count] < 1:
                print("Invalid")
                purchase.pop()  # Remove Invalid Purchase Amount From List
                purchase.append(float("Enter Purchase Amount\n"))
            else:
                break
        if purchase[count] < 3001:
            source[count] = 'Purchased'
            purchased += 1
        else:
            #         Remove Invalid Data From All Lists, Decrement Values & Proceed With Next Iteration

            print("The Student Union Will Not Purchase TextBooks In Excess Of $3,000")
            purchase.pop()
            ISBN.pop()
            title.pop()
            source.pop()
            if condition[count] == 'Excellent':
                excellent -= 1
            if condition[count] == 'Good':
                good -= 1
            if condition[count] == 'Fair':
                fair -= 1
            condition.pop()
            continue
    count += 1    # Increment While Loop And Repeat

#                               Output User Data In Table
try:
    #                     Populate Table Headers And User Data
    headers = ['ISBN #', 'Title', 'Condition', 'Source', 'Purchased', 'Fee']
    for count, temp in enumerate(ISBN):

        #                        Assimilate Donated Fees And Data In Body Of Table

        if source[count] == 'Donated':       # If source[count] == 'Donated' Evaluate condition[count] & Print Fee Based On Condition
            if condition[count] == 'Excellent':
                data.append([ISBN[count], title[count], condition[count], source[count],
                             "$" + str(purchase[count].__round__(2)), "$1,000"])
                tot_fees += 1000
            if condition[count] == 'Good':
                data.append([ISBN[count], title[count], condition[count], source[count],
                             "$" + str(purchase[count].__round__(2)), "$800"])
                tot_fees += 800
            if condition[count] == 'Fair':
                data.append([ISBN[count], title[count], condition[count], source[count],
                             "$" + str(purchase[count].__round__(2)), "$750"])
                tot_fees += 750

        #                        Assimilate Purchased Fee Of 75% & Data In Body Of Table

        if source[count] == 'Purchased':
            data.append(
                [ISBN[count], title[count], condition[count], source[count], "$" + str(purchase[count].__round__(2)),
                 "$" + str(purchase[count] * .75)])
            tot_fees += purchase[count] * .75

    #                       Print Invoice Logo

    print("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓")
    print("\n \t\t\t_ __ _ _  _ ____ _ ____ ____\n"
          " \t\t\t| | \\|  \\/  [__] | |___ |===")

    #                           Animate Invoice Logo
    for temp in trange(excellent + good + fair):
        sleep(1)

    #                      Construct And Populate Table With User Data And Results
    tb.table(data, headers)
    headers2 = ['Donated', 'Purchased', 'Excellent', 'Good', 'Fair', 'Inventory', 'Total Fees']
    data2.append([str(donated), str(purchased), str(excellent), str(good), str(fair), str(excellent + good + fair),
                  str(tot_fees)])
    tb.banner("»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»» REPORT »»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»")
    tb.table(data2, headers2)

#                            Catch Exception If No User Data Was Entered
except TypeError:
    print("Invalid, No Data")
