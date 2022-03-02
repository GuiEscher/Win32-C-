#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

//Criando uma janela no windows

//Protótipo do winProcedure
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

//programa principal
int APIENTRY WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	HWND     hwnd; //identificador da janela
	MSG      msg;   //mensagem
	WNDCLASS wndclass;//classe da janela

	//definindo a classe da janela "janela simples"

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WinProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = "Janela simples";

	//verificando e registrando a classe 
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, "Erro na criação da janela", "Aviso", MB_ICONERROR);
		return 0;
	}
	//criando a janela
	hwnd = CreateWindow("Janela simples",		//Nome da janela
		"Aplicação",		    //título
		WS_OVERLAPPEDWINDOW,    //Estilo da janela
		CW_USEDEFAULT,			//Posição x inicio
		CW_USEDEFAULT,			//posição y inicio
		CW_USEDEFAULT,			//largura inicial
		CW_USEDEFAULT,			//altura inicial
		NULL,					//identificador janela pai
		NULL,					//identificador do menu
		hInstance,				//identificador da aplicação
		NULL);					//parâmetros de aplicação

	//Exibe a janela
	ShowWindow(hwnd, nCmdShow);
	//redesenha a janela
	UpdateWindow(hwnd);
	//tratando as mensagens
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return int(msg.wParam);
}


//--------------------------------------------------------------------

//Procedure da janela (foi chamado no inicio do programa)
LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	HDC        hdc;  //dispositivo gráfico
	PAINTSTRUCT ps;   //Região a ser repintada/invalidada
	RECT       rect; //região da janela (retangular)

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, "Janelinha simples", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
