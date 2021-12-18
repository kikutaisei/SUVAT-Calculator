#include <iostream>
#include <cmath>
using namespace std;

// Main class which takes, validates and processes user input
class SuvatQuestion{
    private:
        string s;
        string u;
        string v;
        string a;
        string t;
        string wantValue;
        string unknownValue;
        bool unknownValueExists;
        int chosenEquation;

        // Checks the user's input values so they meet the valid criteria
        // Returns true if valid and false if invalid
        // If valid, assigns a boolean value to the unknownValueExists attribute
        bool validateSuvat(string suvatInputs[]){
            int wants = 0;
            int unknowns = 0;
            int knowns = 0;
            for (int i = 0; i < 5; i++){
                if (suvatInputs[i] == "?"){
                    wants += 1;
                }else if(suvatInputs[i] == "-"){
                    unknowns += 1;
                }else{
                    knowns += 1;
                }
            }
            if (wants == 1 && unknowns == 1 && knowns == 3){
                unknownValueExists = true;
                return true;
            }else if (wants == 1 && unknowns == 0 && knowns == 4){
                unknownValueExists = false;
                return true;
            }else{
                return false;
            }
        }

        // Assings the user's input values to their corresponding attributes
        // I.E. S -> s, U -> u, V -> u, A -> a, T -> t
        void setSuvat(string suvatInputs[]){
            for (int i = 0; i < 5; i++){
                if (suvatInputs[i] == "?"){
                    switch (i){
                        case 0:
                            wantValue = "S";
                            break;
                        case 1:
                            wantValue = "U";
                            break;
                        case 2:
                            wantValue = "V";
                            break;
                        case 3:
                            wantValue = "A";
                            break;
                        case 4:
                            wantValue = "T";
                            break;
                    }
                }else if (suvatInputs[i] == "-"){
                    switch (i){
                        case 0:
                            unknownValue = "S";
                            break;
                        case 1:
                            unknownValue = "U";
                            break;
                        case 2:
                            unknownValue = "V";
                            break;
                        case 3:
                            unknownValue = "A";
                            break;
                        case 4:
                            unknownValue = "T";
                            break;
                    }
                }else{
                    switch (i){
                        case 0:
                            s = suvatInputs[i];
                            break;
                        case 1:
                            u = suvatInputs[i];
                            break;
                        case 2:
                            v = suvatInputs[i];
                            break;
                        case 3:
                            a = suvatInputs[i];
                            break;
                        case 4:
                            t = suvatInputs[i];
                            break;
                    }
                }
            }
        }

        // Displays the equation options based on what values were input by the user
        // Assigns the equation chosen by the user to the chosenEquation attribute
        void chooseEquation(){
            string equationOptions[5] = {"V = U + AT", "V² = U² + 2AS", "S = UT + ½AT²", "S = VT - ½AT²", "S = ½(U + V)T"};
            if (unknownValueExists == true){
                int options;
                if (unknownValue == "S"){
                    options = 0;
                }else if (unknownValue == "U"){
                    options = 3;
                }else if (unknownValue == "V"){
                    options = 2;
                }else if (unknownValue == "A"){
                    options = 4;
                }else if (unknownValue == "T"){
                    options = 1;
                }
                while (true){
                    string choiceInputString;
                    cout << "\nYou can use the following equation(s):\n";
                    cout << "1) " << equationOptions[options] << "\n";
                    cout << "Press 1 to confirm and continue: ";
                    cin >> choiceInputString;
                    if (choiceInputString == "1"){
                        chosenEquation = options + 1;
                        break;
                    }else{
                        cout << "Your confirmation was invalid. Please try again.\n";
                    }
                }
            }else{
                int options[4];
                if (wantValue == "S"){
                    options[0] = 1;
                    options[1] = 2;
                    options[2] = 3;
                    options[3] = 4;
                }else if (wantValue == "U"){
                    options[0] = 0;
                    options[1] = 1;
                    options[2] = 2;
                    options[3] = 4;
                }else if (wantValue == "V"){
                    options[0] = 0;
                    options[1] = 1;
                    options[2] = 3;
                    options[3] = 4;
                }else if (wantValue == "A"){
                    options[0] = 0;
                    options[1] = 1;
                    options[2] = 2;
                    options[3] = 3;
                }else if (wantValue == "T"){
                    options[0] = 0;
                    options[1] = 2;
                    options[2] = 3;
                    options[3] = 4;
                }
                while (true){
                    string choiceInputString;
                    cout << "\nYou can use the following equation(s):\n";
                    for (int i = 0; i < 4; i++){
                        cout << i + 1 << ") " << equationOptions[options[i]] << "\n";
                    }
                    cout << "Press the number of your desired equation to confirm and continue: ";
                    cin >> choiceInputString;
                    if (choiceInputString == "1" || choiceInputString == "2" || choiceInputString == "3" || choiceInputString == "4"){
                        int choiceInputInt = stoi(choiceInputString);
                        chosenEquation = options[choiceInputInt - 1] + 1;
                        break;
                    }else{
                        cout << "Your confirmation was invalid. Please try again.\n";
                    }
                }
            }
        }

