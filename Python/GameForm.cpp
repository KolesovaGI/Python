#include <iostream>
#include <Windows.h>
#include <vector>
#include "GameForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args)
{	// Базовые настройки для запуска формы
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Запуск указанной формы
	Python::GameForm form;
	Application::Run(% form);
}

// Структура, которую удобно использовать в 2д пространстве
struct Vector2
{
	int X, Y;
};

Vector2 direction; // Направление змейки
Vector2 positionFruit; // Позиция фрукта
Vector2 gameArea; // Игровая зона

/// <summary>
/// Конструктор формы
/// </summary>
Python::GameForm::GameForm(void)
{
	InitializeComponent();

	// Задаётся размер игровой зоны
	gameArea.X = 500;
	gameArea.Y = 500;

	firstLaunch = true; // Первый запуск
	NewGame(); // Запуск новой игры
}

/// <summary>
/// Генерация позиции фрукта
/// </summary>
void Python::GameForm::GeneratePositionFruit()
{
	// Генерация случайной позиции фрукта
	Random^ rand = gcnew Random();
	positionFruit.X = rand->Next(17, gameArea.X); // 17 - смещение относительно боковых границ формы 
	positionFruit.Y = rand->Next(150, gameArea.Y); // 150 - смещение относительно верхней границы формы

	// Проверка, чтобы  фрукты не генерировались на теле змейки
	for (int i = 0; i < score; i++) // Проход по всем элементам змейки 
	{
		if (positionFruit.X == Serpens[i]->Location.X &&
			positionFruit.Y == Serpens[i]->Location.Y) // Если при создании фрукта местоположение совпало со змейкой
		{
			GeneratePositionFruit(); // Фрукт пересоздаётся
		}
	}

	// Преобразование текущей позиции фрукта, относительно шага змейки
	int tempX = positionFruit.X % step;
	positionFruit.X -= tempX;

	int tempY = positionFruit.Y % step;
	positionFruit.Y -= tempY;

	// Присваивание фрукту позиции
	fruit->Location = Point(positionFruit.X, positionFruit.Y);

	// Добавление фрукта на карту
	this->Controls->Add(fruit);
}

/// <summary>
/// Реализация поедания поедания фрукта
/// </summary>
void Python::GameForm::Eating()
{
	// Проверка позиции головы змеи и позиции фрукта
	if (Serpens[0]->Location.X == positionFruit.X && Serpens[0]->Location.Y == positionFruit.Y) // Если голова совпадает по позиции с фруктом
	{
		labelScore->Text = "Счёт: " + ++score; // Увеличивается счёт

		// Добавление нового элемента в хвост змейки
		Serpens[score] = gcnew PictureBox(); // Инициализация нового элемента
		Serpens[score]->Location = Point(Serpens[score - 1]->Location.X + step * direction.X, Serpens[score - 1]->Location.Y - step * direction.Y); // задать позицию относительно позиции предыдущего элменета + шаг и направление
		Serpens[score]->BackColor = Color::Red; // цвет
		Serpens[score]->Width = step; // ширина
		Serpens[score]->Height = step; // высота
		this->Controls->Add(Serpens[score]); // добавление нового элемента хвоста на поле

		SoundPlay(); // Звук питья
		GeneratePositionFruit(); // Сгенерировать новый фрукт (воду)
	}
}

/// <summary>
/// Реализация движения змейки
/// </summary>
void Python::GameForm::Movement()
{
	// Двигать каждый элемент змейки
	for (int i = score; i >= 1; i--) // проход от последнего элемента к предпоследнему с начала
	{
		Serpens[i]->Location = Serpens[i - 1]->Location; // Каждый элемент змейки = позиции предыдущего
	}

	Serpens[0]->Location = Point(Serpens[0]->Location.X + direction.X * step, Serpens[0]->Location.Y + direction.Y * step); // Голова змейки + новая позиция относительно старой + направление * на шаг
}

/// <summary>
/// Проверка на самосъедение
/// </summary>
void Python::GameForm::EatYourself()
{
	// проход по змейке
	for (int i = 1; i < score; i++) 
	{
		if (Serpens[0]->Location == Serpens[i]->Location) // Если голова попала локацией с хвостом
		{
			GameOver(); // игра окончена
		}
	}
}

/// <summary>
/// Конец игрры
/// </summary>
void Python::GameForm::GameOver()
{
	play = true;
	die = true;

	labelGameOver->Visible = true;
}

/// <summary>
/// Запуск новой игры
/// </summary>
void Python::GameForm::NewGame()
{
	// если игра не первая, с карты удаляются все объекты
	if (!firstLaunch) 
	{
		this->Controls->Remove(fruit);

		for (int i = 0; i <= score; i++)
		{
			this->Controls->Remove(Serpens[i]);
		}

		score = 0;
	}

	else
	{
		firstLaunch = false;
	}

	// Инициализация змейки
	Serpens = gcnew array <PictureBox^, 1>(400);
	Serpens[0] = gcnew PictureBox();
	Serpens[0]->Location = Point(200, 200);
	Serpens[0]->BackColor = Color::DarkRed;
	Serpens[0]->Width = step;
	Serpens[0]->Height = step;
	score = 0;

	this->Controls->Add(Serpens[0]);

	// Инициализация фрукта
	fruit = gcnew PictureBox();
	fruit->BackColor = Color::SkyBlue;
	fruit->Width = step;
	fruit->Height = step;
	GeneratePositionFruit();

	// задать интервал обновления и запустить таймер для обновления
	timer->Interval = updateInterval;
	timer->Start();

	// задать направление при запуске
	direction.X = 1;
	direction.Y = 0;

	play = true;
	die = false;

	labelScore->Text = "Счёт: 0";

	labelGameOver->Visible = false;
	groupBoxSettings->Visible = false;
}

