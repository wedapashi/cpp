#include <iostream>
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
        double getGain(void) { 
            return gain; 
        }
        double getOffset(void) { 
            return offset; 
        }
        void setGain(double value) { 
            gain = value; 
        }
        void setOffset(double value) { 
            offset = value; 
        }
        virtual void calibrate(void) {
            // Some code
            cout << "In calibrate" << endl;
        }
};

class sensorInformation {
    private:
        string alias;
    public:
        sensorInformation():sensorInformation("None") {
            ;
        }
        sensorInformation(string s_alias) {
            setAlias(s_alias);
        }
        string getAlias(void) { 
            return alias; 
        }
        void setAlias(string s) { 
            alias.clear();
            alias = s;
        }
};

int main (void) {
    Calibration *pCal = new Calibration;
    sensorInformation *pSensorInfo = reinterpret_cast<sensorInformation*>(pCal);
    pSensorInfo->getAlias();
    cout << endl;
    return EXIT_SUCCESS;
}
