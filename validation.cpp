#include<iostream>
#include<string>
using namespace std;

class IP{
    private:
    string ip[4];
    string addr;
    string msg="";
    size_t dot;
    int error = 0;

    public:
    IP(string addr){
        this->addr = addr;
    }

    string validation(){
        msg = addr;
        int n = -1, m = 0, flag=0;

        while (msg[n] != msg.back()){
            n++;
            for(int m=0; m<4; m++){
            dot = msg.find(".");
            ip[m] = msg.substr(0, dot);
            msg = msg.substr(dot+1);
            }
        }

        for(int m=0; m<4; m++){
            string a = ip[m];
            if (stoi(a)>255 || stoi(a)<0){
                return "Not a valid IP address!!";
            }
        }
        error = 1;
        return "Valid IP address!!";
    }

    string findClass(){
        if(error == 1){
            if(stoi(ip[0]) >= 0 && stoi(ip[0]) <= 127){return "Class A";}
            if(stoi(ip[0]) >= 128 && stoi(ip[0]) <= 191){return "Class B";}
            if(stoi(ip[0]) >= 192 && stoi(ip[0]) <= 223){return "Class C";}
            if(stoi(ip[0]) >= 224 && stoi(ip[0]) <= 239){return "Class D";}
            if(stoi(ip[0]) >= 240 && stoi(ip[0]) <= 255){return "Class E";}
            else{ return "Error"; }
        }
    }


};

int main(){

    string ipaddr;
    cout << "Enter IP address: ";
    cin >> ipaddr;
    IP a(ipaddr);
    cout<< "It is a " << a.validation()<<endl;
    cout<<"Having " << a.findClass()<<endl;
    cout << '\n';
    return 0;
}