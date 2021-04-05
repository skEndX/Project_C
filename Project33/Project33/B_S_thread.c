// Ÿ�̸Ӹ� �߻�����, �׶����� ��ƽ�� ���� ��ġ�� ����ϴ�(���ӵ� ���� ��������) �ٿ ������ ���α׷�

#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
DWORD WINAPI ThreadFunc(LPVOID prc);
void DoCreateMain(HWND hWnd);
void DoButtonMain(HWND hWnd);
void DoPaintMain(HWND hWnd);
void OnTimer(HWND hWnd);

#define R 20
#define BOUNCE 1
#define W 20
#define H 200

HBITMAP hBit;
HINSTANCE g_hInst;
HWND hWndMain, hWnd2;
HANDLE hThread;
LPCTSTR lpszClass = TEXT("Bounce");

RECT crt;
int x, y;
int xv, yv;
int flag = 0;
int btnflag = 0;

int sX[2];
int sY[2];

float sXv[2];
float sYv[2];


struct trans_struct {
	int x;
	int y;
	int xv;
	int yv;
}trans_struct;


void moveStick();
void moveBall();
void collision();

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_BORDER | WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT, 600, 600,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	hWndMain = hWnd;

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	COPYDATASTRUCT *pcds;

	switch (iMessage) {

	case WM_CREATE:
		DoCreateMain(hWnd);
		break;
	case WM_PAINT:
		DoPaintMain(hWnd);
		break;
	case WM_LBUTTONDOWN:
		DoButtonMain(hWnd);
		break;
	case WM_TIMER:
		OnTimer(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		KillTimer(hWnd, 0);
		CloseHandle(hThread);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

/* �߰� �ڵ� �κ� */
//////////////////////////////////////////////////////////////////////////////////////////////////////
DWORD WINAPI ThreadMovingBall(PVOID pArg) {
	Sleep(100);
	while (1) {
		Sleep(30);
		moveBall();
	}
}

DWORD WINAPI ThreadStick(PVOID pArg) {
	Sleep(100);
	while (1) {
		Sleep(30);
		moveStick();
	}
}


void DoCreateMain(HWND hWnd)
{
	GetClientRect(hWnd, &crt);

	x = 80;	//���� x ��ǥ �ʱⰪ
	y = 250;//���� y ��ǥ �ʱⰪ

	xv = (rand() % 4) + 5; //x���� �ӵ�
	yv = (rand() % 4) + 5; //y���� �ӵ�


	sX[0] = 0; sY[0] = H; //���� ��ƽ �ʱⰪ
	sXv[0] = 210; sYv[0] = 5; //���� ��ƽ �ӵ�

	sX[1] = crt.right - W; sY[1] = H - 50; //������ ��ƽ �ʱⰪ
	sXv[1] = 110; sYv[1] = 10; //������ ��ƽ �ӵ�

	/* �߰� �ڵ� �κ� */
	HANDLE hThreadMovingBall = CreateThread(NULL, 0, ThreadMovingBall, (PVOID)hWndMain, 0, NULL);
	HANDLE hThreadStick = CreateThread(NULL, 0, ThreadStick, (PVOID)hWndMain, 0, NULL);

	CloseHandle(hThreadMovingBall);
	CloseHandle(hThreadStick);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////

void DoPaintMain(HWND hWnd)
{
	HDC hdc, hMemDC;
	PAINTSTRUCT ps;
	HBITMAP OldBit;

	hdc = BeginPaint(hWnd, &ps);

	hMemDC = CreateCompatibleDC(hdc);
	OldBit = (HBITMAP)SelectObject(hMemDC, hBit);
	BitBlt(hdc, 0, 0, crt.right, crt.bottom, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, OldBit);
	DeleteDC(hMemDC);
	EndPaint(hWnd, &ps);
	return;
}

void DoButtonMain(HWND hWnd)
{
	if (btnflag == 0) {
		MessageBox(hWnd, TEXT("���α׷��� ����Ǿ����ϴ�."), TEXT("OK"), MB_OK);
		SetTimer(hWnd, 1, 25, NULL);
	}
	if (btnflag > 0) {
		x = 250;
		y = 200;
		xv *= -(BOUNCE);
		flag = 0;
	}
	btnflag = 1;

}

void OnTimer(HWND hWnd)
{
	TCHAR str[123];
	HDC hdc, hMemDC;
	HBITMAP OldBit;
	HPEN hPen, OldPen;
	HBRUSH hBrush, OldBrush;

	hdc = GetDC(hWnd);
	GetClientRect(hWnd, &crt);
	if (hBit == NULL)
	{
		hBit = CreateCompatibleBitmap(hdc, crt.right, crt.bottom);
	}
	hMemDC = CreateCompatibleDC(hdc);
	OldBit = (HBITMAP)SelectObject(hMemDC, hBit);

	FillRect(hMemDC, &crt, GetSysColorBrush(COLOR_WINDOW));

	hPen = CreatePen(PS_INSIDEFRAME, 2, RGB(0, 0, 0));
	OldPen = (HPEN)SelectObject(hMemDC, hPen);
	hBrush = CreateSolidBrush(RGB(255, 120, 0));
	OldBrush = (HBRUSH)SelectObject(hMemDC, hBrush);
	Ellipse(hMemDC, x - R, y - R, x + R, y + R);	 //���׸���


	hBrush = CreateSolidBrush(RGB(255, 255, 0));
	OldBrush = (HBRUSH)SelectObject(hMemDC, hBrush);
	Rectangle(hMemDC, sX[0], sY[0], sX[0] + W, sY[0] + H); //��ƽ �׸���
	Rectangle(hMemDC, sX[1], sY[1], sX[1] + W, sY[1] + H); //��ƽ �׸���


	DeleteObject(SelectObject(hMemDC, OldPen));
	DeleteObject(SelectObject(hMemDC, OldBrush));

	wsprintf(str, TEXT("%d, %d, %d, %d"), x, y, xv, yv);
	TextOut(hMemDC, 100, 50, str, lstrlen(str));


	SelectObject(hMemDC, OldBit);
	DeleteDC(hMemDC);
	ReleaseDC(hWnd, hdc);
	InvalidateRect(hWnd, NULL, FALSE);

	moveStick(); //��ƽ�� ������
	moveBall();  //���� ������
	collision();



}


void moveBall()
{
	if (y <= R || y >= crt.bottom - R) {
		yv *= -(BOUNCE);
		if (y <= R) y = R;
		if (y >= crt.bottom - R) y = crt.bottom - R;
	}
	x += (int)xv;
	y += (int)yv;

}
void moveStick()
{
	RECT crt;
	GetClientRect(hWndMain, &crt);
	if (sY[0] <= 0 || sY[0] >= crt.bottom - H)
	{
		sYv[0] *= -1;
	}

	if (sY[1] <= 0 || sY[1] >= crt.bottom - H)
	{
		sYv[1] *= -1;
	}

	sY[0] += sYv[0];
	sY[1] += sYv[1];

}
void collision()
{
	if (flag == 0)
	{

		if (x < W + R && y > sY[0] - R && y < sY[0] + H + R)
		{
			x += R / 2;
			xv *= (-BOUNCE);
		}
		if (x >= crt.right - R - W && y > sY[1] - R && y < sY[1] + H + R)
		{
			x -= R / 2;
			xv *= (-BOUNCE);
		}
	}

	if (x < crt.left - R || x > crt.right + R) //��� ���
	{
		flag = 1;
	}
}


