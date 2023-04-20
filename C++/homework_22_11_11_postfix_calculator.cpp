#include <stack>
#include <iostream>
#include <vector>

using namespace std;

int swap(int n1, int n2){
    int a;
    a = n1;
    n1 = n2;
    n2 = a;
    return(n1, n2);
}

class Operation{
    public:
        virtual bool match(char oper) = 0;   
};

class OnOperation : public Operation{
    public:
        virtual int modify(int n1) = 0;
};

class BiOperation : public Operation{
    public:
        virtual int calculate(int n1, int n2) = 0;      
};

class ThrOperation : public Operation{
    public:
        virtual void rotate_last_3(int n1, int n2, int n3) = 0;
};

class AddOper : public BiOperation{
    public:
        int calculate(int n1, int n2) override {
            return n1 + n2;
        }
        bool match(char oper) override {
            return oper == '+';
        }
};

class SubOper : public BiOperation{
    public:
        int calculate(int n1, int n2) override {
            return n1 - n2;
        }
        bool match(char oper) override {
            return oper == '-';
        }
};

class MultiOper : public BiOperation{
    public:
        int calculate(int n1, int n2) override {
            return n1 * n2;
        }
        bool match(char oper) override {
            return oper == '*';
        }
};

class DiviOper : public BiOperation{
    public:
        int calculate(int n1, int n2) override {
            return n1 / n2;
        }
        bool match(char oper) override {
            return oper == '/';
        }
};

class InverOper : public OnOperation{
    public:
        int modify(int n1) override {
            return n1 * (-1);
        }
        bool match(char oper) override {
            return oper == '^';
        }
};

class RotatOper : public ThrOperation{
    public:
        void rotate_last_3(int n1, int n2, int n3) override {
            swap(n1, n3); // 1, 2, 3 -> 3, 2, 1
            swap(n2, n3);//3, 2, 1 -> 3, 1, 2
        }
        bool match(char oper) override {
            return oper == 'r';
        }
};

class FaktOper : public OnOperation{
    public:
        int modify(int n1) override {
            int faktorial = 1;
            if(n1>0){
                for(int i=n1; i>0; i--){
                faktorial = faktorial * i;
                }
            }else{
                n1 = n1 * (-1);
                for(int i=n1; i>0; i--){
                faktorial = faktorial * i;
                }
            }
            return faktorial;
        }
        bool match(char oper) override {
            return oper == '!';
        }
};

class PostfixCalc {
    private:
        stack<int> st;
        vector<BiOperation*> operations;
        
    public:
        PostfixCalc(){
            st = stack<int>();
            operations = vector<BiOperation*>();
            operations.push_back(new AddOper());
            operations.push_back(new SubOper());
        }

        void addNumber(int num){
            st.push(num);
        }

        int calculate(char sign){
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            for(int i=0; i < operations.size(); i++){
                if(operations[i]->match(sign)){
                    int res = operations[i]->calculate(n1, n2);
                    st.push(res);
                    break;
                }
            }
            return st.top();
        }
};

int main() {
    int num;
    char oper;
    PostfixCalc calc = PostfixCalc();
    while(true){
        cout << "#> ";
        cin >> num;
        if(cin.fail()){
            cin.clear();
            cin >> oper;
            cout << "getgot_deathgrips_spotify " << oper << endl;
            int res = calc.calculate(oper);
            cout << "koi ne pishe main " << res << endl;
        }
        else{
            calc.addNumber(num);
        }
    }   
}