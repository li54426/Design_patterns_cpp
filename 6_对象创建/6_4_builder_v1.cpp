class House{
public:
    House(){
        // 以下行为会报错, 因为初始化会静态绑定
        this->BuildPart1();
        for (int i = 0; i < 4; i++){
            this->BuildPart2();
        }
        bool flag=pHouseBuilder->BuildPart3();
        if(flag){
            this->BuildPart4();
        }
        this->BuildPart5();
        //return this->BuilderPart5();
    }
    
    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual void BuildPart3() = 0;
    virtual void BuildPart4() = 0;
};