
// ImageProcessing_20212155Doc.h: CImageProcessing20212155Doc 클래스의 인터페이스
//


#pragma once


class CImageProcessing20212155Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CImageProcessing20212155Doc() noexcept;
	DECLARE_DYNCREATE(CImageProcessing20212155Doc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CImageProcessing20212155Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	// 입력 이미지
	unsigned char** inputImage;		//[y][x]
	unsigned char** inputImage2;	//[y][x]

	// 출력 이미지
	unsigned char** resultImage;	//[y][x]

	int imageWidth;
	int imageHeight;
	int depth;
	int LoadImageFile(CArchive& ar);
	void LoadSecondImageFile(CArchive& ar);
};
