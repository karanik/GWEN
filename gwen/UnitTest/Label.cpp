#include "Gwen/UnitTest/UnitTest.h"
#include "Gwen/Controls/Label.h"

using namespace Gwen;

class Label : public GUnit
{
	public:

	GWEN_CONTROL_INLINE( Label, GUnit )
	{
		{
			Gwen::Controls::Label* label = new Gwen::Controls::Label( this );
			label->SetText( "Garry's Normal Label" );
			label->SizeToContents();
			label->SetPos( 10, 10 );
		}

		{
			Gwen::Controls::Label* label = new Gwen::Controls::Label( this );
			label->SetText( GWEN_T("Chinese: \u4E45\u6709\u5F52\u5929\u613F \u7EC8\u8FC7\u9B3C\u95E8\u5173") );
			label->SizeToContents();
			label->SetPos( 10, 30 );
		}

		{
			Gwen::Controls::Label* label = new Gwen::Controls::Label( this );
			label->SetText( GWEN_T("Japanese: \u751F\u3080\u304E\u3000\u751F\u3054\u3081\u3000\u751F\u305F\u307E\u3054") );
			label->SizeToContents();
			label->SetPos( 10, 50 );
		}

		{
			Gwen::Controls::Label* label = new Gwen::Controls::Label( this );
			label->SetText( GWEN_T("Korean: \uADF9\uC9C0\uD0D0\uD5D8\u3000\uD611\uD68C\uACB0\uC131\u3000\uCCB4\uACC4\uC801\u3000\uC5F0\uAD6C") );
			label->SizeToContents();
			label->SetPos( 10, 70 );
		}

		{
			Gwen::Controls::Label* label = new Gwen::Controls::Label( this );
			label->SetText( GWEN_T("Hindi: \u092F\u0947 \u0905\u0928\u0941\u091A\u094D\u091B\u0947\u0926 \u0939\u093F\u0928\u094D\u0926\u0940 \u092E\u0947\u0902 \u0939\u0948\u0964") );
			label->SizeToContents();
			label->SetPos( 10, 90 );
		}

		{
			Gwen::Controls::Label* label = new Gwen::Controls::Label( this );
			label->SetText( GWEN_T("Arabic: \u0627\u0644\u0622\u0646 \u0644\u062D\u0636\u0648\u0631 \u0627\u0644\u0645\u0624\u062A\u0645\u0631 \u0627\u0644\u062F\u0648\u0644\u064A") );
			label->SizeToContents();
			label->SetPos( 10, 110 );
		}

		{
			Gwen::Controls::Label* label = new Gwen::Controls::Label( this );
			label->SetText( GWEN_T("Wow, Coloured Text") );
			label->SetTextColor( Gwen::Color( 0, 0, 255, 255 ) );
			label->SizeToContents();
			label->SetPos( 10, 130 );
		}

		{
			Gwen::Controls::Label* label = new Gwen::Controls::Label( this );
			label->SetText( GWEN_T("Coloured Text With Alpha") );
			label->SetTextColor( Gwen::Color( 0, 0, 255, 100 ) );
			label->SizeToContents();
			label->SetPos( 10, 150 );
		}

		{
			//
			// Note that when using a custom font, this font object has to stick around
			// for the lifetime of the label. Rethink, or is that ideal?
			//
			m_Font.facename = GWEN_T("Comic Sans MS");
			m_Font.size = 25;

			Gwen::Controls::Label* label = new Gwen::Controls::Label( this );
			label->SetText( GWEN_T("Custom Font (Comic Sans 25)") );
			label->SetFont( &m_Font );
			label->SizeToContents();
			label->SetPos( 10, 170 );
		}

	}

	Gwen::Font	m_Font;
};



DEFINE_UNIT_TEST( Label, GWEN_T("Label") );