#pragma once

#include <stdio.h>
#include "Utils.h"
#include "MP3Audio.h"
#include "Tracks.h"
#include <list>

namespace Task1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MP3;

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

	private:
		CTracks* tracks;

	public:
		Form1(void)
		{
      
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
			tracks = new CTracks();
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
	private: System::Windows::Forms::Button^  btOpen;
	private: System::Windows::Forms::ListBox^  lbTracks;
	private: System::Windows::Forms::TextBox^  tbTitle;
	private: System::Windows::Forms::Label^  lbTitle;
	private: System::Windows::Forms::TextBox^  tbAlbum;
	private: System::Windows::Forms::Label^  lbAlbum;
	private: System::Windows::Forms::TextBox^  tbArtist;
	private: System::Windows::Forms::Label^  lbArtist;
	private: System::Windows::Forms::TextBox^  tbYear;
	private: System::Windows::Forms::Label^  lbYear;
	private: System::Windows::Forms::TextBox^  tbTrackNum;
	private: System::Windows::Forms::Label^  lbTrackNum;
	private: System::Windows::Forms::TextBox^  tbGenre;
	private: System::Windows::Forms::Label^  lbGenre;

	private: System::Windows::Forms::Label^  lbSize;
	private: System::Windows::Forms::TextBox^  tbComment;
	private: System::Windows::Forms::Label^  lbComment;
	private: System::Windows::Forms::TextBox^  tbBPM;
	private: System::Windows::Forms::Label^  lbBPM;


	private: System::Windows::Forms::TextBox^  tbSize;
	private: System::Windows::Forms::TextBox^  tbBitrate;
	private: System::Windows::Forms::Label^  lbBitrate;
	private: System::Windows::Forms::Label^  lbLBTracks;
	private: System::Windows::Forms::Button^  btClear;


	private: System::ComponentModel::IContainer^  components;

		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btOpen = (gcnew System::Windows::Forms::Button());
			this->lbTracks = (gcnew System::Windows::Forms::ListBox());
			this->tbTitle = (gcnew System::Windows::Forms::TextBox());
			this->lbTitle = (gcnew System::Windows::Forms::Label());
			this->tbAlbum = (gcnew System::Windows::Forms::TextBox());
			this->lbAlbum = (gcnew System::Windows::Forms::Label());
			this->tbArtist = (gcnew System::Windows::Forms::TextBox());
			this->lbArtist = (gcnew System::Windows::Forms::Label());
			this->tbYear = (gcnew System::Windows::Forms::TextBox());
			this->lbYear = (gcnew System::Windows::Forms::Label());
			this->tbTrackNum = (gcnew System::Windows::Forms::TextBox());
			this->lbTrackNum = (gcnew System::Windows::Forms::Label());
			this->tbGenre = (gcnew System::Windows::Forms::TextBox());
			this->lbGenre = (gcnew System::Windows::Forms::Label());
			this->lbSize = (gcnew System::Windows::Forms::Label());
			this->tbComment = (gcnew System::Windows::Forms::TextBox());
			this->lbComment = (gcnew System::Windows::Forms::Label());
			this->tbBPM = (gcnew System::Windows::Forms::TextBox());
			this->lbBPM = (gcnew System::Windows::Forms::Label());
			this->tbSize = (gcnew System::Windows::Forms::TextBox());
			this->tbBitrate = (gcnew System::Windows::Forms::TextBox());
			this->lbBitrate = (gcnew System::Windows::Forms::Label());
			this->lbLBTracks = (gcnew System::Windows::Forms::Label());
			this->btClear = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btOpen
			// 
			this->btOpen->Location = System::Drawing::Point(7, 5);
			this->btOpen->Name = L"btOpen";
			this->btOpen->Size = System::Drawing::Size(93, 29);
			this->btOpen->TabIndex = 0;
			this->btOpen->Text = L"Open Audio";
			this->btOpen->UseVisualStyleBackColor = true;
			this->btOpen->Click += gcnew System::EventHandler(this, &Form1::btOpen_Click);
			// 
			// lbTracks
			// 
			this->lbTracks->FormattingEnabled = true;
			this->lbTracks->Location = System::Drawing::Point(7, 56);
			this->lbTracks->Name = L"lbTracks";
			this->lbTracks->Size = System::Drawing::Size(373, 199);
			this->lbTracks->TabIndex = 24;
			this->lbTracks->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::selectTrack_Click);
			// 
			// tbTitle
			// 
			this->tbTitle->Location = System::Drawing::Point(86, 264);
			this->tbTitle->Name = L"tbTitle";
			this->tbTitle->ReadOnly = true;
			this->tbTitle->Size = System::Drawing::Size(294, 20);
			this->tbTitle->TabIndex = 2;
			this->tbTitle->WordWrap = false;
			// 
			// lbTitle
			// 
			this->lbTitle->AutoSize = true;
			this->lbTitle->Location = System::Drawing::Point(12, 267);
			this->lbTitle->Name = L"lbTitle";
			this->lbTitle->Size = System::Drawing::Size(27, 13);
			this->lbTitle->TabIndex = 3;
			this->lbTitle->Text = L"Title";
			this->lbTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbAlbum
			// 
			this->tbAlbum->Location = System::Drawing::Point(86, 290);
			this->tbAlbum->Name = L"tbAlbum";
			this->tbAlbum->ReadOnly = true;
			this->tbAlbum->Size = System::Drawing::Size(294, 20);
			this->tbAlbum->TabIndex = 4;
			this->tbAlbum->WordWrap = false;
			// 
			// lbAlbum
			// 
			this->lbAlbum->AutoSize = true;
			this->lbAlbum->Location = System::Drawing::Point(12, 293);
			this->lbAlbum->Name = L"lbAlbum";
			this->lbAlbum->Size = System::Drawing::Size(36, 13);
			this->lbAlbum->TabIndex = 5;
			this->lbAlbum->Text = L"Album";
			this->lbAlbum->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbArtist
			// 
			this->tbArtist->Location = System::Drawing::Point(86, 316);
			this->tbArtist->Name = L"tbArtist";
			this->tbArtist->ReadOnly = true;
			this->tbArtist->Size = System::Drawing::Size(294, 20);
			this->tbArtist->TabIndex = 6;
			this->tbArtist->WordWrap = false;
			// 
			// lbArtist
			// 
			this->lbArtist->AutoSize = true;
			this->lbArtist->Location = System::Drawing::Point(12, 319);
			this->lbArtist->Name = L"lbArtist";
			this->lbArtist->Size = System::Drawing::Size(46, 13);
			this->lbArtist->TabIndex = 7;
			this->lbArtist->Text = L"Interpret";
			this->lbArtist->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbYear
			// 
			this->tbYear->Location = System::Drawing::Point(86, 342);
			this->tbYear->Name = L"tbYear";
			this->tbYear->ReadOnly = true;
			this->tbYear->Size = System::Drawing::Size(34, 20);
			this->tbYear->TabIndex = 8;
			this->tbYear->WordWrap = false;
			// 
			// lbYear
			// 
			this->lbYear->AutoSize = true;
			this->lbYear->Location = System::Drawing::Point(12, 345);
			this->lbYear->Name = L"lbYear";
			this->lbYear->Size = System::Drawing::Size(29, 13);
			this->lbYear->TabIndex = 9;
			this->lbYear->Text = L"Year";
			this->lbYear->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbTrackNum
			// 
			this->tbTrackNum->Location = System::Drawing::Point(329, 342);
			this->tbTrackNum->Name = L"tbTrackNum";
			this->tbTrackNum->ReadOnly = true;
			this->tbTrackNum->Size = System::Drawing::Size(51, 20);
			this->tbTrackNum->TabIndex = 10;
			this->tbTrackNum->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->tbTrackNum->WordWrap = false;
			// 
			// lbTrackNum
			// 
			this->lbTrackNum->AutoSize = true;
			this->lbTrackNum->Location = System::Drawing::Point(274, 345);
			this->lbTrackNum->Name = L"lbTrackNum";
			this->lbTrackNum->Size = System::Drawing::Size(49, 13);
			this->lbTrackNum->TabIndex = 11;
			this->lbTrackNum->Text = L"TrackNo";
			this->lbTrackNum->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbGenre
			// 
			this->tbGenre->Location = System::Drawing::Point(86, 366);
			this->tbGenre->Name = L"tbGenre";
			this->tbGenre->ReadOnly = true;
			this->tbGenre->Size = System::Drawing::Size(294, 20);
			this->tbGenre->TabIndex = 12;
			this->tbGenre->WordWrap = false;
			// 
			// lbGenre
			// 
			this->lbGenre->AutoSize = true;
			this->lbGenre->Location = System::Drawing::Point(12, 369);
			this->lbGenre->Name = L"lbGenre";
			this->lbGenre->Size = System::Drawing::Size(36, 13);
			this->lbGenre->TabIndex = 13;
			this->lbGenre->Text = L"Genre";
			this->lbGenre->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbSize
			// 
			this->lbSize->AutoSize = true;
			this->lbSize->Location = System::Drawing::Point(266, 421);
			this->lbSize->Name = L"lbSize";
			this->lbSize->Size = System::Drawing::Size(57, 13);
			this->lbSize->TabIndex = 15;
			this->lbSize->Text = L"Size in MB";
			this->lbSize->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbComment
			// 
			this->tbComment->Location = System::Drawing::Point(86, 392);
			this->tbComment->Name = L"tbComment";
			this->tbComment->ReadOnly = true;
			this->tbComment->Size = System::Drawing::Size(294, 20);
			this->tbComment->TabIndex = 16;
			this->tbComment->WordWrap = false;
			// 
			// lbComment
			// 
			this->lbComment->AutoSize = true;
			this->lbComment->Location = System::Drawing::Point(12, 395);
			this->lbComment->Name = L"lbComment";
			this->lbComment->Size = System::Drawing::Size(51, 13);
			this->lbComment->TabIndex = 17;
			this->lbComment->Text = L"Comment";
			this->lbComment->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbBPM
			// 
			this->tbBPM->Location = System::Drawing::Point(86, 418);
			this->tbBPM->Name = L"tbBPM";
			this->tbBPM->ReadOnly = true;
			this->tbBPM->Size = System::Drawing::Size(34, 20);
			this->tbBPM->TabIndex = 18;
			this->tbBPM->WordWrap = false;
			// 
			// tbBitrate
			// 
			this->tbBitrate->Location = System::Drawing::Point(215, 418);
			this->tbBitrate->Name = L"tbBitrate";
			this->tbBitrate->ReadOnly = true;
			this->tbBitrate->Size = System::Drawing::Size(34, 20);
			this->tbBitrate->TabIndex = 19;
			this->tbBitrate->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbBitrate->WordWrap = false;
			// 
			// lbBitrate
			// 
			this->lbBitrate->AutoSize = true;
			this->lbBitrate->Location = System::Drawing::Point(141, 421);
			this->lbBitrate->Name = L"lbBitrate";
			this->lbBitrate->Size = System::Drawing::Size(68, 13);
			this->lbBitrate->TabIndex = 20;
			this->lbBitrate->Text = L"Bitrate kBit/s";
			this->lbBitrate->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbBPM
			// 
			this->lbBPM->AutoSize = true;
			this->lbBPM->Location = System::Drawing::Point(12, 421);
			this->lbBPM->Name = L"lbBPM";
			this->lbBPM->Size = System::Drawing::Size(30, 13);
			this->lbBPM->TabIndex = 21;
			this->lbBPM->Text = L"BPM";
			this->lbBPM->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbSize
			// 
			this->tbSize->Location = System::Drawing::Point(329, 418);
			this->tbSize->Name = L"tbSize";
			this->tbSize->ReadOnly = true;
			this->tbSize->Size = System::Drawing::Size(51, 20);
			this->tbSize->TabIndex = 22;
			this->tbSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->tbSize->WordWrap = false;
			// 
			// lbLBTracks
			// 
			this->lbLBTracks->AutoSize = true;
			this->lbLBTracks->Location = System::Drawing::Point(12, 40);
			this->lbLBTracks->Name = L"lbLBTracks";
			this->lbLBTracks->Size = System::Drawing::Size(40, 13);
			this->lbLBTracks->TabIndex = 23;
			this->lbLBTracks->Text = L"Tracks";
			this->lbLBTracks->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btClear
			// 
			this->btClear->Location = System::Drawing::Point(277, 5);
			this->btClear->Name = L"btClear";
			this->btClear->Size = System::Drawing::Size(103, 29);
			this->btClear->TabIndex = 1;
			this->btClear->Text = L"ClearList";
			this->btClear->UseVisualStyleBackColor = true;
			this->btClear->Click += gcnew System::EventHandler(this, &Form1::btClear_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(622, 471);
			this->Controls->Add(this->btClear);
			this->Controls->Add(this->lbLBTracks);
			this->Controls->Add(this->lbBitrate);
			this->Controls->Add(this->tbBitrate);
			this->Controls->Add(this->tbSize);
			this->Controls->Add(this->lbBPM);
			this->Controls->Add(this->tbBPM);
			this->Controls->Add(this->lbComment);
			this->Controls->Add(this->tbComment);
			this->Controls->Add(this->lbSize);
			this->Controls->Add(this->lbGenre);
			this->Controls->Add(this->tbGenre);
			this->Controls->Add(this->lbTrackNum);
			this->Controls->Add(this->tbTrackNum);
			this->Controls->Add(this->lbYear);
			this->Controls->Add(this->tbYear);
			this->Controls->Add(this->lbArtist);
			this->Controls->Add(this->tbArtist);
			this->Controls->Add(this->lbAlbum);
			this->Controls->Add(this->tbAlbum);
			this->Controls->Add(this->lbTitle);
			this->Controls->Add(this->tbTitle);
			this->Controls->Add(this->lbTracks);
			this->Controls->Add(this->btOpen);
			this->Name = L"Form1";
			this->Text = L"MP3 Tagger";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



   System::Void btOpen_Click(System::Object^ sender, System::EventArgs^ e)
   {
      // Displays an OpenFileDialog so the user can select a Cursor.
      OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
      openFileDialog1->Filter = "MP3Audio *.MP3|*.mp3";
      openFileDialog1->Title = "Select a MP3 Audio";

	   //Displays an OpenFolderDialog
	  //FolderBrowserDialog^ openFolder = gcnew FolderBrowserDialog();

      // Show the Dialog.
      // If the user clicked OK in the dialog and
      // a .mp3 file was selected, open it.
      if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK ){
        
		  //TODO here we could also ask for a directory and get the list of files from directory
		  //if (openFolder->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		  //openFolder->SelectedPath;
		
		
		

		///////////////////////////////////////////////////////
        String^ filename = openFileDialog1->FileName;
        //convert filename into std::string
		std::string target = "target"; 
		MarshalString(filename, target);
		
		CMP3Audio* mp3audio = CMP3Audio::read(target);

        if(mp3audio == 0) 
          MessageBox::Show("error");
		
		if(!this->tracks->isInCollection(mp3audio)){

			this->tracks->addTrack(mp3audio);
			String^ name = gcnew String(mp3audio->getFileName());
			lbTracks->Items->Add(name);
			lbTracks->SelectedIndex = (lbTracks->Items->Count-1);

		}else{

			MessageBox::Show("mp3-File already exists");
		}

		

		//delete mp3audio; //only if MP3Audio objects are store in tracks 
      }
   }

  private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

		

           }

