#ifndef TECH_H
#define TECH_H

#include <cstdint>
#include <string>
#include <QString>
#include <ctime>

using std::uint64_t;
#define Rus(str) QString::fromUtf8(str).toLocal8Bit().data()

// Определение базового абстрактного класса

class Tech
{
public:
    Tech(const std::string& type) : m_type(type) { m_ID = ++count; }
    Tech(const std::string& type, int);
    virtual ~Tech() = 0;

    uint32_t& getID() { return m_ID; }
    std::string& getType() { return m_type; }
    std::string getType() const { return m_type; }
    std::string& getReleaseData() { return m_releasedate; }
    std::string& getRecordTime() { return m_recordtime; }
    std::string& getSerialNumber() { return m_serialnumber; }
    std::string& getManufacturer() { return m_manufacturer; }
    std::string& getModel() { return m_model; }
    std::string& getVendor() { return m_vendor; }
    std::string& getCountrymaker() { return m_countrymaker; }
    uint32_t& getPrice() { return m_price; }

    virtual Tech* getTypeClass() = 0;
    virtual std::istream& setState(std::istream& in);
    virtual std::ostream& print(std::ostream& out) const;
    virtual void readFile(std::fstream& file, Tech* obj);
    virtual void writeToFile(std::fstream& file);
    virtual void getStringToSend(std::string& stringToSend);
    virtual void replaceObject(std::string& string);

    static std::string setCurrentDate();

    friend std::ostream& operator<<(std::ostream& out, const Tech& object);
    friend std::istream& operator>>(std::istream& in, Tech& object);

private:
    static uint64_t count;
    static tm* rctime;
    uint32_t m_ID;
    std::string m_type;
    std::string m_recordtime;
    // Свойства, приобретаемые при создании продукта на заводе
    std::string m_serialnumber = "-";
    std::string m_manufacturer = "-";
    std::string m_releasedate = "-";
    std::string m_model = "-";
    // Свойства, которые назначаются в магазине
    std::string m_vendor = "-";
    std::string m_countrymaker = "-";
    uint32_t m_price = 1;
};

// !Определение базового абстрактного класса

// Определение дочерних классов

class Computer final: public Tech
{
public:
    Computer() : Tech("Компьютер") {}
    virtual ~Computer() {};

    std::string& getProcessor() { return m_processor; }
    std::string& getRamtype() { return  m_ramtype; }
    std::string& getScreenResol() { return  m_screenresol; }
    uint32_t& getRamSize() { return  m_ramsize; }
    uint32_t& getCore() { return  m_core; }
    double& getScreenDiagonal() { return m_screendiagonal; }

    virtual Tech* getTypeClass() override final { return new Computer; }
    virtual std::istream& setState(std::istream& in) override final;
    virtual std::ostream& print(std::ostream& out) const override final;
    virtual void readFile(std::fstream& file, Tech* obj) override final;
    virtual void writeToFile(std::fstream& file) override final;
    virtual void getStringToSend(std::string& stringToSend) override final;
    virtual void replaceObject(std::string& string) override final;

private:
    std::string m_processor = "-";
    std::string m_ramtype = "-";
    std::string m_screenresol = "-";
    uint32_t m_ramsize = 1;
    uint32_t m_core = 1;
    double m_screendiagonal = 1;
};

class MobilePhone final: public Tech
{
public:
    MobilePhone() : Tech("Моб.Телефон") {}
    virtual ~MobilePhone() {};

    std::string& getOS() { return m_os; }
    std::string& getProcessor() { return m_processor; }
    std::string& getScreenResol() { return m_screenresol; }
    uint32_t& getCore() { return m_core; }
    uint32_t& getRamSize() { return  m_ramsize; }
    uint32_t& getSimCount() { return m_simcount; }
    double& getScreenDiagonal() { return m_screendiagonal; }

    virtual Tech* getTypeClass() override final { return new MobilePhone; }
    virtual std::istream& setState(std::istream& in) override final;
    virtual std::ostream& print(std::ostream& out) const override final;
    virtual void readFile(std::fstream& file, Tech* obj) override final;
    virtual void writeToFile(std::fstream& file) override final;
    virtual void getStringToSend(std::string& stringToSend) override final;
    virtual void replaceObject(std::string& string) override final;

private:
    std::string m_os = "-";
    std::string m_screenresol = "-";
    std::string m_processor = "-";
    uint32_t m_core = 1;
    uint32_t m_ramsize = 1;
    uint32_t m_simcount = 1;
    double m_screendiagonal = 1;
};

class TV final: public Tech
{
public:
    TV() : Tech("Телевизор") {}
    virtual ~TV() {};

    std::string& getTypescreen() { return  m_typescreen; }
    std::string& getScreenResol() { return m_screenresolution; }
    std::string& getProcessor() { return m_processor; }
    uint32_t& getCore() { return m_core; }
    double& getScreenDiagonal() { return m_screendiagonal; }
    bool& get3DMode() { return  m_3Dmode; }

    virtual Tech* getTypeClass() override final { return new TV; }
    virtual std::istream& setState(std::istream& in) override final;
    virtual std::ostream& print(std::ostream& out) const override final;
    virtual void readFile(std::fstream& file, Tech* obj) override final;
    virtual void writeToFile(std::fstream& file) override final;
    virtual void getStringToSend(std::string& stringToSend) override final;
    virtual void replaceObject(std::string& string) override final;

private:
    std::string m_typescreen = "-";
    std::string m_screenresolution = "-";
    std::string m_processor = "-";
    uint32_t m_core = 1;
    double m_screendiagonal = 1;
    bool m_3Dmode = false;
};

