class Library{ //程序库开发人员
public:
	//稳定 template method
    void Run(){
        Step1();
        if (Step2()) { //支持变化 ==> 虚函数的多态调用
            Step3(); 
        }

        for (int i = 0; i < 4; i++){
            Step4(); //支持变化 ==> 虚函数的多态调用
        }

        Step5();

    }
	virtual ~Library(){ }

protected:
	void Step1() {... }
	void Step3() {... }
	void Step5() {... }
	virtual bool Step2() = 0;//变化
    virtual void Step4() =0; //变化
};

//使用
class Application : public Library {
protected:
    virtual bool Step2() {...}
};
int main() {
    Library* pLib = new Application();
    pLib->Run();
    delete pLib;
}