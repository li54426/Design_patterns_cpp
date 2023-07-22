//--------------------------------[Version2.cpp]----------------------------------
//--------------------------------------------------------------------------------
class IProgress{// 一个方法类
public:
	virtual void DoProgress(float value)=0;
	virtual ~IProgress(){}
};


class FileSplitter{
	string m_filePath;
	int m_fileNumber;
	// 抽象通知机制，支持多个观察者
	List<IProgress*>  m_iprogressList; 
	
public:
	FileSplitter(const string& filePath, int fileNumber) :
		m_filePath(filePath), 
		m_fileNumber(fileNumber){...}

	void split(){
		//1.读取大文件
		//2.分批次向小文件中写入
		for (int i = 0; i < m_fileNumber; i++){
			//...
			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
             //使用 成员函数 发送通知
			onProgress(progressValue);
		}

	}

	void addIProgress(IProgress* iprogress){
		m_iprogressList.push_back(iprogress);
	}

	void removeIProgress(IProgress* iprogress){
		m_iprogressList.remove(iprogress);
	}

protected:
	virtual void onProgress(float value){
		List<IProgress*>::iterator itor=m_iprogressList.begin();

		while (itor != m_iprogressList.end() ){
            // 更新进度条
			(*itor)->DoProgress(value); 
			itor++;
		}
	}
};


// 主程序, 使用了多继承
class MainForm : public Form, public IProgress{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	ProgressBar* progressBar;

public:
	void Button1_Click(){
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());

		ConsoleNotifier cn;

		FileSplitter splitter(filePath, number);
		splitter.addIProgress(this);
		splitter.addIProgress(&cn)£»;
		splitter.split();

		splitter.removeIProgress(this);

	}

    // 重载 通知 函数
	virtual void DoProgress(float value){
		progressBar->setValue(value);
	}
};

class ConsoleNotifier : public IProgress {
public:
	virtual void DoProgress(float value){
		cout << ".";
	}
};