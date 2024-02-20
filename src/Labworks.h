// Labworks.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#include <wx/wx.h>
#include "cMain.h"

class cApp : public wxApp
{
public:
    cApp();
    ~cApp();

private:
    cMain* m_frame1 = nullptr;

public:
    virtual bool OnInit();
};
// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.