#include "global_values.h"
#include "loaded_profile.h"
#include "game_settings.h"
#include <iostream>

#pragma once

namespace SkincReborn {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// This is the custom game menu
	/// </summary>
	public ref class custom_menu : public System::Windows::Forms::Form
	{
	public:
		custom_menu(void)
		{
			InitializeComponent();
		}

	protected:
		~custom_menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  b_prev;
	protected: 
	private: System::Windows::Forms::Button^  b_next;
	private: System::Windows::Forms::Label^  skin_name;
	private: System::Windows::Forms::PictureBox^  skin_display;
	private: System::Windows::Forms::Button^  b_mprev;

	private: System::Windows::Forms::Button^  b_mnext;

	private: System::Windows::Forms::Label^  map_name;

	private: System::Windows::Forms::PictureBox^  map_display;





	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ListBox^  diff;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  exit;
	private: System::Windows::Forms::Label^  warning_label;
	private: System::Windows::Forms::Button^  button3;

	private:
		/// <summary>
		/// Variables for input of game settings
		/// </summary>

		botskintype ToSkin( int s) {
			if(s==1) return B_DEMENTOR;
			else if(s==2) return B_ALTAIR;
			else if(s==3) return B_FREEMAN;
			else if(s==4) return B_ASH;
			return B_DEMENTOR;
		}

		map ToMap( int s) {
			if(s==1) return BASE;
			else if(s==2) return FOREST;
			else if(s==3) return DESERT;
			else if(s==4) return VOLCANO;
			else if(s==5) return CRYSTAL;
			else if(s==6) return INDUSTRIAL;
			else if(s==7) return ARENA;
			return BASE;
		}

		difficulty StringToDiff(String^ arg)
		{
			if(arg=="Easy") return EASY;
			else if(arg=="Standard") return STANDARD;
			else if(arg=="Medium") return MEDIUM;
			else if(arg=="Hard") return HARD;
			else if(arg=="Cheating") return CHEATING;
			else if(arg=="Merciless") return MERCILESS;
			return EASY;
		}


		int skinc;
		int mapc;
		int allowedmaps;
	private: System::Windows::Forms::NumericUpDown^  in_hp;
	private: System::Windows::Forms::NumericUpDown^  in_speed;
	private: System::Windows::Forms::NumericUpDown^  in_dmg;



			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// The following code was generated by Visual Studio
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(custom_menu::typeid));
			this->b_prev = (gcnew System::Windows::Forms::Button());
			this->b_next = (gcnew System::Windows::Forms::Button());
			this->skin_name = (gcnew System::Windows::Forms::Label());
			this->skin_display = (gcnew System::Windows::Forms::PictureBox());
			this->b_mprev = (gcnew System::Windows::Forms::Button());
			this->b_mnext = (gcnew System::Windows::Forms::Button());
			this->map_name = (gcnew System::Windows::Forms::Label());
			this->map_display = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->diff = (gcnew System::Windows::Forms::ListBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->in_hp = (gcnew System::Windows::Forms::NumericUpDown());
			this->in_speed = (gcnew System::Windows::Forms::NumericUpDown());
			this->in_dmg = (gcnew System::Windows::Forms::NumericUpDown());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->warning_label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->skin_display))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->map_display))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->in_hp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->in_speed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->in_dmg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// b_prev
			// 
			this->b_prev->BackColor = System::Drawing::Color::Transparent;
			this->b_prev->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->b_prev->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
				static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(14)));
			this->b_prev->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b_prev->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"b_prev.Image")));
			this->b_prev->Location = System::Drawing::Point(501, 124);
			this->b_prev->Name = L"b_prev";
			this->b_prev->Size = System::Drawing::Size(69, 80);
			this->b_prev->TabIndex = 7;
			this->b_prev->UseVisualStyleBackColor = false;
			this->b_prev->Click += gcnew System::EventHandler(this, &custom_menu::b_prev_Click);
			// 
			// b_next
			// 
			this->b_next->BackColor = System::Drawing::Color::Transparent;
			this->b_next->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->b_next->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
				static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(14)));
			this->b_next->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b_next->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"b_next.Image")));
			this->b_next->Location = System::Drawing::Point(742, 124);
			this->b_next->Name = L"b_next";
			this->b_next->Size = System::Drawing::Size(69, 80);
			this->b_next->TabIndex = 6;
			this->b_next->UseVisualStyleBackColor = false;
			this->b_next->Click += gcnew System::EventHandler(this, &custom_menu::b_next_Click);
			// 
			// skin_name
			// 
			this->skin_name->AutoSize = true;
			this->skin_name->BackColor = System::Drawing::Color::Transparent;
			this->skin_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->skin_name->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->skin_name->Location = System::Drawing::Point(608, 265);
			this->skin_name->Name = L"skin_name";
			this->skin_name->Size = System::Drawing::Size(95, 20);
			this->skin_name->TabIndex = 5;
			this->skin_name->Text = L"Skin Name";
			// 
			// skin_display
			// 
			this->skin_display->BackColor = System::Drawing::Color::Transparent;
			this->skin_display->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"skin_display.Image")));
			this->skin_display->Location = System::Drawing::Point(576, 72);
			this->skin_display->Name = L"skin_display";
			this->skin_display->Size = System::Drawing::Size(160, 190);
			this->skin_display->TabIndex = 4;
			this->skin_display->TabStop = false;
			// 
			// b_mprev
			// 
			this->b_mprev->BackColor = System::Drawing::Color::Transparent;
			this->b_mprev->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->b_mprev->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
				static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(14)));
			this->b_mprev->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b_mprev->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"b_mprev.Image")));
			this->b_mprev->Location = System::Drawing::Point(450, 683);
			this->b_mprev->Name = L"b_mprev";
			this->b_mprev->Size = System::Drawing::Size(69, 80);
			this->b_mprev->TabIndex = 11;
			this->b_mprev->UseVisualStyleBackColor = false;
			this->b_mprev->Click += gcnew System::EventHandler(this, &custom_menu::b_mprev_Click);
			// 
			// b_mnext
			// 
			this->b_mnext->BackColor = System::Drawing::Color::Transparent;
			this->b_mnext->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->b_mnext->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), 
				static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(14)));
			this->b_mnext->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b_mnext->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"b_mnext.Image")));
			this->b_mnext->Location = System::Drawing::Point(791, 683);
			this->b_mnext->Name = L"b_mnext";
			this->b_mnext->Size = System::Drawing::Size(69, 80);
			this->b_mnext->TabIndex = 10;
			this->b_mnext->UseVisualStyleBackColor = false;
			this->b_mnext->Click += gcnew System::EventHandler(this, &custom_menu::b_mnext_Click);
			// 
			// map_name
			// 
			this->map_name->AutoSize = true;
			this->map_name->BackColor = System::Drawing::Color::Transparent;
			this->map_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->map_name->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->map_name->Location = System::Drawing::Point(578, 834);
			this->map_name->Name = L"map_name";
			this->map_name->Size = System::Drawing::Size(48, 20);
			this->map_name->TabIndex = 9;
			this->map_name->Text = L"Map ";
			// 
			// map_display
			// 
			this->map_display->BackColor = System::Drawing::Color::Transparent;
			this->map_display->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"map_display.Image")));
			this->map_display->Location = System::Drawing::Point(525, 631);
			this->map_display->Name = L"map_display";
			this->map_display->Size = System::Drawing::Size(250, 200);
			this->map_display->TabIndex = 8;
			this->map_display->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(471, 308);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 20);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Health:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(471, 362);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 20);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Speed:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(472, 419);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 20);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Damage:";
			// 
			// diff
			// 
			this->diff->BackColor = System::Drawing::Color::Black;
			this->diff->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->diff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->diff->ForeColor = System::Drawing::Color::Maroon;
			this->diff->FormattingEnabled = true;
			this->diff->ItemHeight = 16;
			this->diff->Location = System::Drawing::Point(478, 505);
			this->diff->Name = L"diff";
			this->diff->Size = System::Drawing::Size(353, 82);
			this->diff->TabIndex = 18;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(578, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(155, 24);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Your opponent:";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)), 
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Red;
			this->button3->Location = System::Drawing::Point(951, 803);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(139, 56);
			this->button3->TabIndex = 20;
			this->button3->Text = L"Start";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &custom_menu::button3_Click);
			// 
			// in_hp
			// 
			this->in_hp->BackColor = System::Drawing::Color::Black;
			this->in_hp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->in_hp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->in_hp->ForeColor = System::Drawing::Color::Maroon;
			this->in_hp->Location = System::Drawing::Point(477, 336);
			this->in_hp->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000000, 0, 0, 0});
			this->in_hp->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->in_hp->Name = L"in_hp";
			this->in_hp->Size = System::Drawing::Size(354, 22);
			this->in_hp->TabIndex = 21;
			this->in_hp->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {300, 0, 0, 0});
			this->in_hp->ValueChanged += gcnew System::EventHandler(this, &custom_menu::in_hp_ValueChanged);
			// 
			// in_speed
			// 
			this->in_speed->BackColor = System::Drawing::Color::Black;
			this->in_speed->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->in_speed->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->in_speed->ForeColor = System::Drawing::Color::Maroon;
			this->in_speed->Location = System::Drawing::Point(477, 390);
			this->in_speed->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000000, 0, 0, 0});
			this->in_speed->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->in_speed->Name = L"in_speed";
			this->in_speed->Size = System::Drawing::Size(354, 22);
			this->in_speed->TabIndex = 22;
			this->in_speed->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, 0});
			this->in_speed->ValueChanged += gcnew System::EventHandler(this, &custom_menu::in_speed_ValueChanged);
			// 
			// in_dmg
			// 
			this->in_dmg->BackColor = System::Drawing::Color::Black;
			this->in_dmg->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->in_dmg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->in_dmg->ForeColor = System::Drawing::Color::Maroon;
			this->in_dmg->Location = System::Drawing::Point(476, 447);
			this->in_dmg->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000000, 0, 0, 0});
			this->in_dmg->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->in_dmg->Name = L"in_dmg";
			this->in_dmg->Size = System::Drawing::Size(354, 22);
			this->in_dmg->TabIndex = 23;
			this->in_dmg->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {40, 0, 0, 0});
			this->in_dmg->ValueChanged += gcnew System::EventHandler(this, &custom_menu::in_dmg_ValueChanged);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::Desktop;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(1280, 924);
			this->pictureBox2->TabIndex = 24;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(473, 472);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 20);
			this->label1->TabIndex = 25;
			this->label1->Text = L"Difficulty:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(473, 603);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 20);
			this->label6->TabIndex = 26;
			this->label6->Text = L"Map:";
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
			this->exit->Location = System::Drawing::Point(1233, 12);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(35, 32);
			this->exit->TabIndex = 27;
			this->exit->Text = L"X";
			this->exit->UseVisualStyleBackColor = false;
			this->exit->Click += gcnew System::EventHandler(this, &custom_menu::exit_Click);
			// 
			// warning_label
			// 
			this->warning_label->AutoSize = true;
			this->warning_label->BackColor = System::Drawing::Color::Transparent;
			this->warning_label->ForeColor = System::Drawing::Color::Red;
			this->warning_label->Location = System::Drawing::Point(847, 367);
			this->warning_label->Name = L"warning_label";
			this->warning_label->Size = System::Drawing::Size(201, 91);
			this->warning_label->TabIndex = 28;
			this->warning_label->Text = L"WARNING:\r\nToo high or low values might cause an\r\nunstable / unbalanced game-exper" 
				L"ience.\r\nRecommended values are:\r\nHealth: 100 - 5000\r\nSpeed: 10000 - 15000\r\nDamag" 
				L"e: 20 - 150";
			this->warning_label->Visible = false;
			// 
			// custom_menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1280, 924);
			this->Controls->Add(this->warning_label);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->in_dmg);
			this->Controls->Add(this->in_speed);
			this->Controls->Add(this->in_hp);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->diff);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->b_mprev);
			this->Controls->Add(this->b_mnext);
			this->Controls->Add(this->map_name);
			this->Controls->Add(this->map_display);
			this->Controls->Add(this->b_prev);
			this->Controls->Add(this->b_next);
			this->Controls->Add(this->skin_name);
			this->Controls->Add(this->skin_display);
			this->Controls->Add(this->pictureBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->Name = L"custom_menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"custom_menu";
			this->Load += gcnew System::EventHandler(this, &custom_menu::custom_menu_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &custom_menu::custom_menu_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->skin_display))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->map_display))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->in_hp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->in_speed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->in_dmg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void b_next_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->skinc++;
			 if(skinc>4) skinc=1;

			 switch(skinc) {
			 case 1 : {this->skin_display->Load("menuresource/splash_dementor.png");
					  this->skin_name->Text="Dementor";
					  break;}
			 case 2 : {this->skin_display->Load("menuresource/splash_altair.png");
					  this->skin_name->Text="Altair";
					  break;}
			 case 3 : {this->skin_display->Load("menuresource/splash_freeman.png");
					  this->skin_name->Text="Freeman";
					  break;}
			 case 4 : {this->skin_display->Load("menuresource/splash_ash.png");
					  this->skin_name->Text="Ash";
					  break;}
			 default: {this->skin_display->Load("menuresource/splash_dementor.png");
					  this->skin_name->Text="Dementor";
					  break;}
			 }
			 }
