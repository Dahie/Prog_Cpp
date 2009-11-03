#pragma once

#include <stdio.h>
#include "Utils.h"
#include "MP3Audio.h"
#include <vector>

namespace Task1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung f�r Form1
	///
	/// Warnung: Wenn Sie den Namen dieser Klasse �ndern, m�ssen Sie auch
	///          die Ressourcendateiname-Eigenschaft f�r das Tool zur Kompilierung verwalteter Ressourcen �ndern,
	///          das allen RESX-Dateien zugewiesen ist, von denen diese Klasse abh�ngt.
	///          Anderenfalls k�nnen die Designer nicht korrekt mit den lokalisierten Ressourcen
	///          arbeiten, die diesem Formular zugewiesen sind.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
      
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzuf�gen.
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
    //std::vector<MP3Audio*> openedAudio;
  private: System::Windows::Forms::ListBox^  listBox1;
  protected: 

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f�r die Designerunterst�tzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge�ndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
      this->btOpen = (gcnew System::Windows::Forms::Button());
      this->listBox1 = (gcnew System::Windows::Forms::ListBox());
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
      // listBox1
      // 
      this->listBox1->FormattingEnabled = true;
      this->listBox1->Location = System::Drawing::Point(7, 41);
      this->listBox1->Name = L"listBox1";
      this->listBox1->Size = System::Drawing::Size(272, 212);
      this->listBox1->TabIndex = 1;
      // 
      // Form1
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(292, 266);
      this->Controls->Add(this->listBox1);
      this->Controls->Add(this->btOpen);
      this->Name = L"Form1";
      this->Text = L"MP3 Tagger";
      this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
      this->ResumeLayout(false);

    }
#pragma endregion



   System::Void btOpen_Click(System::Object^ sender, System::EventArgs^ e)
   {
      // Displays an OpenFileDialog so the user can select a Cursor.
      OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
      openFileDialog1->Filter = "MP3Audio *.MP3|*.mp3";
      openFileDialog1->Title = "Select a MP3 Audio";

      // Show the Dialog.
      // If the user clicked OK in the dialog and
      // a .mp3 file was selected, open it.
      if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
      {
        //TODO here we could also ask for a directory and get the list of files from directory

        String^ filename = openFileDialog1->FileName;
        std::string target = "target"; 
       MarshalString(filename, target);
		
		MP3Audio* mp3audio = MP3Audio::read(target);
        if(mp3audio == 0) 
          MessageBox::Show("error");
		
		std::string p1 = mp3audio->getTitle();
		
		String^ title = gcnew String(p1.c_str());
		MessageBox::Show(title);
      }
   }

  private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
           }
};
}

