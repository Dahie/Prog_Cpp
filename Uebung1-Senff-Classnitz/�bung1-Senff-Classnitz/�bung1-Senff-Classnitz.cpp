// �bung1-Senff-Classnitz.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include "Form1.h"

using namespace �bung1SenffClassnitz;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Aktivieren visueller Effekte von Windows XP, bevor Steuerelemente erstellt werden
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Hauptfenster erstellen und ausf�hren
	Application::Run(gcnew Form1());
	return 0;
}
