
#include "Gwen/Util/ControlFactory.h"
#include "Gwen/Controls.h"

using namespace Gwen;

namespace Property 
{
	class FileType: public ControlFactory::Property 
	{
		GWEN_CONTROL_FACTORY_PROPERTY( FileType, GWEN_T("In the format \"PNG file | *.png\"") );

		UnicodeString GetValue( Controls::Base* ctrl )
		{
			return gwen_cast<Controls::FilePicker>(ctrl)->GetFileType();
		}

		void SetValue( Controls::Base* ctrl, const UnicodeString& str )
		{
			gwen_cast<Controls::FilePicker>(ctrl)->SetFileType( str );
		}

	};

}

class FilePicker_Factory : public Gwen::ControlFactory::Base
{
	public:

		GWEN_CONTROL_FACTORY_CONSTRUCTOR( FilePicker_Factory, ControlFactory::Base )
		{
			AddProperty( new Property::FileType() );		
		}

		virtual Gwen::String Name(){ return GWEN_T("FilePicker"); }
		virtual Gwen::String BaseName(){ return GWEN_T("Base"); }

		virtual Gwen::Controls::Base* CreateInstance( Gwen::Controls::Base* parent )
		{
			Gwen::Controls::FilePicker* pControl = new Gwen::Controls::FilePicker( parent );
			pControl->SetSize( 100, 20 );
			pControl->SetFileType( GWEN_T("EXE file | *.exe")  );
			return pControl;
		}
};

GWEN_CONTROL_FACTORY( FilePicker_Factory );