    public:
        // Getters
        string getS(){
            return s;
        }

        string getU(){
            return u;
        }

        string getV(){
            return v;
        }

        string getA(){
            return a;
        }

        string getT(){
            return t;
        }

        string getWantValue(){
            return wantValue;
        }

        int getChosenEquation(){
            return chosenEquation;
        }

        // Constructor function which prompts the user for input
        // Calls other private methods within this class (validateSuvat, setSuvat and chooseEquation)
        SuvatQuestion(){
                string suvatLetters[5] = {"S", "U", "V", "A", "T"};
                string suvatInputs[5];
            while (true){
                cout << "Enter numbers for known values, ? for values to find and - for unknown values.\n";
                for (int i = 0; i < 5; i++){
                    cout << suvatLetters[i] << " = ";
                    cin >> suvatInputs[i];
                }
                if (validateSuvat(suvatInputs) == true){
                    setSuvat(suvatInputs);
                    break;
                }else{
                    cout << "\nYour input(s) were invalid. Please try again.\n";
                }
            }
            chooseEquation();
        }
};

// Class specific to equation 1 (V = U + AT)
class EquationOne{
    private:
        double u;
        double v;
        double a;
        double t;
        string wantValue;
        
        // Setters
        void setU(string inputU){
            u = stod(inputU);
        }

        void setV(string inputV){
            v = stod(inputV);
        }

        void setA(string inputA){
            a = stod(inputA);
        }

        void setT(string inputT){
            t = stod(inputT);
        }

        void setWantValue(string inputWantValue){
            wantValue = inputWantValue;
        }

        // Solver functions based on the letter set to the wantValue attribute of the SuvatQuestion class
        void solveForU(){
            u = v - (a * t);
            cout << "\n" << "V = U + AT" << "   <-- Your chosen equation\n\n";
            cout << v << " = " << "U + (" << a << ")(" << t << ")" << "   <-- Substitute the numbers\n\n";
            cout << v << " = " << "U + " << a * t << "   <-- Multiply AT\n\n";
            cout << u << " = U" << "   <-- Subtract AT on both sides\n\n";
            cout << "U = " << u << "   <-- Swap around for simplicity\n\n";
            cout << "The answer is U = " << u << "ms⁻¹\n";
        }
        
        void solveForV(){
            v = u + (a * t);
            cout << "\n" << "V = U + AT" << "   <-- Your chosen equation\n\n";
            cout << "V = " << u << " + " << "(" << a << ")" << "(" << t << ")" << "   <-- Substitute the numbers\n\n";
            cout << "V = " << u << " + " << a * t << "   <-- Multiply AT\n\n";
            cout << "V = " << v << "   <-- Add U + AT\n\n";
            cout << "The answer is V = " << v << "ms⁻¹\n";
        }

