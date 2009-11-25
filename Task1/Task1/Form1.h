#pragma once

#include <stdio.h>
#include "TracksController.h"
#include "Utils.h"

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

	private:
		CTracksController* tracksController;
	
	public:
		Form1(void)
		{
      
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
			tracksController = new CTracksController();
			if(!tracksController){
				System::Windows::Forms::MessageBox::Show("\nERROR: No memory access. Some components failed to load.\n\n"+
				"\n              ----- MP3Tagger will be closed. -----\n\n\n         Please try to restart the application later!!!\n\n\n","MP3 Tagger",
					System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				exit(0);
			}
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
			delete tracksController;
		}

	private: System::Windows::Forms::GroupBox^  gbSearch;
	private: System::Windows::Forms::TextBox^  tbSearch;
	private: System::Windows::Forms::Label^  lbSearch;
	private: System::Windows::Forms::Button^  btOpen;

	private: System::Windows::Forms::Button^  btClear;
	private: System::Windows::Forms::Button^  btRemove;
	private: System::Windows::Forms::Button^  btAdd;
 
	private: System::Windows::Forms::Button^  btn_indexinfo;

	private: System::Windows::Forms::GroupBox^  gbTracks;
	private: System::Windows::Forms::ListBox^  lbTracks;
	
	private: System::Windows::Forms::GroupBox^  gbMP3Infos;
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
	private: System::Windows::Forms::TextBox^  tbComment;
	private: System::Windows::Forms::Label^  lbComment;
	private: System::Windows::Forms::TextBox^  tbBPM;
	private: System::Windows::Forms::Label^  lbBPM;
	private: System::Windows::Forms::TextBox^  tbBitrate;
	private: System::Windows::Forms::Label^  lbBitrate;
	private: System::Windows::Forms::TextBox^  tbSize;		 
	private: System::Windows::Forms::Label^  lbSize;

	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatLb;

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
			this->btClear = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatLb = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->gbMP3Infos = (gcnew System::Windows::Forms::GroupBox());
			this->gbTracks = (gcnew System::Windows::Forms::GroupBox());
			this->gbSearch = (gcnew System::Windows::Forms::GroupBox());
			this->lbSearch = (gcnew System::Windows::Forms::Label());
			this->tbSearch = (gcnew System::Windows::Forms::TextBox());
			this->btRemove = (gcnew System::Windows::Forms::Button());
			this->btAdd = (gcnew System::Windows::Forms::Button());
			this->btn_indexinfo = (gcnew System::Windows::Forms::Button());
			this->statusStrip1->SuspendLayout();
			this->gbMP3Infos->SuspendLayout();
			this->gbTracks->SuspendLayout();
			this->gbSearch->SuspendLayout();
			this->SuspendLayout();
			// 
			// btOpen
			// 
			this->btOpen->Location = System::Drawing::Point(10, 11);
			this->btOpen->Name = L"btOpen";
			this->btOpen->Size = System::Drawing::Size(90, 29);
			this->btOpen->TabIndex = 1;
			this->btOpen->Text = L"Open Audio";
			this->btOpen->UseVisualStyleBackColor = true;
			this->btOpen->Click += gcnew System::EventHandler(this, &Form1::btOpen_Click);
			// 
			// lbTracks
			// 
			this->lbTracks->AllowDrop = true;
			this->lbTracks->FormattingEnabled = true;
			this->lbTracks->Location = System::Drawing::Point(10, 18);
			this->lbTracks->Name = L"lbTracks";
			this->lbTracks->ScrollAlwaysVisible = true;
			this->lbTracks->Size = System::Drawing::Size(365, 199);
			this->lbTracks->TabIndex = 3;
			this->lbTracks->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::selectTrack_Click);
			this->lbTracks->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::dragFileDrop);
			this->lbTracks->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::dragFileEnter);
			// 
			// tbTitle
			// 
			this->tbTitle->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->tbTitle->Location = System::Drawing::Point(81, 21);
			this->tbTitle->Name = L"tbTitle";
			this->tbTitle->ReadOnly = true;
			this->tbTitle->Size = System::Drawing::Size(294, 20);
			this->tbTitle->TabIndex = 6;
			this->tbTitle->WordWrap = false;
			// 
			// lbTitle
			// 
			this->lbTitle->AutoSize = true;
			this->lbTitle->Location = System::Drawing::Point(7, 24);
			this->lbTitle->Name = L"lbTitle";
			this->lbTitle->Size = System::Drawing::Size(27, 13);
			this->lbTitle->TabIndex = 5;
			this->lbTitle->Text = L"Title";
			this->lbTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbAlbum
			// 
			this->tbAlbum->Location = System::Drawing::Point(81, 47);
			this->tbAlbum->Name = L"tbAlbum";
			this->tbAlbum->ReadOnly = true;
			this->tbAlbum->Size = System::Drawing::Size(294, 20);
			this->tbAlbum->TabIndex = 8;
			this->tbAlbum->WordWrap = false;
			// 
			// lbAlbum
			// 
			this->lbAlbum->AutoSize = true;
			this->lbAlbum->Location = System::Drawing::Point(7, 50);
			this->lbAlbum->Name = L"lbAlbum";
			this->lbAlbum->Size = System::Drawing::Size(36, 13);
			this->lbAlbum->TabIndex = 7;
			this->lbAlbum->Text = L"Album";
			this->lbAlbum->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbArtist
			// 
			this->tbArtist->Location = System::Drawing::Point(81, 73);
			this->tbArtist->Name = L"tbArtist";
			this->tbArtist->ReadOnly = true;
			this->tbArtist->Size = System::Drawing::Size(294, 20);
			this->tbArtist->TabIndex = 10;
			this->tbArtist->WordWrap = false;
			// 
			// lbArtist
			// 
			this->lbArtist->AutoSize = true;
			this->lbArtist->Location = System::Drawing::Point(7, 76);
			this->lbArtist->Name = L"lbArtist";
			this->lbArtist->Size = System::Drawing::Size(46, 13);
			this->lbArtist->TabIndex = 9;
			this->lbArtist->Text = L"Interpret";
			this->lbArtist->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbYear
			// 
			this->tbYear->Location = System::Drawing::Point(81, 99);
			this->tbYear->Name = L"tbYear";
			this->tbYear->ReadOnly = true;
			this->tbYear->Size = System::Drawing::Size(34, 20);
			this->tbYear->TabIndex = 12;
			this->tbYear->WordWrap = false;
			// 
			// lbYear
			// 
			this->lbYear->AutoSize = true;
			this->lbYear->Location = System::Drawing::Point(7, 102);
			this->lbYear->Name = L"lbYear";
			this->lbYear->Size = System::Drawing::Size(29, 13);
			this->lbYear->TabIndex = 11;
			this->lbYear->Text = L"Year";
			this->lbYear->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbTrackNum
			// 
			this->tbTrackNum->Location = System::Drawing::Point(324, 99);
			this->tbTrackNum->Name = L"tbTrackNum";
			this->tbTrackNum->ReadOnly = true;
			this->tbTrackNum->Size = System::Drawing::Size(51, 20);
			this->tbTrackNum->TabIndex = 14;
			this->tbTrackNum->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->tbTrackNum->WordWrap = false;
			// 
			// lbTrackNum
			// 
			this->lbTrackNum->AutoSize = true;
			this->lbTrackNum->Location = System::Drawing::Point(269, 102);
			this->lbTrackNum->Name = L"lbTrackNum";
			this->lbTrackNum->Size = System::Drawing::Size(49, 13);
			this->lbTrackNum->TabIndex = 13;
			this->lbTrackNum->Text = L"TrackNo";
			this->lbTrackNum->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbGenre
			// 
			this->tbGenre->Location = System::Drawing::Point(81, 123);
			this->tbGenre->Name = L"tbGenre";
			this->tbGenre->ReadOnly = true;
			this->tbGenre->Size = System::Drawing::Size(294, 20);
			this->tbGenre->TabIndex = 16;
			this->tbGenre->WordWrap = false;
			// 
			// lbGenre
			// 
			this->lbGenre->AutoSize = true;
			this->lbGenre->Location = System::Drawing::Point(7, 126);
			this->lbGenre->Name = L"lbGenre";
			this->lbGenre->Size = System::Drawing::Size(36, 13);
			this->lbGenre->TabIndex = 15;
			this->lbGenre->Text = L"Genre";
			this->lbGenre->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbSize
			// 
			this->lbSize->AutoSize = true;
			this->lbSize->Location = System::Drawing::Point(261, 178);
			this->lbSize->Name = L"lbSize";
			this->lbSize->Size = System::Drawing::Size(57, 13);
			this->lbSize->TabIndex = 23;
			this->lbSize->Text = L"Size in MB";
			this->lbSize->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbComment
			// 
			this->tbComment->Location = System::Drawing::Point(81, 149);
			this->tbComment->Name = L"tbComment";
			this->tbComment->ReadOnly = true;
			this->tbComment->Size = System::Drawing::Size(294, 20);
			this->tbComment->TabIndex = 18;
			this->tbComment->WordWrap = false;
			// 
			// lbComment
			// 
			this->lbComment->AutoSize = true;
			this->lbComment->Location = System::Drawing::Point(7, 152);
			this->lbComment->Name = L"lbComment";
			this->lbComment->Size = System::Drawing::Size(51, 13);
			this->lbComment->TabIndex = 17;
			this->lbComment->Text = L"Comment";
			this->lbComment->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbBPM
			// 
			this->tbBPM->Location = System::Drawing::Point(81, 175);
			this->tbBPM->Name = L"tbBPM";
			this->tbBPM->ReadOnly = true;
			this->tbBPM->Size = System::Drawing::Size(34, 20);
			this->tbBPM->TabIndex = 20;
			this->tbBPM->WordWrap = false;
			// 
			// lbBPM
			// 
			this->lbBPM->AutoSize = true;
			this->lbBPM->Location = System::Drawing::Point(7, 178);
			this->lbBPM->Name = L"lbBPM";
			this->lbBPM->Size = System::Drawing::Size(30, 13);
			this->lbBPM->TabIndex = 19;
			this->lbBPM->Text = L"BPM";
			this->lbBPM->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbSize
			// 
			this->tbSize->Location = System::Drawing::Point(324, 175);
			this->tbSize->Name = L"tbSize";
			this->tbSize->ReadOnly = true;
			this->tbSize->Size = System::Drawing::Size(51, 20);
			this->tbSize->TabIndex = 24;
			this->tbSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->tbSize->WordWrap = false;
			// 
			// tbBitrate
			// 
			this->tbBitrate->Location = System::Drawing::Point(210, 175);
			this->tbBitrate->Name = L"tbBitrate";
			this->tbBitrate->ReadOnly = true;
			this->tbBitrate->Size = System::Drawing::Size(34, 20);
			this->tbBitrate->TabIndex = 22;
			this->tbBitrate->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbBitrate->WordWrap = false;
			// 
			// lbBitrate
			// 
			this->lbBitrate->AutoSize = true;
			this->lbBitrate->Location = System::Drawing::Point(136, 178);
			this->lbBitrate->Name = L"lbBitrate";
			this->lbBitrate->Size = System::Drawing::Size(68, 13);
			this->lbBitrate->TabIndex = 21;
			this->lbBitrate->Text = L"Bitrate kBit/s";
			this->lbBitrate->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btClear
			// 
			this->btClear->Enabled = false;
			this->btClear->Location = System::Drawing::Point(404, 70);
			this->btClear->Name = L"btClear";
			this->btClear->Size = System::Drawing::Size(90, 29);
			this->btClear->TabIndex = 26;
			this->btClear->Text = L"Clear List";
			this->btClear->UseVisualStyleBackColor = true;
			this->btClear->Click += gcnew System::EventHandler(this, &Form1::btClear_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatLb});
			this->statusStrip1->Location = System::Drawing::Point(0, 509);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(622, 22);
			this->statusStrip1->TabIndex = 29;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatLb
			// 
			this->toolStripStatLb->Enabled = false;
			this->toolStripStatLb->Name = L"toolStripStatLb";
			this->toolStripStatLb->Size = System::Drawing::Size(51, 17);
			this->toolStripStatLb->Text = L"no tracks";
			this->toolStripStatLb->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// gbMP3Infos
			// 
			this->gbMP3Infos->Controls->Add(this->tbYear);
			this->gbMP3Infos->Controls->Add(this->tbTitle);
			this->gbMP3Infos->Controls->Add(this->lbTitle);
			this->gbMP3Infos->Controls->Add(this->tbAlbum);
			this->gbMP3Infos->Controls->Add(this->lbBitrate);
			this->gbMP3Infos->Controls->Add(this->lbAlbum);
			this->gbMP3Infos->Controls->Add(this->tbBitrate);
			this->gbMP3Infos->Controls->Add(this->tbArtist);
			this->gbMP3Infos->Controls->Add(this->tbSize);
			this->gbMP3Infos->Controls->Add(this->lbArtist);
			this->gbMP3Infos->Controls->Add(this->lbBPM);
			this->gbMP3Infos->Controls->Add(this->lbYear);
			this->gbMP3Infos->Controls->Add(this->tbBPM);
			this->gbMP3Infos->Controls->Add(this->tbTrackNum);
			this->gbMP3Infos->Controls->Add(this->lbComment);
			this->gbMP3Infos->Controls->Add(this->lbTrackNum);
			this->gbMP3Infos->Controls->Add(this->tbComment);
			this->gbMP3Infos->Controls->Add(this->tbGenre);
			this->gbMP3Infos->Controls->Add(this->lbSize);
			this->gbMP3Infos->Controls->Add(this->lbGenre);
			this->gbMP3Infos->Location = System::Drawing::Point(7, 287);
			this->gbMP3Infos->Name = L"gbMP3Infos";
			this->gbMP3Infos->Size = System::Drawing::Size(386, 207);
			this->gbMP3Infos->TabIndex = 30;
			this->gbMP3Infos->TabStop = false;
			this->gbMP3Infos->Text = L"MP3 Info";
			// 
			// gbTracks
			// 
			this->gbTracks->Controls->Add(this->lbTracks);
			this->gbTracks->Location = System::Drawing::Point(7, 52);
			this->gbTracks->Name = L"gbTracks";
			this->gbTracks->Size = System::Drawing::Size(386, 229);
			this->gbTracks->TabIndex = 2;
			this->gbTracks->TabStop = false;
			this->gbTracks->Text = L"Tracks";
			// 
			// gbSearch
			// 
			this->gbSearch->Controls->Add(this->lbSearch);
			this->gbSearch->Controls->Add(this->tbSearch);
			this->gbSearch->Controls->Add(this->btOpen);
			this->gbSearch->Location = System::Drawing::Point(7, 1);
			this->gbSearch->Name = L"gbSearch";
			this->gbSearch->Size = System::Drawing::Size(603, 45);
			this->gbSearch->TabIndex = 0;
			this->gbSearch->TabStop = false;
			// 
			// lbSearch
			// 
			this->lbSearch->AutoSize = true;
			this->lbSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbSearch->Location = System::Drawing::Point(340, 17);
			this->lbSearch->Name = L"lbSearch";
			this->lbSearch->Size = System::Drawing::Size(51, 16);
			this->lbSearch->TabIndex = 30;
			this->lbSearch->Text = L"Search";
			this->lbSearch->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tbSearch
			// 
			this->tbSearch->BackColor = System::Drawing::SystemColors::Window;
			this->tbSearch->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->tbSearch->Enabled = false;
			this->tbSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tbSearch->Location = System::Drawing::Point(397, 14);
			this->tbSearch->Name = L"tbSearch";
			this->tbSearch->Size = System::Drawing::Size(200, 22);
			this->tbSearch->TabIndex = 25;
			this->tbSearch->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->tbSearch->TextChanged += gcnew System::EventHandler(this, &Form1::searchField_textChanged);
			// 
			// btRemove
			// 
			this->btRemove->Enabled = false;
			this->btRemove->Location = System::Drawing::Point(404, 140);
			this->btRemove->Name = L"btRemove";
			this->btRemove->Size = System::Drawing::Size(90, 29);
			this->btRemove->TabIndex = 28;
			this->btRemove->Text = L"Remove";
			this->btRemove->UseVisualStyleBackColor = true;
			this->btRemove->Click += gcnew System::EventHandler(this, &Form1::btRemoveClick);
			// 
			// btAdd
			// 
			this->btAdd->Enabled = false;
			this->btAdd->Location = System::Drawing::Point(404, 105);
			this->btAdd->Name = L"btAdd";
			this->btAdd->Size = System::Drawing::Size(90, 29);
			this->btAdd->TabIndex = 27;
			this->btAdd->Text = L"Add";
			this->btAdd->UseVisualStyleBackColor = true;
			this->btAdd->Click += gcnew System::EventHandler(this, &Form1::btOpen_Click);
			// 
			// btn_indexinfo
			// 
			this->btn_indexinfo->Enabled = true;
			this->btn_indexinfo->Location = System::Drawing::Point(404, 175);
			this->btn_indexinfo->Name = L"btn_indexinfo";
			this->btn_indexinfo->Size = System::Drawing::Size(90, 29);
			this->btn_indexinfo->TabIndex = 31;
			this->btn_indexinfo->Text = L"Index Info";
			this->btn_indexinfo->UseVisualStyleBackColor = true;
			this->btn_indexinfo->Click += gcnew System::EventHandler(this, &Form1::btn_indexinfo_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(622, 531);
			this->Controls->Add(this->btn_indexinfo);
			this->Controls->Add(this->btAdd);
			this->Controls->Add(this->btRemove);
			this->Controls->Add(this->btClear);
			this->Controls->Add(this->gbSearch);
			this->Controls->Add(this->gbTracks);
			this->Controls->Add(this->gbMP3Infos);
			this->Controls->Add(this->statusStrip1);
			this->Name = L"Form1";
			this->Text = L"MP3 Tagger";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->gbMP3Infos->ResumeLayout(false);
			this->gbMP3Infos->PerformLayout();
			this->gbTracks->ResumeLayout(false);
			this->gbSearch->ResumeLayout(false);
			this->gbSearch->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void searchField_textChanged(System::Object^  sender, System::EventArgs^  e) {

	//MessageBox::Show(this->tbSearch->Text + " length of text: " + this->tbSearch->TextLength);
			 //this->tbSearch->ResetText(); //delete content of textbox
	//this->tbSearch->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;

  std::string searchterm ="";
	MarshalString(this->tbSearch->Text, searchterm);

  if(searchterm.empty()){ 
		this->updateTitleListOutput(this->tracksController->getAllTitles());
    return;
	}

	const MP3::CSortedTitles* found_titles = this->tracksController->findTitles(searchterm);
	if( found_titles != 0 ){ 
    MessageBox::Show("found somethin");
		this->updateTitleListOutput(found_titles);
	}
		 
}

private: System::Void btn_indexinfo_Click(System::Object^  sender, System::EventArgs^  e) {
      unsigned int length = this->tracksController->getIndexLength();
      unsigned int capacity = this->tracksController->getIndexCapacity();
      MessageBox::Show("Length: " + length + "\n" + "Capacity: " + capacity);
}

private: System::Void btOpen_Click(System::Object^ sender, System::EventArgs^ e) {
      
	  // Displays an OpenFileDialog so the user can select mp3 Files
      OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
	  openFileDialog1->Multiselect = true;
      openFileDialog1->Filter = "MP3Audio *.MP3|*.mp3";
      openFileDialog1->Title = "Select a MP3 Audio";

      // Show the Dialog: If the user clicked OK in the dialog and
      // a .mp3 file was selected, open it.
      if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK ){
        		
		this->openAllFiles(openFileDialog1->FileNames);

		//set right buttons enabled and disable Open Audio button
		this->setButtonsEnabled(this->lbTracks->Items->Count>=1);
      }
}

