﻿
// ImageProcessing_20212155View.cpp: CImageProcessing20212155View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageProcessing_20212155.h"
#endif

#include "ImageProcessing_20212155Doc.h"
#include "ImageProcessing_20212155View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProcessing20212155View

IMPLEMENT_DYNCREATE(CImageProcessing20212155View, CScrollView)

BEGIN_MESSAGE_MAP(CImageProcessing20212155View, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CImageProcessing20212155View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_PIXEL_ADD, &CImageProcessing20212155View::OnPixelAdd)
	ON_COMMAND(ID_PIXEL_SUB, &CImageProcessing20212155View::OnPixelSub)
	ON_COMMAND(ID_PIXEL_MUL, &CImageProcessing20212155View::OnPixelMul)
	ON_COMMAND(ID_PIXEL_DIV, &CImageProcessing20212155View::OnPixelDiv)
	ON_COMMAND(ID_PIXEL_HISTO_EQ, &CImageProcessing20212155View::OnPixelHistoEq)
	ON_COMMAND(ID_PIXEL_CONTRAST_STRETCHING, &CImageProcessing20212155View::OnPixelContrastStretching)
	ON_COMMAND(ID_PIXEL_BINARIZATION, &CImageProcessing20212155View::OnPixelBinarization)
	ON_COMMAND(ID_PIXEL_TWO_IMAGE_ADD, &CImageProcessing20212155View::OnPixelTwoImageAdd)
	ON_COMMAND(ID_PIXEL_TWO_IMAGE_SUB, &CImageProcessing20212155View::OnPixelTwoImageSub)
	ON_COMMAND(ID_REGION_SHARPENING, &CImageProcessing20212155View::OnRegionSharpening)
	ON_COMMAND(ID_REGION_SMOOTHING, &CImageProcessing20212155View::OnRegionSmoothing)
	ON_COMMAND(ID_REGION_EMBOSSING, &CImageProcessing20212155View::OnRegionEmbossing)
	ON_COMMAND(ID_REGION_PREWITT, &CImageProcessing20212155View::OnRegionPrewitt)
	ON_COMMAND(ID_REGION_ROBERTS, &CImageProcessing20212155View::OnRegionRoberts)
	ON_COMMAND(ID_REGION_SOBEL, &CImageProcessing20212155View::OnRegionSobel)
	ON_COMMAND(ID_REGION_AVERAGE_FILTERING, &CImageProcessing20212155View::OnRegionAverageFiltering)
	ON_COMMAND(ID_REGION_MEDIAN_FILTERING, &CImageProcessing20212155View::OnRegionMedianFiltering)
	ON_COMMAND(ID_MOPOLOGY_COLOR_TO_GRAY, &CImageProcessing20212155View::OnMopologyColorToGray)
	ON_COMMAND(ID_MOPOLOGY_BINARIZATION, &CImageProcessing20212155View::OnMopologyBinarization)
	ON_COMMAND(ID_MOPOLOGY_EROSION, &CImageProcessing20212155View::OnMopologyErosion)
	ON_COMMAND(ID_MOPOLOGY_DILATION, &CImageProcessing20212155View::OnMopologyDilation)
END_MESSAGE_MAP()

// CImageProcessing20212155View 생성/소멸

CImageProcessing20212155View::CImageProcessing20212155View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImageProcessing20212155View::~CImageProcessing20212155View()
{
}

BOOL CImageProcessing20212155View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CImageProcessing20212155View 그리기