        void solveForA(){
            a = (v - u) / t;
            cout << "\n" << "V = U + AT" << "   <-- Your chosen equation\n\n";
            cout << v << " = " << u << " + " << t << "A" << "   <-- Substitute the numbers\n\n";
            cout << v - u << " = " << t << "A" << "   <-- Subtract U on both sides\n\n";
            cout << t << "A = " << v - u << "   <-- Swap around for simplicity\n\n";
            cout << "A = " << a << "   <-- Divide (V - U) ÷ T\n\n";
            cout << "The answer is A = " << a << "ms⁻²\n";
        }

        void solveForT(){
            t = (v - u) / a;
            cout << "\n" << "V = U + AT" << "   <-- Your chosen equation\n\n";
            cout << v << " = " << u << " + " << a << "T" << "   <-- Multiply AT\n\n";
            cout << v - u << " = " << a << "T" << "   <-- Subtract U on both sides\n\n";
            cout << a << "T = " << v - u << "   <-- Swap around for simplicity\n\n";
            cout << "T = " << t << "   <-- Divide (V - U) ÷ A\n\n";
            cout << "The answer is T = " << t << "s\n";
        }

    public:
        // Constructor function which takes in the values input by the user in the SuvatQuestion class
        // Runs the setters and solver function based on the letter set to the wantValue attribute of the SuvatQuestion class
        EquationOne(string inputU, string inputV, string inputA, string inputT, string inputWantValue){
            setWantValue(inputWantValue);
            if (wantValue == "U"){
                setV(inputV);
                setA(inputA);
                setT(inputT);
                solveForU();
            }else if (wantValue == "V"){
                setU(inputU);
                setA(inputA);
                setT(inputT);
                solveForV();
            }else if (wantValue == "A"){
                setU(inputU);
                setV(inputV);
                setT(inputT);
                solveForA();
            }else if (wantValue == "T"){
                setU(inputU);
                setV(inputV);
                setA(inputA);
                solveForT();
            }
        }
};

// Class specific to equation 2 (V² = U² + 2AS)
class EquationTwo{
    private:
        double s;
        double u;
        double v;
        double a;
        string wantValue;

        // Setters
        void setS(string inputS){
            s = stod(inputS);
        }

        void setU(string inputU){
            u = stod(inputU);
        }

        void setV(string inputV){
            v = stod(inputV);
        }

        void setA(string inputA){
            a = stod(inputA);
        }

        void setWantValue(string inputWantValue){
            wantValue = inputWantValue;
        }

        // Solver functions based on the letter set to the wantValue attribute of the SuvatQuestion class
        void solveForS(){
            s = (pow(v, 2) - pow(u, 2)) / (2 * a);
            cout << "\n" << "V² = U² + 2AS" << "   <-- Your chosen equation\n\n";
            cout << v << "² = " << u << "² + 2(" << a << ")(S)" << "   <-- Substitute the numbers\n\n";
            cout << pow(v, 2) << " = " << pow(u, 2) << " + " << 2 * a << "S" << "   <-- Square V and U and Multiply 2A\n\n";
            cout << pow(v, 2) - pow(u, 2) << " = " << 2 * a << "S" << "   <-- Subtract U² on both sides\n\n";
            cout << 2 * a << "S = " << pow(v, 2) - pow(u, 2) << "   <-- Swap around for simplicity\n\n";
            cout << "S = " << s << "   <-- Divide 2A on both sides\n\n";
            cout << "The answer is S = " << s << "m\n";
        }

