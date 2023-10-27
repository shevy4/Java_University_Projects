import os
import pyswip
import tableprint as tb
import PySimpleGUI as sg
from pyswip import Prolog
from tqdm import trange
from time import sleep


# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    Data Input Gui  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

def Get_Layout():
    global point
    point = 0
    layout = [[sg.Text("Full Name")], [sg.Input(key="Name"), ], [sg.Text("Age")], [sg.Input(key="Age")],
              [sg.Text("Temperature (F)")], [sg.Input(key="Temperature")], [sg.Text("Weight (LBS)")],
              [sg.Input(key="Weight")],
              [sg.Text("Country")], [sg.Input(key="Country")],
              [sg.CBox("Dizziness", enable_events=True, key="diz")],
              [sg.CBox("Fainting", enable_events=True, key="faint")],
              [sg.CBox("Blurred Vision", enable_events=True, key="blur")],
              [sg.CBox("Itchy Throat", enable_events=True, key="itchy")],
              [sg.CBox("Abdominal Pain", enable_events=True, key="abdominal")],
              [sg.Text("Systolic Value (mm Hg)"), sg.Input(disabled=True, key="sys")],
              [sg.Text("Diastolic Value (mm Hg)"), sg.Input(disabled=True, key="dia")], [sg.Button("ok", key="close")]
              ]
    window = sg.Window('MOH Expert System', layout, background_color="#181b28")

    userdata = []
    user_events = []

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Reads Input From GUI ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    while True:
        event, values = window.read()

        if event == 'diz' or 'blur' or 'faint':
            window['sys'].update(disabled=False)
            window['dia'].update(disabled=False)
            if event == 'diz':
                user_events.append("dizziness")
                point += 1

            if event == 'blur':
                user_events.append("blurriness")
                point += 1

            if event == 'faint':
                user_events.append("fainting")
                point += 1

        if event == "itchy":
            user_events.append("itchy-throat")
            point += 1

        if event == "abdominal":
            user_events.append("abdominal-pain")
            point += 1

        if not values['diz'] and not values['blur'] and not values['faint']:
            window['sys'].update(disabled=True)
            window['dia'].update(disabled=True)
        if event == "close":
            break

    window.close()

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Appends Input From User To List Then Returns It ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    userdata.append(window["Name"].get())
    userdata.append(window["Age"].get())
    userdata.append(str(round(((int(window["Temperature"].get()) - 32) * (5 / 9)), 3)))
    if float(userdata[len(userdata) - 1]) > 37.2:
        point += 1
    userdata.append(window["Weight"].get())
    userdata.append(window["Country"].get().casefold())

    for x in user_events:
        userdata.append(x)

    if window['sys'].get() != "":
        userdata.append(window['sys'].get())
        userdata.append(window['dia'].get())

    try:
        if len(userdata) != 0 and userdata[0] == ",":
            print("INVALID")
            Get_Layout()
        if int(window['sys'].get()) < 90 and int(window['dia'].get()) < 60:
            userdata.append("low_blood_pressure")
            point += 1
        else:
            userdata.append("normal_pressure")

    except ValueError:
        print("Invalid, Retry")
        Get_Layout()

    return userdata


# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Underlying Conditions GUI ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

def Underlying_Conditions():
    layout = [[sg.CBox("I Drink Alcohol Occasionally", enable_events=True, key="Alcohol")],
              [sg.CBox("I Am Stressed Often", enable_events=True, key="Stress")],
              [sg.CBox("I Exercise Infrequently", enable_events=True, key="Exercise")],
              [sg.CBox("I Have Diabetes", enable_events=True, key="Diabetes")],
              [sg.Text("Other"), sg.Input(key="Other")],
              [sg.Button("ok", key="close")]
              ]
    window = sg.Window('MOH Expert System, Underlying Conditions', layout, background_color="#181b28", resizable=True)
    conditions = []

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Appends Conditions To A List Then Returns It ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    while True:
        event, values = window.read()

        if event == "Alcohol":
            if "alcohol" in conditions:
                conditions.remove("alcohol")
            else:
                conditions.append("alcohol")

        if event == "stress":
            if "stress" in conditions:
                conditions.remove("stress")
            else:
                conditions.append("stress")

        if event == "Exercise":
            if "infrequent_exercise" in conditions:
                conditions.remove("infrequent_exercise")
            else:
                conditions.append("infrequent_exercise")

        if event == "Diabetes":
            if "diabetes" in conditions:
                conditions.remove("diabetes")
            else:
                conditions.append("diabetes")

        if event == "close":
            break
        if event == sg.WIN_CLOSED:
            exit(-1)

    if window["Other"].get().casefold() != "":
        conditions.append(window["Other"].get())

    window.close()

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Display Conditions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    temp_conditions = ""
    for x in conditions:
        temp_conditions = temp_conditions + x + ", "
    if len(temp_conditions) != 0:
        tb.banner("Conditions : " + temp_conditions)
    return conditions


# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Main Menu GUI ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

def menu_gui():
    layout = [[sg.Button("Add To Prolog Database", enable_events=True, key="Add")],
              [sg.Button("Analyze Facts", enable_events=True, key="Analyze")],
              [sg.Button("Exit", key="close")]
              ]
    window = sg.Window('MOH Expert System, Menu', layout, background_color="#181b28", resizable=True)
    while True:
        event, values = window.read()

        if event == "Add":
            window.close()
            ReadData()
            menu()

        if event == "Analyze":
            window.close()
            run_statistics()
            menu()

        if event == "close" or event == sg.WIN_CLOSED:
            exit(0)

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Main Menu Method ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Menu Functions Invoke Guis ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

def menu():
    tb.banner("Welcome To The MOH Expert System")
    menu_gui()

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Read Data Input Method ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Invokes Gui To Get User Input ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

def ReadData():
    userdata = Get_Layout()
    print("Analyzing Data..")
    for _ in trange(len(userdata)):
        sleep(.2)

    Analyze_Data(userdata)


# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Analyze Data Method ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

def Analyze_Data(userdata):
    global variant
    variant = "None"
    risk = "mild"
    covid_headers = ["Name", "Age", "temperature", "Weight", "Country", "Symptoms", "Systolic Value",
                     "Diastolic Value", "Blood Pressure"]
    symptoms = []
    data = []
    check_risk_country(str(userdata[4]))
    count = 0

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Appends Symptoms To List ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    for x in range(len(userdata)):
        if userdata[count] == "dizziness" or userdata[count] == "fainting" or userdata[count] == "blurriness" or \
                userdata[count] \
                == "itchy-throat" or userdata[count] == "abdominal-pain":
            symptoms.append(userdata[count])
            userdata.pop(count)
        else:
            count += 1

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Determines Variant Based On Symptoms ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    if len(symptoms) > 3:
        if ("itchy-throat" and "abdominal-pain") or "abdominal-pain" in symptoms:
            variant = "omnicron"
        if "itchy-throat" and not "abdominal-pain" in symptoms:
            variant = "gamma"
    if len(symptoms) > 2 and point > 3:
        risk = "severe"

    userdata.insert(5, symptoms[0])
    symptoms.pop(0)
    data.append(userdata)

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Displays User Data ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    for x in range(len(symptoms) - 1):
        data.append([" ", " ", " ", " ", " ", symptoms[x], " ", " ", " ", ])
    try:
        data.append(
            ["Variant : " + variant, "Risk : " + risk, " ", " ", " ", symptoms[len(symptoms) - 1], " ", " ", " ", ])
    except IndexError:
        data.append(
            ["Variant : " + variant, "Risk : " + risk, " ", " ", " ", " ", " ", " ", " ", ])

    tb.table(data, covid_headers)

    sleep(2)
    conditions = Underlying_Conditions()
    symptoms.insert(1, userdata[5])
    userdata.pop(5)

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Re-Organizes Symptoms List ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    for _, __ in enumerate(symptoms):
        if __ == "itchy-throat":
            symptoms.pop(_)
            symptoms.insert(_, "itchy_throat")
        if __ == "abdominal-pain":
            symptoms.pop(_)
            symptoms.insert(_, "abdominal_pain")

    add_prolog(userdata, symptoms, conditions, risk, variant)

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Check Risk Country Fact From Database ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Checks Risk Country ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

def check_risk_country(country):
    global point
    prolog = Prolog()
    if not os.path.exists("Database.pl"):
        if country.casefold() == "jamaica":
            point += 1

    else:
        prolog.consult("Database.pl")
        for x in prolog.query("risk_country(X)"):
            if str(x.get("X")).casefold() == country.casefold():
                point = point + 1

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Analyzes Data Input ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Amalgamates Facts Into Statistical Table ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