void CImageProcessing20212155View::OnDraw(CDC* pDC)
{
	CImageProcessing20212155Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int x, y;

	if (pDoc->inputImage != NULL) {
		if (pDoc->depth == 1) {	//흑백일 때
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(x, y, RGB(pDoc->inputImage[y][x], pDoc->inputImage[y][x], pDoc->inputImage[y][x]));
		}
		else {	//컬러일 때
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(x, y, RGB(pDoc->inputImage[y][x * 3 + 0], pDoc->inputImage[y][x * 3 + 1], pDoc->inputImage[y][x * 3 + 2]));
		}
		
	}

	if (pDoc->resultImage != NULL) {
		if (pDoc->depth == 1) {	//흑백일 때 
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(pDoc->imageWidth + 20 + x, y, RGB(pDoc->resultImage[y][x], pDoc->resultImage[y][x], pDoc->resultImage[y][x]));
		}
		else {	//컬러일 때
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(pDoc->imageWidth + 20 + x, y, RGB(pDoc->resultImage[y][x * 3 + 0], pDoc->resultImage[y][x * 3 + 1], pDoc->resultImage[y][x * 3 + 2]));
		}
	}

	if (pDoc->inputImage2 != NULL) {
		if (pDoc->depth == 1) {	//흑백일 때
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(2 * (pDoc->imageWidth + 20) + x, y, RGB(pDoc->inputImage2[y][x], pDoc->inputImage2[y][x], pDoc->inputImage2[y][x]));
		}
		else {	//컬러일 때
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(2 * (pDoc->imageWidth + 20) + x, y, RGB(pDoc->inputImage2[y][x * 3 + 0], pDoc->inputImage2[y][x * 3 + 1], pDoc->inputImage2[y][x * 3 + 2]));
		}
	}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CImageProcessing20212155View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = 2048; // 수정된 코드
	sizeTotal.cy = 1024; // 수정된 코드
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CImageProcessing20212155View 인쇄


void CImageProcessing20212155View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CImageProcessing20212155View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImageProcessing20212155View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImageProcessing20212155View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CImageProcessing20212155View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CImageProcessing20212155View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CImageProcessing20212155View 진단

#ifdef _DEBUG
void CImageProcessing20212155View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CImageProcessing20212155View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CImageProcessing20212155Doc* CImageProcessing20212155View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcessing20212155Doc)));
	return (CImageProcessing20212155Doc*)m_pDocument;
}
#endif //_DEBUG


// CImageProcessing20212155View 메시지 처리기


void CImageProcessing20212155View::OnPixelAdd()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();
	if (pDoc->inputImage == NULL) return;

	int x, y;
	int value;
	for (y = 0; y < pDoc->imageHeight; y++) {
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {	 //흑백 이미지
				value = pDoc->inputImage[y][x] + 100;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x] = value;
			}
			else {	 //컬러 이미지
				value = pDoc->inputImage[y][x * 3 + 0] + 100;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x * 3 + 0] = value;

				value = pDoc->inputImage[y][x * 3 + 1] + 100;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x * 3 + 1] = value;

				value = pDoc->inputImage[y][x * 3 + 2] + 100;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x * 3 + 2] = value;
			}
		}
	}
	Invalidate();
}


void CImageProcessing20212155View::OnPixelSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();

	int x, y;
	int value;
	for (y = 0; y < pDoc->imageHeight; y++) {
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {	 //흑백 이미지
				value = pDoc->inputImage[y][x] - 100;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x] = value;
			}
			else {	 //컬러 이미지
				value = pDoc->inputImage[y][x * 3 + 0] - 100;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x * 3 + 0] = value;

				value = pDoc->inputImage[y][x * 3 + 1] - 100;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x * 3 + 1] = value;

				value = pDoc->inputImage[y][x * 3 + 2] - 100;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x * 3 + 2] = value;
			}
		}
	}
	Invalidate();
}


void CImageProcessing20212155View::OnPixelMul()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();

	int x, y;
	int value;
	for (y = 0; y < pDoc->imageHeight; y++) {
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {	 //흑백 이미지
				value = pDoc->inputImage[y][x] * 1.5;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x] = value;
			}
			else {	 //컬러 이미지
				value = pDoc->inputImage[y][x * 3 + 0] * 1.5;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x * 3 + 0] = value;

				value = pDoc->inputImage[y][x * 3 + 1] * 1.5;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x * 3 + 1] = value;

				value = pDoc->inputImage[y][x * 3 + 2] * 1.5;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x * 3 + 2] = value;
			}
		}
	}
	Invalidate();
}


void CImageProcessing20212155View::OnPixelDiv()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();

	int x, y;
	int value;
	for (y = 0; y < pDoc->imageHeight; y++) {
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {	 //흑백 이미지
				value = pDoc->inputImage[y][x] / 1.5;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x] = value;
			}
			else {	 //컬러 이미지
				value = pDoc->inputImage[y][x * 3 + 0] / 1.5;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x * 3 + 0] = value;

				value = pDoc->inputImage[y][x * 3 + 1] / 1.5;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x * 3 + 1] = value;

				value = pDoc->inputImage[y][x * 3 + 2] / 1.5;
				if (value >= 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImage[y][x * 3 + 2] = value;
			}
		}
	}
	Invalidate();
}


