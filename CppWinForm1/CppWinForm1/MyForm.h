#pragma once

#include "DMXDriver.h"
#include <Windows.h>
#include <mmsystem.h>

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			dmx.FTDI_connect();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tbCode;
	private: System::Windows::Forms::Label^  Armed_Label;
	private: DMXDriver dmx;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tbCode = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Armed_Label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// tbCode
			// 
			this->tbCode->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->tbCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbCode->Location = System::Drawing::Point(344, 190);
			this->tbCode->Name = L"tbCode";
			this->tbCode->Size = System::Drawing::Size(186, 62);
			this->tbCode->TabIndex = 0;
			this->tbCode->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(344, 269);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(186, 51);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Execute";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// Armed_Label
			// 
			this->Armed_Label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Armed_Label->AutoSize = true;
			this->Armed_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Armed_Label->ForeColor = System::Drawing::Color::Red;
			this->Armed_Label->Location = System::Drawing::Point(153, 114);
			this->Armed_Label->Name = L"Armed_Label";
			this->Armed_Label->Size = System::Drawing::Size(640, 73);
			this->Armed_Label->TabIndex = 4;
			this->Armed_Label->Text = L"SYSTEM SECURED";
			this->Armed_Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Armed_Label->Click += gcnew System::EventHandler(this, &MyForm::Armed_Label_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(868, 442);
			this->Controls->Add(this->Armed_Label);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tbCode);
			this->Name = L"MyForm";
			this->Text = L"System Access";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int connected = 0;
		if (!dmx.getDeviceConnected())
		{
			connected = dmx.FTDI_connect();
		}
		
		if(!String::Compare(tbCode->Text, L"1234"))
		{
			Armed_Label->Text = L"ACCESS GRANTED";
			Armed_Label->ForeColor = System::Drawing::Color::Green;
			PlaySound(TEXT("access-granted.wav"), NULL, SND_FILENAME | SND_ASYNC);
			dmx.setBlue();
		}
		else
		{
			Armed_Label->Text = L"SYSTEM SECURED";
			Armed_Label->ForeColor = System::Drawing::Color::Red;
			PlaySound(TEXT("access-denied.wav"), NULL, SND_FILENAME | SND_ASYNC);
			dmx.setRed();
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		
		int connected = 0;
		if(!dmx.getDeviceConnected())
		{ 
			connected = dmx.FTDI_connect();
		}
		dmx.setPurple();
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		int connected = 0;
		if (!dmx.getDeviceConnected())
		{
			connected = dmx.FTDI_connect();
		}
		dmx.setRed();
	}
private: System::Void Armed_Label_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