private: System::Void b_prev_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->skinc--;
			 if(skinc<1) skinc=4;

			 switch(skinc) {
			 case 1 : {this->skin_display->Load("menuresource/splash_dementor.png");
					  this->skin_name->Text="Dementor";
					  break;}
			 case 2 : {this->skin_display->Load("menuresource/splash_altair.png");
					  this->skin_name->Text="Altair";
					  break;}
			 case 3 : {this->skin_display->Load("menuresource/splash_freeman.png");
					  this->skin_name->Text="Freeman";
					  break;}
			 case 4 : {this->skin_display->Load("menuresource/splash_ash.png");
					  this->skin_name->Text="Ash";
					  break;}
			 default: {this->skin_display->Load("menuresource/splash_dementor.png");
					  this->skin_name->Text="Dementor";
					  break;}
			 }
		 }
private: System::Void custom_menu_Load(System::Object^  sender, System::EventArgs^  e) {
			this->skinc=1;
			//this->skin_display->Load("menuresource/splash_dementor.png");
			this->skin_name->Text="Dementor";

			this->mapc=1;
			//this->map_display->Load("menuresource/map_sp/splash_base.png");
			this->map_name->Text="Training Grounds";
			//Add maps and difficulty depending on player level
			allowedmaps=1;
			diff->Items->Add("Easy");
			if(p_level>BOGBEARD) {diff->Items->Add("Standard"); allowedmaps=2;}
			if(p_level>LYNWOOD) {allowedmaps=3; diff->Items->Add("Medium");}
			if(p_level>FIRELORD) {allowedmaps=4;}
			if(p_level>TERIDAX) {diff->Items->Add("Cheating"); allowedmaps=5;}
			if(p_level>BOT) {diff->Items->Add("Hard"); allowedmaps=6;}
			if(p_level>LANCE) {diff->Items->Add("Merciless"); allowedmaps=7;}
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 //set game settigns and start game
			 nextwindow=LOADING;
			 g_bothealth=(int)in_hp->Value;
			 g_botspeed=(int)in_speed->Value;
			 g_botfirepower=(int)in_dmg->Value;
			 g_botskin=ToSkin(skinc);
			 // If no difficulty was selected set it to Easy
			 if(diff->SelectedIndex!=-1) g_diff=StringToDiff(diff->SelectedItem->ToString());
			 else g_diff=EASY;
			 g_map=ToMap(mapc);
			 this->Close();
		 }
