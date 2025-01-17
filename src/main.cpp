#include <iostream>
#include <cstdint>
#include <cstring>
#include <wx/wx.h>

#include "uuid.hpp"
#include "byte_utils.hpp"
#include "save_data.hpp"
#include "gui.hpp"

class Main : public wxApp
{
	public:
		virtual bool OnInit();
};
wxIMPLEMENT_APP(Main);

bool Main::OnInit()
{
	MainFrame *frame = new MainFrame();
	frame->Show(true);
	return true;
}
