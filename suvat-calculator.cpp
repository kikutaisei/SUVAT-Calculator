#include <iostream>
#include <cmath>
using namespace std;

// Parent class
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

        // Constructor function which calls other private methods (validateSuvat, setSuvat and chooseEquation) within this class
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
                    cout << "\nYour input(s) were invalid. Please try again.";
                }
            }
            chooseEquation();
        }
};

class EquationOne{
    private:
        double u;
        double v;
        double a;
        double t;
        string wantValue;
        
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

class EquationTwo{
    private:
        double s;
        double u;
        double v;
        double a;
        string wantValue;

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

        void solveForS(){
            s = (pow(v, 2) - pow(u, 2)) / (2 * a);
            cout << "\n" << "V² = U² + 2AS" << "   <-- Your chosen equation\n\n";
            cout << v << "² = " << u << "² + 2(" << a << ")(S)" << "   <-- Substitute the numbers\n\n";
            cout << pow(v, 2) << " = " << pow(u, 2) << " + " << 2 * a << "S" << "   <-- Square V and U and Multiply 2A\n\n";
            cout << pow(v, 2) - pow(u, 2) << " = " << 2 * a << "S" << "   <-- Subtract U² on both sides\n\n";
            cout << 2 * a << "S = " << pow(v, 2) - pow(u, 2) << "   <-- Swap around for simplicity\n\n";
            cout << "S = " << s << "   <-- Divide by 2A on both sides\n\n";
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
            cout << "A = " << a << "   <-- Divide by 2S on both sides\n\n";
            cout << "The answer is A = " << a << "ms⁻²\n";
        }
    
    public:
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

int main(){
    cout << "\n"; // Adding extra space

    SuvatQuestion newQuestion;

    if (newQuestion.getChosenEquation() == 1){
        EquationOne newEquationOne(newQuestion.getU(), newQuestion.getV(), newQuestion.getA(), newQuestion.getT(), newQuestion.getWantValue());
    }else if (newQuestion.getChosenEquation() == 2){
        EquationTwo newEquationTwo(newQuestion.getS(), newQuestion.getU(), newQuestion.getV(), newQuestion.getA(), newQuestion.getWantValue());
    }

    cout << "\n"; // Adding extra space
    return 0;
}