// Banana.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "Banana.h"
#include "UIlib.h"
#include "Core/UIBase.h"

#define MAX_LOADSTRING 100
using namespace DuiLib;



#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif

class CDuiFrameWnd1 : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual void    Notify(TNotifyUI& msg) {
		if (msg.sType == _T("click"))
		{
			if (msg.pSender->GetName() == _T("0001"))
			{
			//	::MessageBox(NULL, _T("我是按钮"), _T("点击了按钮"), NULL);
			}
		}
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE)
		{
			m_PaintManager.Init(m_hWnd);


			CDialogBuilder builder;
			CControlUI* pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager);

			ASSERT(pRoot && "Failed to parse XML");

			m_PaintManager.AttachDialog(pRoot);

			m_PaintManager.AddNotifier(this);



			return lRes;
		}
		//不允许非客户区被激活
		//窗口不被激活显示
		else if (uMsg == WM_NCACTIVATE)
		{
			if (!::IsIconic(m_hWnd))
			{
				return (wParam == 0) ? TRUE : FALSE;
			}
		}

		//创建没有标题的标题栏
		else if (uMsg == WM_NCPAINT)
		{
			return 0;
		}
		//指定为空
		else if (uMsg == WM_NCCALCSIZE)
		{
			return 0;
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		return __super::HandleMessage(uMsg, wParam, lParam);
	}

protected:
	CPaintManagerUI m_PaintManager;
};

class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR    GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("duilib.xml"); }
	virtual CDuiString GetSkinFolder() { return _T(""); }
};





int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


	CPaintManagerUI::SetInstance(hInstance);

	CPaintManagerUI::SetResourcePath(L"./");

	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("dui..windows"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
	duiFrame.ShowModal();

	return 0;
}