/// <summary>
/// Проверка на столкновение с бортиками
/// </summary>
void Python::GameForm::CheckBorders()
{
	if (Serpens[0]->Location.X >= RightBorder->Location.X || Serpens[0]->Location.X <= LeftBorder->Location.X) // Если змейка врезалась в бортик
	{
		direction.X *= -2; // Развернуть в обратном направлении и вдвое увеличить скорость
	}

	if (Serpens[0]->Location.Y <= UpperBorder->Location.Y || Serpens[0]->Location.Y >= LowerBorder->Location.Y) // Если змейка врезалась в бортик
	{
		direction.Y *= -2; // Развернуть в обратном направлении и вдвое увеличить скорость
	}
}

/// <summary>
/// Воспроизведение звуков
/// </summary>
void Python::GameForm::SoundPlay()
{
	soundEat = gcnew System::Media::SoundPlayer("..\\Resources\\3.wav");
	soundEat->Play();
}

/// <summary>
/// Обработник нажатия на "Выход"
/// </summary>
System::Void Python::GameForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

/// <summary>
/// Обработник нажатия на "Спарвка"
/// </summary>
System::Void Python::GameForm::справкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Правила игры в Питона:\n1. Для управления движением Питона используйте соответствующие стрелки;\n2. Вам нужно съесть наибольшее количество фруктов;\n3. Если Питон съест себя - конец игры;\n4. Если Питон врежется в ограждение - его скорость увеличится вдвое;");

	return System::Void();
}

/// <summary>
/// Обработчик нажатия на "Новая игра"
/// </summary>
System::Void Python::GameForm::новаяИграаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	NewGame();

	return System::Void();
}

/// <summary>
/// Обработчик нажжатия на паузу
/// </summary>
System::Void Python::GameForm::паузапродолжитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (play) // если игра идёт
	{
		play = false; // игра останавливается
	}
	else // если игра стоит на паузе
	{
		play = true; // игра запускается
		timer->Start(); // таймер запускается
	}

	return System::Void();
}

/// <summary>
/// Обработчик нажатия на "Настройки"
/// </summary>
System::Void Python::GameForm::настройкиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (groupBoxSettings->Visible == false) 
	{
		play = false;

		buttonApplySpeed->Enabled = true;
		numericUpDownSpeed->Enabled = true;
		groupBoxSettings->Visible = true;
	}

	else 
	{
		play = true;
		timer->Start();

		buttonApplySpeed->Enabled = false;
		numericUpDownSpeed->Enabled = false;
		groupBoxSettings->Visible = false;
	};
}

/// <summary>
/// Обработчик нажатия на кнопку управления скоростью
/// </summary>
System::Void Python::GameForm::buttonApplySpeed_Click(System::Object^ sender, System::EventArgs^ e)
{
	updateInterval = Convert::ToSingle(numericUpDownSpeed->Value);
	timer->Interval = updateInterval;

	buttonApplySpeed->Enabled = false;
	numericUpDownSpeed->Enabled = false;
	groupBoxSettings->Visible = false;

	play = true;
	timer->Start();

	return System::Void();
}

/// <summary>
/// Обработчик считывания кнопок, отвечающих за управление движением змейки
/// </summary>
System::Void Python::GameForm::GameForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode.ToString() == "Right") 
	{
		direction.X = 1;
		direction.Y = 0;
	}

	else if (e->KeyCode.ToString() == "Left") 
	{
		direction.X = -1;
		direction.Y = 0;
	}

	else if (e->KeyCode.ToString() == "Up") 
	{
		direction.Y = -1;
		direction.X = 0;
	}

	else if (e->KeyCode.ToString() == "Down") 
	{
		direction.Y = 1;
		direction.X = 0;
	}

	return System::Void();
}

/// <summary>
/// Обновление игрового окна
/// </summary>
void Python::GameForm::GameForm_Update(Object^ obgect, EventArgs^ e)
{
	if (!die && play) // если змейка не погибла и игра продолжается
	{
		Movement(); // змейка двигается
		Eating(); // змейка ест
		EatYourself(); // проверка, не съела ли змейка себя
		CheckBorders(); // проверка столкновения с бортиками
	}

	else if (die && play) // если змейка умерла
	{
		timer->Stop(); // таймер останавливается
		MessageBox::Show("GAME OVER"); // сообщение о конце игры
	}

	else if (!play && !die) // если игра не идет и змейка ещё жива
	{
		timer->Stop(); // таймер останавливается
		MessageBox::Show("STOP"); // сообщение о паузе
	}
}
