#pragma once
#include "stdafx.h"
#include "frmPortConfig.h"
#include "frmCameraProperties.h"
#include "CommunicationHandler.h"
#include "StereoVision.h"
#include "Calibration.h"
#include "SaveAndLoadConfigurations.h"
#include "Simulator.h"
#include "PathPlanning.h"

namespace RobotVisionWindows {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::VisualBasic::ApplicationServices;
	/// <summary>
	/// Summary for MainForm
	/// </summary>

	StereoVision stereovision;
	Calibration calibration;
	Simulator simulator;
	PathPlanning pathplanning;
	std::pair<int,std::pair<int,int>> IMUValues;

	public ref class MainForm : public System::Windows::Forms::Form
	{

	public:
		MainForm(void)
		{
			InitializeComponent();
			InitializeCompassImages();

		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
#pragma region Windows Form Designer Declaration

		System::String^ RobotConfigFilePath;
		System::Diagnostics::Stopwatch watch1;
		System::Diagnostics::Stopwatch watch2;
		double CurrentLeftMotorPosition;
		double CurrentRightMotorPosition;
		double LastCellLeftMotorPosition;
		double LastCellRightMotorPosition;
		int CurrentPathIndex;
		int CurrentPathPointIndex;
		int CurrentRobotDirection;
		int NextRobotDirection;
		int NextRobotPathIndex;
		int NextRobotPathPointIndex;
		int RobotTurnDegree;
		bool RobotIsMovingToNextPoint;
		bool RobotIsTurningToNextDirection;
		bool FirstRun;
		CommunicationHandler Comhandler;
		SaveAndLoadConfigurations Confs;
		System::Drawing::Image^ imgCompassN;
		System::Drawing::Image^ imgCompassS;
		System::Drawing::Image^ imgCompassW;
		System::Drawing::Image^ imgCompassE;
		System::Drawing::Image^ imgCompassNE;
		System::Drawing::Image^ imgCompassNW;
		System::Drawing::Image^ imgCompassSE;
		System::Drawing::Image^ imgCompassSW;
		System::Windows::Forms::Label^  lblMbattery;
		System::Windows::Forms::Label^  lblSbattery;
		System::Windows::Forms::Label^  lblNUCbattery;
		System::Windows::Forms::Label^  lblMbatteryVoltage;
		System::Windows::Forms::Label^  lblSbatteryVoltage;
		System::Windows::Forms::Label^  lblNUCbatteryVoltage;
		System::Windows::Forms::Label^  lblHumidityPercent;
		System::Windows::Forms::Label^  lblTemperatureDegree;
		System::Windows::Forms::Label^  lblMCbatteryCurrent;
		System::Windows::Forms::Label^  lblHumidity;
		System::Windows::Forms::Label^  lblTemperature;
		System::Windows::Forms::Label^  lblMCbattery;
		System::Windows::Forms::PictureBox^  picLeft;
		System::Windows::Forms::PictureBox^  picRight;
		System::Windows::Forms::PictureBox^  picDisparity;
		System::Windows::Forms::CheckBox^  chkShowCameras;
		System::Windows::Forms::CheckBox^  chkEnableSampling;
		System::Windows::Forms::CheckBox^  chkUseCalibratio;
		System::Windows::Forms::CheckBox^  chkComputeDisparity;
		System::Windows::Forms::CheckBox^  chkShowDisparity;
		System::Windows::Forms::Button^  btnCameraProperties;
		System::Windows::Forms::Button^  btnSnapShot;
		System::Windows::Forms::Button^  btnStartPathPlanning;
		System::Windows::Forms::Button^  btnOpenMap;
		System::Windows::Forms::Button^  btnSaveDisparity;
		System::Windows::Forms::Button^  btnCaptureVideo;
		System::Windows::Forms::Button^  btnCalibration;
		System::Windows::Forms::Button^  btnExit;
		System::Windows::Forms::ComboBox^  cboSamplingDistance;
		System::Windows::Forms::Label^  lblSamplingDistance;
		System::Windows::Forms::Label^  lblAvoidanceDistance;
		System::Windows::Forms::ComboBox^  cboAvoidanceDistance;
		System::Windows::Forms::PictureBox^  picCamerasPositions;
		System::Windows::Forms::TextBox^  txtLeftCameraAngle;
		System::Windows::Forms::TextBox^  txtRightCameraAngle;
		System::Windows::Forms::TextBox^  txtCameraUpperTiltAngle;
		System::Windows::Forms::TextBox^  txtCameraPanAngle;
		System::Windows::Forms::PictureBox^  picGridMap;
		System::Windows::Forms::Label^  lblSystemMessages;
		System::Windows::Forms::Label^  lblMessages;
		System::Windows::Forms::Label^  lblLeftMotorEncoder;
		System::Windows::Forms::Label^  lblRightMotorEncoder;
		System::Windows::Forms::Label^  lblRightMotorEncoderValue;
		System::Windows::Forms::Label^  lblLeftMotorEncoderValue;
		System::Windows::Forms::Label^  lblRobotSpeed;
		System::Windows::Forms::ComboBox^  cboRobotSpeed;
		System::Windows::Forms::Button^  btnRobotSelfTest;
		System::Windows::Forms::Button^  btnRobotTurnOn;
		System::Windows::Forms::Button^  btnRobotTurnOff;
		System::Windows::Forms::Timer^  tmrMainLoop;
		System::Windows::Forms::Timer^  tmrSensorRefresh;
		System::Windows::Forms::Label^  lblBlock1;
		System::Windows::Forms::Label^  lblBlock2;
		System::Windows::Forms::Button^  btnPortConfiguration;
		System::Windows::Forms::OpenFileDialog^  openMapDialog;
		System::Windows::Forms::Button^  btnSave;
		System::Windows::Forms::Button^  btnSaveSample;
		System::Windows::Forms::Timer^  tmrCalibrationLoop;
		System::Windows::Forms::Label^  lblFPSValue;
		System::Windows::Forms::Label^  lblFPS;
		System::Windows::Forms::PictureBox^  picCompass;
		System::Windows::Forms::Timer^  tmrPathPlanning;
		System::Windows::Forms::PictureBox^  picIMUPicture;
		System::Windows::Forms::Label^  lblYaw;
		System::Windows::Forms::Label^  lblPitch;
		System::Windows::Forms::Label^  lblRoll;
		System::Windows::Forms::Label^  lblRealFPSValue;
		System::Windows::Forms::Label^  lblRealFPS;
		System::Windows::Forms::PictureBox^  picArmPositions;
		System::Windows::Forms::TextBox^  txtCameraBottomTiltAngle;
		System::Windows::Forms::TextBox^  txtCameraMiddleTiltAngle;
		System::Windows::Forms::RadioButton^  btnPosition1;
		System::Windows::Forms::RadioButton^  btnPosition2;
		System::Windows::Forms::RadioButton^  btnPosition4;
		System::Windows::Forms::RadioButton^  btnPosition3;
		System::Windows::Forms::Label^  lblSCbatteryCurrent;
		System::Windows::Forms::Label^  lblSCbattery;
		System::Windows::Forms::Label^  lblNUCCbatteryCurrent;
		System::Windows::Forms::Label^  lblNUCCbattery;

		System::ComponentModel::IContainer^  components;
#pragma endregion
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->lblMbattery = (gcnew System::Windows::Forms::Label());
			this->lblSbattery = (gcnew System::Windows::Forms::Label());
			this->lblNUCbattery = (gcnew System::Windows::Forms::Label());
			this->lblMbatteryVoltage = (gcnew System::Windows::Forms::Label());
			this->lblSbatteryVoltage = (gcnew System::Windows::Forms::Label());
			this->lblNUCbatteryVoltage = (gcnew System::Windows::Forms::Label());
			this->lblHumidityPercent = (gcnew System::Windows::Forms::Label());
			this->lblTemperatureDegree = (gcnew System::Windows::Forms::Label());
			this->lblMCbatteryCurrent = (gcnew System::Windows::Forms::Label());
			this->lblHumidity = (gcnew System::Windows::Forms::Label());
			this->lblTemperature = (gcnew System::Windows::Forms::Label());
			this->lblMCbattery = (gcnew System::Windows::Forms::Label());
			this->picLeft = (gcnew System::Windows::Forms::PictureBox());
			this->picRight = (gcnew System::Windows::Forms::PictureBox());
			this->picDisparity = (gcnew System::Windows::Forms::PictureBox());
			this->chkShowCameras = (gcnew System::Windows::Forms::CheckBox());
			this->chkEnableSampling = (gcnew System::Windows::Forms::CheckBox());
			this->chkUseCalibratio = (gcnew System::Windows::Forms::CheckBox());
			this->chkComputeDisparity = (gcnew System::Windows::Forms::CheckBox());
			this->chkShowDisparity = (gcnew System::Windows::Forms::CheckBox());
			this->btnCameraProperties = (gcnew System::Windows::Forms::Button());
			this->btnSnapShot = (gcnew System::Windows::Forms::Button());
			this->btnStartPathPlanning = (gcnew System::Windows::Forms::Button());
			this->btnOpenMap = (gcnew System::Windows::Forms::Button());
			this->btnSaveDisparity = (gcnew System::Windows::Forms::Button());
			this->btnCaptureVideo = (gcnew System::Windows::Forms::Button());
			this->btnCalibration = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->cboSamplingDistance = (gcnew System::Windows::Forms::ComboBox());
			this->lblSamplingDistance = (gcnew System::Windows::Forms::Label());
			this->lblAvoidanceDistance = (gcnew System::Windows::Forms::Label());
			this->cboAvoidanceDistance = (gcnew System::Windows::Forms::ComboBox());
			this->picCamerasPositions = (gcnew System::Windows::Forms::PictureBox());
			this->txtLeftCameraAngle = (gcnew System::Windows::Forms::TextBox());
			this->txtRightCameraAngle = (gcnew System::Windows::Forms::TextBox());
			this->txtCameraUpperTiltAngle = (gcnew System::Windows::Forms::TextBox());
			this->txtCameraPanAngle = (gcnew System::Windows::Forms::TextBox());
			this->picGridMap = (gcnew System::Windows::Forms::PictureBox());
			this->lblSystemMessages = (gcnew System::Windows::Forms::Label());
			this->lblMessages = (gcnew System::Windows::Forms::Label());
			this->lblLeftMotorEncoder = (gcnew System::Windows::Forms::Label());
			this->lblRightMotorEncoder = (gcnew System::Windows::Forms::Label());
			this->lblRightMotorEncoderValue = (gcnew System::Windows::Forms::Label());
			this->lblLeftMotorEncoderValue = (gcnew System::Windows::Forms::Label());
			this->lblRobotSpeed = (gcnew System::Windows::Forms::Label());
			this->cboRobotSpeed = (gcnew System::Windows::Forms::ComboBox());
			this->btnRobotSelfTest = (gcnew System::Windows::Forms::Button());
			this->btnRobotTurnOn = (gcnew System::Windows::Forms::Button());
			this->btnRobotTurnOff = (gcnew System::Windows::Forms::Button());
			this->tmrMainLoop = (gcnew System::Windows::Forms::Timer(this->components));
			this->tmrSensorRefresh = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblBlock1 = (gcnew System::Windows::Forms::Label());
			this->lblBlock2 = (gcnew System::Windows::Forms::Label());
			this->btnPortConfiguration = (gcnew System::Windows::Forms::Button());
			this->openMapDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnSaveSample = (gcnew System::Windows::Forms::Button());
			this->tmrCalibrationLoop = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblFPSValue = (gcnew System::Windows::Forms::Label());
			this->lblFPS = (gcnew System::Windows::Forms::Label());
			this->picCompass = (gcnew System::Windows::Forms::PictureBox());
			this->tmrPathPlanning = (gcnew System::Windows::Forms::Timer(this->components));
			this->picIMUPicture = (gcnew System::Windows::Forms::PictureBox());
			this->lblYaw = (gcnew System::Windows::Forms::Label());
			this->lblPitch = (gcnew System::Windows::Forms::Label());
			this->lblRoll = (gcnew System::Windows::Forms::Label());
			this->lblRealFPSValue = (gcnew System::Windows::Forms::Label());
			this->lblRealFPS = (gcnew System::Windows::Forms::Label());
			this->picArmPositions = (gcnew System::Windows::Forms::PictureBox());
			this->txtCameraBottomTiltAngle = (gcnew System::Windows::Forms::TextBox());
			this->txtCameraMiddleTiltAngle = (gcnew System::Windows::Forms::TextBox());
			this->btnPosition1 = (gcnew System::Windows::Forms::RadioButton());
			this->btnPosition2 = (gcnew System::Windows::Forms::RadioButton());
			this->btnPosition4 = (gcnew System::Windows::Forms::RadioButton());
			this->btnPosition3 = (gcnew System::Windows::Forms::RadioButton());
			this->lblSCbatteryCurrent = (gcnew System::Windows::Forms::Label());
			this->lblSCbattery = (gcnew System::Windows::Forms::Label());
			this->lblNUCCbatteryCurrent = (gcnew System::Windows::Forms::Label());
			this->lblNUCCbattery = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picLeft))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picRight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picDisparity))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picCamerasPositions))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picGridMap))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picCompass))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picIMUPicture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picArmPositions))->BeginInit();
			this->SuspendLayout();
			// 
			// lblMbattery
			// 
			this->lblMbattery->AutoSize = true;
			this->lblMbattery->Enabled = false;
			this->lblMbattery->Location = System::Drawing::Point(12, 41);
			this->lblMbattery->Name = L"lblMbattery";
			this->lblMbattery->Size = System::Drawing::Size(123, 13);
			this->lblMbattery->TabIndex = 0;
			this->lblMbattery->Text = L"Motors Battery Voltage : ";
			// 
			// lblSbattery
			// 
			this->lblSbattery->AutoSize = true;
			this->lblSbattery->Enabled = false;
			this->lblSbattery->Location = System::Drawing::Point(12, 62);
			this->lblSbattery->Name = L"lblSbattery";
			this->lblSbattery->Size = System::Drawing::Size(119, 13);
			this->lblSbattery->TabIndex = 1;
			this->lblSbattery->Text = L"Servo Battery Voltage : ";
			// 
			// lblNUCbattery
			// 
			this->lblNUCbattery->AutoSize = true;
			this->lblNUCbattery->Enabled = false;
			this->lblNUCbattery->Location = System::Drawing::Point(12, 83);
			this->lblNUCbattery->Name = L"lblNUCbattery";
			this->lblNUCbattery->Size = System::Drawing::Size(114, 13);
			this->lblNUCbattery->TabIndex = 2;
			this->lblNUCbattery->Text = L"NUC Battery Voltage : ";
			// 
			// lblMbatteryVoltage
			// 
			this->lblMbatteryVoltage->AutoSize = true;
			this->lblMbatteryVoltage->Enabled = false;
			this->lblMbatteryVoltage->Location = System::Drawing::Point(145, 41);
			this->lblMbatteryVoltage->Name = L"lblMbatteryVoltage";
			this->lblMbatteryVoltage->Size = System::Drawing::Size(23, 13);
			this->lblMbatteryVoltage->TabIndex = 3;
			this->lblMbatteryVoltage->Text = L"0 V";
			// 
			// lblSbatteryVoltage
			// 
			this->lblSbatteryVoltage->AutoSize = true;
			this->lblSbatteryVoltage->Enabled = false;
			this->lblSbatteryVoltage->Location = System::Drawing::Point(145, 62);
			this->lblSbatteryVoltage->Name = L"lblSbatteryVoltage";
			this->lblSbatteryVoltage->Size = System::Drawing::Size(23, 13);
			this->lblSbatteryVoltage->TabIndex = 4;
			this->lblSbatteryVoltage->Text = L"0 V";
			// 
			// lblNUCbatteryVoltage
			// 
			this->lblNUCbatteryVoltage->AutoSize = true;
			this->lblNUCbatteryVoltage->Enabled = false;
			this->lblNUCbatteryVoltage->Location = System::Drawing::Point(145, 83);
			this->lblNUCbatteryVoltage->Name = L"lblNUCbatteryVoltage";
			this->lblNUCbatteryVoltage->Size = System::Drawing::Size(23, 13);
			this->lblNUCbatteryVoltage->TabIndex = 5;
			this->lblNUCbatteryVoltage->Text = L"0 V";
			// 
			// lblHumidityPercent
			// 
			this->lblHumidityPercent->AutoSize = true;
			this->lblHumidityPercent->Enabled = false;
			this->lblHumidityPercent->Location = System::Drawing::Point(145, 188);
			this->lblHumidityPercent->Name = L"lblHumidityPercent";
			this->lblHumidityPercent->Size = System::Drawing::Size(24, 13);
			this->lblHumidityPercent->TabIndex = 11;
			this->lblHumidityPercent->Text = L"0 %";
			// 
			// lblTemperatureDegree
			// 
			this->lblTemperatureDegree->AutoSize = true;
			this->lblTemperatureDegree->Enabled = false;
			this->lblTemperatureDegree->Location = System::Drawing::Point(145, 167);
			this->lblTemperatureDegree->Name = L"lblTemperatureDegree";
			this->lblTemperatureDegree->Size = System::Drawing::Size(20, 13);
			this->lblTemperatureDegree->TabIndex = 10;
			this->lblTemperatureDegree->Text = L"0 °";
			// 
			// lblMCbatteryCurrent
			// 
			this->lblMCbatteryCurrent->AutoSize = true;
			this->lblMCbatteryCurrent->Enabled = false;
			this->lblMCbatteryCurrent->Location = System::Drawing::Point(145, 104);
			this->lblMCbatteryCurrent->Name = L"lblMCbatteryCurrent";
			this->lblMCbatteryCurrent->Size = System::Drawing::Size(23, 13);
			this->lblMCbatteryCurrent->TabIndex = 9;
			this->lblMCbatteryCurrent->Text = L"0 A";
			// 
			// lblHumidity
			// 
			this->lblHumidity->AutoSize = true;
			this->lblHumidity->Enabled = false;
			this->lblHumidity->Location = System::Drawing::Point(12, 188);
			this->lblHumidity->Name = L"lblHumidity";
			this->lblHumidity->Size = System::Drawing::Size(53, 13);
			this->lblHumidity->TabIndex = 8;
			this->lblHumidity->Text = L"Humidity :";
			// 
			// lblTemperature
			// 
			this->lblTemperature->AutoSize = true;
			this->lblTemperature->Enabled = false;
			this->lblTemperature->Location = System::Drawing::Point(12, 167);
			this->lblTemperature->Name = L"lblTemperature";
			this->lblTemperature->Size = System::Drawing::Size(76, 13);
			this->lblTemperature->TabIndex = 7;
			this->lblTemperature->Text = L"Temperature : ";
			// 
			// lblMCbattery
			// 
			this->lblMCbattery->AutoSize = true;
			this->lblMCbattery->Enabled = false;
			this->lblMCbattery->Location = System::Drawing::Point(12, 104);
			this->lblMCbattery->Name = L"lblMCbattery";
			this->lblMCbattery->Size = System::Drawing::Size(121, 13);
			this->lblMCbattery->TabIndex = 6;
			this->lblMCbattery->Text = L"Motors Battery Current : ";
			// 
			// picLeft
			// 
			this->picLeft->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picLeft->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picLeft.Image")));
			this->picLeft->Location = System::Drawing::Point(240, 40);
			this->picLeft->Name = L"picLeft";
			this->picLeft->Size = System::Drawing::Size(270, 150);
			this->picLeft->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picLeft->TabIndex = 12;
			this->picLeft->TabStop = false;
			// 
			// picRight
			// 
			this->picRight->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picRight->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picRight.Image")));
			this->picRight->Location = System::Drawing::Point(515, 40);
			this->picRight->Name = L"picRight";
			this->picRight->Size = System::Drawing::Size(270, 150);
			this->picRight->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picRight->TabIndex = 13;
			this->picRight->TabStop = false;
			// 
			// picDisparity
			// 
			this->picDisparity->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picDisparity->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picDisparity.Image")));
			this->picDisparity->Location = System::Drawing::Point(391, 196);
			this->picDisparity->Name = L"picDisparity";
			this->picDisparity->Size = System::Drawing::Size(240, 150);
			this->picDisparity->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picDisparity->TabIndex = 14;
			this->picDisparity->TabStop = false;
			// 
			// chkShowCameras
			// 
			this->chkShowCameras->AutoSize = true;
			this->chkShowCameras->Location = System::Drawing::Point(857, 107);
			this->chkShowCameras->Name = L"chkShowCameras";
			this->chkShowCameras->Size = System::Drawing::Size(97, 17);
			this->chkShowCameras->TabIndex = 4;
			this->chkShowCameras->Text = L"Show Cameras";
			this->chkShowCameras->UseVisualStyleBackColor = true;
			this->chkShowCameras->CheckedChanged += gcnew System::EventHandler(this, &MainForm::chkShowCameras_CheckedChanged);
			// 
			// chkEnableSampling
			// 
			this->chkEnableSampling->AutoSize = true;
			this->chkEnableSampling->Location = System::Drawing::Point(857, 199);
			this->chkEnableSampling->Name = L"chkEnableSampling";
			this->chkEnableSampling->Size = System::Drawing::Size(105, 17);
			this->chkEnableSampling->TabIndex = 8;
			this->chkEnableSampling->Text = L"Enable Sampling";
			this->chkEnableSampling->UseVisualStyleBackColor = true;
			this->chkEnableSampling->CheckedChanged += gcnew System::EventHandler(this, &MainForm::chkEnableSampling_CheckedChanged);
			// 
			// chkUseCalibratio
			// 
			this->chkUseCalibratio->AutoSize = true;
			this->chkUseCalibratio->Location = System::Drawing::Point(857, 176);
			this->chkUseCalibratio->Name = L"chkUseCalibratio";
			this->chkUseCalibratio->Size = System::Drawing::Size(128, 17);
			this->chkUseCalibratio->TabIndex = 7;
			this->chkUseCalibratio->Text = L"Use Calibration Matrix";
			this->chkUseCalibratio->UseVisualStyleBackColor = true;
			this->chkUseCalibratio->CheckedChanged += gcnew System::EventHandler(this, &MainForm::chkUseCalibratio_CheckedChanged);
			// 
			// chkComputeDisparity
			// 
			this->chkComputeDisparity->AutoSize = true;
			this->chkComputeDisparity->Location = System::Drawing::Point(857, 153);
			this->chkComputeDisparity->Name = L"chkComputeDisparity";
			this->chkComputeDisparity->Size = System::Drawing::Size(111, 17);
			this->chkComputeDisparity->TabIndex = 6;
			this->chkComputeDisparity->Text = L"Compute Disparity";
			this->chkComputeDisparity->UseVisualStyleBackColor = true;
			// 
			// chkShowDisparity
			// 
			this->chkShowDisparity->AutoSize = true;
			this->chkShowDisparity->Location = System::Drawing::Point(857, 130);
			this->chkShowDisparity->Name = L"chkShowDisparity";
			this->chkShowDisparity->Size = System::Drawing::Size(96, 17);
			this->chkShowDisparity->TabIndex = 5;
			this->chkShowDisparity->Text = L"Show Disparity";
			this->chkShowDisparity->UseVisualStyleBackColor = true;
			// 
			// btnCameraProperties
			// 
			this->btnCameraProperties->Location = System::Drawing::Point(857, 227);
			this->btnCameraProperties->Name = L"btnCameraProperties";
			this->btnCameraProperties->Size = System::Drawing::Size(129, 23);
			this->btnCameraProperties->TabIndex = 9;
			this->btnCameraProperties->Text = L"Camera Properties";
			this->btnCameraProperties->UseVisualStyleBackColor = true;
			this->btnCameraProperties->Click += gcnew System::EventHandler(this, &MainForm::btnCameraProperties_Click);
			// 
			// btnSnapShot
			// 
			this->btnSnapShot->Location = System::Drawing::Point(857, 279);
			this->btnSnapShot->Name = L"btnSnapShot";
			this->btnSnapShot->Size = System::Drawing::Size(129, 23);
			this->btnSnapShot->TabIndex = 10;
			this->btnSnapShot->Text = L"SnapShot";
			this->btnSnapShot->UseVisualStyleBackColor = true;
			this->btnSnapShot->Click += gcnew System::EventHandler(this, &MainForm::btnSnapShot_Click);
			// 
			// btnStartPathPlanning
			// 
			this->btnStartPathPlanning->Enabled = false;
			this->btnStartPathPlanning->Location = System::Drawing::Point(857, 415);
			this->btnStartPathPlanning->Name = L"btnStartPathPlanning";
			this->btnStartPathPlanning->Size = System::Drawing::Size(129, 23);
			this->btnStartPathPlanning->TabIndex = 14;
			this->btnStartPathPlanning->Text = L"Start Path Planning";
			this->btnStartPathPlanning->UseVisualStyleBackColor = true;
			this->btnStartPathPlanning->Click += gcnew System::EventHandler(this, &MainForm::btnStartPathPlanning_Click);
			// 
			// btnOpenMap
			// 
			this->btnOpenMap->Location = System::Drawing::Point(857, 386);
			this->btnOpenMap->Name = L"btnOpenMap";
			this->btnOpenMap->Size = System::Drawing::Size(129, 23);
			this->btnOpenMap->TabIndex = 13;
			this->btnOpenMap->Text = L"Open Map";
			this->btnOpenMap->UseVisualStyleBackColor = true;
			this->btnOpenMap->Click += gcnew System::EventHandler(this, &MainForm::btnOpenMap_Click);
			// 
			// btnSaveDisparity
			// 
			this->btnSaveDisparity->Location = System::Drawing::Point(857, 337);
			this->btnSaveDisparity->Name = L"btnSaveDisparity";
			this->btnSaveDisparity->Size = System::Drawing::Size(129, 23);
			this->btnSaveDisparity->TabIndex = 12;
			this->btnSaveDisparity->Text = L"Save Disparity";
			this->btnSaveDisparity->UseVisualStyleBackColor = true;
			this->btnSaveDisparity->Click += gcnew System::EventHandler(this, &MainForm::btnSaveDisparity_Click);
			// 
			// btnCaptureVideo
			// 
			this->btnCaptureVideo->Location = System::Drawing::Point(857, 308);
			this->btnCaptureVideo->Name = L"btnCaptureVideo";
			this->btnCaptureVideo->Size = System::Drawing::Size(129, 23);
			this->btnCaptureVideo->TabIndex = 11;
			this->btnCaptureVideo->Text = L"Capture Video";
			this->btnCaptureVideo->UseVisualStyleBackColor = true;
			this->btnCaptureVideo->Click += gcnew System::EventHandler(this, &MainForm::btnCaptureVideo_Click);
			// 
			// btnCalibration
			// 
			this->btnCalibration->Location = System::Drawing::Point(448, 11);
			this->btnCalibration->Name = L"btnCalibration";
			this->btnCalibration->Size = System::Drawing::Size(129, 23);
			this->btnCalibration->TabIndex = 20;
			this->btnCalibration->Text = L"Calibration";
			this->btnCalibration->UseVisualStyleBackColor = true;
			this->btnCalibration->Click += gcnew System::EventHandler(this, &MainForm::btnCalibration_Click);
			// 
			// btnExit
			// 
			this->btnExit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnExit->Location = System::Drawing::Point(798, 626);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(188, 23);
			this->btnExit->TabIndex = 19;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &MainForm::btnExit_Click);
			// 
			// cboSamplingDistance
			// 
			this->cboSamplingDistance->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSamplingDistance->Enabled = false;
			this->cboSamplingDistance->FormattingEnabled = true;
			this->cboSamplingDistance->Items->AddRange(gcnew cli::array< System::Object^  >(20) {L"1", L"2", L"3", L"4", L"5", L"6", L"7", 
				L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20"});
			this->cboSamplingDistance->Location = System::Drawing::Point(901, 472);
			this->cboSamplingDistance->Name = L"cboSamplingDistance";
			this->cboSamplingDistance->Size = System::Drawing::Size(44, 21);
			this->cboSamplingDistance->TabIndex = 15;
			// 
			// lblSamplingDistance
			// 
			this->lblSamplingDistance->AutoSize = true;
			this->lblSamplingDistance->Enabled = false;
			this->lblSamplingDistance->Location = System::Drawing::Point(786, 475);
			this->lblSamplingDistance->Name = L"lblSamplingDistance";
			this->lblSamplingDistance->Size = System::Drawing::Size(101, 13);
			this->lblSamplingDistance->TabIndex = 33;
			this->lblSamplingDistance->Text = L"Sampling Distance :";
			// 
			// lblAvoidanceDistance
			// 
			this->lblAvoidanceDistance->AutoSize = true;
			this->lblAvoidanceDistance->Location = System::Drawing::Point(787, 502);
			this->lblAvoidanceDistance->Name = L"lblAvoidanceDistance";
			this->lblAvoidanceDistance->Size = System::Drawing::Size(109, 13);
			this->lblAvoidanceDistance->TabIndex = 35;
			this->lblAvoidanceDistance->Text = L"Avoidance Distance :";
			// 
			// cboAvoidanceDistance
			// 
			this->cboAvoidanceDistance->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboAvoidanceDistance->FormattingEnabled = true;
			this->cboAvoidanceDistance->Items->AddRange(gcnew cli::array< System::Object^  >(9) {L"1", L"2", L"3", L"4", L"5", L"6", 
				L"7", L"8", L"9"});
			this->cboAvoidanceDistance->Location = System::Drawing::Point(901, 499);
			this->cboAvoidanceDistance->Name = L"cboAvoidanceDistance";
			this->cboAvoidanceDistance->Size = System::Drawing::Size(44, 21);
			this->cboAvoidanceDistance->TabIndex = 16;
			// 
			// picCamerasPositions
			// 
			this->picCamerasPositions->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picCamerasPositions->Enabled = false;
			this->picCamerasPositions->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picCamerasPositions.Image")));
			this->picCamerasPositions->Location = System::Drawing::Point(201, 210);
			this->picCamerasPositions->Name = L"picCamerasPositions";
			this->picCamerasPositions->Size = System::Drawing::Size(151, 125);
			this->picCamerasPositions->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->picCamerasPositions->TabIndex = 36;
			this->picCamerasPositions->TabStop = false;
			// 
			// txtLeftCameraAngle
			// 
			this->txtLeftCameraAngle->AcceptsReturn = true;
			this->txtLeftCameraAngle->BackColor = System::Drawing::SystemColors::Control;
			this->txtLeftCameraAngle->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtLeftCameraAngle->Enabled = false;
			this->txtLeftCameraAngle->Location = System::Drawing::Point(225, 205);
			this->txtLeftCameraAngle->Name = L"txtLeftCameraAngle";
			this->txtLeftCameraAngle->Size = System::Drawing::Size(24, 13);
			this->txtLeftCameraAngle->TabIndex = 21;
			this->txtLeftCameraAngle->Text = L"90";
			this->txtLeftCameraAngle->Enter += gcnew System::EventHandler(this, &MainForm::txtLeftCameraAngle_Enter);
			this->txtLeftCameraAngle->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::txtLeftCameraAngle_KeyPress);
			this->txtLeftCameraAngle->Leave += gcnew System::EventHandler(this, &MainForm::txtLeftCameraAngle_Leave);
			// 
			// txtRightCameraAngle
			// 
			this->txtRightCameraAngle->BackColor = System::Drawing::SystemColors::Control;
			this->txtRightCameraAngle->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtRightCameraAngle->Enabled = false;
			this->txtRightCameraAngle->Location = System::Drawing::Point(309, 205);
			this->txtRightCameraAngle->Name = L"txtRightCameraAngle";
			this->txtRightCameraAngle->Size = System::Drawing::Size(24, 13);
			this->txtRightCameraAngle->TabIndex = 22;
			this->txtRightCameraAngle->Text = L"90";
			this->txtRightCameraAngle->Enter += gcnew System::EventHandler(this, &MainForm::txtRightCameraAngle_Enter);
			this->txtRightCameraAngle->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::txtRightCameraAngle_KeyPress);
			this->txtRightCameraAngle->Leave += gcnew System::EventHandler(this, &MainForm::txtRightCameraAngle_Leave);
			// 
			// txtCameraUpperTiltAngle
			// 
			this->txtCameraUpperTiltAngle->BackColor = System::Drawing::SystemColors::Control;
			this->txtCameraUpperTiltAngle->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtCameraUpperTiltAngle->Enabled = false;
			this->txtCameraUpperTiltAngle->Location = System::Drawing::Point(107, 332);
			this->txtCameraUpperTiltAngle->Name = L"txtCameraUpperTiltAngle";
			this->txtCameraUpperTiltAngle->Size = System::Drawing::Size(24, 13);
			this->txtCameraUpperTiltAngle->TabIndex = 23;
			this->txtCameraUpperTiltAngle->Text = L"90";
			this->txtCameraUpperTiltAngle->Enter += gcnew System::EventHandler(this, &MainForm::txtCameraUpperTiltAngle_Enter);
			this->txtCameraUpperTiltAngle->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::txtCameraTiltAngle_KeyPress);
			this->txtCameraUpperTiltAngle->Leave += gcnew System::EventHandler(this, &MainForm::txtCameraUpperTiltAngle_Leave);
			// 
			// txtCameraPanAngle
			// 
			this->txtCameraPanAngle->BackColor = System::Drawing::SystemColors::Control;
			this->txtCameraPanAngle->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtCameraPanAngle->Enabled = false;
			this->txtCameraPanAngle->Location = System::Drawing::Point(30, 446);
			this->txtCameraPanAngle->Name = L"txtCameraPanAngle";
			this->txtCameraPanAngle->Size = System::Drawing::Size(24, 13);
			this->txtCameraPanAngle->TabIndex = 26;
			this->txtCameraPanAngle->Text = L"90";
			this->txtCameraPanAngle->Enter += gcnew System::EventHandler(this, &MainForm::txtCameraPanAngle_Enter);
			this->txtCameraPanAngle->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::txtCameraPanAngle_KeyPress);
			this->txtCameraPanAngle->Leave += gcnew System::EventHandler(this, &MainForm::txtCameraPanAngle_Leave);
			// 
			// picGridMap
			// 
			this->picGridMap->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picGridMap->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picGridMap->Cursor = System::Windows::Forms::Cursors::Default;
			this->picGridMap->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picGridMap.Image")));
			this->picGridMap->Location = System::Drawing::Point(239, 352);
			this->picGridMap->Name = L"picGridMap";
			this->picGridMap->Size = System::Drawing::Size(530, 300);
			this->picGridMap->TabIndex = 41;
			this->picGridMap->TabStop = false;
			this->picGridMap->Click += gcnew System::EventHandler(this, &MainForm::picGridMap_Click);
			// 
			// lblSystemMessages
			// 
			this->lblSystemMessages->AutoSize = true;
			this->lblSystemMessages->Location = System::Drawing::Point(12, 490);
			this->lblSystemMessages->Name = L"lblSystemMessages";
			this->lblSystemMessages->Size = System::Drawing::Size(98, 13);
			this->lblSystemMessages->TabIndex = 42;
			this->lblSystemMessages->Text = L"System Messages :";
			// 
			// lblMessages
			// 
			this->lblMessages->AutoEllipsis = true;
			this->lblMessages->AutoSize = true;
			this->lblMessages->Location = System::Drawing::Point(12, 512);
			this->lblMessages->Name = L"lblMessages";
			this->lblMessages->Size = System::Drawing::Size(64, 13);
			this->lblMessages->TabIndex = 43;
			this->lblMessages->Text = L"Initializing ...";
			// 
			// lblLeftMotorEncoder
			// 
			this->lblLeftMotorEncoder->AutoSize = true;
			this->lblLeftMotorEncoder->Enabled = false;
			this->lblLeftMotorEncoder->Location = System::Drawing::Point(12, 209);
			this->lblLeftMotorEncoder->Name = L"lblLeftMotorEncoder";
			this->lblLeftMotorEncoder->Size = System::Drawing::Size(104, 13);
			this->lblLeftMotorEncoder->TabIndex = 44;
			this->lblLeftMotorEncoder->Text = L"Left Motor Encoder :";
			// 
			// lblRightMotorEncoder
			// 
			this->lblRightMotorEncoder->AutoSize = true;
			this->lblRightMotorEncoder->Enabled = false;
			this->lblRightMotorEncoder->Location = System::Drawing::Point(12, 230);
			this->lblRightMotorEncoder->Name = L"lblRightMotorEncoder";
			this->lblRightMotorEncoder->Size = System::Drawing::Size(111, 13);
			this->lblRightMotorEncoder->TabIndex = 45;
			this->lblRightMotorEncoder->Text = L"Right Motor Encoder :";
			// 
			// lblRightMotorEncoderValue
			// 
			this->lblRightMotorEncoderValue->AutoSize = true;
			this->lblRightMotorEncoderValue->Enabled = false;
			this->lblRightMotorEncoderValue->Location = System::Drawing::Point(145, 230);
			this->lblRightMotorEncoderValue->Name = L"lblRightMotorEncoderValue";
			this->lblRightMotorEncoderValue->Size = System::Drawing::Size(13, 13);
			this->lblRightMotorEncoderValue->TabIndex = 46;
			this->lblRightMotorEncoderValue->Text = L"0";
			// 
			// lblLeftMotorEncoderValue
			// 
			this->lblLeftMotorEncoderValue->AutoSize = true;
			this->lblLeftMotorEncoderValue->Enabled = false;
			this->lblLeftMotorEncoderValue->Location = System::Drawing::Point(145, 209);
			this->lblLeftMotorEncoderValue->Name = L"lblLeftMotorEncoderValue";
			this->lblLeftMotorEncoderValue->Size = System::Drawing::Size(13, 13);
			this->lblLeftMotorEncoderValue->TabIndex = 47;
			this->lblLeftMotorEncoderValue->Text = L"0";
			// 
			// lblRobotSpeed
			// 
			this->lblRobotSpeed->AutoSize = true;
			this->lblRobotSpeed->Location = System::Drawing::Point(787, 529);
			this->lblRobotSpeed->Name = L"lblRobotSpeed";
			this->lblRobotSpeed->Size = System::Drawing::Size(76, 13);
			this->lblRobotSpeed->TabIndex = 49;
			this->lblRobotSpeed->Text = L"Robot Speed :";
			// 
			// cboRobotSpeed
			// 
			this->cboRobotSpeed->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboRobotSpeed->FormattingEnabled = true;
			this->cboRobotSpeed->Items->AddRange(gcnew cli::array< System::Object^  >(10) {L"10", L"15", L"20", L"25", L"35", L"40", L"45", 
				L"50", L"55", L"60"});
			this->cboRobotSpeed->Location = System::Drawing::Point(901, 526);
			this->cboRobotSpeed->Name = L"cboRobotSpeed";
			this->cboRobotSpeed->Size = System::Drawing::Size(44, 21);
			this->cboRobotSpeed->TabIndex = 17;
			// 
			// btnRobotSelfTest
			// 
			this->btnRobotSelfTest->Location = System::Drawing::Point(856, 582);
			this->btnRobotSelfTest->Name = L"btnRobotSelfTest";
			this->btnRobotSelfTest->Size = System::Drawing::Size(129, 23);
			this->btnRobotSelfTest->TabIndex = 18;
			this->btnRobotSelfTest->Text = L"Robot Self Test";
			this->btnRobotSelfTest->UseVisualStyleBackColor = true;
			this->btnRobotSelfTest->Click += gcnew System::EventHandler(this, &MainForm::btnRobotSelfTest_Click);
			// 
			// btnRobotTurnOn
			// 
			this->btnRobotTurnOn->Location = System::Drawing::Point(857, 12);
			this->btnRobotTurnOn->Name = L"btnRobotTurnOn";
			this->btnRobotTurnOn->Size = System::Drawing::Size(129, 23);
			this->btnRobotTurnOn->TabIndex = 1;
			this->btnRobotTurnOn->Text = L"Robot Turn On";
			this->btnRobotTurnOn->UseVisualStyleBackColor = true;
			this->btnRobotTurnOn->Click += gcnew System::EventHandler(this, &MainForm::btnRobotTurnOn_Click);
			// 
			// btnRobotTurnOff
			// 
			this->btnRobotTurnOff->Enabled = false;
			this->btnRobotTurnOff->Location = System::Drawing::Point(856, 41);
			this->btnRobotTurnOff->Name = L"btnRobotTurnOff";
			this->btnRobotTurnOff->Size = System::Drawing::Size(129, 23);
			this->btnRobotTurnOff->TabIndex = 2;
			this->btnRobotTurnOff->Text = L"Robot Turn Off";
			this->btnRobotTurnOff->UseVisualStyleBackColor = true;
			this->btnRobotTurnOff->Click += gcnew System::EventHandler(this, &MainForm::btnRobotTurnOff_Click);
			// 
			// tmrMainLoop
			// 
			this->tmrMainLoop->Interval = 40;
			this->tmrMainLoop->Tick += gcnew System::EventHandler(this, &MainForm::tmrMainLoop_Tick);
			// 
			// tmrSensorRefresh
			// 
			this->tmrSensorRefresh->Interval = 1000;
			this->tmrSensorRefresh->Tick += gcnew System::EventHandler(this, &MainForm::tmrSensorRefresh_Tick);
			// 
			// lblBlock1
			// 
			this->lblBlock1->AutoSize = true;
			this->lblBlock1->Enabled = false;
			this->lblBlock1->Location = System::Drawing::Point(951, 475);
			this->lblBlock1->Name = L"lblBlock1";
			this->lblBlock1->Size = System::Drawing::Size(45, 13);
			this->lblBlock1->TabIndex = 53;
			this->lblBlock1->Text = L"Block(s)";
			// 
			// lblBlock2
			// 
			this->lblBlock2->AutoSize = true;
			this->lblBlock2->Location = System::Drawing::Point(951, 502);
			this->lblBlock2->Name = L"lblBlock2";
			this->lblBlock2->Size = System::Drawing::Size(45, 13);
			this->lblBlock2->TabIndex = 54;
			this->lblBlock2->Text = L"Block(s)";
			// 
			// btnPortConfiguration
			// 
			this->btnPortConfiguration->Location = System::Drawing::Point(857, 70);
			this->btnPortConfiguration->Name = L"btnPortConfiguration";
			this->btnPortConfiguration->Size = System::Drawing::Size(129, 23);
			this->btnPortConfiguration->TabIndex = 3;
			this->btnPortConfiguration->Text = L"Port &Configuration";
			this->btnPortConfiguration->UseVisualStyleBackColor = true;
			this->btnPortConfiguration->Click += gcnew System::EventHandler(this, &MainForm::btnPortConfiguration_Click);
			// 
			// openMapDialog
			// 
			this->openMapDialog->FileName = L"openMapDialog";
			// 
			// btnSave
			// 
			this->btnSave->Enabled = false;
			this->btnSave->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnSave.Image")));
			this->btnSave->Location = System::Drawing::Point(16, 307);
			this->btnSave->Margin = System::Windows::Forms::Padding(0);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(24, 24);
			this->btnSave->TabIndex = 27;
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &MainForm::btnSave_Click);
			// 
			// btnSaveSample
			// 
			this->btnSaveSample->Enabled = false;
			this->btnSaveSample->Location = System::Drawing::Point(448, 352);
			this->btnSaveSample->Name = L"btnSaveSample";
			this->btnSaveSample->Size = System::Drawing::Size(129, 23);
			this->btnSaveSample->TabIndex = 55;
			this->btnSaveSample->Text = L"Save Sample";
			this->btnSaveSample->UseVisualStyleBackColor = true;
			this->btnSaveSample->Visible = false;
			this->btnSaveSample->Click += gcnew System::EventHandler(this, &MainForm::btnSaveSample_Click);
			// 
			// tmrCalibrationLoop
			// 
			this->tmrCalibrationLoop->Interval = 40;
			this->tmrCalibrationLoop->Tick += gcnew System::EventHandler(this, &MainForm::tmrCalibrationLoop_Tick);
			// 
			// lblFPSValue
			// 
			this->lblFPSValue->AutoSize = true;
			this->lblFPSValue->Location = System::Drawing::Point(145, 251);
			this->lblFPSValue->Name = L"lblFPSValue";
			this->lblFPSValue->Size = System::Drawing::Size(13, 13);
			this->lblFPSValue->TabIndex = 57;
			this->lblFPSValue->Text = L"0";
			// 
			// lblFPS
			// 
			this->lblFPS->AutoSize = true;
			this->lblFPS->Location = System::Drawing::Point(12, 251);
			this->lblFPS->Name = L"lblFPS";
			this->lblFPS->Size = System::Drawing::Size(79, 13);
			this->lblFPS->TabIndex = 56;
			this->lblFPS->Text = L"Disparity FPS  :";
			// 
			// picCompass
			// 
			this->picCompass->InitialImage = nullptr;
			this->picCompass->Location = System::Drawing::Point(776, 352);
			this->picCompass->Name = L"picCompass";
			this->picCompass->Size = System::Drawing::Size(64, 76);
			this->picCompass->TabIndex = 58;
			this->picCompass->TabStop = false;
			this->picCompass->Click += gcnew System::EventHandler(this, &MainForm::picCompass_Click);
			// 
			// tmrPathPlanning
			// 
			this->tmrPathPlanning->Interval = 40;
			this->tmrPathPlanning->Tick += gcnew System::EventHandler(this, &MainForm::tmrPathPlanning_Tick);
			// 
			// picIMUPicture
			// 
			this->picIMUPicture->Enabled = false;
			this->picIMUPicture->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picIMUPicture.Image")));
			this->picIMUPicture->Location = System::Drawing::Point(675, 218);
			this->picIMUPicture->Name = L"picIMUPicture";
			this->picIMUPicture->Size = System::Drawing::Size(165, 104);
			this->picIMUPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picIMUPicture->TabIndex = 59;
			this->picIMUPicture->TabStop = false;
			// 
			// lblYaw
			// 
			this->lblYaw->AutoSize = true;
			this->lblYaw->Enabled = false;
			this->lblYaw->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblYaw->Location = System::Drawing::Point(693, 210);
			this->lblYaw->Name = L"lblYaw";
			this->lblYaw->Size = System::Drawing::Size(28, 13);
			this->lblYaw->TabIndex = 60;
			this->lblYaw->Text = L"Yaw";
			// 
			// lblPitch
			// 
			this->lblPitch->AutoSize = true;
			this->lblPitch->Enabled = false;
			this->lblPitch->ForeColor = System::Drawing::Color::Blue;
			this->lblPitch->Location = System::Drawing::Point(757, 325);
			this->lblPitch->Name = L"lblPitch";
			this->lblPitch->Size = System::Drawing::Size(31, 13);
			this->lblPitch->TabIndex = 61;
			this->lblPitch->Text = L"Pitch";
			// 
			// lblRoll
			// 
			this->lblRoll->AutoSize = true;
			this->lblRoll->Enabled = false;
			this->lblRoll->ForeColor = System::Drawing::Color::DarkRed;
			this->lblRoll->Location = System::Drawing::Point(662, 289);
			this->lblRoll->Name = L"lblRoll";
			this->lblRoll->Size = System::Drawing::Size(25, 13);
			this->lblRoll->TabIndex = 62;
			this->lblRoll->Text = L"Roll";
			// 
			// lblRealFPSValue
			// 
			this->lblRealFPSValue->AutoSize = true;
			this->lblRealFPSValue->Location = System::Drawing::Point(145, 272);
			this->lblRealFPSValue->Name = L"lblRealFPSValue";
			this->lblRealFPSValue->Size = System::Drawing::Size(13, 13);
			this->lblRealFPSValue->TabIndex = 64;
			this->lblRealFPSValue->Text = L"0";
			// 
			// lblRealFPS
			// 
			this->lblRealFPS->AutoSize = true;
			this->lblRealFPS->Location = System::Drawing::Point(12, 272);
			this->lblRealFPS->Name = L"lblRealFPS";
			this->lblRealFPS->Size = System::Drawing::Size(75, 13);
			this->lblRealFPS->TabIndex = 63;
			this->lblRealFPS->Text = L"Program FPS :";
			// 
			// picArmPositions
			// 
			this->picArmPositions->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picArmPositions->Enabled = false;
			this->picArmPositions->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picArmPositions.Image")));
			this->picArmPositions->Location = System::Drawing::Point(16, 307);
			this->picArmPositions->Name = L"picArmPositions";
			this->picArmPositions->Size = System::Drawing::Size(142, 171);
			this->picArmPositions->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->picArmPositions->TabIndex = 65;
			this->picArmPositions->TabStop = false;
			// 
			// txtCameraBottomTiltAngle
			// 
			this->txtCameraBottomTiltAngle->BackColor = System::Drawing::SystemColors::Control;
			this->txtCameraBottomTiltAngle->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtCameraBottomTiltAngle->Enabled = false;
			this->txtCameraBottomTiltAngle->Location = System::Drawing::Point(141, 430);
			this->txtCameraBottomTiltAngle->Name = L"txtCameraBottomTiltAngle";
			this->txtCameraBottomTiltAngle->Size = System::Drawing::Size(24, 13);
			this->txtCameraBottomTiltAngle->TabIndex = 25;
			this->txtCameraBottomTiltAngle->Text = L"90";
			this->txtCameraBottomTiltAngle->Enter += gcnew System::EventHandler(this, &MainForm::txtCameraBottomTiltAngle_Enter);
			this->txtCameraBottomTiltAngle->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::txtCameraBottomTiltAngle_KeyPress);
			this->txtCameraBottomTiltAngle->Leave += gcnew System::EventHandler(this, &MainForm::txtCameraBottomTiltAngle_Leave);
			// 
			// txtCameraMiddleTiltAngle
			// 
			this->txtCameraMiddleTiltAngle->BackColor = System::Drawing::SystemColors::Control;
			this->txtCameraMiddleTiltAngle->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtCameraMiddleTiltAngle->Enabled = false;
			this->txtCameraMiddleTiltAngle->Location = System::Drawing::Point(30, 362);
			this->txtCameraMiddleTiltAngle->Name = L"txtCameraMiddleTiltAngle";
			this->txtCameraMiddleTiltAngle->Size = System::Drawing::Size(24, 13);
			this->txtCameraMiddleTiltAngle->TabIndex = 24;
			this->txtCameraMiddleTiltAngle->Text = L"90";
			this->txtCameraMiddleTiltAngle->Enter += gcnew System::EventHandler(this, &MainForm::txtCameraMiddleTiltAngle_Enter);
			this->txtCameraMiddleTiltAngle->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::txtCameraMiddleTiltAngle_KeyPress);
			this->txtCameraMiddleTiltAngle->Leave += gcnew System::EventHandler(this, &MainForm::txtCameraMiddleTiltAngle_Leave);
			// 
			// btnPosition1
			// 
			this->btnPosition1->Appearance = System::Windows::Forms::Appearance::Button;
			this->btnPosition1->AutoSize = true;
			this->btnPosition1->Checked = true;
			this->btnPosition1->Enabled = false;
			this->btnPosition1->Location = System::Drawing::Point(201, 352);
			this->btnPosition1->Name = L"btnPosition1";
			this->btnPosition1->Size = System::Drawing::Size(23, 23);
			this->btnPosition1->TabIndex = 28;
			this->btnPosition1->TabStop = true;
			this->btnPosition1->Text = L"1";
			this->btnPosition1->UseVisualStyleBackColor = true;
			this->btnPosition1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::btnPosition1_CheckedChanged);
			// 
			// btnPosition2
			// 
			this->btnPosition2->Appearance = System::Windows::Forms::Appearance::Button;
			this->btnPosition2->AutoSize = true;
			this->btnPosition2->Enabled = false;
			this->btnPosition2->Location = System::Drawing::Point(201, 381);
			this->btnPosition2->Name = L"btnPosition2";
			this->btnPosition2->Size = System::Drawing::Size(23, 23);
			this->btnPosition2->TabIndex = 29;
			this->btnPosition2->Text = L"2";
			this->btnPosition2->UseVisualStyleBackColor = true;
			this->btnPosition2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::btnPosition2_CheckedChanged);
			// 
			// btnPosition4
			// 
			this->btnPosition4->Appearance = System::Windows::Forms::Appearance::Button;
			this->btnPosition4->AutoSize = true;
			this->btnPosition4->Enabled = false;
			this->btnPosition4->Location = System::Drawing::Point(201, 439);
			this->btnPosition4->Name = L"btnPosition4";
			this->btnPosition4->Size = System::Drawing::Size(23, 23);
			this->btnPosition4->TabIndex = 31;
			this->btnPosition4->Text = L"4";
			this->btnPosition4->UseVisualStyleBackColor = true;
			this->btnPosition4->CheckedChanged += gcnew System::EventHandler(this, &MainForm::btnPosition4_CheckedChanged);
			// 
			// btnPosition3
			// 
			this->btnPosition3->Appearance = System::Windows::Forms::Appearance::Button;
			this->btnPosition3->AutoSize = true;
			this->btnPosition3->Enabled = false;
			this->btnPosition3->Location = System::Drawing::Point(201, 410);
			this->btnPosition3->Name = L"btnPosition3";
			this->btnPosition3->Size = System::Drawing::Size(23, 23);
			this->btnPosition3->TabIndex = 30;
			this->btnPosition3->Text = L"3";
			this->btnPosition3->UseVisualStyleBackColor = true;
			this->btnPosition3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::btnPosition3_CheckedChanged);
			// 
			// lblSCbatteryCurrent
			// 
			this->lblSCbatteryCurrent->AutoSize = true;
			this->lblSCbatteryCurrent->Enabled = false;
			this->lblSCbatteryCurrent->Location = System::Drawing::Point(145, 125);
			this->lblSCbatteryCurrent->Name = L"lblSCbatteryCurrent";
			this->lblSCbatteryCurrent->Size = System::Drawing::Size(23, 13);
			this->lblSCbatteryCurrent->TabIndex = 67;
			this->lblSCbatteryCurrent->Text = L"0 A";
			// 
			// lblSCbattery
			// 
			this->lblSCbattery->AutoSize = true;
			this->lblSCbattery->Enabled = false;
			this->lblSCbattery->Location = System::Drawing::Point(12, 125);
			this->lblSCbattery->Name = L"lblSCbattery";
			this->lblSCbattery->Size = System::Drawing::Size(117, 13);
			this->lblSCbattery->TabIndex = 66;
			this->lblSCbattery->Text = L"Servo Battery Current : ";
			// 
			// lblNUCCbatteryCurrent
			// 
			this->lblNUCCbatteryCurrent->AutoSize = true;
			this->lblNUCCbatteryCurrent->Enabled = false;
			this->lblNUCCbatteryCurrent->Location = System::Drawing::Point(145, 146);
			this->lblNUCCbatteryCurrent->Name = L"lblNUCCbatteryCurrent";
			this->lblNUCCbatteryCurrent->Size = System::Drawing::Size(23, 13);
			this->lblNUCCbatteryCurrent->TabIndex = 69;
			this->lblNUCCbatteryCurrent->Text = L"0 A";
			// 
			// lblNUCCbattery
			// 
			this->lblNUCCbattery->AutoSize = true;
			this->lblNUCCbattery->Enabled = false;
			this->lblNUCCbattery->Location = System::Drawing::Point(12, 146);
			this->lblNUCCbattery->Name = L"lblNUCCbattery";
			this->lblNUCCbattery->Size = System::Drawing::Size(112, 13);
			this->lblNUCCbattery->TabIndex = 68;
			this->lblNUCCbattery->Text = L"NUC Battery Current : ";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 661);
			this->Controls->Add(this->lblNUCCbatteryCurrent);
			this->Controls->Add(this->lblNUCCbattery);
			this->Controls->Add(this->lblSCbatteryCurrent);
			this->Controls->Add(this->lblSCbattery);
			this->Controls->Add(this->btnPosition4);
			this->Controls->Add(this->btnPosition3);
			this->Controls->Add(this->btnPosition2);
			this->Controls->Add(this->btnPosition1);
			this->Controls->Add(this->txtCameraMiddleTiltAngle);
			this->Controls->Add(this->txtCameraBottomTiltAngle);
			this->Controls->Add(this->lblRealFPSValue);
			this->Controls->Add(this->lblRealFPS);
			this->Controls->Add(this->lblRoll);
			this->Controls->Add(this->lblPitch);
			this->Controls->Add(this->lblYaw);
			this->Controls->Add(this->picIMUPicture);
			this->Controls->Add(this->picCompass);
			this->Controls->Add(this->lblFPSValue);
			this->Controls->Add(this->lblFPS);
			this->Controls->Add(this->btnSaveSample);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->btnPortConfiguration);
			this->Controls->Add(this->lblBlock2);
			this->Controls->Add(this->lblBlock1);
			this->Controls->Add(this->btnRobotTurnOff);
			this->Controls->Add(this->btnRobotTurnOn);
			this->Controls->Add(this->btnRobotSelfTest);
			this->Controls->Add(this->lblRobotSpeed);
			this->Controls->Add(this->cboRobotSpeed);
			this->Controls->Add(this->lblLeftMotorEncoderValue);
			this->Controls->Add(this->lblRightMotorEncoderValue);
			this->Controls->Add(this->lblRightMotorEncoder);
			this->Controls->Add(this->lblLeftMotorEncoder);
			this->Controls->Add(this->lblMessages);
			this->Controls->Add(this->lblSystemMessages);
			this->Controls->Add(this->picGridMap);
			this->Controls->Add(this->txtCameraPanAngle);
			this->Controls->Add(this->txtCameraUpperTiltAngle);
			this->Controls->Add(this->txtRightCameraAngle);
			this->Controls->Add(this->txtLeftCameraAngle);
			this->Controls->Add(this->picCamerasPositions);
			this->Controls->Add(this->lblAvoidanceDistance);
			this->Controls->Add(this->cboAvoidanceDistance);
			this->Controls->Add(this->lblSamplingDistance);
			this->Controls->Add(this->cboSamplingDistance);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnCalibration);
			this->Controls->Add(this->btnCaptureVideo);
			this->Controls->Add(this->btnSaveDisparity);
			this->Controls->Add(this->btnOpenMap);
			this->Controls->Add(this->btnStartPathPlanning);
			this->Controls->Add(this->btnSnapShot);
			this->Controls->Add(this->btnCameraProperties);
			this->Controls->Add(this->chkShowDisparity);
			this->Controls->Add(this->chkComputeDisparity);
			this->Controls->Add(this->chkUseCalibratio);
			this->Controls->Add(this->chkEnableSampling);
			this->Controls->Add(this->chkShowCameras);
			this->Controls->Add(this->picDisparity);
			this->Controls->Add(this->picRight);
			this->Controls->Add(this->picLeft);
			this->Controls->Add(this->lblHumidityPercent);
			this->Controls->Add(this->lblTemperatureDegree);
			this->Controls->Add(this->lblMCbatteryCurrent);
			this->Controls->Add(this->lblHumidity);
			this->Controls->Add(this->lblTemperature);
			this->Controls->Add(this->lblMCbattery);
			this->Controls->Add(this->lblNUCbatteryVoltage);
			this->Controls->Add(this->lblSbatteryVoltage);
			this->Controls->Add(this->lblMbatteryVoltage);
			this->Controls->Add(this->lblNUCbattery);
			this->Controls->Add(this->lblSbattery);
			this->Controls->Add(this->lblMbattery);
			this->Controls->Add(this->picArmPositions);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Robot Control Panel";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picLeft))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picRight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picDisparity))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picCamerasPositions))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picGridMap))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picCompass))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picIMUPicture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picArmPositions))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		//************************************
		void InitializeCompassImages(void){
			Reflection::Assembly^ pxAssembly = Reflection::Assembly::GetExecutingAssembly();
			Resources::ResourceManager^ resources  = gcnew Resources::ResourceManager("RobotVisionWindows.ImageResource",pxAssembly);
			imgCompassN  = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Compass_N")));
			imgCompassS  = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Compass_S")));
			imgCompassW  = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Compass_W")));
			imgCompassE  = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Compass_E")));
			imgCompassNE = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Compass_NE")));
			imgCompassNW = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Compass_NW")));
			imgCompassSE = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Compass_SE")));
			imgCompassSW = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Compass_SW")));
		}
		//************************************
		System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
			ProgramLog::program_log_open();
			ProgramLog::write_log("Application Started");
			RobotConfigFilePath = "RobotConfig.txt";
			//stereovision.Initialize(RobotConfigFilePath);
			RobotIsMovingToNextPoint = false;
			RobotIsTurningToNextDirection = false;
			watch2.Start();
			IMUValues.first = 0;
			IMUValues.second.first = 0;
			IMUValues.second.second = 0;
			//tmrMainLoop->Enabled = true;
			FirstRun=true;
		}
		//************************************
		System::Void tmrMainLoop_Tick(System::Object^  sender, System::EventArgs^  e) {

			watch1.Restart();

			stereovision.CaptureFramFromCAM();

#pragma omp parallel sections  // divides the team into sections
			{

#pragma omp section
				{
					if(stereovision.IsRightCameraAvaiable()){
						if(chkShowCameras->Checked)	DrawCVImage(picRight,stereovision.getCamImageRight());}
					//else stereovision.InitializeCameras();
				}
#pragma omp section
				{
					if(stereovision.IsLeftCameraAvaiable()){
						if(stereovision.getVideoCaptureStatus()) stereovision.VideoCaptureContinue();
						if(chkShowCameras->Checked) DrawCVImage(picLeft,stereovision.getCamImageLeft());}
					//else stereovision.InitializeCameras();
				}
#pragma omp section
				{
					if(stereovision.IsRightCameraAvaiable() && stereovision.IsLeftCameraAvaiable() && chkComputeDisparity->Checked){
						if(chkUseCalibratio->Checked)stereovision.UseCalibrationMatrix();
						stereovision.DisparityMapCalculation();
					}
				}
#pragma omp section
				{
					if(!stereovision.getDisparityMap3Channel().empty() && chkShowDisparity->Checked){
						DrawCVImage(picDisparity,stereovision.getDisparityMap3Channel());
					}
				}

			}

			watch1.Stop();
			double watch1time = 1 / double(watch1.ElapsedMilliseconds) * 1000;
			lblFPSValue->Text = watch1time.ToString("N2");
			watch2.Stop();
			double watch2time = 1 / double(watch2.ElapsedMilliseconds) * 1000;
			lblRealFPSValue->Text = watch2time.ToString("N2");
			watch2.Restart();

		}
		//************************************
		System::Void DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& colorImage)
		{
			System::Drawing::Graphics^ graphics = control->CreateGraphics();
			System::IntPtr ptr(colorImage.ptr());
			try{
				System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colorImage.cols,colorImage.rows,(int)colorImage.step,System::Drawing::Imaging::PixelFormat::Format24bppRgb,ptr);
				System::Drawing::RectangleF rect(0,0,(float)control->Width,(float)control->Height);
				graphics->DrawImage(b,rect);}
			catch(...){}
		}
		//************************************
		System::Void chkUseCalibratio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {if(chkUseCalibratio->Checked)stereovision.LoadCalibrationMatrix();}
		//************************************
		System::Void btnSnapShot_Click(System::Object^  sender, System::EventArgs^  e) {stereovision.SnapShot();}
		//************************************
		System::Void btnSaveDisparity_Click(System::Object^  sender, System::EventArgs^  e) {
			if(stereovision.IsRightCameraAvaiable() && stereovision.IsLeftCameraAvaiable() && chkComputeDisparity->Checked)
				stereovision.SaveDisparity();}
		//************************************
		System::Void btnCaptureVideo_Click(System::Object^  sender, System::EventArgs^  e) {
			if(stereovision.IsLeftCameraAvaiable()){
				if(stereovision.getVideoCaptureStatus()){
					stereovision.VideoCaptureStop();
					btnCaptureVideo->Text = "Capture &Video";
				}
				else if(stereovision.VideoCaptureStart()) btnCaptureVideo->Text = "Stop Cap&ture";}
		}
		//************************************
		System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
			tmrMainLoop->Enabled = false;
			tmrSensorRefresh->Enabled = false;
			Comhandler.TurnOffMotors();
			Comhandler.TurnOffServos();
			Comhandler.ResetEncodersPositions();
			Comhandler.CloseSensorsPort();
			Comhandler.CloseMotorsPort();
			calibration.~calibration();
			stereovision.~StereoVision();
			simulator.~Simulator();
			ProgramLog::write_log("Application Closed by User");
			ProgramLog::program_log_close();
			this->Close();
			Application::Exit();
		}
		//************************************
		System::Void btnRobotTurnOn_Click(System::Object^  sender, System::EventArgs^  e) {
			Confs.Initialize(RobotConfigFilePath);
			Confs.LoadConfigs();
			int PositionNumber = ArmPosition();
			txtLeftCameraAngle->Text = Confs.LeftCameraAngle.ToString();
			txtRightCameraAngle->Text = Confs.RightCameraAngle.ToString();
			txtCameraUpperTiltAngle->Text = Confs.CamerasUpperTiltAngle[PositionNumber].ToString();
			txtCameraMiddleTiltAngle->Text = Confs.CamerasMiddleTiltAngle[PositionNumber].ToString();
			txtCameraBottomTiltAngle->Text = Confs.CamerasBottomTiltAngle[PositionNumber].ToString();
			txtCameraPanAngle->Text = Confs.CamerasPanAngle[PositionNumber].ToString();
			cboSamplingDistance->SelectedItem = Confs.SamplingDistance.ToString();
			cboAvoidanceDistance->SelectedItem = Confs.AvoidanceDistance.ToString();
			cboRobotSpeed->SelectedItem = Confs.RobotSpeed.ToString();
			Comhandler.InitializeMotors(Confs.MotorPort,Confs.MotorBaudRate);
			Comhandler.InitializeSensors(Confs.SensorPort,Confs.SensorBaudRate);
			Comhandler.InitializeIMU(Confs.IMUPort,Confs.IMUBaudRate);
			RobotoTurnOnProcedure();
		}
		//************************************
		void RobotoTurnOnProcedure(void){

			if(Comhandler.MotorsPortIsOpen()) {
				btnRobotTurnOff->Enabled = true;
				btnRobotTurnOn->Enabled = false;
				btnPortConfiguration->Enabled = false;
				btnSave->Enabled = true;
				Comhandler.TurnOnMotors();Sleep(3000);
				Comhandler.TurnOnServos();Sleep(3000);
				int PositionNumber = ArmPosition();
				Comhandler.TurnLeftCameraServo(Confs.LeftCameraAngle,Confs.ServoSpeed);Sleep(4000);
				Comhandler.TurnRightCameraServo(Confs.RightCameraAngle,Confs.ServoSpeed);Sleep(4000);
				Comhandler.TurnUpperTiltServo(Confs.CamerasUpperTiltAngle[PositionNumber],Confs.ServoSpeed);Sleep(4000);
				Comhandler.TurnMiddleTiltServo(Confs.CamerasMiddleTiltAngle[PositionNumber],Confs.ServoSpeed);Sleep(4000);
				Comhandler.TurnBottomTiltServo(Confs.CamerasBottomTiltAngle[PositionNumber],Confs.ServoSpeed);Sleep(4000);
				Comhandler.TurnPanServo(Confs.CamerasPanAngle[PositionNumber],Confs.ServoSpeed);
				txtCameraPanAngle->Enabled = true;
				txtCameraUpperTiltAngle->Enabled = true;
				txtCameraMiddleTiltAngle->Enabled = true;
				txtCameraBottomTiltAngle->Enabled = true;
				txtLeftCameraAngle->Enabled = true;
				txtRightCameraAngle->Enabled = true;
				btnPosition1->Enabled = true;
				btnPosition2->Enabled = true;
				btnPosition3->Enabled = true;
				btnPosition4->Enabled = true;
			}			

			if(Comhandler.SensorsPortIsOpen()) {
				Comhandler.TurnOnMotors();
				btnRobotTurnOff->Enabled = true;
				btnRobotTurnOn->Enabled = false;
				btnPortConfiguration->Enabled = false;

				lblMbattery->Enabled = true;
				lblSbattery->Enabled = true;
				lblNUCbattery->Enabled = true;
				lblMbatteryVoltage->Enabled = true;
				lblSbatteryVoltage->Enabled = true;
				lblNUCbatteryVoltage->Enabled = true;
				lblHumidityPercent->Enabled = true;
				lblTemperatureDegree->Enabled = true;
				lblMCbatteryCurrent->Enabled = true;
				lblHumidity->Enabled = true;
				lblTemperature->Enabled = true;
				lblMCbattery->Enabled = true;
				lblLeftMotorEncoder->Enabled = true;
				lblRightMotorEncoder->Enabled = true;
				lblRightMotorEncoderValue->Enabled = true;
				lblLeftMotorEncoderValue->Enabled = true;
				lblSCbatteryCurrent->Enabled = true;
				lblSCbattery->Enabled = true;
				lblNUCCbatteryCurrent->Enabled = true;
				lblNUCCbattery->Enabled = true;

				if(Comhandler.MotorBatteryVoltage() < Confs.MotorBatteryLow){MessageBox::Show("The Motor Battery is Too Low","Robot Error",MessageBoxButtons::OK,MessageBoxIcon::Warning);}
				if(Comhandler.ServoBatteryVoltage() <  Confs.ServoBatteryLow){MessageBox::Show("The Servo Battery is Too Low","Robot Error",MessageBoxButtons::OK,MessageBoxIcon::Warning);}
				tmrSensorRefresh->Enabled = true;
			}

			if(Comhandler.IMUPortIsOpen()){
				btnRobotTurnOff->Enabled = true;
				btnRobotTurnOn->Enabled = false;
				btnPortConfiguration->Enabled = false;
				picIMUPicture->Enabled = true;
				lblYaw->Enabled = true;
				lblPitch->Enabled = true;
				lblRoll->Enabled = true;
				tmrSensorRefresh->Enabled = true;
			}
		}
		//************************************
		System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e) {

			int PositionNumber = ArmPosition();
			Confs.LeftCameraAngle = int::Parse(txtLeftCameraAngle->Text);
			Confs.RightCameraAngle = int::Parse(txtRightCameraAngle->Text);
			Confs.CamerasUpperTiltAngle[PositionNumber] = int::Parse(txtCameraUpperTiltAngle->Text);
			Confs.CamerasMiddleTiltAngle[PositionNumber] = int::Parse(txtCameraMiddleTiltAngle->Text);
			Confs.CamerasBottomTiltAngle[PositionNumber] = int::Parse(txtCameraBottomTiltAngle->Text);
			Confs.CamerasPanAngle[PositionNumber] = int::Parse(txtCameraPanAngle->Text);
			Confs.SamplingDistance = int::Parse(cboSamplingDistance->SelectedItem->ToString());
			Confs.AvoidanceDistance = int::Parse(cboAvoidanceDistance->SelectedItem->ToString());
			Confs.RobotSpeed = int::Parse(cboRobotSpeed->SelectedItem->ToString());
			Confs.ServoSpeed = int::Parse(cboRobotSpeed->SelectedItem->ToString());
			Confs.SaveConfigs();
		}
		//************************************
		System::Void btnRobotTurnOff_Click(System::Object^  sender, System::EventArgs^  e) {
			RobotTurnOffProcedure();
		}
		//************************************
		void RobotTurnOffProcedure(void){
			btnRobotTurnOff->Enabled = false;
			btnRobotTurnOn->Enabled = true;
			btnSave->Enabled = false;
			btnPortConfiguration->Enabled = true;
			tmrSensorRefresh->Enabled = false;
			txtCameraPanAngle->Enabled = false;
			txtCameraUpperTiltAngle->Enabled = false;
			txtCameraMiddleTiltAngle->Enabled = false;
			txtCameraBottomTiltAngle->Enabled = false;
			txtLeftCameraAngle->Enabled = false;
			txtRightCameraAngle->Enabled = false;
			btnPosition1->Enabled = false;
			btnPosition2->Enabled = false;
			btnPosition3->Enabled = false;
			btnPosition4->Enabled = false;
			picIMUPicture->Enabled = false;
			lblYaw->Enabled = false;
			lblPitch->Enabled = false;
			lblRoll->Enabled = false;
			lblMbattery->Enabled = false;
			lblSbattery->Enabled = false;
			lblNUCbattery->Enabled = false;
			lblMbatteryVoltage->Enabled = false;
			lblSbatteryVoltage->Enabled = false;
			lblNUCbatteryVoltage->Enabled = false;
			lblHumidityPercent->Enabled = false;
			lblTemperatureDegree->Enabled = false;
			lblMCbatteryCurrent->Enabled = false;
			lblHumidity->Enabled = false;
			lblTemperature->Enabled = false;
			lblMCbattery->Enabled = false;
			lblLeftMotorEncoder->Enabled = false;
			lblRightMotorEncoder->Enabled = false;
			lblRightMotorEncoderValue->Enabled = false;
			lblLeftMotorEncoderValue->Enabled = false;
			lblSCbatteryCurrent->Enabled = false;
			lblSCbattery->Enabled = false;
			lblNUCCbatteryCurrent->Enabled = false;
			lblNUCCbattery->Enabled = false;
			Comhandler.TurnOffServos();
			Comhandler.TurnOffMotors();
			Comhandler.CloseSensorsPort();
			Comhandler.CloseMotorsPort();
			Comhandler.CloseIMUPort();
		}
		//************************************
		System::Void tmrSensorRefresh_Tick(System::Object^  sender, System::EventArgs^  e) {
			if(lblMbatteryVoltage->Enabled){
				lblMbatteryVoltage->Text =   Comhandler.MotorBatteryVoltage().ToString("N2") + " V"; 
				lblSbatteryVoltage->Text = Comhandler.ServoBatteryVoltage().ToString("N2") + " V"; 
				lblNUCbatteryVoltage->Text = Comhandler.NUCBatteryVoltage().ToString("N2") + " V";
				lblMCbatteryCurrent->Text = Comhandler.MotorBatteryCurrent().ToString("N2")+ " A";;
				lblSCbatteryCurrent->Text = Comhandler.ServoBatteryCurrent().ToString("N2")+ " A";;
				lblNUCCbatteryCurrent->Text = Comhandler.NUCBatteryCurrent().ToString("N2")+ " A";;
				lblTemperatureDegree->Text = Comhandler.Temperature().ToString("N2") + " °";;
				lblHumidityPercent->Text = Comhandler.Humidity().ToString("N2")+ " %";
				if(!pathplanning.getPathPlanningStatus()){
					lblLeftMotorEncoderValue->Text = Comhandler.LeftEncoderPosition().ToString();
					lblRightMotorEncoderValue->Text = Comhandler.RightEncoderPosition().ToString();}
				else {
					lblLeftMotorEncoderValue->Text = CurrentLeftMotorPosition.ToString();
					lblRightMotorEncoderValue->Text = CurrentRightMotorPosition.ToString();}}
			if(picIMUPicture->Enabled){
				IMUValues = Comhandler.ReadIMU();
				lblYaw->Text = IMUValues.first.ToString();
				lblPitch->Text = IMUValues.second.first.ToString();
				lblRoll->Text = IMUValues.second.second.ToString();
			}
		}
		//************************************
		System::Void btnRobotSelfTest_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		//************************************
		System::Void btnPortConfiguration_Click(System::Object^  sender, System::EventArgs^  e) {
			frmPortConfig^ portconfigform = gcnew frmPortConfig();
			portconfigform->Initialize(RobotConfigFilePath);
			portconfigform->ShowDialog();
		}
		//************************************ 
		System::Void MainForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			Comhandler.BothMotorStop();}
		//************************************ 
		System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			if(btnRobotTurnOff->Enabled){
				int RobotSpeed = int::Parse(cboRobotSpeed->SelectedItem->ToString());
				if(e->KeyCode == Keys::W) Comhandler.MoveForward(RobotSpeed,RobotSpeed);
				else if(e->KeyCode == Keys::S) Comhandler.MoveBackward(RobotSpeed,RobotSpeed);
				else if(e->KeyCode == Keys::A) Comhandler.TurnLeft(RobotSpeed,RobotSpeed);
				else if(e->KeyCode == Keys::D) Comhandler.TurnRight(RobotSpeed,RobotSpeed);
			}
		}
		//************************************ 
		System::Void txtLeftCameraAngle_Enter(System::Object^  sender, System::EventArgs^  e) {
			Confs.LeftCameraAngle = int::Parse(txtLeftCameraAngle->Text);
		}
		//************************************
		System::Void txtLeftCameraAngle_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			if(e->KeyChar == Convert::ToChar(Keys::Enter)){
				try{ Comhandler.TurnLeftCameraServo(int::Parse(txtLeftCameraAngle->Text),Confs.ServoSpeed); }
				catch(...){ txtLeftCameraAngle->Text = Confs.LeftCameraAngle.ToString();}
				txtRightCameraAngle->Focus();
			}
		}
		//************************************
		System::Void txtLeftCameraAngle_Leave(System::Object^  sender, System::EventArgs^  e) {
			try{ Comhandler.TurnLeftCameraServo(int::Parse(txtLeftCameraAngle->Text),Confs.ServoSpeed); }
			catch(...){ txtLeftCameraAngle->Text = Confs.LeftCameraAngle.ToString();}
		}
		//************************************
		System::Void txtRightCameraAngle_Enter(System::Object^  sender, System::EventArgs^  e) {
			Confs.RightCameraAngle = int::Parse(txtRightCameraAngle->Text);
		}
		//************************************
		System::Void txtRightCameraAngle_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			if(e->KeyChar == Convert::ToChar(Keys::Enter)){
				try{ Comhandler.TurnRightCameraServo(int::Parse(txtRightCameraAngle->Text),Confs.ServoSpeed); }
				catch(...){ txtRightCameraAngle->Text = Confs.RightCameraAngle.ToString();}
				txtCameraUpperTiltAngle->Focus();
			}
		}
		//************************************
		System::Void txtRightCameraAngle_Leave(System::Object^  sender, System::EventArgs^  e) {
			try{ Comhandler.TurnRightCameraServo(int::Parse(txtRightCameraAngle->Text),Confs.ServoSpeed); }
			catch(...){ txtRightCameraAngle->Text = Confs.RightCameraAngle.ToString();}
		}
		//************************************
		System::Void txtCameraUpperTiltAngle_Enter(System::Object^  sender, System::EventArgs^  e) {
			int PositionNumber = ArmPosition();
			Confs.CamerasUpperTiltAngle[PositionNumber] = int::Parse(txtCameraUpperTiltAngle->Text);
		}
		//************************************
		System::Void txtCameraTiltAngle_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			if(e->KeyChar == Convert::ToChar(Keys::Enter)){
				int PositionNumber = ArmPosition();
				try{ Comhandler.TurnUpperTiltServo(int::Parse(txtCameraUpperTiltAngle->Text),Confs.ServoSpeed); }
				catch(...){ txtCameraUpperTiltAngle->Text = Confs.CamerasUpperTiltAngle[PositionNumber].ToString();}
				txtCameraMiddleTiltAngle->Focus();
			}
		}
		//************************************
		System::Void txtCameraUpperTiltAngle_Leave(System::Object^  sender, System::EventArgs^  e) {
			int PositionNumber = ArmPosition();
			try{ Comhandler.TurnUpperTiltServo(int::Parse(txtCameraUpperTiltAngle->Text),Confs.ServoSpeed); }
			catch(...){ txtCameraUpperTiltAngle->Text = Confs.CamerasUpperTiltAngle[PositionNumber].ToString();}
		}
		//************************************
		System::Void txtCameraMiddleTiltAngle_Enter(System::Object^  sender, System::EventArgs^  e) {
			int PositionNumber = ArmPosition();
			Confs.CamerasMiddleTiltAngle[PositionNumber] = int::Parse(txtCameraMiddleTiltAngle->Text);
		}
		//************************************
		System::Void txtCameraMiddleTiltAngle_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			if(e->KeyChar == Convert::ToChar(Keys::Enter)){
				int PositionNumber = ArmPosition();
				try{ Comhandler.TurnMiddleTiltServo(int::Parse(txtCameraMiddleTiltAngle->Text),Confs.ServoSpeed); }
				catch(...){ txtCameraMiddleTiltAngle->Text = Confs.CamerasMiddleTiltAngle[PositionNumber].ToString();}
				txtCameraBottomTiltAngle->Focus();
			}
		}
		//************************************
		System::Void txtCameraMiddleTiltAngle_Leave(System::Object^  sender, System::EventArgs^  e) {
			int PositionNumber = ArmPosition();
			try{ Comhandler.TurnMiddleTiltServo(int::Parse(txtCameraMiddleTiltAngle->Text),Confs.ServoSpeed); }
			catch(...){ txtCameraMiddleTiltAngle->Text = Confs.CamerasMiddleTiltAngle[PositionNumber].ToString();}
		}
		//************************************
		System::Void txtCameraBottomTiltAngle_Enter(System::Object^  sender, System::EventArgs^  e) {
			int PositionNumber = ArmPosition();
			Confs.CamerasBottomTiltAngle[PositionNumber] = int::Parse(txtCameraBottomTiltAngle->Text);
		}
		//************************************
		System::Void txtCameraBottomTiltAngle_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			if(e->KeyChar == Convert::ToChar(Keys::Enter)){
				int PositionNumber = ArmPosition();
				try{ Comhandler.TurnBottomTiltServo(int::Parse(txtCameraBottomTiltAngle->Text),Confs.ServoSpeed); }
				catch(...){ txtCameraBottomTiltAngle->Text = Confs.CamerasBottomTiltAngle[PositionNumber].ToString();}
				txtCameraPanAngle->Focus();
			}
		}
		//************************************
		System::Void txtCameraBottomTiltAngle_Leave(System::Object^  sender, System::EventArgs^  e) {
			int PositionNumber = ArmPosition();
			try{ Comhandler.TurnBottomTiltServo(int::Parse(txtCameraBottomTiltAngle->Text),Confs.ServoSpeed); }
			catch(...){ txtCameraBottomTiltAngle->Text = Confs.CamerasBottomTiltAngle[PositionNumber].ToString();}
		}
		//************************************
		System::Void txtCameraPanAngle_Enter(System::Object^  sender, System::EventArgs^  e) {
			int PositionNumber = ArmPosition();
			Confs.CamerasPanAngle[PositionNumber] = int::Parse(txtCameraPanAngle->Text);
		}
		//************************************
		System::Void txtCameraPanAngle_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			if(e->KeyChar == Convert::ToChar(Keys::Enter)){
				int PositionNumber = ArmPosition();
				try{ Comhandler.TurnPanServo(int::Parse(txtCameraPanAngle->Text),Confs.ServoSpeed); }
				catch(...){ txtCameraPanAngle->Text = Confs.CamerasPanAngle[PositionNumber].ToString();}
				btnSave->Focus();
			}
		}
		//************************************
		System::Void txtCameraPanAngle_Leave(System::Object^  sender, System::EventArgs^  e) {
			int PositionNumber = ArmPosition();
			try{ Comhandler.TurnPanServo(int::Parse(txtCameraPanAngle->Text),Confs.ServoSpeed); }
			catch(...){ txtCameraPanAngle->Text = Confs.CamerasPanAngle[PositionNumber].ToString();}
		}//************************************

		//************************************
		System::Void chkEnableSampling_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if(chkEnableSampling->Checked) {
				lblSamplingDistance->Enabled = true;
				lblBlock1->Enabled = true;
				cboSamplingDistance->Enabled = true;}
			else{
				lblSamplingDistance->Enabled = false;
				lblBlock1->Enabled = false;
				cboSamplingDistance->Enabled = false;}
		}
		//************************************
		System::Void btnCameraProperties_Click(System::Object^  sender, System::EventArgs^  e) {
			frmCameraProperties^ Cameraproperties = gcnew frmCameraProperties(stereovision,RobotConfigFilePath);
			Cameraproperties->ShowDialog();
		}
		//************************************
		System::Void btnOpenMap_Click(System::Object^  sender, System::EventArgs^  e) {
			openMapDialog->Filter = "image files (*.png)|*.png|All files (*.*)|*.*";
			openMapDialog->FilterIndex = 1;
			openMapDialog->RestoreDirectory = true;
			if (openMapDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				System::String^ Location = openMapDialog->FileName;
				string MapFileAddress = msclr::interop::marshal_as<std::string>(Location);
				if(simulator.LoadMap(MapFileAddress) && !simulator.getMap().empty()){
					//lblMessages->Text = " cols : " + simulator.getMap().cols.ToString() + " , rows : " +simulator.getMap().rows.ToString() + "\n";
					simulator.Initialize(picGridMap->Width,picGridMap->Height);
					btnStartPathPlanning->Enabled = false;
					DrawCVImage(picGridMap,simulator.getMap());
					simulator.setMapLoadedCorrectly(true);
					picGridMap->Cursor = System::Windows::Forms::Cursors::Hand;
					picCompass->Image = imgCompassN;
					CurrentRobotDirection = 0; //North
					picCompass->Cursor = System::Windows::Forms::Cursors::Hand;
				}
			}
		}
		//************************************
		System::Void picGridMap_Click(System::Object^  sender, System::EventArgs^  e) {
			if(simulator.getMapLoadedCorrectly() && !pathplanning.getPathPlanningStatus()){
				MouseEventArgs^ MouseEvents = (MouseEventArgs^)e;
				if(MouseEvents->Button == Windows::Forms::MouseButtons::Left){
					simulator.MouseLeftClick(MouseEvents->X,MouseEvents->Y);
				}
				else if(MouseEvents->Button == Windows::Forms::MouseButtons::Middle){
					simulator.MouseMiddleClick(MouseEvents->X,MouseEvents->Y);	
				}
				else if(MouseEvents->Button == Windows::Forms::MouseButtons::Right){
					simulator.MouseRightClick(MouseEvents->X,MouseEvents->Y);
				}
				DrawCVImage(picGridMap,simulator.getMap());
				if(simulator.getStart() != cv::Point(0,0) && simulator.getGoals().size() > 0){
					btnStartPathPlanning->Enabled = true;
				}
				else
					btnStartPathPlanning->Enabled = false;
			}
		}
		//************************************
		System::Void picCompass_Click(System::Object^  sender, System::EventArgs^  e) {
			MouseEventArgs^ MouseEvents = (MouseEventArgs^)e;
			if(simulator.getMapLoadedCorrectly() && !pathplanning.getPathPlanningStatus()){
				if(MouseEvents->Button == Windows::Forms::MouseButtons::Left){
					if(CurrentRobotDirection == 0)        { CurrentRobotDirection =  45;  picCompass->Image = imgCompassNE;} //NorthEast
					else if(CurrentRobotDirection == 45)  { CurrentRobotDirection =  90;  picCompass->Image = imgCompassE; } //East
					else if(CurrentRobotDirection == 90)  { CurrentRobotDirection =  135; picCompass->Image = imgCompassSE;} //SouthEast
					else if(CurrentRobotDirection == 135) { CurrentRobotDirection =  180; picCompass->Image = imgCompassS; } //South
					else if(CurrentRobotDirection == 180) { CurrentRobotDirection = -135; picCompass->Image = imgCompassSW;} //SouthWest
					else if(CurrentRobotDirection == -135){ CurrentRobotDirection = -90;  picCompass->Image = imgCompassW; } //Wast
					else if(CurrentRobotDirection == -90) { CurrentRobotDirection = -45;  picCompass->Image = imgCompassNW;} //NorthWast
					else if(CurrentRobotDirection == -45) { CurrentRobotDirection =  0;   picCompass->Image = imgCompassN; } //North
				}
				if(MouseEvents->Button == Windows::Forms::MouseButtons::Right){
					if(CurrentRobotDirection == 0)        { CurrentRobotDirection =  -45; picCompass->Image = imgCompassNW;} //NorthEast
					else if(CurrentRobotDirection == -45) { CurrentRobotDirection =  -90; picCompass->Image = imgCompassW; } //East
					else if(CurrentRobotDirection == -90) { CurrentRobotDirection = -135; picCompass->Image = imgCompassSW;} //SouthEast
					else if(CurrentRobotDirection ==-135) { CurrentRobotDirection =  180; picCompass->Image = imgCompassS; } //South
					else if(CurrentRobotDirection == 180) { CurrentRobotDirection =  135; picCompass->Image = imgCompassSE;} //SouthWest
					else if(CurrentRobotDirection == 135) { CurrentRobotDirection =   90; picCompass->Image = imgCompassE; } //Wast
					else if(CurrentRobotDirection ==  90) { CurrentRobotDirection =   45; picCompass->Image = imgCompassNE;} //NorthWast
					else if(CurrentRobotDirection ==  45) { CurrentRobotDirection =    0; picCompass->Image = imgCompassN; } //North
				}
			}
		}
		//************************************
		System::Void btnCalibration_Click(System::Object^  sender, System::EventArgs^  e) {

			if(!calibration.CalibrationIsInProccess())
				if(stereovision.IsRightCameraAvaiable() && stereovision.IsLeftCameraAvaiable()){

					FormChangesForCalibration(true);
					lblMessages-> Text = "";

					picLeft->Size = System::Drawing::Size(486,270);
					picRight->Size = System::Drawing::Size(486,270);

					picLeft->Location = System::Drawing::Point(14,40);
					picRight->Location = System::Drawing::Point(515,40);

					btnCalibration->Text = "Calibrating ...";
					calibration.Initialize(stereovision.getRightCameraDeviceID(),stereovision.getLeftCameraDeviceID());
					tmrCalibrationLoop->Enabled = true;
				}
				else{MessageBox::Show("Both Cameras are not Avaiable","Camera Error",MessageBoxButtons::OK,MessageBoxIcon::Error);}

			else{
				calibration.CancelCalibratio();
				FormChangesForCalibration(false);
				btnCalibration->Text = "Calibration";

				tmrCalibrationLoop->Enabled = false;

				picLeft->Size = System::Drawing::Size(270,150);
				picRight->Size = System::Drawing::Size(270,150);

				picLeft->Location = System::Drawing::Point(240,40);
				picRight->Location = System::Drawing::Point(515,40);
			}
		}
		//************************************
		System::Void tmrCalibrationLoop_Tick(System::Object^  sender, System::EventArgs^  e) {
			if(calibration.getSampleNumber() < calibration.getRequiredSample()){
				std::pair <Mat,Mat> CameraImages = calibration.ClibrationDrawChessboard();
				if(!CameraImages.first.empty())	DrawCVImage(picRight,CameraImages.first);
				if(!CameraImages.second.empty()) DrawCVImage(picLeft,CameraImages.second);
			}
			else{
				lblMessages-> Text = "Sampling Finished. \n";
				lblMessages-> Text += "Starting Calibration ... \n";
				std::pair<double,double> result = calibration.StereoCameraClibration();

				lblMessages-> Text = "Calibration Finished in " + result.first.ToString("N2") + "\n";
				lblMessages-> Text += " With "  + result.second.ToString("N2") + " Error \n";

				calibration.CancelCalibratio();
				FormChangesForCalibration(false);
				btnCalibration->Text = "Calibration";

				tmrCalibrationLoop->Enabled = false;

				picLeft->Size = System::Drawing::Size(270,150);
				picRight->Size = System::Drawing::Size(270,150);

				picLeft->Location = System::Drawing::Point(240,40);
				picRight->Location = System::Drawing::Point(515,40);
			}
		}
		//************************************
		System::Void btnSaveSample_Click(System::Object^  sender, System::EventArgs^  e) {
			if(calibration.getSampleNumber() < calibration.getRequiredSample()){
				if(calibration.SaveSnapShot()) lblMessages-> Text += "Sample" + calibration.getSampleNumber().ToString() + " Saved \n";}
		}
		//************************************
		void FormChangesForCalibration(bool Change){
			tmrMainLoop->Enabled = !Change;

			if(!Change && !btnRobotTurnOn->Enabled)
				tmrSensorRefresh->Enabled = !Change;

			btnSaveSample->Visible = Change;
			btnSaveSample->Enabled= Change;

			lblFPSValue->Visible = !Change;
			lblFPS->Visible = !Change;
			lblMbattery->Visible = !Change;
			lblSbattery->Visible = !Change;
			lblNUCbattery->Visible = !Change;
			lblMbatteryVoltage->Visible = !Change;
			lblSbatteryVoltage->Visible = !Change;
			lblNUCbatteryVoltage->Visible = !Change;
			lblHumidityPercent->Visible = !Change;
			lblTemperatureDegree->Visible = !Change;
			lblMCbatteryCurrent->Visible = !Change;
			lblHumidity->Visible = !Change;
			lblTemperature->Visible = !Change;
			lblMCbattery->Visible = !Change;
			lblSCbatteryCurrent->Visible = !Change;
			lblSCbattery->Visible = !Change;
			lblNUCCbatteryCurrent->Visible = !Change;
			lblNUCCbattery->Visible = !Change;
			picDisparity->Visible = !Change;
			chkShowCameras->Visible = !Change;
			chkEnableSampling->Visible = !Change;
			chkUseCalibratio->Visible = !Change;
			chkComputeDisparity->Visible = !Change;
			chkShowDisparity->Visible = !Change;
			btnCameraProperties->Visible = !Change;
			btnSnapShot->Visible = !Change;
			btnStartPathPlanning->Visible = !Change;
			btnOpenMap->Visible = !Change;
			btnSaveDisparity->Visible = !Change;
			btnCaptureVideo->Visible = !Change;
			cboSamplingDistance->Visible = !Change;
			lblSamplingDistance->Visible = !Change;
			lblAvoidanceDistance->Visible = !Change;
			cboAvoidanceDistance->Visible = !Change;
			picCamerasPositions->Visible = !Change;
			txtLeftCameraAngle->Visible = !Change;
			txtRightCameraAngle->Visible = !Change;
			txtCameraUpperTiltAngle->Visible = !Change;
			txtCameraMiddleTiltAngle->Visible = !Change;
			txtCameraBottomTiltAngle->Visible = !Change;
			txtCameraPanAngle->Visible = !Change;
			picGridMap->Visible = !Change;
			lblLeftMotorEncoder ->Visible = !Change;
			lblRightMotorEncoder ->Visible = !Change;
			lblRightMotorEncoderValue->Visible = !Change;
			lblLeftMotorEncoderValue->Visible = !Change;
			lblRobotSpeed->Visible = !Change;
			cboRobotSpeed->Visible = !Change;
			btnRobotSelfTest->Visible = !Change;
			btnRobotTurnOn->Visible = !Change;
			btnRobotTurnOff->Visible = !Change;
			lblBlock1->Visible = !Change;
			lblBlock2->Visible = !Change;
			btnPortConfiguration->Visible = !Change;
			btnSave->Visible = !Change;
			btnPosition1->Visible = !Change;
			btnPosition2->Visible = !Change;
			btnPosition3->Visible = !Change;
			btnPosition4->Visible = !Change;
		}
		//************************************
		System::Void btnStartPathPlanning_Click(System::Object^  sender, System::EventArgs^  e) {

			if(!pathplanning.getPathPlanningStatus()) {
				if(!btnRobotTurnOff->Enabled){ MessageBox::Show("Please Turn On the Robot","Robot Error",MessageBoxButtons::OK,MessageBoxIcon::Warning);return;}
				if(!stereovision.IsRightCameraAvaiable()){MessageBox::Show("Cannot Open The Right Camera","Camera Error",MessageBoxButtons::OK,MessageBoxIcon::Warning);return;}
				if(!stereovision.IsLeftCameraAvaiable()){MessageBox::Show("Cannot Open The Left Camera","Camera Error",MessageBoxButtons::OK,MessageBoxIcon::Warning);return;}

				chkComputeDisparity->Checked = true;
				btnOpenMap->Enabled = false;
				btnCalibration->Enabled = false;
				btnRobotTurnOff->Enabled = false;
				btnRobotSelfTest->Enabled = false;
				btnSave->Enabled = false;
				txtCameraPanAngle->Enabled = false;
				txtCameraUpperTiltAngle->Enabled = false;
				txtCameraMiddleTiltAngle->Enabled = false;
				txtCameraBottomTiltAngle->Enabled = false;
				txtLeftCameraAngle->Enabled = false;
				txtRightCameraAngle->Enabled = false;
				PlanPath();}
			else{
				tmrPathPlanning->Enabled = false;
				PathPlanningStop();}
		}
		//************************************
		void PlanPath(void){

			LastCellLeftMotorPosition = Comhandler.LeftEncoderPosition();
			LastCellRightMotorPosition = Comhandler.RightEncoderPosition();
			CurrentPathIndex = 0;
			CurrentPathPointIndex = 0;

			btnStartPathPlanning->Text = "Stop PathPlanning";

			pathplanning.Initialize(simulator.getGrayScaleMap(),simulator.getStart(),simulator.getGoals());
			pathplanning.CalculateInitialPath();
			simulator.DrawInitialPath(pathplanning.getPath());
			DrawCVImage(picGridMap,simulator.getInitialPathMap());

			tmrPathPlanning->Enabled = true;
		}
		//************************************
		void PathPlanningStop(void){
			Comhandler.BothMotorStop();
			btnStartPathPlanning->Text = "Start PathPlanning";
			pathplanning.setPathPlanningStatus(false);

			RobotIsMovingToNextPoint = false;
			btnOpenMap->Enabled = true;
			btnCalibration->Enabled = true;
			btnRobotTurnOff->Enabled = true;
			btnRobotSelfTest->Enabled = true;
			btnSave->Enabled = true;
			txtCameraPanAngle->Enabled = true;
			txtCameraUpperTiltAngle->Enabled = true;
			txtCameraMiddleTiltAngle->Enabled = true;
			txtCameraBottomTiltAngle->Enabled = true;
			txtLeftCameraAngle->Enabled = true;
			txtRightCameraAngle->Enabled = true;
		}
		//************************************
		void PathPlanningProcedure(void){
			tmrPathPlanning->Enabled = false;	
			UpdateCompass();
			DrawCVImage(picGridMap,simulator.ShowRobotPositionOnMap(pathplanning.GetRoborCurrentPositionPoint(CurrentPathIndex,CurrentPathPointIndex)));
			std::pair<int,std::pair<int,int>> result = pathplanning.FindNextRobotDirection(CurrentPathIndex,CurrentPathPointIndex);
			NextRobotDirection = result.first;
			NextRobotPathIndex = result.second.first;
			NextRobotPathPointIndex = result.second.second;

			if(NextRobotPathIndex == -1 && NextRobotPathPointIndex == -1) {
				lblMessages->Text += " Goal Reached \n";
				PathPlanningStop();}
			else {
				lblMessages->Text = "Point[" + CurrentPathIndex.ToString()+"]["+CurrentPathPointIndex.ToString() + "] \n";
				lblMessages->Text += "Next Point[" + NextRobotPathIndex.ToString()+"]["+NextRobotPathPointIndex.ToString() + "] \n";
				lblMessages->Text += "Direction From : " + CurrentRobotDirection.ToString() + " to " + NextRobotDirection.ToString() + "\n";
				ExecuteNextRobotAction();
			}
		}
		//************************************
		void ExecuteNextRobotAction(void){
			CalculateRobotTurnDegree();
			int RobotSpeed = int::Parse(cboRobotSpeed->SelectedItem->ToString());
			lblMessages->Text += "Turn Degree : " + RobotTurnDegree.ToString() + "\n";
			if(RobotTurnDegree == 0) Comhandler.MoveForward(RobotSpeed,RobotSpeed);
			else if(RobotTurnDegree > 0)  Comhandler.TurnRight(RobotSpeed,RobotSpeed);
			else Comhandler.TurnLeft(RobotSpeed,RobotSpeed); 
			RobotIsMovingToNextPoint = true;
			tmrPathPlanning->Enabled = true;
		}
		//************************************
		void CalculateRobotTurnDegree(void){
			RobotTurnDegree = NextRobotDirection - CurrentRobotDirection;
			if (RobotTurnDegree < -180) RobotTurnDegree += 360;
			else if (RobotTurnDegree > 180) RobotTurnDegree -= 360;
		}
		//************************************
		void CheckMovementStatus(void){
			tmrPathPlanning->Enabled = false;
			std::pair<int,int> EncodersPositions = CheckEncoders();
			int RightMotorLimit = 0;
			int LeftMotorLimit = 0;
			switch(RobotTurnDegree){
			case    0: {RightMotorLimit = 1000; LeftMotorLimit = 1000;break;}
			case  -45: {RightMotorLimit =  600; LeftMotorLimit = -350;break;}
			case  +45: {RightMotorLimit = -350; LeftMotorLimit =  600;break;}
			case  -90: {RightMotorLimit = 1300; LeftMotorLimit = -600;break;}
			case  +90: {RightMotorLimit = -600; LeftMotorLimit = 1300;break;}
			case -135: {RightMotorLimit = 1900; LeftMotorLimit =-1000;break;}
			case +135: {RightMotorLimit =-1000; LeftMotorLimit = 1900;break;}
			case -180: {RightMotorLimit = 2700; LeftMotorLimit =-1400;break;}
			case +180: {RightMotorLimit =-1400; LeftMotorLimit = 2700;break;}
			}

			if(RobotTurnDegree == 0     && EncodersPositions.first > RightMotorLimit && EncodersPositions.second > LeftMotorLimit){ 
				lblMessages->Text += "Straight Done \n";
				CurrentPathIndex = NextRobotPathIndex;
				CurrentPathPointIndex = NextRobotPathPointIndex;
				MovementDone();}
			else if (RobotTurnDegree> 0 && EncodersPositions.first < RightMotorLimit && EncodersPositions.second > LeftMotorLimit) {
				lblMessages->Text += "Right Turn Done \n";
				CurrentRobotDirection = NextRobotDirection;
				MovementDone();}
			else if (RobotTurnDegree< 0 && EncodersPositions.first > RightMotorLimit && EncodersPositions.second < LeftMotorLimit) {
				lblMessages->Text += "Left Turn Done \n";
				CurrentRobotDirection = NextRobotDirection ; 
				MovementDone();}


			tmrPathPlanning->Enabled = true;
		}
		//************************************
		void MovementDone(void){
			LastCellLeftMotorPosition = CurrentRightMotorPosition;
			LastCellLeftMotorPosition = CurrentLeftMotorPosition;
			RobotIsMovingToNextPoint = false;
		}
		//************************************
		std::pair<int,int> CheckEncoders(void){
			return std::pair<int,int> (int(  CurrentRightMotorPosition - LastCellRightMotorPosition ) ,int(CurrentLeftMotorPosition - LastCellLeftMotorPosition));
		}
		//************************************
		void UpdateCompass(void){				
			switch (CurrentRobotDirection){
			case    0 :{ picCompass->Image = imgCompassN; break;} //North 
			case   45 :{ picCompass->Image = imgCompassNE;break;} //NorthEast
			case   90 :{ picCompass->Image = imgCompassE; break;} //East
			case  135 :{ picCompass->Image = imgCompassSE;break;} //SouthEast
			case  180 :{ picCompass->Image = imgCompassS; break;} //South
			case -135 :{ picCompass->Image = imgCompassSW;break;} //SouthWest
			case  -90 :{ picCompass->Image = imgCompassW; break;} //Wast
			case  -45 :{ picCompass->Image = imgCompassNW;break;} //NorthWast
			}
		}
		//************************************
		System::Void tmrPathPlanning_Tick(System::Object^  sender, System::EventArgs^  e) {

			if(CheckForMapUpdate())PlanPath();

			CurrentLeftMotorPosition = Comhandler.LeftEncoderPosition();
			CurrentRightMotorPosition = Comhandler.RightEncoderPosition();
			if(RobotIsMovingToNextPoint) CheckMovementStatus();
			else PathPlanningProcedure();

		}
		//************************************	
		bool CheckForMapUpdate(void){

		
			return false;
		}
		//************************************	
		System::Void btnPosition1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {PositionToLabel();}
		//************************************	
		System::Void btnPosition2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {PositionToLabel();}
		//************************************	
		System::Void btnPosition3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {PositionToLabel();}
		//************************************	
		System::Void btnPosition4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			Comhandler.TurnUpperTiltServo(Confs.CamerasUpperTiltAngle[3],Confs.ServoSpeed);
			Comhandler.TurnMiddleTiltServo(Confs.CamerasMiddleTiltAngle[3],Confs.ServoSpeed);
			Comhandler.TurnBottomTiltServo(Confs.CamerasBottomTiltAngle[3],Confs.ServoSpeed);
			Comhandler.TurnPanServo(Confs.CamerasPanAngle[3],Confs.ServoSpeed);
		}
		//************************************
		System::Void chkShowCameras_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if(FirstRun){
				FirstRun=false;
				stereovision.Initialize(RobotConfigFilePath);
				tmrMainLoop->Enabled = true;}
		}
		//************************************
		int ArmPosition(){
			int PositionNumber = 0;
			if(btnPosition1->Checked) PositionNumber = 0;
			else if (btnPosition2->Checked) PositionNumber = 1;
			else if (btnPosition3->Checked) PositionNumber = 2;
			else if (btnPosition4->Checked) PositionNumber = 3;
			return PositionNumber;
		}
		//************************************
		void PositionToLabel(){
			int PositionNumber = ArmPosition();
			txtCameraUpperTiltAngle->Text = Confs.CamerasUpperTiltAngle[PositionNumber].ToString();
			txtCameraMiddleTiltAngle->Text = Confs.CamerasMiddleTiltAngle[PositionNumber].ToString();
			txtCameraBottomTiltAngle->Text = Confs.CamerasBottomTiltAngle[PositionNumber].ToString();
			txtCameraPanAngle->Text = Confs.CamerasPanAngle[PositionNumber].ToString();
			Comhandler.TurnUpperTiltServo(Confs.CamerasUpperTiltAngle[PositionNumber],Confs.ServoSpeed);
			Comhandler.TurnMiddleTiltServo(Confs.CamerasMiddleTiltAngle[PositionNumber],Confs.ServoSpeed);
			Comhandler.TurnBottomTiltServo(Confs.CamerasBottomTiltAngle[PositionNumber],Confs.ServoSpeed);
			Comhandler.TurnPanServo(Confs.CamerasPanAngle[PositionNumber],Confs.ServoSpeed);
		}
		//************************************
	};
}

