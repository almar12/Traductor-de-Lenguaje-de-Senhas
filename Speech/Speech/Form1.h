#pragma once

#include "Funciones.h"
#include <string>
#include <msclr\marshal_cppstd.h>
using namespace std;
namespace Speech {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Speech::Synthesis;


	int datos[100][5];
	char ab[100];
	int cant;
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

		

		Form1(void)
		{
			InitializeComponent();
			PuertoSerial->Open();
			
			
			datos[0][0]=415;
			datos[0][1]=280;
			datos[0][2]=273;
			datos[0][3]=283;
			datos[0][4]=294;
			ab[0] = 'a';

			datos[1][0]=328;
			datos[1][1]=404;
			datos[1][2]=406;
			datos[1][3]=414;
			datos[1][4]=422;
			ab[1] ='b';

			
			datos[2][0]=367;
			datos[2][1]=341;
			datos[2][2]=340;
			datos[2][3]=342;
			datos[2][4]=388;
			ab[2] = 'c';
			

			cant =3;

			
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
			PuertoSerial->Close();
		}
		

	private: System::Windows::Forms::Button^  button1;
	private: System::IO::Ports::SerialPort^  PuertoSerial;
	private: System::Windows::Forms::TextBox^  texto;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  traduccion;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->PuertoSerial = (gcnew System::IO::Ports::SerialPort(this->components));
			this->texto = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->traduccion = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(70, 153);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(185, 71);
			this->button1->TabIndex = 0;
			this->button1->Text = L"LERR Y APRENDER";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// PuertoSerial
			// 
			this->PuertoSerial->PortName = L"COM12";
			// 
			// texto
			// 
			this->texto->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->texto->Location = System::Drawing::Point(26, 13);
			this->texto->Multiline = true;
			this->texto->Name = L"texto";
			this->texto->Size = System::Drawing::Size(267, 117);
			this->texto->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(440, 153);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(185, 71);
			this->button2->TabIndex = 2;
			this->button2->Text = L"TRADUCIR";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// traduccion
			// 
			this->traduccion->AutoSize = true;
			this->traduccion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->traduccion->Location = System::Drawing::Point(417, 36);
			this->traduccion->Name = L"traduccion";
			this->traduccion->Size = System::Drawing::Size(0, 42);
			this->traduccion->TabIndex = 3;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(772, 248);
			this->Controls->Add(this->traduccion);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->texto);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {







				 SpeechSynthesizer^ s = gcnew SpeechSynthesizer();
				
				 s->Speak("HELOu WE AR ERROR 404");
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

				 String^ l ;
				 l = PuertoSerial->ReadLine();
				 
				 msclr::interop::marshal_context context;
				 string p = context.marshal_as<string>(l);
				 //string t = p.substr(0,1);
				 //String^ ss = context.marshal_as<String^>(t);
				 //traduccion->Text = ss;
				 
				 int aux[5];
				 int i =0;
				 int pos;
				 int ant=0;
				 while(i<5)
				 {
					//pos = p.find("+",ant);
					aux[i] = atoi(p.substr(i*3,3).c_str());
					//ant = pos +1;
					i++;
				 }
				 
				 i=0;
				 while(i<cant)
				 {
					 if(Comparar(datos[i],aux))
					 {
						//SpeechSynthetizer^ s = gcnew SpeechSynthetizer();
						 //String^ po = gcnew String(ab[i]);
						 //p = context.marshal_as<String^>();
						 //traduccion->Text = po;
						switch(i)
						{
							case 0 : traduccion->Text="a";;
								break;
							case 1 : traduccion->Text="b";;
								break;
							case 2 : traduccion->Text="c";;
								break;
							default:traduccion->Text="";
						}
						 
						 break;
					 }
					 i++;
				 }

				 
				 

			 }
};
}

