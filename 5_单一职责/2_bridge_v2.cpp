//------------------------------[Version2.c]-----------------------------------
//-----------------------------------------------------------------------------
class Messager{
protected:
    // 基类指针
     MessagerImp* messagerImp;//...
public:
    virtual void Login(string username, string password)=0;
    virtual void SendMessage(string message)=0;
    virtual void SendPicture(Image image)=0;
    
    virtual ~Messager(){}
};

class MessagerImp{
public:
    virtual void PlaySound()=0;
    virtual void DrawShape()=0;
    virtual void WriteText()=0;
    virtual void Connect()=0;
    
    virtual MessagerImp(){}
};


//平台实现 m
class PCMessagerImp : public MessagerImp{
public:
    // PC 平台的实现
    virtual void PlaySound(){...}
    virtual void DrawShape(){...}
    virtual void WriteText(){...}
    virtual void Connect(){...}
};

class MobileMessagerImp : public MessagerImp{
public:
    // Mobile 平台的实现
    virtual void PlaySound(){...}
    virtual void DrawShape(){...}
    virtual void WriteText(){...}
    virtual void Connect(){...}
};

//业务抽象 n
//类的数目：1+n+m
class MessagerLite :public Messager {
public:
    virtual void Login(string username, string password){
        messagerImp->Connect();
        //........
    }
    virtual void SendMessage(string message){
        messagerImp->WriteText();
        //........
    }
    virtual void SendPicture(Image image){
        messagerImp->DrawShape();
        //........
    }
};

class MessagerPerfect  :public Messager {
public:
    virtual void Login(string username, string password){
        messagerImp->PlaySound();
        messagerImp->Connect();
        ...
    }
    virtual void SendMessage(string message){
        messagerImp->PlaySound();
        ...
        messagerImp->WriteText();

    }
    virtual void SendPicture(Image image){
        messagerImp->PlaySound();
        ...
        messagerImp->DrawShape();

    }
};


void Process(){
    // 运行时装配
    MessagerImp* mImp=new PCMessagerImp();
    Messager *m =new Messager(mImp);
}
