#pragma once

#include <iostream>

namespace SkincReborn {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de credits_menu
	/// </summary>
	public ref class credits_menu : public System::Windows::Forms::Form
	{
	public:
		credits_menu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~credits_menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::LinkLabel^  linkLabel2;
	private: System::Windows::Forms::LinkLabel^  linkLabel3;
	private: System::Windows::Forms::LinkLabel^  linkLabel4;
	private: System::Windows::Forms::LinkLabel^  linkLabel5;
	private: System::Windows::Forms::LinkLabel^  linkLabel6;
	private: System::Windows::Forms::LinkLabel^  linkLabel7;
	private: System::Windows::Forms::LinkLabel^  linkLabel8;
	private: System::Windows::Forms::LinkLabel^  linkLabel9;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::LinkLabel^  linkLabel10;
	private: System::Windows::Forms::LinkLabel^  linkLabel11;
	private: System::Windows::Forms::LinkLabel^  linkLabel12;
	private: System::Windows::Forms::LinkLabel^  linkLabel13;
	private: System::Windows::Forms::LinkLabel^  linkLabel14;
	private: System::Windows::Forms::LinkLabel^  linkLabel15;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::LinkLabel^  linkLabel16;
	private: System::Windows::Forms::LinkLabel^  linkLabel17;
	private: System::Windows::Forms::LinkLabel^  linkLabel18;
	private: System::Windows::Forms::Button^  exit;
	private: System::Windows::Forms::Label^  label4;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(credits_menu::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel3 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel4 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel5 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel6 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel7 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel8 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel9 = (gcnew System::Windows::Forms::LinkLabel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->linkLabel10 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel11 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel12 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel13 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel14 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel15 = (gcnew System::Windows::Forms::LinkLabel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->linkLabel16 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel17 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel18 = (gcnew System::Windows::Forms::LinkLabel());
			this->exit = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Silver;
			this->label1->Location = System::Drawing::Point(611, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Credits";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Silver;
			this->label2->Location = System::Drawing::Point(159, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Programming:";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Silver;
			this->label3->Location = System::Drawing::Point(159, 108);
			this->label3->Margin = System::Windows::Forms::Padding(0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(439, 80);
			this->label3->TabIndex = 2;
			this->label3->Text = L"All programming by Benjamin Kahl aka Helliaca aka Elanus19\r\nin C++ 11\r\nusing SFML" 
				L" 2.1 graphics-libraries\r\nwith Microsoft Visual Studio 2010";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(635, 108);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(245, 93);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(947, 108);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(250, 99);
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Silver;
			this->label4->Location = System::Drawing::Point(159, 243);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(565, 180);
			this->label4->TabIndex = 6;
			this->label4->Text = resources->GetString(L"label4.Text");
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Silver;
			this->label5->Location = System::Drawing::Point(159, 206);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(86, 24);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Artwork:";
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Silver;
			this->label6->Location = System::Drawing::Point(159, 478);
			this->label6->Margin = System::Windows::Forms::Padding(0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(437, 160);
			this->label6->TabIndex = 8;
			this->label6->Text = resources->GetString(L"label6.Text");
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Silver;
			this->label7->Location = System::Drawing::Point(159, 441);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(65, 24);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Music";
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Silver;
			this->label8->Location = System::Drawing::Point(163, 695);
			this->label8->Margin = System::Windows::Forms::Padding(0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(296, 140);
			this->label8->TabIndex = 10;
			this->label8->Text = resources->GetString(L"label8.Text");
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Silver;
			this->label9->Location = System::Drawing::Point(163, 658);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(137, 24);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Sound effects";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel1->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel1->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel1->Location = System::Drawing::Point(408, 148);
			this->linkLabel1->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(151, 13);
			this->linkLabel1->TabIndex = 11;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"http://www.sfml-dev.org/";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel1_LinkClicked);
			// 
			// linkLabel2
			// 
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel2->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel2->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel2->Location = System::Drawing::Point(408, 168);
			this->linkLabel2->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(162, 13);
			this->linkLabel2->TabIndex = 12;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"http://msdn.microsoft.com/";
			this->linkLabel2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel2_LinkClicked);
			// 
			// linkLabel3
			// 
			this->linkLabel3->AutoSize = true;
			this->linkLabel3->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel3->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel3->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel3->Location = System::Drawing::Point(481, 243);
			this->linkLabel3->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel3->Name = L"linkLabel3";
			this->linkLabel3->Size = System::Drawing::Size(183, 13);
			this->linkLabel3->TabIndex = 13;
			this->linkLabel3->TabStop = true;
			this->linkLabel3->Text = L"http://helliaca.deviantart.com/";
			this->linkLabel3->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel3_LinkClicked);
			// 
			// linkLabel4
			// 
			this->linkLabel4->AutoSize = true;
			this->linkLabel4->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel4->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel4->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel4->Location = System::Drawing::Point(242, 264);
			this->linkLabel4->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel4->Name = L"linkLabel4";
			this->linkLabel4->Size = System::Drawing::Size(367, 13);
			this->linkLabel4->TabIndex = 14;
			this->linkLabel4->TabStop = true;
			this->linkLabel4->Text = L"http://helliaca.deviantart.com/gallery/51553426/Skinc-Artwork";
			this->linkLabel4->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel4_LinkClicked);
			// 
			// linkLabel5
			// 
			this->linkLabel5->AutoSize = true;
			this->linkLabel5->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel5->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel5->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel5->Location = System::Drawing::Point(481, 300);
			this->linkLabel5->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel5->Name = L"linkLabel5";
			this->linkLabel5->Size = System::Drawing::Size(186, 13);
			this->linkLabel5->TabIndex = 15;
			this->linkLabel5->TabStop = true;
			this->linkLabel5->Text = L"http://www.obsidiandawn.com/";
			this->linkLabel5->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel5_LinkClicked);
			// 
			// linkLabel6
			// 
			this->linkLabel6->AutoSize = true;
			this->linkLabel6->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel6->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel6->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel6->Location = System::Drawing::Point(380, 319);
			this->linkLabel6->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel6->Name = L"linkLabel6";
			this->linkLabel6->Size = System::Drawing::Size(350, 13);
			this->linkLabel6->TabIndex = 16;
			this->linkLabel6->TabStop = true;
			this->linkLabel6->Text = L"http://medialoot.com/item/free-subtle-grunge-brushes-vol-1/";
			this->linkLabel6->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel6_LinkClicked);
			// 
			// linkLabel7
			// 
			this->linkLabel7->AutoSize = true;
			this->linkLabel7->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel7->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel7->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel7->Location = System::Drawing::Point(376, 338);
			this->linkLabel7->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel7->Name = L"linkLabel7";
			this->linkLabel7->Size = System::Drawing::Size(145, 13);
			this->linkLabel7->TabIndex = 17;
			this->linkLabel7->TabStop = true;
			this->linkLabel7->Text = L"http://planetside.co.uk/";
			this->linkLabel7->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel7_LinkClicked);
			// 
			// linkLabel8
			// 
			this->linkLabel8->AutoSize = true;
			this->linkLabel8->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel8->CausesValidation = false;
			this->linkLabel8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel8->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel8->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel8->Location = System::Drawing::Point(368, 478);
			this->linkLabel8->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel8->Name = L"linkLabel8";
			this->linkLabel8->Size = System::Drawing::Size(175, 13);
			this->linkLabel8->TabIndex = 18;
			this->linkLabel8->TabStop = true;
			this->linkLabel8->Text = L"http://www.incompetech.com";
			this->linkLabel8->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel8_LinkClicked);
			// 
			// linkLabel9
			// 
			this->linkLabel9->AutoSize = true;
			this->linkLabel9->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel9->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel9->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel9->Location = System::Drawing::Point(430, 280);
			this->linkLabel9->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel9->Name = L"linkLabel9";
			this->linkLabel9->Size = System::Drawing::Size(144, 13);
			this->linkLabel9->TabIndex = 19;
			this->linkLabel9->TabStop = true;
			this->linkLabel9->Text = L"http://www.adobe.com/";
			this->linkLabel9->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel9_LinkClicked);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(938, 243);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(250, 99);
			this->pictureBox3->TabIndex = 20;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(668, 504);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(433, 65);
			this->pictureBox4->TabIndex = 21;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.BackgroundImage")));
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox5->Location = System::Drawing::Point(668, 597);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(300, 118);
			this->pictureBox5->TabIndex = 22;
			this->pictureBox5->TabStop = false;
			// 
			// linkLabel10
			// 
			this->linkLabel10->AutoSize = true;
			this->linkLabel10->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel10->CausesValidation = false;
			this->linkLabel10->Enabled = false;
			this->linkLabel10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel10->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel10->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel10->Location = System::Drawing::Point(408, 695);
			this->linkLabel10->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel10->Name = L"linkLabel10";
			this->linkLabel10->Size = System::Drawing::Size(159, 13);
			this->linkLabel10->TabIndex = 23;
			this->linkLabel10->TabStop = true;
			this->linkLabel10->Text = L"http://www.freesound.com";
			// 
			// linkLabel11
			// 
			this->linkLabel11->AutoSize = true;
			this->linkLabel11->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel11->CausesValidation = false;
			this->linkLabel11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel11->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel11->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel11->Location = System::Drawing::Point(481, 809);
			this->linkLabel11->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel11->Name = L"linkLabel11";
			this->linkLabel11->Size = System::Drawing::Size(275, 13);
			this->linkLabel11->TabIndex = 24;
			this->linkLabel11->TabStop = true;
			this->linkLabel11->Text = L"https://www.freesound.org/people/Setuniman/";
			this->linkLabel11->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel11_LinkClicked);
			// 
			// linkLabel12
			// 
			this->linkLabel12->AutoSize = true;
			this->linkLabel12->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel12->CausesValidation = false;
			this->linkLabel12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel12->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel12->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel12->Location = System::Drawing::Point(481, 789);
			this->linkLabel12->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel12->Name = L"linkLabel12";
			this->linkLabel12->Size = System::Drawing::Size(265, 13);
			this->linkLabel12->TabIndex = 25;
			this->linkLabel12->TabStop = true;
			this->linkLabel12->Text = L"https://www.freesound.org/people/qubodup/";
			this->linkLabel12->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel12_LinkClicked);
			// 
			// linkLabel13
			// 
			this->linkLabel13->AutoSize = true;
			this->linkLabel13->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel13->CausesValidation = false;
			this->linkLabel13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel13->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel13->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel13->Location = System::Drawing::Point(481, 769);
			this->linkLabel13->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel13->Name = L"linkLabel13";
			this->linkLabel13->Size = System::Drawing::Size(265, 13);
			this->linkLabel13->TabIndex = 26;
			this->linkLabel13->TabStop = true;
			this->linkLabel13->Text = L"https://www.freesound.org/people/Willlewis/";
			this->linkLabel13->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel13_LinkClicked);
			// 
			// linkLabel14
			// 
			this->linkLabel14->AutoSize = true;
			this->linkLabel14->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel14->CausesValidation = false;
			this->linkLabel14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel14->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel14->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel14->Location = System::Drawing::Point(481, 749);
			this->linkLabel14->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel14->Name = L"linkLabel14";
			this->linkLabel14->Size = System::Drawing::Size(312, 13);
			this->linkLabel14->TabIndex = 27;
			this->linkLabel14->TabStop = true;
			this->linkLabel14->Text = L"https://www.freesound.org/people/metamorphmuses/";
			this->linkLabel14->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel14_LinkClicked);
			// 
			// linkLabel15
			// 
			this->linkLabel15->AutoSize = true;
			this->linkLabel15->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel15->CausesValidation = false;
			this->linkLabel15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel15->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel15->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel15->Location = System::Drawing::Point(481, 729);
			this->linkLabel15->Margin = System::Windows::Forms::Padding(0);
			this->linkLabel15->Name = L"linkLabel15";
			this->linkLabel15->Size = System::Drawing::Size(303, 13);
			this->linkLabel15->TabIndex = 28;
			this->linkLabel15->TabStop = true;
			this->linkLabel15->Text = L"https://www.freesound.org/people/RICHERlandTV/";
			this->linkLabel15->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel15_LinkClicked);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(901, 763);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(351, 128);
			this->label10->TabIndex = 29;
			this->label10->Text = L"All music and sound is licensed under Creative Commons:\r\n- By Attribution 3.0\r\n\r\n" 
				L"\r\n- Public Domain Dedication\r\n\r\n\r\n- By Attribution 3.0 - Non-commercial\r\n";
			// 
			// linkLabel16
			// 
			this->linkLabel16->AutoSize = true;
			this->linkLabel16->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel16->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel16->Location = System::Drawing::Point(911, 793);
			this->linkLabel16->Name = L"linkLabel16";
			this->linkLabel16->Size = System::Drawing::Size(268, 16);
			this->linkLabel16->TabIndex = 30;
			this->linkLabel16->TabStop = true;
			this->linkLabel16->Text = L"http://creativecommons.org/licenses/by/3.0/";
			this->linkLabel16->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel16_LinkClicked);
			// 
			// linkLabel17
			// 
			this->linkLabel17->AutoSize = true;
			this->linkLabel17->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel17->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel17->Location = System::Drawing::Point(911, 843);
			this->linkLabel17->Name = L"linkLabel17";
			this->linkLabel17->Size = System::Drawing::Size(310, 16);
			this->linkLabel17->TabIndex = 31;
			this->linkLabel17->TabStop = true;
			this->linkLabel17->Text = L"http://creativecommons.org/publicdomain/zero/1.0/";
			this->linkLabel17->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel17_LinkClicked);
			// 
			// linkLabel18
			// 
			this->linkLabel18->AutoSize = true;
			this->linkLabel18->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel18->LinkColor = System::Drawing::Color::Teal;
			this->linkLabel18->Location = System::Drawing::Point(911, 891);
			this->linkLabel18->Name = L"linkLabel18";
			this->linkLabel18->Size = System::Drawing::Size(286, 16);
			this->linkLabel18->TabIndex = 32;
			this->linkLabel18->TabStop = true;
			this->linkLabel18->Text = L"http://creativecommons.org/licenses/by-nc/3.0/";
			this->linkLabel18->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &credits_menu::linkLabel18_LinkClicked);
			// 
			// exit
			// 
			this->exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)), 
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->exit->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->exit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->exit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->exit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->exit->Location = System::Drawing::Point(1217, 12);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(35, 32);
			this->exit->TabIndex = 33;
			this->exit->Text = L"X";
			this->exit->UseVisualStyleBackColor = false;
			this->exit->Click += gcnew System::EventHandler(this, &credits_menu::exit_Click);
			// 
			// credits_menu
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1280, 924);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->linkLabel18);
			this->Controls->Add(this->linkLabel17);
			this->Controls->Add(this->linkLabel16);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->linkLabel15);
			this->Controls->Add(this->linkLabel14);
			this->Controls->Add(this->linkLabel13);
			this->Controls->Add(this->linkLabel12);
			this->Controls->Add(this->linkLabel11);
			this->Controls->Add(this->linkLabel10);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->linkLabel9);
			this->Controls->Add(this->linkLabel8);
			this->Controls->Add(this->linkLabel7);
			this->Controls->Add(this->linkLabel6);
			this->Controls->Add(this->linkLabel5);
			this->Controls->Add(this->linkLabel4);
			this->Controls->Add(this->linkLabel3);
			this->Controls->Add(this->linkLabel2);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MaximumSize = System::Drawing::Size(1280, 924);
			this->MinimumSize = System::Drawing::Size(1280, 924);
			this->Name = L"credits_menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"credits_menu";
			this->Load += gcnew System::EventHandler(this, &credits_menu::credits_menu_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &credits_menu::credits_menu_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void credits_menu_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void credits_menu_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if(e->KeyCode == Keys::M){
				 std::cout<<"Changing FormBorderStyle"<<std::endl;
				 if(this->FormBorderStyle == System::Windows::Forms::FormBorderStyle::Sizable) this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
				 else this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
			 }
		 }
private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
				System::Diagnostics::Process::Start(linkLabel1->Text->ToString());
		 }
private: System::Void linkLabel15_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel15->Text->ToString());
		 }
private: System::Void linkLabel14_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel14->Text->ToString());
		 }
private: System::Void linkLabel13_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel13->Text->ToString());
		 }
private: System::Void linkLabel12_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel12->Text->ToString());
		 }
private: System::Void linkLabel11_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel11->Text->ToString());
		 }
private: System::Void linkLabel16_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel16->Text->ToString());
		 }
private: System::Void linkLabel3_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel3->Text->ToString());
		 }
private: System::Void linkLabel4_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel4->Text->ToString());
		 }
private: System::Void linkLabel9_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel9->Text->ToString());
		 }
private: System::Void linkLabel5_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel5->Text->ToString());
		 }
private: System::Void linkLabel6_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel6->Text->ToString());
		 }
private: System::Void linkLabel7_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel7->Text->ToString());
		 }
private: System::Void linkLabel8_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel8->Text->ToString());
		 }
private: System::Void linkLabel2_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel2->Text->ToString());
		 }
private: System::Void linkLabel17_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel17->Text->ToString());
		 }
private: System::Void linkLabel18_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start(linkLabel18->Text->ToString());
		 }
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