        void solveForU(){
            u = sqrt(pow(v, 2) - (2 * a * s));
            cout << "\n" << "V² = U² + 2AS" << "   <-- Your chosen equation\n\n";
            cout << v << "² = U² + 2(" << a << ")(" << s << ")" << "   <-- Substitute the numbers\n\n";
            cout << pow(v, 2) << " = U² + " << 2 * a * s << "   <-- Square V and Multiply 2AS\n\n";
            cout << (pow(v, 2)) - (2 * a * s) << " = U²" << "   <-- Subtract 2AS on both sidesn\n\n";
            cout << "U² = " << (pow(v, 2)) - (2 * a * s) << "   <-- Swap around for simplicity\n\n";
            cout << "U = " << u << "   <-- Square root on both sides\n\n";
            cout << "The answer is U = " << u << "ms⁻¹\n";
        }

        void solveForV(){
            v = sqrt(pow(u, 2) + (2 * a * s));
            cout << "\n" << "V² = U² + 2AS" << "   <-- Your chosen equation\n\n";
            cout << "V² = " << u << "² + 2(" << a << ")(" << s << ")" << "   <-- Substitute the numbers\n\n";
            cout << "V² = " << pow(u, 2) << " + " << 2 * a * s << "   <-- Square U and multiply 2AS\n\n";
            cout << "V² = " << pow(u, 2) + (2 * a * s) << "   <-- Add U² and 2AS\n\n";
            cout << "V = " << v << "   <-- Square root on both sides\n\n";
            cout << "The answer is V = " << v << "ms⁻¹\n"; 
        }

        void solveForA(){
            a = (pow(v, 2) - pow(u, 2)) / (2 * s);
            cout << "\n" << "V² = U² + 2AS" << "   <-- Your chosen equation\n\n";
            cout << v << "² = " << u << "² + 2(A)(" << s << ")" << "   <-- Substitute the numbers\n\n";
            cout << pow(v, 2) << " = " << pow(u, 2) << " + " << 2 * s << "A" << "   <-- Square V and U and Multiply 2S\n\n";
            cout << pow(v, 2) - pow(u, 2) << " = " << 2 * s << "A" << "   <-- Subtract U² on both sides\n\n";
            cout << 2 * s << "A = " << pow(v, 2) - pow(u, 2) << "   <-- Swap around for simplicity\n\n";
            cout << "A = " << a << "   <-- Divide 2S on both sides\n\n";
            cout << "The answer is A = " << a << "ms⁻²\n";
        }
    
    public:
        // Constructor function which takes in the values input by the user in the SuvatQuestion class
        // Runs the setters and solver function based on the letter set to the wantValue attribute of the SuvatQuestion class
        EquationTwo(string inputS, string inputU, string inputV, string inputA, string inputWantValue){
            setWantValue(inputWantValue);
            if (wantValue == "S"){
                setU(inputU);
                setV(inputV);
                setA(inputA);
                solveForS();
            }else if (wantValue == "U"){
                setS(inputS);
                setV(inputV);
                setA(inputA);
                solveForU();
            }else if (wantValue == "V"){
                setS(inputS);
                setU(inputU);
                setA(inputA);
                solveForV();
            }else if (wantValue == "A"){
                setS(inputS);
                setU(inputU);
                setV(inputV);
                solveForA();
            }
        }
};

// Class specific to equation 3 (S = UT + ½AT²)
class EquationThree{
    private:
        double s;
        double u;
        double a;
        double tSingle; // Stores t from user input (When t is one value)
        double tQuadratic[2]; // Stores t for output (When t is wanted and the quadratic equation is used)
        string wantValue;

        // Setters
        void setS(string inputS){
            s = stod(inputS);
        }

        void setU(string inputU){
            u = stod(inputU);
        }

        void setA(string inputA){
            a = stod(inputA);
        }

        void setTSingle(string inputTSingle){
            tSingle = stod(inputTSingle);
        }

        void setWantValue(string inputWantValue){
            wantValue = inputWantValue;
        }

