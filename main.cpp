#include <iostream>
#include <string>

//using namespace std;
using std::string;
using std::cout;
using std::endl;

class AbstractEntity {
public:
    virtual string GetName() const = 0;
    virtual ~AbstractEntity() = default;
};

class AccountEntity : public AbstractEntity {
public:
    string GetName() const override {
        return "AccountEntity";
    }
};

class RoleEntity : public AbstractEntity {
public:
    string GetName() const override {
        return "RoleEntity";
    }
};

class TretiyEntity : public AbstractEntity {                                                                                          //
public:
    string GetName() const override {
        return "TretiyEntity";
    }
};

class IRepository {
public:
    virtual void Save(AbstractEntity* entity) = 0;
    virtual ~IRepository() = default;
};

class AccountRepository : public IRepository {
public:
  void Save(AbstractEntity* entity) override {
    AccountEntity* account = dynamic_cast<AccountEntity*>(entity);
    if (account != nullptr) {
        cout << "Save object: " << account->GetName() << endl;
    }     
  }
};
class RoleRepository : public IRepository {
public:
  void Save(RoleEntity* entity) override {
      RoleEntity* role = dynamic_cast<RoleEntity*>(entity);
        if (role != nullptr) {
            cout << "Save object: " << role->GetName() << endl;
        }
  }
};

class TretiyRepository : public IRepository {                                                                                         //
public:
    void Save(AbstractEntity* entity) override {
        TretiyEntity* tretiy = dynamic_cast<TretiyEntity*>(entity);
        if (tretiy != nullptr) {
            cout << "Save object: " << tretiy->GetName() << endl;
        }
    }
};


int main() {

    AccountEntity account;
    RoleEntity* role = new RoleEntity(); //

    AccountRepository accountRepo;
    RoleRepository roleRepo;             //

    accountRepo.Save(&account);  
    roleRepo.Save(role);                 //

    accountRepo.Save(role); //

    delete role;                         //

    TretiyEntity tretiy;                               //
    TretiyRepository tretiyrepo;                       //
    tretiyrepo.Save(&tretiy);                          //
    
    return 0;
}