void CImageProcessing20212155View::OnPixelHistoEq()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();

	int x, y, k;
	int hist[256]{}, sum[256]{};
	int rhist[256]{}, rsum[256]{}, ghist[256]{}, gsum[256]{}, bhist[256]{}, bsum[256]{};
	int acc_hist = 0;
	int r_acc_hist = 0, g_acc_hist = 0, b_acc_hist = 0;
	float N = (float)(pDoc->imageHeight * pDoc->imageWidth);	//영상의 전체 픽셀 수

	//명암값 빈도수 조사
	for (y = 0; y < pDoc->imageHeight; y++) {
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {	 //흑백 이미지
				hist[pDoc->inputImage[y][x]]++;
			}
			else {	 //컬러 이미지
				rhist[pDoc->inputImage[y][x * 3 + 0]]++;
				ghist[pDoc->inputImage[y][x * 3 + 1]]++;
				bhist[pDoc->inputImage[y][x * 3 + 2]]++;
			}
		}
	}

	//누적된 히스토그램 합 계산
	for (k = 0; k < 256; k++) {
		if (pDoc->depth == 1) {	 //흑백 이미지
			acc_hist += hist[k];
			sum[k] = acc_hist;
		}
		else {	 //컬러 이미지
			r_acc_hist += rhist[k];
			rsum[k] = r_acc_hist;

			g_acc_hist += ghist[k];
			gsum[k] = g_acc_hist;

			b_acc_hist += bhist[k];
			bsum[k] = b_acc_hist;
		}
	}

	for (y = 0; y < pDoc->imageHeight; y++) {
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {	 //흑백 이미지
				k = pDoc->inputImage[y][x];
				pDoc->resultImage[y][x] = (unsigned char)(sum[k] / N * 255);
			}
			else {	 //컬러 이미지
				k = pDoc->inputImage[y][x * 3 + 0];
				pDoc->resultImage[y][x * 3 + 0] = (unsigned char)(rsum[k] / N * 255);

				k = pDoc->inputImage[y][x * 3 + 1];
				pDoc->resultImage[y][x * 3 + 1] = (unsigned char)(gsum[k] / N * 255);

				k = pDoc->inputImage[y][x * 3 + 2];
				pDoc->resultImage[y][x * 3 + 2] = (unsigned char)(bsum[k] / N * 255);
			}
		}
	}

	Invalidate();
}


void CImageProcessing20212155View::OnPixelContrastStretching()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();

	//변수 선언
	int min = 256, max = -1;
	int rmin = 256, rmax = -1, gmin = 256, gmax = -1, bmin = 256, bmax = -1;
	int x, y;
	int p;

	//최대, 최소 값 검색
	for (y = 0; y < pDoc->imageHeight; y++) {
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {	 //흑백 이미지
				if (pDoc->inputImage[y][x] < min) min = pDoc->inputImage[y][x];
				if (pDoc->inputImage[y][x] > max) max = pDoc->inputImage[y][x];
			}
			else {	 //컬러 이미지
				if (pDoc->inputImage[y][x * 3 + 0] < rmin) rmin = pDoc->inputImage[y][x * 3 + 0];
				if (pDoc->inputImage[y][x * 3 + 0] > rmax) rmax = pDoc->inputImage[y][x * 3 + 0];

				if (pDoc->inputImage[y][x * 3 + 1] < gmin) gmin = pDoc->inputImage[y][x * 3 + 1];
				if (pDoc->inputImage[y][x * 3 + 1] > gmax) gmax = pDoc->inputImage[y][x * 3 + 1];

				if (pDoc->inputImage[y][x * 3 + 2] < bmin) bmin = pDoc->inputImage[y][x * 3 + 2];
				if (pDoc->inputImage[y][x * 3 + 2] > bmax) bmax = pDoc->inputImage[y][x * 3 + 2];
			}
		}
	}

	//P' = (float)(P-min)/(max-min)*255
	for (y = 0; y < pDoc->imageHeight; y++) {
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {	 //흑백 이미지
				p = pDoc->inputImage[y][x];
				pDoc->resultImage[y][x] = (float)(p - min) / (max - min) * 255;
			}
			else {	 //컬러 이미지
				p = pDoc->inputImage[y][x * 3 + 0];
				pDoc->resultImage[y][x * 3 + 0] = (float)(p - rmin) / (rmax - rmin) * 255;

				p = pDoc->inputImage[y][x * 3 + 1];
				pDoc->resultImage[y][x * 3 + 1] = (float)(p - gmin) / (gmax - gmin) * 255;

				p = pDoc->inputImage[y][x * 3 + 2];
				pDoc->resultImage[y][x * 3 + 2] = (float)(p - bmin) / (bmax - bmin) * 255;
			}
		}
	}

	Invalidate();
}


