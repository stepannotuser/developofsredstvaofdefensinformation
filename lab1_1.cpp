#include <iostream>

using namespace std;

class Product {
private:
    int price;

public:
    void SetPrice(int p) {
        price = p;
    }

    int GetPrice() const {
        return price;
    }
};

class ProductValidator {
public:
    virtual bool IsValid(int price) const = 0;
};

class RegularUserValidator : public ProductValidator {
public:
    bool IsValid(int price) const override {
        return price > 0;
    }
};

class CustomerServiceValidator : public ProductValidator {
public:
    bool IsValid(int price) const override {
        return price > 100000;
    }
};

int main() {
    Product product; int nowprice = 200;
    product.SetPrice(nowprice);

    RegularUserValidator regularValidator;
    CustomerServiceValidator customerValidator;

    cout << "Is product valid for regular users? "
         << (regularValidator.IsValid(product.GetPrice()) ? "Yes" : "No")
         << endl;

    cout << "Is product valid for CustomerService? "
         << (customerValidator.IsValid(product.GetPrice()) ? "Yes" : "No")
         << endl;

    return 0;
}
