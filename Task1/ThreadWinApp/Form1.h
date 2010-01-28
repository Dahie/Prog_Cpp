#pragma once



namespace ThreadWinApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
  using namespace System::Threading;

	/// <summary>
	/// Zusammenfassung für Form1
	///
	/// Warnung: Wenn Sie den Namen dieser Klasse ändern, müssen Sie auch
	///          die Ressourcendateiname-Eigenschaft für das Tool zur Kompilierung verwalteter Ressourcen ändern,
	///          das allen RESX-Dateien zugewiesen ist, von denen diese Klasse abhängt.
	///          Anderenfalls können die Designer nicht korrekt mit den lokalisierten Ressourcen
	///          arbeiten, die diesem Formular zugewiesen sind.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
      //if (trd->IsAlive)
	      //trd->Abort();
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::Button^  button1;
  protected: 
  private: System::Windows::Forms::ProgressBar^  progressBar1;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;
    Thread^ trd;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
      this->button1 = (gcnew System::Windows::Forms::Button());
      this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
      this->SuspendLayout();
      // 
      // button1
      // 
      this->button1->Location = System::Drawing::Point(15, 8);
      this->button1->Name = L"button1";
      this->button1->Size = System::Drawing::Size(87, 30);
      this->button1->TabIndex = 0;
      this->button1->Text = L"button1";
      this->button1->UseVisualStyleBackColor = true;
      this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
      // 
      // progressBar1
      // 
      this->progressBar1->Location = System::Drawing::Point(19, 60);
      this->progressBar1->Name = L"progressBar1";
      this->progressBar1->Size = System::Drawing::Size(261, 20);
      this->progressBar1->TabIndex = 1;
      // 
      // Form1
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(292, 266);
      this->Controls->Add(this->progressBar1);
      this->Controls->Add(this->button1);
      this->Name = L"Form1";
      this->Text = L"Form1";
      this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
      this->ResumeLayout(false);

    }
#pragma endregion

  __delegate void DelegateThreadTask();
private: void ThreadTask()
{
	int stp;
	int newval;
	Random *rnd=new Random();

	if (progressBar1->InvokeRequired == false)
		{
		stp=this->progressBar1->Step*rnd->Next(-1,2);
		newval = this->progressBar1->Value + stp;

		if (newval > this->progressBar1->Maximum)
			newval = this->progressBar1->Maximum;
		else if (newval < this->progressBar1->Minimum)
			newval = this->progressBar1->Minimum;

		this->progressBar1->Value = newval;
		}
	else 
		{
		DelegateThreadTask *myThreadDelegate = new DelegateThreadTask(this,ThreadTask);
		this->Invoke(myThreadDelegate);			
		}
}
private: void repeat()
{	
	while(true)
	{
	ThreadTask();
	Thread::Sleep(100);
	}
}

  private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
              MessageBox::Show(S"This is the main thread");
           }
  private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
    ThreadStart *myThreadDelegate = new ThreadStart(this, &ThreadWinApp::Form1::repeat);
    trd = new Thread(myThreadDelegate);
    trd->IsBackground = true;
    trd->Start();
           }
  };


}

