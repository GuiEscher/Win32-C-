#define WIN32_LEAN_AND_MEAN 
#include <Windows.h>
#include <sstream>
using std::stringstream;

int APIENTRY WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

	//calculando o tamanho da tela com messagebox e getmetrics

	int resposta = MessageBox(NULL, "Vamos calcular o tamanho da tela?", "mensagem",
		MB_YESNO | MB_ICONQUESTION);//definição de botoes

	if (resposta == IDYES)//se o botao "SIM" for pressionado, entao
	{
		int cxscreen = GetSystemMetrics(SM_CXSCREEN);//função do tamanho da tela em x
		int cyscreen = GetSystemMetrics(SM_CYSCREEN);//função do tamanho da tela em y

		stringstream text;//criando string tipo cout

		text << "Resolução da tela: " << cxscreen << "x" << cyscreen;
		MessageBox(NULL, text.str().c_str(), "Tamanho da tela", MB_OK | MB_ICONINFORMATION);
						//transforma text em string e dps em uma string para ser usada na MBox
	}
	else {
		MessageBox(NULL, "O jogo necessita do tamanho da tela", "Aviso", MB_OK | MB_ICONERROR);
	}

}