        // Solver functions based on the letter set to the wantValue attribute of the SuvatQuestion class
        void solveForS(){
            s = (u * tSingle) + (0.5 * a * pow(tSingle, 2));
            cout << "\n" << "S = UT + ½AT²" << "   <-- Your chosen equation\n\n";
            cout << "S = (" << u << ")(" << tSingle << ") + ½(" << a << ")(" << tSingle << ")²" << "   <-- Substitute the numbers\n\n";
            cout << "S = " << u * tSingle << " + " << 0.5 * a * pow(tSingle, 2) << "   <-- Multiply UT and ½AT²\n\n";
            cout << "S = " << s << "   <-- Add UT and ½AT²\n\n";
            cout << "The answer is S = " << s << "m\n";
        }

        void solveForU(){
            u = (s - (0.5 * a * pow(tSingle, 2))) / tSingle;
            cout << "\n" << "S = UT + ½AT²" << "   <-- Your chosen equation\n\n";
            cout << s << " = (U)(" << tSingle << ") + ½(" << a << ")(" << tSingle << ")²" << "   <-- Substitute the numbers\n\n";
            cout << s << " = " << tSingle << "U + " << 0.5 * a * pow(tSingle, 2) << "   <-- Multiply UT and ½AT²\n\n";
            cout << s - (0.5 * a * pow(tSingle, 2)) <<  " = " << tSingle << "U" << "   <-- Subtract ½AT² on both sides\n\n";
            cout << tSingle << "U = " << s - (0.5 * a * pow(tSingle, 2)) << "   <-- Swap around for simplicity\n\n";
            cout << "U = " << u << "   <-- Divide T on both sides\n\n";
            cout << "The answer is U = " << u << "ms⁻¹\n";
        }

        void solveForA(){
            a = (s - (u * tSingle)) / (0.5 * pow(tSingle, 2));
            cout << "\n" << "S = UT + ½AT²" << "   <-- Your chosen equation\n\n";
            cout << s << " = (" << u << ")(" << tSingle << ") + ½(A)(" << tSingle << ")²" << "   <-- Substitute the numbers\n\n";
            cout << s << " = " << u * tSingle << " + " << 0.5 * pow(tSingle, 2) << "A" << "   <-- Multiply UT and ½AT²\n\n";
            cout << s - (u * tSingle) << " = " << 0.5 * pow(tSingle, 2) << "A" << "   <-- Subtract UT on both sides\n\n";
            cout << 0.5 * pow(tSingle, 2) << "A" << " = " << s - (u * tSingle) << "   <-- Swap around for simplicity\n\n";
            cout << "A = " << a << "   <-- Divide T on both sides\n\n";
            cout << "The answer is A = " << a << "ms⁻²\n";
        }

        void solveForTQuadratic(){
            tQuadratic[0] = (-u + sqrt(pow(u, 2) - (2 * a * (-s)))) / a;
            tQuadratic[1] = (-u - sqrt(pow(u, 2) - (2 * a * (-s)))) / a;
            cout << "\n" << "S = UT + ½AT²" << "   <-- Your chosen equation\n\n";
            cout << s << " = (" << u << ")(T) + ½(" << a << ")(T)²" << "   <-- Substitute the numbers\n\n";
            cout << s << " = " << u << "T + " << 0.5 * a << "T²" << "   <-- Multiply UT and ½A\n\n";
            cout << 0.5 * a << "T² + " << u << "T + " << -s << " = 0" << "   <-- Rearrange to quadratic equation format\n\n";
            cout << "[USING QUADRATIC FORMULA]\n\n";
            cout << "The answers are T = " << tQuadratic[0] << "s and T = " << tQuadratic[1] << "s\n";
        }
    