private: System::Void b_mnext_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->mapc++;
			 if(mapc>allowedmaps) mapc=1;

			 switch(mapc) {
			 case 1 : {this->map_display->Load("menuresource/map_sp/splash_base.png");
					  this->map_name->Text="Training Grounds";
					  break;}
			 case 2 : {this->map_display->Load("menuresource/map_sp/splash_forest.png");
					  this->map_name->Text="Sacred Forest";
					  break;}
			 case 3 : {this->map_display->Load("menuresource/map_sp/splash_desert.png");
					  this->map_name->Text="Enchanted Desert";
					  break;}
			 case 4 : {this->map_display->Load("menuresource/map_sp/splash_volcano.png");
					  this->map_name->Text="Forsaken Mountain";
					  break;}
			 case 5 : {this->map_display->Load("menuresource/map_sp/splash_crystal.png");
					  this->map_name->Text="Crystal Caves";
					  break;}
			 case 6 : {this->map_display->Load("menuresource/map_sp/splash_industrial.png");
					  this->map_name->Text="Darksteam Citadel";
					  break;}
			 case 7 : {this->map_display->Load("menuresource/map_sp/splash_arena.png");
					  this->map_name->Text="Skinc Arena";
					  break;}
			 default: {this->map_display->Load("menuresource/map_sp/splash_base.png");
					  this->map_name->Text="Training Grounds";
					  break;}
			 }
		 }
