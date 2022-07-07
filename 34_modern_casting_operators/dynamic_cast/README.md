# Dynamic cast

Typical expression:

    dynamic_cast <new_type> (expression)

`dynamic_cast` can be used only with pointers and references to objects. Its purpose is to ensure that the result of the
type conversion is a valid complete object of the requested class. Therefore, `dynamic_cast` is always successful when
we cast a class to one of its base classes.

    class CBase { };
    class CDerived:public CBase { };

    CBase b; CBase* pb;
    CDerived d; CDerived* pd;

    pb = dynamic_cast<CBase*>(&d);     // Derived-to-base -- This is acceptable
    pd = dynamic_cast<CDerived*>(&b);  // Base-to-derived -- This is not

The second conversion in this piece of code would produce a compilation error since base-to-derived conversions are not allowed with dynamic_cast unless the base class is polymorphic.

When a class is polymorphic, dynamic_cast performs a special checking during runtime to ensure that the expression yields a valid complete object of the requested class.

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
            double getGain(void) { return gain; }
            double getOffset(void) { return offset; }
            void setGain(double value) { gain = value; }
            void setOffset(double value) { offset = value; }
            virtual void calibrate(void) {
                // Some code
            }
    };

    class sensorInformation:public Calibration {
        private:
            string alias;
        public:
            sensorInformation():sensorInformation("None", 1.0, 1.0) { ; }
            sensorInformation(string s_alias, double m, double c):Calibration(m, c) { setAlias(s_alias); }
            string getAlias(void) { return alias; }
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

`dynamic_cast` requires the Run-Time Type Information (RTTI) to keep track of dynamic types. Some compilers support this feature as an option which is disabled by default. This must be enabled for runtime type checking using `dynamic_cast` to work properly.
The code tries to perform two `dynamic casts` from pointer objects of type `Calibration*` (`pCal_d` and `pCal_d`) to a pointer object of type `sensorInformation*`, but only the first one is successful. Notice their respective initializations.

Even though both are pointers of type `Calibration*`, `pCal_b` points to an object of type sensorInformation, while `pCal_d` points to an object of type `Calibration`. Thus, when their respective type-castings are performed using `dynamic_cast`, `pCal_b` is pointing to a full object of class `sensorInformation`, whereas `pCal_d` is pointing to an object of class `Calibration`, which is an incomplete object of class `sensorInformation`.

When `dynamic_cast` cannot cast a pointer because it is not a complete object of the required class - as in the second conversion in the previous example - it returns a null pointer to indicate the failure. If `dynamic_cast` is used to convert to a reference type and the conversion is not possible, an exception of type bad_cast is thrown instead.

`dynamic_cast` can also cast null pointers even between pointers to unrelated classes, and can also cast pointers of any type to `void` pointers (`void*`).

***
### Program output:

    Exception: Null pointer on second type-cast



