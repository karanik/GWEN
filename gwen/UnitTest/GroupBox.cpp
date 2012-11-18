#include "Gwen/UnitTest/UnitTest.h"
#include "Gwen/Controls/GroupBox.h"

using namespace Gwen;

class GroupBox : public GUnit
{
	public:

	GWEN_CONTROL_INLINE( GroupBox, GUnit )
	{
		Gwen::Controls::GroupBox* pGroup = new Gwen::Controls::GroupBox( this );
		pGroup->SetText( GWEN_T("Group Box") );
		pGroup->SetSize( 300, 200 );
	}
};



DEFINE_UNIT_TEST( GroupBox, GWEN_T("GroupBox") );