void CImageProcessing20212155View::OnPixelBinarization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();

	//변수 선언
	int thresh = 150;
	int x, y;

	for (y = 0; y < pDoc->imageHeight; y++) {
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {	 //흑백 이미지
				if (pDoc->inputImage[y][x] > thresh)
					pDoc->resultImage[y][x] = 255;
				else
					pDoc->resultImage[y][x] = 0;
			}
			else {	 //컬러 이미지
				if (pDoc->inputImage[y][x * 3 + 0] + pDoc->inputImage[y][x * 3 + 1] + pDoc->inputImage[y][x * 3 + 2] > thresh) {
					pDoc->resultImage[y][x * 3 + 0] = 255;
					pDoc->resultImage[y][x * 3 + 1] = 255;
					pDoc->resultImage[y][x * 3 + 2] = 255;
				}
				else {
					pDoc->resultImage[y][x * 3 + 0] = 0;
					pDoc->resultImage[y][x * 3 + 1] = 0;
					pDoc->resultImage[y][x * 3 + 2] = 0;
				}
			}
		}
	}

	Invalidate();
}


void CImageProcessing20212155View::OnPixelTwoImageAdd()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();

	CFileDialog dlg(true);
	CFile file;

	if (dlg.DoModal() == IDOK) {

		file.Open(dlg.GetPathName(), CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		pDoc->LoadSecondImageFile(ar);
		file.Close();

		int x, y;
		for (y = 0; y < pDoc->imageHeight; y++) {
			for (x = 0; x < pDoc->imageWidth; x++) {
				if (pDoc->depth == 1) {	 //흑백 이미지
					pDoc->resultImage[y][x] = 0.5 * pDoc->inputImage[y][x] + 0.5 * pDoc->inputImage2[y][x];
				}
				else {	 //컬러 이미지
					pDoc->resultImage[y][x * 3 + 0] = 0.5 * pDoc->inputImage[y][x * 3 + 0] + 0.5 * pDoc->inputImage2[y][x * 3 + 0];
					pDoc->resultImage[y][x * 3 + 1] = 0.5 * pDoc->inputImage[y][x * 3 + 1] + 0.5 * pDoc->inputImage2[y][x * 3 + 1];
					pDoc->resultImage[y][x * 3 + 2] = 0.5 * pDoc->inputImage[y][x * 3 + 2] + 0.5 * pDoc->inputImage2[y][x * 3 + 2];
				}
			}
		}

		Invalidate();
	}
}


void CImageProcessing20212155View::OnPixelTwoImageSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();

	CFileDialog dlg(true);
	CFile file;

	if (dlg.DoModal() == IDOK) {

		file.Open(dlg.GetPathName(), CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		pDoc->LoadSecondImageFile(ar);
		file.Close();

		int x, y;
		for (y = 0; y < pDoc->imageHeight; y++) {
			for (x = 0; x < pDoc->imageWidth; x++) {
				if (pDoc->depth == 1) {	 //흑백 이미지
					pDoc->resultImage[y][x] = abs(pDoc->inputImage[y][x] - pDoc->inputImage2[y][x]);
				}
				else {	 //컬러 이미지
					pDoc->resultImage[y][x * 3 + 0] = abs(pDoc->inputImage[y][x * 3 + 0] - pDoc->inputImage2[y][x * 3 + 0]);
					pDoc->resultImage[y][x * 3 + 1] = abs(pDoc->inputImage[y][x * 3 + 1] - pDoc->inputImage2[y][x * 3 + 1]);
					pDoc->resultImage[y][x * 3 + 2] = abs(pDoc->inputImage[y][x * 3 + 2] - pDoc->inputImage2[y][x * 3 + 2]);
				}
			}
		}

		Invalidate();
	}
}


void CImageProcessing20212155View::OnRegionSharpening()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();
	float kernel[3][3] = {
		{0, -1, 0},
		{-1, 5, -1},
		{0, -1, 0}
	};

	convolve(pDoc->inputImage, pDoc->resultImage, pDoc->imageWidth, pDoc->imageHeight, kernel, 0, pDoc->depth);

	Invalidate();
}



void CImageProcessing20212155View::OnRegionSmoothing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();
	float kernel[3][3] = {
		{1 / 9.0f, 1 / 9.0f, 1 / 9.0f},
		{1 / 9.0f, 1 / 9.0f, 1 / 9.0f},
		{1 / 9.0f, 1 / 9.0f, 1 / 9.0f}
	};

	convolve(pDoc->inputImage, pDoc->resultImage, pDoc->imageWidth, pDoc->imageHeight, kernel, 0, pDoc->depth);

	Invalidate();
}


void CImageProcessing20212155View::OnRegionEmbossing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();
	float kernel[3][3] = {
		{-1, 0, 0},
		{0, 0, 0},
		{0, 0, 1}
	};

	convolve(pDoc->inputImage, pDoc->resultImage, pDoc->imageWidth, pDoc->imageHeight, kernel, 128, pDoc->depth);

	Invalidate();
}