def run_statistics():
    prolog = Prolog
    prolog.consult("Database.pl")
    total = 0
    at_risk = 0
    age = []
    weight = [0, 0]
    omnicron = 0
    gamma = 0
    hypertension = 0
    headers = ["Total Persons", "At Risk", "Age Range", "Hypertension Risk", "Obesity Risk", "Variants"]
    data = []

    for fact in prolog.query("stat(X, Y)"):
        total += int(fact.get("X"))
        at_risk += int(fact.get("Y"))

    for fact in prolog.query("age(X, Y)"):
        age.append(fact.get("X"))
    age.sort()

    for fact in prolog.query("weight(X, Y)"):
        weight[0] += int(fact.get("Y"))
        if float(fact.get("X")) > 190:
            weight[1] += int(fact.get("Y"))

    for fact in prolog.query("blood_pressure(X, Y)"):
        if fact.get("X") == "high_blood_pressure":
            hypertension += 1

    for fact in prolog.query("variant(X, Y)"):
        if fact.get("X") == "omnicron":
            omnicron += fact.get("Y")
        if fact.get("X") == "gamma":
            gamma += fact.get("Y")

    data.append([str(total), str(int((at_risk / total) * 100)) + "%", str(age[0]) + " - " + str(age[len(age) - 1]),
                 str((hypertension / total) * 100) + "%",
                 str(round((weight[1] / weight[0]) * 100, 1)) + "%", "Omnicron " +
                 str(round((omnicron / total) * 100, 1)) + "%"])
    data.append([" ", " ", " ", " ", " ", "Gamma " + str(round((gamma / total) * 100, 1)) + "%"])
    tb.table(data, headers)

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Add User Input To Database File ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Adds Data Input To Database ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

