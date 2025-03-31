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
  }

class RoleRepository : public IRepository {
public:
  void Save(RoleEntity* entity) override {
  }
