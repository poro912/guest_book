#include "GB_moudles.h"

// ���� �ΰ�

// // ���� ũ��
#define Main_Logo_Width 300
#define Main_Logo_Height 298

// ���� ���� X Y ��ǥ
#define Main_Logo_X (1420 / 2)- (Main_Logo_Width / 2)
#define Main_Logo_Y (900 / 2) - (Main_Logo_Height / 2)



// ���� �ΰ�

// �ΰ� ũ��
#define Serve_Logo_Width 200
#define Serve_Logo_Height 48


// �ΰ� ���� X Y ��ǥ
#define Serve_Logo_X 1420 - Serve_Logo_Width - 100
#define Serve_Logo_Y 900 - Serve_Logo_Height - 10 - 200


// �α� ����
#define Logo_Transparency 60





void Drawlogo(HINSTANCE hInst, HDC hdc, int xDest, int yDest, int wDest, int hDest,int i);