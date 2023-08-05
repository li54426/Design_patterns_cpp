//--------------------------------[Version3.cpp]--------------------------------------
//------------------------------------------------------------------------------------

//客户
class MainForm : public Form{
    ISplitter*  prototype;//原型对象
public:
    MainForm(ISplitter*  prototype){
        this->prototype=prototype;
    }
void Button1_Click(){
ISplitter * splitter=
            prototype->clone(); //克隆原型
        splitter->split();
}
};


//抽象类 原型
class ISplitter{
public:
    virtual void split()=0;
    virtual ISplitter* clone()=0; //通过克隆自己来创建对象
    virtual ~ISplitter(){}
};


//具体类
class BinarySplitter : public ISplitter{
public:
    virtual ISplitter* clone(){
        return new BinarySplitter(*this);
    }
};
class VideoSplitter: public ISplitter{
public:
    virtual ISplitter* clone(){
        return new VideoSplitter(*this);
    }
};