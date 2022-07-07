#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Calibration {
    private:
        double gain;
        double offset;
    public:
        Calibration():Calibration(1.0, 1.0) {
            ;
        }
        Calibration(double m, double c) {
            gain = m;
            offset = c;
        }
        double getGain(void) { return gain; }
        double getOffset(void) { return offset; }
        void setGain(double value) { gain = value; }
        void setOffset(double value) { offset = value; }
};

class sensorInformation:private Calibration {
    private:
        string alias;
        string json;
    public:
        sensorInformation():sensorInformation("None", "{}", 1.0, 1.0) {
            ;
        }
        sensorInformation(string s_alias, string s_json, double m, double c):Calibration(m, c) {
            setAlias(s_alias);
            json = s_json;
        }
        string getAlias(void) { 
            return alias; 
        }
        void setAlias(string s) { 
            alias.clear();
            alias = s;
        }
        void serialize(void) {
            ostringstream ostream;
            ostream << "{\"alias\":\"" << alias << "\"," << "\"calibration\":{\"gain\":" << getGain() << ",\"offset\":" << getOffset() << "}}";
            json.clear();
            json = ostream.str();
        }
        string getJsonStr(void) {
            return json;
        }
        void printJson(void) {
            cout << json << endl;
        }
};

int main(void)
{
    sensorInformation sInfo("Maverick", "{}", 1.109876, -0.004567);
    sInfo.serialize();
    sInfo.printJson();
    
    try {
        ofstream outFileStream("sensorInfo.json", ios::trunc);
        if(false == outFileStream.is_open()) {
            throw 1;
        }
        outFileStream << sInfo.getJsonStr() << endl;
        outFileStream.close();
        // Read from file
        ifstream inFileStream("sensorInfo.json");
        if(false == inFileStream.is_open()) {
            throw 2;
        }
        string s;
        inFileStream >> s;
        cout << "Read from the file: " << s << endl;
    }
    catch (int err) {
        if(1 == err) {
            cout << "Err: Couldn't create file." <<endl;
            return EXIT_FAILURE;
        }
        else if(2 == err) {
            cout << "Err: Couldn't open the file for reading." <<endl;
            return EXIT_FAILURE;
        }
    }

    
    cout<<endl;
    return EXIT_SUCCESS;
}