private: System::Void selectTrack_Click(System::Object^  sender, System::EventArgs^  e) {
		 
			 if(lbTracks->SelectedIndex != -1){

			String^ curItem = lbTracks->SelectedItem->ToString();

			std::string filename ="";
			MarshalString(curItem, filename);

			//show MP3-Information to this track
			this->showMP3Infos(filename);
		
		}
		 }

private: System::Void showMP3Infos(const std::string& filename) {
			 
			this->tbTitle->Text = gcnew String(this->tracks->getTrack(filename)->getTitle());
			this->tbAlbum->Text = gcnew String(this->tracks->getTrack(filename)->getAlbum());
			this->tbArtist->Text = gcnew String(this->tracks->getTrack(filename)->getArtist());
			this->tbYear->Text = gcnew String(this->tracks->getTrack(filename)->getYear());
			this->tbTrackNum->Text = gcnew String(this->tracks->getTrack(filename)->getTrackNum());
			this->tbGenre->Text = gcnew String(this->tracks->getTrack(filename)->getGenre());
			this->tbComment->Text = gcnew String(this->tracks->getTrack(filename)->getComment());
			this->tbBPM->Text = gcnew String(this->tracks->getTrack(filename)->getBPM());
			this->tbSize->Text = gcnew String(this->tracks->getTrack(filename)->getFileSize().ToString());
			this->tbBitrate->Text = gcnew String(this->tracks->getTrack(filename)->getBitrate().ToString());
			
			/*String^ path = gcnew String(this->tracks->getTrack(filename)->getFilePath());
			MessageBox::Show("Path: " + path);*/
				
		}

 private: System::Void clearMP3Infos() {

		this->tbTitle->Text = "";
		this->tbAlbum->Text = "";
		this->tbArtist->Text = "";
		this->tbYear->Text = "";
		this->tbTrackNum->Text = "";
		this->tbGenre->Text = "";
		this->tbComment->Text = "";
		this->tbBPM->Text = "";
		this->tbSize->Text = "";
		this->tbBitrate->Text = "";
		  
		  }
private: System::Void btClear_Click(System::Object^  sender, System::EventArgs^  e) {

		//clear all lists and GUI fields
		this->tracks->clearTracks();
		this->lbTracks->Items->Clear();
		this->clearMP3Infos();


		 }
};
}

