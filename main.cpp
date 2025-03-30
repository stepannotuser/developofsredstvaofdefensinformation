class AbstractEntity(){
}
class AccountEntity : public AbstractEntity{
}
class RoleEntity : public AbstractEntity{
}
class Repository
{
  void Save(AbstractEntity entity)
  { if (entity is AccountEntity){}
    if (entity is RoleEntity){}
  }
}
