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


int main() {

    AccountEntity account;

    RoleEntity* role = new RoleEntity(); //

    AccountRepository accountRepo;
    RoleRepository roleRepo;             //

    accountRepo.Save(&account);  
    roleRepo.Save(role);                 //

    accountRepo.Save(role); //

    delete role;                         //

    return 0;
}
