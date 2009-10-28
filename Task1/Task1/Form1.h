#pragma once


namespace Task1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
      
      InitializeOpenFileDialog();
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
			if (components)
			{
				delete components;
			}
		}
  private: 
    System::Windows::Forms::Button^  btOpen;
    System::Windows::Forms::OpenFileDialog^ OpenFileDialog1;
  protected: 

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
      this->btOpen = (gcnew System::Windows::Forms::Button());
      this->SuspendLayout();
      // 
      // btOpen
      // 
      this->btOpen->Location = System::Drawing::Point(7, 5);
      this->btOpen->Name = L"btOpen";
      this->btOpen->Size = System::Drawing::Size(130, 29);
      this->btOpen->TabIndex = 0;
      this->btOpen->Text = L"Open Audio";
      this->btOpen->UseVisualStyleBackColor = true;
      this->btOpen->Click += gcnew System::EventHandler(this, &Form1::btOpen_Click);
      // 
      // Form1
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(292, 266);
      this->Controls->Add(this->btOpen);
      this->Name = L"Form1";
      this->Text = L"MP3 Tagger";
      this->ResumeLayout(false);

    }
#pragma endregion
    void InitializeOpenFileDialog()
    {
       this->OpenFileDialog1 = gcnew System::Windows::Forms::OpenFileDialog;
       
       // Set the file dialog to filter for mp3 files.
       this->OpenFileDialog1->Filter = "MP3 Audio (*.MP3)|*.MP3";
       
       // Allow the user to select one audio.
       this->OpenFileDialog1->Multiselect = false;
       this->OpenFileDialog1->Title = "My MP3 Browser";
    }


  private: System::Void btOpen_Click(System::Object^  sender, System::EventArgs^  e) {
    OpenFileDialog1->ShowDialog();
           }
  };
}

