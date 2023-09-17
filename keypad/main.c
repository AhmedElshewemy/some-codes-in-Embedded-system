#include"KBD.h"
#include"SEV_SEG.h"


#define F_CPU 8000000UL

int main()
{
	u8 Local_U8Key ;
	KBD_VidInit();
	SEV_SEG_VidInit();



	while(1)
	{
		Local_U8Key = KBD_U8GetPressedKey();
		if( Local_U8Key != 20 )
		{


			switch(Local_U8Key)
			{
				case '0' :
					SEV_SEG_VidSetNumber(SEV_SEG_ZERO);
					break;

				case '1' :
					SEV_SEG_VidSetNumber(SEV_SEG_ONE);
						break;
				case '2' :
					SEV_SEG_VidSetNumber(SEV_SEG_TWO);
					break;
				case '3' :
					SEV_SEG_VidSetNumber(SEV_SEG_THREE);
					break;
				case '4' :
					SEV_SEG_VidSetNumber(SEV_SEG_FOUR);
					break;
				case '5' :
					SEV_SEG_VidSetNumber(SEV_SEG_FIVE);
					break;
				case '6' :
				SEV_SEG_VidSetNumber(SEV_SEG_SIX);
				        break;

				case '7' :
					SEV_SEG_VidSetNumber(SEV_SEG_SEVEN);
						break;
				case '8' :
					SEV_SEG_VidSetNumber(SEV_SEG_EIGHT);
					break;
				case '9' :
					SEV_SEG_VidSetNumber(SEV_SEG_NINE);
					break;

				default :
					SEV_SEG_VidSetNumber(SEV_SEG_FOUR);
			}

		}
	}
}


