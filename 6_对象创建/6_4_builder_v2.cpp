// direct 和 builder 是可以复合的, 如果规模较小
class House{...};
// 具体类
class StoneHouse: public House{...};


//抽象基类 构造步骤 低层函数
class HouseBuilder {
public:
    House* GetResult(){
        return pHouse;//构造完返回
    }
    virtual ~HouseBuilder(){}
protected:
    // 返回值在这里
    House* pHouse;
	virtual void BuildPart1()=0;
    virtual void BuildPart2()=0;
    virtual void BuildPart3()=0;
    virtual void BuildPart4()=0;
    virtual void BuildPart5()=0;
};

// 重用bulider 来创建 不同种类 的迷宫
class StoneHouseBuilder: public HouseBuilder{
protected:
    //每部分构造的具体实现
    virtual void BuildPart1(){...}
    virtual void BuildPart2(){...}
    virtual void BuildPart3(){...}
    virtual void BuildPart4(){...}
    virtual void BuildPart5(){...}
};

// 造房子
class HouseDirector{   
public:
    HouseBuilder* pHouseBuilder;
    HouseDirector(HouseBuilder* pHouseBuilder){
        this->pHouseBuilder=pHouseBuilder;
    }
    House* Construct(){
        // 按 步骤 分别构造每一部分
        pHouseBuilder->BuildPart1();
        for (int i = 0; i < 4; i++){
            pHouseBuilder->BuildPart2();
        }
        bool flag=pHouseBuilder->BuildPart3();
        if(flag){
            pHouseBuilder->BuildPart4();
        }
        pHouseBuilder->BuildPart5();
        return pHouseBuilder->GetResult();
    }
};

int main(){
    // 创建一个初始化产品
    House *house = new StoneHouse;
    // 以下 两类 可以合为 一类
    HouseBuilder *builder = new StonehouseBuilder(house);
    HouseDirector *director = new HouseDirector(builder);
    // 在最后的一步 才 返回产品
    director-> Construct();
    
}