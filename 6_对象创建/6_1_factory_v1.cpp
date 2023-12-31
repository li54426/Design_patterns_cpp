// 抽象类
class ISplitter{
public:
    virtual void split()=0;
    virtual ~ISplitter(){}
};
// 具体类
class BinarySplitter : public ISplitter{...
};
class TxtSplitter: public ISplitter{...
};
class PictureSplitter: public ISplitter{...
};
class VideoSplitter: public ISplitter{...
};

// 工厂基类
class SplitterFactory{
public:
    virtual ISplitter* CreateSplitter()=0;
    virtual ~SplitterFactory(){}
};
// 具体工厂
class BinarySplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new BinarySplitter();
    }
};
class TxtSplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new TxtSplitter();
    }
};
class PictureSplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new PictureSplitter();
    }
};
class VideoSplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new VideoSplitter();
    }
};


// 使用者
class MainForm : public Form{
    SplitterFactory*  factory;//工厂
public:
    MainForm(SplitterFactory*  factory){
        // 需要传入 factory
        this->factory=factory;
    }
    void Button1_Click(){
        ISplitter * splitter = factory->CreateSplitter(); //多态new
            splitter->split();

    }
};