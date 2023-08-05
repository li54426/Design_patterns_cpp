//数据库访问有关的基类 产品基类
class IDBConnection{...};
class IDBCommand{...};
class IDataReader{...};

//抽象工厂 统一系列化对象（相互作用）  工厂基类
class IDBFactory{
public:
    virtual IDBConnection* CreateDBConnection()=0;
    virtual IDBCommand* CreateDBCommand()=0;
    virtual IDataReader* CreateDataReader()=0;
    
};


//支持SQL Server 具体产品实现
class SqlConnection: public IDBConnection{...};
class SqlCommand: public IDBCommand{...};
class SqlDataReader: public IDataReader{...};

//具体工厂实现
class SqlDBFactory:public IDBFactory{
public:
    virtual IDBConnection* CreateDBConnection()=0;
    virtual IDBCommand* CreateDBCommand()=0;
    virtual IDataReader* CreateDataReader()=0;
};
class EmployeeDAO{
    IDBFactory* dbFactory;    
public:
    vector<EmployeeDO> GetEmployees(){
        IDBConnection* connection = dbFactory->CreateDBConnection();
        connection->ConnectionString("...");
        IDBCommand* command =dbFactory->CreateDBCommand();
        command->CommandText("...");
        command->SetConnection(connection); //关联性
        IDBDataReader* reader = command->ExecuteReader(); //关联性
        while (reader->Read()){
            ...
        }
    }
};