private: System::Void openAllFiles(System::Array^ filenames){

		for(int i=0; i<filenames->Length; ++i){

			//convert String^ filename into std::string
			std::string target = "target"; 
			MarshalString(filenames->GetValue(i)->ToString(), target);

			//pass file to controller, read ID3 tags and create mp3 object, store it in collection
			Response response = this->tracksController->addFile(target);

			switch(response){

				case NO_MP3_FILE:{ 
					
					System::Windows::Forms::MessageBox::Show("\nSelected file is NOT a mp3 file ( *.MP3 | *.mp3 ) !\n\n\nFAILED TO LOAD:\n\n\""
					+filenames->GetValue(i)->ToString()+"\"\n\n","MP3 Tagger",
					System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Warning);
					lbTracks->Select();
					break;
				}
				case NOT_READ:{ 

					MessageBox::Show("\nERROR: No memory access. \n\n\nFollowing file failed to load:\n\n\""+filenames->GetValue(i)->ToString()+"\"\n\n","MP3 Tagger",
					System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
					lbTracks->Select();
					break;
				}
				case OK:{
					
					MP3::CSortedTitles* titles = this->tracksController->getAllTitles();
					titles->sortTitles();
					this->updateTitleListOutput(titles);
					break;
				}
				case ALREADY_OPENED:{

					//TODO just the filename!!!!!!!!!!
					MessageBox::Show("mp3-File \""+filenames->GetValue(i)->ToString()+"\" already exists");
					lbTracks->Select();
					break;
				}
			}//end of switch			
		}//end of for loop
}

private: System::Void selectTrack_Click(System::Object^  sender, System::EventArgs^  e) {
		 
		if(lbTracks->SelectedIndex != -1){

			String^ curItem = lbTracks->SelectedItem->ToString();

			std::string name ="";
			MarshalString(curItem, name);

			//show MP3-Information to this track
			this->showMP3Infos(name);		
		}
}

private: System::Void btClear_Click(System::Object^  sender, System::EventArgs^  e) {

		//clear all lists and GUI fields
		this->tracksController->removeAllFiles();
		this->lbTracks->Items->Clear();
		this->clearMP3Infos();

		this->setButtonsEnabled(false);
}

private: System::Void btRemoveClick(System::Object^  sender, System::EventArgs^  e) {

		if(lbTracks->SelectedIndex != -1){

			String^ curItem = lbTracks->SelectedItem->ToString();

			std::string name ="";
			MarshalString(curItem, name);

			//remove track
			this->tracksController->removeFile(name);

			this->updateTitleListOutput(this->tracksController->getAllTitles());

			if(lbTracks->Items->Count>=1){
				//lbTracks->SelectedIndex = 0;
			}else{
				this->clearMP3Infos();
				this->setButtonsEnabled(false);
			}
		}
}

//fill listBox with names from sorted title list
private: System::Void updateTitleListOutput( const MP3::CSortedTitles* titles ){

		String^ title;

		//clear listBox Items and MP3 Info
		lbTracks->Items->Clear();
		clearMP3Infos();

		MP3::CSortedTitles::const_iterator iter = titles->getBeginIterator();
		for (iter; iter != titles->getEndIterator(); ++iter ) {
			
			title = gcnew String((iter->sTitleName).c_str());
			//title = gcnew String((*iter).c_str());
			lbTracks->Items->Add(title);
			lbTracks->SelectedIndex = 0;
			lbTracks->Select();
		}

		//output number of read tracks in status strip
		this->toolStripStatLb->Text = titles->getSizeOfSortedTitles().ToString()+ " tracks";
}

private: System::Void setButtonsEnabled(bool flag) {
			 
		this->btClear->Enabled = flag;
		this->btRemove->Enabled = flag;
		this->btAdd->Enabled = flag;
		this->tbSearch->Enabled = flag;

		this->btOpen->Enabled = !flag;
		if(!flag)
		this->btOpen->Select();
}

private: System::Void showMP3Infos(const std::string& name) {

		MP3::CMP3Audio* mp3audio = this->tracksController->getFile(name);

		this->tbTitle->Text = gcnew String(mp3audio->getTitle());
		this->tbAlbum->Text = gcnew String(mp3audio->getAlbum());
		this->tbArtist->Text = gcnew String(mp3audio->getArtist());
		this->tbYear->Text = gcnew String(mp3audio->getYear());
		this->tbTrackNum->Text = gcnew String(mp3audio->getTrackNum());
		this->tbGenre->Text = gcnew String(mp3audio->getGenre());
		this->tbComment->Text = gcnew String(mp3audio->getComment());
		this->tbBPM->Text = gcnew String(mp3audio->getBPM());
		this->tbSize->Text = gcnew String(mp3audio->getFileSize().ToString());
		this->tbBitrate->Text = gcnew String(mp3audio->getBitrate().ToString());
		
		//show filename in bottom status strip
		this->toolStripStatLb->Text = gcnew String(mp3audio->getFileName());

		/*String^ path = gcnew String(mp3audio->getFilePath());
		MessageBox::Show("Path: " + path);*/
				
}

private: System::Void clearMP3Infos( void ) {

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

		this->toolStripStatLb->Text = "no tracks";		  
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
//Drag and drop methods
///////////////////////////////////////////////////////////////////////////////////////////////////////

//called when a specific area is entered
private: System::Void dragFileEnter(System::Object^  /*sender*/, System::Windows::Forms::DragEventArgs^  e) {

		 e->Effect = DragDropEffects::Copy;
}

//called when object was dropped in specific area
private: System::Void dragFileDrop(System::Object^  /*sender*/,System::Windows::Forms::DragEventArgs^  e) {
		
		 //System::Windows::Forms::IDataObject^ data = e->Data;
		 Object^ file = e->Data->GetData("FileNameW");

		 System::Array^ filenames = safe_cast<System::Array^>(file);
		 this->openAllFiles(filenames);

		 //set right buttons enabled and disable Open Audio button
		 this->setButtonsEnabled(this->lbTracks->Items->Count>=1);
}

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {}

};//class Form1

}
