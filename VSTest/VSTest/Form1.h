#pragma once

#include "Person.h" 

namespace VSTest {

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
    CPerson* pers;
	public:
		Form1(void)
		{
			InitializeComponent();
			pers = new CPerson("Peter", 2);
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
	private: System::Windows::Forms::Button^  btAddItem;
  private: System::Windows::Forms::TextBox^  tbNewItem;
  private: System::Windows::Forms::ListBox^  lbItems;



  protected: 

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
      this->btAddItem = (gcnew System::Windows::Forms::Button());
      this->tbNewItem = (gcnew System::Windows::Forms::TextBox());
      this->lbItems = (gcnew System::Windows::Forms::ListBox());
      this->SuspendLayout();
      // 
      // btAddItem
      // 
      this->btAddItem->Location = System::Drawing::Point(146, 224);
      this->btAddItem->Name = L"btAddItem";
      this->btAddItem->Size = System::Drawing::Size(96, 30);
      this->btAddItem->TabIndex = 0;
      this->btAddItem->Text = L"Add Item";
      this->btAddItem->UseVisualStyleBackColor = true;
      this->btAddItem->Click += gcnew System::EventHandler(this, &Form1::btAddItem_click);
      // 
      // tbNewItem
      // 
      this->tbNewItem->Location = System::Drawing::Point(21, 190);
      this->tbNewItem->Name = L"tbNewItem";
      this->tbNewItem->Size = System::Drawing::Size(221, 20);
      this->tbNewItem->TabIndex = 1;
      // 
      // lbItems
      // 
      this->lbItems->FormattingEnabled = true;
      this->lbItems->Location = System::Drawing::Point(21, 9);
      this->lbItems->Name = L"lbItems";
      this->lbItems->Size = System::Drawing::Size(221, 147);
      this->lbItems->TabIndex = 2;
      // 
      // Form1
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(292, 266);
      this->Controls->Add(this->lbItems);
      this->Controls->Add(this->tbNewItem);
      this->Controls->Add(this->btAddItem);
      this->Name = L"Form1";
      this->Text = L"Form1";
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
	private: System::Void btAddItem_click(System::Object^  sender, System::EventArgs^  e) {
				 //MessageBox::Show("btAddItem wurde geklickt!", "Event",
         //  MessageBoxButtons::OK, MessageBoxIcon::Information );

        int a = pers->getAge();
        String ^sTemp = gcnew String( pers->getName());
        lbItems->Items->Add( String::Format("Item: (0): Person: (1), Age: (2)",tbNewItem->Text, sTemp, a ));
			 }
	};
}