def add_prolog(userdata, symptoms, conditions, risk, variant):
    global point

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Checks If Database Exits & Writes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    if not os.path.exists("Database.pl"):
        prolog_file = open("Database.pl", "w")
        prolog_file.write("stat(1, 1).\n")
        prolog_file.write("risk_country(jamaica).\n")
        prolog_file.write("age({}, {}).\n".format(userdata[1], "1"))
        prolog_file.write("temperature({}, {}).\n".format(userdata[2], "1"))
        prolog_file.write("weight(" + userdata[3] + ", 1).\n")
        prolog_file.write("country(" + userdata[4] + ", 1).\n")
        for _ in symptoms:
            prolog_file.write("symptoms(" + _ + ", 1).\n")
        prolog_file.write("systolic_value(" + userdata[5] + ", 1).\n")
        prolog_file.write("diastolic_value(" + userdata[6] + ", 1).\n")
        prolog_file.write("blood_pressure(" + userdata[7] + ", 1).\n")
        if len(conditions) != 0:
            for _ in conditions:
                prolog_file.write("condition(" + _.casefold() + ", 1).\n")
        prolog_file.write("risk(" + risk.casefold() + ", 1).\n")
        prolog_file.write("variant(" + variant.casefold() + ", 1).")
        prolog_file.close()
    else:
        prolog_file = open("Database.pl", "r+")
        prolog = Prolog

        file_data = []
        for _, fact in enumerate(prolog_file):
            file_data.append(fact)

        # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ If Database Exists Then Increment ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        if os.path.exists("Database.pl"):

            for fact in prolog.query("stats(X, Y)"):
                for count, file_fact in enumerate(file_data):
                    if file_data[count].split("(")[0] == "stats":
                        file_data.insert(count, "stats({}, {}).\n".format(int(fact.get("X")) + 1, int(fact.get("Y"))
                                                                          + 1))
                        break

            for fact in prolog.query("age(X, Y)"):
                if userdata[1] == str(fact.get("X")):
                    for count, file_fact in enumerate(file_data):
                        if file_fact == "age(" + str(userdata[1]) + ", " + str(fact.get("Y")) + ").\n":
                            file_data.pop(count)
                            file_data.insert(count, "age({}, {}).\n".format(fact.get("X"), int(fact.get("Y")) + 1))

            for fact in prolog.query("age(X, Y)"):
                if userdata[1] != str(fact.get("X")):
                    for count, file_fact in enumerate(file_data):
                        if file_data[count].split("(")[0] == "age":
                            file_data.insert(1, "age({}, {}).\n".format(userdata[1], "1"))
                            break

            for fact in prolog.query("temperature(X, Y)"):
                if userdata[2] == str(fact.get("X")):
                    for count, file_fact in enumerate(file_data):
                        if file_fact == "temperature(" + str(userdata[2]) + ", " + str(fact.get("Y")) + ").\n":
                            file_data.pop(count)
                            file_data.insert(count, "temperature({}, {}).\n".format(fact.get("X"), int(fact.get("Y"))
                                                                                    + 1))

            for fact in prolog.query("temperature(X, Y)"):
                if userdata[2] != str(fact.get("X")):
                    for count, file_fact in enumerate(file_data):
                        if file_data[count].split("(")[0] == "temperature":
                            file_data.insert(count, "temperature({}, {}).\n".format(userdata[2], "1"))
                            break

            for fact in prolog.query("weight(X, Y)"):
                if userdata[3] == str(fact.get("X")):
                    for count, file_fact in enumerate(file_data):
                        if file_fact == "weight(" + str(userdata[3]) + ", " + str(fact.get("Y")) + ").\n":
                            file_data.pop(count)
                            file_data.insert(count, "weight({}, {}).\n".format(fact.get("X"), int(fact.get("Y")) + 1))

            for fact in prolog.query("weight(X, Y)"):
                if userdata[3] != str(fact.get("X")):
                    for count, file_fact in enumerate(file_data):
                        if file_data[count].split("(")[0] == "weight":
                            file_data.insert(count, "weight({}, {}).\n".format(userdata[3], "1"))
                            break

            for fact in prolog.query("country(X, Y)"):
                if userdata[4] == str(fact.get("X")):
                    for count, file_fact in enumerate(file_data):
                        if file_fact == "country(" + str(userdata[4]) + ", " + str(fact.get("Y")) + ").\n":
                            file_data.pop(count)
                            file_data.insert(count, "country({}, {}).\n".format(fact.get("X"), int(fact.get("Y")) + 1))

            for fact in prolog.query("country(X, Y)"):
                if userdata[4] != str(fact.get("X")):
                    for count, file_fact in enumerate(file_data):
                        if file_data[count].split("(")[0] == "country":
                            file_data.insert(count, "country({}, {}).\n".format(userdata[4], "1"))
                            break

            for fact in prolog.query("symptoms(X, Y)"):
                for _ in symptoms:
                    if _ == str(fact.get("X")):
                        for count, file_fact in enumerate(file_data):
                            if file_fact == "symptoms(" + _ + ", " + str(fact.get("Y")) + ").\n":
                                file_data.pop(count)
                                file_data.insert(count, "symptoms({}, {}).\n".format(fact.get("X"), int(fact.get("Y"))
                                                                                     + 1))

            symptom_list = []
            for fact in prolog.query("symptoms(X, Y)"):
                symptom_list.append(fact.get("X"))
            symptom_list = list(set(symptoms) - set(symptom_list))
            for count, file_fact in enumerate(file_data):
                if file_data[count].split("(")[0] == "symptoms":
                    file_data.insert(count, "symptoms({}, {}).\n".format(symptom_list, "1"))
                    break

            for fact in prolog.query("systolic_value(X, Y)"):
                if userdata[len(userdata) - 3] == str(fact.get("X")):
                    for count, file_fact in enumerate(file_data):
                        if file_fact == "systolic_value(" + str(userdata[len(userdata) - 3]) + ", " \
                                + str(fact.get("Y")) + ").\n":
                            file_data.pop(count)
                            file_data.insert(count, "systolic_value({}, {}).\n".format(fact.get("X"), int(fact.get("Y"))
                                                                                       + 1))

            for fact in prolog.query("systolic_value(X, Y)"):
                if userdata[len(userdata) - 3] != str(fact.get("X")):
                    for count, file_fact in enumerate(file_data):
                        if file_data[count].split("(")[0] == "systolic_value":
                            file_data.insert(count, "systolic_value({}, {})".format(userdata[len(userdata) - 3], "1"))
                            break

            for fact in prolog.query("diastolic_value(X, Y)"):
                if userdata[len(userdata) - 2] == str(fact.get("X")):
                    for count, file_fact in enumerate(file_data):
                        if file_fact == "diastolic_value(" + str(userdata[len(userdata) - 2]) + ", " + str(
                                fact.get("Y")) + ").\n":
                            file_data.pop(count)
                            file_data.insert(count,
                                             "diastolic_value({}, {}).\n".format(fact.get("X"), int(fact.get("Y")) + 1))

            for fact in prolog.query("diastolic_value(X, Y)"):
                if userdata[len(userdata) - 2] != str(fact.get("X")):
                    for count, file_fact in enumerate(file_data):
                        if file_data[count].split("(")[0] == "diastolic_value":
                            file_data.insert(count,
                                             "diastolic_value({}, {}).\n".format(userdata[len(userdata) - 2], "1"))
                            break

            for fact in prolog.query("blood_pressure(X, Y)"):
                if userdata[len(userdata) - 1] == str(fact.get("X")):
                    for count, file_fact in enumerate(file_data):
                        if file_fact == "blood_pressure(" + str(userdata[len(userdata) - 1]) + ", " + str(
                                fact.get("Y")) + ").\n":
                            file_data.pop(count)
                            file_data.insert(count,
                                             "blood_pressure({}, {}).\n".format(fact.get("X"), int(fact.get("Y")) + 1))

            for fact in prolog.query("blood_pressure(X, Y)"):
                if userdata[len(userdata) - 1] != str(fact.get("X")):
                    for count, file_fact in enumerate(file_data):
                        if file_data[count].split("(")[0] == "blood_pressure":
                            file_data.insert(count, "blood_pressure({},{}).\n".format(userdata[len(userdata) - 1], "1"))
                            break

            try:
                for fact in prolog.query("condition(X, Y)"):
                    for _ in conditions:
                        if _ == str(fact.get("X")):
                            for count, file_fact in enumerate(file_data):
                                if file_fact == "condition(" + _ + ", " + str(fact.get("Y")) + ").\n":
                                    file_data.pop(count)
                                    file_data.insert(count,
                                                     "condition({}, {}).\n".format(fact.get("X"),
                                                                                   int(fact.get("Y")) + 1))

                for fact in prolog.query("condition(X, Y)"):
                    for _ in conditions:
                        if _ != str(fact.get("X")):
                            file_data.insert(len(file_data) - 2, "condition({}, {}).\n".format(_, "1"))

            except pyswip.prolog.PrologError:
                pass

            for fact in prolog.query("risk(X, Y)"):
                if risk == fact.get("X"):
                    for count, file_fact in enumerate(file_data):
                        if file_fact == "risk(" + risk + ", " + str(
                                fact.get("Y")) + ").\n" or file_fact == "risk(" + risk + ", " + \
                                str(fact.get("Y")) + ").\n":
                            file_data.pop(count)
                            file_data.insert(count, "risk({}, {}).\n".format(fact.get("X"), int(fact.get("Y")) + 1))

            for fact in prolog.query("risk(X, Y)"):
                if risk != fact.get("X"):
                    for count, file_fact in enumerate(file_data):
                        if file_data[count].split("(")[0] == "risk":
                            file_data.insert(count, "risk({},{}).\n".format(risk, "1"))
                            break

            for fact in prolog.query("variant(X, Y)"):
                if variant.casefold() == fact.get("X"):
                    for count, file_fact in enumerate(file_data):
                        if file_data[count].split("(")[0] == "variant":
                            file_data.pop(count)
                            file_data.insert(count, "variant({}, {})".format(fact.get("X"), int(fact.get("Y")) + 1))

            for fact in prolog.query("variant(X, Y)"):
                if variant.casefold() != fact.get("X"):
                    for count, file_fact in enumerate(file_data):
                        if file_data[count].split("(")[0] == "variant":
                            file_data.insert(count, "variant({},{}).".format(variant.casefold(), "1"))

            prolog_file.close()
            os.remove("Database.pl")
            prolog_file = open("Database.pl", "w")

            # ~~~~~~~~~~~~~~~~ Updates Previous Contents Of Database And Replaces It With New Incremented List ~~~~~~~~~~~~~~

            for fact in file_data:
                prolog_file.write(fact)
            prolog_file.close()
    sleep(.3)
    print("Writing To Database")
    for _ in trange(8):
        sleep(.2)


# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Start Of The Program ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

global point

menu()
