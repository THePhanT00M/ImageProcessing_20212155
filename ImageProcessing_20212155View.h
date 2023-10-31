
// ImageProcessing_20212155View.h: CImageProcessing20212155View 클래스의 인터페이스
//

#pragma once


class CImageProcessing20212155View : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CImageProcessing20212155View() noexcept;
	DECLARE_DYNCREATE(CImageProcessing20212155View)

// 특성입니다.
public:
	CImageProcessing20212155Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CImageProcessing20212155View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPixelAdd();
	afx_msg void OnPixelSub();
	afx_msg void OnPixelMul();
	afx_msg void OnPixelDiv();
	afx_msg void OnPixelHistoEq();
	afx_msg void OnPixelContrastStretching();
	afx_msg void OnPixelBinarization();
	afx_msg void OnPixelTwoImageAdd();
	afx_msg void OnPixelTwoImageSub();
	afx_msg void OnRegionSharpening();
	afx_msg void OnRegionSmoothing();
	afx_msg void OnRegionEmbossing();
	void convolve(unsigned char** inputImage, unsigned char** resultImage, int cols, int rows, float mask[][3], int bias, int depth);
	afx_msg void OnRegionPrewitt();
	afx_msg void OnRegionRoberts();
	afx_msg void OnRegionSobel();
	afx_msg void OnRegionAverageFiltering();
	afx_msg void OnRegionMedianFiltering();
	afx_msg void OnMopologyColorToGray();
	afx_msg void OnMopologyBinarization();
	afx_msg void OnMopologyErosion();
	afx_msg void OnMopologyDilation();
};

#ifndef _DEBUG  // ImageProcessing_20212155View.cpp의 디버그 버전
inline CImageProcessing20212155Doc* CImageProcessing20212155View::GetDocument() const
   { return reinterpret_cast<CImageProcessing20212155Doc*>(m_pDocument); }
#endif

