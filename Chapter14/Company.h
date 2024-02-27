#pragma once
#include <iostream>
#include <string>

class abstr_emp {
private:
    std::string fname;
    std::string lname;
    std::string job;

public:
    abstr_emp() : fname("Default"), lname("Default"), job("Default") {}
    abstr_emp(const std::string &fn, const std::string &ln,
    const std::string &j) : fname(fn), lname(ln), job(j) {}

    virtual void showAll() const;
    virtual void SetAll();
    friend std::ostream &operator<<(std::ostream &os, const abstr_emp &e);
    virtual ~abstr_emp() = 0;
};

void abstr_emp::showAll() const {
    std::cout << "First Name: " << fname << "\nLast Name: " << lname << "\nJob: " << job << std::endl;
}

void abstr_emp::SetAll() {
    std::cout << "Enter first name: ";
    std::getline(std::cin, fname);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lname);
    std::cout << "Enter job: ";
    std::getline(std::cin, job);
}

std::ostream &operator<<(std::ostream &os, const abstr_emp &e) {
    os << "First Name: " << e.fname << "\nLast Name: " << e.lname << "\nJob: " << e.job;
    return os;
}

abstr_emp::~abstr_emp() {}

class employee : public abstr_emp {
public:
    employee() : abstr_emp() {}
    employee(const std::string &fn, const std::string &ln, 
    const std::string &j) : abstr_emp(fn, ln, j) {}

    virtual void showAll() const override;
    virtual void SetAll() override;
};

void employee::showAll() const {
    std::cout << "Employee\n";
    abstr_emp::showAll();
}

void employee::SetAll() {
    std::cout << "Enter employee data:\n";
    abstr_emp::SetAll();
}

class manager : virtual public abstr_emp {
private:
    int inchargeof;

protected:
    int InChargeof() const { return inchargeof; }
    int &InChargeof() { return inchargeof; }

public:
    manager() : abstr_emp(), inchargeof(0) {}
    manager(const std::string &fn, const std::string &ln, 
    const std::string &j, int ico = 0) : abstr_emp(fn, ln, j), inchargeof(ico) {}
    manager(const abstr_emp &e, int ico) : abstr_emp(e), inchargeof(ico) {}
    manager(const manager &m) : abstr_emp(m), inchargeof(m.inchargeof) {}

    virtual void showAll() const override;
    virtual void SetAll() override;
};

void manager::showAll() const {
    std::cout << "Manager\n";
    abstr_emp::showAll();
    std::cout << "In Charge of: " << inchargeof << std::endl;
}

void manager::SetAll() {
    std::cout << "Enter manager data:\n";
    abstr_emp::SetAll();
    std::cout << "Enter number of employees managed: ";
    std::cin >> inchargeof;
    std::cin.get(); // consume newline
}

class fink : virtual public abstr_emp {
private:
    std::string reportsto;

protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string &ReportsTo() { return reportsto; }

public:
    fink() : abstr_emp(), reportsto("None") {}
    fink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo)
        : abstr_emp(fn, ln, j), reportsto(rpo) {}
    fink(const abstr_emp &e, const std::string &rpo) : abstr_emp(e), reportsto(rpo) {}
    fink(const fink &e) : abstr_emp(e), reportsto(e.reportsto) {}

    virtual void showAll() const override;
    virtual void SetAll() override;
};

void fink::showAll() const {
    std::cout << "Fink\n";
    abstr_emp::showAll();
    std::cout << "Reports To: " << reportsto << std::endl;
}

void fink::SetAll() {
    std::cout << "Enter fink data:\n";
    abstr_emp::SetAll();
    std::cout << "Enter to whom fink reports: ";
    std::getline(std::cin, reportsto);
}

class highfink : public manager, public fink {
public:
    highfink() : abstr_emp(), manager(), fink() {}
    
    highfink(const std::string &fn, const std::string &ln, 
    const std::string &j, const std::string &rpo, int ico)
        : abstr_emp(fn, ln, j),
        manager(fn, ln, j, ico), 
        fink(fn, ln, j, rpo) {}

    highfink(const abstr_emp &e, const std::string &rpo, int ico)
        : abstr_emp(e), manager(e, ico), fink(e, rpo) {}

    highfink(const fink &f, int ico) 
    : abstr_emp(f),
    manager(f, ico), 
    fink(f) {}

    highfink(const manager &m, const std::string &rpo) 
    : abstr_emp(m), 
    manager(m), 
    fink(m, rpo) {}
    highfink(const highfink &h)
        : abstr_emp(h), manager(h), fink(h) {}

    virtual void showAll() const override;
    virtual void SetAll() override;
};

void highfink::showAll() const {
    std::cout << "Highfink\n";
    abstr_emp::showAll();
    std::cout << "In Charge of: " << InChargeof() << "\nReports To: " << ReportsTo() << std::endl;
}

void highfink::SetAll() {
    std::cout << "Enter highfink data:\n";
    abstr_emp::SetAll();
    manager::SetAll();
    fink::SetAll();
}
