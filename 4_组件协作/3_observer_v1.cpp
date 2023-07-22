//--------------------------------[Version1.cpp]--------------------------------------
//------------------------------------------------------------------------------------
// 主程序, 用来展示 界面
class MainForm : public Form{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
    // 通知, 依赖于具体的 应用场景 例如, windows
	ProgressBar* progressBar;

public:
	void Button1_Click(){
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());
		
        // 开始进行文件处理
		FileSplitter splitter(filePath, number, progressBar);
		splitter.split();

	}
};

// 分割功能
class FileSplitter{
	string m_filePath;
	int m_fileNumber;
    // 具体的通知控件
	ProgressBar* m_progressBar;

public:
	FileSplitter(const string& filePath, int fileNumber, ProgressBar* progressBar) :
		m_filePath(filePath), 
		m_fileNumber(fileNumber),
		m_progressBar(progressBar){
	}

	void split(){
		//1.读取大文件
		//2.分批次向小文件中写入
		for (int i = 0; i < m_fileNumber; i++){
			//...
			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			m_progressBar->setValue(progressValue);
		}

	}
};