private: System::Void b_mprev_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->mapc--;
			 if(mapc<1) mapc=allowedmaps;

			 switch(mapc) {
			 case 1 : {this->map_display->Load("menuresource/map_sp/splash_base.png");
					  this->map_name->Text="Training Grounds";
					  break;}
			 case 2 : {this->map_display->Load("menuresource/map_sp/splash_forest.png");
					  this->map_name->Text="Sacred Forest";
					  break;}
			 case 3 : {this->map_display->Load("menuresource/map_sp/splash_desert.png");
					  this->map_name->Text="Enchanted Desert";
					  break;}
			 case 4 : {this->map_display->Load("menuresource/map_sp/splash_volcano.png");
					  this->map_name->Text="Forsaken Mountain";
					  break;}
			 case 5 : {this->map_display->Load("menuresource/map_sp/splash_crystal.png");
					  this->map_name->Text="Crystal Caves";
					  break;}
			 case 6 : {this->map_display->Load("menuresource/map_sp/splash_industrial.png");
					  this->map_name->Text="Darksteam Citadel";
					  break;}
			 case 7 : {this->map_display->Load("menuresource/map_sp/splash_arena.png");
					  this->map_name->Text="Skinc Arena";
					  break;}
			 default: {this->map_display->Load("menuresource/map_sp/splash_base.png");
					  this->map_name->Text="Training Grounds";
					  break;}
			 }
		 }
private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void custom_menu_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if(e->KeyCode == Keys::M){
				 std::cout<<"Changing FormBorderStyle"<<std::endl;
				 if(this->FormBorderStyle == System::Windows::Forms::FormBorderStyle::Sizable) this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
				 else this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
			 }
		 }
private: System::Void in_dmg_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(in_dmg->Value > 150 || in_dmg->Value < 20) this->warning_label->Visible = true;
			 else this->warning_label->Visible = false;
		 }
private: System::Void in_speed_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(in_speed->Value > 15000 || in_speed->Value < 10000) this->warning_label->Visible = true;
			 else this->warning_label->Visible = false;
		 }
private: System::Void in_hp_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(in_hp->Value > 5000 || in_hp->Value < 100) this->warning_label->Visible = true;
			 else this->warning_label->Visible = false;
		 }
};
}