    public:
        // Constructor function which takes in the values input by the user in the SuvatQuestion class
        // Runs the setters and solver function based on the letter set to the wantValue attribute of the SuvatQuestion class
        EquationThree(string inputS, string inputU, string inputA, string inputTSingle, string inputWantValue){
            setWantValue(inputWantValue);
            if (wantValue == "S"){
                setU(inputU);
                setA(inputA);
                setTSingle(inputTSingle);
                solveForS();
            }else if (wantValue == "U"){
                setS(inputS);
                setA(inputA);
                setTSingle(inputTSingle);
                solveForU();
            }else if (wantValue == "A"){
                setS(inputS);
                setU(inputU);
                setTSingle(inputTSingle);
                solveForA();
            }else if (wantValue == "T"){
                setS(inputS);
                setU(inputU);
                setA(inputA);
                solveForTQuadratic();
            }
        }
};

// Class specific to equation 4 (S = VT - ½AT²)
class EquationFour{
    private:
        double s;
        double v;
        double a;
        double tSingle; // Stores t from user input (When t is one value)
        double tQuadratic[2]; // Stores t for output (When t is wanted and the quadratic equation is used)
        string wantValue;

        // Setters
        void setS(string inputS){
            s = stod(inputS);
        }

        void setV(string inputV){
            v = stod(inputV);
        }

        void setA(string inputA){
            a = stod(inputA);
        }

        void setTSingle(string inputTSingle){
            tSingle = stod(inputTSingle);
        }

        void setWantValue(string inputWantValue){
            wantValue = inputWantValue;
        }

        // Solver functions based on the letter set to the wantValue attribute of the SuvatQuestion class
        void solveForS(){
            s = (v * tSingle) - (0.5 * a * pow(tSingle, 2));
            cout << "\n" << "S = VT - ½AT²" << "   <-- Your chosen equation\n\n";
            cout << "S = (" << v << ")(" << tSingle << ") - ½(" << a << ")(" << tSingle << ")²" << "   <-- Substitute the numbers\n\n";
            cout << "S = " << v * tSingle << " - " << 0.5 * a * pow(tSingle, 2) << "   <-- Multiply VT and ½AT²\n\n";
            cout << "S = " << s << "   <-- Add VT and ½AT²\n\n";
            cout << "The answer is S = " << s << "m\n";
        }
        
        void solveForV(){
            v = (s + (0.5 * a * pow(tSingle, 2))) / tSingle;
            cout << "\n" << "S = VT - ½AT²" << "   <-- Your chosen equation\n\n";
            cout << s << " = (V)(" << tSingle << ") - ½(" << a << ")(" << tSingle << ")²" << "   <-- Substitute the numbers\n\n";
            cout << s << " = " << tSingle << "V - " << 0.5 * a * pow(tSingle, 2) << "   <-- Multiply VT and ½AT²\n\n";
            cout << s + (0.5 * a * pow(tSingle, 2)) <<  " = " << tSingle << "V" << "   <-- Add ½AT² on both sides\n\n";
            cout << tSingle << "V = " << s + (0.5 * a * pow(tSingle, 2)) << "   <-- Swap around for simplicity\n\n";
            cout << "V = " << v << "   <-- Divide T on both sides\n\n";
            cout << "The answer is V = " << v << "ms⁻¹\n";
        }
        
        void solveForA(){
            a = (-s + (v * tSingle)) / (0.5 * pow(tSingle, 2));
            cout << "\n" << "S = VT - ½AT²" << "   <-- Your chosen equation\n\n";
            cout << s << " = (" << v << ")(" << tSingle << ") - ½(A)(" << tSingle << ")²" << "   <-- Substitute the numbers\n\n";
            cout << s << " = " << v * tSingle << " - " << 0.5 * pow(tSingle, 2) << "A" << "   <-- Multiply VT and ½AT²\n\n";
            cout << s - (v * tSingle) << " = " << -(0.5 * pow(tSingle, 2)) << "A" << "   <-- Subtract VT on both sides\n\n";
            cout << -(s - (v * tSingle)) << " = " << 0.5 * pow(tSingle, 2) << "A" << "   <-- Divide -1 on both sides\n\n";
            cout << 0.5 * pow(tSingle, 2) << "A" << " = " << -(s - (v * tSingle)) << "   <-- Swap around for simplicity\n\n";
            cout << "A = " << a << "   <-- Divide T on both sides\n\n";
            cout << "The answer is A = " << a << "ms⁻²\n";
        }
        