void CImageProcessing20212155View::convolve(unsigned char** inputImage, unsigned char** resultImage, int cols, int rows, float mask[][3], int bias, int depth)
{
	// TODO: 여기에 구현 코드 추가.
	int x, y;
	int i, j;
	int sum, rsum, gsum, bsum;

	//테두리 제외를  위해 1 until len-1
	for (y = 1; y < rows - 1; y++) {
		for (x = 1; x < cols - 1; x++) {
			if (depth == 1) {  //흑백 이미지
				sum = 0;
				for (j = 0; j < 3; j++) {
					for (i = 0; i < 3; i++) {
						sum += inputImage[y + j - 1][x + i - 1] * mask[j][i];
					}
				}
				sum += bias;
				if (sum > 255) sum = 255;
				else if (sum < 0) sum = 0;

				resultImage[y][x] = sum;
			}
			else {  //컬러 이미지
				rsum = gsum = bsum = 0;
				for (j = 0; j < 3; j++) {
					for (i = 0; i < 3; i++) {
						rsum += inputImage[y + j - 1][3 * (x + i - 1) + 0] * mask[j][i];
						gsum += inputImage[y + j - 1][3 * (x + i - 1) + 1] * mask[j][i];
						bsum += inputImage[y + j - 1][3 * (x + i - 1) + 2] * mask[j][i];
					}
				}
				rsum += bias;
				gsum += bias;
				bsum += bias;

				if (rsum > 255) rsum = 255;
				else if (rsum < 0) rsum = 0;
				if (gsum > 255) gsum = 255;
				else if (gsum < 0) gsum = 0;
				if (bsum > 255) bsum = 255;
				else if (bsum < 0) bsum = 0;

				resultImage[y][3 * x + 0] = rsum;
				resultImage[y][3 * x + 1] = gsum;
				resultImage[y][3 * x + 2] = bsum;
			}

		}
	}
}


void CImageProcessing20212155View::OnRegionPrewitt()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();
	
	float maskH[3][3] = {
		{-1, -1, -1},
		{ 0,  0,  0},
		{ 1,  1,  1}
	};
	float maskV[3][3] = {
		{1, 0, -1},
		{1, 0, -1},
		{1, 0, -1}
	};

	unsigned char** Er, ** Ec;
	int i, x, y;
	int sum, rsum, gsum, bsum;

	//메모리 할당
	Er = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->imageHeight; i++) {
		Er[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
	}

	convolve(pDoc->inputImage, Er, pDoc->imageWidth, pDoc->imageHeight, maskH, 128, pDoc->depth);
	convolve(pDoc->inputImage, Ec, pDoc->imageWidth, pDoc->imageHeight, maskV, 128, pDoc->depth);

	for (y = 0; y < pDoc->imageHeight; y++) {
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {
				sum = sqrt((Er[y][x] - 128) * (Er[y][x] - 128) + (Ec[y][x] - 128) * (Ec[y][x] - 128));
				if (sum > 255) sum = 255;
				else if (sum < 0) sum = 0;
				pDoc->resultImage[y][x] = sum;
			}
			else {
				rsum = sqrt((Er[y][x * 3 + 0] - 128) * (Er[y][x * 3 + 0] - 128) + (Ec[y][x * 3 + 0] - 128) * (Ec[y][x * 3 + 0] - 128));
				if (rsum > 255) rsum = 255;
				else if (rsum < 0) rsum = 0;

				gsum = sqrt((Er[y][x * 3 + 1] - 128) * (Er[y][x * 3 + 1] - 128) + (Ec[y][x * 3 + 1] - 128) * (Ec[y][x * 3 + 1] - 128));
				if (gsum > 255) gsum = 255;
				else if (gsum < 0) gsum = 0;

				bsum = sqrt((Er[y][x * 3 + 2] - 128) * (Er[y][x * 3 + 2] - 128) + (Ec[y][x * 3 + 2] - 128) * (Ec[y][x * 3 + 2] - 128));
				if (bsum > 255) bsum = 255;
				else if (bsum < 0) bsum = 0;

				sum = sqrt(rsum * rsum + gsum * gsum + bsum * bsum);
				if (sum > 255) sum = 255;
				else if (sum < 0) sum = 0;

				pDoc->resultImage[y][x * 3 + 0] = sum;
				pDoc->resultImage[y][x * 3 + 1] = sum;
				pDoc->resultImage[y][x * 3 + 2] = sum;
			}
		}
	}

	for (i = 0; i < pDoc->imageHeight; i++) {
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);

	Invalidate();
}