class Toaster final: public Tech
{
public:
    Toaster() : Tech("Тостер") {}
    virtual ~Toaster() {};

    uint32_t& getToastCount() { return m_toastcount; }
    uint32_t& getPower() { return  m_power; }
    bool& getDefrosting() { return  m_defrostring; }
    bool& getHeating() { return m_heating; }

    virtual Tech* getTypeClass() override final { return  new Toaster; }
    virtual std::istream& setState(std::istream& in) override final;
    virtual std::ostream& print(std::ostream& out) const override final;
    virtual void readFile(std::fstream& file, Tech* obj) override final;
    virtual void writeToFile(std::fstream& file) override final;
    virtual void getStringToSend(std::string& stringToSend) override final;
    virtual void replaceObject(std::string& string) override final;

private:
    uint32_t m_toastcount = 1;
    uint32_t m_power = 1;
    bool m_defrostring = false;
    bool m_heating = false;
};

class CoffeMaker final: public Tech
{
public:
    CoffeMaker() : Tech("Кофемашина") {}
    virtual ~CoffeMaker() {};

    uint32_t& getPower() { return m_power; }
    uint32_t& getPressure() { return m_pressure; }
    bool& getCappuccinoMaker() { return m_cappuccinomaker; }

    virtual Tech* getTypeClass() override final { return new CoffeMaker; }
    virtual std::istream& setState(std::istream& in) override final;
    virtual std::ostream& print(std::ostream& out) const override final;
    virtual void readFile(std::fstream& file, Tech* obj) override final;
    virtual void writeToFile(std::fstream& file) override final;
    virtual void getStringToSend(std::string& stringToSend) override final;
    virtual void replaceObject(std::string& string) override final;

private:
    uint32_t m_power = 1;
    uint32_t m_pressure = 1;
    bool m_cappuccinomaker = false;
};

class ElKettle final: public Tech
{
public:
    ElKettle() : Tech("Эл.Чайник") {}
    virtual ~ElKettle() {};

    uint32_t& getPower() { return m_power; }
    uint32_t& getVolume() { return m_volume; }
    bool& getTimer() { return m_timer; }

    virtual Tech* getTypeClass() override final { return new ElKettle; }
    virtual std::istream& setState(std::istream& in) override final;
    virtual std::ostream& print(std::ostream& out) const override final;
    virtual void readFile(std::fstream& file, Tech* obj) override final;
    virtual void writeToFile(std::fstream& file) override final;
    virtual void getStringToSend(std::string& stringToSend) override final;
    virtual void replaceObject(std::string& string) override final;

private:
    uint32_t m_power = 1;
    uint32_t m_volume = 1;
    bool m_timer = false;
};

class Fridge final: public Tech
{
public:
    Fridge() : Tech("Холодильник") {}
    virtual ~Fridge() {};

    uint32_t& getVolume() { return m_volume; }
    uint32_t& getShelfCount() { return m_shelfcount; }
    uint32_t& getNoiseLvl() { return m_noiselvl; }
    bool& getMultizone() { return m_multizone; }

    virtual Tech* getTypeClass() override final { return  new Fridge; }
    virtual std::istream& setState(std::istream& in) override final;
    virtual std::ostream& print(std::ostream& out) const override final;
    virtual void readFile(std::fstream& file, Tech* obj) override final;
    virtual void writeToFile(std::fstream& file) override final;
    virtual void getStringToSend(std::string& stringToSend) override final;
    virtual void replaceObject(std::string& string) override final;

private:
    uint32_t m_volume = 1;
    uint32_t m_shelfcount = 1;
    uint32_t m_noiselvl = 1;
    bool m_multizone = false;
};

class Conditioner final: public Tech
{
public:
    Conditioner() : Tech("Кондиционер") {}
    virtual ~Conditioner() {};

    std::string& getWorkmode() { return m_workmode; }
    uint32_t& getCoolingPower() { return m_coolingpower; }
    uint32_t& getHeathingPower() { return m_heatingpower; }
    bool& getRemouteControl() { return m_remotecontol; }

    virtual Tech* getTypeClass() override final { return new Conditioner; }
    virtual std::istream& setState(std::istream& in) override final;
    virtual std::ostream& print(std::ostream& out) const override final;
    virtual void readFile(std::fstream& file, Tech* obj) override final;
    virtual void writeToFile(std::fstream& file) override final;
    virtual void getStringToSend(std::string& stringToSend) override final;
    virtual void replaceObject(std::string& string) override final;

private:
    std::string m_workmode = "";
    uint32_t m_coolingpower = 1;
    uint32_t m_heatingpower = 1;
    bool m_remotecontol = false;
};

class Microwawe final: public Tech
{
public:
    Microwawe() : Tech("Микроволновка") {}
    virtual ~Microwawe() {};

    uint32_t& getPower() { return m_power; }
    uint32_t& getLvlPower() { return m_lvlpower_count; }
    uint32_t& getVolume() { return m_volume; }
    bool& getQuickstart() { return m_quickstart; }
    bool& getTimer() { return m_timer; }

    virtual Tech* getTypeClass() override final { return new Microwawe; }
    virtual std::istream& setState(std::istream& in) override final;
    virtual std::ostream& print(std::ostream& out) const override final;
    virtual void readFile(std::fstream& file, Tech* obj) override final;
    virtual void writeToFile(std::fstream& file) override final;
    virtual void getStringToSend(std::string& stringToSend) override final;
    virtual void replaceObject(std::string& string) override final;

private:
    uint32_t m_power = 1;
    uint32_t m_lvlpower_count = 1;
    uint32_t m_volume = 1;
    bool m_quickstart = false;
    bool m_timer = false;
};

// !Определение дочерних классов

#endif // TECH_H