        void solveForTQuadratic(){
            tQuadratic[0] = -(-v + sqrt(pow(v, 2) - (2 * a * (s)))) / a;
            tQuadratic[1] = -(-v - sqrt(pow(v, 2) - (2 * a * (s)))) / a;
            cout << "\n" << "S = VT - ½AT²" << "   <-- Your chosen equation\n\n";
            cout << s << " = (" << v << ")(T) - ½(" << a << ")(T)²" << "   <-- Substitute the numbers\n\n";
            cout << s << " = " << v << "T - " << 0.5 * a << "T²" << "   <-- Multiply VT and ½A\n\n";
            cout << -(0.5 * a) << "T² + " << v << "T + " << -s << " = 0" << "   <-- Rearrange to quadratic equation format\n\n";
            cout << "[USING QUADRATIC FORMULA]\n\n";
            cout << "The answers are T = " << tQuadratic[0] << "s and T = " << tQuadratic[1] << "s\n";
        }
    
    public:
        // Constructor function which takes in the values input by the user in the SuvatQuestion class
        // Runs the setters and solver function based on the letter set to the wantValue attribute of the SuvatQuestion class
        EquationFour(string inputS, string inputV, string inputA, string inputTSingle, string inputWantValue){
            setWantValue(inputWantValue);
            if (wantValue == "S"){
                setV(inputV);
                setA(inputA);
                setTSingle(inputTSingle);
                solveForS();
            }else if (wantValue == "V"){
                setS(inputS);
                setA(inputA);
                setTSingle(inputTSingle);
                solveForV();
            }else if (wantValue == "A"){
                setS(inputS);
                setV(inputV);
                setTSingle(inputTSingle);
                solveForA();
            }else if (wantValue == "T"){
                setS(inputS);
                setV(inputV);
                setA(inputA);
                solveForTQuadratic();
            }
        }
};

// Class specific to equation 5 (S = ½(U + V)T)
class EquationFive{
    private:
        double s;
        double u;
        double v;
        double t;
        string wantValue;

        // Setters
        void setS(string inputS){
            s = stod(inputS);
        }

        void setU(string inputU){
            u = stod(inputU);
        }

        void setV(string inputV){
            v = stod(inputV);
        }

        void setT(string inputT){
            t = stod(inputT);
        }

        void setWantValue(string inputWantValue){
            wantValue = inputWantValue;
        }

        // Solver functions based on the letter set to the wantValue attribute of the SuvatQuestion class
        void solveForS(){
            s = 0.5 * (u + v) * t;
            cout << "\n" << "S = ½(U + V)T" << "   <-- Your chosen equation\n\n";
            cout << "S = ½(" << u << " + " << v << ")(" << t << ")" << "   <-- Substitute the numbers\n\n";
            cout << "S = ½(" << u + v << ")(" << t << ")" << "   <-- Add U + V\n\n";
            cout << "S = " << s << "   <-- Multiply ½(U + V)T\n\n";
            cout << "The answer is S = " << s << "m\n";
        }

        void solveForU(){
            u = (s / (0.5 * t)) - v;
            cout << "\n" << "S = ½(U + V)T" << "   <-- Your chosen equation\n\n";
            cout << s << " = ½(U + " << v << ")(" << t << ")" << "   <-- Substitute the numbers\n\n";
            cout << s << " = " << 0.5 * t << "(U + " << v << ")" << "   <-- Multiply ½T\n\n";
            cout << s / (0.5 * t) << " = U + " << v << "   <-- Divide ½A on both sides\n\n";
            cout << "U + " << v << " = " << s / (0.5 * t) << "   <-- Swap around for simplicity\n\n";
            cout << "U = " << u << "   <-- Subtract V on both sides\n\n";
            cout << "The answer is U = " << u << "ms⁻¹\n";
        }

