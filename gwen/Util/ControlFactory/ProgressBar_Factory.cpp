
#include "Gwen/Util/ControlFactory.h"
#include "Gwen/Controls.h"

using namespace Gwen;

namespace Property 
{
	class CycleSpeed: public ControlFactory::Property 
	{
		GWEN_CONTROL_FACTORY_PROPERTY( CycleSpeed, GWEN_T("") );

		UnicodeString GetValue( Controls::Base* ctrl )
		{
			return Utility::Format( GWEN_T("%f"), (float)gwen_cast<Controls::ProgressBar>(ctrl)->GetCycleSpeed() );
		}

		void SetValue( Controls::Base* ctrl, const UnicodeString& str )
		{
			float num;
			if ( GWEN_SSCANF( str.c_str(), GWEN_T("%f"), &num ) != 1 ) return;

			gwen_cast<Controls::ProgressBar>(ctrl)->SetCycleSpeed( num );
		}

	};

}

class ProgressBar_Factory : public Gwen::ControlFactory::Base
{
	public:

		GWEN_CONTROL_FACTORY_CONSTRUCTOR( ProgressBar_Factory, Gwen::ControlFactory::Base )
		{
			AddProperty( new Property::CycleSpeed() );
		}

		virtual Gwen::String Name(){ return GWEN_T("ProgressBar"); }
		virtual Gwen::String BaseName(){ return GWEN_T("Base"); }

		virtual Gwen::Controls::Base* CreateInstance( Gwen::Controls::Base* parent )
		{
			Gwen::Controls::ProgressBar* pControl = new Gwen::Controls::ProgressBar( parent );
			pControl->SetSize( 200, 20 );
			return pControl;
		}
};


GWEN_CONTROL_FACTORY( ProgressBar_Factory );
