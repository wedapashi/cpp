#include <iostream>
#include <exception>
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
        }
};

class sensorInformation:public Calibration {
    private:
        string alias;
    public:
        sensorInformation():sensorInformation("None", 1.0, 1.0) {
            ;
        }
        sensorInformation(string s_alias, double m, double c):Calibration(m, c) {
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
    try {
        Calibration * pCal_d = new sensorInformation;
        Calibration * pCal_b = new Calibration;
        sensorInformation * pSensorInfo;

        pSensorInfo = dynamic_cast<sensorInformation*>(pCal_d);
        if (nullptr == pSensorInfo) {
            cout << "Null pointer on first type-cast" << endl;
        }
        pSensorInfo = dynamic_cast<sensorInformation*>(pCal_b);
        if (nullptr == pSensorInfo) {
            cout << "Null pointer on second type-cast" << endl;
        }
    } catch (exception& e) {
        cout << "Exception: " << e.what();
    }
    
    cout << endl;
    return EXIT_SUCCESS;
}