        void solveForV(){
            v = (s / (0.5 * t)) - u;
            cout << "\n" << "S = ½(U + V)T" << "   <-- Your chosen equation\n\n";
            cout << s << " = ½(" << u << " + V)(" << t << ")" << "   <-- Substitute the numbers\n\n";
            cout << s << " = " << 0.5 * t << "(" << u << " + V)" << "   <-- Multiply ½T\n\n";
            cout << s / (0.5 * t) << " = " << u << " + V" << "   <-- Divide ½A on both sides\n\n";
            cout << u << " + V = " << s / (0.5 * t) << "   <-- Swap around for simplicity\n\n";
            cout << "V = " << v << "   <-- Subtract V on both sides\n\n";
            cout << "The answer is V = " << v << "ms⁻¹\n";
        }

        void solveForT(){
            t = s / (0.5 * (u + v));
            cout << "\n" << "S = ½(U + V)T" << "   <-- Your chosen equation\n\n";
            cout << s << " = ½(" << u << " + " << v << ")(T)" << "   <-- Substitute the numbers\n\n";
            cout << s << " = ½(" << u + v << ")(T)" << "   <-- Add U + V\n\n";
            cout << s << " = " << 0.5 * (u + v) << "T" << "   <-- Multiply ½(U + V)\n\n";
            cout << 0.5 * (u + v) << "T = " << s << "   <-- Swap around for simplicity\n\n";
            cout << "T = " << t << "   <-- Divide ½(U + V) on both sides\n\n";
            cout << "The answer is T = " << t << "s\n";
        }

    public:
        // Constructor function which takes in the values input by the user in the SuvatQuestion class
        // Runs the setters and solver function based on the letter set to the wantValue attribute of the SuvatQuestion class
        EquationFive(string inputS, string inputU, string inputV, string inputT, string inputWantValue){
            setWantValue(inputWantValue);
            if (wantValue == "S"){
                setU(inputU);
                setV(inputV);
                setT(inputT);
                solveForS();
            }else if (wantValue == "U"){
                setS(inputS);
                setV(inputV);
                setT(inputT);
                solveForU();
            }else if (wantValue == "V"){
                setS(inputS);
                setU(inputU);
                setT(inputT);
                solveForV();
            }else if (wantValue == "T"){
                setS(inputS);
                setU(inputU);
                setV(inputV);
                solveForT();
            }
        }
};

// Main function to be run during execution
int main(){
    cout << "\n"; // Adding extra space

    // Creating a new object of the SuvatQuestion class for user input
    SuvatQuestion newQuestion;

    // If statement which creates a new object of one of the five EquationX classes depending on the eqution chosen by the user
    if (newQuestion.getChosenEquation() == 1){
        EquationOne newEquationOne(newQuestion.getU(), newQuestion.getV(), newQuestion.getA(), newQuestion.getT(), newQuestion.getWantValue());
    }else if (newQuestion.getChosenEquation() == 2){
        EquationTwo newEquationTwo(newQuestion.getS(), newQuestion.getU(), newQuestion.getV(), newQuestion.getA(), newQuestion.getWantValue());
    }else if (newQuestion.getChosenEquation() == 3){
        EquationThree newEquationThree(newQuestion.getS(), newQuestion.getU(), newQuestion.getA(), newQuestion.getT(), newQuestion.getWantValue());
    }else if (newQuestion.getChosenEquation() == 4){
        EquationFour newEquationFour(newQuestion.getS(), newQuestion.getV(), newQuestion.getA(), newQuestion.getT(), newQuestion.getWantValue());
    }else if (newQuestion.getChosenEquation() == 5){
        EquationFive newEquationFive(newQuestion.getS(), newQuestion.getU(), newQuestion.getV(), newQuestion.getT(), newQuestion.getWantValue());
    }

    cout << "\n"; // Adding extra space
    return 0;
}