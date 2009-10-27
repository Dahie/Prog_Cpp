// Task1.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include "Form1.h"
   #include <id3/tag.h>


using namespace Task1;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Aktivieren visueller Effekte von Windows XP, bevor Steuerelemente erstellt werden
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Hauptfenster erstellen und ausführen
	Application::Run(gcnew Form1());
	return 0;
}
