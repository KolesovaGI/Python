#pragma once
namespace Python {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ менюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ новаяИграаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ паузапродолжитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ настройкиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBoxGameData;
	private: System::Windows::Forms::Label^ labelScore;
	private: System::Windows::Forms::GroupBox^ groupBoxSettings;


	private: System::Windows::Forms::Button^ buttonApplySpeed;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownSpeed;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ LowerBorder;

	private: System::Windows::Forms::PictureBox^ UpperBorder;
	private: System::Windows::Forms::PictureBox^ RightBorder;
	private: System::Windows::Forms::PictureBox^ LeftBorder;
	private: System::Windows::Forms::Timer^ timer;




	private: System::Windows::Forms::Label^ labelGameOver;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->менюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->новаяИграаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->паузапродолжитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->настройкиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBoxGameData = (gcnew System::Windows::Forms::GroupBox());
			this->labelScore = (gcnew System::Windows::Forms::Label());
			this->groupBoxSettings = (gcnew System::Windows::Forms::GroupBox());
			this->buttonApplySpeed = (gcnew System::Windows::Forms::Button());
			this->numericUpDownSpeed = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->LowerBorder = (gcnew System::Windows::Forms::PictureBox());
			this->UpperBorder = (gcnew System::Windows::Forms::PictureBox());
			this->RightBorder = (gcnew System::Windows::Forms::PictureBox());
			this->LeftBorder = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelGameOver = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->groupBoxGameData->SuspendLayout();
			this->groupBoxSettings->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSpeed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LowerBorder))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UpperBorder))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RightBorder))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LeftBorder))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->менюToolStripMenuItem,
					this->справкаToolStripMenuItem, this->выходToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(750, 37);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// менюToolStripMenuItem
			// 
			this->менюToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->новаяИграаToolStripMenuItem,
					this->паузапродолжитьToolStripMenuItem, this->настройкиToolStripMenuItem
			});
			this->менюToolStripMenuItem->Name = L"менюToolStripMenuItem";
			this->менюToolStripMenuItem->Size = System::Drawing::Size(96, 33);
			this->менюToolStripMenuItem->Text = L"Меню";
			// 
			// новаяИграаToolStripMenuItem
			// 
			this->новаяИграаToolStripMenuItem->Name = L"новаяИграаToolStripMenuItem";
			this->новаяИграаToolStripMenuItem->Size = System::Drawing::Size(334, 38);
			this->новаяИграаToolStripMenuItem->Text = L"Новая игра";
			this->новаяИграаToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::новаяИграаToolStripMenuItem_Click);
			// 
			// паузапродолжитьToolStripMenuItem
			// 
			this->паузапродолжитьToolStripMenuItem->Name = L"паузапродолжитьToolStripMenuItem";
			this->паузапродолжитьToolStripMenuItem->Size = System::Drawing::Size(334, 38);
			this->паузапродолжитьToolStripMenuItem->Text = L"Пауза/продолжить";
			this->паузапродолжитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::паузапродолжитьToolStripMenuItem_Click);
			// 
			// настройкиToolStripMenuItem
			// 
			this->настройкиToolStripMenuItem->Name = L"настройкиToolStripMenuItem";
			this->настройкиToolStripMenuItem->Size = System::Drawing::Size(334, 38);
			this->настройкиToolStripMenuItem->Text = L"Настройки";
			this->настройкиToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::настройкиToolStripMenuItem_Click);
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(126, 33);
			this->справкаToolStripMenuItem->Text = L"Справка";
			this->справкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::справкаToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(101, 33);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::выходToolStripMenuItem_Click);
			// 
			// groupBoxGameData
			// 
			this->groupBoxGameData->BackColor = System::Drawing::Color::Peru;
			this->groupBoxGameData->Controls->Add(this->labelScore);
			this->groupBoxGameData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxGameData->ForeColor = System::Drawing::Color::White;
			this->groupBoxGameData->Location = System::Drawing::Point(12, 49);
			this->groupBoxGameData->Name = L"groupBoxGameData";
			this->groupBoxGameData->Size = System::Drawing::Size(445, 91);
			this->groupBoxGameData->TabIndex = 1;
			this->groupBoxGameData->TabStop = false;
			this->groupBoxGameData->Text = L"Данные игры";
			// 
			// labelScore
			// 
			this->labelScore->AutoSize = true;
			this->labelScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelScore->Location = System::Drawing::Point(6, 35);
			this->labelScore->Name = L"labelScore";
			this->labelScore->Size = System::Drawing::Size(110, 32);
			this->labelScore->TabIndex = 0;
			this->labelScore->Text = L"Счёт: 0";
			// 
			// groupBoxSettings
			// 
			this->groupBoxSettings->BackColor = System::Drawing::Color::BurlyWood;
			this->groupBoxSettings->Controls->Add(this->buttonApplySpeed);
			this->groupBoxSettings->Controls->Add(this->numericUpDownSpeed);
			this->groupBoxSettings->Controls->Add(this->label2);
			this->groupBoxSettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxSettings->Location = System::Drawing::Point(201, 224);
			this->groupBoxSettings->Name = L"groupBoxSettings";
			this->groupBoxSettings->Size = System::Drawing::Size(372, 125);
			this->groupBoxSettings->TabIndex = 2;
			this->groupBoxSettings->TabStop = false;
			this->groupBoxSettings->Text = L"Настройки";
			this->groupBoxSettings->Visible = false;
			// 
			// buttonApplySpeed
			// 
			this->buttonApplySpeed->Location = System::Drawing::Point(42, 75);
			this->buttonApplySpeed->Name = L"buttonApplySpeed";
			this->buttonApplySpeed->Size = System::Drawing::Size(275, 38);
			this->buttonApplySpeed->TabIndex = 3;
			this->buttonApplySpeed->Text = L"Применить";
			this->buttonApplySpeed->UseVisualStyleBackColor = true;
			this->buttonApplySpeed->Click += gcnew System::EventHandler(this, &GameForm::buttonApplySpeed_Click);
			// 
			// numericUpDownSpeed
			// 
			this->numericUpDownSpeed->Location = System::Drawing::Point(227, 34);
			this->numericUpDownSpeed->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericUpDownSpeed->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownSpeed->Name = L"numericUpDownSpeed";
			this->numericUpDownSpeed->Size = System::Drawing::Size(111, 35);
			this->numericUpDownSpeed->TabIndex = 1;
			this->numericUpDownSpeed->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(7, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(226, 29);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Введите скорость:";
			// 
			// LowerBorder
			// 
			this->LowerBorder->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->LowerBorder->Location = System::Drawing::Point(0, 891);
			this->LowerBorder->Name = L"LowerBorder";
			this->LowerBorder->Size = System::Drawing::Size(750, 5);
			this->LowerBorder->TabIndex = 3;
			this->LowerBorder->TabStop = false;
			// 
			// UpperBorder
			// 
			this->UpperBorder->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->UpperBorder->Location = System::Drawing::Point(0, 146);
			this->UpperBorder->Name = L"UpperBorder";
			this->UpperBorder->Size = System::Drawing::Size(750, 5);
			this->UpperBorder->TabIndex = 4;
			this->UpperBorder->TabStop = false;
			// 
			// RightBorder
			// 
			this->RightBorder->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->RightBorder->Location = System::Drawing::Point(745, 146);
			this->RightBorder->Name = L"RightBorder";
			this->RightBorder->Size = System::Drawing::Size(5, 750);
			this->RightBorder->TabIndex = 5;
			this->RightBorder->TabStop = false;
			// 
			// LeftBorder
			// 
			this->LeftBorder->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->LeftBorder->Location = System::Drawing::Point(0, 146);
			this->LeftBorder->Name = L"LeftBorder";
			this->LeftBorder->Size = System::Drawing::Size(5, 750);
			this->LeftBorder->TabIndex = 6;
			this->LeftBorder->TabStop = false;
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &GameForm::GameForm_Update);
			// 
			// labelGameOver
			// 
			this->labelGameOver->AutoSize = true;
			this->labelGameOver->BackColor = System::Drawing::Color::BurlyWood;
			this->labelGameOver->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelGameOver->ForeColor = System::Drawing::Color::Red;
			this->labelGameOver->Location = System::Drawing::Point(262, 175);
			this->labelGameOver->Name = L"labelGameOver";
			this->labelGameOver->Size = System::Drawing::Size(263, 46);
			this->labelGameOver->TabIndex = 7;
			this->labelGameOver->Text = L"GAME OVER";
			this->labelGameOver->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->labelGameOver->Visible = false;
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(750, 896);
			this->Controls->Add(this->labelGameOver);
			this->Controls->Add(this->LeftBorder);
			this->Controls->Add(this->RightBorder);
			this->Controls->Add(this->UpperBorder);
			this->Controls->Add(this->LowerBorder);
			this->Controls->Add(this->groupBoxSettings);
			this->Controls->Add(this->groupBoxGameData);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"GameForm";
			this->RightToLeftLayout = true;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Python";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GameForm::GameForm_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBoxGameData->ResumeLayout(false);
			this->groupBoxGameData->PerformLayout();
			this->groupBoxSettings->ResumeLayout(false);
			this->groupBoxSettings->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSpeed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LowerBorder))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UpperBorder))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RightBorder))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LeftBorder))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// Данные игры
	private: PictureBox^ fruit; // фрукт
	private: array<PictureBox^>^ Serpens; // змея
	private: System::Media::SoundPlayer^ soundEat; // звук жевания
	private: bool play; // играть
	private: bool die; // смерть
	private: bool firstLaunch; // первый запуск
	private: int step = 10; // шаг
	private: float updateInterval = 100; // интервал обновления
	private: int score = 0; // счёт

	// Действия игры
	private: void GeneratePositionFruit(); // Генерация позиции фрукта
	private: void Eating(); // Питон съедает фрукт
	private: void Movement(); // Движение Питона
	private: void EatYourself(); // Питон съел себя
	private: void GameOver(); // Конец игры
	private: void NewGame(); // Новая игра
	private: void CheckBorders(); // Проверка, не врезалась ли змейка в бортики
	private: void SoundPlay(); // Воспроизведение аудио

	// Обработчики нажатия на кнопки

	private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void справкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void новаяИграаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void паузапродолжитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void настройкиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonApplySpeed_Click(System::Object^ sender, System::EventArgs^ e); 

	// Отслеживание нажатой клавиши
	private: System::Void GameForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);

	// Событие обновления игры
	private: void GameForm_Update(Object^ obgect, EventArgs^ e);
};
}