void CImageProcessing20212155View::OnRegionRoberts()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();

	float maskH[3][3] = {
		{-1, 0, 0},
		{ 0,  1,  0},
		{ 0,  0,  0}
	};
	float maskV[3][3] = {
		{0, 0, -1},
		{0, 1, 0},
		{0, 0, 0}
	};

	unsigned char** Er, ** Ec;
	int i, x, y;
	int sum, rsum, gsum, bsum;

	//메모리 할당
	Er = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->imageHeight; i++) {
		Er[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
	}

	convolve(pDoc->inputImage, Er, pDoc->imageWidth, pDoc->imageHeight, maskH, 128, pDoc->depth);
	convolve(pDoc->inputImage, Ec, pDoc->imageWidth, pDoc->imageHeight, maskV, 128, pDoc->depth);
	
	for (y = 0; y < pDoc->imageHeight; y++) {
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {
				sum = sqrt((Er[y][x] - 128) * (Er[y][x] - 128) + (Ec[y][x] - 128) * (Ec[y][x] - 128));
				if (sum > 255) sum = 255;
				else if (sum < 0) sum = 0;
				pDoc->resultImage[y][x] = sum;
			}
			else {
				rsum = sqrt((Er[y][x * 3 + 0] - 128) * (Er[y][x * 3 + 0] - 128) + (Ec[y][x * 3 + 0] - 128) * (Ec[y][x * 3 + 0] - 128));
				if (rsum > 255) rsum = 255;
				else if (rsum < 0) rsum = 0;

				gsum = sqrt((Er[y][x * 3 + 1] - 128) * (Er[y][x * 3 + 1] - 128) + (Ec[y][x * 3 + 1] - 128) * (Ec[y][x * 3 + 1] - 128));
				if (gsum > 255) gsum = 255;
				else if (gsum < 0) gsum = 0;

				bsum = sqrt((Er[y][x * 3 + 2] - 128) * (Er[y][x * 3 + 2] - 128) + (Ec[y][x * 3 + 2] - 128) * (Ec[y][x * 3 + 2] - 128));
				if (bsum > 255) bsum = 255;
				else if (bsum < 0) bsum = 0;

				sum = sqrt(rsum * rsum + gsum * gsum + bsum * bsum);
				if (sum > 255) sum = 255;
				else if (sum < 0) sum = 0;

				pDoc->resultImage[y][x * 3 + 0] = sum;
				pDoc->resultImage[y][x * 3 + 1] = sum;
				pDoc->resultImage[y][x * 3 + 2] = sum;
			}
		}
	}

	for (i = 0; i < pDoc->imageHeight; i++) {
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);

	Invalidate();
}


void CImageProcessing20212155View::OnRegionSobel()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();

	float maskH[3][3] = {
		{-1, -2, -1},
		{ 0,  0,  0},
		{ 1,  2,  1}
	};
	float maskV[3][3] = {
		{1, 0, -1},
		{2, 0, -2},
		{1, 0, -1}
	};

	unsigned char** Er, ** Ec;
	int i, x, y;
	int sum, rsum, gsum, bsum;

	//메모리 할당
	Er = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->imageHeight; i++) {
		Er[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
	}

	convolve(pDoc->inputImage, Er, pDoc->imageWidth, pDoc->imageHeight, maskH, 128, pDoc->depth);
	convolve(pDoc->inputImage, Ec, pDoc->imageWidth, pDoc->imageHeight, maskV, 128, pDoc->depth);

	for (y = 0; y < pDoc->imageHeight; y++) {
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {
				sum = sqrt((Er[y][x] - 128) * (Er[y][x] - 128) + (Ec[y][x] - 128) * (Ec[y][x] - 128));
				if (sum > 255) sum = 255;
				else if (sum < 0) sum = 0;

				//이진화를 통해 경계선이 뚜렷한 부분만 남김
				if (sum > 128) sum = 255;
				else sum = 0;

				pDoc->resultImage[y][x] = sum;
			}
			else {
				rsum = sqrt((Er[y][x * 3 + 0] - 128) * (Er[y][x * 3 + 0] - 128) + (Ec[y][x * 3 + 0] - 128) * (Ec[y][x * 3 + 0] - 128));
				if (rsum > 255) rsum = 255;
				else if (rsum < 0) rsum = 0;

				gsum = sqrt((Er[y][x * 3 + 1] - 128) * (Er[y][x * 3 + 1] - 128) + (Ec[y][x * 3 + 1] - 128) * (Ec[y][x * 3 + 1] - 128));
				if (gsum > 255) gsum = 255;
				else if (gsum < 0) gsum = 0;

				bsum = sqrt((Er[y][x * 3 + 2] - 128) * (Er[y][x * 3 + 2] - 128) + (Ec[y][x * 3 + 2] - 128) * (Ec[y][x * 3 + 2] - 128));
				if (bsum > 255) bsum = 255;
				else if (bsum < 0) bsum = 0;

				sum = sqrt(rsum * rsum + gsum * gsum + bsum * bsum);
				if (sum > 255) sum = 255;
				else if (sum < 0) sum = 0;

				//이진화를 통해 경계선이 뚜렷한 부분만 남김
				if (sum > 128) sum = 255;
				else sum = 0;

				pDoc->resultImage[y][x * 3 + 0] = sum;
				pDoc->resultImage[y][x * 3 + 1] = sum;
				pDoc->resultImage[y][x * 3 + 2] = sum;
			}
		}
	}

	for (i = 0; i < pDoc->imageHeight; i++) {
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);

	Invalidate();
}


