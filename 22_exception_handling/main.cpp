#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>

class buffer {
    unsigned char packet[64];
    unsigned int where;
    public:
        void writeAt(unsigned int pos, unsigned char* src, unsigned int sz) {
            if(nullptr == src)
                throw std::invalid_argument("source pointer is nullptr.");
            if(pos >= sizeof(packet))
                throw std::out_of_range("Array out of bounds.");
            if(sz >= sizeof(packet) - pos)
                throw std::range_error("Invalid range operation causing buffer overrun.");
            std::memcpy(&packet[where], src, sz);
            where+=sz;
        }

        void append(unsigned char* src, unsigned int sz) {
            writeAt(this->where, src, sz);
        }

        void print(void) {
            std::cout << packet << std::endl;
        }
};

class keyValuePair {
    std::string key;
    std::string value;
    const char delimiter = '\n';
    public:
        keyValuePair() : key(), value() { }
        keyValuePair(std::string _key, std::string _value) : key(_key), value(_value) { }
        void set(const std::string& _key, const std::string& _val) {
            key = _key;
            value = _val;
        }
        const std::string get(void) const {
            std::ostringstream ostream;
            ostream << '\"' << key << '\"' << " = " << '\"' << value << '\"' << delimiter;
            return ostream.str();
        }
        void print(void) const {
            std::cout << this->get() << std::endl;
        }
        const unsigned int getSize(void) const {
            return this->get().length();
        }
        unsigned char* exportAsArray(void) {
            unsigned char* arr = new unsigned char[this->getSize()];
            std::memcpy(arr, this->get().c_str(), this->getSize());
            return arr;
        }
};

int main()
{
    try {
        buffer b;
        keyValuePair field1("SN", "123456");
        keyValuePair field2("VID", "22C4");
        keyValuePair field3("Error Injection", "I will Cause overflow");
        b.append(field1.exportAsArray(), field1.getSize());
        b.append(field2.exportAsArray(), field2.getSize());
        b.append(field3.exportAsArray(), field3.getSize());
        b.print();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}

