class Library{
public:
	void Step1(){}
    void Step3(){}
    void Step5(){}
};


// 应用程序开发人员
class Application{
public:
	bool Step2(){...}
    void Step4(){...}
};

int main(){
	Library lib();
	Application app();
	lib.Step1();
	if (app.Step2()){
		lib.Step3();
	}
	for (int i = 0; i < 4; i++){
		app.Step4();
	}
	lib.Step5();
}