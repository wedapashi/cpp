#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>

class keyValuePair {
private:    
    std::string key;
    std::string value;
public:
    keyValuePair() : key(), value() { }
    keyValuePair(std::string _key, std::string _value) : key(_key), value(_value) { }
    void set(const std::string& _key, const std::string& _val) {
        key = _key;
        value = _val;
    }
    const std::string get(void) const {
        std::ostringstream ostream;
        ostream << '\"' << key << '\"' << " = " << '\"' << value << '\"' << std::endl;
        return ostream.str();
    }
    void print(void) const { std::cout << this->get() << std::endl; }
    const unsigned int getSize(void) const { return this->get().length(); }
    unsigned char* exportAsArray(void) {
        unsigned char* arr = new unsigned char[this->getSize()];
        std::memcpy(arr, this->get().c_str(), this->getSize());
        return arr;
    }
};

class Buffer {
private:    
    unsigned char packet[128];
    unsigned int where;
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
public:
    Buffer() : where(0) {}
    void append(unsigned char* src, unsigned int sz) {
        writeAt(this->where, src, sz);
    }
    void print(void) { std::cout << packet << std::endl; }
};

class Module {
private:
    std::shared_ptr<Buffer> m_Buffer{};
    std::unique_ptr<keyValuePair> m_pair{};
public:
    void setBuffer(const std::shared_ptr<Buffer> &buff) { m_Buffer = buff; }
    const std::shared_ptr<Buffer>& getBuffer() const { return m_Buffer; }
    void setKeyValuePair(const keyValuePair& pair) {
        m_pair = std::make_unique<keyValuePair>(pair);
    }
    const std::unique_ptr<keyValuePair>& getKeyValuePair() const { 
        return m_pair; 
    }
    void writeToBuffer(void) {
        m_Buffer.get()->append(getKeyValuePair().get()->exportAsArray(), getKeyValuePair().get()->getSize());
    }
};

int main(void)
{
    try {
        const keyValuePair serialNum("SN", "123456");
        const keyValuePair modelNum("Model", "M4623-N");
        const keyValuePair vId("VID", "0x22C4");
        const keyValuePair pId("PID", "0x1000");
        std::shared_ptr<Buffer> buffer { new Buffer{} };

        std::shared_ptr<Module> devInfo { new Module{} };
        devInfo.get()->setBuffer(buffer);
        devInfo.get()->setKeyValuePair(serialNum);
        devInfo.get()->writeToBuffer();
        devInfo.get()->setKeyValuePair(modelNum);
        devInfo.get()->writeToBuffer();

        std::shared_ptr<Module> descrInfo { new Module{} };
        descrInfo.get()->setBuffer(buffer);
        descrInfo.get()->setKeyValuePair(vId);
        descrInfo.get()->writeToBuffer();
        descrInfo.get()->setKeyValuePair(pId);
        descrInfo.get()->writeToBuffer();
        buffer.get()->print();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
