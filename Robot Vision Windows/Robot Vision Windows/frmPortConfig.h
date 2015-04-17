#pragma once

namespace RobotVisionWindows {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmPortConfig
	/// </summary>
	public ref class frmPortConfig : public System::Windows::Forms::Form
	{
	public:
		//********************************
		void Initialize(System::String^ filepath){FilePath =  filepath;}

		frmPortConfig(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmPortConfig()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::String^ FilePath;
		System::Windows::Forms::GroupBox^  gbxMotorPort;
		System::Windows::Forms::Label^  lblMotorPortName;
		System::Windows::Forms::Label^  lblMotorBaudRate;
		System::Windows::Forms::ComboBox^  cboMotorPorts;
		System::Windows::Forms::ComboBox^  cboMotorBaudRate;
		System::Windows::Forms::GroupBox^  gbxSensorPort;
		System::Windows::Forms::Label^  lblSensorPortName;
		System::Windows::Forms::Label^  lblSensorBaudRate;
		System::Windows::Forms::ComboBox^  cboSensorPorts;
		System::Windows::Forms::ComboBox^  cboSensorBaudRate;
		System::Windows::Forms::GroupBox^  gbxIMUPort;
		System::Windows::Forms::Label^  lblIMUPortName;
		System::Windows::Forms::Label^  lblIMUBaudRate;
		System::Windows::Forms::ComboBox^  cboIMUPorts;
		System::Windows::Forms::ComboBox^  cboIMUBaudRate;
		System::Windows::Forms::Button^  btnExit;
		System::Windows::Forms::Button^  btnSave;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmPortConfig::typeid));
			this->lblMotorBaudRate = (gcnew System::Windows::Forms::Label());
			this->lblMotorPortName = (gcnew System::Windows::Forms::Label());
			this->cboMotorBaudRate = (gcnew System::Windows::Forms::ComboBox());
			this->cboMotorPorts = (gcnew System::Windows::Forms::ComboBox());
			this->gbxMotorPort = (gcnew System::Windows::Forms::GroupBox());
			this->gbxSensorPort = (gcnew System::Windows::Forms::GroupBox());
			this->lblSensorPortName = (gcnew System::Windows::Forms::Label());
			this->lblSensorBaudRate = (gcnew System::Windows::Forms::Label());
			this->cboSensorPorts = (gcnew System::Windows::Forms::ComboBox());
			this->cboSensorBaudRate = (gcnew System::Windows::Forms::ComboBox());
			this->gbxIMUPort = (gcnew System::Windows::Forms::GroupBox());
			this->lblIMUPortName = (gcnew System::Windows::Forms::Label());
			this->lblIMUBaudRate = (gcnew System::Windows::Forms::Label());
			this->cboIMUPorts = (gcnew System::Windows::Forms::ComboBox());
			this->cboIMUBaudRate = (gcnew System::Windows::Forms::ComboBox());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->gbxMotorPort->SuspendLayout();
			this->gbxSensorPort->SuspendLayout();
			this->gbxIMUPort->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblMotorBaudRate
			// 
			this->lblMotorBaudRate->AutoSize = true;
			this->lblMotorBaudRate->Location = System::Drawing::Point(5, 55);
			this->lblMotorBaudRate->Name = L"lblMotorBaudRate";
			this->lblMotorBaudRate->Size = System::Drawing::Size(64, 13);
			this->lblMotorBaudRate->TabIndex = 10;
			this->lblMotorBaudRate->Text = L"Baud Rate :";
			// 
			// lblMotorPortName
			// 
			this->lblMotorPortName->AutoSize = true;
			this->lblMotorPortName->Location = System::Drawing::Point(5, 25);
			this->lblMotorPortName->Name = L"lblMotorPortName";
			this->lblMotorPortName->Size = System::Drawing::Size(35, 13);
			this->lblMotorPortName->TabIndex = 9;
			this->lblMotorPortName->Text = L"Port : ";
			// 
			// cboMotorBaudRate
			// 
			this->cboMotorBaudRate->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboMotorBaudRate->FormattingEnabled = true;
			this->cboMotorBaudRate->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"2400", L"4800", L"9600", L"19200", L"38400", 
				L"57600", L"115200"});
			this->cboMotorBaudRate->Location = System::Drawing::Point(96, 52);
			this->cboMotorBaudRate->Name = L"cboMotorBaudRate";
			this->cboMotorBaudRate->Size = System::Drawing::Size(92, 21);
			this->cboMotorBaudRate->TabIndex = 8;
			// 
			// cboMotorPorts
			// 
			this->cboMotorPorts->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboMotorPorts->FormattingEnabled = true;
			this->cboMotorPorts->Location = System::Drawing::Point(67, 22);
			this->cboMotorPorts->Name = L"cboMotorPorts";
			this->cboMotorPorts->Size = System::Drawing::Size(121, 21);
			this->cboMotorPorts->TabIndex = 6;
			// 
			// gbxMotorPort
			// 
			this->gbxMotorPort->Controls->Add(this->lblMotorPortName);
			this->gbxMotorPort->Controls->Add(this->lblMotorBaudRate);
			this->gbxMotorPort->Controls->Add(this->cboMotorPorts);
			this->gbxMotorPort->Controls->Add(this->cboMotorBaudRate);
			this->gbxMotorPort->Location = System::Drawing::Point(12, 12);
			this->gbxMotorPort->Name = L"gbxMotorPort";
			this->gbxMotorPort->Size = System::Drawing::Size(197, 81);
			this->gbxMotorPort->TabIndex = 12;
			this->gbxMotorPort->TabStop = false;
			this->gbxMotorPort->Text = L"Motors Port";
			// 
			// gbxSensorPort
			// 
			this->gbxSensorPort->Controls->Add(this->lblSensorPortName);
			this->gbxSensorPort->Controls->Add(this->lblSensorBaudRate);
			this->gbxSensorPort->Controls->Add(this->cboSensorPorts);
			this->gbxSensorPort->Controls->Add(this->cboSensorBaudRate);
			this->gbxSensorPort->Location = System::Drawing::Point(12, 99);
			this->gbxSensorPort->Name = L"gbxSensorPort";
			this->gbxSensorPort->Size = System::Drawing::Size(197, 81);
			this->gbxSensorPort->TabIndex = 13;
			this->gbxSensorPort->TabStop = false;
			this->gbxSensorPort->Text = L"Sensors Port";
			// 
			// lblSensorPortName
			// 
			this->lblSensorPortName->AutoSize = true;
			this->lblSensorPortName->Location = System::Drawing::Point(5, 25);
			this->lblSensorPortName->Name = L"lblSensorPortName";
			this->lblSensorPortName->Size = System::Drawing::Size(35, 13);
			this->lblSensorPortName->TabIndex = 9;
			this->lblSensorPortName->Text = L"Port : ";
			// 
			// lblSensorBaudRate
			// 
			this->lblSensorBaudRate->AutoSize = true;
			this->lblSensorBaudRate->Location = System::Drawing::Point(5, 55);
			this->lblSensorBaudRate->Name = L"lblSensorBaudRate";
			this->lblSensorBaudRate->Size = System::Drawing::Size(64, 13);
			this->lblSensorBaudRate->TabIndex = 10;
			this->lblSensorBaudRate->Text = L"Baud Rate :";
			// 
			// cboSensorPorts
			// 
			this->cboSensorPorts->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSensorPorts->FormattingEnabled = true;
			this->cboSensorPorts->Location = System::Drawing::Point(67, 22);
			this->cboSensorPorts->Name = L"cboSensorPorts";
			this->cboSensorPorts->Size = System::Drawing::Size(121, 21);
			this->cboSensorPorts->TabIndex = 6;
			// 
			// cboSensorBaudRate
			// 
			this->cboSensorBaudRate->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSensorBaudRate->FormattingEnabled = true;
			this->cboSensorBaudRate->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"2400", L"4800", L"9600", L"19200", L"38400", 
				L"57600", L"115200"});
			this->cboSensorBaudRate->Location = System::Drawing::Point(96, 52);
			this->cboSensorBaudRate->Name = L"cboSensorBaudRate";
			this->cboSensorBaudRate->Size = System::Drawing::Size(92, 21);
			this->cboSensorBaudRate->TabIndex = 8;
			// 
			// gbxIMUPort
			// 
			this->gbxIMUPort->Controls->Add(this->lblIMUPortName);
			this->gbxIMUPort->Controls->Add(this->lblIMUBaudRate);
			this->gbxIMUPort->Controls->Add(this->cboIMUPorts);
			this->gbxIMUPort->Controls->Add(this->cboIMUBaudRate);
			this->gbxIMUPort->Location = System::Drawing::Point(12, 186);
			this->gbxIMUPort->Name = L"gbxIMUPort";
			this->gbxIMUPort->Size = System::Drawing::Size(197, 81);
			this->gbxIMUPort->TabIndex = 14;
			this->gbxIMUPort->TabStop = false;
			this->gbxIMUPort->Text = L"IMU Port";
			// 
			// lblIMUPortName
			// 
			this->lblIMUPortName->AutoSize = true;
			this->lblIMUPortName->Location = System::Drawing::Point(5, 25);
			this->lblIMUPortName->Name = L"lblIMUPortName";
			this->lblIMUPortName->Size = System::Drawing::Size(35, 13);
			this->lblIMUPortName->TabIndex = 9;
			this->lblIMUPortName->Text = L"Port : ";
			// 
			// lblIMUBaudRate
			// 
			this->lblIMUBaudRate->AutoSize = true;
			this->lblIMUBaudRate->Location = System::Drawing::Point(5, 55);
			this->lblIMUBaudRate->Name = L"lblIMUBaudRate";
			this->lblIMUBaudRate->Size = System::Drawing::Size(64, 13);
			this->lblIMUBaudRate->TabIndex = 10;
			this->lblIMUBaudRate->Text = L"Baud Rate :";
			// 
			// cboIMUPorts
			// 
			this->cboIMUPorts->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboIMUPorts->FormattingEnabled = true;
			this->cboIMUPorts->Location = System::Drawing::Point(67, 22);
			this->cboIMUPorts->Name = L"cboIMUPorts";
			this->cboIMUPorts->Size = System::Drawing::Size(121, 21);
			this->cboIMUPorts->TabIndex = 6;
			// 
			// cboIMUBaudRate
			// 
			this->cboIMUBaudRate->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboIMUBaudRate->FormattingEnabled = true;
			this->cboIMUBaudRate->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"2400", L"4800", L"9600", L"19200", L"38400", 
				L"57600", L"115200"});
			this->cboIMUBaudRate->Location = System::Drawing::Point(96, 52);
			this->cboIMUBaudRate->Name = L"cboIMUBaudRate";
			this->cboIMUBaudRate->Size = System::Drawing::Size(92, 21);
			this->cboIMUBaudRate->TabIndex = 8;
			// 
			// btnExit
			// 
			this->btnExit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnExit->Location = System::Drawing::Point(119, 273);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(90, 23);
			this->btnExit->TabIndex = 31;
			this->btnExit->Text = L"E&xit";
			this->btnExit->UseVisualStyleBackColor = true;
			// 
			// btnSave
			// 
			this->btnSave->DialogResult = System::Windows::Forms::DialogResult::Yes;
			this->btnSave->Location = System::Drawing::Point(12, 273);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(90, 23);
			this->btnSave->TabIndex = 32;
			this->btnSave->Text = L"&Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmPortConfig::btnSave_Click);
			// 
			// frmPortConfig
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(223, 304);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->gbxIMUPort);
			this->Controls->Add(this->gbxSensorPort);
			this->Controls->Add(this->gbxMotorPort);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"frmPortConfig";
			this->Text = L"Port Configuration";
			this->Load += gcnew System::EventHandler(this, &frmPortConfig::frmPortConfig_Load);
			this->gbxMotorPort->ResumeLayout(false);
			this->gbxMotorPort->PerformLayout();
			this->gbxSensorPort->ResumeLayout(false);
			this->gbxSensorPort->PerformLayout();
			this->gbxIMUPort->ResumeLayout(false);
			this->gbxIMUPort->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


	private:
		//********************************
		System::Void frmPortConfig_Load(System::Object^  sender, System::EventArgs^  e) {
			array<System::String^>^ serialPorts = nullptr;
			try{ serialPorts = System::IO::Ports::SerialPort::GetPortNames();}
			catch (System::Exception^ ex){
				System::Windows::Forms::MessageBox::Show(ex->Message,"Port Error",System::Windows::Forms::MessageBoxButtons::OK,System::Windows::Forms::MessageBoxIcon::Warning);}
			for each(System::String^ Port in serialPorts){
				cboMotorPorts->Items->Add(Port);
				cboSensorPorts->Items->Add(Port);
				cboIMUPorts->Items->Add(Port);}
			LoadConfigs();
		}
		//********************************
		void SaveConfigs(void){
			try
			{
				array<System::String^,1>^ FileString = System::IO::File::ReadAllLines(FilePath);
				FileString[14] = "***Ports Configuration***";
				FileString[15] = "Motor Port         : " + cboMotorPorts->SelectedItem->ToString();
				FileString[16] = "Motor BuadRate     : " + cboMotorBaudRate->SelectedItem->ToString();
				FileString[17] = "Sensor Port        : " + cboSensorPorts->SelectedItem->ToString();
				FileString[18] = "Sensor BuadRate    : " + cboSensorBaudRate->SelectedItem->ToString();
				FileString[19] = "IMU Port           : " + cboIMUPorts->SelectedItem->ToString();
				FileString[20] = "IMU BuadRate       : " + cboIMUBaudRate->SelectedItem->ToString();
				FileString[21] = " ";
				System::IO::File::WriteAllLines(FilePath,FileString);
			}
			catch(...){}
		}
		//********************************
		void LoadConfigs(void){
			try
			{
				array<System::String^,1>^ FileString = System::IO::File::ReadAllLines(FilePath);

				if(cboMotorPorts->FindString(FileString[15]->Substring(21)) == -1) cboMotorPorts->Items->Add(FileString[15]->Substring(21));
				cboMotorPorts->SelectedItem = FileString[15]->Substring(21);
				cboMotorBaudRate->SelectedItem = FileString[16]->Substring(21);

				if(cboSensorPorts->FindString(FileString[17]->Substring(21)) == -1) cboSensorPorts->Items->Add(FileString[17]->Substring(21));
				cboSensorPorts->SelectedItem = FileString[17]->Substring(21);
				cboSensorBaudRate->SelectedItem = FileString[18]->Substring(21);

				if(cboIMUPorts->FindString(FileString[19]->Substring(21)) == -1) cboIMUPorts->Items->Add(FileString[19]->Substring(21));
				cboIMUPorts->SelectedItem = FileString[19]->Substring(21);
				cboIMUBaudRate->SelectedItem = FileString[20]->Substring(21);

			}
			catch(...){}
		}
		//********************************
		System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e) {
			SaveConfigs();
		}
	};
}