void CImageProcessing20212155View::OnRegionAverageFiltering()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();

	int x, y;
	int j, i;
	int sum, rsum, gsum, bsum;

	// 5 * 5 영역의 평균값
	for (y = 2; y < pDoc->imageHeight - 2; y++) {
		for (x = 2; x < pDoc->imageWidth - 2; x++) {
			if (pDoc->depth == 1) {
				sum = 0;
				for (j = 0; j < 5; j++) {
					for (i = 0; i < 5; i++) {
						sum += pDoc->inputImage[y + j - 2][x + i - 2];
					}
				}
				sum /= 25;

				if (sum > 255) sum = 255;
				else if (sum < 0) sum = 0;

				pDoc->resultImage[y][x] = sum;
			}
			else {
				rsum = gsum = bsum = 0;
				for (j = 0; j < 5; j++) {
					for (i = 0; i < 5; i++) {
						rsum += pDoc->inputImage[y + j - 2][(x + i - 2) * 3 + 0];
						gsum += pDoc->inputImage[y + j - 2][(x + i - 2) * 3 + 1];
						bsum += pDoc->inputImage[y + j - 2][(x + i - 2) * 3 + 2];
					}
				}
				rsum /= 25;
				gsum /= 25;
				bsum /= 25;

				if (rsum > 255) rsum = 255;
				else if (rsum < 0) rsum = 0;
				if (gsum > 255) gsum = 255;
				else if (gsum < 0) gsum = 0;
				if (bsum > 255) bsum = 255;
				else if (bsum < 0) bsum = 0;

				pDoc->resultImage[y][x * 3 + 0] = rsum;
				pDoc->resultImage[y][x * 3 + 1] = gsum;
				pDoc->resultImage[y][x * 3 + 2] = bsum;
			}
		}
	}

	Invalidate();
}


void CImageProcessing20212155View::OnRegionMedianFiltering()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();

	int x, y, i, j;
	int n[9], temp;

	for (y = 0; y < pDoc->imageHeight; y++)
	{
		for (x = 0; x < pDoc->imageWidth; x++)
		{
			n[0] = pDoc->inputImage[y - 1][x - 1];
			n[1] = pDoc->inputImage[y - 1][x + 0];
			n[2] = pDoc->inputImage[y - 1][x + 1];
			n[3] = pDoc->inputImage[y + 0][x - 1];
			n[4] = pDoc->inputImage[y + 0][x + 0];
			n[5] = pDoc->inputImage[y + 0][x + 1];
			n[6] = pDoc->inputImage[y + 1][x - 1];
			n[7] = pDoc->inputImage[y + 1][x + 0];
			n[8] = pDoc->inputImage[y + 1][x + 1];

			//sorting = 오름차순
			for (i = 8; i >= 0; i--) {
				for (j = 0; j < i; j++) {
					if (n[j] > n[j + 1]) {
						temp = n[j + 1];
						n[j + 1] = n[j];
						n[j] = temp;
					}
				}
			}

			pDoc->resultImage[y][x] = n[4];
		}
	}
}


void CImageProcessing20212155View::OnMopologyColorToGray()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();
	if (pDoc->depth == 1) return;

	int x, y;
	int gray;

	for (y = 1; y < pDoc->imageHeight - 1; y++) {
		for (x = 1; x < pDoc->imageWidth - 1; x++) {
			gray = ((pDoc->inputImage[y][x * 3 + 0] + pDoc->inputImage[y][x * 3 + 1] + pDoc->inputImage[y][x * 3 + 0]) / 3);
			pDoc->inputImage[y][x * 3 + 0] = gray;
			pDoc->inputImage[y][x * 3 + 1] = gray;
			pDoc->inputImage[y][x * 3 + 2] = gray;
		}
	}

	Invalidate();
}


