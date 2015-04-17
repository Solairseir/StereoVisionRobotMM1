#pragma once
#include "stereoVision.h"


namespace RobotVisionWindows {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmCameraProperties
	/// </summary>

	StereoVision *stereoVision;

	public ref class frmCameraProperties : public System::Windows::Forms::Form
	{
	public:

		frmCameraProperties(StereoVision &Stereovision,System::String^ filepath)
		{
			FilePath =  filepath;
			stereoVision = &Stereovision;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmCameraProperties()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		System::String^ FilePath;
		System::Windows::Forms::HScrollBar^  hsbBrightness;
		System::Windows::Forms::HScrollBar^  hsbContrast;
		System::Windows::Forms::HScrollBar^  hsbSaturation;
		System::Windows::Forms::HScrollBar^  hsbGain;
		System::Windows::Forms::HScrollBar^  hsbExposure;
		System::Windows::Forms::HScrollBar^  hsbWhiteBalance;
		System::Windows::Forms::HScrollBar^  hsbSharpness;
		System::Windows::Forms::HScrollBar^  hsbZoom;
		System::Windows::Forms::HScrollBar^  hsbFocus;
		System::Windows::Forms::Label^  lblBrightness;
		System::Windows::Forms::Label^  lblContrast;
		System::Windows::Forms::Label^  lblGain;
		System::Windows::Forms::Label^  lblWhiteBalance;
		System::Windows::Forms::Label^  lblSharpness;
		System::Windows::Forms::Label^  lblZoom;
		System::Windows::Forms::Label^  lblFocus;
		System::Windows::Forms::Label^  lblExposure;
		System::Windows::Forms::Label^  lblSaturation;
		System::Windows::Forms::RadioButton^  rbLeftCamera;
		System::Windows::Forms::RadioButton^  rbRightCamera;
		System::Windows::Forms::Button^  btnSave;
		System::Windows::Forms::Button^  btnExit;
		System::Windows::Forms::TextBox^  txtBrightness;
		System::Windows::Forms::TextBox^  txtContrast;
		System::Windows::Forms::TextBox^  txtExposure;
		System::Windows::Forms::TextBox^  txtWhiteBalance;
		System::Windows::Forms::TextBox^  txtSharpness;
		System::Windows::Forms::TextBox^  txtZoom;
		System::Windows::Forms::TextBox^  txtFocus;
		System::Windows::Forms::TextBox^  txtSaturation;
		System::Windows::Forms::TextBox^  txtGain;
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent()
		{
			this->hsbBrightness = (gcnew System::Windows::Forms::HScrollBar());
			this->hsbContrast = (gcnew System::Windows::Forms::HScrollBar());
			this->hsbSaturation = (gcnew System::Windows::Forms::HScrollBar());
			this->hsbGain = (gcnew System::Windows::Forms::HScrollBar());
			this->hsbExposure = (gcnew System::Windows::Forms::HScrollBar());
			this->hsbWhiteBalance = (gcnew System::Windows::Forms::HScrollBar());
			this->hsbSharpness = (gcnew System::Windows::Forms::HScrollBar());
			this->hsbZoom = (gcnew System::Windows::Forms::HScrollBar());
			this->hsbFocus = (gcnew System::Windows::Forms::HScrollBar());
			this->lblBrightness = (gcnew System::Windows::Forms::Label());
			this->lblContrast = (gcnew System::Windows::Forms::Label());
			this->lblSaturation = (gcnew System::Windows::Forms::Label());
			this->lblGain = (gcnew System::Windows::Forms::Label());
			this->lblWhiteBalance = (gcnew System::Windows::Forms::Label());
			this->lblSharpness = (gcnew System::Windows::Forms::Label());
			this->lblZoom = (gcnew System::Windows::Forms::Label());
			this->lblFocus = (gcnew System::Windows::Forms::Label());
			this->lblExposure = (gcnew System::Windows::Forms::Label());
			this->rbLeftCamera = (gcnew System::Windows::Forms::RadioButton());
			this->rbRightCamera = (gcnew System::Windows::Forms::RadioButton());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->txtBrightness = (gcnew System::Windows::Forms::TextBox());
			this->txtContrast = (gcnew System::Windows::Forms::TextBox());
			this->txtExposure = (gcnew System::Windows::Forms::TextBox());
			this->txtWhiteBalance = (gcnew System::Windows::Forms::TextBox());
			this->txtSharpness = (gcnew System::Windows::Forms::TextBox());
			this->txtZoom = (gcnew System::Windows::Forms::TextBox());
			this->txtFocus = (gcnew System::Windows::Forms::TextBox());
			this->txtSaturation = (gcnew System::Windows::Forms::TextBox());
			this->txtGain = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// hsbBrightness
			// 
			this->hsbBrightness->BackColor = System::Drawing::Color::DarkRed;
			this->hsbBrightness->Location = System::Drawing::Point(127, 64);
			this->hsbBrightness->Margin = System::Windows::Forms::Padding(6);
			this->hsbBrightness->Maximum = 250;
			this->hsbBrightness->Minimum = -1;
			this->hsbBrightness->Name = L"hsbBrightness";
			this->hsbBrightness->Padding = System::Windows::Forms::Padding(4);
			this->hsbBrightness->Size = System::Drawing::Size(319, 13);
			this->hsbBrightness->TabIndex = 4;
			this->hsbBrightness->TabStop = true;
			this->hsbBrightness->ValueChanged += gcnew System::EventHandler(this, &frmCameraProperties::hsbBrightness_ValueChanged);
			// 
			// hsbContrast
			// 
			this->hsbContrast->BackColor = System::Drawing::Color::DarkRed;
			this->hsbContrast->Location = System::Drawing::Point(127, 97);
			this->hsbContrast->Margin = System::Windows::Forms::Padding(6);
			this->hsbContrast->Maximum = 250;
			this->hsbContrast->Minimum = -1;
			this->hsbContrast->Name = L"hsbContrast";
			this->hsbContrast->Padding = System::Windows::Forms::Padding(4);
			this->hsbContrast->Size = System::Drawing::Size(319, 13);
			this->hsbContrast->TabIndex = 7;
			this->hsbContrast->TabStop = true;
			this->hsbContrast->ValueChanged += gcnew System::EventHandler(this, &frmCameraProperties::hsbContrast_ValueChanged);
			// 
			// hsbSaturation
			// 
			this->hsbSaturation->BackColor = System::Drawing::Color::DarkRed;
			this->hsbSaturation->Location = System::Drawing::Point(127, 130);
			this->hsbSaturation->Margin = System::Windows::Forms::Padding(6);
			this->hsbSaturation->Maximum = 250;
			this->hsbSaturation->Minimum = -1;
			this->hsbSaturation->Name = L"hsbSaturation";
			this->hsbSaturation->Padding = System::Windows::Forms::Padding(4);
			this->hsbSaturation->Size = System::Drawing::Size(319, 13);
			this->hsbSaturation->TabIndex = 10;
			this->hsbSaturation->TabStop = true;
			this->hsbSaturation->ValueChanged += gcnew System::EventHandler(this, &frmCameraProperties::hsbSaturation_ValueChanged);
			// 
			// hsbGain
			// 
			this->hsbGain->BackColor = System::Drawing::Color::DarkRed;
			this->hsbGain->Location = System::Drawing::Point(127, 163);
			this->hsbGain->Margin = System::Windows::Forms::Padding(6);
			this->hsbGain->Maximum = 250;
			this->hsbGain->Minimum = -1;
			this->hsbGain->Name = L"hsbGain";
			this->hsbGain->Padding = System::Windows::Forms::Padding(4);
			this->hsbGain->Size = System::Drawing::Size(319, 13);
			this->hsbGain->TabIndex = 13;
			this->hsbGain->TabStop = true;
			this->hsbGain->ValueChanged += gcnew System::EventHandler(this, &frmCameraProperties::hsbGain_ValueChanged);
			// 
			// hsbExposure
			// 
			this->hsbExposure->BackColor = System::Drawing::Color::DarkRed;
			this->hsbExposure->LargeChange = 1;
			this->hsbExposure->Location = System::Drawing::Point(127, 196);
			this->hsbExposure->Margin = System::Windows::Forms::Padding(6);
			this->hsbExposure->Maximum = 10;
			this->hsbExposure->Minimum = -10;
			this->hsbExposure->Name = L"hsbExposure";
			this->hsbExposure->Padding = System::Windows::Forms::Padding(4);
			this->hsbExposure->Size = System::Drawing::Size(319, 13);
			this->hsbExposure->TabIndex = 16;
			this->hsbExposure->TabStop = true;
			this->hsbExposure->ValueChanged += gcnew System::EventHandler(this, &frmCameraProperties::hsbExposure_ValueChanged);
			// 
			// hsbWhiteBalance
			// 
			this->hsbWhiteBalance->BackColor = System::Drawing::Color::DarkRed;
			this->hsbWhiteBalance->Location = System::Drawing::Point(127, 229);
			this->hsbWhiteBalance->Margin = System::Windows::Forms::Padding(6);
			this->hsbWhiteBalance->Maximum = 10000;
			this->hsbWhiteBalance->Minimum = -1;
			this->hsbWhiteBalance->Name = L"hsbWhiteBalance";
			this->hsbWhiteBalance->Padding = System::Windows::Forms::Padding(4);
			this->hsbWhiteBalance->Size = System::Drawing::Size(319, 13);
			this->hsbWhiteBalance->TabIndex = 19;
			this->hsbWhiteBalance->TabStop = true;
			this->hsbWhiteBalance->ValueChanged += gcnew System::EventHandler(this, &frmCameraProperties::hsbWhiteBalance_ValueChanged);
			// 
			// hsbSharpness
			// 
			this->hsbSharpness->BackColor = System::Drawing::Color::DarkRed;
			this->hsbSharpness->Location = System::Drawing::Point(127, 262);
			this->hsbSharpness->Margin = System::Windows::Forms::Padding(6);
			this->hsbSharpness->Maximum = 250;
			this->hsbSharpness->Minimum = -1;
			this->hsbSharpness->Name = L"hsbSharpness";
			this->hsbSharpness->Padding = System::Windows::Forms::Padding(4);
			this->hsbSharpness->Size = System::Drawing::Size(319, 13);
			this->hsbSharpness->TabIndex = 22;
			this->hsbSharpness->TabStop = true;
			this->hsbSharpness->ValueChanged += gcnew System::EventHandler(this, &frmCameraProperties::hsbSharpness_ValueChanged);
			// 
			// hsbZoom
			// 
			this->hsbZoom->BackColor = System::Drawing::Color::DarkRed;
			this->hsbZoom->LargeChange = 1;
			this->hsbZoom->Location = System::Drawing::Point(127, 295);
			this->hsbZoom->Margin = System::Windows::Forms::Padding(6);
			this->hsbZoom->Maximum = 10;
			this->hsbZoom->Minimum = -1;
			this->hsbZoom->Name = L"hsbZoom";
			this->hsbZoom->Padding = System::Windows::Forms::Padding(4);
			this->hsbZoom->Size = System::Drawing::Size(319, 13);
			this->hsbZoom->TabIndex = 25;
			this->hsbZoom->TabStop = true;
			this->hsbZoom->ValueChanged += gcnew System::EventHandler(this, &frmCameraProperties::hsbZoom_ValueChanged);
			// 
			// hsbFocus
			// 
			this->hsbFocus->BackColor = System::Drawing::Color::DarkRed;
			this->hsbFocus->LargeChange = 17;
			this->hsbFocus->Location = System::Drawing::Point(127, 328);
			this->hsbFocus->Margin = System::Windows::Forms::Padding(6);
			this->hsbFocus->Maximum = 250;
			this->hsbFocus->Minimum = -1;
			this->hsbFocus->Name = L"hsbFocus";
			this->hsbFocus->Padding = System::Windows::Forms::Padding(4);
			this->hsbFocus->Size = System::Drawing::Size(319, 13);
			this->hsbFocus->TabIndex = 28;
			this->hsbFocus->TabStop = true;
			this->hsbFocus->ValueChanged += gcnew System::EventHandler(this, &frmCameraProperties::hsbFocus_ValueChanged);
			// 
			// lblBrightness
			// 
			this->lblBrightness->AutoSize = true;
			this->lblBrightness->Location = System::Drawing::Point(15, 64);
			this->lblBrightness->Name = L"lblBrightness";
			this->lblBrightness->Size = System::Drawing::Size(62, 13);
			this->lblBrightness->TabIndex = 3;
			this->lblBrightness->Text = L"Brightness :";
			// 
			// lblContrast
			// 
			this->lblContrast->AutoSize = true;
			this->lblContrast->Location = System::Drawing::Point(15, 97);
			this->lblContrast->Name = L"lblContrast";
			this->lblContrast->Size = System::Drawing::Size(52, 13);
			this->lblContrast->TabIndex = 6;
			this->lblContrast->Text = L"Contrast :";
			// 
			// lblSaturation
			// 
			this->lblSaturation->AutoSize = true;
			this->lblSaturation->Location = System::Drawing::Point(15, 130);
			this->lblSaturation->Name = L"lblSaturation";
			this->lblSaturation->Size = System::Drawing::Size(61, 13);
			this->lblSaturation->TabIndex = 9;
			this->lblSaturation->Text = L"Saturation :";
			// 
			// lblGain
			// 
			this->lblGain->AutoSize = true;
			this->lblGain->Location = System::Drawing::Point(15, 163);
			this->lblGain->Name = L"lblGain";
			this->lblGain->Size = System::Drawing::Size(35, 13);
			this->lblGain->TabIndex = 12;
			this->lblGain->Text = L"Gain :";
			// 
			// lblWhiteBalance
			// 
			this->lblWhiteBalance->AutoSize = true;
			this->lblWhiteBalance->Location = System::Drawing::Point(15, 229);
			this->lblWhiteBalance->Name = L"lblWhiteBalance";
			this->lblWhiteBalance->Size = System::Drawing::Size(83, 13);
			this->lblWhiteBalance->TabIndex = 18;
			this->lblWhiteBalance->Text = L"White Balance :";
			// 
			// lblSharpness
			// 
			this->lblSharpness->AutoSize = true;
			this->lblSharpness->Location = System::Drawing::Point(15, 262);
			this->lblSharpness->Name = L"lblSharpness";
			this->lblSharpness->Size = System::Drawing::Size(63, 13);
			this->lblSharpness->TabIndex = 21;
			this->lblSharpness->Text = L"Sharpness :";
			// 
			// lblZoom
			// 
			this->lblZoom->AutoSize = true;
			this->lblZoom->Location = System::Drawing::Point(15, 295);
			this->lblZoom->Name = L"lblZoom";
			this->lblZoom->Size = System::Drawing::Size(40, 13);
			this->lblZoom->TabIndex = 24;
			this->lblZoom->Text = L"Zoom :";
			// 
			// lblFocus
			// 
			this->lblFocus->AutoSize = true;
			this->lblFocus->Location = System::Drawing::Point(15, 328);
			this->lblFocus->Name = L"lblFocus";
			this->lblFocus->Size = System::Drawing::Size(42, 13);
			this->lblFocus->TabIndex = 27;
			this->lblFocus->Text = L"Focus :";
			// 
			// lblExposure
			// 
			this->lblExposure->AutoSize = true;
			this->lblExposure->Location = System::Drawing::Point(15, 196);
			this->lblExposure->Name = L"lblExposure";
			this->lblExposure->Size = System::Drawing::Size(57, 13);
			this->lblExposure->TabIndex = 15;
			this->lblExposure->Text = L"Exposure :";
			// 
			// rbLeftCamera
			// 
			this->rbLeftCamera->AutoSize = true;
			this->rbLeftCamera->Checked = true;
			this->rbLeftCamera->Location = System::Drawing::Point(18, 25);
			this->rbLeftCamera->Name = L"rbLeftCamera";
			this->rbLeftCamera->Size = System::Drawing::Size(82, 17);
			this->rbLeftCamera->TabIndex = 1;
			this->rbLeftCamera->TabStop = true;
			this->rbLeftCamera->Text = L"Left Camera";
			this->rbLeftCamera->UseVisualStyleBackColor = true;
			// 
			// rbRightCamera
			// 
			this->rbRightCamera->AutoSize = true;
			this->rbRightCamera->Location = System::Drawing::Point(357, 25);
			this->rbRightCamera->Name = L"rbRightCamera";
			this->rbRightCamera->Size = System::Drawing::Size(89, 17);
			this->rbRightCamera->TabIndex = 2;
			this->rbRightCamera->Text = L"Right Camera";
			this->rbRightCamera->UseVisualStyleBackColor = true;
			this->rbRightCamera->CheckedChanged += gcnew System::EventHandler(this, &frmCameraProperties::rbRightCamera_CheckedChanged);
			// 
			// btnSave
			// 
			this->btnSave->DialogResult = System::Windows::Forms::DialogResult::Yes;
			this->btnSave->Location = System::Drawing::Point(18, 370);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(205, 23);
			this->btnSave->TabIndex = 30;
			this->btnSave->Text = L"&Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmCameraProperties::btnSave_Click);
			// 
			// btnExit
			// 
			this->btnExit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnExit->Location = System::Drawing::Point(241, 370);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(205, 23);
			this->btnExit->TabIndex = 31;
			this->btnExit->Text = L"E&xit";
			this->btnExit->UseVisualStyleBackColor = true;
			// 
			// txtBrightness
			// 
			this->txtBrightness->Location = System::Drawing::Point(455, 61);
			this->txtBrightness->Name = L"txtBrightness";
			this->txtBrightness->Size = System::Drawing::Size(43, 20);
			this->txtBrightness->TabIndex = 5;
			this->txtBrightness->Leave += gcnew System::EventHandler(this, &frmCameraProperties::txtBrightness_Leave);
			// 
			// txtContrast
			// 
			this->txtContrast->Location = System::Drawing::Point(455, 94);
			this->txtContrast->Name = L"txtContrast";
			this->txtContrast->Size = System::Drawing::Size(43, 20);
			this->txtContrast->TabIndex = 8;
			this->txtContrast->Leave += gcnew System::EventHandler(this, &frmCameraProperties::txtContrast_Leave);
			// 
			// txtExposure
			// 
			this->txtExposure->Location = System::Drawing::Point(455, 193);
			this->txtExposure->Name = L"txtExposure";
			this->txtExposure->Size = System::Drawing::Size(43, 20);
			this->txtExposure->TabIndex = 17;
			this->txtExposure->Leave += gcnew System::EventHandler(this, &frmCameraProperties::txtExposure_Leave);
			// 
			// txtWhiteBalance
			// 
			this->txtWhiteBalance->Location = System::Drawing::Point(455, 226);
			this->txtWhiteBalance->Name = L"txtWhiteBalance";
			this->txtWhiteBalance->Size = System::Drawing::Size(43, 20);
			this->txtWhiteBalance->TabIndex = 20;
			this->txtWhiteBalance->Leave += gcnew System::EventHandler(this, &frmCameraProperties::txtWhiteBalance_Leave);
			// 
			// txtSharpness
			// 
			this->txtSharpness->Location = System::Drawing::Point(455, 259);
			this->txtSharpness->Name = L"txtSharpness";
			this->txtSharpness->Size = System::Drawing::Size(43, 20);
			this->txtSharpness->TabIndex = 23;
			this->txtSharpness->Leave += gcnew System::EventHandler(this, &frmCameraProperties::txtSharpness_Leave);
			// 
			// txtZoom
			// 
			this->txtZoom->Location = System::Drawing::Point(455, 292);
			this->txtZoom->Name = L"txtZoom";
			this->txtZoom->Size = System::Drawing::Size(43, 20);
			this->txtZoom->TabIndex = 26;
			this->txtZoom->Leave += gcnew System::EventHandler(this, &frmCameraProperties::txtZoom_Leave);
			// 
			// txtFocus
			// 
			this->txtFocus->Location = System::Drawing::Point(455, 325);
			this->txtFocus->Name = L"txtFocus";
			this->txtFocus->Size = System::Drawing::Size(43, 20);
			this->txtFocus->TabIndex = 29;
			this->txtFocus->Leave += gcnew System::EventHandler(this, &frmCameraProperties::txtFocus_Leave);
			// 
			// txtSaturation
			// 
			this->txtSaturation->Location = System::Drawing::Point(455, 127);
			this->txtSaturation->Name = L"txtSaturation";
			this->txtSaturation->Size = System::Drawing::Size(43, 20);
			this->txtSaturation->TabIndex = 11;
			this->txtSaturation->Leave += gcnew System::EventHandler(this, &frmCameraProperties::txtSaturation_Leave);
			// 
			// txtGain
			// 
			this->txtGain->Location = System::Drawing::Point(455, 160);
			this->txtGain->Name = L"txtGain";
			this->txtGain->Size = System::Drawing::Size(43, 20);
			this->txtGain->TabIndex = 14;
			this->txtGain->Leave += gcnew System::EventHandler(this, &frmCameraProperties::txtGain_Leave);
			// 
			// frmCameraProperties
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(511, 405);
			this->Controls->Add(this->txtGain);
			this->Controls->Add(this->txtSaturation);
			this->Controls->Add(this->txtFocus);
			this->Controls->Add(this->txtZoom);
			this->Controls->Add(this->txtSharpness);
			this->Controls->Add(this->txtWhiteBalance);
			this->Controls->Add(this->txtExposure);
			this->Controls->Add(this->txtContrast);
			this->Controls->Add(this->txtBrightness);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->rbRightCamera);
			this->Controls->Add(this->rbLeftCamera);
			this->Controls->Add(this->lblExposure);
			this->Controls->Add(this->lblFocus);
			this->Controls->Add(this->lblZoom);
			this->Controls->Add(this->lblSharpness);
			this->Controls->Add(this->lblWhiteBalance);
			this->Controls->Add(this->lblGain);
			this->Controls->Add(this->lblSaturation);
			this->Controls->Add(this->lblContrast);
			this->Controls->Add(this->lblBrightness);
			this->Controls->Add(this->hsbSharpness);
			this->Controls->Add(this->hsbZoom);
			this->Controls->Add(this->hsbFocus);
			this->Controls->Add(this->hsbGain);
			this->Controls->Add(this->hsbExposure);
			this->Controls->Add(this->hsbWhiteBalance);
			this->Controls->Add(this->hsbSaturation);
			this->Controls->Add(this->hsbContrast);
			this->Controls->Add(this->hsbBrightness);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"frmCameraProperties";
			this->Text = L"Camera Properties";
			this->Load += gcnew System::EventHandler(this, &frmCameraProperties::frmCameraProperties_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 

		System::Void frmCameraProperties_Load(System::Object^  sender, System::EventArgs^  e) {
			GetCamValues('L');
		}
		//********************************
		System::Void rbRightCamera_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			if(rbRightCamera->Checked) {GetCamValues('R');}
			else {GetCamValues('L');}
		}

		//********************************
		void UpdateTextBoxValues(void){
			txtBrightness->Text = hsbBrightness->Value.ToString();
			txtContrast->Text = hsbContrast->Value.ToString();
			txtSaturation->Text = hsbSaturation->Value.ToString();
			txtGain->Text = hsbGain->Value.ToString();
			txtExposure->Text = hsbExposure->Value.ToString();
			txtWhiteBalance->Text = hsbWhiteBalance->Value.ToString();
			txtSharpness->Text = hsbSharpness->Value.ToString();
			txtZoom->Text = hsbZoom->Value.ToString();
			txtFocus->Text = hsbFocus->Value.ToString();
		}
		//********************************
		void GetCamValues(char Camera){
			int CameraID = 0;

			if(Camera == 'R'){
				CameraID = stereoVision->getRightCameraDeviceID();}
			else {
				CameraID = stereoVision->getLeftCameraDeviceID();}

			hsbBrightness->Value  = stereoVision->GetBrightness(CameraID);
			hsbContrast->Value = stereoVision->GetContrast(CameraID);
			hsbSaturation->Value  = stereoVision->GetSaturation(CameraID);
			hsbGain->Value  = stereoVision->GetGain(CameraID); 
			hsbExposure->Value  = stereoVision->GetExposure(CameraID); 
			hsbWhiteBalance->Value  = stereoVision->GetWhiteBalance(CameraID); 
			hsbSharpness->Value = stereoVision->GetSharpness(CameraID); 
			hsbZoom->Value= stereoVision->GetZoom(CameraID); 
			hsbFocus->Value   = stereoVision->GetFocus(CameraID);
			UpdateTextBoxValues();
		}
		//********************************
		System::Void hsbBrightness_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			if(rbRightCamera->Checked) stereoVision->SetBrightness(stereoVision->getRightCameraDeviceID(),hsbBrightness->Value);
			else stereoVision->SetBrightness(stereoVision->getLeftCameraDeviceID(),hsbBrightness->Value);
			txtBrightness->Text = hsbBrightness->Value.ToString();}
		//********************************
		System::Void hsbContrast_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			if(rbRightCamera->Checked) stereoVision->SetContrast(stereoVision->getRightCameraDeviceID(),hsbContrast->Value);
			else stereoVision->SetContrast(stereoVision->getLeftCameraDeviceID(),hsbContrast->Value);
			txtContrast->Text = hsbContrast->Value.ToString();}
		//********************************
		System::Void hsbSaturation_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			if(rbRightCamera->Checked) stereoVision->SetSaturation(stereoVision->getRightCameraDeviceID(),hsbSaturation->Value);
			else stereoVision->SetSaturation(stereoVision->getLeftCameraDeviceID(),hsbSaturation->Value);
			txtSaturation->Text = hsbSaturation->Value.ToString();}
		//********************************
		System::Void hsbGain_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			if(rbRightCamera->Checked) stereoVision->SetGain(stereoVision->getRightCameraDeviceID(),hsbGain->Value);
			else stereoVision->SetGain(stereoVision->getLeftCameraDeviceID(),hsbGain->Value);
			txtGain->Text = hsbGain->Value.ToString();}
		//********************************
		System::Void hsbExposure_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			if(rbRightCamera->Checked) stereoVision->SetExposure(stereoVision->getRightCameraDeviceID(),hsbExposure->Value);
			else stereoVision->SetExposure(stereoVision->getLeftCameraDeviceID(),hsbExposure->Value);
			txtExposure->Text = hsbExposure->Value.ToString();}
		//********************************
		System::Void hsbWhiteBalance_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			if(rbRightCamera->Checked) stereoVision->SetWhiteBalance(stereoVision->getRightCameraDeviceID(),hsbWhiteBalance->Value);
			else stereoVision->SetWhiteBalance(stereoVision->getLeftCameraDeviceID(),hsbWhiteBalance->Value);
			txtWhiteBalance->Text = hsbWhiteBalance->Value.ToString();}
		//********************************
		System::Void hsbSharpness_ValueChanged(System::Object^  sender, System::EventArgs^  e) {				
			if(rbRightCamera->Checked) stereoVision->SetSharpness(stereoVision->getRightCameraDeviceID(),hsbSharpness->Value);
			else stereoVision->SetSharpness(stereoVision->getLeftCameraDeviceID(),hsbSharpness->Value);
			txtSharpness->Text = hsbSharpness->Value.ToString();}
		//********************************
		System::Void hsbZoom_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			if(rbRightCamera->Checked) stereoVision->SetZoom(stereoVision->getRightCameraDeviceID(),hsbZoom->Value);
			else stereoVision->SetZoom(stereoVision->getLeftCameraDeviceID(),hsbZoom->Value);
			txtZoom->Text = hsbZoom->Value.ToString();}
		//********************************
		System::Void hsbFocus_ValueChanged(System::Object^  sender, System::EventArgs^  e) {				
			if(rbRightCamera->Checked) stereoVision->SetFocus(stereoVision->getRightCameraDeviceID(),hsbFocus->Value);
			else stereoVision->SetFocus(stereoVision->getLeftCameraDeviceID(),hsbFocus->Value);
			txtFocus->Text = hsbFocus->Value.ToString();}
		//********************************
		System::Void txtBrightness_Leave(System::Object^  sender, System::EventArgs^  e) {
			int value = 0;
			try{ value = int::Parse(txtBrightness->Text);}
			catch(...){txtBrightness->Text = hsbBrightness->Value.ToString(); return;}

			if( value >= hsbBrightness->Minimum && value<=hsbBrightness->Maximum){
				hsbBrightness->Value = value;
				if(rbRightCamera->Checked) stereoVision->SetBrightness(stereoVision->getRightCameraDeviceID(),hsbBrightness->Value);
				else stereoVision->SetBrightness(stereoVision->getLeftCameraDeviceID(),hsbBrightness->Value);}
			else{txtBrightness->Text = hsbBrightness->Value.ToString();}
		}
		//********************************
		System::Void txtContrast_Leave(System::Object^  sender, System::EventArgs^  e) {
			int value = 0;
			try{ value = int::Parse(txtContrast->Text);}
			catch(...){txtContrast->Text = hsbContrast->Value.ToString(); return;}

			if( value >= hsbContrast->Minimum && value<=hsbContrast->Maximum){
				hsbContrast->Value = value;
				if(rbRightCamera->Checked) stereoVision->SetContrast(stereoVision->getRightCameraDeviceID(),hsbContrast->Value);
				else stereoVision->SetContrast(stereoVision->getLeftCameraDeviceID(),hsbContrast->Value);}
			else{txtContrast->Text = hsbContrast->Value.ToString();}
		}
		//********************************
		System::Void txtSaturation_Leave(System::Object^  sender, System::EventArgs^  e) {
			int value = 0;
			try{ value = int::Parse(txtSaturation->Text);}
			catch(...){txtSaturation->Text = hsbSaturation->Value.ToString(); return;}

			if( value >= hsbSaturation->Minimum && value<=hsbSaturation->Maximum){
				hsbSaturation->Value = value;
				if(rbRightCamera->Checked) stereoVision->SetSaturation(stereoVision->getRightCameraDeviceID(),hsbSaturation->Value);
				else stereoVision->SetSaturation(stereoVision->getLeftCameraDeviceID(),hsbSaturation->Value);}
			else{txtSaturation->Text = hsbSaturation->Value.ToString();}
		}
		//********************************
		System::Void txtGain_Leave(System::Object^  sender, System::EventArgs^  e) {
			int value = 0;
			try{ value = int::Parse(txtGain->Text);}
			catch(...){txtGain->Text = hsbGain->Value.ToString(); return;}

			if( value >= hsbGain->Minimum && value<=hsbGain->Maximum){
				hsbGain->Value = value;
				if(rbRightCamera->Checked) stereoVision->SetGain(stereoVision->getRightCameraDeviceID(),hsbGain->Value);
				else stereoVision->SetGain(stereoVision->getLeftCameraDeviceID(),hsbGain->Value);}
			else{txtGain->Text = hsbGain->Value.ToString();}
		}
		//********************************
		System::Void txtExposure_Leave(System::Object^  sender, System::EventArgs^  e) {
			int value = 0;
			try{ value = int::Parse(txtExposure->Text);}
			catch(...){txtExposure->Text = hsbExposure->Value.ToString(); return;}

			if( value >= hsbExposure->Minimum && value<=hsbExposure->Maximum){
				hsbExposure->Value = value;
				if(rbRightCamera->Checked) stereoVision->SetExposure(stereoVision->getRightCameraDeviceID(),hsbExposure->Value);
				else stereoVision->SetExposure(stereoVision->getLeftCameraDeviceID(),hsbExposure->Value);}
			else{txtExposure->Text = hsbExposure->Value.ToString();}
		}
		//********************************
		System::Void txtWhiteBalance_Leave(System::Object^  sender, System::EventArgs^  e) {
			int value = 0;
			try{ value = int::Parse(txtWhiteBalance->Text);}
			catch(...){txtWhiteBalance->Text = hsbWhiteBalance->Value.ToString(); return;}

			if( value >= hsbWhiteBalance->Minimum && value<=hsbWhiteBalance->Maximum){
				hsbWhiteBalance->Value = value;
				if(rbRightCamera->Checked) stereoVision->SetWhiteBalance(stereoVision->getRightCameraDeviceID(),hsbWhiteBalance->Value);
				else stereoVision->SetWhiteBalance(stereoVision->getLeftCameraDeviceID(),hsbWhiteBalance->Value);}
			else{txtWhiteBalance->Text = hsbWhiteBalance->Value.ToString();}
		}
		//********************************
		System::Void txtSharpness_Leave(System::Object^  sender, System::EventArgs^  e) {
			int value = 0;
			try{ value = int::Parse(txtSharpness->Text);}
			catch(...){txtSharpness->Text = hsbSharpness->Value.ToString(); return;}

			if( value >= hsbSharpness->Minimum && value<=hsbSharpness->Maximum){
				hsbSharpness->Value = value;
				if(rbRightCamera->Checked) stereoVision->SetSharpness(stereoVision->getRightCameraDeviceID(),hsbSharpness->Value);
				else stereoVision->SetSharpness(stereoVision->getLeftCameraDeviceID(),hsbSharpness->Value);}
			else{txtSharpness->Text = hsbSharpness->Value.ToString();}
		}
		//********************************
		System::Void txtZoom_Leave(System::Object^  sender, System::EventArgs^  e) {
			int value = 0;
			try{ value = int::Parse(txtZoom->Text);}
			catch(...){txtZoom->Text = hsbZoom->Value.ToString(); return;}

			if( value >= hsbZoom->Minimum && value<=hsbZoom->Maximum){
				hsbZoom->Value = value;
				if(rbRightCamera->Checked) stereoVision->SetZoom(stereoVision->getRightCameraDeviceID(),hsbZoom->Value);
				else stereoVision->SetZoom(stereoVision->getLeftCameraDeviceID(),hsbZoom->Value);}
			else{txtZoom->Text = hsbZoom->Value.ToString();}
		}
		//********************************
		System::Void txtFocus_Leave(System::Object^  sender, System::EventArgs^  e) {
			int value = 0;
			try{ value = int::Parse(txtFocus->Text);}
			catch(...){txtFocus->Text = hsbFocus->Value.ToString(); return;}

			if( value >= hsbFocus->Minimum && value<=hsbFocus->Maximum){
				hsbFocus->Value = value;
				if(rbRightCamera->Checked) stereoVision->SetFocus(stereoVision->getRightCameraDeviceID(),hsbFocus->Value);
				else stereoVision->SetFocus(stereoVision->getLeftCameraDeviceID(),hsbFocus->Value);}
			else{txtFocus->Text = hsbFocus->Value.ToString();}
		}
		//********************************
		System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e) {
			SaveConfigs();}
		//********************************
		void SaveConfigs(){
			try
			{
				array<System::String^,1>^ FileString = System::IO::File::ReadAllLines(FilePath);
				FileString[22] = "***Right Camera Configuration***";
				FileString[23] = "Brightness         : " + stereoVision->GetBrightness(stereoVision->getRightCameraDeviceID()).ToString();
				FileString[24] = "Contrast           : " + stereoVision->GetContrast(stereoVision->getRightCameraDeviceID()).ToString();
				FileString[25] = "Saturation         : " + stereoVision->GetSaturation(stereoVision->getRightCameraDeviceID()).ToString();
				FileString[26] = "Gain               : " + stereoVision->GetGain(stereoVision->getRightCameraDeviceID()).ToString();
				FileString[27] = "Exposure           : " + stereoVision->GetExposure(stereoVision->getRightCameraDeviceID()).ToString();
				FileString[28] = "White Balance      : " + stereoVision->GetWhiteBalance(stereoVision->getRightCameraDeviceID()).ToString();
				FileString[29] = "Sharpness          : " + stereoVision->GetSharpness(stereoVision->getRightCameraDeviceID()).ToString();
				FileString[30] = "Zoom               : " + stereoVision->GetZoom(stereoVision->getRightCameraDeviceID()).ToString();
				FileString[31] = "Focus              : " + stereoVision->GetFocus(stereoVision->getRightCameraDeviceID()).ToString();

				FileString[33] = "***Left Camera Configuration***";
				FileString[34] = "Brightness         : " + stereoVision->GetBrightness(stereoVision->getLeftCameraDeviceID()).ToString();
				FileString[35] = "Contrast           : " + stereoVision->GetContrast(stereoVision->getLeftCameraDeviceID()).ToString();
				FileString[36] = "Saturation         : " + stereoVision->GetSaturation(stereoVision->getLeftCameraDeviceID()).ToString();
				FileString[37] = "Gain               : " + stereoVision->GetGain(stereoVision->getLeftCameraDeviceID()).ToString();
				FileString[38] = "Exposure           : " + stereoVision->GetExposure(stereoVision->getLeftCameraDeviceID()).ToString();
				FileString[39] = "White Balance      : " + stereoVision->GetWhiteBalance(stereoVision->getLeftCameraDeviceID()).ToString();
				FileString[40] = "Sharpness          : " + stereoVision->GetSharpness(stereoVision->getLeftCameraDeviceID()).ToString();
				FileString[41] = "Zoom               : " + stereoVision->GetZoom(stereoVision->getLeftCameraDeviceID()).ToString();
				FileString[42] = "Focus              : " + stereoVision->GetFocus(stereoVision->getLeftCameraDeviceID()).ToString();
				System::IO::File::WriteAllLines(FilePath,FileString);
			}
			catch(...){}

		}

	};
}
