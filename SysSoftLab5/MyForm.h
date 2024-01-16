
#pragma once
#pragma comment(lib,"Advapi32.lib")
#include <Windows.h>
#include <string>
#include <vcclr.h>
#include <stdio.h>
#include "SCMC_class.h"

ServiceControlManagerControl SCMC;

namespace SysSoftLab5 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Add_btn;
	protected:
	private: System::Windows::Forms::Button^ Remove_btn;
	private: System::Windows::Forms::Button^ Start_btn;
	private: System::Windows::Forms::Button^ Stop_btn;
	private: System::Windows::Forms::Button^ Open_btn;
	private: System::Windows::Forms::Button^ Close_btn;
	private: System::Windows::Forms::Label^ File_path_text;
	private: System::Windows::Forms::Label^ Service_name_text;
	private: System::Windows::Forms::Label^ Symbolic_link_name_text;
	private: System::Windows::Forms::TextBox^ Symbolic_link_name_edit;
	private: System::Windows::Forms::TextBox^ Service_name_edit;
	private: System::Windows::Forms::Button^ File_path_btn;
	private: System::Windows::Forms::OpenFileDialog^ Open_File_Dialog;
	private: System::Windows::Forms::RichTextBox^ output_edit;
	private: System::Windows::Forms::TextBox^ File_path_edit;
	private: System::Windows::Forms::Button^ Read_btn;
	private: System::Windows::Forms::Button^ Write_btn;
	private: System::Windows::Forms::Button^ Send_btn;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->Add_btn = (gcnew System::Windows::Forms::Button());
			this->Remove_btn = (gcnew System::Windows::Forms::Button());
			this->Start_btn = (gcnew System::Windows::Forms::Button());
			this->Stop_btn = (gcnew System::Windows::Forms::Button());
			this->Open_btn = (gcnew System::Windows::Forms::Button());
			this->Close_btn = (gcnew System::Windows::Forms::Button());
			this->File_path_text = (gcnew System::Windows::Forms::Label());
			this->Service_name_text = (gcnew System::Windows::Forms::Label());
			this->Symbolic_link_name_text = (gcnew System::Windows::Forms::Label());
			this->Symbolic_link_name_edit = (gcnew System::Windows::Forms::TextBox());
			this->Service_name_edit = (gcnew System::Windows::Forms::TextBox());
			this->File_path_btn = (gcnew System::Windows::Forms::Button());
			this->Open_File_Dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->output_edit = (gcnew System::Windows::Forms::RichTextBox());
			this->File_path_edit = (gcnew System::Windows::Forms::TextBox());
			this->Read_btn = (gcnew System::Windows::Forms::Button());
			this->Write_btn = (gcnew System::Windows::Forms::Button());
			this->Send_btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();

			this->Add_btn->Location = System::Drawing::Point(12, 111);
			this->Add_btn->Name = L"Add_btn";
			this->Add_btn->Size = System::Drawing::Size(84, 28);
			this->Add_btn->TabIndex = 0;
			this->Add_btn->Text = L"Add";
			this->Add_btn->UseVisualStyleBackColor = true;
			this->Add_btn->Click += gcnew System::EventHandler(this, &MyForm::Add_btn_Click);

			this->Remove_btn->Location = System::Drawing::Point(98, 111);
			this->Remove_btn->Name = L"Remove_btn";
			this->Remove_btn->Size = System::Drawing::Size(84, 28);
			this->Remove_btn->TabIndex = 1;
			this->Remove_btn->Text = L"Remove";
			this->Remove_btn->UseVisualStyleBackColor = true;
			this->Remove_btn->Click += gcnew System::EventHandler(this, &MyForm::Remove_btn_Click);

			this->Start_btn->Location = System::Drawing::Point(12, 142);
			this->Start_btn->Name = L"Start_btn";
			this->Start_btn->Size = System::Drawing::Size(84, 28);
			this->Start_btn->TabIndex = 2;
			this->Start_btn->Text = L"Start";
			this->Start_btn->UseVisualStyleBackColor = true;
			this->Start_btn->Click += gcnew System::EventHandler(this, &MyForm::Start_btn_Click);

			this->Stop_btn->Location = System::Drawing::Point(98, 142);
			this->Stop_btn->Name = L"Stop_btn";
			this->Stop_btn->Size = System::Drawing::Size(84, 28);
			this->Stop_btn->TabIndex = 3;
			this->Stop_btn->Text = L"Stop";
			this->Stop_btn->UseVisualStyleBackColor = true;
			this->Stop_btn->Click += gcnew System::EventHandler(this, &MyForm::Stop_btn_Click);

			this->Open_btn->Location = System::Drawing::Point(12, 173);
			this->Open_btn->Name = L"Open_btn";
			this->Open_btn->Size = System::Drawing::Size(84, 28);
			this->Open_btn->TabIndex = 4;
			this->Open_btn->Text = L"Open";
			this->Open_btn->UseVisualStyleBackColor = true;
			this->Open_btn->Click += gcnew System::EventHandler(this, &MyForm::Open_btn_Click);

			this->Close_btn->Location = System::Drawing::Point(98, 173);
			this->Close_btn->Name = L"Close_btn";
			this->Close_btn->Size = System::Drawing::Size(84, 28);
			this->Close_btn->TabIndex = 5;
			this->Close_btn->Text = L"Close";
			this->Close_btn->UseVisualStyleBackColor = true;
			this->Close_btn->Click += gcnew System::EventHandler(this, &MyForm::Close_btn_Click);

			this->File_path_text->AutoSize = true;
			this->File_path_text->Location = System::Drawing::Point(132, 9);
			this->File_path_text->Name = L"File_path_text";
			this->File_path_text->Size = System::Drawing::Size(50, 13);
			this->File_path_text->TabIndex = 6;
			this->File_path_text->Text = L"File path:";
 
			this->Service_name_text->Location = System::Drawing::Point(12, 16);
			this->Service_name_text->Name = L"Service_name_text";
			this->Service_name_text->Size = System::Drawing::Size(84, 13);
			this->Service_name_text->TabIndex = 7;
			this->Service_name_text->Text = L"Service name:";
			this->Service_name_text->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			this->Symbolic_link_name_text->Location = System::Drawing::Point(9, 69);
			this->Symbolic_link_name_text->Name = L"Symbolic_link_name_text";
			this->Symbolic_link_name_text->Size = System::Drawing::Size(116, 13);
			this->Symbolic_link_name_text->TabIndex = 8;
			this->Symbolic_link_name_text->Text = L"Symbolic link name:";
			this->Symbolic_link_name_text->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			this->Symbolic_link_name_edit->Location = System::Drawing::Point(10, 85);
			this->Symbolic_link_name_edit->Name = L"Symbolic_link_name_edit";
			this->Symbolic_link_name_edit->Size = System::Drawing::Size(169, 20);
			this->Symbolic_link_name_edit->TabIndex = 9;

			this->Service_name_edit->Location = System::Drawing::Point(9, 32);
			this->Service_name_edit->Name = L"Service_name_edit";
			this->Service_name_edit->Size = System::Drawing::Size(170, 20);
			this->Service_name_edit->TabIndex = 10;

			this->File_path_btn->Location = System::Drawing::Point(442, 6);
			this->File_path_btn->Name = L"File_path_btn";
			this->File_path_btn->Size = System::Drawing::Size(24, 20);
			this->File_path_btn->TabIndex = 11;
			this->File_path_btn->Text = L"...";
			this->File_path_btn->UseVisualStyleBackColor = true;
			this->File_path_btn->Click += gcnew System::EventHandler(this, &MyForm::File_path_btn_Click);

			this->output_edit->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->output_edit->Location = System::Drawing::Point(188, 32);
			this->output_edit->Name = L"output_edit";
			this->output_edit->ReadOnly = true;
			this->output_edit->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedBoth;
			this->output_edit->Size = System::Drawing::Size(278, 206);
			this->output_edit->TabIndex = 12;
			this->output_edit->Text = L"";

			this->File_path_edit->Location = System::Drawing::Point(188, 6);
			this->File_path_edit->Name = L"File_path_edit";
			this->File_path_edit->Size = System::Drawing::Size(248, 20);
			this->File_path_edit->TabIndex = 13;

			this->Read_btn->Location = System::Drawing::Point(12, 210);
			this->Read_btn->Name = L"Read_btn";
			this->Read_btn->Size = System::Drawing::Size(53, 28);
			this->Read_btn->TabIndex = 14;
			this->Read_btn->Text = L"Read";
			this->Read_btn->UseVisualStyleBackColor = true;
			this->Read_btn->Click += gcnew System::EventHandler(this, &MyForm::Read_btn_Click);

			this->Write_btn->Location = System::Drawing::Point(135, 210);
			this->Write_btn->Name = L"Write_btn";
			this->Write_btn->Size = System::Drawing::Size(47, 28);
			this->Write_btn->TabIndex = 15;
			this->Write_btn->Text = L"Write";
			this->Write_btn->UseVisualStyleBackColor = true;
			this->Write_btn->Click += gcnew System::EventHandler(this, &MyForm::Write_btn_Click);

			this->Send_btn->Location = System::Drawing::Point(68, 210);
			this->Send_btn->Name = L"Send_btn";
			this->Send_btn->Size = System::Drawing::Size(64, 28);
			this->Send_btn->TabIndex = 16;
			this->Send_btn->Text = L"Send CTL";
			this->Send_btn->UseVisualStyleBackColor = true;
			this->Send_btn->Click += gcnew System::EventHandler(this, &MyForm::Send_btn_Click);

			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(477, 250);
			this->Controls->Add(this->Send_btn);
			this->Controls->Add(this->Write_btn);
			this->Controls->Add(this->Read_btn);
			this->Controls->Add(this->File_path_edit);
			this->Controls->Add(this->output_edit);
			this->Controls->Add(this->File_path_btn);
			this->Controls->Add(this->Service_name_edit);
			this->Controls->Add(this->Symbolic_link_name_edit);
			this->Controls->Add(this->Symbolic_link_name_text);
			this->Controls->Add(this->Service_name_text);
			this->Controls->Add(this->File_path_text);
			this->Controls->Add(this->Close_btn);
			this->Controls->Add(this->Open_btn);
			this->Controls->Add(this->Stop_btn);
			this->Controls->Add(this->Start_btn);
			this->Controls->Add(this->Remove_btn);
			this->Controls->Add(this->Add_btn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximumSize = System::Drawing::Size(493, 289);
			this->MinimumSize = System::Drawing::Size(493, 289);
			this->Name = L"MyForm";
			this->Text = L"instdrv";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void File_path_btn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		IO::Stream^ stream;
		OpenFileDialog^ Open_file_dlg = gcnew OpenFileDialog();
		Open_file_dlg->Filter = "Sys files (*.sys)|*.sys";
		if (Open_file_dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			File_path_edit->Text = Open_file_dlg->FileName;
			if ((stream = Open_file_dlg->OpenFile()) != nullptr)
			{
				stream->Close();
			}
		}
	}
	private: System::Void Add_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		pin_ptr<const wchar_t> DisplayName = PtrToStringChars(Service_name_edit->Text);
		pin_ptr<const wchar_t> BinaryPathName = PtrToStringChars(File_path_edit->Text);
		SCMC.SetDriverInfo(DisplayName, BinaryPathName);
		DWORD error = SCMC.Add();
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Add service error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Add service success\r\n";
	}
	private: System::Void Remove_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		DWORD error = SCMC.Remove();
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Remove service error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Remove service success\r\n";
	}
	private: System::Void Start_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		DWORD error = SCMC.Start();
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Start service error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Start service success\r\n";
	}
	private: System::Void Stop_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		DWORD error = SCMC.Stop();
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Stop service error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Stop service success\r\n";
	}
	private: System::Void Open_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		pin_ptr<const wchar_t> SymbolicLinkName = PtrToStringChars(Symbolic_link_name_edit->Text);
		DWORD error = SCMC.Open(SymbolicLinkName);
		if (error != ERROR_SUCCESS)
		{
			if (error == 4294967295)
				output_edit->Text += L"Open device error (aready opened)\r\n";
			else if (error == 4294967294)
				output_edit->Text += L"Open device error (invalid link)\r\n";
			else if (error == 4294967293)
				output_edit->Text += L"Open device success\r\n";
			else
				output_edit->Text += L"Open device error (" + error.ToString() + ")\r\n";
		}
		else
			output_edit->Text += L"Open device success\r\n";
	}
	private: System::Void Close_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		DWORD error = SCMC.Close();
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Close device error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Close device success\r\n";
	}
	private: System::Void Read_btn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		unsigned char buf[8];
		std::wstring str;
		DWORD error = SCMC.Read(&str, buf, 8);
		output_edit->Text += gcnew String(str.c_str());
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Read from device error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Read from device success\r\n";
	}
	private: System::Void Send_btn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		unsigned char InBuf[8] = "_aboba_";
		unsigned char OutBuf[16];
		std::wstring str;
		DWORD error = SCMC.SendCtlCode(&str, IOCTL_MY_INDIRECT, InBuf, 8, OutBuf, 16);
		output_edit->Text += gcnew String(str.c_str());
		str.clear();
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Send CTL code to device error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Send CTL code to device success\r\n";

		error = SCMC.SendCtlCode(&str, IOCTL_MY_OUTDIRECT, InBuf, 8, OutBuf, 16);
		output_edit->Text += gcnew String(str.c_str());
		str.clear();
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Send CTL code to device error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Send CTL code to device success\r\n";

		error = SCMC.SendCtlCode(&str, IOCTL_MY_NEITHER, InBuf, 8, OutBuf, 16);
		output_edit->Text += gcnew String(str.c_str());
		str.clear();
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Send CTL code to device error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Send CTL code to device success\r\n";
		error = SCMC.SendCtlCode(&str, IOCTL_MY_BUFFERED, InBuf, 8, OutBuf, 16);
		output_edit->Text += gcnew String(str.c_str());
		str.clear();
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Send CTL code to device error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Send CTL code to device success\r\n";
		error = SCMC.SendCtlCode(&str, IOCTL_UNK_INDIRECT, InBuf, 8, OutBuf, 16);
		output_edit->Text += gcnew String(str.c_str());
		str.clear();
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Send CTL code to device error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Send CTL code to device success\r\n";
		error = SCMC.SendCtlCode(&str, IOCTL_UNK_OUTDIRECT, InBuf, 8, OutBuf, 16);
		output_edit->Text += gcnew String(str.c_str());
		str.clear();
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Send CTL code to device error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Send CTL code to device success\r\n";
		error = SCMC.SendCtlCode(&str, IOCTL_UNK_NEITHER, InBuf, 8, OutBuf, 16);
		output_edit->Text += gcnew String(str.c_str());
		str.clear();
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Send CTL code to device error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Send CTL code to device success\r\n";
		error = SCMC.SendCtlCode(&str, IOCTL_UNK_BUFFERED, InBuf, 8, OutBuf, 16);
		output_edit->Text += gcnew String(str.c_str());
		str.clear();
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Send CTL code to device error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Send CTL code to device success\r\n";
	}
	private: System::Void Write_btn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		unsigned char buf[16] = "aboba 123456789";
		std::wstring str;
		DWORD error = SCMC.Write(&str, buf, 16);
		output_edit->Text += gcnew String(str.c_str());
		if (error != ERROR_SUCCESS)
			output_edit->Text += L"Write to device error (" + error.ToString() + ")\r\n";
		else
			output_edit->Text += L"Write to device success\r\n";
	}
};
}