void CImageProcessing20212155View::OnMopologyBinarization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();
	int x, y;
	int th = 100;

	for (y = 1; y < pDoc->imageHeight - 1; y++) {
		for (x = 1; x < pDoc->imageWidth - 1; x++) {
			if (pDoc->depth == 1) {
				if (pDoc->inputImage[y][x] > th)
					pDoc->inputImage[y][x] = 255;
				else
					pDoc->inputImage[y][x] = 0;
			}
			else {
				if (pDoc->inputImage[y][x * 3 + 0] > th) {
					pDoc->inputImage[y][x * 3 + 0] = 255;
					pDoc->inputImage[y][x * 3 + 1] = 255;
					pDoc->inputImage[y][x * 3 + 2] = 255;
				}
				else {
					pDoc->inputImage[y][x * 3 + 0] = 0;
					pDoc->inputImage[y][x * 3 + 1] = 0;
					pDoc->inputImage[y][x * 3 + 2] = 0;
				}
			}
		}
	}

	Invalidate();
}


void CImageProcessing20212155View::OnMopologyErosion()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();
	int x, y;
	int min;

	for (y = 1; y < pDoc->imageHeight - 1; y++) {
		for (x = 1; x < pDoc->imageWidth - 1; x++) {
			if (pDoc->depth == 1) {	//흑백
				min = 255;
				for (int j = 0; j < 3; j++) {
					for (int i = 0; i < 3; i++) {
						if (min > pDoc->inputImage[y + j - 1][x + i - 1])
							min = pDoc->inputImage[y + j - 1][x + i - 1];
					}
				}
				pDoc->resultImage[y][x] = min;
			}
			else {	//컬러
				min = 255;
				for (int j = 0; j < 3; j++) {
					for (int i = 0; i < 3; i++) {
						if (min > pDoc->inputImage[y + j - 1][(x + i - 1) * 3 + 0])
							min = pDoc->inputImage[y + j - 1][(x + i - 1) * 3 + 0];
					}
				}
				pDoc->resultImage[y][x * 3 + 0] = min;

				min = 255;
				for (int j = 0; j < 3; j++) {
					for (int i = 0; i < 3; i++) {
						if (min > pDoc->inputImage[y + j - 1][(x + i - 1) * 3 + 1])
							min = pDoc->inputImage[y + j - 1][(x + i - 1) * 3 + 1];
					}
				}
				pDoc->resultImage[y][x * 3 + 1] = min;

				min = 255;
				for (int j = 0; j < 3; j++) {
					for (int i = 0; i < 3; i++) {
						if (min > pDoc->inputImage[y + j - 1][(x + i - 1) * 3 + 2])
							min = pDoc->inputImage[y + j - 1][(x + i - 1) * 3 + 2];
					}
				}
				pDoc->resultImage[y][x * 3 + 2] = min;
			}
		}
	}

	Invalidate();
}


void CImageProcessing20212155View::OnMopologyDilation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing20212155Doc* pDoc = GetDocument();
	int x, y;
	int max;

	for (y = 1; y < pDoc->imageHeight - 1; y++) {
		for (x = 1; x < pDoc->imageWidth - 1; x++) {
			if (pDoc->depth == 1) {	//흑백
				max = 0;
				for (int j = 0; j < 3; j++) {
					for (int i = 0; i < 3; i++) {
						if (max < pDoc->inputImage[y + j - 1][x + i - 1])
							max = pDoc->inputImage[y + j - 1][x + i - 1];
					}
				}
				pDoc->resultImage[y][x] = max;
			}
			else {	//컬러
				max = 0;
				for (int j = 0; j < 3; j++) {
					for (int i = 0; i < 3; i++) {
						if (max < pDoc->inputImage[y + j - 1][(x + i - 1) * 3 + 0])
							max = pDoc->inputImage[y + j - 1][(x + i - 1) * 3 + 0];
					}
				}
				pDoc->resultImage[y][x * 3 + 0] = max;

				max = 0;
				for (int j = 0; j < 3; j++) {
					for (int i = 0; i < 3; i++) {
						if (max < pDoc->inputImage[y + j - 1][(x + i - 1) * 3 + 1])
							max = pDoc->inputImage[y + j - 1][(x + i - 1) * 3 + 1];
					}
				}
				pDoc->resultImage[y][x * 3 + 1] = max;

				max = 0;
				for (int j = 0; j < 3; j++) {
					for (int i = 0; i < 3; i++) {
						if (max < pDoc->inputImage[y + j - 1][(x + i - 1) * 3 + 2])
							max = pDoc->inputImage[y + j - 1][(x + i - 1) * 3 + 2];
					}
				}
				pDoc->resultImage[y][x * 3 + 2] = max;
			}
		}
	}

	Invalidate();
}