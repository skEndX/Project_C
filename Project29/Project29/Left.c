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
HWND hWndMain, hWnd;
HANDLE hThread;
LPCTSTR lpszClass = TEXT("Left");

RECT crt;
int x, y;
int xv, yv;
int flag = 1;	//ó�� ������ ��, ���� �������� �ʵ��� ����
int btnflag = 0;

//int sX[2];
//int sY[2];
//
//float sXv[2];
//float sYv[2];

typedef struct trans_struct {
	int x;
	int y;
	int xv;
	int yv;
}trans_struct;

//void moveStick();	������ �ʿ���� ������ �ּ�ó��
void moveBall();
void collision(HWND hWnd);

trans_struct ball_data;
COPYDATASTRUCT pcds;	//����ȭ�� �� �ֵ��� COPTDATASTRUCT ���
COPYDATASTRUCT *c_data;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPc_dataInstance, LPSTR lpszCmdParam, int nCmdShow) {
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
	switch (iMessage) {
	case WM_COPYDATA:
		c_data = (COPYDATASTRUCT *)lParam;	//COPYDATASTRUCT ����Ͽ� ����ȭ
		x = ((trans_struct *)(c_data->lpData))->x;
		y = ((trans_struct *)(c_data->lpData))->y;
		xv = ((trans_struct *)(c_data->lpData))->xv;
		yv = ((trans_struct *)(c_data->lpData))->yv;
		flag = 0;
		break;
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

DWORD WINAPI ThreadMovingBall(PVOID pArg) {
	Sleep(100);
	while (1) {
		Sleep(30);
		if (flag == 0) {
			moveBall();
		}
	}
}

void DoCreateMain(HWND hWnd)
{
	GetClientRect(hWnd, &crt);

	x = -20;
	y = 250;//���� y ��ǥ �ʱⰪ

	xv = (rand() % 4) + 5; //x���� �ӵ�
	yv = (rand() % 4) + 5; //y���� �ӵ�

	//sX[0] = 0; sY[0] = H; //���� ��ƽ �ʱⰪ
	//sXv[0] = 210; sYv[0] = 5; //���� ��ƽ �ӵ�

	//sX[1] = crt.right - W; sY[1] = H - 50; //������ ��ƽ �ʱⰪ
	//sXv[1] = 110; sYv[1] = 10; //������ ��ƽ �ӵ�

	HANDLE hThreadMovingBall = CreateThread(NULL, 0, ThreadMovingBall, (PVOID)hWndMain, 0, NULL);
	CloseHandle(hThreadMovingBall);
}

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
	Ellipse(hMemDC, x - R, y - R, x + R, y + R);    //���׸���

	//hBrush = CreateSolidBrush(RGB(255, 255, 0));
	//OldBrush = (HBRUSH)SelectObject(hMemDC, hBrush);
	//Rectangle(hMemDC, sX[0], sY[0], sX[0] + W, sY[0] + H); //��ƽ �׸���
	//Rectangle(hMemDC, sX[1], sY[1], sX[1] + W, sY[1] + H); //��ƽ �׸���

	DeleteObject(SelectObject(hMemDC, OldPen));
	DeleteObject(SelectObject(hMemDC, OldBrush));

	wsprintf(str, TEXT("%d, %d, %d, %d"), x, y, xv, yv);
	TextOut(hMemDC, 100, 50, str, lstrlen(str));

	SelectObject(hMemDC, OldBit);
	DeleteDC(hMemDC);
	ReleaseDC(hWnd, hdc);
	InvalidateRect(hWnd, NULL, FALSE);

	//moveStick(); //��ƽ�� ������
	//moveBall();  //���� ������
	collision(hWnd);
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

//void moveStick()
//{
//	RECT crt;
//	GetClientRect(hWndMain, &crt);
//	if (sY[0] <= 0 || sY[0] >= crt.bottom - H)
//	{
//		sYv[0] *= -1;
//	}
//
//	if (sY[1] <= 0 || sY[1] >= crt.bottom - H)
//	{
//		sYv[1] *= -1;
//	}
//
//	sY[0] += sYv[0];
//	sY[1] += sYv[1];
//
//}

void collision(HWND hWnd)
{
	if (flag == 0) {
		//����, ��, �Ʒ� ����
		if (x < R && y >= -R && y <= crt.bottom + R) {
			x += R / 2;
			xv *= (-BOUNCE);
		}

		//���������� ��� ���
		if (x > crt.right + R) {
			flag = 1;
			ball_data.x = x - 600;
			ball_data.y = y;
			ball_data.xv = xv;
			ball_data.yv = yv;
			pcds.lpData = &ball_data;
			pcds.cbData = sizeof(ball_data);
			pcds.dwData = "201801730 KimDaHee";

			HWND find_w = FindWindow(NULL, TEXT("Right"));
			SendMessage(find_w, WM_COPYDATA, (WPARAM)hWnd, (LPARAM)&pcds);
		}
	}
}